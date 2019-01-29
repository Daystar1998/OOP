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

// Author: Dana Steil
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
void String::set(const char* const newString) {

	destroy();

	if (newString != NULL) {

		pString = new char[strlen(newString) + 1];
		strcpy(pString, newString);
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

// Author: Dana Steil
bool String::isEmpty() {

	//when pString is null the condition will short circuit
	return (pString == NULL || strlen(pString) == 0);
}