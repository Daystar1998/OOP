#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(SubStringTests) {

public:

	TEST_METHOD(StringSubStringStart) {

		String original = String("This is an example string");

		String subString = original.subString(0, 4);

		if (!subString.equals(String("This"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringEnd) {

		String original = String("This is an example string");

		String subString = original.subString(19, 6);

		if (!subString.equals(String("string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringStartOneBeforeZero) {

		String original = String("This is an example string");

		String subString = original.subString(-1, 4);

		if (!subString.equals(String("Thi"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringStartFarBeforeZero) {

		String original = String("This is an example string");

		String subString = original.subString(-100, 101);

		if (!subString.equals(String("T"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringEndBeforeZero) {

		String original = String("This is an example string");

		String subString = original.subString(-100, 4);

		if (!subString.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringStartAfterEnd) {

		String original = String("This is an example string");

		String subString = original.subString(25, 4);

		if (!subString.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringEndAfterEnd) {

		String original = String("This is an example string");

		String subString = original.subString(0, 27);

		if (!subString.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringStartBeforeZeroAndEndAfterEnd) {

		String original = String("This is an example string");

		String subString = original.subString(-1, 27);

		if (!subString.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringEmpty) {

		String original = String();

		String subString = original.subString(-1, 27);

		if (!subString.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringLengthZero) {

		String original = String("This is an example string");

		String subString = original.subString(0, 0);

		if (!subString.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringSubStringLengthNegative) {

		String original = String("This is an example string");

		String subString = original.subString(0, -1);

		if (!subString.equals(String())) {

			Assert::Fail();
		}
	}
	};
}