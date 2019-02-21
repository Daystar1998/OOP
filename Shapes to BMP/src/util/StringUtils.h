// Author: Matthew Day

#pragma once

#include <string>
#include <cctype>

using std::string;
using std::isdigit;
using std::isalnum;

class StringUtils {

public:

	static string getNumber(const char *data, int length, int start, int &end);

	static string getAlphaNumericWord(const char *data, int length, int start, int &end);
};