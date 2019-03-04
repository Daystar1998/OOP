// Author: Matthew Day

#pragma once

#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::to_string;
using std::vector;

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

	void split(const string &delimiter, vector<String> &oTokens) const;

	bool startsWith(const string &other) const;

	bool endsWith(const string &other) const;
private:

	bool isWhiteSpace(char c) const;
};