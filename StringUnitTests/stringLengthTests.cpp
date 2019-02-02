#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(LengthTests) {

public:

	TEST_METHOD(StringLengthDefault) {

		String s = String();

		Assert::AreEqual(0, s.length());
	}

	TEST_METHOD(StringLengthEmptyCharPointer) {

		String s = String("");

		Assert::AreEqual(0, s.length());
	}

	TEST_METHOD(StringLengthFourChars) {

		String s = String("test");

		Assert::AreEqual(4, s.length());
	}
	};
}