//Lamog, Rob
//February 22, 2012 Lab #2A
//Section #0245 MW 9am-11am

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string employeeInitials;
	float numberOfHoursWorked;
	double employeePayRate, grossWages, federalWithholding, stateWithholding, unionWithholding, totalDeductions, netPay;
	
	const double federalWithholdingRate = 0.18;
	const double stateWithholdingRate = 0.045;
	const double hospitalization = 25.65;
	const double unionDues = 0.02;
	
	cout << "Please enter your initials (FirstMiddleLast) without spaces or punctuation. \n";
	cin >> employeeInitials;
//	cout << employeeInitials << endl;
	cout << "Please enter the number of hours (ie 40.5) worked. \n";
	cin >> numberOfHoursWorked;
//	cout << numberOfHoursWorked << endl;
	cout << "Please enter hourly rate as a decimal (ie 12.00). \n";
	cin >> employeePayRate;
//	cout << employeePayRate << endl;
	
	grossWages = numberOfHoursWorked * employeePayRate;
	federalWithholding = federalWithholdingRate * grossWages;
	stateWithholding = stateWithholdingRate * grossWages;
	unionWithholding = unionDues * grossWages;
	totalDeductions = federalWithholding + stateWithholding + hospitalization + unionWithholding;
	netPay = grossWages - totalDeductions;

//checking variables exist and are doing something
/*
	cout << grossWages << endl;
	cout << federalWithholding << endl;
	cout << stateWithholding << endl;
	cout << unionWithholding << endl;
	cout << totalDeductions << endl;
	cout << netPay << endl;
*/
	
	cout << fixed << showpoint << setprecision(2)
		<< "Employee \t" << setw (15) << employeeInitials << endl
		<< "Hours Worked \t" << setw (15) << numberOfHoursWorked << endl
		<< "Hourly Rate \t" << setw (15) << employeePayRate << endl
		<< "Total Wages \t" << setw (15) << grossWages << endl
		<< endl << "Deductions" << endl
		<< "Federal Withholding: \t" << setw (7) << federalWithholding << endl
		<< "State Withholding \t" << setw (7) << stateWithholding << endl
		<< "Hospitalization \t" << setw (7) << hospitalization << endl
		<< "Union Dues \t" << setw (15) << unionWithholding << endl
		<< "Total Deductions \t" << setw (7) << totalDeductions << endl
		<< "Net Pay \t" << setw (15) << netPay << endl;
	
//	system("pause");
	return 0;
}