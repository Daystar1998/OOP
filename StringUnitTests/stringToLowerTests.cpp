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

		if (!s.equals(String("this is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyToLower) {

		String s = String();

		s.toLower();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToLowerWithNumbersOnEnds) {

		String s = String("1THIS IS AN EXAMPLE STRING1");

		s.toLower();

		if (!s.equals(String("1this is an example string1"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToLowerWithNumberInMiddle) {

		String s = String("THIS IS AN 1EXAMPLE STRING");

		s.toLower();

		if (!s.equals(String("this is an 1example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToLowerWithSymbolsOnEnds) {

		String s = String("!@#$%^&*()THIS IS AN EXAMPLE STRING!@#$%^&*()");

		s.toLower();

		if (!s.equals(String("!@#$%^&*()this is an example string!@#$%^&*()"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToLowerWithSymbolsInMiddle) {

		String s = String("THIS IS AN !@#$%^&*()EXAMPLE STRING");

		s.toLower();

		if (!s.equals(String("this is an !@#$%^&*()example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToLowerAlreadyLowercase) {

		String s = String("this is an example string");

		s.toLower();

		if (!s.equals(String("this is an example string"))) {

			Assert::Fail();
		}
	}
	};
}