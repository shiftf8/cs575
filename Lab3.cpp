//Lamog, Rob
//March 7, 2012 Lab #3B
//Section #0245 MW 9am-11am

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    string initials;
	float a, b, c;
	double radianA, radianB, radianC;
	const float PI = 3.14159;
	
	cout << "Please enter your initials (FirstMiddleLast) without spaces or punctuation. \n";
	cin >> initials;
	//cout << initials << endl;
	cout << "Please enter three lengths (number number number) separated by spaces, to create a triangle. \n";
	cin >> a >> b >> c;
	//cout << a << " " << b << " " << c << endl;
	
	//Checking to see the values entered can make a triangle. If NOT, stop program.
	//Ask professor if this actually saves cycles? Does not save cycles.
	if ((a <= 0) || (b <= 0) || (c <= 0))
		cout << endl << initials << ", you have entered dimensions that cannot make a triangle. Please re-run the program to try again. \n";
	else
	{
		if (!(a + b > c) || !(b + c > a) || !(c + a > b))
		//The following expression is easier to read compared to the one above. Thanks dad. But C++ doesn't like multiple relations even with proper parentheses.
		//if (((a + b > c) || (b + c > a) || (c + a > b)) != true)
			cout << endl << initials << ", you have entered dimensions that cannot make a triangle. Please re-run the program to try again. \n";
		else
		{
			//Checking if triangle is equilateral. If TRUE, display output for equilateral triangle.
			if ((a == b) && (b == c))
				cout << endl << initials << ", you have entered the values of an equilateral triangle with " << a << " as the length of each side. \n";
			else
			{
				//Calculate if triangle has a right angle using law of cosines.
				radianC = acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b));
				cout << radianC << endl;
				if ((radianC > 1.5707 && radianC < 1.58))
					radianC = 1;
				radianB = acos((pow(c, 2) + pow(a, 2) - pow(b, 2))/(2*c*a));
				cout << radianB << endl;
				if ((radianB > 1.5707 && radianB < 1.58))
					radianB = 1;
				radianA = acos((pow(b, 2) + pow(c, 2) - pow(a, 2))/(2*b*c));
				cout << radianA << endl;
				if ((radianA > 1.5707 && radianA < 1.58))
					radianA = 1;
				
				//Check if triangle has a 90 degree angle. If NOT, output isosceles or scalene.
				if ((radianA == 1) || (radianB == 1) || (radianC == 1))
				{
					//Check if triangle is isosceles right triangle. If NOT, it must be a scalene right triangle.
					if ((a == b) || (b == c) || (c == a))
						cout << endl << initials << ", this is an isosceles right triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
					else
						cout << endl << initials << ", this is a scalene right triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
				}
				else
				{
					//Check if triangle is isosceles. If NOT, it must be a scalene triangle.
					if ((a == b) || (b == c) || (c == a))
						cout << endl << initials << ", this is an isosceles triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
					else
						cout << endl << initials << ", this is a scalene triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
				}
			}	
		}
	}
//	system("pause");
	return 0;
}