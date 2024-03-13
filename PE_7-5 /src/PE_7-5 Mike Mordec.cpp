//============================================================================
// Name        : PE_7-5.cpp
// Author      : Mike Mordec
// Date        : 10/23/22
//             : This is LAB 5 of CSC 155 - CS Department Oakton Community College
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void getData(int &numPerson, int &numChildren, double &salary, int &pension,
		double &tax);
double taxAmount(int numPerson, double salary, double pension, double tax,
		double totalTax);

int main() {
	int numberOfPerson = 0;
	int numberOfChildren = 0;
	int pensionPercent = 0;
	double grossIncome = 0;
	double taxableIncome = 0;
	double taxOwed = 0;
	double taxPayment = 0;

	getData(numberOfPerson, numberOfChildren, grossIncome, pensionPercent,
			taxableIncome);

	taxPayment = taxAmount(numberOfPerson, grossIncome, pensionPercent,
			taxableIncome, taxOwed);
	cout << std::fixed << std::setprecision(2);
	cout << "The tax is: " << taxPayment << endl;

	return 0;
}

void getData(int &numPerson, int &numChildren, double &salary, int &pension,
		double &tax) {
	char maritalStatus;

	cout << "Enter marital status. M = Married & S = Single. ";
	cin >> maritalStatus;
	cout << endl;

	if (maritalStatus == 'm' || maritalStatus == 'M') {
		cout << "Any children under the age of 14? ";
		cin >> numChildren;
		cout << endl;

		numPerson = 2 + numChildren;
	}

	else if (maritalStatus == 's' || maritalStatus == 'S') {
		numPerson = 1;
	}

	cout
			<< "Enter gross salary for the year: ";
	cin >> salary;
	cout << endl;

	cout << "Enter the percentage of salary contributed to pension (0-6 percent) ";
	cin >> pension;
	cout << endl;
}

double taxAmount(int numPerson, double salary, double pension, double tax,
		double totalTax) {

	const int PERSONAL_EXEMPTION = 1500;
	const int SINGLE_EXEMPTION = 4000;
	const int MARRIED_EXEMPTION = 7000;

	if (numPerson == 1)
	{
		tax = salary - PERSONAL_EXEMPTION;
		tax = tax - SINGLE_EXEMPTION;
		tax = tax - salary * (pension / 100.00);
	}
	else if (numPerson >= 2)
	{
		tax = salary - MARRIED_EXEMPTION;
		tax = tax - (PERSONAL_EXEMPTION * numPerson);
		tax = tax - salary * (pension / 100);

	}
	if (tax >= 0 && tax <= 15000) {

		totalTax = tax * 0.15;
	} else if (tax >= 15001 && tax <= 40000) {

		totalTax = 2250 + (tax - 15000) * 0.25;
	} else if (tax >= 40001) {

		totalTax = 8460 + (tax - 40000) * 0.35;
	}

	return totalTax;
}

