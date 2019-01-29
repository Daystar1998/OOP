// Author: Matthew Day

#include"String.h"

// Author: Dana Steil
String::String() {

	pString = NULL;
}

// Author: Dana Steil
String::String(const String& newString) {

	pString = NULL;
	set(newString.pString);
}

// Author: Dana Steil
String::String(const char* const newString) {

	pString = NULL;
	set(newString);
}

String::String(int i) {

	pString = NULL;
	set(i);
}

String::String(char c) {

	pString = NULL;
	set(c);
}

// Author: Dana Steil
String::~String() {

	destroy();
}

// Author: Dana Steil
void String::destroy() {

	if (pString != NULL) {

		delete[] pString;
		pString = NULL;
	}
}

// Author: Dana Steil
// Edited by Matthew Day to use strcpy_s instead of the depreciated strcpy
void String::set(const char* const newString) {

	destroy();

	if (newString != NULL) {

		int length = strlen(newString) + 1;
		pString = new char[length];
		strcpy_s(pString, length, newString);
	} else {

		pString = NULL;
	}
}

// Author: Dana Steil
void String::set(const String& newString) {

	set(newString.pString);
}

void String::set(char c) {

	destroy();

	pString = new char[2];

	pString[0] = c;
	pString[1] = '\0';
}

void String::set(int i) {

	destroy();

	stack<char> convertedChars;

	int current = i;

	if (i < 0) {

		convertedChars.push('-');
		current = -i;
	}

	do {

		char asciiCode = (char)(current % 10 + 48);
		convertedChars.push(asciiCode);

		current /= 10;
	} while (current > 0);

	int size = convertedChars.size();

	pString = new char[size + 1];

	for (int j = 0; j < size; j++) {

		pString[j] = convertedChars.top();
		convertedChars.pop();
	}

	pString[size] = '\0';
}

// Author: Dana Steil
void String::write(ostream& out) {

	if (pString != NULL) {

		out << pString;
	}
}

void String::append(const String &other) {

	char *result = new char[this->length() + other.length() + 1];

	if (!this->isEmpty()) {

		strcpy_s(result, this->length() + 1, this->pString);
	}

	if (!other.isEmpty()) {

		strcpy_s(result + this->length(), other.length() + 1, other.pString);
	}

	set(result);
}

void String::append(const char *other) {

	this->append(String(other));
}

void String::append(int i) {

	this->append(String(i));
}

void String::append(char c) {

	this->append(String(c));
}

void String::prepend(const String &other) {

	String result(other);

	result.append(*this);

	this->set(result);
}

void String::prepend(const char *other) {

	this->prepend(String(other));
}

void String::prepend(int i) {

	this->prepend(String(i));
}

void String::prepend(char c) {

	this->prepend(String(c));
}

bool String::contains(char c) {

	bool result = false;

	if (!isEmpty()) {

		int i = 0;

		while (pString[i] != '\0') {

			if (pString[i] == c) {

				result = true;
				break;
			}

			i++;
		}
	}

	return result;
}

// Author: Dana Steil
bool String::isEmpty() const {

	//when pString is null the condition will short circuit
	return (pString == NULL || strlen(pString) == 0);
}

int String::length() const {

	int result = 0;

	if (!isEmpty()) {

		result = strlen(pString);
	}

	return result;
}