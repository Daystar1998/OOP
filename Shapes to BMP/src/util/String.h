#pragma once

#include<stack>
#include<string>

using std::stack;
using std::string;
using std::to_string;

class String : public string {

public:

	String();

	String(const string &newString);

	String(const char* const newString);

	String(int i);

	String(char c);

	void prepend(const String &other);

	void toUpper();

	void toLower();

	void trimStart();

	void trimEnd();

	void trim();
private:

	bool isWhiteSpace(char c);
};