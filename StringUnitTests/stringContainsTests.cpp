#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(ContainsTests) {

public:

	TEST_METHOD(StringContainsStringSuccess) {

		String s1 = String("This is an example string");

		if (!s1.contains(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsCharPointerSuccess) {

		String s1 = String("This is an example string");

		if (!s1.contains("example")) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsCharSuccess) {

		String s1 = String("This is an example string");

		if (!s1.contains('i')) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsIntSuccess) {

		String s1 = String("1 2 3 4");

		if (!s1.contains(2)) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyContainsEmptySuccess) {

		String s1 = String();

		if (!s1.contains(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsStringFollowingPartialMatchSuccess) {

		String s1 = String("This is an exexample string");

		if (!s1.contains(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsStringAtStartSuccess) {

		String s1 = String("This is an example string");

		if (!s1.contains(String("This"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsStringAtEndSuccess) {

		String s1 = String("This is an example string");

		if (!s1.contains(String("string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyContainsStringFailure) {

		String s1 = String();

		if (s1.contains(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsStringFailure) {

		String s1 = String("This is an example string");

		if (s1.contains(String("random"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsCharPointerFailure) {

		String s1 = String("This is an example string");

		if (s1.contains("random")) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsCharFailure) {

		String s1 = String("This is an example string");

		if (s1.contains('z')) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsIntFailure) {

		String s1 = String("This is an example string");

		if (s1.contains(6)) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringContainsPartialMatchFailure) {

		String s1 = String("This is an example string");

		if (s1.contains(String("exampleTest"))) {

			Assert::Fail();
		}
	}
	};
}