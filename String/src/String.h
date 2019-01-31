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

	explicit String(const char* const newString);

	explicit String(int i);

	explicit String(char c);

	~String();

	void set(const char* const newString);

	void set(const String& newString);

	void set(int i);

	void set(char c);

	void write(std::ostream& out);

	void append(const String &other);

	void append(const char *other);

	void append(int i);

	void append(char c);

	void prepend(const String &other);

	void prepend(const char *other);

	void prepend(int i);

	void prepend(char c);

	bool contains(String s);

	// bool contains(const char *const s);

	// bool contains(int i);

	bool contains(char c);

	// void insert String, char*, int, char, at an index

	bool isEmpty() const; // empty when the pointer is null or the first character is \0
	
	int length() const;
private:

	void destroy();
};