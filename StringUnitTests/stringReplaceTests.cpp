#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(ReplaceTests) {

public:

	TEST_METHOD(StringReplaceThisToEmpty) {

		String s = String("This is an example string");

		s.replace(s, String());

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringReplaceThisToThis) {

		String s = String("This is an example string");

		s.replace(s, s);

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringReplaceThisToString) {

		String s = String("This is an example string");

		s.replace(s, String("Test"));

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringReplaceThisToCharPointer) {

		String s = String("This is an example string");

		s.replace(s, "Test");

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringReplaceThisToChar) {

		String s = String("This is an example string");

		s.replace(s, 't');

		Assert::IsTrue(s.equals(String("t")));
	}

	TEST_METHOD(StringReplaceThisToInt) {

		String s = String("This is an example string");

		s.replace(s, 12345);

		Assert::IsTrue(s.equals(String("12345")));
	}

	TEST_METHOD(StringReplaceEmptyToEmpty) {

		String s = String("This is an example string");

		s.replace(String(), String());

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringReplaceStringFrontToEmpty) {

		String s = String("This is an example string");

		s.replace(String("This"), String());

		Assert::IsTrue(s.equals(String(" is an example string")));
	}

	TEST_METHOD(StringReplaceStringBackToEmpty) {

		String s = String("This is an example string");

		s.replace(String("string"), String());

		Assert::IsTrue(s.equals(String("This is an example ")));
	}

	TEST_METHOD(StringReplaceStringMiddleToEmpty) {

		String s = String("This is an example string");

		s.replace(String("an"), String());

		Assert::IsTrue(s.equals(String("This is  example string")));
	}

	TEST_METHOD(StringReplaceEquivalentStringToEmpty) {

		String s = String("This is an example string");

		s.replace(String("This is an example string"), String());

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringReplaceStringFrontToThis) {

		String s = String("This is an example string");

		s.replace(String("This"), s);

		Assert::IsTrue(s.equals(String("This is an example string is an example string")));
	}

	TEST_METHOD(StringReplaceStringBackToThis) {

		String s = String("This is an example string");

		s.replace(String("string"), s);

		Assert::IsTrue(s.equals(String("This is an example This is an example string")));
	}

	TEST_METHOD(StringReplaceStringMiddleToThis) {

		String s = String("This is an example string");

		s.replace(String("an"), s);

		Assert::IsTrue(s.equals(String("This is This is an example string example string")));
	}

	TEST_METHOD(StringReplaceUnusedStringToString) {

		String s = String("This is an example string");

		s.replace(String("test"), String("something"));

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringReplaceStringFrontToInt) {

		String s = String("This is an example string");

		s.replace(String("This"), 12345);

		Assert::IsTrue(s.equals(String("12345 is an example string")));
	}

	TEST_METHOD(StringReplaceStringBackToInt) {

		String s = String("This is an example string");

		s.replace(String("string"), 12345);

		Assert::IsTrue(s.equals(String("This is an example 12345")));
	}

	TEST_METHOD(StringReplaceStringMiddleToInt) {

		String s = String("This is an example string");

		s.replace(String("an"), 12345);

		Assert::IsTrue(s.equals(String("This is 12345 example string")));
	}

	TEST_METHOD(StringReplaceStringFrontToChar) {

		String s = String("This is an example string");

		s.replace(String("This"), 't');

		Assert::IsTrue(s.equals(String("t is an example string")));
	}

	TEST_METHOD(StringReplaceStringBackToChar) {

		String s = String("This is an example string");

		s.replace(String("string"), 't');

		Assert::IsTrue(s.equals(String("This is an example t")));
	}

	TEST_METHOD(StringReplaceStringMiddleToChar) {

		String s = String("This is an example string");

		s.replace(String("an"), 't');

		Assert::IsTrue(s.equals(String("This is t example string")));
	}

	TEST_METHOD(StringReplaceStringFrontToCharPointer) {

		String s = String("This is an example string");

		s.replace(String("This"), "Test");

		Assert::IsTrue(s.equals(String("Test is an example string")));
	}

	TEST_METHOD(StringReplaceStringBackToCharPointer) {

		String s = String("This is an example string");

		s.replace(String("string"), "Test");

		Assert::IsTrue(s.equals(String("This is an example Test")));
	}

	TEST_METHOD(StringReplaceStringMiddleToCharPointer) {

		String s = String("This is an example string");

		s.replace(String("an"), "Test");

		Assert::IsTrue(s.equals(String("This is Test example string")));
	}

	TEST_METHOD(StringReplaceCharFrontToString) {

		String s = String("This is an example string");

		s.replace('T', String("test"));

		Assert::IsTrue(s.equals(String("testhis is an example string")));
	}

	TEST_METHOD(StringReplaceCharBackToString) {

		String s = String("This is an example string");

		s.replace('g', String("test"));

		Assert::IsTrue(s.equals(String("This is an example strintest")));
	}

	TEST_METHOD(StringReplaceCharMiddleToString) {

		String s = String("This is an example string");

		s.replace('n', String("test"));

		Assert::IsTrue(s.equals(String("This is atest example stritestg")));
	}

	TEST_METHOD(StringReplaceCharFrontToInt) {

		String s = String("This is an example string");

		s.replace('T', 12345);

		Assert::IsTrue(s.equals(String("12345his is an example string")));
	}

	TEST_METHOD(StringReplaceCharBackToInt) {

		String s = String("This is an example string");

		s.replace('g', 12345);

		Assert::IsTrue(s.equals(String("This is an example strin12345")));
	}

	TEST_METHOD(StringReplaceCharMiddleToInt) {

		String s = String("This is an example string");

		s.replace('n', 12345);

		Assert::IsTrue(s.equals(String("This is a12345 example stri12345g")));
	}

	TEST_METHOD(StringReplaceCharFrontToChar) {

		String s = String("This is an example string");

		s.replace('T', 'f');

		Assert::IsTrue(s.equals(String("fhis is an example string")));
	}

	TEST_METHOD(StringReplaceCharBackToChar) {

		String s = String("This is an example string");

		s.replace('g', 'f');

		Assert::IsTrue(s.equals(String("This is an example strinf")));
	}

	TEST_METHOD(StringReplaceCharMiddleToChar) {

		String s = String("This is an example string");

		s.replace('n', 't');

		Assert::IsTrue(s.equals(String("This is at example stritg")));
	}

	TEST_METHOD(StringReplaceCharFrontToEmpty) {

		String s = String("This is an example string");

		s.replace('T', String());

		Assert::IsTrue(s.equals(String("his is an example string")));
	}

	TEST_METHOD(StringReplaceCharBackToEmpty) {

		String s = String("This is an example string");

		s.replace('g', String());

		Assert::IsTrue(s.equals(String("This is an example strin")));
	}

	TEST_METHOD(StringReplaceCharMiddleToEmpty) {

		String s = String("This is an example string");

		s.replace('n', String());

		Assert::IsTrue(s.equals(String("This is a example strig")));
	}

	TEST_METHOD(StringReplaceCharFrontToCharPointer) {

		String s = String("This is an example string");

		s.replace('T', "test");

		Assert::IsTrue(s.equals(String("testhis is an example string")));
	}

	TEST_METHOD(StringReplaceCharBackToCharPointer) {

		String s = String("This is an example string");

		s.replace('g', "test");

		Assert::IsTrue(s.equals(String("This is an example strintest")));
	}

	TEST_METHOD(StringReplaceCharMiddleToCharPointer) {

		String s = String("This is an example string");

		s.replace('n', "test");

		Assert::IsTrue(s.equals(String("This is atest example stritestg")));
	}

	TEST_METHOD(StringReplaceUnusedCharToString) {

		String s = String("This is an example string");

		s.replace('f', String("something"));

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringReplaceUnusedCharPointerToString) {

		String s = String("This is an example string");

		s.replace("random", String("something"));

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringReplaceCharPointerFrontToString) {

		String s = String("This is an example string");

		s.replace("This", String("something"));

		Assert::IsTrue(s.equals(String("something is an example string")));
	}

	TEST_METHOD(StringReplaceCharPointerBackToString) {

		String s = String("This is an example string");

		s.replace("string", String("something"));

		Assert::IsTrue(s.equals(String("This is an example something")));
	}

	TEST_METHOD(StringReplaceCharPointerMiddleToString) {

		String s = String("This is an example string");

		s.replace("an", String("something"));

		Assert::IsTrue(s.equals(String("This is something example string")));
	}

	TEST_METHOD(StringReplaceCharPointerFrontToChar) {

		String s = String("This is an example string");

		s.replace("This", 'f');

		Assert::IsTrue(s.equals(String("f is an example string")));
	}

	TEST_METHOD(StringReplaceCharPointerBackToChar) {

		String s = String("This is an example string");

		s.replace("string", 'f');

		Assert::IsTrue(s.equals(String("This is an example f")));
	}

	TEST_METHOD(StringReplaceCharPointerMiddleToChar) {

		String s = String("This is an example string");

		s.replace("an", 'f');

		Assert::IsTrue(s.equals(String("This is f example string")));
	}

	TEST_METHOD(StringReplaceCharPointerFrontToCharPointer) {

		String s = String("This is an example string");

		s.replace("This", "test");

		Assert::IsTrue(s.equals(String("test is an example string")));
	}

	TEST_METHOD(StringReplaceCharPointerBackToCharPointer) {

		String s = String("This is an example string");

		s.replace("string", "test");

		Assert::IsTrue(s.equals(String("This is an example test")));
	}

	TEST_METHOD(StringReplaceCharPointerMiddleToCharPointer) {

		String s = String("This is an example string");

		s.replace("an", "test");

		Assert::IsTrue(s.equals(String("This is test example string")));
	}

	TEST_METHOD(StringReplaceCharPointerFrontToInt) {

		String s = String("This is an example string");

		s.replace("This", 12345);

		Assert::IsTrue(s.equals(String("12345 is an example string")));
	}

	TEST_METHOD(StringReplaceCharPointerBackToInt) {

		String s = String("This is an example string");

		s.replace("string", 12345);

		Assert::IsTrue(s.equals(String("This is an example 12345")));
	}

	TEST_METHOD(StringReplaceCharPointerMiddleToInt) {

		String s = String("This is an example string");

		s.replace("an", 12345);

		Assert::IsTrue(s.equals(String("This is 12345 example string")));
	}

	TEST_METHOD(StringReplaceCharPointerFrontToEmpty) {

		String s = String("This is an example string");

		s.replace("This", String());

		Assert::IsTrue(s.equals(String(" is an example string")));
	}

	TEST_METHOD(StringReplaceCharPointerBackToEmpty) {

		String s = String("This is an example string");

		s.replace("string", String());

		Assert::IsTrue(s.equals(String("This is an example ")));
	}

	TEST_METHOD(StringReplaceCharPointerMiddleToEmpty) {

		String s = String("This is an example string");

		s.replace("an", String());

		Assert::IsTrue(s.equals(String("This is  example string")));
	}

	TEST_METHOD(StringReplaceUnusedCharPointerMiddleToEmpty) {

		String s = String("This is an example string");

		s.replace("random", String());

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringReplaceMultipleCharPointerToEmpty) {

		String s = String("Test test more tests");

		s.replace("test", String());

		Assert::IsTrue(s.equals(String("Test  more s")));
	}

	TEST_METHOD(StringReplaceMultipleCharToEmpty) {

		String s = String("Test test more tests");

		s.replace('t', String());

		Assert::IsTrue(s.equals(String("Tes es more ess")));
	}

	TEST_METHOD(StringReplaceMultipleStringToEmpty) {

		String s = String("Test test more tests");

		s.replace(String("test"), String());

		Assert::IsTrue(s.equals(String("Test  more s")));
	}

	TEST_METHOD(StringReplaceMultipleIntToEmpty) {

		String s = String("1 1 1 1");

		s.replace(1, String());

		Assert::IsTrue(s.equals(String("   ")));
	}

	TEST_METHOD(StringReplacePartialFollowedByActualStringToEmpty) {

		String s = String("exexample");

		s.replace(String("example"), String());

		Assert::IsTrue(s.equals(String("ex")));
	}

	TEST_METHOD(StringReplacePartialFollowedByActualCharPointerToEmpty) {

		String s = String("exexample");

		s.replace("example", String());

		Assert::IsTrue(s.equals(String("ex")));
	}

	TEST_METHOD(StringReplacePartialFollowedByActualIntToEmpty) {

		String s = String("1212345");

		s.replace(12345, String());

		Assert::IsTrue(s.equals(String("12")));
	}

	TEST_METHOD(StringReplacePartialAtEndIntToEmpty) {

		String s = String("123");

		s.replace(String("12345"), String());

		Assert::IsTrue(s.equals(String("123")));
	}

	TEST_METHOD(StringReplacePartialAtEndCharPointerToEmpty) {

		String s = String("test");

		s.replace("testing", String());

		Assert::IsTrue(s.equals(String("test")));
	}

	TEST_METHOD(StringReplacePartialAtEndStringToEmpty) {

		String s = String("test");

		s.replace(String("testing"), String());

		Assert::IsTrue(s.equals(String("test")));
	}
	};
}