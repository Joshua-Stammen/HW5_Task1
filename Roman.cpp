//
// Created by butte on 10/26/2017.
//
#include "Roman.h"
#include <iostream>
#include <string>
using namespace std;



/*!
 * Default Constructor
 */
Roman::Roman()
{
    value = 0;
}
/*!
 * Second Constructor that get a string vlaue and converts it to a 
 * interger to be assigned to the variable "value".
 * @param str
 */
Roman::Roman(const string &str)
{
	value = 0;
    convertFromRoman(str);
}
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

/*!
 * getValue: obtains the value of the integer "value".
 * returns: value - integer
 */
unsigned int Roman::getValue() const {

    return value;
}

void Roman::setValue(unsigned int value) {
    Roman::value = value;
}
/*!
 * convertFromRoman: Converts a Roman Numeral representation to an integer value and assigns
                     it to the Roman peramater "value".
 * @param R1 - object 
 */
void Roman::convertFromRoman(const string& R1)
{
    for(int i = 0; i<R1.length(); i++)
    {
        switch(R1.at(i))
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
/*!
 * operator+: allows for two Roman objects to be summed to eachother using the + operator.
 * @param i - integer 
 * returns: temp - the result after i and value are sumed to eachother
 */
Roman Roman::operator+(const Roman &romNew) const 
{
    Roman temp;
    temp.value = (romNew.value + value);
    return temp;
}
/*!
 * operator+: allows for a Roman object to be added to in integer using the + operator.
 * @param i - integer 
 * returns: temp - the result after i and value are sumed to eachother
 */
Roman Roman::operator+(const int i) const 
{
    Roman temp;    
    temp.value= i + value;
    return temp;
}
/*!
 * operator+=: allows a Roman object to be incremented by the Roman i.vlaue using += operator.
 * @param R1 - Roman  
 */
void Roman::operator+=(const Roman& R1)
{
      value += R1.value;
}
/*!
 * operator+=: allows a Roman object to be incremented by the integer i using += operator.
 * @param i - integer 
 */
void Roman::operator +=(const int i)
{
      value += i;
}
/*!
 * operator++: allows a Roman object to be incremented by 1 using the prefix ++.
 * returns: temp - a result
 */
Roman Roman::operator++() 
{
	Roman temp;
    temp.value = (++value);
    return temp;
}
/*!
 * operator++: allows a Roman object to be incremented by 1 using the postfix ++.
 * @param i - integer of what the variable should be
 * returns: temp - a result
 */
Roman Roman::operator++(int i)
{
   Roman temp;
   temp.value = (++i);
   return temp;
}

/*!
 * convertToRoman: converts the integer value in the class Roman to a Roman Numeral representation
 * returns: numeral - a roman numeral
 */
string Roman::convertToRoman() const
{
	int number = value;
    string numeral = "";
    int divisor[] = {1000, 500, 100, 50, 10, 5, 1};
    char singleLetter[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'}; 
    for(int j = 0; j < 7; j++)
    {
        int numberDivided  = (number/divisor[j]);
        for(int i = 0; i < numberDivided; i++)
        {
            numeral += singleLetter[j];
            number = number%divisor[j];
    	}
    }
    return numeral;
}
/*!
 * checkTest: finds out if one of the operator overload methods return the correct result.
 * 		      if it does then the program outputs the "Passed" to the terminal, otherwise 
 *			  the program outputs a failed message to the terminal. 
 * @param testName - number of the test
 * @param whatItShouldBe - integer of what the variable should be
 * @param obj - from the Roman class - uesed to find 
 * returns: bool
 */
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
 /*!
 * checkTest: finds out if the convertToRoman method returns the correct roman numeral. 
 * 		      if it does then the program outputs the "Passed" to the terminal, otherwise 
 			  the program outputs a failed message to the terminal. 
 * @param testName - number of the test
 * @param whatItShouldBe
 * @param whatItIs
 * returns: bool
 */
bool checkTest(string testName, string whatItShouldBe, string whatItIs ) 
{
     if (whatItShouldBe == whatItIs) 
	 {
         cout << "Passed " << testName << endl;
         return true;
     } 
	 else 
	 {
         cout << "****** Failed test " << testName << " ****** " << endl << "     Object contained: " << whatItIs << endl
              << "     Output should have contained: " << whatItShouldBe << endl;
              return false;
     }
 }

