#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(AtTests) {

public:

	TEST_METHOD(StringAtZero) {

		String s = String("This is an example string");

		Assert::AreEqual('T', s.at(0));
	}

	TEST_METHOD(StringAtNullTerminator) {

		String s = String("This is an example string");

		Assert::AreEqual('\0', s.at(25));
	}

	TEST_METHOD(StringAtOneBelowZero) {

		String s = String("This is an example string");

		Assert::AreEqual('\0', s.at(-1));
	}

	TEST_METHOD(StringAtFarBelowZero) {

		String s = String("This is an example string");

		Assert::AreEqual('\0', s.at(-100));
	}

	TEST_METHOD(StringAtOneAboveLength) {

		String s = String("This is an example string");

		Assert::AreEqual('\0', s.at(26));
	}

	TEST_METHOD(StringAtFarAboveLength) {

		String s = String("This is an example string");

		Assert::AreEqual('\0', s.at(100));
	}

	TEST_METHOD(StringAtMiddle) {

		String s = String("This is an example string");

		Assert::AreEqual('a', s.at(13));
	}
	};
}