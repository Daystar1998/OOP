#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(IsEmptyTests) {

public:

	TEST_METHOD(StringIsEmptyDefaultSuccess) {

		String s = String();

		Assert::IsTrue(s.isEmpty());
	}

	TEST_METHOD(StringIsEmptyEmptyCharPointerSuccess) {

		String s = String("");

		Assert::IsTrue(s.isEmpty());
	}

	TEST_METHOD(StringIsEmptyEmptyCharPointerFailure) {

		String s = String("Test");

		Assert::IsFalse(s.isEmpty());
	}
	};
}