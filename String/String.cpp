#include<iostream>
#include<string>
#include"String.h"

using namespace std;

String::String() {

	pString = NULL;
}

String::String(const char* const newString) {

	pString = NULL;
	set(newString);
}

String::String(const String& newString) {

	pString = NULL;
	set(newString.pString);
}

String::~String() {

	destroy();
}

void String::destroy() {

	if (pString != NULL) {

		delete[] pString;
		pString = NULL;
	}
}

void String::set(const char* const newString) {

	destroy();

	if (newString != NULL) {

		pString = new char[strlen(newString) + 1];
		strcpy(pString, newString);
	} else {

		pString = NULL;
	}
}

void String::set(const String& newString) {

	set(newString.pString);
}

bool String::isEmpty() {

	//when pString is null the condition will short circuit
	return (pString == NULL || strlen(pString) == 0);
}

void String::write(ostream& out) {

	if (pString != NULL) {

		out << pString;
	}
}