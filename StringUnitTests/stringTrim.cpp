#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(TrimTests) {

public:

	TEST_METHOD(StringTrimNoWhitespace) {

		String s = String("This is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimOneSpaceAtBeginning) {

		String s = String(" This is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimFiveSpacesAtBeginning) {

		String s = String("     This is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimOneTabAtBeginning) {

		String s = String("	This is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimFiveTabsAtBeginning) {

		String s = String("					This is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimCarriageReturnAtBeginning) {

		String s = String("\rThis is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimVerticalTabAtBeginning) {

		String s = String("\vThis is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimMultipleTypesWhitespaceAtBeginning) {

		String s = String("\v\r\t  This is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimCharacterBeforeSpaceAtBeginning) {

		String s = String("T his is an example string");

		s.trim();

		Assert::IsTrue(s.equals(String("T his is an example string")));
	}

	TEST_METHOD(StringTrimOneSpaceAtEnd) {

		String s = String("This is an example string ");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimFiveSpacesAtEnd) {

		String s = String("This is an example string     ");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimOneTabAtEnd) {

		String s = String("This is an example string	");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimFiveTabsAtEnd) {

		String s = String("This is an example string					");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimCarriageReturnAtEnd) {

		String s = String("This is an example string\r");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimVerticalTabAtEnd) {

		String s = String("This is an example string\v");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimMultipleTypesWhitespaceAtEnd) {

		String s = String("This is an example string\v\r\t  ");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimOneSpaceAtBothEnds) {

		String s = String(" This is an example string ");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimFiveSpacesAtBothEnds) {

		String s = String("     This is an example string     ");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimOneTabAtBothEnds) {

		String s = String("	This is an example string	");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimFiveTabsAtBothEnds) {

		String s = String("					This is an example string					");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringTrimMultipleTypesWhitespaceAtBothEnds) {

		String s = String("\v\r\t  This is an example string\v\r\t  ");

		s.trim();

		Assert::IsTrue(s.equals(String("This is an example string")));
	}

	TEST_METHOD(StringEmptyTrim) {

		String s = String();

		s.trim();

		Assert::IsTrue(s.equals(String()));
	}

	TEST_METHOD(StringTrimOnlyWhitespace) {

		String s = String("\r\t\v ");

		s.trim();

		Assert::IsTrue(s.equals(String()));
	}
	};
}