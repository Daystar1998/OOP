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

		Assert::IsTrue(s.equals(String("Test This is an example string")));
	}

	TEST_METHOD(StringInsertStringFarBelowZero) {

		String s = String("This is an example string");
		s.insert(String("Test "), -100);

		Assert::IsTrue(s.equals(String("Test This is an example string")));
	}

	TEST_METHOD(StringInsertStringZero) {

		String s = String("This is an example string");
		s.insert(String("Test "), 0);

		Assert::IsTrue(s.equals(String("Test This is an example string")));
	}

	TEST_METHOD(StringInsertStringOneAboveLength) {

		String s = String("This is an example string");
		s.insert(String(" Test"), 25);

		Assert::IsTrue(s.equals(String("This is an example string Test")));
	}

	TEST_METHOD(StringInsertStringFarAboveLength) {

		String s = String("This is an example string");
		s.insert(String(" Test"), 1000);

		Assert::IsTrue(s.equals(String("This is an example string Test")));
	}

	TEST_METHOD(StringInsertStringMiddle) {

		String s = String("This is an example string");
		s.insert(String("Test"), 11);

		Assert::IsTrue(s.equals(String("This is an Testexample string")));
	}

	TEST_METHOD(StringInsertCharPointerOneBelowZero) {

		String s = String("This is an example string");
		s.insert("Test", -1);

		Assert::IsTrue(s.equals(String("TestThis is an example string")));
	}

	TEST_METHOD(StringInsertCharPointerFarBelowZero) {

		String s = String("This is an example string");
		s.insert("Test", -100);

		Assert::IsTrue(s.equals(String("TestThis is an example string")));
	}

	TEST_METHOD(StringInsertCharPointerZero) {

		String s = String("This is an example string");
		s.insert("Test", 0);

		Assert::IsTrue(s.equals(String("TestThis is an example string")));
	}

	TEST_METHOD(StringInsertCharPointerOneAboveLength) {

		String s = String("This is an example string");
		s.insert("Test", 25);

		Assert::IsTrue(s.equals(String("This is an example stringTest")));
	}

	TEST_METHOD(StringInsertCharPointerFarAboveLength) {

		String s = String("This is an example string");
		s.insert("Test", 1000);

		Assert::IsTrue(s.equals(String("This is an example stringTest")));
	}

	TEST_METHOD(StringInsertCharPointerMiddle) {

		String s = String("This is an example string");
		s.insert("Test", 11);

		Assert::IsTrue(s.equals(String("This is an Testexample string")));
	}

	TEST_METHOD(StringInsertCharOneBelowZero) {

		String s = String("This is an example string");
		s.insert('t', -1);

		Assert::IsTrue(s.equals(String("tThis is an example string")));
	}

	TEST_METHOD(StringInsertCharFarBelowZero) {

		String s = String("This is an example string");
		s.insert('t', -100);

		Assert::IsTrue(s.equals(String("tThis is an example string")));
	}

	TEST_METHOD(StringInsertCharZero) {

		String s = String("This is an example string");
		s.insert('t', 0);

		Assert::IsTrue(s.equals(String("tThis is an example string")));
	}

	TEST_METHOD(StringInsertCharOneAboveLength) {

		String s = String("This is an example string");
		s.insert('t', 25);

		Assert::IsTrue(s.equals(String("This is an example stringt")));
	}

	TEST_METHOD(StringInsertCharFarAboveLength) {

		String s = String("This is an example string");
		s.insert('t', 1000);

		Assert::IsTrue(s.equals(String("This is an example stringt")));
	}

	TEST_METHOD(StringInsertCharMiddle) {

		String s = String("This is an example string");
		s.insert('t', 11);

		Assert::IsTrue(s.equals(String("This is an texample string")));
	}

	TEST_METHOD(StringInsertIntOneBelowZero) {

		String s = String("This is an example string");
		s.insert(10, -1);

		Assert::IsTrue(s.equals(String("10This is an example string")));
	}

	TEST_METHOD(StringInsertIntFarBelowZero) {

		String s = String("This is an example string");
		s.insert(10, -100);

		Assert::IsTrue(s.equals(String("10This is an example string")));
	}

	TEST_METHOD(StringInsertIntZero) {

		String s = String("This is an example string");
		s.insert(10, 0);

		Assert::IsTrue(s.equals(String("10This is an example string")));
	}

	TEST_METHOD(StringInsertIntOneAboveLength) {

		String s = String("This is an example string");
		s.insert(10, 25);

		Assert::IsTrue(s.equals(String("This is an example string10")));
	}

	TEST_METHOD(StringInsertIntFarAboveLength) {

		String s = String("This is an example string");
		s.insert(10, 1000);

		Assert::IsTrue(s.equals(String("This is an example string10")));
	}

	TEST_METHOD(StringInsertIntMiddle) {

		String s = String("This is an example string");
		s.insert(10, 11);

		Assert::IsTrue(s.equals(String("This is an 10example string")));
	}

	TEST_METHOD(StringInsertEmptyOneBelowZero) {

		String s = String("This is an example string");
		s.insert(String(), -1);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringInsertEmptyFarBelowZero) {

		String s = String("This is an example string");
		s.insert(String(), -100);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringInsertEmptyZero) {

		String s = String("This is an example string");
		s.insert(String(), 0);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringInsertEmptyOneAboveLength) {

		String s = String("This is an example string");
		s.insert(String(), 25);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringInsertEmptyFarAboveLength) {

		String s = String("This is an example string");
		s.insert(String(), 1000);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringInsertEmptyMiddle) {

		String s = String("This is an example string");
		s.insert(String(), 11);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringEmptyInsertEmptyOneBelowZero) {

		String s = String();
		s.insert(String(), -1);

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringEmptyInsertEmptyFarBelowZero) {

		String s = String();
		s.insert(String(), -100);

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringEmptyInsertEmptyZero) {

		String s = String();
		s.insert(String(), 0);

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringEmptyInsertEmptyOneAboveLength) {

		String s = String();
		s.insert(String(), 1);

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringEmptyInsertEmptyFarAboveLength) {

		String s = String();
		s.insert(String(), 1000);

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringEmptyInsertStringOneBelowZero) {

		String s = String();
		s.insert(String("example"), -1);

		Assert::IsTrue(s.equals(String("example")));
	}

	TEST_METHOD(StringEmptyInsertStringFarBelowZero) {

		String s = String();
		s.insert(String("example"), -100);

		Assert::IsTrue(s.equals(String("example")));
	}

	TEST_METHOD(StringEmptyInsertStringZero) {

		String s = String();
		s.insert(String("example"), 0);

		Assert::IsTrue(s.equals(String("example")));
	}

	TEST_METHOD(StringEmptyInsertStringOneAboveLength) {

		String s = String();
		s.insert(String("example"), 1);

		Assert::IsTrue(s.equals(String("example")));
	}

	TEST_METHOD(StringEmptyInsertStringFarAboveLength) {

		String s = String();
		s.insert(String("example"), 1000);

		Assert::IsTrue(s.equals(String("example")));
	}

	TEST_METHOD(StringEmptyInsertCharPointerOneBelowZero) {

		String s = String();
		s.insert("Test", -1);

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringEmptyInsertCharPointerFarBelowZero) {

		String s = String();
		s.insert("Test", -100);

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringEmptyInsertCharPointerZero) {

		String s = String();
		s.insert("Test", 0);

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringEmptyInsertCharPointerOneAboveLength) {

		String s = String();
		s.insert("Test", 1);

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringEmptyInsertCharPointerFarAboveLength) {

		String s = String();
		s.insert("Test", 1000);

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringEmptyInsertCharOneBelowZero) {

		String s = String();
		s.insert('t', -1);

		Assert::IsTrue(s.equals(String("t")));
	}

	TEST_METHOD(StringEmptyInsertCharFarBelowZero) {

		String s = String();
		s.insert('t', -100);

		Assert::IsTrue(s.equals(String("t")));
	}

	TEST_METHOD(StringEmptyInsertCharZero) {

		String s = String();
		s.insert('t', 0);

		Assert::IsTrue(s.equals(String("t")));
	}

	TEST_METHOD(StringEmptyInsertCharOneAboveLength) {

		String s = String();
		s.insert('t', 1);

		Assert::IsTrue(s.equals(String("t")));
	}

	TEST_METHOD(StringEmptyInsertCharFarAboveLength) {

		String s = String();
		s.insert('t', 1000);

		Assert::IsTrue(s.equals(String("t")));
	}

	TEST_METHOD(StringEmptyInsertIntOneBelowZero) {

		String s = String();
		s.insert(10, -1);

		Assert::IsTrue(s.equals(String("10")));
	}

	TEST_METHOD(StringEmptyInsertIntFarBelowZero) {

		String s = String();
		s.insert(10, -100);

		Assert::IsTrue(s.equals(String("10")));
	}

	TEST_METHOD(StringEmptyInsertIntZero) {

		String s = String();
		s.insert(10, 0);

		Assert::IsTrue(s.equals(String("10")));
	}

	TEST_METHOD(StringEmptyInsertIntOneAboveLength) {

		String s = String();
		s.insert(10, 1);

		Assert::IsTrue(s.equals(String("10")));
	}

	TEST_METHOD(StringEmptyInsertIntFarAboveLength) {

		String s = String();
		s.insert(10, 1000);

		Assert::IsTrue(s.equals(String("10")));
	}

	TEST_METHOD(StringInsertThisInMiddle) {

		String s = String("This is an example string");
		s.insert(s, 11);

		Assert::IsTrue(s.equals(String("This is an This is an example stringexample string")));
	}

	TEST_METHOD(StringInsertNull) {

		String s = String("This is an example string");
		s.insert(nullptr, 0);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringInsertNullPointer) {

		String s1 = String("This is an example string");
		String *s2 = nullptr;

#pragma warning(suppress: 6011)
		s1.insert(*s2, 0);

		Assert::IsTrue(s1.equals(String("This is an example string")));
	}
	};
}