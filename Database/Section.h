#pragma once
#include <string>
#include <iostream>

using namespace std;

class Section
{
private:
	string gym = "Gym";
	string swimmingPool = "Swimming";
	string box = "Box";
	string stretching = "Stretching";
	string rockClimbing = "Climbing";

public:
	string setSection(int choice) {
		try
		{
			if (choice <= 0 || choice > 5)
				throw "invalid choice";
			switch (choice)
			{
			case 1:
				return gym;
				break;
			case 2:
				return swimmingPool;
				break;
			case 3:
				return box;
				break;
			case 4:
				return stretching;
				break;
			case 5:
				return rockClimbing;
				break;
			}
		}
		catch (...)
		{
			cout << "Error: invalid choice" << endl;
		}
	}

	string setSection(string section) {
		if (section == "Gym")
			return this->gym;
		else if (section == "Swimming")
			return this->swimmingPool;
		else if (section == "Box")
			return this->box;
		else if (section == "Stretching")
			return this->stretching;
		else if (section == "Climbing")
			return this->rockClimbing;
		else
			return "Error: section not found";
	}

	void ShowSection() {
		cout << "\n1. " << gym << endl
			 << "2. " << swimmingPool << endl
			 << "3. " << box << endl
			 << "4. " << stretching << endl
			 << "5. " << rockClimbing << endl;
	}
};

