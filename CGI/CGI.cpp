//
// Created by Kory Moaning on 2/26/21.
//


#include "CGI.hpp"

static const int B64index[256] = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62, 63, 62, 62, 63, 52, 53, 54, 55,
   56, 57, 58, 59, 60, 61,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,
   7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,  0,
   0,  0,  0, 63,  0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
   41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };

CGI::CGI(Request &req, Server &ser): env (NULL), envCount (16), RequestBody(""), ResponseBody("") {
	std::string envKey[] = {"AUTH_TYPE", "CONTENT_LENGTH", "CONTENT_TYPE", "GATEWAY_INTERFACE", "PATH_INFO",
	"PATH_TRANSLATED","QUERY_STRING", "REMOTE_ADDR", "REMOTE_IDENT", "REMOTE_USER", "REQUEST_METHOD", "REQUEST_URI",
	"SCRIPT_NAME", "SERVER_NAME", "SERVER_PORT", "SERVER_PROTOCOL", "SERVER_SOFTWARE"};
	for (int i = 0; i < envCount ; ++i) {
		this->envMap[envKey[i]];
	}
	std::map<std::string, std::string> tmp = req.getHeaders();
	for (std::map<std::string, std::string>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		std::string a = it->first;
		if(a.find("-") != std::string::npos)
			a.replace(a.find("-"), 1, "_");
		std::transform(a.begin(), a.end(), a.begin(), toupper);
		envMap["HTTP_" + a] = it->second;
		envCount++;
	}

}

CGI::~CGI() {
	if(env) {
		for (int i = 0; i < envCount; ++i) {
			delete env[i];
		}
		delete env;
	}
	if(argv) {
		delete argv[0]; delete argv[1]; delete argv;
	}
}

CGI::CGI(const CGI &copy) {

}

CGI &CGI::operator=(const CGI &copy) {
	return *this;
}

const std::string &CGI::getResponseBody() const {
	return ResponseBody;
}

void CGI::setResponseBody(const std::string &responseBody) {
	ResponseBody = responseBody;
}

std::string b64decode(const void* data, const size_t len)
{
	unsigned char* p = (unsigned char*)data;
	int pad = len > 0 && (len % 4 || p[len - 1] == '=');
	const size_t L = ((len + 3) / 4 - pad) * 4;
	std::string str(L / 4 * 3 + pad, '\0');

	for (size_t i = 0, j = 0; i < L; i += 4)
	{
		int n = B64index[p[i]] << 18 | B64index[p[i + 1]] << 12 | B64index[p[i + 2]] << 6 | B64index[p[i + 3]];
		str[j++] = n >> 16;
		str[j++] = n >> 8 & 0xFF;
		str[j++] = n & 0xFF;
	}
	if (pad)
	{
		int n = B64index[p[L]] << 18 | B64index[p[L + 1]] << 12;
		str[str.size() - 1] = n >> 16;

		if (len > L + 2 && p[L + 2] != '=')
		{
			n |= B64index[p[L + 2]] << 6;
			str.push_back(n >> 8 & 0xFF);
		}
	}
	return str;
}

void CGI::init(Request &req, Server &ser) {
//	this->envMap["CONTENT_LENGTH"] =  	const_cast<std::map<std::string,std::string>&>(req.getHeaders())["CONTENT-LENGTH"];
//	сортировка по методам и в зависимости от этого установка значение переменных

//	std::string method = req.getMethod();
//	if(method == "GET" || method == "HEAD")
//		; //Взять данные из переменной окружения QUERY_STRING
//	else if(method == "POST")
//		;Проанализировать переменную QUERY_STRING
//         Получить длинну данных из CONTENT_LENGTH
//         Если (CONTENT_LENGTH>0) то
//             Считать CONTENT_LENGTH байт из sdtin как данные.
//	else
//		; //error


	this->envMap["REQUEST_URI"] = "/" + req.getPath(); //"/html/YoupiBanane/1.bla";      //"localhost/1.cgi";
	this->envMap["QUERY_STRING"] = req.getQueryString();     // "";
	this->envMap["SCRIPT_NAME"] = req.getPath(); //"/html/YoupiBanane/1.bla"; // req.getPath(); // "1.bla";   // ?? "1.cgi"
	this->envMap["PATH_INFO"] = "/" + req.getPath(); // "/html/YoupiBanane/1.bla"; //req.getPathInfo(); // "CGI/cgi_tester"; по дефолту "cgi_tester" or path/to/interpretier
	this->envMap["SERVER_SOFTWARE"] = ser.getEnvValue("SERVER_SOFTWARE");
	this->envMap["SERVER_PROTOCOL"] = ser.getEnvValue("SERVER_PROTOCOL");
	this->envMap["GATEWAY_INTERFACE"] = "CGI/1.1"; // ser.getEnvValue("GATEWAY_INTERFACE");
	this->envMap["REQUEST_METHOD"] = req.getMethod();
	if(req.getHeaders().find("AUTHORIZATION") != req.getHeaders().end() &&
					!req.getHeaders().find("AUTHORIZATION")->second.empty()) {
		std::string tmp = req.getHeaders().find("AUTHORIZATION")->second;
		size_t pos = tmp.find(' ');
		if(pos != std::string::npos) {
			this->envMap["AUTH_TYPE"] = tmp.substr(0, pos);  //?? default Basic,
			std::string tmpFoIdent = tmp.substr(pos + 1);
			tmpFoIdent = b64decode(tmpFoIdent.c_str(), tmpFoIdent.size());
			if((pos = tmpFoIdent.find(':')) != std::string::npos) {
				this->envMap["REMOTE_USER"] = tmpFoIdent.substr(0, pos);
				this->envMap["REMOTE_IDENT"] = tmpFoIdent.substr(pos + 1);
			}
		}
	}
	if (req.getHeaders().find("CONTENT-LENGTH") != req.getHeaders().end())
		this->envMap["CONTENT_LENGTH"] = req.getHeaders().find("CONTENT-LENGTH")->second;
	else
		this->envMap["CONTENT_LENGTH"] = "";
	if (req.getHeaders().find("CONTENT-TYPE") != req.getHeaders().end())
		this->envMap["CONTENT_TYPE"] = req.getHeaders().find("CONTENT-TYPE")->second;
	else
		this->envMap["CONTENT_TYPE"] = "";
	char dir[1024];
	if (getcwd(dir, 1024) == NULL)
		throw std::runtime_error("error getcwd. 500 Internal Server Error");
	this->envMap["PATH_TRANSLATED"] = this->envMap["PATH_INFO"][0] == '/' ?
		std::string(dir) + this->envMap["PATH_INFO"] : std::string(dir) + "/" + this->envMap["PATH_INFO"];
	this->envMap["REMOTE_ADDR"] = "127.0.0.1"; //ser.getEnvValue("REMOTE_ADDR");
	this->envMap["SERVER_NAME"] = ser.getEnvValue("SERVER_NAME");
	this->envMap["SERVER_PORT"] = ser.getEnvValue("SERVER_PORT");
	this->RequestBody = req.getBody();
	PathInfo = req.getPathInfo();
	this->argv = new char *[3]; // проверка маллокав
	this->argv[0] = strdup(req.getPathInfo().c_str()); // strdup("cgi_tester");
	this->argv[1] = strdup(envMap.find("REQUEST_URI")->second.c_str());  // проверка маллокав
	this->argv[2] = NULL;
	std::cout << "ARGV 0 " << this->argv[0] << std::endl;
	std::cout << "ARGV 1 " << this->argv[1] << std::endl;

}

void CGI::creatENV() {
	std::string tmp;
	envCount = envMap.size();
	env = new char *[envCount + 1]; // проверка маллокав
	std::map <std::string, std::string>:: iterator it = envMap.begin();
	for (int i = 0; it != envMap.end(); it++, i++) {
		tmp = it->first + "=" + it->second;
		env[i] = strdup(tmp.c_str()); // проверка маллокав
	}
	env[envMap.size()] = NULL;

	int i = 0;
	while(i < envMap.size())
	{
		std::cout << "ENV "<< i << " " << env[i] << std::endl;
		i++;
	}
}

// содержимое скрипта поступает на fd[0](STDIN подменяется fd[0])
// результат на STDOUT(подменненный на fdF)
// в fd[1] - тело запроса

void CGI::exec() {
	pid_t pid;
	int ex;
	int fdF = open("./myFile", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU | S_IRWXO | S_IRWXG);
	int status;
	if (pipe(fd) != 0)
		throw std::runtime_error("cannot pipe. code: 500 Internal Server Error");
	pid = fork();
	if(pid < 0) {
		throw std::runtime_error("cannot fork. code: 500 Internal Server Error");
	}
	else if(pid == 0) { // ребенок
		close(fd[1]);
		if (dup2(fd[0], STDIN) < 0)
			throw std::runtime_error("Cannot dup, 1. code: 500 Internal Server Error");
		if (dup2(fdF, STDOUT) < 0)
			throw std::runtime_error("Cannot dup, 2. code: 500 Internal Server Error");
		ex = execve(PathInfo.c_str(), argv , env);
		exit(ex);
	}
	else { // родитель
		close(fd[0]);
		write(fd[1], RequestBody.c_str(), RequestBody.length());// atoi(this->envMap["CONTENT_LENGTH"].c_str())
		close(fd[1]);
		std::cerr << "Waiting..." << std::endl;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status)) {
			status = WEXITSTATUS(status);
		}
		std::cout << "status: " << status << std::endl;
		if(status != 0)
			throw std::runtime_error("Cannot execve. code: 500 Internal Server Error");
		close(fdF);
		close(fd[0]);
	}
}





