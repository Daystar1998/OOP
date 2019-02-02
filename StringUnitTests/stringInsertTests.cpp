#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(InsertTests) {

public:

	TEST_METHOD(StringInsertStringOneBelowZero) {

		String s = String("This is an example string");
		s.insert(String("Test "), -1);

		if (!s.equals(String("Test This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertStringFarBelowZero) {

		String s = String("This is an example string");
		s.insert(String("Test "), -100);

		if (!s.equals(String("Test This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertStringZero) {

		String s = String("This is an example string");
		s.insert(String("Test "), 0);

		if (!s.equals(String("Test This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertStringOneAboveLength) {

		String s = String("This is an example string");
		s.insert(String(" Test"), 25);

		if (!s.equals(String("This is an example string Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertStringFarAboveLength) {

		String s = String("This is an example string");
		s.insert(String(" Test"), 1000);

		if (!s.equals(String("This is an example string Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertStringMiddle) {

		String s = String("This is an example string");
		s.insert(String("Test"), 11);

		if (!s.equals(String("This is an Testexample string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharPointerOneBelowZero) {

		String s = String("This is an example string");
		s.insert("Test", -1);

		if (!s.equals(String("TestThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharPointerFarBelowZero) {

		String s = String("This is an example string");
		s.insert("Test", -100);

		if (!s.equals(String("TestThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharPointerZero) {

		String s = String("This is an example string");
		s.insert("Test", 0);

		if (!s.equals(String("TestThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharPointerOneAboveLength) {

		String s = String("This is an example string");
		s.insert("Test", 25);

		if (!s.equals(String("This is an example stringTest"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharPointerFarAboveLength) {

		String s = String("This is an example string");
		s.insert("Test", 1000);

		if (!s.equals(String("This is an example stringTest"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharPointerMiddle) {

		String s = String("This is an example string");
		s.insert("Test", 11);

		if (!s.equals(String("This is an Testexample string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharOneBelowZero) {

		String s = String("This is an example string");
		s.insert('t', -1);

		if (!s.equals(String("tThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharFarBelowZero) {

		String s = String("This is an example string");
		s.insert('t', -100);

		if (!s.equals(String("tThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharZero) {

		String s = String("This is an example string");
		s.insert('t', 0);

		if (!s.equals(String("tThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharOneAboveLength) {

		String s = String("This is an example string");
		s.insert('t', 25);

		if (!s.equals(String("This is an example stringt"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharFarAboveLength) {

		String s = String("This is an example string");
		s.insert('t', 1000);

		if (!s.equals(String("This is an example stringt"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertCharMiddle) {

		String s = String("This is an example string");
		s.insert('t', 11);

		if (!s.equals(String("This is an texample string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertIntOneBelowZero) {

		String s = String("This is an example string");
		s.insert(10, -1);

		if (!s.equals(String("10This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertIntFarBelowZero) {

		String s = String("This is an example string");
		s.insert(10, -100);

		if (!s.equals(String("10This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertIntZero) {

		String s = String("This is an example string");
		s.insert(10, 0);

		if (!s.equals(String("10This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertIntOneAboveLength) {

		String s = String("This is an example string");
		s.insert(10, 25);

		if (!s.equals(String("This is an example string10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertIntFarAboveLength) {

		String s = String("This is an example string");
		s.insert(10, 1000);

		if (!s.equals(String("This is an example string10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertIntMiddle) {

		String s = String("This is an example string");
		s.insert(10, 11);

		if (!s.equals(String("This is an 10example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertEmptyOneBelowZero) {

		String s = String("This is an example string");
		s.insert(String(), -1);

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertEmptyFarBelowZero) {

		String s = String("This is an example string");
		s.insert(String(), -100);

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertEmptyZero) {

		String s = String("This is an example string");
		s.insert(String(), 0);

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertEmptyOneAboveLength) {

		String s = String("This is an example string");
		s.insert(String(), 25);

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertEmptyFarAboveLength) {

		String s = String("This is an example string");
		s.insert(String(), 1000);

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertEmptyMiddle) {

		String s = String("This is an example string");
		s.insert(String(), 11);

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertEmptyOneBelowZero) {

		String s = String();
		s.insert(String(), -1);

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertEmptyFarBelowZero) {

		String s = String();
		s.insert(String(), -100);

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertEmptyZero) {

		String s = String();
		s.insert(String(), 0);

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertEmptyOneAboveLength) {

		String s = String();
		s.insert(String(), 1);

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertEmptyFarAboveLength) {

		String s = String();
		s.insert(String(), 1000);

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertStringOneBelowZero) {

		String s = String();
		s.insert(String("example"), -1);

		if (!s.equals(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertStringFarBelowZero) {

		String s = String();
		s.insert(String("example"), -100);

		if (!s.equals(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertStringZero) {

		String s = String();
		s.insert(String("example"), 0);

		if (!s.equals(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertStringOneAboveLength) {

		String s = String();
		s.insert(String("example"), 1);

		if (!s.equals(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertStringFarAboveLength) {

		String s = String();
		s.insert(String("example"), 1000);

		if (!s.equals(String("example"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharPointerOneBelowZero) {

		String s = String();
		s.insert("Test", -1);

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharPointerFarBelowZero) {

		String s = String();
		s.insert("Test", -100);

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharPointerZero) {

		String s = String();
		s.insert("Test", 0);

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharPointerOneAboveLength) {

		String s = String();
		s.insert("Test", 1);

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharPointerFarAboveLength) {

		String s = String();
		s.insert("Test", 1000);

		if (!s.equals(String("Test"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharOneBelowZero) {

		String s = String();
		s.insert('t', -1);

		if (!s.equals(String("t"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharFarBelowZero) {

		String s = String();
		s.insert('t', -100);

		if (!s.equals(String("t"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharZero) {

		String s = String();
		s.insert('t', 0);

		if (!s.equals(String("t"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharOneAboveLength) {

		String s = String();
		s.insert('t', 1);

		if (!s.equals(String("t"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertCharFarAboveLength) {

		String s = String();
		s.insert('t', 1000);

		if (!s.equals(String("t"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertIntOneBelowZero) {

		String s = String();
		s.insert(10, -1);

		if (!s.equals(String("10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertIntFarBelowZero) {

		String s = String();
		s.insert(10, -100);

		if (!s.equals(String("10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertIntZero) {

		String s = String();
		s.insert(10, 0);

		if (!s.equals(String("10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertIntOneAboveLength) {

		String s = String();
		s.insert(10, 1);

		if (!s.equals(String("10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyInsertIntFarAboveLength) {

		String s = String();
		s.insert(10, 1000);

		if (!s.equals(String("10"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringInsertThisInMiddle) {

		String s = String("This is an example string");
		s.insert(s, 11);

		if (!s.equals(String("This is an This is an example stringexample string"))) {

			Assert::Fail();
		}
	}
	};
}