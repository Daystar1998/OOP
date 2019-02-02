#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(PrependTests) {

public:

	TEST_METHOD(StringPrependStringToEmpty) {

		String s = String();

		s.prepend(String("Test"));

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependCharPointerToEmpty) {

		String s = String();

		s.prepend("Test");

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependCharToEmpty) {

		String s = String();

		s.prepend('t');

		if (!s.equals(String('t'))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependIntToEmpty) {

		String s = String();

		s.prepend(100);

		if (!s.equals(String("100"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependEmptyToEmpty) {

		String s = String();

		s.prepend(String());

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependStringToString) {

		String s = String("Original");

		s.prepend(String("Test"));

		if (!s.equals(String("TestOriginal"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependCharPointerToString) {

		String s = String("Original");

		s.prepend("Test");

		if (!s.equals(String("TestOriginal"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependCharToString) {

		String s = String("Original");

		s.prepend('t');

		if (!s.equals(String("tOriginal"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependIntToString) {

		String s = String("Original");

		s.prepend(100);

		if (!s.equals(String("100Original"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringPrependEmptyToString) {

		String s = String("Original");

		s.prepend(String());

		if (!s.equals(String("Original"))) {

			Assert::Fail();
		}
	}
	};
}