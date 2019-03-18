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

	};
}