#pragma once

#include<iostream>
#include<string>

using namespace std;

class String {

private:

	char* pString;
public:

	String();

	String(const String& newString);

	String(const char* const newString);

	//String( int i );

	String( char c );

	~String();

	void set(const char* const newString);

	void set(const String& newString);

	//void set( int i );

	void set( char c );

	void write(std::ostream& out);

	// append takes an int, char, char* or String&
	// prepend takes an int, char , char* or String&

	// bool contains( char c);

	// bool contains( String s );

	// bool contains( const char* const s );

	// bool contains( int i );

	// void insert String, char*, int, char, at an index

	bool isEmpty(); // empty when the pointer is null or the first character is \0
	
	int length();
private:

	void destroy();
};