//Lamog, Rob
//Lab #5A
//Section #0245 MW 9am-11am

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int findmax(int& theuserInt, int& themax) {
    if (theuserInt > themax) themax = theuserInt;
	return(themax);
}

int findmin(int& theuserInt, int& themin) {
	if (theuserInt < themin) themin = theuserInt;
	return(themin);
}

int findtotal(int& theuserInt, int& thetotal) {
	thetotal = thetotal + theuserInt;
	return(thetotal);
}

float findaverage(float& theaverage, int& thetotal) {
	theaverage = thetotal / 7.0;
	return(theaverage);
}

int main() {
	
	ifstream inData;
	ofstream outData;
	string strInput;
	int userInt, max, min, total;
	float average;
	int i, j; //counters
	
/*	inData.open ("data.txt");

	//Checking for error with file.
	if (!inData) {
		cout << "Cannot open file, terminating program." << endl;
		exit (1);
	}
	
	outData.open ("newfile.txt");
*/	
	for (max = 0, min = 1000, total = 0, i = 0, j = 0; i < 7; i++) {
		//while (inData >> strInput) {
		while (cin >> strInput) {
			//cout << strInput << " ";

			//Convert string to integer.
			stringstream(strInput) >> userInt;
			cout << userInt << " ";
			//outData << userInt << " ";
			j++;

			//Checking for maximum.
			//if (userInt > max) max = userInt;
			findmax(userInt, max);
			//cout << max << " ";

			//Checking for minimum.
			//if (userInt < min) min = userInt;
			findmin(userInt, min);
			//cout << min << " ";
			
			//Totaling up line.
			//total = total + userInt;
			findtotal(userInt, total);

			//Average of the line.
			//average = total / 7.0;
			findaverage(average, total);

			if ((j % 7) == 0) {
				cout << endl << "Max: " << max << "\tMin: " << min << "\tTotal: " << total << "\tAverage: " << average << endl;
				//outData << endl << "Max: " << max << "\tMin: " << min << "\tTotal: " << total << "\tAverage: " << average << endl;
				average = 0;
				max = 0;
				min = 1000;
				total = 0;
			}
		}
	}
/*
	inData.close();
	outData.close ();
*/
	//system("pause");
	return 0;
}