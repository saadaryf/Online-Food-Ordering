#pragma once

#include"Include.h"
class Cart
{
private:
	ofstream outMenu;
	ifstream inMenu2;
	ofstream fout2;
	string food;
	int price;
public:
	Cart()
	{
		food = "";
		price = 0;
	}
	void setFoodandPrice(string food,int price)
	{
		outMenu.open("Menu.txt", ios::app);
		this->food = food;
		this->price = price;
		cout << food << endl;
		cout << price << endl;
		outMenu << food << endl;
		outMenu << price << endl;
		outMenu.close();
	}
	void deleteFood()
	{
		inMenu2.open("Menu.txt", ios::in);
		if (!inMenu2)
		{
			cout << "Can't open File" << endl;
		}
		else
		{
			cout << "\n\t\t--> Displaying Food <-- " << endl;
			while (!inMenu2.eof())
			{
				string food;
				string price;
				getline(inMenu2, food);
				getline(inMenu2, price);
				cout << "\n\t\t--> " << food << " = " << price << endl;
			}
			inMenu2.close();
			string food;
			cout << "Enter the food Name you want to delete: ";
			cin >> food;
			string temp;
			fout2.open("Temp2.txt", ios::app);
			if (!fout2)
			{
				cout << "Can't CREATE Temp2 File " << endl;
			}
			else
			{
				inMenu2.open("Menu.txt", ios::in);
				while (!inMenu2.eof())
				{
					getline(inMenu2, temp);
					if (temp == food)
					{
						getline(inMenu2, temp);
						continue;
					}
					else
					{
						fout2 << temp << endl;
					}

				}
				inMenu2.close();
			}
			fout2.close();
		}
	//	inMenu2.close();
		remove("Menu.txt");
		rename("Temp2.txt", "Menu.txt");
		cout << "Food Successfully Deleted " << endl;
	}


};