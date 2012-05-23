//Lamog, Rob
//Lab #8A
//Section #0245 MW 9am-11am

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#define l 50 //Array length

using namespace std;

void openFiles(void);
void menuQuery(void);
void displayMenu(void);
void selOutput(int selectedOption);
void dataManipA(void);
void dataManipB(void);
double findMean(double arrHIn[], int x);
void dataManipC(void);
void dataManipD(void);
void dataManipE(void);
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

/*void openFiles() {
	//Open data file.
	inData.open("data.txt");
	//Checking for error opening data file.
	if (!inData) {
		cout << "Cannot open file. Terminating program." << endl;
		system("pause");
		exit (1);
	}
	
	//Open new files.
	outData.open("");
	errorData.open("");
}*/

void menuQuery() {
	string str;
	int selectedOption;
	
	while (str != "Exit") {
		//Initialize valid input flag.
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
	cout << "Menu" << endl; //Temp menu
/*	cout << "Please make a selection from the following menu options:" << endl
		<< "(A) Display all input data formatted with columns and column headers." << endl
		<< "(B) Display list of households with income greater than average household income." << endl
		<< "(C) Display percentage of households below poverty level." << endl
		<< "(D) Display all input data sorted by household income." << endl
		<< "(E) Display the median household income." << endl
		<< "Type a letter corresponding to your selection or type 'Exit' to quit, then press enter." << endl << endl;*/
}

void selOutput(int selectedOption) {
	if (selectedOption == 1) dataManipA();
	if (selectedOption == 2) dataManipB();
	if (selectedOption == 3) dataManipC();
	if (selectedOption == 4) dataManipD();
	if (selectedOption == 5) dataManipE();
}

void dataManipA() {
/*	string houseId, houseIncome, iMembers, arrHId[l];
	double double_houseIncome, arrHIn[l];
	int int_iMembers, arrMem[l];
	int i = 0, x = 0; //Counters

	while (cin >> houseId >> houseIncome >> iMembers) {
		//Put House Id in array.
		arrHId[i] = houseId;
		cout << i << " " << arrHId[i] << " ";
		//Put House Income in array.
		stringstream(houseIncome) >> double_houseIncome;
		arrHIn[i] = double_houseIncome;
		cout << arrHIn[i] << " ";
		//Put Number of Members in Household in array.
		stringstream(iMembers) >> int_iMembers;
		arrMem[i] = int_iMembers;
		cout << arrMem[i] << endl;
		x = i; //Total number of entries.
		i++;
	}*/
	
	//Temp Arrays explicitly initialized.
	string arrHId[] = {"WHVC", "AAAA", "BURB", "CCCC"};
	double arrHIn[] = {34000.00, 10500.00, 23500.00, 150000.00};
	int arrMem[] = {5, 8, 2, 4};

	int i, x = 4; //Counters
		
	cout << "Option A: ALL Households, Income, and # of Members in Household." << endl
		<< "Household ID" << "\tHousehold Income" << "\t# of Members" << endl;
	for (i = 0; i < x; i++) {
		cout.precision(2);
		cout << left << fixed << setw(12) << arrHId[i] << "\t" << setw(16) << right << arrHIn[i] << "\t" << left << arrMem[i] << endl;
	}
	cout << endl;
}

void dataManipB() {
/*	string houseId, houseIncome, iMembers, arrHId[l];
	double double_houseIncome, arrHIn[l];
	int int_iMembers, arrMem[l];
	int i = 0, x = 0; //Counters

	while (cin >> houseId >> houseIncome >> iMembers) {
		//Put House Id in array.
		arrHId[i] = houseId;
		cout << i << " " << arrHId[i] << " ";
		//Put House Income in array.
		stringstream(houseIncome) >> double_houseIncome;
		arrHIn[i] = double_houseIncome;
		cout << arrHIn[i] << " ";
		//Put Number of Members in Household in array.
		stringstream(iMembers) >> int_iMembers;
		arrMem[i] = int_iMembers;
		cout << arrMem[i] << endl;
		x = i; //Total number of entries.
		i++;
	}*/
	
	//Temp Arrays explicitly initialized.
	string arrHId[] = {"WHVC", "AAAA", "BURB", "CCCC"};
	double arrHIn[] = {34000.00, 10500.00, 23500.00, 150000.00};
	int arrMem[] = {5, 8, 2, 4};
		
	double mean;
	int i, x = 4; //Counters
	
	mean = findMean(arrHIn, x);

	cout << "Option B: Households Above Average Income" << endl
		<< "Household ID" << "\tHousehold Income" << endl;
	for (i = 0; i < x; i++) {
		if (arrHIn[i] > mean) {
			cout.precision(2);
			cout << left << fixed << setw(12) << arrHId[i] << "\t" << setw(16) << arrHIn[i] << endl;
		}
	}
	cout << endl;
}

double findMean(double arrHIn[], int x) {
	double average, total = 0.0;
	int i; //Counters
	
	for (i = 0; i < x; i++) {
		total = total + arrHIn[i];
	}
	average = total / x;
	//cout << "Average: " << average << endl;
	return(average);
}

void dataManipC() {
/*	string houseId, houseIncome, iMembers, arrHId[l];
	double double_houseIncome, arrHIn[l];
	int int_iMembers, arrMem[l];
	int i = 0, x = 0; //Counters

	while (cin >> houseId >> houseIncome >> iMembers) {
		//Put House Id in array.
		arrHId[i] = houseId;
		cout << i << " " << arrHId[i] << " ";
		//Put House Income in array.
		stringstream(houseIncome) >> double_houseIncome;
		arrHIn[i] = double_houseIncome;
		cout << arrHIn[i] << " ";
		//Put Number of Members in Household in array.
		stringstream(iMembers) >> int_iMembers;
		arrMem[i] = int_iMembers;
		cout << arrMem[i] << endl;
		x = i; //Total number of entries.
		i++;
	}*/
	
	//Temp Arrays explicitly initialized.
	string arrHId[] = {"WHVC", "AAAA", "BURB", "CCCC"};
	double arrHIn[] = {34000.00, 10500.00, 23500.00, 150000.00};
	int arrMem[] = {5, 8, 2, 4};

	float P; //Poverty level.
	float percent; //Percent of households below poverty level.
	float j = 0.0; //Count of households below poverty level.
	int i, x = 4; //Counters
	
	cout << "Option C: Percentage of households below poverty level." << endl;
	for (i = 0, j = 0; i < x; i++) {
		P = 8000.00 + (500.00 * (arrMem[i] - 2));
		if (arrHIn[i] < P) j++;
		//cout << "Poverty Level: " << P << endl;
	}
	//cout << j << endl;
	percent = (j / x) * 100;
	cout.precision(2);
	cout << fixed << percent << "% of households are below poverty level." << endl << endl;
}

void dataManipD() {
/*	string houseId, houseIncome, iMembers, arrHId[l];
	double double_houseIncome, arrHIn[l];
	int int_iMembers, arrMem[l];
	int i = 0, x = 0; //Counters

	while (cin >> houseId >> houseIncome >> iMembers) {
		//Put House Id in array.
		arrHId[i] = houseId;
		cout << i << " " << arrHId[i] << " ";
		//Put House Income in array.
		stringstream(houseIncome) >> double_houseIncome;
		arrHIn[i] = double_houseIncome;
		cout << arrHIn[i] << " ";
		//Put Number of Members in Household in array.
		stringstream(iMembers) >> int_iMembers;
		arrMem[i] = int_iMembers;
		cout << arrMem[i] << endl;
		x = i; //Total number of entries.
		i++;
	}*/
	
	//Temp Arrays explicitly initialized.
	string arrHId[] = {"WHVC", "AAAA", "BURB", "CCCC"};
	double arrHIn[] = {34000.00, 10500.00, 23500.00, 150000.00};
	int arrMem[] = {5, 8, 2, 4};
	
	string tempString;
	double tempDouble;
	int tempInt;
	int i, flag = 1, x = 4;
	int d = x;
	
	cout << "Option D: Data sorted by household income." << endl
		<< "Household ID" << "\tHousehold Income" << "\t# of Members in Household" << endl;
	//Shell sort.
	while(flag || (d > 1)) {
		flag = 0;
		d = (d+1) / 2;
		for (i = 0; i < (x - d); i++) {
			if (arrHIn[i + d] > arrHIn[i]) {
				//Swap Household Income Array
				tempDouble = arrHIn[i + d];
				arrHIn[i + d] = arrHIn[i];
				arrHIn[i] = tempDouble;
				//Swap Household ID - Parallel Array
				tempString = arrHId[i + d];
				arrHId[i + d] = arrHId[i];
				arrHId[i] = tempString;
				//Swap Number of Members in Household - Parallel Array
				tempInt = arrMem[i + d];
				arrMem[i + d] = arrMem[i];
				arrMem[i] = tempInt;
				
				flag = 1;
			}
		}
	}
	
	for (i = 0; i < x; i++) {
		cout.precision(2);
		cout << left << fixed << setw(12) << arrHId[i] << "\t" << setw(16) << right << arrHIn[i] << "\t" << left << arrMem[i] << endl;
	}
	cout << endl;
}

void dataManipE() {
/*	string houseId, houseIncome, iMembers, arrHId[l];
	double double_houseIncome, arrHIn[l];
	int int_iMembers, arrMem[l];
	int i = 0, x = 0; //Counters

	while (cin >> houseId >> houseIncome >> iMembers) {
		//Put House Id in array.
		arrHId[i] = houseId;
		cout << i << " " << arrHId[i] << " ";
		//Put House Income in array.
		stringstream(houseIncome) >> double_houseIncome;
		arrHIn[i] = double_houseIncome;
		cout << arrHIn[i] << " ";
		//Put Number of Members in Household in array.
		stringstream(iMembers) >> int_iMembers;
		arrMem[i] = int_iMembers;
		cout << arrMem[i] << endl;
		x = i; //Total number of entries.
		i++;
	}*/
	
	//Temp Arrays explicitly initialized.
	string arrHId[] = {"WHVC", "AAAA", "BURB", "CCCC"};
	double arrHIn[] = {34000.00, 10500.00, 23500.00, 150000.00};
	int arrMem[] = {5, 8, 2, 4};

	string tempString;
	double tempDouble, average;
	int tempInt;
	int i, flag = 1, x = 4;
	int d = x;
	
	cout << "Option E: Median household income." << endl;
	//Shell sort.
	while(flag || (d > 1)) {
		flag = 0;
		d = (d+1) / 2;
		for (i = 0; i < (x - d); i++) {
			if (arrHIn[i + d] > arrHIn[i]) {
				//Swap Household Income Array
				tempDouble = arrHIn[i + d];
				arrHIn[i + d] = arrHIn[i];
				arrHIn[i] = tempDouble;
				//Swap Household ID - Parallel Array
				tempString = arrHId[i + d];
				arrHId[i + d] = arrHId[i];
				arrHId[i] = tempString;
				//Swap Number of Members in Household - Parallel Array
				tempInt = arrMem[i + d];
				arrMem[i + d] = arrMem[i];
				arrMem[i] = tempInt;
				
				flag = 1;
			}
		}
	}
	
	if (x % 2) {
		i = x / 2;
		average = arrHIn[i];
	}
	else {
		i = x / 2;
		average = (arrHIn[i] + arrHIn[i-1]) / 2.0;
	}
	
	cout.precision(2);
	cout << fixed << average << " is the median household income." << endl;
}

void closeFiles() {
	inData.close();
	outData.close();
}