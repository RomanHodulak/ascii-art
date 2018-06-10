#include "InvalidFileException.h"

const char * InvalidFileException::what() const noexcept {
	return this->message.c_str();
}

InvalidFileException::InvalidFileException(const std::string & type, const std::string & file) {
	this->message = "Invalid ";
	this->message += type;
	this->message += " file \"";
	this->message += file;
	this->message += "\".";
}

InvalidFileException::InvalidFileException(const std::string & type, const std::string & file, const std::string & reason) {
	this->message = "Invalid ";
	this->message += type;
	this->message += " file \"";
	this->message += file;
	this->message += "\": ";
	this->message += reason;
}
