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

	bool contains(const String &other) const;

	bool contains(const char *const s) const;

	bool contains(int i) const;

	bool contains(char c) const;

	void insert(const String &other, int index);

	void insert(const char *const s, int index);

	void insert(int i, int index);

	void insert(char c, int index);

	bool isEmpty() const; // empty when the pointer is null or the first character is \0

	int length() const;
private:

	void destroy();
};