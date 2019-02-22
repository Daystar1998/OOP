// Author: Matthew Day

#include"String.h"

String::String()
	: string() {
}

String::String(const string &newString)
	: string(newString) {
}

String::String(const char* const newString)
	: string(newString) {
}

String::String(int i)
	: string(to_string(i)) {
}

String::String(char c)
	: string(to_string(c)) {
}

void String::prepend(const String &other) {

	String result(other);

	result.append(*this);

	this->assign(result);
}

void String::toUpper() {

	if (!this->empty()) {

		int length = this->length();
		char *result = new char[length + 1];

		for (int i = 0; i < length; i++) {
			
			if (this->at(i) >= 97 && this->at(i) <= 122) {

				result[i] = this->at(i) - 32;
			} else {

				result[i] = this->at(i);
			}
		}

		result[length] = '\0';

		this->assign(result);

		delete[] result;
	}
}

void String::toLower() {

	if (!this->empty()) {

		int length = this->length();
		char *result = new char[length + 1];

		for (int i = 0; i < length; i++) {

			if (this->at(i) >= 65 && this->at(i) <= 90) {

				result[i] = this->at(i) + 32;
			} else {

				result[i] = this->at(i);
			}
		}

		result[length] = '\0';

		this->assign(result);

		delete[] result;
	}
}

void String::trimStart() {

	if (!this->empty()) {

		int start;

		for (start = 0; start < this->length(); start++) {

			if (!isWhiteSpace(this->at(start))) {

				break;
			}
		}

		this->assign(this->substr(start, this->length() - start));
	}
}

void String::trimEnd() {

	if (!this->empty()) {

		int end;

		for (end = this->length() - 1; end >= 0; end--) {

			if (!isWhiteSpace(this->at(end))) {

				break;
			}
		}

		this->assign(this->substr(0, end + 1));
	}
}

void String::trim() {

	this->trimStart();
	this->trimEnd();
}

bool String::isWhiteSpace(char c) {

	bool result = false;

	switch (c) {

	case ' ':
	case '\n':
	case '\r':
	case '\t':
	case '\v':

		result = true;
		break;
	}

	return result;
}