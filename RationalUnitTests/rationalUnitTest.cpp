#include <sstream>
#include <string>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Rational/src/rational.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using std::stringstream;
using std::string;

namespace RationalUnitTests
{		
	TEST_CLASS(RationalUnitTests) {

	public:
		
		TEST_METHOD(StreamInsertionOperatorDefault) {

			Rational rational;

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("0", result.c_str());
		}

		TEST_METHOD(StreamInsertionOperatorNumeratorOnly) {

			Rational rational(7);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("7", result.c_str());
		}

		TEST_METHOD(StreamInsertionOperatorNumeratorAndDenominator) {

			Rational rational(7, 8);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("7/8", result.c_str());
		}
	};
}