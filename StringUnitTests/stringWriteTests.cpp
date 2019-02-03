#include <sstream>
#include <string>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(WriteTests) {

public:

	TEST_METHOD(StringWriteString) {

		std::stringstream stream;
		std::string outString;

		String s = String("This is an example string");

		s.write(stream);

		std::getline(stream, outString);

		Assert::AreEqual("This is an example string", outString.c_str());
	}

	TEST_METHOD(StringWriteEmpty) {

		std::stringstream stream;
		std::string outString;

		String s;

		s.write(stream);

		std::getline(stream, outString);

		Assert::AreEqual("", outString.c_str());
	}
	};
}