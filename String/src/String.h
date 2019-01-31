#pragma once

#include<iostream>
#include<stack>
#include<string>

using namespace std;

class String {

private:

	char* pString;
public:

	String();

	String(const String& newString);

	String(const char* const newString);

	String(int i);

	String(char c);

	~String();

	void set(const char* const newString);

	void set(const String& newString);

	void set(int i);

	void set(char c);

	void write(std::ostream& out);

	void append(const String &other);

	void prepend(const String &other);

	bool contains(const String &other) const;

	void insert(const String &other, int index);

	String subString(int start, int length) const;

	bool equals(const String &other) const;

	bool isEmpty() const; // empty when the pointer is null or the first character is \0

	int length() const;
private:

	void destroy();
};