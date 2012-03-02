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
	int angleA, angleB, angleC;
	float a, b, c;
	double radA, radB, radC;
	const float PI = 3.14159;
	
	cout << "Please enter your initials (FirstMiddleLast) without spaces or punctuation. \n";
	cin >> initials;
	cout << initials << endl;
	cout << "Please enter three lengths (number number number) separated by spaces, to create a triangle. \n";
	cin >> a >> b >> c;
	cout << a << " " << b << " " << c << endl;
	
	//Checking to see the values entered can make a triangle. If NOT, stop program.
	if (!((a + b) > c) || !((b + c) > a) || !((c + a) > b))
	{
		cout << endl << initials << ", you have entered dimensions that cannot make a triangle. Please re-run the program to try again. \n";
	}
	else
	{
		//Checking if triangle is equilateral. If TRUE, display output for equilateral triangle.
		if ((a == b) && (b == c))
		{
			cout << endl << initials << ", you have entered the values of an equilateral triangle with " << a << " as the length of each side. \n";
		}
		else
		{
			//Calculate if triangle has a right angle using law of cosines.
			//Must also remember to convert radian answer to degrees.
			radC = acos((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b));
			angleC = radC*180/PI;
//			cout << angleC << endl;
			radB = acos((pow(c, 2) + pow(a, 2) - pow(b, 2))/(2*c*a));
			angleB = radB*180/PI;
//			cout << angleB << endl;
			radA = acos((pow(b, 2) + pow(c, 2) - pow(a, 2))/(2*b*c));
			angleA = radA*180/PI;
//			cout << angleA << endl;
			
			//Check if triangle has a 90 degree angle. If NOT, output isosceles or scalene.
			if ((angleA == 90) || (angleB == 90) || (angleC == 90))
			{
				//Check if triangle is isosceles right triangle. If NOT, it must be a scalene right triangle.
				if ((a == b) || (b == c) || (c == a))
				{
					cout << endl << initials << ", this is an isosceles right triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
				}
				else
				{
					cout << endl << initials << ", this is a scalene right triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
				}
			}
			else
			{
				//Check if triangle is isosceles. If NOT, it must be a scalene triangle.
				if ((a == b) || (b == c) || (c == a))
				{
					cout << endl << initials << ", this is an isosceles triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
				}
				else
				{
					cout << endl << initials << ", this is a scalene triangle with (" << a << ", " << b << ", " << c << ") as the lengths of each side. \n";
				}
			}
		}	
	}
//	system("pause");
	return 0;
}