#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(ToLowerTests) {

public:

	TEST_METHOD(StringToLower) {

		String s = String("THIS IS AN EXAMPLE STRING");

		s.toLower();

		Assert::IsTrue(s.equals(String("this is an example string")));
	}

	TEST_METHOD(StringEmptyToLower) {

		String s = String();

		s.toLower();

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringToLowerWithNumbersOnEnds) {

		String s = String("1THIS IS AN EXAMPLE STRING1");

		s.toLower();

		Assert::IsTrue(s.equals(String("1this is an example string1")));
	}

	TEST_METHOD(StringToLowerWithNumberInMiddle) {

		String s = String("THIS IS AN 1EXAMPLE STRING");

		s.toLower();

		Assert::IsTrue(s.equals(String("this is an 1example string")));
	}

	TEST_METHOD(StringToLowerWithSymbolsOnEnds) {

		String s = String("!@#$%^&*()THIS IS AN EXAMPLE STRING!@#$%^&*()");

		s.toLower();

		Assert::IsTrue(s.equals(String("!@#$%^&*()this is an example string!@#$%^&*()")));
	}

	TEST_METHOD(StringToLowerWithSymbolsInMiddle) {

		String s = String("THIS IS AN !@#$%^&*()EXAMPLE STRING");

		s.toLower();

		Assert::IsTrue(s.equals(String("this is an !@#$%^&*()example string")));
	}

	TEST_METHOD(StringToLowerAlreadyLowercase) {

		String s = String("this is an example string");

		s.toLower();

		Assert::IsTrue(s.equals(String("this is an example string")));
	}
	};
}