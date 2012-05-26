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
void selOutput(int selectedOption); //User selection output.
int grabData(void); //Returning count of struct household array.
void dataManipA(int i); //Output list of all household data.
void dataManipB(int i); //Output list of household income above average.
double findMean(houseData household[], int i); //Returning average household income.
void dataManipC(int i); //Output percentage of households below poverty level.
void dataManipD(int i); //Output sorted list of households by income.
void dataManipE(int i); //Output median household income.
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
	int i = 9; //Counter

/*	while (cin >> houseID >> houseIncome >> iMembers) {
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
	int selectedOption;
	
	while (str != "Exit") {
		//Initialize valid input flag and options.
		bool inputValid = false;
		selectedOption = 0;

		displayMenu();
		cin >> str;
		if (str == "Exit") {
			cout << "Exiting app. Have a great day." << endl;
			break;
		}
		//Checking input and flagging for valid input.
		if ((str == "a") || (str == "A")) {
			//cout << str << endl;
			selectedOption = 1;
			inputValid = true;
		}
		if ((str == "b") || (str == "B")) {
			selectedOption = 2;
			inputValid = true;
		}
		if ((str == "c") || (str == "C")) {
			selectedOption = 3;
			inputValid = true;
		}
		if ((str == "d") || (str == "D")) {
			selectedOption = 4;
			inputValid = true;
		}
		if ((str == "e") || (str == "E")) {
			selectedOption = 5;
			inputValid = true;
		}
		
		if (!inputValid) cout << "You have made an invalid entry. Please enter a proper selection." << endl;
		else selOutput(selectedOption);
			//cout << selectedOption << endl;
	}
}

void displayMenu() {
//	cout << "Menu" << endl; //Temp menu
	cout << "Please make a selection from the following menu options:" << endl
		<< "(A) Display all input data formatted with columns and column headers." << endl
		<< "(B) Display list of households with income greater than average household income." << endl
		<< "(C) Display percentage of households below poverty level." << endl
		<< "(D) Display all input data sorted by household income." << endl
		<< "(E) Display the median household income." << endl
		<< "Type a letter corresponding to your selection or type 'Exit' to quit, then press enter." << endl << endl;
}

void selOutput(int selectedOption) {
	int i; //Total of entries in data struct houseData household[]
	
	//Grabbing data entries from file. Put total count in i.
	i = grabData();

	if (selectedOption == 1) dataManipA(i);
	if (selectedOption == 2) dataManipB(i);
	if (selectedOption == 3) dataManipC(i);
	if (selectedOption == 4) dataManipD(i);
	if (selectedOption == 5) dataManipE(i);
}

void dataManipA(int i) {
	int j; //Counter
	
	cout << "Option A: ALL Households, Income, and # of Members in Household." << endl
		<< "Household ID" << "\tHousehold Income" << "\t# of Members" << endl;
	
	for (j = 0; j < i; j++) {
		cout.precision(2);
		cout << fixed << setw(12) << left << household[j].id << "\t$" << setw(15) << right << household[j].income << "\t" << left << household[j].members << endl;
	}
	cout << endl;
}

void dataManipB(int i) {
	double mean; //Average household income.
	int j; //Counter
	
	mean = findMean(household, i);
	//cout << mean << endl;
	
	cout.precision(2);
	cout << fixed << "Option B: Households Above Average Income" << endl
		<< "Average Household Income: $" << mean << endl
		<< "Household ID" << "\tHousehold Income" << endl;	
	for (j = 0; j < i; j++) {
		if (household[j].income > mean) {
			cout << setw(12) << left << household[j].id << "\t$" << setw(15) << right << household[j].income << endl;
		}
	}
	cout << endl;
}

double findMean(houseData household[], int i) {
	double average, total = 0.0;
	int j; //Counter
	
	for (j = 0; j < i; j++) {
		total = total + household[j].income;
	}
	average = total / j;
	//cout << "Average: " << average << endl;
	return(average);
}

void dataManipC(int i) {
	float P; //Poverty level.
	float x; //Counter, forcing float data type.
	double percent; //Percent of households below poverty level.
	int j; //Counter
	
	cout << "Option C: Percentage of households below poverty level." << endl;
	for (j = 0, x = 0; j < i; j++) {
		P = 8000.00 + (500.00 * (household[j].members - 2));
		if (household[j].income < P) {
			x++;
			//cout << "Poverty Level: " << P << "\tIncome: " << household[j].income << endl;
		}
	}
	//cout << x << " " << j << endl;
	percent = (x / j) * 100;
	cout.precision(2);
	cout << fixed << percent << "% of households are below poverty level." << endl << endl;
}

void dataManipD(int i) {
	//Temp storage for swapping.
	string tempString;
	double tempDouble;
	int tempInt;
	int d = i;
	int j, flag = 1; //Counter and flag to confirm swap.
	
	cout << "Option D: Data sorted by household income." << endl
		<< "Household ID" << "\tHousehold Income" << "\t# of Members" << endl;
	//Shell sort.
	while(flag || (d > 1)) {
		flag = 0;
		d = (d+1) / 2;
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

void dataManipE(int i) {
	//Temp storage for swapping.
	string tempString;
	double tempDouble, average;
	int tempInt;
	int d = i;
	int j, flag = 1; //Counter and flag to confirm swap.
	
	cout << "Option E: Median household income." << endl;
	//Shell sort.
	while(flag || (d > 1)) {
		flag = 0;
		d = (d+1) / 2;
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