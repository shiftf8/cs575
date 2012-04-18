//Lamog, Rob
//Lab #5A
//Section #0245 MW 9am-11am

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    
	ifstream inData;
	ofstream outData;
	string strInput;
	int userInt;
	int max, min, total;
	float average;
	int i, j; //counters
	
	inData.open ("C:\\temp\\data.txt");

	//Checking for error with file.
	if (!inData) {
		cout << "Cannot open file, terminating program." << endl;
		exit (1);
	}
	
	outData.open ("C:\\temp\\newfile.txt");
	
	for (max = 0, min = 1000, total = 0, i = 0, j = 0; i < 7; i++) {
		while (inData >> strInput) {
			//cout << strInput << " ";

			//Convert string to integer.
			stringstream(strInput) >> userInt;
			//cout << userInt << " ";
			outData << userInt << " ";
			j++;

			//Checking for maximum.
			if (userInt > max) max = userInt;
			//cout << max << " ";

			//Checking for minimum.
			if (userInt < min) min = userInt;
			//cout << min << " ";
			
			//Totaling up line.
			total = total + userInt;

			//Average of the line.
			average = total / 7;

			if ((j % 7) == 0) {
				//cout << endl << "Max: " << max << "\tMin: " << min << "\tTotal: " << total << "\tAverage: " << average << endl;
				outData << endl << "Max: " << max << "\tMin: " << min << "\tTotal: " << total << "\tAverage: " << average << endl;
				average = 0;
				max = 0;
				min = 1000;
				total = 0;
			}
		}
	}

	inData.close();
	outData.close ();

	//system("pause");
	return 0;
}