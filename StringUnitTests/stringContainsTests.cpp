#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(ContainsTests) {

public:

	TEST_METHOD(StringContainsStringSuccess) {

		String s1 = String("This is an example string");

		Assert::IsTrue(s1.contains(String("example")));
	}

	TEST_METHOD(StringContainsCharPointerSuccess) {

		String s1 = String("This is an example string");

		Assert::IsTrue(s1.contains("example"));
	}

	TEST_METHOD(StringContainsCharSuccess) {

		String s1 = String("This is an example string");

		Assert::IsTrue(s1.contains('i'));
	}

	TEST_METHOD(StringContainsIntSuccess) {

		String s1 = String("1 2 3 4");

		Assert::IsTrue(s1.contains(2));
	}

	TEST_METHOD(StringEmptyContainsEmptySuccess) {

		String s1 = String();

		Assert::IsTrue(s1.contains(String()));
	}

	TEST_METHOD(StringContainsStringFollowingPartialMatchSuccess) {

		String s1 = String("This is an exexample string");

		Assert::IsTrue(s1.contains(String("example")));
	}

	TEST_METHOD(StringContainsStringAtStartSuccess) {

		String s1 = String("This is an example string");

		Assert::IsTrue(s1.contains(String("This")));
	}

	TEST_METHOD(StringContainsStringAtEndSuccess) {

		String s1 = String("This is an example string");

		Assert::IsTrue(s1.contains(String("string")));
	}

	TEST_METHOD(StringContainsEmptySuccess) {

		String s1 = String("This is an example string");

		Assert::IsTrue(s1.contains(String()));
	}

	TEST_METHOD(StringContainsThisSuccess) {

		String s = String("Test");

		Assert::IsTrue(s.contains(s));
	}

	TEST_METHOD(StringEmptyContainsStringFailure) {

		String s1 = String();

		Assert::IsFalse(s1.contains(String("example")));
	}

	TEST_METHOD(StringContainsStringFailure) {

		String s1 = String("This is an example string");

		Assert::IsFalse(s1.contains(String("random")));
	}

	TEST_METHOD(StringContainsCharPointerFailure) {

		String s1 = String("This is an example string");

		Assert::IsFalse(s1.contains("random"));
	}

	TEST_METHOD(StringContainsCharFailure) {

		String s1 = String("This is an example string");

		Assert::IsFalse(s1.contains('z'));
	}

	TEST_METHOD(StringContainsIntFailure) {

		String s1 = String("This is an example string");

		Assert::IsFalse(s1.contains(6));
	}

	TEST_METHOD(StringContainsPartialMatchFailure) {

		String s1 = String("This is an example string");

		Assert::IsFalse(s1.contains(String("exampleTest")));
	}
	};
}