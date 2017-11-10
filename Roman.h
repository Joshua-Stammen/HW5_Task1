//
// Created by butte on 10/26/2017.
//

#ifndef HW5_TASK1_ROMAN_H
#define HW5_TASK1_ROMAN_H

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
void testConstructor();
void testOperatorPlus();
void testOperatorPlusEqual();
void testOperatorIncrement();
bool checkTest(string,string,string);
bool checkTest(string, string, string);
void testOutput();


//Class Definition
class Roman
{
private:
    unsigned int value;  //The roman numeral itself isn't stored.  Instead, we just store the integer that corresponds to it.
    void convertFromRoman(const string&);   //The method that helps us take an roman numeral in a string and convert it into the integer.
public:
    /*!
     * Default Constructor
     */
    Roman();

    unsigned int getValue() const;

    void setValue(unsigned int value);
    Roman(const string&);  //The constructor which accepts a string and  converts it internally to an integer.  It actually just forwards it onto convertFromRoman()
    //Roman operator=(const Roman & R1);
	Roman operator+(const Roman &r1) const;  //The left and right operands are Roman objects
    Roman operator+(const int) const; //The left operand is a Roman object, the right is an int number.
    void operator +=(const Roman&);  //The left and right operands are Roman objects, but the left operand can change.
    void operator +=(const int);  //The left operand is a Roman object, the right is an int number.  The left operand can change.
    Roman operator++();  //The prefix ++ operator
    Roman operator++(int i);
    //void operator=(const Roman& R1, const Roman& R2);
    
	string convertToRoman() const;  //The method that helps us take an integer and turn it into a roman numeral
	
    //These two are for testing purposes only.  They have been given to you.
    friend bool checkTest(string, int, const Roman&);  //A testing function.  It is friended so it can access the class.
    //friend bool checkTest(string, string, string);
    friend void testOutput();
    //Another test function that needs to access private class members.
};

#endif //HW5_TASK1_ROMAN_H

