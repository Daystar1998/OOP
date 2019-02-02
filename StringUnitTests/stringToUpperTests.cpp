#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(ToUpperTests) {

public:

	TEST_METHOD(StringToUpper) {

		String s = String("This is an example string");

		s.toUpper();

		if (!s.equals(String("THIS IS AN EXAMPLE STRING"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyToUpper) {

		String s = String();

		s.toUpper();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToUpperWithNumbersOnEnds) {

		String s = String("1This is an example string1");

		s.toUpper();

		if (!s.equals(String("1THIS IS AN EXAMPLE STRING1"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToUpperWithNumberInMiddle) {

		String s = String("This is an 1example string");

		s.toUpper();

		if (!s.equals(String("THIS IS AN 1EXAMPLE STRING"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToUpperWithSymbolsOnEnds) {

		String s = String("!@#$%^&*()This is an example string!@#$%^&*()");

		s.toUpper();

		if (!s.equals(String("!@#$%^&*()THIS IS AN EXAMPLE STRING!@#$%^&*()"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToUpperWithSymbolsInMiddle) {

		String s = String("This is an !@#$%^&*()example string");

		s.toUpper();

		if (!s.equals(String("THIS IS AN !@#$%^&*()EXAMPLE STRING"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringToUpperAlreadyUppercase) {

		String s = String("THIS IS AN EXAMPLE STRING");

		s.toUpper();

		if (!s.equals(String("THIS IS AN EXAMPLE STRING"))) {

			Assert::Fail();
		}
	}
	};
}