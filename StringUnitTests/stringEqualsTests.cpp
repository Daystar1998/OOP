#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(EqualsTests) {

public:

	TEST_METHOD(StringEqualsSuccess) {

		String s = String("Test");

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringEqualsEmptySuccess) {

		String s = String();

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringEqualsThisSuccess) {

		String s = String("Test");

		Assert::IsTrue(s.equals(s));
	}

	TEST_METHOD(StringEqualsFailureBeginning) {

		String s = String("Test");

		Assert::IsFalse(s.equals(String("fTest")));
	}

	TEST_METHOD(StringEqualsFailureEnding) {

		String s = String("Test");

		Assert::IsFalse(s.equals(String("Testf")));
	}

	TEST_METHOD(StringEqualsFailureMiddle) {

		String s = String("Test");

		Assert::IsFalse(s.equals(String("Tefst")));
	}

	TEST_METHOD(StringEqualsFailureBothEnds) {

		String s = String("Test");

		Assert::IsFalse(s.equals(String("fTestf")));
	}

	TEST_METHOD(StringEqualsFailureBothEndsAndMiddle) {

		String s = String("Test");

		Assert::IsFalse(s.equals(String("fTefstf")));
	}

	TEST_METHOD(StringEqualsFailureSameLengthFirstDifferent) {

		String s = String("1Test");

		Assert::IsFalse(s.equals(String("2Test")));
	}

	TEST_METHOD(StringEqualsFailureSameLengthLastDifferent) {

		String s = String("Test1");

		Assert::IsFalse(s.equals(String("Test2")));
	}

	TEST_METHOD(StringEqualsNullFailure) {

		String s = String("Test");

		Assert::IsFalse(s.equals(nullptr));
	}

	TEST_METHOD(StringEqualsNullPointerFailure) {

		String s1 = String("Test");

		String *s2 = nullptr;

#pragma warning(suppress: 6011)
		Assert::IsFalse(s1.equals(*s2));
	}
	};
}