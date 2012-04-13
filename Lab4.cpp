//Lamog, Rob
//FFFF, 2012 Lab #4A
//Section #0245 MW 9am-11am

#include <iostream>

using namespace std;

int main() {
    
	int userInput = 0;
	int isDivisible, isPerfect;
	int i, j; //counters
	
	do {
		/*
			how do i check if user input is actually an integer? how do i sanitize input?
			run a loop on each input character and check it? what about white space? null
			characters? started looking at c_text and thought i was close when i examined
			hex values. note to self. look into at a later date. not "required" for this
			assignment.
		*/
		
		cout << "Enter an integer from 1 to 1000 or enter 0 to quit: \n";
		cin >> userInput;
		//cout << userInput << endl;
		
		//Check if user input is outside of 0 and 1000.
		if (userInput < 0 || userInput > 1000) {
			cout << userInput << " is not a valid entry.\n";
			//cout << userInput << endl;
			
		} else {
			//Break loop if user input is zero.
			if (userInput == 0) break;
		
			//Loop through all possible divisors of user input.
			for (i = 1, j = 0, isDivisible = 0, isPerfect = 0; userInput != i; i++) {
				isDivisible = userInput % i; //Checking if user input is divisible.
				if (isDivisible == 0) {
					isPerfect = isPerfect + i; //Checking if user input is perfect.
					j++; //Counting number of times user input is evenly divisible.
					
				}
				//cout << userInput << " " << isDivisible << " " << i << " " << j << endl;
			}
			
			//One is a unique number.
			if (userInput == 1) cout << userInput << " is neither perfect or prime." << endl;
			
			//Check if number is prime.
			if (j == 1) cout << userInput << " is prime." << endl;
			
			//Check if number is perfect.
			if (userInput == isPerfect) {
				cout << userInput << " is perfect." << endl;
				cout << "Divisors include: ";
				i = 1;
				while (userInput != i) {
					isDivisible = userInput % i;
					if (isDivisible == 0) {
						cout << i << " ";
					}
					i++;
				}
				cout << endl;
			
			//Number must not be prime.
			} else if (j > 1) {
				cout << userInput << " is not prime." << endl;
				cout << "Divisors include: ";
				i = 1;
				while (userInput != i) {
					isDivisible = userInput % i;
					if (isDivisible == 0) {
						cout << i << " ";
					}
					i++;
				}
				cout << endl;
			}
		}			
	} while (userInput != 0); //Loop until 0 is entered.
	cout << "You have entered 0. Thank you for playing.\n";

//	system("pause");
	return 0;
}