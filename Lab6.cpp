//Lamog, Rob
//Lab #6A
//Section #0245 MW 9am-11am

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const float adultStandard = 21.75;
const float adultDeluxe = 25.80;
const float childDiscount = 0.60;
const float tipAndTax = 0.18;
const float surcharge = 0.07;
const float discountA = 0.015;
const float discountB = 0.025;
const float discountC = 0.035;

ifstream inData;
ofstream outData, errorData;

//Prototypes
void openFiles(void);
void billing(void);
void custom_ErrorFlags(bool error_A, bool error_C, bool error_M, bool error_S, bool error_D, string adults, string children, string meal, string surcharge, string deposit);
void billing_Statement(int adultsInt, int childrenInt, bool deluxeMeal, bool weekendSurcharge, float depositFloat);
float calc_AdultStandardMeal(int adultsInt);
float calc_ChildrenStandardMeal(int childrenInt);
float calc_AdultDeluxeMeal(int adultsInt);
float calc_ChildrenDeluxeMeal(int childrenInt);
float calc_TipandTax(float mealSubTotal);
float calc_Surcharge(float totalMeals);
float calc_EarlyPaymentDiscount(float totalBill);
void closeFiles(void);

int main() {
    openFiles();
    billing();
    closeFiles();

	system("pause");
	return 0;
}

void openFiles() {
    //Open data file.
    inData.open("C:\\temp\\Lab6\\data.txt");

	//Checking for error opening data file.
	if (!inData) {
		cout << "Cannot open file, terminating program." << endl;
		exit (1);
	}

    //New files.
    outData.open("C:\\temp\\Lab6\\billingstatement.txt");
    errorData.open("C:\\temp\\Lab6\\billingerrorfile.txt");
}

void billing() {
    string adults, children, meal, surcharge, deposit; //Data string variables.
    //Data converted variables.
    int adultsInt, childrenInt;
    bool deluxeMeal = false, weekendSurcharge = false;
	float depositFloat;

	bool error_A = false, error_C = false, error_M = false, error_S = false, error_D = false; //Custom error flags.
    
    while (inData >> adults >> children >> meal >> surcharge >> deposit) {
	//while (cin >> adults >> children >> meal >> surcharge >> deposit) {
		stringstream(adults) >> adultsInt;
		if (adultsInt < 0) error_A = true;
		
		stringstream(children) >> childrenInt;
		if (childrenInt < 0) error_C = true;
		
		if (meal == "D") deluxeMeal = true;
		else if (meal == "S") deluxeMeal = false;
		else error_M = true;
		
		if (surcharge == "Y") weekendSurcharge = true;
		else if (surcharge == "N") weekendSurcharge = false;
		else error_S = true;
		
		stringstream(deposit) >> depositFloat;
		if (depositFloat < 0.0) error_D = true;
		
		if (error_A || error_C || error_M || error_S || error_D) {
			custom_ErrorFlags(error_A, error_C, error_M, error_S, error_D, adults, children, meal, surcharge, deposit);
			//Reset custom error flags before continuing.
			error_A = false, error_C = false, error_M = false, error_S = false, error_D = false;
		}
		else billing_Statement(adultsInt, childrenInt, deluxeMeal, weekendSurcharge, depositFloat);
		//cout << adults << " " << children << " " << meal << " " << surcharge << " " << deposit << endl;
	}
}		

void custom_ErrorFlags(bool error_A, bool error_C, bool error_M, bool error_S, bool error_D, string adults, string children, string meal, string surcharge, string deposit) {
    errorData << "Adults: " << adults << " Children: " << children << " Meal: "  << meal << " Surcharge: "  << surcharge << " Deposit: $"  << deposit << " "  << endl;
	if (error_A) errorData << "Invalid number of adults." << endl;
	if (error_C) errorData << "Invalid number of children." << endl;
	if (error_M) errorData << "Invalid meal selection." << endl;
	if (error_S) errorData << "Invalid surcharge entry." << endl;
	if (error_D) errorData << "Invalid deposit entry." << endl;
	errorData << endl;
}

void billing_Statement(int adultsInt, int childrenInt, bool deluxeMeal, bool weekendSurcharge, float depositFloat) {
	float adultMealTotal, childrenMealTotal, mealSubTotal, tipAndTaxTotal, surchargeTotal = 0.0, totalMeals, totalBill, balance, earlyPaymentDiscount;

	//Deluxe Meal total.
	if (deluxeMeal) {
		//cout << "Deluxe Meal" << endl;
		outData << "Deluxe Meal" << endl;
		adultMealTotal = calc_AdultDeluxeMeal(adultsInt);
		childrenMealTotal = calc_ChildrenDeluxeMeal(childrenInt);
		mealSubTotal = calc_AdultDeluxeMeal(adultsInt) + calc_ChildrenDeluxeMeal(childrenInt);
		//cout << "Deluxe Meal: " << mealTotal << " = (" << adultsInt << " * " << adultDeluxe << ") + ((" << childrenInt << " * " << adultDeluxe << ") / " << childDiscount << ")" << endl;
	}
	//Standard Meal total.
	else {
		//cout << "Standard Meal" << endl;
		outData << "Standard Meal" << endl;
		adultMealTotal = calc_AdultStandardMeal(adultsInt);
		//cout << calc_AdultStandardMeal(adultsInt) << endl;
		childrenMealTotal = calc_ChildrenStandardMeal(childrenInt);
		//cout << calc_ChildrenStandardMeal(childrenInt) << endl;
		mealSubTotal = calc_AdultStandardMeal(adultsInt) + calc_ChildrenStandardMeal(childrenInt);
		//cout << "Standard Meal: " << mealTotal << " = (" << adultsInt << " * " << adultDeluxe << ") + ((" << childrenInt << " * " << adultDeluxe << ") / " << childDiscount << ")" << endl;
	}

	tipAndTaxTotal = calc_TipandTax(mealSubTotal);
	totalMeals = mealSubTotal + tipAndTaxTotal;
    //Only calculate surcharge if necessary.
	if (weekendSurcharge) surchargeTotal = calc_Surcharge(totalMeals);
	totalBill = mealSubTotal + tipAndTaxTotal + surchargeTotal;
	balance = totalBill - depositFloat;
    //Balance could be negative, which means no discount.
	if (balance > 0.0) earlyPaymentDiscount = calc_EarlyPaymentDiscount(totalBill);
	else earlyPaymentDiscount = 0.0;
	
	//cout.precision(2);
	outData.precision(2);
	outData << fixed << "# of Adults: \t" << setw(4) << adultsInt << "\tCost: \t\t$" << setw(8) << adultMealTotal << endl
		<< "# of Children: \t" << setw(4) << childrenInt << "\tCost: \t\t$" << setw(8) << childrenMealTotal << endl
		<< "\t\t\tSubtotal: \t$" << setw(8) << mealSubTotal << endl
		<< "\t\t\tTip and Tax: \t$" << setw(8) << tipAndTaxTotal << endl
		<< "\t\t\tSurchage: \t$" << setw(8) << surchargeTotal << endl
		<< "\t\t\tTotal Bill: \t$" << setw(8) << totalBill << endl
        << "\t\t\tDeposit: \t$" << setw(8) << -(depositFloat) << endl << endl
		<< "\tOutstanding Balance: $" << balance << endl
		<< "Early payment Discount if paid within 10 days: $" << earlyPaymentDiscount << endl << endl;
}

float calc_AdultStandardMeal(int adultsInt) {	
	float adultMealTotal;
	adultMealTotal = adultsInt * adultStandard;
	return(adultMealTotal);
}

float calc_ChildrenStandardMeal(int childrenInt) {	
	float childrenMealTotal;
	childrenMealTotal = (childrenInt * adultStandard) * childDiscount;
	return(childrenMealTotal);
}

float calc_AdultDeluxeMeal(int adultsInt) {
	float adultMealTotal;
	adultMealTotal = adultsInt * adultDeluxe;
	return(adultMealTotal);
}

float calc_ChildrenDeluxeMeal(int childrenInt) {
	float childrenMealTotal;
	childrenMealTotal = (childrenInt * adultDeluxe) * childDiscount;
	return(childrenMealTotal);
}

float calc_TipandTax(float mealSubTotal) {	
	float tipAndTaxTotal;
	tipAndTaxTotal = mealSubTotal * tipAndTax;
	return(tipAndTaxTotal);
}

float calc_Surcharge(float totalMeals) {
	float surchargeTotal;
	surchargeTotal = totalMeals * surcharge;
	return(surchargeTotal);
}

float calc_EarlyPaymentDiscount(float totalBill) {
	float earlyPaymentDiscount;
    if (totalBill > 0.0) {
		if (totalBill < 100.0) earlyPaymentDiscount = -(totalBill * discountA);
		if ((totalBill >= 100.0) && (totalBill < 400.0)) earlyPaymentDiscount = -(totalBill * discountB);
		if (totalBill >= 400.0) earlyPaymentDiscount = -(totalBill * discountC);
	}
	return(earlyPaymentDiscount);
}

void closeFiles() {
	inData.close();
	outData.close();
	errorData.close();
}
