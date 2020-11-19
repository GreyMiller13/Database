#pragma once
#include <iostream>

using namespace std;

class Subscription
{
private:
	int yearActivation;
	int monthActivation;
	int dayActivation;
	int yearEnding;
	int monthEnding;
	int dayEnding;

	void setDateActivation(int year, int month, int day) {
		try
		{
			if (year < 2020 || year > 2021 || month <= 0 || month > 12 || day <= 0 || day > 31)
				throw "wrong activation date";
			this->yearActivation = year;
			this->monthActivation = month;
			this->dayActivation = day;
		}
		catch (...)
		{
			cout << "Error: wrong activation date" << endl;
		}
	}

	void setDateEnding(int year, int month, int day) {
		try
		{
			if (year < yearActivation || year > 2022 || month <= 0 || month > 12 || day <= 0 || day > 31)
				throw "wrong ending date";
			this->yearEnding = year;
			this->monthEnding = month;
			this->dayEnding = day;
		}
		catch (...)
		{
			cout << "Error: wrong ending date" << endl;
		}
	}
public:
	
	void EnterDateActivation() {
		int year, month, day;
		cout << "Enter the year of subscription activation: "; cin >> year;
		cout << "Enter the month of subscription activation: "; cin >> month;
		cout << "Enter the day of subscription activation: "; cin >> day;
		setDateActivation(year, month, day);
	}
	void EnterDateActivation(int year, int month, int day) {
		setDateActivation(year, month, day);
	}

	int getYearActivation() {
		return yearActivation;
	}
	int getMonthActivation() {
		return monthActivation;
	}
	int getDayActivation() {
		return dayActivation;
	}

	void EnterDateEnding() {
		int year, month, day;
		cout << "Enter the year of subscription ending: "; cin >> year;
		cout << "Enter the month of subscription ending: "; cin >> month;
		cout << "Enter the day of subscription ending: "; cin >> day;
		setDateEnding(year, month, day);
	}
	void EnterDateEnding(int year, int month, int day) {
		setDateEnding(year, month, day);
	}

	int getYearEnding() {
		return yearEnding;
	}
	int getMonthEnding() {
		return monthEnding;
	}
	int getDayEnding() {
		return dayEnding;
	}
};

