#include <iostream>

#include "String.h"

using std::cout;

int main(){

	String stringTest("test");
	String charTest('c');
	String intTest(7);
	String copyTest(intTest);

	stringTest.write(cout);
	charTest.write(cout);
	intTest.write(cout);
	copyTest.write(cout);
}