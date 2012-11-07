//Lamog, Rob
//Lab #4A
//Section #0245 MW 9am-11am

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    
    int userInt = 0;
	string strInput;
	size_t found;
	int isDivisible, isPerfect;
	int i, j; //counters
	
	do {
		cout << "Enter an integer from 1 to 1000 or \'0\' to quit: \n";
		getline (cin, strInput);
		//cout << strInput << endl;

		if (strInput == "0") break;
		
		//Convert string to integer.
		stringstream(strInput) >> userInt;
		//cout << userInt << endl;
		
		//Search string input for decimal/period.
		found = strInput.find('.');
		
		if (found != string::npos) {
			cout << strInput << " is not a valid entry.\n";
		
		//Check if user input is outside of 0 and 1000.
		} else if (userInt < 0 || userInt > 1000) {
			cout << strInput << " is not a valid entry.\n";
			
		} else {
			//Loop through all possible divisors of user input.
			for (i = 1, j = 0, isDivisible = 0, isPerfect = 0; userInt != i; i++) {
				isDivisible = userInt % i; //Checking if user input is evenly divisible.
				if (isDivisible == 0) {
					isPerfect = isPerfect + i; //Checking if user input is perfect.
					j++; //Counting number of times user input is evenly divisible.
					
				}
				//cout << userInput << " " << isDivisible << " " << i << " " << j << endl;
			}
			
			//One is a unique number.
			if (userInt == 1) cout << userInt << " is neither perfect or prime." << endl;
			
			//With only one even divisor, number is prime.
			if (j == 1) cout << userInt << " is prime." << endl;
			
			//Number is perfect if even divisors add up to userInput.
			if (userInt == isPerfect) {
				cout << userInt << " is perfect." << endl
					<< "Divisors include:" << endl;
				
				//Initialize counters
				i = 1; j = 0;
				
				while (userInt != i) {
					isDivisible = userInt % i;
					if (isDivisible == 0) {
						cout << "\t" << i;
						j++;
						if ((j % 6) == 0) cout << endl;
					}
					i++;
				}
				cout << endl;
			
			//Number must not be prime.
			} else if (j > 1) {
				cout << userInt << " is not prime." << endl
					<< "Divisors include:" << endl;
				
				//Initialize counters
				i = 1; j = 0;
				
				while (userInt != i) {
					isDivisible = userInt % i;
					if (isDivisible == 0) {
						cout << "\t" << i;
						j++;
						if ((j % 6) == 0) cout << endl;
					}
					i++;
				}
				cout << endl;
			}
		}
	} while (strInput != "0"); //Loop until 0 is entered.
	cout << "You have entered 0. Thank you for playing.\n";

//	system("pause");
	return 0;
}