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

		TEST_METHOD(AdditionOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 + r2;

			Assert::IsTrue(Rational(25, 8) == result);
		}

		TEST_METHOD(AdditionOperatorRationalNumber) {

			Rational r(10, 5);

			Rational result = r + (Rational)8;

			Assert::IsTrue(Rational(10, 1) == result);
		}

		TEST_METHOD(AdditionOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = (Rational)5 + r;

			Assert::IsTrue(Rational(32, 5) == result);
		}

		TEST_METHOD(SubtractionOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 - r2;

			Assert::IsTrue(Rational(7, 8) == result);
		}

		TEST_METHOD(SubtractionOperatorRationalNumber) {

			Rational r(7, 5);

			Rational result = r - (Rational)8;

			Assert::IsTrue(Rational(-33, 5) == result);
		}

		TEST_METHOD(SubtractionOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = (Rational)5 - r;

			Assert::IsTrue(Rational(18, 5) == result);
		}

		TEST_METHOD(MultiplicationOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 * r2;

			Assert::IsTrue(Rational(9, 4) == result);
		}

		TEST_METHOD(MultiplicationOperatorRationalNumber) {

			Rational r(7, 5);

			Rational result = r * (Rational)8;

			Assert::IsTrue(Rational(56, 5) == result);
		}

		TEST_METHOD(MultiplicationOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = (Rational)5 * r;

			Assert::IsTrue(Rational(7, 1) == result);
		}

		TEST_METHOD(DivisionOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 / r2;

			Assert::IsTrue(Rational(16, 9) == result);
		}

		TEST_METHOD(DivisionOperatorRationalNumber) {

			Rational r(7, 5);

			Rational result = r / (Rational)8;

			Assert::IsTrue(Rational(7, 40) == result);
		}

		TEST_METHOD(DivisionOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = (Rational)5 / r;

			Assert::IsTrue(Rational(25, 7) == result);
		}

		TEST_METHOD(DivisionOperatorRationalZero) {

			Rational r(7, 5);

			bool threwException = false;

			try {


				Rational result = r / (Rational)0;
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

		TEST_METHOD(AdditionAssignmentOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			r1 += r2;

			Assert::IsTrue(Rational(25, 8) == r1);
		}

		TEST_METHOD(AdditionAssignmentOperatorRationalNumber) {

			Rational r(10, 5);

			r += 8;

			Assert::IsTrue(Rational(10, 1) == r);
		}

		TEST_METHOD(SubtractionAssignmentOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			r1 -= r2;

			Assert::IsTrue(Rational(7, 8) == r1);
		}

		TEST_METHOD(SubtractionAssignmentOperatorRationalNumber) {

			Rational r(7, 5);

			r -= 8;

			Assert::IsTrue(Rational(-33, 5) == r);
		}

		TEST_METHOD(MultiplicationAssignmentOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			r1 *= r2;

			Assert::IsTrue(Rational(9, 4) == r1);
		}

		TEST_METHOD(MultiplicationAssignmentOperatorRationalNumber) {

			Rational r(7, 5);

			r *= 8;

			Assert::IsTrue(Rational(56, 5) == r);
		}

		TEST_METHOD(DivisionAssignmentOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			r1 /= r2;

			Assert::IsTrue(Rational(16, 9) == r1);
		}

		TEST_METHOD(DivisionAssignmentOperatorRationalNumber) {

			Rational r(7, 5);

			r /= 8;

			Assert::IsTrue(Rational(7, 40) == r);
		}

		TEST_METHOD(DivisionAssignmentOperatorRationalZero) {

			Rational r(7, 5);

			bool threwException = false;

			try {


				r /= 0;
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

		TEST_METHOD(CastDouble1) {

			Rational r(1, 10);

			Assert::AreEqual(0.1, (double)r);
		}

		TEST_METHOD(CastDouble2) {

			Rational r(50, 5);

			Assert::AreEqual(10.0, (double)r);
		}

		TEST_METHOD(EqualityOperatorRationalRationalSuccess) {

			Rational r1(7, 5);
			Rational r2(7, 5);

			Assert::IsTrue(r1 == r2);
		}

		TEST_METHOD(EqualityOperatorRationalRationalFailure) {

			Rational r1(7, 5);
			Rational r2(20, 3);

			Assert::IsFalse(r1 == r2);
		}

		TEST_METHOD(EqualityOperatorRationalNumber) {

			Rational r(5, 1);

			Assert::IsTrue(r == (Rational)5);
		}

		TEST_METHOD(EqualityOperatorNumberRational) {

			Rational r(9, 1);

			Assert::IsTrue((Rational)9 == r);
		}

		TEST_METHOD(EqualityOperatorThis) {

			Rational r(5, 7);

			Assert::IsTrue(r == r);
		}
	};
}