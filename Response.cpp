#include "Response.hpp"

// Connection: alive/close
// Content-Language/Content-Length/Content-Location/Content-Type
// Date
// Last-Modified
// Location <- redirection or when a new resource has been created
// Retry-After: 120 / Fri, 07 Nov 2014 23:59:59 GMT | seconds/ HTTP date
// Server
// Transfer-Encoding: chunked / compress / deflate / gzip / identity

// WWW-Authenticate: Indicates the authentication scheme that should be used to access the requested entity. WWW-Authenticate: Basic
// 401 (Unauthorized) -> WWW-Authenticate
// A server MAY generate a WWW-Authenticate header field in other response messages to indicate that supplying credentials (or different credentials) might affect the response.


Response::Response():
	_version("HTTP/1.1"),
	_statusCode(200),
	_respSize(0),
	_statusMessage("ОК"),
	_body(""),
	_toClose(false){}

std::string	Response::setStatusMessage(int code){
	switch(code){
		case 400: return "Bad Request";
		case 401: return "Payment Required";
		case 403: return "Forbidden";
		case 404: return "Not Found";
		case 405: return "Method Not Allowed";
		case 406: return "Not Acceptable";
		case 408: return "Request Timeout";
		case 409: return "Conflict";
		case 410: return "Gone";
		case 411: return "Length Required";
		case 413: return"Payload Too Large";
		case 414: return "URI Too Long";
		case 415: return "Unsupported Media Type";
		case 417: return "Expectation Failed";
		case 426: return "Upgrade Required";
		case 500: return "Internal Server Error";
		case 501: return "Not Implemented";
		case 502: return "Bad Gateway";
		case 503: return "Service Unavailable";
		case 504: return "Gateway Timeout";
		case 505: return "HTTP Version Not Supported";
		case 506: return "Variant Also Negotiates";
		case 507: return "Insufficient Storage";
		case 508: return "Loop Detected";
		case 510: return "Not Extended";
		case 511: return "Network Authentication Required";
		default:
			return "OK";
	}
}
Response::~Response(){}

void	Response::setError(Server const &serv) {
	if (this->_toClose == true)
		_headers.insert(std::make_pair("Connection", "close"));
	else
		_headers.insert(std::make_pair("Connection", "alive"));

	_headers.insert(std::make_pair("Content-Language", "en"));
	_headers.insert(std::make_pair("Content-Type", "text/html"));
	if (serv.get_errorPath(this->_statusCode).empty()){
		this->_body = get_errorPage(this->_statusCode);
	}
	else{
		std::cout << serv.get_errorPath(this->_statusCode) << std::endl;
		std::ifstream	in(serv.get_errorPath(this->_statusCode));
		std::string		tmp("");
		while (getline(in, tmp)){
			this->_body.append(tmp + "\n");
		}
		this->_body.pop_back();
	}
	_headers.insert(std::make_pair("Content-Length", std::to_string(_body.size())));
	setDate();
	if (this->_statusCode == 405){
		 _headers.insert(std::make_pair("Allow", std::to_string(_body.size())));
	}
}

// 200 updated - 201 created 
// Content-Location
// Last-Modified

void	Response::execPUT(Client &client) {
	struct stat st;
	std::string tmp("");
	int file = open("myFile2", O_RDWR, 0666);
	std::string fileContent("");

	if (file != -1) {
		char buf[2];
		int ret;
		while ((ret = read(file, buf, 1) > 0)) {
			buf[ret] = '\0';
			fileContent.append(std::string(buf));
		}
		if (fileContent == client.getRequest().getBody()) {
			this->setStatusCode(200);
			setLastModified("myFile2");
		}
		else {
			close(file);
			int file = open("myFile2", O_RDWR | O_TRUNC, 0666);
			write(file, client.getRequest().getBody().c_str(), client.getRequest().getBody().length());
			this->setStatusCode(200);
        }
	}
	else {
		close(file);
		int file = open("myFile2", O_RDWR | O_CREAT, 0666);
		write(file, client.getRequest().getBody().c_str(), client.getRequest().getBody().length());
		this->setStatusCode(201);
	}
	setDate();
	if (this->_toClose == true)
		_headers.insert(std::make_pair("Connection", "close"));
	else
		_headers.insert(std::make_pair("Connection", "alive"));
	setContentLocation("myFile2", "./");
	close(file);
}

void	Response::execGET(Client &client){
	std::ifstream	file(client.getPathToFile());
	std::string		tmp("");
	if (file.is_open() == 0)
		throw std::exception();
	while (getline(file, tmp)){
		this->_body.append(tmp.append("\n"));
	}
	_body.pop_back();
	std::cout << client.getPathToFile() << std::endl;
	this->_headers.insert(std::make_pair("Content-Length", std::to_string(this->_body.size())));
	if (client.getMethod() == "HEAD")
		_body.clear();
	if (this->_toClose == true)
		_headers.insert(std::make_pair("Connection", "close"));
	else
		_headers.insert(std::make_pair("Connection", "alive"));
	
	setDate();
	setLastModified(client.getPathToFile());
	setContentType(client.getPathToFile());
	_headers.insert(std::make_pair("Content-Language", "en"));
}

void Response::parseCgiFile(Client &client) {
	std::ifstream file("./cgiFile", std::ifstream::in);
	std::string line("");

	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.find("Status:") != std::string::npos) {
				this->setStatusCode(atoi(line.substr(8, 3).c_str()));
			}
			else {
				if (line == "\r")
					break;
				size_t pos = line.find(':');
				std::pair<std::string, std::string> node;
				node.first = line.substr(0, pos);
				line.erase(0, pos + 2);
				node.second = line.substr(0, (line.length() - 1));
				this->_headers.insert(node);
			}
		}
		while (getline(file, line))
			this->_body.append(line);
	}
	else {
		std::cerr << "CGI, WHERE FILE ????" << std::endl;
	}
	file.close();
	int fd = open("./cgiFile", O_TRUNC);
	close(fd);
}

Response::Response(Server const &serv, Client &client):
	_version(serv.getEnvValue("SERVER_PROTOCOL")),
	_statusCode(client.getStatusCode()),
	_respSize(0),
	_statusMessage(setStatusMessage(client.getStatusCode())),
	_body(""),
	_toClose(client.getToClose()) {
		if (this->_statusCode  >= 400)
			setError(serv);
		else if (client.getWhere() == toCGI)
			parseCgiFile(client);
		else if (client.getMethod() == "GET" || client.getMethod() == "HEAD")
			execGET(client);
		else if (client.getMethod() == "PUT")
			execPUT(client);

}

size_t			Response::get_respSize(void) const {
	return _respSize;
}

std::string		Response::getResponse(void) {
	std::string		ret("");
	ret.append(this->_version);
	ret.append(" " + std::to_string(this->_statusCode));
	ret.append(" " + this->_statusMessage);
	ret.append("\r\n");
	std::map<std::string, std::string>::const_iterator it = _headers.begin();
	for (; it != _headers.end(); it++){
		ret.append(it->first + ": " + it->second + "\r\n");
	}
	ret.append("\r\n");
	if (!_body.empty()){
		ret.append(this->_body);
		ret.append("\r\n");
	}
	this->_respSize = ret.size();
	return ret;
}

Response::Response(Response const &other) {
	*this = other;
}

Response	&Response::operator=(Response const &other) {
	if (this != &other){
		this->_version = other._version;
		this->_statusCode = other._statusCode;
		this->_statusMessage = other._statusMessage;
		this->_headers = other._headers;
		this->_body = other._body;
		this->_toClose = other._toClose;
		this->_respSize = other._respSize;
	}
	return *this;
}

// setters
void	Response::set_version(std::string version) {
	this->_version = version;
}

void	Response::setStatusCode(int statusCode) {
	this->_statusCode = statusCode;
	this->_statusMessage = setStatusMessage(statusCode);
}

void	Response::set_statusMessage(std::string statusMessage) {
	this->_statusMessage = statusMessage;
}

void	Response::set_headers(std::map<std::string,std::string> headers) {
	this->_headers = headers;
}

void	Response::set_body(std::string body) {
	this->_body = body;
}

void	Response::setContentLocation(std::string const &pathToFile, std::string const &serverRoot){

	std::string tmp = pathToFile.substr(serverRoot.size() + 1, pathToFile.size());
	this->_headers.insert(std::make_pair("Content-Location", tmp));

}


void	Response::setContentType(std::string const &pathToFile){
	std::string file(pathToFile.substr(pathToFile.rfind('/'), pathToFile.size()));
	size_t pos;
	if ((pos = file.rfind('.')) == std::string::npos)
		this->_headers.insert(std::make_pair("Content-Type", "text/plain"));
	else{
		std::string extension(file.substr(pos, file.size()));
		std::cout << extension << std::endl;
		this->_headers.insert(std::make_pair("Content-Type", findMimeType(extension)));
	}
}

void	Response::setLastModified(std::string const &file) {
	struct tm		timeinfo;
	char			buffer[30];
	struct stat		st;

	stat(file.c_str(), &st);
	std::string time(std::to_string(st.st_mtimespec.tv_sec));
	strptime(time.c_str(), "%s", &timeinfo);
	strftime(buffer,30,"%a, %d %b %G %T %Z", &timeinfo);
	this->_headers.insert(std::make_pair("Last-Modified", (std::string)(buffer)));
}

void	Response::setDate(void){
	struct tm		timeinfo;
	char			buffer[30];
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	std::string time(std::to_string(tv.tv_sec));
	strptime(time.c_str(), "%s", &timeinfo);
	strftime (buffer,30,"%a, %d %b %G %T %Z", &timeinfo);
	this->_headers.insert(std::make_pair("Date", (std::string)(buffer)));
}

// getters
std::string 	Response::get_version(void) const {
	return _version;
}

int			Response::get_statusCode(void) const {
	return _statusCode;
}

std::string		Response::get_statusMessage(void) const {
	return _statusMessage;
}

std::map<std::string,std::string>		&Response::get_headers(void) {
	return _headers;
}

std::string		Response::get_body(void) const {
	return _body;
}


