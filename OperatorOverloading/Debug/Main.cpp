// In-Class Exercise for Classes
// HugeInteger test program.
#include <iostream>
#include <cstdlib>
#include "HugeInteger.h" // include definition of class HugeInteger
using namespace std;

int main()
{
	HugeInteger n1(7654321);
	HugeInteger n2("100000000000000");
	HugeInteger n3; // HugeInteger object n3
	HugeInteger n4(5);
	HugeInteger n5;


	// n5 = n1.add(n2);
	n5 = n1 + n2;
	// n1.output();
	cout << "   n1:" << n1 << endl;
	cout << " + ";
	// n2.output();
	cout << "n2:" << n2 << endl;
	cout << " = ";
	// n5.output();
	cout << "n5:" << n5 << endl;
	cout << "\n\n";


	n5 = n2.subtract(n4);
	n2.output();
	cout << " - ";
	n4.output();
	cout << " = ";
	n5.output();
	cout << "\n\n";


	if (n2==(n2) == true)
	{
		cout << n2;// n2.output();
		cout << " is equal to ";
		//n2.output();
		cout << n2;
		cout << "\n\n";
	}


	if (n1.isNotEqualTo(n2) == true)
	{
		n1.output();
		cout << " is not equal to ";
		n2.output();
		cout << "\n\n";
	}


	if (n2.isGreaterThan(n1) == true)
	{
		n2.output();
		cout << " is greater than ";
		n1.output();
		cout << "\n\n";
	}


	if (n4.isLessThan(n2) == true)
	{
		n4.output();
		cout << " is less than ";
		n2.output();
		cout << "\n\n";
	}


	if (n4.isLessThanOrEqualTo(n4) == true)
	{
		n4.output();
		cout << " is less than or equal to ";
		n4.output();
		cout << "\n\n";
	}


	if (n4.isLessThanOrEqualTo(n2) == true)
	{
		n4.output();
		cout << " is less than or equal to ";
		n2.output();
		cout << "\n\n";
	}


	if (n3.isGreaterThanOrEqualTo(n3) == true)
	{
		n3.output();
		cout << " is greater than or equal to ";
		n3.output();
		cout << "\n\n";
	}


	if (n2.isGreaterThanOrEqualTo(n3) == true)
	{
		n2.output();
		cout << " is greater than or equal to ";
		n3.output();
		cout << "\n\n";
	}


	if (n3.isZero() == true)
	{
		cout << "n3 contains ";
		n3.output();
		cout << "\n\n";
	}

	system("pause");
	return 0;
}
