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

	// Convert to unsigned int because turning INT_MIN positive results in too large a number for a regular int to hold and just returned the same value as INT_MIN
	unsigned int current = (unsigned int)i;

	do {

		char asciiCode = (char)(current % 10 + 48);
		convertedChars.push(asciiCode);

		current /= 10;
	} while (current > 0);

	if (i < 0) {

		convertedChars.push('-');
	}

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

	delete[] result;
}

void String::prepend(const String &other) {

	String result(other);

	result.append(*this);

	this->set(result);
}

bool String::contains(const String &other) const {

	bool result = false;

	if (!this->isEmpty() && !other.isEmpty()) {

		for (int i = 0; this->length() - i >= other.length(); i++) {

			if (this->pString[i] == other.pString[0]) {

				bool matching = true;

				for (int j = 1; j < other.length(); j++) {

					if (this->pString[++i] != other.pString[j]) {

						matching = false;
						break;
					}
				}

				if (matching) {

					result = true;
					break;
				}
			}
		}
	}

	return result;
}

void String::insert(const String &other, int index) {

	if (!other.isEmpty()) {

		if (index < 0) {

			this->prepend(other);
		} else if (index >= this->length()) {

			this->append(other);
		} else {

			char *result = new char[this->length() + other.length() + 1];

			int i = 0;

			for (; i < index; i++) {

				result[i] = this->pString[i];
			}

			for (; i < index + other.length(); i++) {

				result[i] = other.pString[i - index];
			}

			for (; i < this->length() + other.length() + 1; i++) {

				result[i] = this->pString[i - other.length()];
			}

			this->set(result);

			delete[] result;
		}
	}
}

String String::subString(int start, int length) const {

	String result;

	if (!this->isEmpty() && length > 0 && start < this->length()) {

		int begin = start;

		if (begin < 0) {

			begin = 0;
		}

		int end = begin + length;

		if (this->length() < end) {

			end = this->length();
		}

		char *data = new char[end - begin + 1];

		for (int i = begin; i < end; i++) {

			data[i - begin] = this->pString[i];
		}

		data[end - begin] = '\0';

		result.set(data);

		delete[] data;
	}

	return result;
}

void String::toUpper() {

	if (!this->isEmpty()) {

		int length = this->length();
		char *result = new char[length + 1];

		for (int i = 0; i < length; i++) {

			if (this->pString[i] >= 97 && this->pString[i] <= 122) {

				result[i] = this->pString[i] - 32;
			} else {

				result[i] = this->pString[i];
			}
		}

		result[length] = '\0';

		this->set(result);

		delete[] result;
	}
}

void String::toLower() {

	if (!this->isEmpty()) {

		int length = this->length();
		char *result = new char[length + 1];

		for (int i = 0; i < length; i++) {

			if (this->pString[i] >= 65 && this->pString[i] <= 90) {

				result[i] = this->pString[i] + 32;
			} else {

				result[i] = this->pString[i];
			}
		}

		result[length] = '\0';

		this->set(result);

		delete[] result;
	}
}

void String::trimStart() {

	if (!this->isEmpty()) {

		int start;

		for (start = 0; start < this->length(); start++) {

			if (!isWhiteSpace(this->pString[start])) {

				break;
			}
		}

		this->set(this->subString(start, this->length() - start));
	}
}

void String::trimEnd() {

	if (!this->isEmpty()) {

		int end;

		for (end = this->length(); end >= 0; end--) {

			if (!isWhiteSpace(this->pString[end])) {

				break;
			}
		}

		this->set(this->subString(0, end));
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

char String::at(int index) const {

	char result = '\0';

	if (!this->isEmpty() && index >= 0 && index < this->length()) {

		result = this->pString[index];
	}

	return result;
}

bool String::equals(const String &other) const {

	bool result = false;

	if (this->isEmpty() && other.isEmpty()) {

		result = true;
	} else if (this->length() == other.length()) {

		bool matching = true;

		for (int i = 0; i < this->length(); i++) {

			if (this->pString[i] != other.pString[i]) {

				matching = false;
				break;
			}
		}

		if (matching) {

			result = true;
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