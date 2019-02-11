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

		TEST_METHOD(ConstructorReductionNumeratorHigher) {

			Rational rational(16, 8);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("2", result.c_str());
		}

		TEST_METHOD(ConstructorReductionDenominatorHigher) {

			Rational rational(5, 50);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("1/10", result.c_str());
		}

		TEST_METHOD(ConstructorDenominatorZero) {

			try {

				Rational rational(5, 0);
				Assert::Fail();
			} catch (...) {
				
			}
		}

		TEST_METHOD(AssignmentOperator) {

			Rational rational1(20, 5);
			Rational rational2(10, 50);

			rational2 = rational1;

			stringstream stream1;
			stringstream stream2;

			stream1 << rational1;
			stream2 << rational2;

			string result1 = stream1.str();
			string result2 = stream2.str();

			Assert::AreEqual(result1.c_str(), result2.c_str());
		}

		TEST_METHOD(PreIncrementationOperator) {

			Rational rational(10, 7);

			stringstream stream;

			stream << ++rational;

			string result = stream.str();

			Assert::AreEqual("17/7", result.c_str());
		}

		TEST_METHOD(PostIncrementationOperator) {

			Rational rational(10, 7);

			stringstream stream;
			stream << rational++;
			string result = stream.str();

			Assert::AreEqual("10/7", result.c_str());

			stream.str("");
			stream << rational;
			result = stream.str();

			Assert::AreEqual("17/7", result.c_str());
		}

		TEST_METHOD(PreDecrementationOperator) {

			Rational rational(10, 7);

			stringstream stream;

			stream << --rational;

			string result = stream.str();

			Assert::AreEqual("3/7", result.c_str());
		}

		TEST_METHOD(PostDecrementationOperator) {

			Rational rational(10, 7);

			stringstream stream;
			stream << rational--;
			string result = stream.str();

			Assert::AreEqual("10/7", result.c_str());

			stream.str("");
			stream << rational;
			result = stream.str();

			Assert::AreEqual("3/7", result.c_str());
		}
	};
}