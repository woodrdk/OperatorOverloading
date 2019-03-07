// HugeInteger.cpp
// Member-function definitions for class HugeInteger.
#include <iostream>
#include "HugeInteger.h" // include definition of class HugeInteger 
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInteger object
HugeInteger::HugeInteger(long value)
{
	// initialize array to zero
	for (int i = 0; i < 40; ++i)
		integer[i] = 0;

	// place digits of argument into array 
	for (int j = 39; value != 0 && j >= 0; --j)
	{
		integer[j] = static_cast<short>(value % 10);
		value /= 10;
	} // end inner for
} // end HugeInteger constructor

// copy constructor; 
// converts a char string representing a large integer into a HugeInteger
HugeInteger::HugeInteger(const string &string)
{
	input(string); // call input to initialize HugeInteger
} // end HugeInteger constructor

// addition operator; HugeInteger + HugeInteger
//HugeInteger HugeInteger::add(const HugeInteger &op2) const
HugeInteger HugeInteger::operator+(const HugeInteger & op2)const
{
	HugeInteger temp; // temporary result
	int carry = 0;

	// iterate through HugeInteger
	for (int i = 39; i >= 0; --i)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		// determine whether to carry a 1
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10; // reduce to 0-9
			carry = 1;
		} // end if
		else // no carry
			carry = 0;
	} // end for

	return temp; // return the sum
} // end function add

// addition operator; HugeInteger + int
HugeInteger HugeInteger::add(int op2) const
{
	// convert op2 to a HugeInteger, then invoke add
	return *this + (HugeInteger(op2));
} // end function add

// HugeInteger + string that represents large integer value
HugeInteger HugeInteger::add(const string &op2) const
{
	// convert op2 to a HugeInteger, then invoke add
	return *this + (HugeInteger(op2));
} // end function add

// subtraction operator, subtract op2 from (*this)
HugeInteger HugeInteger::subtract(const HugeInteger & op2) const
{
	// return if first value is smaller; we are not handling negatives
	if (isLessThan(op2))
	{
		cout << "Error: Tried to subtract larger value from smaller value."
			<< endl;
		return HugeInteger("0");
	} // end if

	HugeInteger result("0"); // final result currently 0

	// used to determine if previous digit had 10 added to it;
	// if true, current digit needs to be reduced by 1
	bool minusOne = false;

	// for each digit in both arrays,
	// subtract digit of smaller int from digit of larger int
	for (int i = 39; i >= 0; --i)
	{
		// find digits we will currently be subtracting
		int topValue = integer[i];
		int bottomValue = op2.integer[i];

		// if previous topValue had 10 added to it;
		// subtract one from current topValue
		if (minusOne)
		{
			if (topValue == 0) // topValue cannot become -1

			   // set to 9 but keep minusOne true for next digit
				topValue = 9;
			else
			{
				topValue -= 1; // subtract from top value
				minusOne = false; // minusOne is handled, return to false
			} // end else
		} // end outer if

		// if topValue larger, perform subtraction and store result
		if (topValue >= bottomValue)
			result.integer[i] = topValue - bottomValue;
		else
		{
			topValue += 10; // if bottomValue larger, add 10 to topValue
			minusOne = true; // next digit must be decreased

			// topValue is now larger, perform subtraction and store result
			result.integer[i] = topValue - bottomValue;
		} // end else
	} // end for

	return result; // return final result
} // end function subtract

// function to subtract an integer from a HugeInteger
HugeInteger HugeInteger::subtract(int op2) const
{
	// convert op2 to a HugeInteger, then invoke subtract
	return subtract(HugeInteger(op2));
} // end function subtract

// function that takes string representing a number
// and subtracts it from a HugeInteger
HugeInteger HugeInteger::subtract(const string &op2) const
{
	// convert op2 to a HugeInteger, then invoke subtract
	return subtract(HugeInteger(op2));
} // end function subtract

// function that tests if two HugeIntegers are equal
bool HugeInteger::operator==(const HugeInteger & x) const
{
	for (int i = 39; i >= 0; --i)
		if (integer[i] != x.integer[i])
			return false;

	return true;
} // end function isEqualTo

// function that tests if two HugeIntegers are not equal
bool HugeInteger::isNotEqualTo(const HugeInteger & x) const
{
	return !(*this ==(x));
} // end function isNotEqualTo

// function to test if one HugeInteger is greater than another
bool HugeInteger::isGreaterThan(const HugeInteger & x) const
{
	return (x.isLessThan(*this));
} // end function isGreaterThan

// function that tests if one HugeInteger is less than another
bool HugeInteger::isLessThan(const HugeInteger & x) const
{
	for (int i = 0; i < 40; ++i)
		if (integer[i] > x.integer[i])
			return false;
		else if (integer[i] < x.integer[i])
			return true;

	return false;
} // end function isLessThan

// function that tests if one HugeInteger is greater than
// or equal to another
bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger & x) const
{
	return (!isLessThan(x));
} // end function isGreaterThanOrEqualTo

// function that tests if one HugeInteger is less than or
// equal to another
bool HugeInteger::isLessThanOrEqualTo(const HugeInteger & x) const
{
	return (*this == (x) || isLessThan(x));
} // end function isLessThanOrEqualTo

// function that tests if a HugeInteger is zero
bool HugeInteger::isZero() const
{
	for (int i = 0; i < 40; ++i)
		if (integer[i] != 0)
			return false;

	return true;
} // end function isZero

// converts a string representing a large integer into a HugeInteger
void HugeInteger::input(const string &val)
{
	// initialize array to zero
	for (int i = 0; i < 40; ++i)
		integer[i] = 0;

	// place digits of argument into array
	int length = val.size();

	for (int j = 40 - length, k = 0; j < 40; ++j, ++k)

		if (isdigit(val[k]))
			integer[j] = val[k] - '0';
} // end function input

// overloaded output operator
void HugeInteger::output() const
{
	int i; // used for looping

	for (i = 0; (i < 40) && (integer[i] == 0); ++i)
		; // skip leading zeros

	if (i == 40)
		cout << 0;
	else
		for (; i < 40; ++i) // display the HugeInteger
			cout << integer[i];
} // end function output

ostream & operator<<(ostream & out, const HugeInteger & other) {
	size_t i = 0;
	for (; i < 40&& other.integer[i] == 0; ++i) // print spaces
	{
		out << " ";
	}
	for (; i < 40; ++i) // print digits
	{
		out << other.integer[i];
	}
	return out;
}

istream & operator>>(istream & in, HugeInteger & other) {
	string temp;
	in >> temp;
	other = HugeInteger(temp);
	return in;
}