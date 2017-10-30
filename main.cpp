#include <iostream>
#include <string>
#include "Roman.h"

using namespace std;




// Testing Function Prototypes
void testConstructor();
bool checkTest(string testName, int whatItShouldBe, const Roman& obj);
bool checkTest(string testName, string whatItShouldBe, string whatItIs);
void testOperatorPlus();
//void testOperatorPlusEqual();
//void testOperatorIncrement();
//void testConsoleIO();

/* This MUST be in a different source and header file */

/* Main Function */////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    testConstructor();
    //testOperatorPlus();
    //testOperatorPlusEqual();
    //testOperatorIncrement();
    //testOutput();
    return 0;
};

//testConsoleIO();

/* This MAY be in a different source and header file */

//This helps with testing, do not modify.
void testConstructor()
{
    //Test to make sure that empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a bigger number.
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);

}
/*
void testOperatorPlus()
{
	//Test adding two roman objects
	Roman a("XVI");
	Roman b("MDCLXVI");
	Roman c = a + b;
	checkTest("testOperatorPlus #1", 1682, c);
	//make sure the left and right operands weren't modified
	checkTest("testOperatorPlus #2", 16, a);
	checkTest("testOperatorPlus #3", 1666, b);

	//Test adding an object with an int
	c = a + 52;
	checkTest("testOperatorPlus #4", 68, c);
	//make sure the left operand wasn't modified
	checkTest("testOperatorPlus #5", 16, a);

	//Test adding an int with an object
	c = 578 + a;
	checkTest("testOperatorPlus #6", 594, c);
	//make sure the right operand wasn't modified
	checkTest("testOperatorPlus #7", 16, a);

}

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

}	*/

bool checkTest(string testName, int whatItShouldBe, const Roman& obj )
{
    if (whatItShouldBe == obj.value)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< obj.value << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

bool checkTest(string testName, string whatItShouldBe, string whatItIs )
{
    if (whatItShouldBe == whatItIs)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: "<< whatItIs << endl << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

void testOperatorPlus() {

}

/*void testOutput()
{
	Roman a("MDCLXVI");
	string b = a.convertToRoman();
	checkTest("testOutput #1", "MDCLXVI", b);

	//This is really the value 7.  Your code should correctly read this in and convert it back to VII.
	Roman c("IIIIIII");
	b = c.convertToRoman();
	checkTest("testOutput #2", "VII", b);
}*/



___________________________________________________________________________________________________________________________

#ifndef ROMAN_H
#define ROMAN_H
#include <iostream>
#include <string>
using namespace std;

class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
public:
    //The default constructor that allows us to make empty objects.
    Roman():value(0){}
    //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()
    Roman(const string& romanString):value(0){convertFromRoman(romanString);}

    void convertFromRoman(const string& romanValue);  //The method that helps us take an roman numeral in a string and convert it into the integer.

    //string convertToRoman() const;  //The method that helps us take an integer and turn it into a roman numeral

    //Roman operator+(const Roman&) const;  //The left and right operands are Roman objects
    //Roman operator+(const int) const; //The left operand is a Roman object, the right is an int number.
    //void operator +=(const Roman&);  //The left and right operands are Roman objects, but the left operand can change.
    //void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    //Roman operator++();  //The prefix ++ operator

    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    friend void testOutput(); //Another test function that needs to access private class members.
};

#endif





______________________________________________________________________________________________________________

#include "Roman.h"
#include <iostream>
#include <string>
using namespace std;

//Roman::Roman():value(0){}

void Roman::convertFromRoman(const string& romanValue)
{
    for(int i = 0; i<romanValue.length(); i++)
    {
        switch(romanValue.at(i))
        {
            case 'I': value += 1;break;
            case 'V': value += 5;break;
            case 'X': value += 10;break;
            case 'L': value += 50;break;
            case 'C': value += 100;break;
            case 'D': value += 500;break;
            case 'M': value += 1000;
        }
    }
}
