// Author: Matthew Day

#include <string>

#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Map/src/Map.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace util;

namespace MapUnitTests
{		
	TEST_CLASS(MapTests)
	{
	public:
		
		TEST_METHOD(InsertionExtractionTest1)
		{
			
			Map<int, char> test;

			test[9] = 'i';

			Assert::AreEqual((char)test[9], 'i');
		}

		TEST_METHOD(InsertionExtractionTest2) {

			Map<int, char> test;

			test[4] = '9';

			Assert::AreEqual((char)test[4], '9');
		}

		TEST_METHOD(InsertionExtractionTest3) {

			Map<char, char> test;

			test['h'] = 'i';

			Assert::AreEqual((char)test['h'], 'i');
		}

		TEST_METHOD(InsertionExtractionTest4) {

			Map<char, char> test;

			test['l'] = '7';

			Assert::AreEqual((char)test['l'], '7');
		}

		TEST_METHOD(InsertionExtractionTest5) {

			Map<char, int> test;

			test['h'] = 6;

			Assert::AreEqual((int)test['h'], 6);
		}

		TEST_METHOD(InsertionExtractionTest6) {

			Map<char, int> test;

			test['l'] = 7;

			Assert::AreEqual((int)test['l'], 7);
		}

		TEST_METHOD(UpdateValueTest1) {

			Map<char, int> test;

			test['h'] = 6;
			test['h'] = 8;

			Assert::AreEqual((int)test['h'], 8);
		}

		TEST_METHOD(UpdateValueTest2) {

			Map<char, int> test;

			test['l'] = 7;
			test['l'] = 3;

			Assert::AreEqual((int)test['l'], 3);
		}

		TEST_METHOD(UpdateValueTest3) {

			Map<char, char> test;

			test['y'] = '9';
			test['y'] = '7';

			Assert::AreEqual((char)test['y'], '7');
		}

		TEST_METHOD(SizeTest1) {

			Map<char, char> test;

			Assert::AreEqual(test.size(), 0U);
		}

		TEST_METHOD(SizeTest2) {

			Map<int, int> test;

			test[8] = 7;

			Assert::AreEqual(test.size(), 1U);
		}

		TEST_METHOD(SizeTest3) {

			Map<int, int> test;

			test[8] = 7;
			test[8] = 7;

			Assert::AreEqual(test.size(), 1U);
		}

		TEST_METHOD(SizeTest4) {

			Map<int, int> test;

			test[8] = 7;
			test[5] = 4;

			Assert::AreEqual(test.size(), 2U);
		}

		TEST_METHOD(CastSuccessTest1) {

			Map<int, int> test;

			test[9] = 8;

			bool caughtCorrectException = false;

			int i = test[9];

			Assert::AreEqual(i, 8);
		}

		TEST_METHOD(CastSuccessTest2) {

			Map<int, int> test;

			test[9] = -5;
			test[3] = 0;
			test[100] = 3;
			test[7] = 76;

			bool caughtCorrectException = false;

			int i = test[9];

			Assert::AreEqual(i, -5);
		}

		TEST_METHOD(CastFailureTest1) {

			Map<int, int> test;

			bool caughtCorrectException = false;

			try {

				int i = test[9];
			} catch (std::range_error e) {

				if (std::string(e.what()) == "Key not found in map") {

					caughtCorrectException = true;
				}
			}

			if (!caughtCorrectException) {

				Assert::Fail();
			}
		}

		TEST_METHOD(CastFailureTest2) {

			Map<int, int> test;

			test[7] = 6;

			bool caughtCorrectException = false;

			try {

				int i = test[9];
			} catch (std::range_error e) {

				if (std::string(e.what()) == "Key not found in map") {

					caughtCorrectException = true;
				}
			}

			if (!caughtCorrectException) {

				Assert::Fail();
			}
		}

		TEST_METHOD(ReferenceSuccessTest1) {

			Map<int, int> test;

			test[9] = 8;

			bool caughtCorrectException = false;

			int *i = &test[9];

			Assert::AreEqual(*i, 8);
		}

		TEST_METHOD(ReferenceSuccessTest2) {

			Map<int, int> test;

			test[9] = 8;
			test[8] = 5;
			test[10] = 7;
			test[5] = 111;

			test[9] = 6;

			bool caughtCorrectException = false;

			int *i = &test[9];

			Assert::AreEqual(*i, 6);
		}

		TEST_METHOD(ReferenceFailureTest1) {

			Map<int, int> test;

			bool caughtCorrectException = false;

			try {

				int *i = &test[9];
			} catch (std::range_error e) {

				if (std::string(e.what()) == "Key not found in map") {

					caughtCorrectException = true;
				}
			}

			if (!caughtCorrectException) {

				Assert::Fail();
			}
		}

		TEST_METHOD(ReferenceFailureTest2) {

			Map<int, int> test;

			test[9] = 8;

			bool caughtCorrectException = false;

			try {

				int *i = &test[7];
			} catch (std::range_error e) {

				if (std::string(e.what()) == "Key not found in map") {

					caughtCorrectException = true;
				}
			}

			if (!caughtCorrectException) {

				Assert::Fail();
			}
		}
	};
}