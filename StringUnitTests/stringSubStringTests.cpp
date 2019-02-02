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

		Assert::IsTrue(subString.equals(String("This")));
	}

	TEST_METHOD(StringSubStringEnd) {

		String original = String("This is an example string");

		String subString = original.subString(19, 6);

		Assert::IsTrue(subString.equals(String("string")));
	}

	TEST_METHOD(StringSubStringStartOneBeforeZero) {

		String original = String("This is an example string");

		String subString = original.subString(-1, 4);

		Assert::IsTrue(subString.equals(String("Thi")));
	}

	TEST_METHOD(StringSubStringStartFarBeforeZero) {

		String original = String("This is an example string");

		String subString = original.subString(-100, 101);

		Assert::IsTrue(subString.equals(String("T")));
	}

	TEST_METHOD(StringSubStringEndBeforeZero) {

		String original = String("This is an example string");

		String subString = original.subString(-100, 4);

		Assert::IsTrue(subString.equals(String()));
	}

	TEST_METHOD(StringSubStringStartAfterEnd) {

		String original = String("This is an example string");

		String subString = original.subString(25, 4);

		Assert::IsTrue(subString.equals(String()));
	}

	TEST_METHOD(StringSubStringEndAfterEnd) {

		String original = String("This is an example string");

		String subString = original.subString(0, 27);

		Assert::IsTrue(subString.equals(String("This is an example string")));
	}

	TEST_METHOD(StringSubStringStartBeforeZeroAndEndAfterEnd) {

		String original = String("This is an example string");

		String subString = original.subString(-1, 27);

		Assert::IsTrue(subString.equals(String("This is an example string")));
	}

	TEST_METHOD(StringSubStringEmpty) {

		String original = String();

		String subString = original.subString(-1, 27);

		Assert::IsTrue(subString.equals(String()));
	}

	TEST_METHOD(StringSubStringLengthZero) {

		String original = String("This is an example string");

		String subString = original.subString(0, 0);

		Assert::IsTrue(subString.equals(String()));
	}

	TEST_METHOD(StringSubStringLengthNegative) {

		String original = String("This is an example string");

		String subString = original.subString(0, -1);

		Assert::IsTrue(subString.equals(String()));
	}
	};
}