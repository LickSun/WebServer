#include "Client.hpp"

//////////////////////////   Coplin   \\\\\\\\\\\\\\\\\\\\\\\\\\

Client::Client():
	_sd(0),
	_flag(WAIT),
	_locPos(0),
	_where(toServer),
	_statusCode(200) {}

Client::Client(int sd):
	_sd(sd),
	_flag(WAIT),
	_locPos(0),
	_where(toServer),
	_statusCode(200) {}

Client::~Client() {}

bool operator==(const Client &c1, const Client &c2){
	if (&c1 == &c2)
		return true;
	return false;
}

//////////////////////////   Coplin   \\\\\\\\\\\\\\\\\\\\\\\\\\


//////////////////////////   Setters   \\\\\\\\\\\\\\\\\\\\\\\\\\

void	Client::setStatusCode(int code) {
	this->_statusCode = code;
}

void	Client::setSd(int sd) {
	this->_sd = sd;
}

void	Client::setFlag(int flag) {
	this->_flag = flag;
}

void	Client::setRequest(Request &reqv) {
	this->_request = reqv;
}

void	Client::setWhere(int where) {
	this->_where = where;
}

void	Client::setToClose(bool toClose) {
	this->_request.setToClose(toClose);
}

//////////////////////////   Setters   \\\\\\\\\\\\\\\\\\\\\\\\\\


//////////////////////////   Getters   \\\\\\\\\\\\\\\\\\\\\\\\\\

int		Client::getSd(void) const {
	return this->_sd;
}

int		Client::getFlag(void) const {
	return this->_flag;
}

Request	&Client::getRequest(void) {
	return this->_request;
}

void	Client::setLocPos(int pos){
	this->_locPos = pos;
}


int		Client::getLocPos(void) const{
	return this->_locPos;
}


int		Client::getStatusCode(void) const {
	return this->_statusCode;
}

const std::string &Client::getPathToFile() const {
	return pathToFile;
}

void Client::setPathToFile(const std::string &pathToFile) {
	this->pathToFile = pathToFile;
}

int Client::getWhere() const {
	return this->_where;
}

bool	Client::getToClose(void) const {
	return this->_request.getToClose();
}

std::string const	&Client::getMethod(void) const{
	return this->_request.getMethod();
}

//////////////////////////   Getters   \\\\\\\\\\\\\\\\\\\\\\\\\\


//////////////////////////   Update Methods   \\\\\\\\\\\\\\\\\\\\\\\\\\

void	Client::clear(void){
	this->_where = toServer;
	this->_flag = WAIT;
	this->_statusCode = 200;
	this->_request.reset();
	this->pathToFile.clear();
}

//////////////////////////   Update Methods   \\\\\\\\\\\\\\\\\\\\\\\\\\


