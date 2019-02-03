#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(ContainsTests) {

public:

	TEST_METHOD(StringContainsStringSuccess) {

		String s = String("This is an example string");

		Assert::IsTrue(s.contains(String("example")));
	}

	TEST_METHOD(StringContainsCharPointerSuccess) {

		String s = String("This is an example string");

		Assert::IsTrue(s.contains("example"));
	}

	TEST_METHOD(StringContainsCharSuccess) {

		String s = String("This is an example string");

		Assert::IsTrue(s.contains('i'));
	}

	TEST_METHOD(StringContainsIntSuccess) {

		String s = String("1 2 3 4");

		Assert::IsTrue(s.contains(2));
	}

	TEST_METHOD(StringEmptyContainsEmptySuccess) {

		String s = String();

		Assert::IsTrue(s.contains(String()));
	}

	TEST_METHOD(StringContainsStringFollowingPartialMatchSuccess) {

		String s = String("This is an exexample string");

		Assert::IsTrue(s.contains(String("example")));
	}

	TEST_METHOD(StringContainsStringAtStartSuccess) {

		String s = String("This is an example string");

		Assert::IsTrue(s.contains(String("This")));
	}

	TEST_METHOD(StringContainsStringAtEndSuccess) {

		String s = String("This is an example string");

		Assert::IsTrue(s.contains(String("string")));
	}

	TEST_METHOD(StringContainsEmptySuccess) {

		String s = String("This is an example string");

		Assert::IsTrue(s.contains(String()));
	}

	TEST_METHOD(StringContainsThisSuccess) {

		String s = String("Test");

		Assert::IsTrue(s.contains(s));
	}

	TEST_METHOD(StringContainsNullSuccess) {

		String s = String("Test");

		Assert::IsTrue(s.contains(nullptr));
	}

	TEST_METHOD(StringContainsNullPointerSuccess) {

		String s1 = String("Test");

		String *s2 = nullptr;

		Assert::IsTrue(s1.contains(*s2));
	}

	TEST_METHOD(StringEmptyContainsStringFailure) {

		String s = String();

		Assert::IsFalse(s.contains(String("example")));
	}

	TEST_METHOD(StringContainsStringFailure) {

		String s = String("This is an example string");

		Assert::IsFalse(s.contains(String("random")));
	}

	TEST_METHOD(StringContainsCharPointerFailure) {

		String s = String("This is an example string");

		Assert::IsFalse(s.contains("random"));
	}

	TEST_METHOD(StringContainsCharFailure) {

		String s = String("This is an example string");

		Assert::IsFalse(s.contains('z'));
	}

	TEST_METHOD(StringContainsIntFailure) {

		String s = String("This is an example string");

		Assert::IsFalse(s.contains(6));
	}

	TEST_METHOD(StringContainsPartialMatchFailure) {

		String s = String("This is an example string");

		Assert::IsFalse(s.contains(String("exampleTest")));
	}
	};
}