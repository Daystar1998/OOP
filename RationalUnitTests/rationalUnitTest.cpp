#include <sstream>
#include <string>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Rational/src/rational.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using std::stringstream;
using std::string;

namespace RationalUnitTests {		

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

		TEST_METHOD(ConstructorImplicit1) {

			Rational rational = 5;

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("5", result.c_str());
		}

		TEST_METHOD(ConstructorImplicit2) {

			Rational rational = 0;

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("0", result.c_str());
		}

		TEST_METHOD(ConstructorNegativeNumerator) {

			Rational rational(-16, 7);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("-16/7", result.c_str());
		}

		TEST_METHOD(ConstructorNegativeDenominator) {

			Rational rational(16, -7);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("-16/7", result.c_str());
		}

		TEST_METHOD(ConstructorNegativeNumeratorAndDenominator) {

			Rational rational(-16, -7);

			stringstream stream;

			stream << rational;

			string result = stream.str();

			Assert::AreEqual("16/7", result.c_str());
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

			bool threwException = false;

			try {

				Rational rational(5, 0);
				Assert::Fail();
			} catch (const char *message) {
				
				if (message != "Error: Divide by zero") {

					Assert::Fail(L"Incorrect exception thrown");
				}

				threwException = true;
			}

			if (!threwException) {

				Assert::Fail(L"Exception not thrown");
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

		TEST_METHOD(LeastCommonMultiple1) {

			Rational r;

			long result = r.leastCommonMultiple(10, 24);

			Assert::AreEqual(120L, result);
		}

		TEST_METHOD(LeastCommonMultiple2) {

			Rational r;

			long result = r.leastCommonMultiple(9, 5);

			Assert::AreEqual(45L, result);
		}

		TEST_METHOD(GreatestCommonDivisor1) {

			Rational r;

			long result = r.greatestCommonDivisor(10, 24);

			Assert::AreEqual(2L, result);
		}

		TEST_METHOD(GreatestCommonDivisor2) {

			Rational r;

			long result = r.greatestCommonDivisor(33, 11);

			Assert::AreEqual(11L, result);
		}

		TEST_METHOD(PlusOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 + r2;

			Assert::IsTrue(Rational(25, 8) == result);
		}

		TEST_METHOD(PlusOperatorRationalNumber) {

			Rational r(10, 5);

			Rational result = r + 8;

			Assert::IsTrue(Rational(10, 1) == result);
		}

		TEST_METHOD(PlusOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = 5 + r;

			Assert::IsTrue(Rational(32, 5) == result);
		}
	};
}