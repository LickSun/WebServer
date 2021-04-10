//
// Created by Kory Moaning on 3/20/21.
//

#include "RequestConfigMatch.hpp"

void	setErrorCode(const std::string& str, Client &client) {
	client.setStatusCode( atoi(str.c_str()));
	std::cerr << "error : " << str << std::endl;
}

std::vector<std::string>	splitString(std::string str) {
	std::vector<std::string> ret;
	size_t pos;
	while ((pos = str.find(' ')) != std::string::npos) {
		ret.push_back(str.substr(0, pos));
		str.erase(0, pos + 1);
	}
	ret.push_back(str);
	return ret;
}

size_t	countChar(const std::string& str, char c) {
	size_t len = str.length();
	size_t count = 0;
	for (size_t i = 0; i < len; ++i) {
		if (str[i] == '/')
			count++;
	}
	return count;
}

std::string			b64decode(const void* data, const size_t len)
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

int	compareLocation(std::string &uri, location_t &loc, std::string &res) {
	std::string name = loc._name;
	int len = name.length();
	if (len > 1)
		len -= 1;
	if(name.compare(0, len, uri.substr(0,len)) == 0) {
		res = name;
		if (len > 1)
			uri.erase(0, len);
		return 1;
	}
	else if (std::regex_match(uri.substr(0,len), std::regex(name))) {
		res = name;
		uri.erase(0, len);
		return 1;
	}
	return 0;
}

std::string	getLocation(std::string &uri, Server &ser, int &pos) {
	std::string res;
	std::vector<location_t> tmp = ser.get_locations();
	size_t count = tmp.size();
	size_t i = 0;
	while (i < count) {
		if (compareLocation(uri, tmp[i], res))
			break;
		i++;
	}
	if (i == count)
		throw std::runtime_error("404");
	pos = i;
	return res;
}

int	autoIndex(std::string &ret, Server const &serv, const location_t &location) {
	if (location._directives.find("autoindex")->second == "on")
		return 1;
//		getListing(ret, serv, location);										// листинг директорий
	else
		throw std::runtime_error("404");		//"Index Not Found, code: 403");
}

int	checkIndex(std::string &ret, Server const &serv, const location_t &location) {
	struct stat info;
	std::string tmp;
	std::string str = location._directives.find("index")->second;
	if (!str.empty()) {
		std::vector<std::string> index = splitString(str);
		size_t size = index.size();
		size_t i;
		for (i = 0; i < size; ++i) {
			tmp = ret + index[i];
			if(stat(tmp.c_str() , &info) == 0)
				break;
		}
		ret = tmp;
		if(i == size) {									// не нашла index files
			ret = tmp;
			return (autoIndex(ret, serv, location));
		}
		else											// нашла индекс, добавила его к директории
			ret = tmp;
	}
	else												// нет index в location
		return (autoIndex(ret, serv, location));
	return 0;
}

std::string	getPath(std::string &uri, int &loc, Request &req, const Server &ser) {
	struct stat info;
	std::string tmp;
	tmp = ser.get_locations()[loc]._directives.find("root")->second + uri;
	size_t count = countChar(tmp, '/');
	size_t pos = tmp.find('/');
	std::string ret = tmp.substr(0, pos + 1);
	tmp.erase(0, pos + 1);
	const char *path = ret.c_str();
	for (size_t i = 0; i <= count; ++i) {
		if (stat(path, &info) == 0){
			if ((pos = tmp.find('/')) == std::string::npos) {
				if(tmp.length())
					pos = tmp.length() - 1;
			}
			ret += tmp.substr(0, pos + 1);
			tmp.erase(0, pos + 1);
			path = ret.c_str();
			continue;
		}
		break;
	}
	size_t last = ret.length() - 1;
	if (ret[last] == '/' && tmp.length() == 0) {			//папка, checkIndex
		if (checkIndex(ret, ser, ser.get_locations()[loc])) {
			req.setPath(ret);
			throw std::runtime_error("243");
		}
	} else if(ret[last] == '/' && tmp.length() != 0) {		//точно файл, проверить его наличие
		ret.erase(ret.length() - 1, 1);
		path = ret.c_str();
		req.setPathInfo(tmp);
		if (stat(path, &info) != 0)
			throw std::runtime_error("404");				//"paht not found. code: 404 Not Found";
	} else {
		path = ret.c_str();
		if (stat(path, &info) != 0) {
			if (req.getMethod() != "PUT" && req.getMethod() != "POST")
				throw std::runtime_error("404");
		}
		else {
			if (S_ISDIR(info.st_mode)) {
				ret = ret + '/';
				if (checkIndex(ret, ser, ser.get_locations()[loc])) {
					req.setPath(ret);
					throw std::runtime_error("243");
				}

			}
		}
	}
	req.setPath(ret);
	return (ret);
}

void	compareHostName(const std::string& hostName, const std::string& ip, const std::string& servName) {
	if(hostName != ip && hostName != servName)
		throw std::runtime_error("400");
}

void	comparePort(const std::string& port, const std::string& servPort) {
	if(port != servPort)
		throw std::runtime_error("400");
}

int	checkHost(int pos, std::string &uri, Server &ser) {
	std::string port;
	std::string host;
	std::string hostName;
	size_t colon;
	host.assign(uri, 0, pos);
	if(host != ser.get_serverName() && host != (ser.get_serverName() + ":" + ser.get_port()) && host != (ser.get_ip() + ":" + ser.get_port())) {
		if((colon = host.find(':')) != std::string::npos) {
			hostName.assign(host, 0, colon);
			port = host.substr(colon + 1);
			compareHostName(hostName, ser.get_ip(), ser.get_serverName());
			comparePort(port, ser.get_port());
		}
		else
			compareHostName(host, ser.get_ip(), ser.get_serverName());
		uri.erase(0, host.length());
	}
	else {
		if ((colon = host.find(':') != std::string::npos)) {
			hostName.assign(host, 0, colon);
			port = host.substr(colon + 1);
			uri.erase(0, host.length());
		}
	}
	return 0;
}

void	checkBodySize(Server &ser, int locIndex, Request &req) {
	std::string maxBody;
	maxBody = ser.get_locations()[locIndex]._directives.find("max_body_size")->second;
	if (!maxBody.empty()) {
		size_t len = atoi(maxBody.c_str());
		if (req.getBody().size() > len)
			throw std::runtime_error("413");
	}
}

bool	getWhere(std::map<std::string, std::string> dir, Request &req) {
	std::string extReq;
	std::vector<std::string> extConfArr = splitString(dir.find("cgi_extensions")->second);
	size_t pos;
	if((pos = req.getPath().rfind('.')) != std::string::npos)
		extReq = req.getPath().substr(pos);
	size_t i;
	for (i = 0; i < extConfArr.size(); ++i) {
		if (extReq == extConfArr[i])
			break;
	}
	if (i == extConfArr.size())
		return false;
	if(req.getPathInfo() != dir.find("cgi_path")->second)
		return false;
	const std::string& method = req.getMethod();
	if(method == "GET" || method == "HEAD" || method == "POST")
		return true; // true == cgi in Where
	return false;
}
bool passUser(std::string user, std::string pas, const std::string &path) {
	std::string line;
	std::ifstream file(path);
	if (!file.is_open())
		throw std::runtime_error("500");
	while (getline(file, line)){
		trimString(line);
		if (!line.empty()) { // find user, match pass, if ok file.close(), return true.
			size_t pos = line.find(':');
			if(pos != std::string::npos) {
				if (line.substr(0, pos) == user && line.substr(pos + 1) == pas) {
					file.close();
					return true;
				}
			}
		}
	}
	file.close();
	return false;
}

bool checkAutorization(Request &req, int locIndex, Server &ser) {
	std::map<std::string, std::string> map =  ser.get_locations()[locIndex]._directives;
	std::string path;
	if(map.find("auth_basic") != map.end()) {
		if(req.getHeaders().find("AUTHORIZATION") == req.getHeaders().end() || req.getHeaders().find("AUTHORIZATION")->second.empty())
			return false;
		size_t pos = req.getHeaders().find("AUTHORIZATION")->second.rfind(' ');
		if(pos == std::string::npos)
			return false;
		std::string authTipe = req.getHeaders().find("AUTHORIZATION")->second.substr(0, pos); //default Basic
		if(authTipe != "Basic")
			return false;
		std::string tmpFoIdent = req.getHeaders().find("AUTHORIZATION")->second.substr(pos + 1);
		tmpFoIdent = b64decode(tmpFoIdent.c_str(), tmpFoIdent.size());
		if((pos = tmpFoIdent.find(':')) == std::string::npos)
			return false;
		if(map.find("auth_basic_user_file") != map.end()) {
			path = map.find("auth_basic_user_file")->second;// сравнить имя и пароль с конфигом, дешифратор "YnVsaW5hOk15TWVnYUJlc3RQYXNz" => bulina:MyMegaBestPass;
			return passUser(tmpFoIdent.substr(0, pos), tmpFoIdent.substr(pos + 1), path);
		}
		else
			throw std::runtime_error("500");
	}
	return true;
}

void	checkConf(Server &ser, int locIndex, Request &req, Client &client) {
	if(ser.get_locations()[locIndex]._directives.find("method") != ser.get_locations()[locIndex]._directives.end()) {
		std::vector<std::string> methods = splitString(ser.get_locations()[locIndex]._directives.find("method")->second);
		size_t size = methods.size();
		size_t i;
		for (i = 0; i < size; ++i) {
			if(methods[i] == req.getMethod())
				break;
		}
		if(i == size)
			throw std::runtime_error("405");
	}
	checkBodySize(ser, locIndex, req);
	if (!checkAutorization(req, locIndex, ser))
		throw std::runtime_error("401");
	if (getWhere(ser.get_locations()[locIndex]._directives, req))
		client.setWhere(toCGI);
	else {
		if (req.getMethod() == "POST")
			throw std::runtime_error("500");
		client.setWhere(toServer);
	}
}

int RequestConfigMatch(Client &client, Server &ser) {
	Request &req = client.getRequest();
	std::string uri = req.getPath();
	std::string pathToScript;
	int loc = -1;
	size_t pos;
	try {
		if((pos = uri.rfind('?')) != std::string::npos)
			uri.erase(pos);
		pos = 0;
		if(uri.compare(0, 7, "http://") == 0) {
			uri.erase(0, 7);
			if((pos = uri.find('/')) != std::string::npos)
				checkHost(pos, uri, ser);
		}
		getLocation(uri, ser, loc);
		client.setLocPos(loc);
		pathToScript = getPath(uri, loc, req, ser);
		client.setPathToFile(pathToScript);
		checkConf(ser, loc, req, client);
	}
	catch (std::exception &exception) {
		client.setPathToFile(req.getPath());
		setErrorCode(exception.what(), client);
		return -1;
	}
	return client.getWhere();
}