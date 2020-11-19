#pragma once
#include "Subscription.h"
#include "Section.h"
#include <string>

using namespace std;

class Client : public Subscription, Section
{
public:
	string name;
	string surname;
	string patronymic;

private:
	int yearBirth;
	int monthBirth;
	int dayBirth;
	string section;
	
	void setDateBirth(int yearBirth, int monthBirth, int dayBirth) {
		try
		{
			if (yearBirth < 1950 || yearBirth > 2020 || monthBirth <= 0 || monthBirth > 12 || dayBirth <= 0 || dayBirth > 31)
				throw "invalid datebirth";
			this->yearBirth = yearBirth;
			this->monthBirth = monthBirth;
			this->dayBirth = dayBirth;
		}
		catch (...)
		{
			cout << "Error: invalid datebirth" << endl;
		}
	}

public:
	void EnterDateBirth() {
		int yearBirth, monthBirth, dayBirth;
		cout << "Enter the year of birth: "; cin >> yearBirth;
		cout << "Enter the month of birth: "; cin >> monthBirth;
		cout << "Enter the day of birth: "; cin >> dayBirth;
		setDateBirth(yearBirth, monthBirth, dayBirth);
	}
	void EnterDateBirth(int yearBirth, int monthBirth, int dayBirth) {
		setDateBirth(yearBirth, monthBirth, dayBirth);
	}
	
	int getYearBirth() {
		return yearBirth;
	}
	int getMonthBirth() {
		return monthBirth;
	}
	int getDayBirth() {
		return dayBirth;
	}

	void setSection() {
		ShowSection();
		int choice;
		cout << "Enter number section: "; cin >> choice;
		this->section = Section::setSection(choice);
	}

	void setSection(string section) {
		this->section = Section::setSection(section);
	}

	string getSection() {
		return section;
	}
};

