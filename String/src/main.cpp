#include <iostream>
#include <vld.h>

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

	s3.set("Substring below zero start test");
	String s5 = s3.subString(-1, 5);
	s5.write(cout);
	cout << endl;

	s3.set("Substring past length start test");
	s5.set(s3.subString(100, 5));
	s5.write(cout);
	cout << endl;

	s3.set("Substring past string length test");
	s5.set(s3.subString(0, 100));
	s5.write(cout);
	cout << endl;

	s3.set("Substring inside string test");
	s5.set(s3.subString(5, 6));
	s5.write(cout);
	cout << endl;

	s3.set("Substring both outside string test");
	s5.set(s3.subString(-2, 100));
	s5.write(cout);
	cout << endl;

	s3.set("Equality test end false: 1");
	s4.set("Equality test end false: 2");
	cout << s3.equals(s4) << endl;

	s3.set("Equality test true");
	s4.set("Equality test true");
	cout << s3.equals(s4) << endl;

	s3.set("1: Equality test begin false");
	s4.set("2: Equality test begin false");
	cout << s3.equals(s4) << endl;
}