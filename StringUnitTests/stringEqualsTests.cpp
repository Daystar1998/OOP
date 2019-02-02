#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(EqualsTests) {

public:

	TEST_METHOD(StringEqualsSuccess) {

		String s = String("Test");

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsEmptySuccess) {

		String s = String();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsThisSuccess) {

		String s = String("Test");

		if (!s.equals(s)) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsFailBeginning) {

		String s = String("Test");

		if (s.equals(String("fTest"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsFailEnding) {

		String s = String("Test");

		if (s.equals(String("Testf"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsFailMiddle) {

		String s = String("Test");

		if (s.equals(String("Tefst"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsFailBothEnds) {

		String s = String("Test");

		if (s.equals(String("fTestf"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEqualsFailBothEndsAndMiddle) {

		String s = String("Test");

		if (s.equals(String("fTefstf"))) {

			Assert::Fail();
		}
	}
	};
}