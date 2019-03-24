// Author: Matthew Day

#include "stringUtils.h"

#include <cctype>
#include <stack>
#include <vector>

using std::isdigit;
using std::isalnum;
using std::stack;

string StringUtils::getNumber(const string &data, int start, int &end) {

	string result = "";
	int position = start;

	if (data[start] == '-') {

		result.push_back('-');
		position++;
	}

	for (int i = position; i < data.length(); i++) {

		if (isdigit(data[i])) {

			result.push_back(data[i]);
		} else {

			break;
		}

		end = i;
	}

	return result;
}

int StringUtils::getNextNumber(const string &data, int start, int &end) {

	int result = 0;

	for (int i = start; i < data.length(); i++) {

		if (isdigit(data[i]) || data[i] == '-') {

			result = stoi(getNumber(data, i, end));
			break;
		}
	}

	return result;
}

string StringUtils::getVariable(const string &data, int start, int &end) {

	string result = "";
	int position = start;

	for (int i = position; i < data.length(); i++) {

		if (isalnum(data[i]) || data[i] == '_') {

			result.push_back(data[i]);
		} else {

			break;
		}

		end = i;
	}

	return result;
}

string StringUtils::getNextVariable(const string &data, int start, int &end) {

	string result = "";

	for (int i = start; i < data.length(); i++) {

		if (isalnum(data[i])) {

			result = getVariable(data, i, end);
			break;
		}
	}

	return result;
}

void StringUtils::trimStart(string &str) {

	if (!str.empty()) {

		int start;

		for (start = 0; start < str.length(); start++) {

			if (!isWhiteSpace(str.at(start))) {

				break;
			}
		}

		str.assign(str.substr(start, str.length() - start));
	}
}

void StringUtils::trimEnd(string &str) {

	if (!str.empty()) {

		int end;

		for (end = (int)str.length() - 1; end >= 0; end--) {

			if (!isWhiteSpace(str.at(end))) {

				break;
			}
		}

		str.assign(str.substr(0, end + 1));
	}
}

void StringUtils::trim(string &str) {

	trimStart(str);
	trimEnd(str);
}

bool StringUtils::startsWith(string &lValue, const string &rValue) {

	bool result = false;

	if (lValue.length() >= rValue.length()) {

		size_t j = 0;

		bool matching = false;

		for (int i = 0; i < rValue.length(); i++) {

			if (rValue[i] == lValue.at(j)) {

				matching = true;
			} else {

				matching = false;
				break;
			}

			j++;
		}

		if (matching) {

			result = true;
		}
	}

	return result;
}

bool StringUtils::isWhiteSpace(char c) {

	bool result = false;

	switch (c) {

		case ' ':
		case '\n':
		case '\r':
		case '\t':
		case '\v':

			result = true;
			break;
	}

	return result;
}