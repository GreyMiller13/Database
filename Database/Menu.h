#pragma once
#include <iostream>
#include "Database.h"
#include "Client.h"

using namespace std;

class Menu : public Database
{
private:
	void ShowMenu() {
		cout << "=====================================" << endl
			 << "= 1. Create a new database          =" << endl
			 << "= 2. Add new client to the database =" << endl
			 << "= 3. Export database to file        =" << endl
			 << "= 4. Import database from file      =" << endl
			 << "= 5. Delete database                =" << endl
			 << "= 6. Show database                  =" << endl
			 << "= 7. Autosave enable / disable      =" << endl
			 << "= 8. Exit the program               =" << endl
			 << "=====================================" << endl;
	}
	
	void InterfaceChoice(int choice) {
		
		switch (choice)
		{
		case 1:
			menu.CreateDatabase();
			break;
		case 2:
			menu.AddClient();
			break;
		case 3:
			menu.ExportDatebase();
			break;
		case 4:
			menu.AssigningData();
			break;
		case 5:
			menu.DeleteDatabase();
			break;
		case 6:
			menu.ShowDatabase();
			break;
		case 7:
			menu.SwitchAutosave();
			break;
		case 8:
			cout << "You exit the program." << endl;
			if (getAutosave()) {
				cout << "All data has been automatically saved." << endl;
				menu.ExportDatebase();
			}
			break;
		}
	}

public:
	void Interface() {
		int choice;
		do
		{
			ShowMenu();
			cout << "Enter the operation number: "; cin >> choice;
			try
			{
				if (choice < 1 || choice > 8)
					throw "invalid choice";
				InterfaceChoice(choice);
				system("pause");
				system("cls");
			}
			catch (...)
			{
				cout << "Error: invalid choice" << endl;
			}
		} while (choice != 8);
	}
}menu;

