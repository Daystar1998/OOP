// Author: Matthew Day

#pragma once

#include <string>
#include <cctype>

using std::string;
using std::isdigit;
using std::isalnum;

class StringUtils {

public:

	static string getNumber(const string &data, int start, int &end);

	static int getNextNumber(const string &data, int start, int &end);

	static string getVariable(const string &data, int start, int &end);

	static string getNextVariable(const string &data, int start, int &end);
};