#include "stdafx.h"
#include "CppUnitTest.h"

#include "../String/src/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests {

	TEST_CLASS(TrimStartTests) {

public:

	TEST_METHOD(StringTrimStartNoWhitespace) {

		String s = String("This is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartOneSpaceAtBeginning) {

		String s = String(" This is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartFiveSpacesAtBeginning) {

		String s = String("     This is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartOneTabAtBeginning) {

		String s = String("	This is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartFiveTabsAtBeginning) {

		String s = String("					This is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartCarriageReturnAtBeginning) {

		String s = String("\rThis is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartVerticalTabAtBeginning) {

		String s = String("\vThis is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartMultipleTypesWhitespaceAtBeginning) {

		String s = String("\v\r\t  This is an example string");

		s.trimStart();

		if (!s.equals(String("This is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartCharacterBeforeSpaceAtBeginning) {

		String s = String("T his is an example string");

		s.trimStart();

		if (!s.equals(String("T his is an example string"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartOneSpaceAtEnd) {

		String s = String("This is an example string ");

		s.trimStart();

		if (!s.equals(String("This is an example string "))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartFiveSpacesAtEnd) {

		String s = String("This is an example string     ");

		s.trimStart();

		if (!s.equals(String("This is an example string     "))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartOneTabAtEnd) {

		String s = String("This is an example string	");

		s.trimStart();

		if (!s.equals(String("This is an example string	"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartFiveTabsAtEnd) {

		String s = String("This is an example string					");

		s.trimStart();

		if (!s.equals(String("This is an example string					"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartCarriageReturnAtEnd) {

		String s = String("This is an example string\r");

		s.trimStart();

		if (!s.equals(String("This is an example string\r"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartVerticalTabAtEnd) {

		String s = String("This is an example string\v");

		s.trimStart();

		if (!s.equals(String("This is an example string\v"))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartMultipleTypesWhitespaceAtEnd) {

		String s = String("This is an example string\v\r\t  ");

		s.trimStart();

		if (!s.equals(String("This is an example string\v\r\t  "))) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringEmptyTrimStart) {

		String s = String();

		s.trimStart();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}

	TEST_METHOD(StringTrimStartOnlyWhitespace) {

		String s = String("\r\t\v ");

		s.trimStart();

		if (!s.equals(String())) {

			Assert::Fail();
		}
	}
	};
}