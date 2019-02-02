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

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndOneSpaceAtBeginning) {

		String s = String(" This is an example string");

		s.trimEnd();

		if (!s.equals(String(" This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndFiveSpacesAtBeginning) {

		String s = String("     This is an example string");

		s.trimEnd();

		if (!s.equals(String("     This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndOneTabAtBeginning) {

		String s = String("	This is an example string");

		s.trimEnd();

		if (!s.equals(String("	This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndFiveTabsAtBeginning) {

		String s = String("					This is an example string");

		s.trimEnd();

		if (!s.equals(String("					This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndCarriageReturnAtBeginning) {

		String s = String("\rThis is an example string");

		s.trimEnd();

		if (!s.equals(String("\rThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndVerticalTabAtBeginning) {

		String s = String("\vThis is an example string\v");

		s.trimEnd();

		if (!s.equals(String("\vThis is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndMultipleTypesWhitespaceAtBeginning) {

		String s = String("\v\r\t  This is an example string");

		s.trimEnd();

		if (!s.equals(String("\v\r\t  This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndCharacterAfterSpace) {

		String s = String("This is an example strin g");

		s.trimEnd();

		if (!s.equals(String("This is an example strin g"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndOneSpace) {

		String s = String("This is an example string ");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndFiveSpace) {

		String s = String("This is an example string     ");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndOneTab) {

		String s = String("This is an example string	");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndFiveTab) {

		String s = String("This is an example string					");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndCarriageReturn) {

		String s = String("This is an example string\r");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndVerticalTab) {

		String s = String("This is an example string\v");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndMultipleTypesWhitespace) {

		String s = String("This is an example string\v\r\t  ");

		s.trimEnd();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyTrimEnd) {

		String s = String();

		s.trimEnd();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimEndOnlyWhitespace) {

		String s = String("\r\t\v ");

		s.trimEnd();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}
	};
}