//Lamog, Rob
//Lab #8A
//Section #0245 MW 9am-11am

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#define l 50 //Default array length

using namespace std;

struct houseData {
    string id; //Household ID
	double income; //Household Income
	int members; //# of Members in Household
} household[l];

void openFiles(void);
void menuQuery(void); //Menu app.
void displayMenu(void); //Display menu options.
void selectionOutput(string str); //User selection output.
int grabData(void); //Returning count of struct household array.
void allHouseholdData(int i); //Output list of all household data.
void householdIncomeAboveAve(int i); //Output list of household income above average.
double findMean(houseData household[], int i); //Returning average household income.
void percentBelowPovertyLevel(int i); //Output percentage of households below poverty level.
void sortByIncome(int i); //Output sorted list of households by income.
void medianHouseholdIncome(int i); //Output median household income.
void closeFiles(void);

ifstream inData;
ofstream outData;

int main() {
	//openFiles();
	menuQuery();
	//closeFiles();
	
	//system("pause");
	return 0;
}

void openFiles() {
	//Open data file.
	inData.open("data.txt");
	//Checking for error opening data file.
	if (!inData) {
		cout << "Cannot open file. Terminating program." << endl;
		//system("pause");
		//exit (1);
	}
	
	//Open new files.
	outData.open("output.txt");
}

int grabData() {
	string houseID, houseIncome, iMembers;
/*	int i = 0; //Counter

	while (inData >> houseID >> houseIncome >> iMembers) {
		//Put House Data into struct houseData array.
		household[i].id = houseID;
		//cout << i << " " << household[i].id << " " << houseID << " ";

		//Convert houseIncome to double.
		stringstream(houseIncome) >> household[i].income;
		//cout << household[i].income << " " << houseIncome << " ";

		//Convert iMembers to int.
		stringstream(iMembers) >> household[i].members;
		//cout << household[i].members << " " << iMembers << endl;

		i++;
	}*/
	
	//Temp explicit array initialization.
	int i = 9; //Adjusting array length to test menu options.
	
	household[0].id = "WHVC";
	household[1].id = "AAAA";
	household[2].id = "BURB";
	household[3].id = "CCCC";
	household[4].id = "DATA";
	household[5].id = "EEEE";
	household[6].id = "FADE";
	household[7].id = "GATE";
	household[8].id = "HILO";

	household[0].income = 34000.00;
	household[1].income = 10500.00;
	household[2].income = 23500.00;
	household[3].income = 150000.00;
	household[4].income = 8000.00;
	household[5].income = 36000.00;
	household[6].income = 8500.00;
	household[7].income = 25000.00;
	household[8].income = 3000.00;
	
	household[0].members = 5;
	household[1].members = 8;
	household[2].members = 2;
	household[3].members = 4;
	household[4].members = 3;
	household[5].members = 5;
	household[6].members = 4;
	household[7].members = 1;
	household[8].members = 1;

	//cout << household[0].id << " " << household[0].income << " " << household[0].members << endl;
	
	return(i);
}

void menuQuery() {
	string str;
	
	while (str != "Exit") {
		displayMenu();
		cin >> str;
		if (str == "Exit") {
			cout << "Exiting menu. Have a great day." << endl;
			break;
		}
		
		//Initialize valid input flag and options.
		bool isInputValid = false;
		
		//Checking input and flagging for valid input.
		if (str == "1") isInputValid = true;
		if (str == "2") isInputValid = true;
		if (str == "3") isInputValid = true;
		if (str == "4") isInputValid = true;
		if (str == "5") isInputValid = true;
		
		if (!isInputValid) cout << "You have made an invalid entry. Please enter a proper selection." << endl << endl;
		else selectionOutput(str);
	}
}

void displayMenu() {
/*	cout << "Menu" << endl; //Temp menu*/
	cout << "Please make a selection from the following menu options:" << endl
		<< "1) Display all input data formatted with columns and column headers." << endl
		<< "2) Display list of households with income greater than average household income." << endl
		<< "3) Display percentage of households below poverty level." << endl
		<< "4) Display all input data sorted by household income." << endl
		<< "5) Display the median household income." << endl
		<< "Enter a number corresponding to your selection or enter 'Exit' to quit." << endl;
}

void selectionOutput(string str) {
	int totalEntries; //Total of entries in data struct houseData household[]
	
	//Grabbing data entries from file. Put total count in i.
	totalEntries = grabData();

	if (str == "1") allHouseholdData(totalEntries);
	if (str == "2") householdIncomeAboveAve(totalEntries);
	if (str == "3") percentBelowPovertyLevel(totalEntries);
	if (str == "4") sortByIncome(totalEntries);
	if (str == "5") medianHouseholdIncome(totalEntries);
}

void allHouseholdData(int i) {
	cout << "ALL Households, Income, and # of Members in Household." << endl
		<< "Household ID" << "\tHousehold Income" << "\t# of Members" << endl;
	for (int j = 0; j < i; j++) {
		cout.precision(2);
		cout << fixed << setw(12) << left << household[j].id << "\t$" << setw(15) << right << household[j].income << "\t" << left << household[j].members << endl;
	}
	cout << endl;
}

void householdIncomeAboveAve(int i) {
	double mean; //Average household income.
	
	mean = findMean(household, i);
	//cout << mean << endl;
	
	cout.precision(2);
	cout << fixed << "Households Above Average Income" << endl
		<< "Average Household Income: $" << mean << endl
		<< "Household ID" << "\tHousehold Income" << endl;	
	for (int j = 0; j < i; j++) {
		if (household[j].income > mean) {
			cout << setw(12) << left << household[j].id << "\t$" << setw(15) << right << household[j].income << endl;
		}
	}
	cout << endl;
}

double findMean(houseData household[], int i) {
	int j;
	double average, total = 0.0;
	
	for (j = 0; j < i; j++) {
		total = total + household[j].income;
	}
	average = total / j;
	//cout << "Average: " << average << endl;
	return(average);
}

void percentBelowPovertyLevel(int i) {
	float P; //Poverty level.
	float x = 0.0; //Counter, forcing float data type.
	double percent; //Percent of households below poverty level.

	for (int j = 0; j < i; j++) {
		P = 8000.00 + (500.00 * (household[j].members - 2));
		if (household[j].income < P) {
			x++;
			//cout << "Poverty Level: " << P << "\tIncome: " << household[j].income << endl;
		}
	}

	percent = (x / i) * 100;
	
	cout.precision(2);
	cout << fixed << percent << "% of households are below poverty level." << endl << endl;
}

void sortByIncome(int i) {
	//Temp storage for swapping.
	string tempString;
	double tempDouble;
	int tempInt;
	int d = i; //Comparison counter to total entries.
	int j, flag = 1; //Counter and flag to confirm swap.
	
	cout << "Data sorted by household income." << endl
		<< "Household ID" << "\tHousehold Income" << "\t# of Members" << endl;
	//Shell sort.
	while(flag || (d > 1)) {
		flag = 0;
		d = (d + 1) / 2;
		for (j = 0; j < (i - d); j++) {
			if (household[j + d].income > household[j].income) {
				//Swap Household Income Array
				tempDouble = household[j + d].income;
				household[j + d].income = household[j].income;
				household[j].income = tempDouble;
				//Swap Household ID - Parallel Array
				tempString = household[j + d].id;
				household[j + d].id = household[j].id;
				household[j].id = tempString;
				//Swap Number of Members in Household - Parallel Array
				tempInt = household[j + d].members;
				household[j + d].members = household[j].members;
				household[j].members = tempInt;
				
				flag = 1;
			}
		}
	}
	for (j = 0; j < i; j++) {
		cout.precision(2);
		cout << fixed << setw(12) << left << household[j].id << "\t$" << setw(15) << right << household[j].income << "\t" << left << household[j].members << endl;
	}
	cout << endl;
}

void medianHouseholdIncome(int i) {
	//Temp storage for swapping.
	string tempString;
	double tempDouble, average;
	int tempInt;
	int d = i;
	int j, flag = 1; //Counter and flag to confirm swap.
	
	//Shell sort.
	while(flag || (d > 1)) {
		flag = 0;
		d = (d + 1) / 2;
		for (j = 0; j < (i - d); j++) {
			if (household[j + d].income > household[j].income) {
				//Swap Household Income Array
				tempDouble = household[j + d].income;
				household[j + d].income = household[j].income;
				household[j].income = tempDouble;
				//Swap Household ID - Parallel Array
				tempString = household[j + d].id;
				household[j + d].id = household[j].id;
				household[j].id = tempString;
				//Swap Number of Members in Household - Parallel Array
				tempInt = household[j + d].members;
				household[j + d].members = household[j].members;
				household[j].members = tempInt;
				
				flag = 1;
			}
		}
	}
	
	if (i % 2) {
		j = i / 2;
		average = household[j].income;
	}
	else {
		j = i / 2;
		average = (household[j].income + household[j - 1].income) / 2.0;
	}
	
	cout.precision(2);
	cout << fixed << "$" << average << " is the median household income." << endl << endl;
}

void closeFiles() {
	inData.close();
	outData.close();
}