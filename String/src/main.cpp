#include <iostream>

#include "String.h"

using std::cout;
using std::endl;

int main(){

	String stringTest("test 1");
	String charTest('c');
	String intTest(7874);
	String copyTest(intTest);

	String intTestMin(INT_MIN);
	String intTestMax(INT_MAX);

	intTestMin.write(cout);
	cout << endl;

	intTestMax.write(cout);
	cout << endl;

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

	copyTest.append("char* test");
	copyTest.write(cout);
	cout << endl;

	copyTest.append('c');
	copyTest.write(cout);
	cout << endl;

	copyTest.append(783);
	copyTest.write(cout);
	cout << endl;

	copyTest.append(copyTest);
	copyTest.write(cout);
	cout << endl;

	intTest.prepend(charTest);
	intTest.write(cout);
	cout << endl;

	intTest.prepend("char* test");
	intTest.write(cout);
	cout << endl;

	intTest.prepend('c');
	intTest.write(cout);
	cout << endl;

	intTest.prepend(783);
	intTest.write(cout);
	cout << endl;

	intTest.prepend(intTest);
	intTest.write(cout);
	cout << endl;

	String s1(70);

	cout << s1.contains('7') << endl;
	cout << s1.contains('8') << endl;

	String s2("Comparison string test");
	String s3("Comparison string test");
	String s4("string");

	cout << s2.contains(s3) << endl;
	cout << s2.contains(s4) << endl;

	s3.set("Insert negative position");
	s3.insert(s4, -1);
	s3.write(cout);
	cout << endl;

	s3.set("Insert after length position");
	s3.insert(s4, 100);
	s3.write(cout);
	cout << endl;

	s3.set("Insert after 'Insert'");
	s3.insert(s4, 6);
	s3.write(cout);
	cout << endl;

	s3.set("Insert at 0 index");
	s3.insert(s4, 0);
	s3.write(cout);
	cout << endl;

	s3.set("Insert at end");
	s3.insert(s4, s3.length());
	s3.write(cout);
	cout << endl;
}