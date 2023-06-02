#pragma once

#include"Include.h"
#include"Users.h"

class Manager:public Users
{
private:
	ofstream outManager;
	ifstream inManager;
	bool foundUser = false;
public:
	Manager()
	{
		userName = new char[30];
		password = "";
		outManager.open("ManagerLogin.txt", ios::app);
		inManager.open("ManagerLogin.txt", ios::in);
	}
	void Login()
	{
		outManager << "SaadArif889988" << endl;
		if (!inManager||!outManager)
		{
			cout << "Can't OPEN or CREAT File " << endl;
		}
		else
		{
			cout << "Enter your userName to Login: ";
			cin >> userName;
			cout << "Enter Password: ";
			cin >> password;
			string userNamePassword = userName + password;
			while (!inManager.eof())
			{
				string temp = "";
				getline(inManager, temp);
				if (temp == userNamePassword)
				{
					foundUser = true;
					break;
				}
				else
				{
					continue;
				}

			}

		}
	}
	bool foundManager()
	{
		if (foundUser)
			return true;
		else
			return false;
	}
	void showTotalHistory()
	{
		string temp;
		inOrderHistory.open("OrderHistory.txt", ios::app);
		cout << "Displaying All Orders" << endl;
		while (!inOrderHistory.eof())
		{
			getline(inOrderHistory, temp);
			cout << temp << endl;
		}
		inOrderHistory.close();
	}

	void showSpecificHistory()
	{
		string name;
		cout << "Enter The Name Of User You Want to see History Of: ";
		cin >> name;
		string t1, t2, t3, t4, t5, t6;
		inOrderHistory.open("OrderHistory.txt", ios::app);
		cout << "Your Order History is " << endl;
		bool flag = false;
		while (!inOrderHistory.eof())
		{
			inOrderHistory >> t1;
			inOrderHistory >> t2;
			inOrderHistory >> t3;
			inOrderHistory >> t4;
			inOrderHistory >> t5;
			inOrderHistory >> t6;

			if (t4 == name)
			{
				cout << t1 << " " << t2 << " " << t3 << " " << name << " " << t5 << " " << t6 << endl;
				flag = true;
			}
		}
		if (!flag)
		{
			cout << "This User Have no Order History" << endl;
		}
		inOrderHistory.close();
	}
	void BlockAccount()
	{
		cout << "Enter user Name: ";
		cin >> userName;
		cout << "Enter user Pass: ";
		cin >> password;
		userNamePassword = userName + password;
		DeleteAccount();
	}


};