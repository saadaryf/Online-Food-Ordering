#pragma once

#include"Include.h"
#include"Users.h"

class Rider:public Users
{

private:
	ofstream outRiderID;
	ifstream inRiderID;
	bool foundRider;
	int i;
public:
	Rider()
	{
		i = 0;
		foundRider = false;
		userName = new char[30];
		password = "";
		outRiderID.open("RiderLogins.txt", ios::app);
		inRiderID.open("RiderLogins.txt", ios::in);
	}
	void Login()
	{
		if (!inRiderID)
		{
			cout << "Can't OPEN File " << endl;
		}
		else
		{
			cout << "Enter your userName to Login: ";
			cin >> userName;
			cout << "Enter Password: ";
			char character;
			while (true)
			{
				character = _getch();
				if (character == '\r')
				{
					break;
				}
				password = password + character;
				cout << "*";
			}
			cout << endl;
			string userNamePassword = userName + password;
			while (!inRiderID.eof())
			{
				string temp = "";
				getline(inRiderID, temp);
				if (temp == userNamePassword)
				{
					foundRider = true;
					break;
				}
				else
				{
					continue;
				}

			}
	
		}

	}
	bool foundRiders()
	{
		if (foundRider)
			return true;
		else
			return false;
	}



	void Register()
	{

		if (!outRiderID)
		{
			cout << "Can't CREATE File " << endl;
		}
		else
		{
			cout << "Enter your userName to Sign Up: ";
			cin >> userName;
			if (strlen(userName) > 30)
			{
				cout << "-----Your userName is too Long----- " << endl;
			}
			else
			{

				cout << "Set Passeord: ";
				char character;
				while (true)
				{
					character = _getch();
					if (character == '\r')
					{
						break;
					}
					password = password + character;
					cout << "*";
				}
				cout << endl;
				
				outRiderID << userName;
				outRiderID << password << endl;


			}
		}
	}

	void viewOrder()
	{
		string temp[500];
		inOrderHistory.open("OrderHistory.txt", ios::app);
		while (!inOrderHistory.eof())
		{
			getline(inOrderHistory, temp[i]);
			i++;
		}
		cout << temp[i - 2];
		cout << endl;
		inOrderHistory.close();
	}

	void confirmOrder()
	{
		int choice = 0;
			cout << "Enter 1 if you have Delivered Order " << endl;
			cin >> choice;
			if (choice == 1)
			{
				cout << "Order Money are added to your Wallet" << endl;
				OrderMoney(totalPrice);
			}
			else
			{
				cout << "You Have Not delivered Order " << endl;
			}
		
	}



};