#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(AppendTests) {

public:

	TEST_METHOD(StringAppendStringToEmpty) {

		String s = String();

		s.append(String("Test"));

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringAppendCharPointerToEmpty) {

		String s = String();

		s.append("Test");

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringAppendCharToEmpty) {

		String s = String();

		s.append('t');

		Assert::IsTrue(s.equals(String('t')));
	}

	TEST_METHOD(StringAppendIntToEmpty) {

		String s = String();

		s.append(100);

		Assert::IsTrue(s.equals(String("100")));
	}

	TEST_METHOD(StringAppendEmptyToEmpty) {

		String s = String();

		s.append(String());

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringAppendStringToString) {

		String s = String("Original");

		s.append(String("Test"));

		Assert::IsTrue(s.equals(String("OriginalTest")));
	}

	TEST_METHOD(StringAppendCharPointerToString) {

		String s = String("Original");

		s.append("Test");

		Assert::IsTrue(s.equals(String("OriginalTest")));
	}

	TEST_METHOD(StringAppendCharToString) {

		String s = String("Original");

		s.append('t');

		Assert::IsTrue(s.equals(String("Originalt")));
	}

	TEST_METHOD(StringAppendIntToString) {

		String s = String("Original");

		s.append(100);

		Assert::IsTrue(s.equals(String("Original100")));
	}

	TEST_METHOD(StringAppendEmptyToString) {

		String s = String("Original");

		s.append(String());

		Assert::IsTrue(s.equals(String("Original")));
	}

	TEST_METHOD(StringAppendThis) {

		String s = String("Test");

		s.append(s);

		Assert::IsTrue(s.equals(String("TestTest")));
	}

	TEST_METHOD(StringAppendNull) {

		String s = String("Test");

		s.append(nullptr);

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringAppendNullPointer) {

		String s1 = String("Test");

		String *s2 = nullptr;

		s1.append(*s2);

		Assert::IsTrue(s1.equals(String("Test")));
	}
	};
}