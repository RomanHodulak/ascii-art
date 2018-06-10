#ifndef ASCII_ART_INVALIDFILEEXCEPTION_H
#define ASCII_ART_INVALIDFILEEXCEPTION_H

#include <exception>
#include <string>

class InvalidFileException : public std::exception {
private:

	std::string message;

public:

	/**
	 * Constructs new instance.
	 *
	 * @param type Expected file type e.g. BMP.
	 * @param file File name to show in the message.
	 */
	InvalidFileException(const std::string & type, const std::string & file);

	/**
	 * Constructs new instance.
	 *
	 * @param type Expected file type e.g. BMP.
	 * @param file File name to show in the message.
	 * @param reason Additional information about the cause of the exception.
	 */
	InvalidFileException(const std::string & type, const std::string & file, const std::string & reason);

	const char * what() const noexcept override;
};

#endif //ASCII_ART_INVALIDFILEEXCEPTION_H
