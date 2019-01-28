// Author: Matthew Day

#include<iostream>
#include<string>
#include"String.h"

using namespace std;

// Author: Dana Steil
String::String() {

	pString = NULL;
}

// Author: Dana Steil
String::String(const char* const newString) {

	pString = NULL;
	set(newString);
}

// Author: Dana Steil
String::String(const String& newString) {

	pString = NULL;
	set(newString.pString);
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

// Author: Dana Steil
bool String::isEmpty() {

	//when pString is null the condition will short circuit
	return (pString == NULL || strlen(pString) == 0);
}

// Author: Dana Steil
void String::write(ostream& out) {

	if (pString != NULL) {

		out << pString;
	}
}