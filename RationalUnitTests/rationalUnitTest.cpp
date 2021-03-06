#include <sstream>
#include <string>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Rational/src/rational.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using std::stringstream;
using std::string;

namespace RationalUnitTests {		

	TEST_CLASS(StreamInsertionTests) {

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

	TEST_CLASS(ConstructorTests) {

	public:

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
	};

	TEST_CLASS(AssignmentTests) {

	public:

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
	};

	TEST_CLASS(PreIncrementationTests) {

	public:

		TEST_METHOD(PreIncrementationOperator) {

			Rational rational(10, 7);

			stringstream stream;

			stream << ++rational;

			string result = stream.str();

			Assert::AreEqual("17/7", result.c_str());
		}
	};

	TEST_CLASS(PostIncrementationTests) {

	public:

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
	};

	TEST_CLASS(PreDecrementationTests) {

	public:

		TEST_METHOD(PreDecrementationOperator) {

			Rational rational(10, 7);

			stringstream stream;

			stream << --rational;

			string result = stream.str();

			Assert::AreEqual("3/7", result.c_str());
		}
	};

	TEST_CLASS(PostDecrementationTests) {

	public:

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

	TEST_CLASS(LeastCommonMultipleTests) {

	public:

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
	};

	TEST_CLASS(GreatestCommonDivisorTests) {

	public:

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
	};

	TEST_CLASS(AdditionOperatorTests) {

	public:

		TEST_METHOD(AdditionOperatorRationalRational1) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 + r2;

			Assert::IsTrue(Rational(25, 8) == result);
		}

		TEST_METHOD(AdditionOperatorRationalRational2) {

			Rational r1(9, 8);
			Rational r2(10, 5);

			Rational result = r1 + r2;

			Assert::IsTrue(Rational(25, 8) == result);
		}

		TEST_METHOD(AdditionOperatorRationalNumber) {

			Rational r(10, 5);

			Rational result = r + 8;

			Assert::IsTrue(Rational(10, 1) == result);
		}

		TEST_METHOD(AdditionOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = 5 + r;

			Assert::IsTrue(Rational(32, 5) == result);
		}
	};

	TEST_CLASS(SubtractionOperatorTests) {

	public:

		TEST_METHOD(SubtractionOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 - r2;

			Assert::IsTrue(Rational(7, 8) == result);
		}

		TEST_METHOD(SubtractionOperatorRationalNumber) {

			Rational r(7, 5);

			Rational result = r - 8;

			Assert::IsTrue(Rational(-33, 5) == result);
		}

		TEST_METHOD(SubtractionOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = 5 - r;

			Assert::IsTrue(Rational(18, 5) == result);
		}
	};

	TEST_CLASS(MultiplicationOperatorTests) {

	public:

		TEST_METHOD(MultiplicationOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 * r2;

			Assert::IsTrue(Rational(9, 4) == result);
		}

		TEST_METHOD(MultiplicationOperatorRationalNumber) {

			Rational r(7, 5);

			Rational result = r * 8;

			Assert::IsTrue(Rational(56, 5) == result);
		}

		TEST_METHOD(MultiplicationOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = 5 * r;

			Assert::IsTrue(Rational(7, 1) == result);
		}
	};

	TEST_CLASS(DivisionOperatorTests) {

	public:

		TEST_METHOD(DivisionOperatorRationalRational) {

			Rational r1(10, 5);
			Rational r2(9, 8);

			Rational result = r1 / r2;

			Assert::IsTrue(Rational(16, 9) == result);
		}

		TEST_METHOD(DivisionOperatorRationalNumber) {

			Rational r(7, 5);

			Rational result = r / 8;

			Assert::IsTrue(Rational(7, 40) == result);
		}

		TEST_METHOD(DivisionOperatorNumberRational) {

			Rational r(7, 5);

			Rational result = 5 / r;

			Assert::IsTrue(Rational(25, 7) == result);
		}

		TEST_METHOD(DivisionOperatorRationalZero) {

			Rational r(7, 5);

			bool threwException = false;

			try {


				Rational result = r / 0;
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
	};

	TEST_CLASS(AdditionAssignmentOperatorTests) {

	public:

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
	};

	TEST_CLASS(SubtractionAssignmentOperatorTests) {

	public:

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
	};

	TEST_CLASS(MultiplicationAssignmentOperatorTests) {

	public:

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
	};

	TEST_CLASS(DivisionAssignmentOperatorTests) {

	public:

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
	};

	TEST_CLASS(CastDoubleTests) {

	public:

		TEST_METHOD(CastDouble1) {

			Rational r(1, 10);

			Assert::AreEqual(0.1, (double)r);
		}

		TEST_METHOD(CastDouble2) {

			Rational r(50, 5);

			Assert::AreEqual(10.0, (double)r);
		}
	};

	TEST_CLASS(EqualityOperatorTests) {

	public:

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

			Assert::IsTrue(r == 5);
		}

		TEST_METHOD(EqualityOperatorNumberRational) {

			Rational r(9, 1);

			Assert::IsTrue(9 == r);
		}

		TEST_METHOD(EqualityOperatorThis) {

			Rational r(5, 7);

			Assert::IsTrue(r == r);
		}
	};

	TEST_CLASS(InequalityOperatorTests) {

	public:

		TEST_METHOD(InequalityOperatorRationalRationalFailure) {

			Rational r1(7, 5);
			Rational r2(7, 5);

			Assert::IsFalse(r1 != r2);
		}

		TEST_METHOD(InequalityOperatorRationalRationalSuccess) {

			Rational r1(7, 5);
			Rational r2(20, 3);

			Assert::IsTrue(r1 != r2);
		}

		TEST_METHOD(InequalityOperatorRationalNumber) {

			Rational r(5, 1);

			Assert::IsFalse(r != 5);
		}

		TEST_METHOD(InequalityOperatorNumberRational) {

			Rational r(9, 1);

			Assert::IsFalse(9 != r);
		}

		TEST_METHOD(InequalityOperatorThis) {

			Rational r(5, 7);

			Assert::IsFalse(r != r);
		}
	};

	TEST_CLASS(GreaterThanOperatorTests) {

	public:

		TEST_METHOD(GreaterThanOperatorRationalRationalEqual) {

			Rational r1(7, 5);
			Rational r2(7, 5);

			Assert::IsFalse(r1 > r2);
		}

		TEST_METHOD(GreaterThanOperatorRationalRationalSuccess) {

			Rational r1(20, 3);
			Rational r2(7, 5);

			Assert::IsTrue(r1 > r2);
		}

		TEST_METHOD(GreaterThanOperatorRationalRationalFailure) {

			Rational r1(7, 5);
			Rational r2(20, 3);

			Assert::IsFalse(r1 > r2);
		}

		TEST_METHOD(GreaterThanOperatorRationalNumber) {

			Rational r(7, 1);

			Assert::IsTrue(r > 5);
		}

		TEST_METHOD(GreaterThanOperatorNumberRational) {

			Rational r(5, 1);

			Assert::IsTrue(9 > r);
		}

		TEST_METHOD(GreaterThanOperatorThis) {

			Rational r(5, 7);

			Assert::IsFalse(r > r);
		}
	};

	TEST_CLASS(GreaterThanOrEqualOperatorTests) {

	public:

		TEST_METHOD(GreaterThanOrEqualOperatorRationalRationalEqual) {

			Rational r1(7, 5);
			Rational r2(7, 5);

			Assert::IsTrue(r1 >= r2);
		}

		TEST_METHOD(GreaterThanOrEqualOperatorRationalRationalSuccess) {

			Rational r1(20, 3);
			Rational r2(7, 5);

			Assert::IsTrue(r1 >= r2);
		}

		TEST_METHOD(GreaterThanOrEqualOperatorRationalRationalFailure) {

			Rational r1(7, 5);
			Rational r2(20, 3);

			Assert::IsFalse(r1 >= r2);
		}

		TEST_METHOD(GreaterThanOrEqualOperatorRationalNumber) {

			Rational r(7, 1);

			Assert::IsTrue(r >= 5);
		}

		TEST_METHOD(GreaterThanOrEqualOperatorNumberRational) {

			Rational r(5, 1);

			Assert::IsTrue(9 >= r);
		}

		TEST_METHOD(GreaterThanOrEqualOperatorThis) {

			Rational r(5, 7);

			Assert::IsTrue(r >= r);
		}
	};

	TEST_CLASS(LessThanOperatorTests) {

	public:

		TEST_METHOD(LessThanOperatorRationalRationalEqual) {

			Rational r1(7, 5);
			Rational r2(7, 5);

			Assert::IsFalse(r1 < r2);
		}

		TEST_METHOD(LessThanOperatorRationalRationalSuccess) {

			Rational r1(7, 5);
			Rational r2(20, 3);

			Assert::IsTrue(r1 < r2);
		}

		TEST_METHOD(LessThanOperatorRationalRationalFailure) {

			Rational r1(20, 3);
			Rational r2(7, 5);

			Assert::IsFalse(r1 < r2);
		}

		TEST_METHOD(LessThanOperatorRationalNumber) {

			Rational r(7, 2);

			Assert::IsTrue(r < 5);
		}

		TEST_METHOD(LessThanOperatorNumberRational) {

			Rational r(33, 2);

			Assert::IsTrue(4 < r);
		}

		TEST_METHOD(LessThanOperatorThis) {

			Rational r(5, 7);

			Assert::IsFalse(r < r);
		}
	};

	TEST_CLASS(LessThanOrEqualOperatorTests) {

	public:

		TEST_METHOD(LessThanOrEqualOperatorRationalRationalEqual) {

			Rational r1(7, 5);
			Rational r2(7, 5);

			Assert::IsTrue(r1 <= r2);
		}

		TEST_METHOD(LessThanOrEqualOperatorRationalRationalSuccess) {

			Rational r1(7, 5);
			Rational r2(20, 3);

			Assert::IsTrue(r1 <= r2);
		}

		TEST_METHOD(LessThanOrEqualOperatorRationalRationalFailure) {

			Rational r1(20, 3);
			Rational r2(7, 5);

			Assert::IsFalse(r1 <= r2);
		}

		TEST_METHOD(LessThanOrEqualOperatorRationalNumber) {

			Rational r(7, 2);

			Assert::IsTrue(r <= 5);
		}

		TEST_METHOD(LessThanOrEqualOperatorNumberRational) {

			Rational r(33, 2);

			Assert::IsTrue(4 <= r);
		}

		TEST_METHOD(LessThanOrEqualOperatorThis) {

			Rational r(5, 7);

			Assert::IsTrue(r <= r);
		}
	};

	TEST_CLASS(StreamExtractionOperatorTests) {

	public:

		TEST_METHOD(StreamExtractionOperator1) {

			Rational rational;

			stringstream stream("123/789");

			stream >> rational;

			Assert::IsTrue(Rational(123, 789) == rational);
		}

		TEST_METHOD(StreamExtractionOperator2) {

			Rational rational;

			stringstream stream("6/8");

			stream >> rational;

			Assert::IsTrue(Rational(6, 8) == rational);
		}

		TEST_METHOD(StreamExtractionOperatorNoDenominator) {

			Rational rational;

			stringstream stream("789");

			stream >> rational;

			Assert::IsTrue(Rational(789) == rational);
		}
	};

	TEST_CLASS(ExponentialOperatorTests) {

	public:

		TEST_METHOD(ExponentialOperatorWholeNumber1) {
		
			Rational r(5);

			Rational result = r ^ 3;

			Assert::IsTrue(Rational(125) == result);
		}

		TEST_METHOD(ExponentialOperatorWholeNumber2) {

			Rational r(12);

			Rational result = r ^ 7;

			Assert::IsTrue(Rational(35831808) == result);
		}

		TEST_METHOD(ExponentialOperatorWholeNumber3) {

			Rational r(-12);

			Rational result = r ^ 7;

			Assert::IsTrue(Rational(-35831808) == result);
		}

		TEST_METHOD(ExponentialOperatorWholeNumber4) {

			Rational r(8);

			Rational result = r ^ -3;

			Assert::IsTrue(Rational(1953125, 1000000000) == result);
		}

		TEST_METHOD(ExponentialOperatorFraction1) {

			Rational r(8, 3);

			Rational result = r ^ 3;

			Assert::IsTrue(Rational(512, 27) == result);
		}

		TEST_METHOD(ExponentialOperatorFraction2) {

			Rational r(1, 2);

			Rational result = r ^ -3;

			Assert::IsTrue(Rational(8) == result);
		}

		TEST_METHOD(ExponentialOperatorZeroExponent) {

			Rational r(1, 2);

			Rational result = r ^ 0;

			Assert::IsTrue(Rational(1) == result);
		}
	};

	TEST_CLASS(FunctionOperatorTests) {

	public:

		TEST_METHOD(FunctionOperator1) {

			Rational r(1, 2);

			Assert::AreEqual("1/2", r().c_str());
		}

		TEST_METHOD(FunctionOperator2) {

			Rational r(5, 8);

			Assert::AreEqual("5/8", r().c_str());
		}

		TEST_METHOD(FunctionOperator3) {

			Rational r(7, 2);

			Assert::AreEqual("7/2", r().c_str());
		}

		TEST_METHOD(FunctionOperator4) {

			Rational r(8, 2);

			Assert::AreEqual("4/1", r().c_str());
		}
	};
}