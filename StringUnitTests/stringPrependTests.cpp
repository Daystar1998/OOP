#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(PrependTests) {

public:

	TEST_METHOD(StringPrependStringToEmpty) {

		String s = String();

		s.prepend(String("Test"));

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringPrependCharPointerToEmpty) {

		String s = String();

		s.prepend("Test");

		Assert::IsTrue(s.equals(String("Test")));
	}

	TEST_METHOD(StringPrependCharToEmpty) {

		String s = String();

		s.prepend('t');

		Assert::IsTrue(s.equals(String('t')));
	}

	TEST_METHOD(StringPrependIntToEmpty) {

		String s = String();

		s.prepend(100);

		Assert::IsTrue(s.equals(String("100")));
	}

	TEST_METHOD(StringPrependEmptyToEmpty) {

		String s = String();

		s.prepend(String());

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringPrependStringToString) {

		String s = String("Original");

		s.prepend(String("Test"));

		Assert::IsTrue(s.equals(String("TestOriginal")));
	}

	TEST_METHOD(StringPrependCharPointerToString) {

		String s = String("Original");

		s.prepend("Test");

		Assert::IsTrue(s.equals(String("TestOriginal")));
	}

	TEST_METHOD(StringPrependCharToString) {

		String s = String("Original");

		s.prepend('t');

		Assert::IsTrue(s.equals(String("tOriginal")));
	}

	TEST_METHOD(StringPrependIntToString) {

		String s = String("Original");

		s.prepend(100);

		Assert::IsTrue(s.equals(String("100Original")));
	}

	TEST_METHOD(StringPrependEmptyToString) {

		String s = String("Original");

		s.prepend(String());

		Assert::IsTrue(s.equals(String("Original")));
	}

	TEST_METHOD(StringPrependThis) {

		String s = String("Original");

		s.prepend(s);

		Assert::IsTrue(s.equals(String("OriginalOriginal")));
	}

	TEST_METHOD(StringPrependNull) {

		String s = String("Original");

		s.prepend(nullptr);

		Assert::IsTrue(s.equals(String("Original")));
	}

	TEST_METHOD(StringPrependNullPointer) {

		String s1 = String("Original");

		String *s2 = nullptr;

#pragma warning(suppress: 6011)
		s1.prepend(*s2);

		Assert::IsTrue(s1.equals(String("Original")));
	}
	};
}