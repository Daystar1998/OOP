#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(SetTests) {

public:

	TEST_METHOD(StringSetEmptyToCharPointer) {

		String s = String();

		s.set("Test");

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetEmptyToChar) {

		String s = String();

		s.set('t');

		if (!s.equals(String('t'))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetEmptyToIntMin) {

		String s = String();

		s.set(INT_MIN);

		if (!s.equals(String(std::to_string(INT_MIN).c_str()))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetEmptyToIntMax) {

		String s = String();

		s.set(INT_MAX);

		if (!s.equals(String(std::to_string(INT_MAX).c_str()))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetEmptyToIntZero) {

		String s = String();

		s.set(0);

		if (!s.equals(String("0"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetEmptyToString) {

		String s1 = String();
		String s2 = String("Test");

		s1.set(s2);

		if (!s1.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetStringToString) {

		String s1 = String("First");
		String s2 = String("Second");

		s1.set("Second");

		if (!s1.equals(String("Second"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetStringToChar) {

		String s = String("Previous");

		s.set('t');

		if (!s.equals(String('t'))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSetStringToInt) {

		String s = String("Previous");

		s.set(0);

		if (!s.equals(String(0))) {

			Assert::Fail();
		}
	}
	};
}