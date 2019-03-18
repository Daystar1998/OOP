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

	};
}