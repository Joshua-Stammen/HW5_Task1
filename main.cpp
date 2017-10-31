#include "Roman.h"
#include "cmake-build-debug/Roman.h"
#include <iostream>
#include <string>

using namespace std;
/* Main Function */////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    testConstructor();
    testOperatorPlus();
    testOperatorPlusEqual();
    testOperatorIncrement();
    testOutput();
    return 0;
};

//testConsoleIO();

/* This MAY be in a different source and header file */


void testOperatorPlusEqual()
{
	//Test adding two roman objects
	Roman a("MLII");
	Roman b("DDCCI");
	a += b;
	checkTest("testOperatorPlusEqual #1", 2253, a);
	//make sure the right operand wasn't modified
	checkTest("testOperatorPlusEqual #2", 1201, b);

	//Test adding on an integer
	b += 17;
	checkTest("testOperatorPlusEqual #3", 1218, b);
}

void testOperatorIncrement()
{
	//Test prefix increment
	Roman a("MLII");
	Roman b("DDCCI");
	b = ++a;
	checkTest("testOperatorIncrement #1", 1053, a);
	checkTest("testOperatorIncrement #2", 1053, b);
}

void testConsoleIO()
{
	//Test reading in the data using the extraction operator >>
	cout << "Enter the text CCLX: ";
	Roman a;
	cin >> a;
	checkTest("testConsoleIO #1", 260, a);

	//Test outputting data using the insertion operator <<
	cout << "testConsoleIO #2" << endl << "If this says 260, this test passed: " << a << endl;

}


void testOutput()
{
	Roman a("MDCLXVI");
	string b = a.convertToRoman();
	checkTest("testOutput #1", "MDCLXVI", b);

	//This is really the value 7.  Your code should correctly read this in and convert it back to VII.
	Roman c("IIIIIII");
	b = c.convertToRoman();
	checkTest("testOutput #2", "VII", b);
}

