// Author: Matthew Day

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class StringUtils {

public:

	static string getNumber(const string &data, int start, int &end);

	static int getNextNumber(const string &data, int start, int &end);

	static string getVariable(const string &data, int start, int &end);

	static string getNextVariable(const string &data, int start, int &end);

	static bool startsWith(string &lValue, const string &rValue);
};