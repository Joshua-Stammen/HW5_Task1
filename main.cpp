#include "Roman.h"
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

/*!
 * testOperatorPlus: Conduts 7 tests using the opartor + by adding two objects together, 
 *                   a object to an integer, and another oject to an integer.  
 */
void testOperatorPlus() {
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
    c = a + 578;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);
}
/*!
 * testOperatorPlusEqual: Conduts 3 tests using the opartor += by incrementing the a integer by b, and
 *                        by incrementing the integer b by 17.  
 */
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
/*!
 * testOperatorPlusEqual: Conduts 2 tests using the opartor ++ by incrementing the a 
 *                        integer and assigning the new value of a to b.
 */
void testOperatorIncrement()
{
    //Test prefix increment
    Roman a("MLII");
    Roman b("DDCCI");
    b = ++a;
    checkTest("testOperatorIncrement #1", 1053, a);
    checkTest("testOperatorIncrement #2", 1053, b);
}
/*!
 * testOperatorPlusEqual: tests the convertToRoman method twice, and then checks to see if the result was correct
 */
void testOutput()
{
    Roman a("MDCLXVI");
    string bob = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", bob);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    bob = c.convertToRoman();
    
    checkTest("testOutput #2", "VII", bob);
}

