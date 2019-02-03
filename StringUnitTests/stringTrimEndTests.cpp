#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(TrimEndTests) {

public:

	TEST_METHOD(StringTrimEndNoWhitespace) {

		String s = String("This is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndOneSpaceAtBeginning) {

		String s = String(" This is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String(" This is an example string")));
	}

	TEST_METHOD(StringTrimEndFiveSpacesAtBeginning) {

		String s = String("     This is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("     This is an example string")));
	}

	TEST_METHOD(StringTrimEndOneTabAtBeginning) {

		String s = String("	This is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("	This is an example string")));
	}

	TEST_METHOD(StringTrimEndFiveTabsAtBeginning) {

		String s = String("					This is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("					This is an example string")));
	}

	TEST_METHOD(StringTrimEndCarriageReturnAtBeginning) {

		String s = String("\rThis is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("\rThis is an example string")));
	}

	TEST_METHOD(StringTrimEndVerticalTabAtBeginning) {

		String s = String("\vThis is an example string\v");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("\vThis is an example string")));
	}

	TEST_METHOD(StringTrimEndMultipleTypesWhitespaceAtBeginning) {

		String s = String("\v\r\t  This is an example string");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("\v\r\t  This is an example string")));
	}

	TEST_METHOD(StringTrimEndCharacterAfterSpaceAtEnd) {

		String s = String("This is an example strin g");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example strin g")));
	}

	TEST_METHOD(StringTrimEndOneSpaceAtEnd) {

		String s = String("This is an example string ");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndFiveSpacesAtEnd) {

		String s = String("This is an example string     ");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndOneTabAtEnd) {

		String s = String("This is an example string	");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndFiveTabsAtEnd) {

		String s = String("This is an example string					");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndCarriageReturnAtEnd) {

		String s = String("This is an example string\r");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndVerticalTabAtEnd) {

		String s = String("This is an example string\v");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndMultipleTypesWhitespaceAtEnd) {

		String s = String("This is an example string\v\r\t  ");

		s.trimEnd();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimEndEmpty) {

		String s = String();

		s.trimEnd();

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringTrimEndOnlyWhitespace) {

		String s = String("\r\t\v ");

		s.trimEnd();

		Assert::IsTrue(s.equals(String()));
	}
	};
}