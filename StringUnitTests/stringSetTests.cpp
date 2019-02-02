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

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringSetEmptyToChar) {

		String s = String();

		s.set('t');

		Assert::IsTrue(s.equals(String('t')));
	}

	TEST_METHOD(StringSetEmptyToIntMin) {

		String s = String();

		s.set(INT_MIN);

		Assert::IsTrue(s.equals(String(std::to_string(INT_MIN).c_str())));
	}

	TEST_METHOD(StringSetEmptyToIntMax) {

		String s = String();

		s.set(INT_MAX);

		Assert::IsTrue(s.equals(String(std::to_string(INT_MAX).c_str())));
	}

	TEST_METHOD(StringSetEmptyToIntZero) {

		String s = String();

		s.set(0);

		Assert::IsTrue(s.equals(String("0")));
	}

	TEST_METHOD(StringSetEmptyToString) {

		String s1 = String();
		String s2 = String("Test");

		s1.set(s2);

		Assert::IsTrue(s1.equals(String("Test")));
	}

	TEST_METHOD(StringSetStringToString) {

		String s1 = String("First");
		String s2 = String("Second");

		s1.set("Second");

		Assert::IsTrue(s1.equals(String("Second")));
	}

	TEST_METHOD(StringSetStringToChar) {

		String s = String("Previous");

		s.set('t');

		Assert::IsTrue(s.equals(String('t')));
	}

	TEST_METHOD(StringSetStringToInt) {

		String s = String("Previous");

		s.set(0);

		Assert::IsTrue(s.equals(String(0)));
	}

	TEST_METHOD(StringSetThis) {

		String s = String("Previous");

		s.set(s);

		Assert::IsTrue(s.equals(String("Previous")));
	}
	};
}