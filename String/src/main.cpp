#include <iostream>

#include "String.h"

using std::cout;
using std::endl;

int main(){

	String stringTest("test");
	String charTest('c');
	String intTest(7874);
	String copyTest(intTest);

	stringTest.write(cout);
	cout << endl;

	charTest.write(cout);
	cout << endl;

	intTest.write(cout);
	cout << endl;

	copyTest.write(cout);
	cout << endl;

	copyTest.append(stringTest);
	copyTest.write(cout);
	cout << endl;
}