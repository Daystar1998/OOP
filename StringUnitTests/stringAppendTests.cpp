#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(AppendTests) {

public:

	TEST_METHOD(StringAppendStringToEmpty) {

		String s = String();

		s.append(String("Test"));

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendCharPointerToEmpty) {

		String s = String();

		s.append("Test");

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendCharToEmpty) {

		String s = String();

		s.append('t');

		if (!s.equals(String('t'))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendIntToEmpty) {

		String s = String();

		s.append(100);

		if (!s.equals(String("100"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendEmptyToEmpty) {

		String s = String();

		s.append(String());

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendStringToString) {

		String s = String("Original");

		s.append(String("Test"));

		if (!s.equals(String("OriginalTest"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendCharPointerToString) {

		String s = String("Original");

		s.append("Test");

		if (!s.equals(String("OriginalTest"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendCharToString) {

		String s = String("Original");

		s.append('t');

		if (!s.equals(String("Originalt"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendIntToString) {

		String s = String("Original");

		s.append(100);

		if (!s.equals(String("Original100"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringAppendEmptyToString) {

		String s = String("Original");

		s.append(String());

		if (!s.equals(String("Original"))) {

			Assert::Fail();
		}
	}
	};
}