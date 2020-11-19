#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Client.h"

using namespace std;

class Database
{
private:
	bool newDatabase = true;
	bool autosave = false;
	int countElementDatabase = 0;
	string str, tempstr, number, name, surname, patronymic, yearBirth, monthBirth, dayBirth,
		   yearActivate, monthActivate, dayActivate, yearEnding, monthEnding, dayEnding, section, empty;

	void setAutosave(bool autosave) {
		this->autosave = autosave;
	}

public:
	vector <Client> database;
	
	void CreateDatabase() {
		if (newDatabase) {
			int size;
			cout << "Enter the size of the database: "; cin >> size;
			database.resize(size);
			newDatabase = false;
		}
		else {
			cout << "Error: database was created earlier" << endl;
		}
	}
	
	void AddClient() {
		if (newDatabase) {
			CreateDatabase();
		}
		cout << "\nEnter client information N " << countElementDatabase + 1 << endl;
		cout << "Name: "; cin >> database[countElementDatabase].name;
		cout << "Surname: "; cin >> database[countElementDatabase].surname;
		cout << "Patronymic: "; cin >> database[countElementDatabase].patronymic;
		cout << "Date birth:" << endl; database[countElementDatabase].EnterDateBirth();
		cout << "Date activate subscription:" << endl; database[countElementDatabase].EnterDateActivation();
		cout << "Date ending subscription:" << endl; database[countElementDatabase].EnterDateEnding();
		cout << "Section: "; database[countElementDatabase].Client::setSection();
		countElementDatabase++;
	}

	void ShowDatabase() {
		for (int i = 0; i < countElementDatabase; i++) {
			cout << "\nName:\t\t\t\t" << database[i].name << endl
				 << "Surname:\t\t\t" << database[i].surname << endl
				 << "Patronymic:\t\t\t" << database[i].patronymic << endl
				 << "Date birth:\t\t\t" << database[i].getYearBirth() << "." << database[i].getMonthBirth() << "." << database[i].getDayBirth() << endl
				 << "Date activate subscription:\t" << database[i].getYearActivation() << "." << database[i].getMonthActivation() << "." << database[i].getDayActivation() << endl
				 << "Date ending subscription:\t" << database[i].getYearEnding() << "." << database[i].getMonthEnding() << "." << database[i].getDayEnding() << endl
				 << "Section:\t\t\t" << database[i].getSection() << endl;
		}
	}

	void ExportDatebase() {
		ofstream importDatabase;
		string path;
		if (autosave) {
			path = "autosave.txt";
		}
		else {
			cout << "Enter the database import path: "; cin >> path;
		}
		importDatabase.open(path);
		if (importDatabase.is_open()) {
			for (int i = 0; i < countElementDatabase; i++) {
				
				number = to_string(i+1);

				yearBirth = to_string(database[i].getYearBirth());
				monthBirth = to_string(database[i].getMonthBirth());
				dayBirth = to_string(database[i].getDayBirth());
				
				yearActivate = to_string(database[i].getYearActivation());
				monthActivate = to_string(database[i].getMonthActivation());
				dayActivate = to_string(database[i].getDayActivation());
				
				yearEnding = to_string(database[i].getYearEnding());
				monthEnding = to_string(database[i].getMonthEnding());
				dayEnding = to_string(database[i].getDayEnding());
				
				tempstr = number + ";" + database[i].name + ";" + database[i].surname + ";" 
						+ database[i].patronymic + ";" + yearBirth + ';' + monthBirth + ';' + dayBirth + ";" 
						+ yearActivate + ';' + monthActivate + ';' + dayActivate + ";" 
						+ yearEnding + ';' + monthEnding + ';' + dayEnding + ";" 
						+ database[i].getSection();

				importDatabase << tempstr + ";" << endl;
			}
			importDatabase.close();
		}
		else {
			cout << "Error: file not found" << endl;
		}
	}
	
	string ImportDatabase() {
		fstream exportDatabase;
		string path;
		cout << "Enter the database export path: "; cin >> path;
		exportDatabase.open(path);
		if (exportDatabase.is_open()) {
			string total, temp;
			while (!exportDatabase.eof()) {
				exportDatabase >> temp;
				total += temp + ";";
			}
			return total;
			exportDatabase.close();
		}
		else {
			return "Error: file not found";
		}
	}

	void AssigningData() {
		database.resize(100);
		str = ImportDatabase();
		countElementDatabase = -1;
		for (int i = 0; i < str.length(); i++) {

			tempstr = str.substr(str.find(';', 0) + 1);
			number = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			database[i].name = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			database[i].surname = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			database[i].patronymic = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			yearBirth = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			monthBirth = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			dayBirth = str.erase(str.find(';', 0));
			str = tempstr;

			database[i].EnterDateBirth(atoi(yearBirth.c_str()), atoi(monthBirth.c_str()), atoi(dayBirth.c_str()));

			tempstr = str.substr(str.find(';', 0) + 1);
			yearActivate = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			monthActivate = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			dayActivate = str.erase(str.find(';', 0));
			str = tempstr;

			database[i].EnterDateActivation(atoi(yearActivate.c_str()), atoi(monthActivate.c_str()), atoi(dayActivate.c_str()));

			tempstr = str.substr(str.find(';', 0) + 1);
			yearEnding = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			monthEnding = str.erase(str.find(';', 0));
			str = tempstr;

			tempstr = str.substr(str.find(';', 0) + 1);
			dayEnding = str.erase(str.find(';', 0));
			str = tempstr;

			database[i].EnterDateEnding(atoi(yearEnding.c_str()), atoi(monthEnding.c_str()), atoi(dayEnding.c_str()));

			tempstr = str.substr(str.find(';', 0) + 1);
			section = str.erase(str.find(';', 0));
			str = tempstr;

			database[i].Client::setSection(section);

			tempstr = str.substr(str.find(';', 0) + 1);
			empty = str.erase(str.find(';', 0));
			str = tempstr;

			countElementDatabase++;
		}
	}

	void DeleteDatabase() {
		string path;
		cout << "Enter the path to the database to delete: "; cin >> path;
		const char *charPath = path.c_str();
		remove(charPath);
	}
	
	bool getAutosave() {
		return autosave;
	}

	void SwitchAutosave() {
		char choice;
		if (autosave) {
			cout << "Autosave enable" << endl;
			cout << "Disable? (y/n)" << endl;
			cin >> choice;
			if (choice == 'y') {
				setAutosave(0);
			}
		}
		else {
			cout << "Autosave disable" << endl;
			cout << "Enable? (y/n)" << endl;
			cin >> choice;
			if (choice == 'y') {
				setAutosave(1);
			}
		}	
	}
};