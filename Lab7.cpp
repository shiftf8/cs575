//Lamog, Rob
//Lab #7B
//Section #0245 MW 9am-11am

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define length 50

using namespace std;

ifstream inData;
ofstream outData;

//Prototypes
void openFiles(void);
void arraySort(void); //Sort data input into even and odd arrays.
void calcOut(int arr[], int x); //Average, High, Low.
void calcOutHigherThanAve(int arr[], int x, float average);
void closeFiles(void);

int main() {
    //openFiles();
	arraySort();
	//closeFiles();
	
	//system("pause");
	return 0;
}

/*void openFiles() {
	//Open data file.
	inData.open ("data.txt");

	//Checking for error opening data file.
	if (!inData) {
		cout << "Cannot open file, terminating program." << endl;
		exit (1);
	}

	//New files.
	outData.open("output.txt");
}*/

void arraySort() {
	string input;
	int inputInt, evens[length], odds[length];
	int i = 0, j = 0; //counters
	
	while (cin >> input) {
		stringstream(input) >> inputInt;
		//cout << inputInt << endl;
		if (!(inputInt % 2)) {
			evens[i] = inputInt;
			//cout << evens[i] << ", ";
			i++;
		}
		if (inputInt % 2) {
			odds[j] = inputInt;
			//cout << odds[j] << ", ";
			j++;
		}
	}
	
	//cout << odds[4];
	calcOut(evens, i);
	cout << endl << endl;
	calcOut(odds, j);
}

void calcOut(int arr[], int x) {
	float average, total = 0.0;
	int high = 0, low = 1000;
	int i; //counter
	
	cout << "Array [ ";
	for (i = 0; i < x; i++) {
		total = total + arr[i];
		//cout << " + " << arr[i] << " = " << total;
		if (arr[i] > high) high = arr[i];
		//cout << high << " ";
		if (arr[i] < low) low = arr[i];
		//cout << low << " ";
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
	
	average = total / x;
	cout << "Average = " << average << "\tHigh = "<< high << "\tLow = " << low << endl;
	calcOutHigherThanAve(arr, x, average);	
}

void calcOutHigherThanAve(int arr[], int x, float average) {
	int j; //counter
	
	cout << "Numbers higher than average [ ";
	for (j = 0; j < x; j++) {
		if (arr[j] > average) cout << arr[j] << " ";
	}
	cout << "]";
}

void closeFiles() {
	inData.close();
	outData.close();
}
