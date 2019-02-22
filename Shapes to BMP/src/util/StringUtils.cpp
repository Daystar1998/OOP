// Author: Matthew Day

#include "stringUtils.h"

string StringUtils::getNumber(const string &data, int start, int &end) {

	string result = "";
	int pos = start;

	if (data[start] == '-') {

		result.push_back('-');
		pos++;
	}

	for (int i = pos; i < data.length(); i++) {

		if (isdigit(data[i])) {

			result.push_back(data[i]);
		} else {

			break;
		}

		end = i;
	}

	return result;
}

string StringUtils::getAlphaNumericWord(const string &data, int start, int &end) {

	string result = "";
	int pos = start;

	for (int i = pos; i < data.length(); i++) {

		if (isalnum(data[i])) {

			result.push_back(data[i]);
		} else {

			break;
		}

		end = i;
	}

	return result;
}