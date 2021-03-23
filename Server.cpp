#include "Server.hpp"

const std::array<std::string, 17> Server::_env_names = {"AUTH_TYPE", "CONTENT_LENGTH",
		"CONTENT_TYPE", "GATEWAY_INTERFACE", "PATH_INFO", "PATH_TRANSLATED", "QUERY_STRING",
		"REMOTE_ADDR", "REMOTE_IDENT", "REMOTE_USER", "REQUEST_METHOD", "REQUEST_URI",
		"SCRIPT_NAME", "SERVER_NAME", "SERVER_PORT", "SERVER_PROTOCOL", "SERVER_SOFTWARE"};

Server::Server():
	_master_socket(0),
	_addrlen(0),
	_serverName(""),
	_ip(""),
	_port(""),
	_root(""),
	_maxBodySize(""),
	_maxSd(0){}

Server::~Server(){}

void		Server::sortLocations(void){
	std::vector<location_t>::iterator	it = _locations.begin();
	for (; it != _locations.end(); it++){
		if (it->_name.front() != '/')
			it->_name.insert(it->_name.begin(), '/');
		if (it->_name.back() != '/')
			it->_name.push_back('/');
	}
	std::sort(_locations.begin(), _locations.end(), location_tCompare);
}

void		Server::fullConfigEnvironment(void){
	this->_env.insert(std::make_pair<std::string, std::string>("AUTH_TYPE", "Basic"));
	this->_env.insert(std::make_pair<std::string, std::string>("GATEWAY_INTERFACE", "CGI/1.1"));
	this->_env.insert(std::make_pair<std::string, std::string>("SERVER_NAME", this->_serverName));
	this->_env.insert(std::make_pair<std::string, std::string>("SERVER_PORT", this->_port));
	this->_env.insert(std::make_pair<std::string, std::string>("SERVER_PROTOCOL", "HTTP/1.1"));
	this->_env.insert(std::make_pair<std::string, std::string>("SERVER_SOFTWARE", "TOXIGEN/1.0"));
}

void		Server::fullBasicDirectives(void){
	if (_serverName.empty())
		_serverName = _ip + ":" + _port;
	if (_root.empty())
		_root = ".";
	if (_maxBodySize.empty())
		_maxBodySize = "10000";

	std::vector<location_t>::iterator it = _locations.begin();
	for (; it < _locations.end(); it++){
		if (it->_directives.find("root") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("root", ""));
		if (it->_directives.find("max_body_size") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("max_body_size", _maxBodySize));
		if (it->_directives.find("method") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("method", "GET HEAD PUT POST"));
		if (it->_directives.find("autoindex") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("autoindex", "on"));
		if (it->_directives.find("cgi_extensions") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("cgi_extensions", ".php"));
		if (it->_directives.find("cgi_path") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("cgi_path", "/usr/bin/php"));
		if (it->_directives.find("upload_storage") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("upload_storage", "/storage"));
		if (it->_directives.find("index") == it->_directives.end())
			it->_directives.insert(std::make_pair<std::string, std::string>("index", "index.php index.html"));
	}
}

Server	&Server::operator=(Server const &other){
	if (this != &other){
		this->_master_socket = other._master_socket;
		this->_addrlen = other._addrlen;
		this->_addr = other._addr;
		this->_maxSd = other._maxSd;
		this->_env = other._env;

		this->_serverName = other._serverName;
		this->_ip = other._ip;
		this->_port = other._port;
		this->_root = other._root;
		this->_maxBodySize = other._maxBodySize;
		this->_errorPages = other._errorPages;
		this->_locations = other._locations;
	}
	return *this;
}

Server::Server(Server const &other){
	*this = other;
}

int			Server::get_maxSd(void) const{
	return _maxSd;
}


void		Server::FD_reset(fd_set *to_set){
	std::vector<Client>::const_iterator it = this->_clients.begin();
	_maxSd = this->_master_socket;

	for (; it != this->_clients.end(); it++){
		int sd = it->getSd();
		if (sd > 0)
			FD_SET(sd, to_set);
		if (_maxSd < sd)
			_maxSd = sd;
	}
}

std::string const	&Server::getLocationMethods(int pos) const{
	return this->_locations[pos]._directives.find("method")->second;
}


void	Server::create_master_socket(int domain, int type, int protocol){
	_master_socket = create_socket(domain, type, protocol);
	allow_mul_cons_socket(_master_socket);
}

void	Server::set_address_socket(const char *ip, int port, int domain){
	_addr.sin_addr.s_addr = inet_addr(ip);
	_addr.sin_port = htons(port); //(port << 8) >> 8
	_addr.sin_family = domain;
	_addrlen = sizeof(_addr);
	// _addr.
}

void	Server::bind_master_socket(void){
	bind_socket(this->_master_socket, &(this->_addr), this->_addrlen);
}

int		Server::accept_master_socket(void){
	int new_socket;
	sockaddr_in addr;
	if ((new_socket = accept(_master_socket, (struct sockaddr *)&addr, (socklen_t*)&_addrlen)) < 0){
			std::cerr << "Accept failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	this->_env.insert(make_pair("REMOTE_ADDR", ipToString(addr.sin_addr.s_addr)));
	return (new_socket);
}

// setters

void	Server::set_serverName(const std::string &_name){
	this->_serverName = _name;
}

void	Server::set_ip(const std::string& ip){
	this->_ip = ip;
}

void	Server::set_port(const std::string& port){
	this->_port = port;
}

void	Server::set_root(const std::string& root){
	this->_root = root;
}

void	Server::set_maxBodySize(const std::string& len){
	this->_maxBodySize = len;
}

void	Server::add_errorPage(const std::pair<int, std::string> &page){
	this->_errorPages.insert(page);
}

void	Server::set_locations(std::vector<location_t>& locations){
	this->_locations = locations;
}

void	Server::set_master_socket(const int socket){
	this->_master_socket = socket;
}

void	Server::set_addrlen(const socklen_t& len){
	this->_addrlen = len;
}

void	Server::set_sockaddress(const sockaddr_in& addr){
	this->_addr = addr;
}


	// getters

std::string			Server::get_port(void) const{
	return _port;
}

std::string	Server::get_root(void) const{
	return _root;
}

std::string			Server::get_maxBodySize(void) const{
	return _maxBodySize;
}

std::string	Server::get_serverName(void) const{
	return _serverName;
}

std::string	Server::get_ip(void) const{
	return _ip;
}

std::string	Server::get_errorPath(int code) const{
	std::map<int, std::string>::const_iterator it = this->_errorPages.begin();
	if ((it = this->_errorPages.find(code)) != this->_errorPages.end()){
		return it->second;
	}
	return "";
}

int			Server::get_master_socket(void) const{
	return _master_socket;
}

socklen_t	Server::get_addrlen(void) const{
	return _addrlen;
}

sockaddr_in const	&Server::get_sockaddress(void) const{
	return _addr;
}

std::vector<location_t>	Server::get_locations(void) const{
	return _locations;
}


size_t		Server::delete_client(size_t index){
	if (index >= this->_clients.size())
		return -1;
	this->_clients.erase(this->_clients.begin() + index -1);
	return this->_clients.size();
}

// for clients

void		Server::add_client(int newSd){
	this->_clients.push_back(Client(newSd));
}

size_t				Server::get_clientCount(void) const{
	return this->_clients.size();
}

int					Server::get_clientsd(size_t index) const{
	if (index > this->_clients.size())
		return -1;
	else
		return this->_clients[index - 1].getSd();
}

Client		&Server::get_Client(int index){
	if (index > this->_clients.size())
		throw std::exception();
	else
		return this->_clients[index - 1];
}

std::string	Server::getEnvValue(std::string	key) const{
	std::map<std::string, std::string>::const_iterator it = this->_env.find(key);
	if (it == this->_env.end())
		throw std::exception();
	else
		return it->second;
}
