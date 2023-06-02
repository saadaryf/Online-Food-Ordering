#pragma once

#include"Include.h"
#include"Wallet.h"


class Users : public Wallet
{
protected:
	string adress;
	long long int userContact;
	int totalPrice;
	int priceOfOrder;
	char* userName;
	string password;
	string userNamePassword;
	ofstream outUserContact;
	ifstream inUserContact;
	ofstream outUserID;
	ofstream outUserAdress;
	ifstream inUserAdress;
	ifstream inUserID;
	ifstream inMenu;
	bool foundUser;
	bool foundFood;
	string price;
	ofstream outOrderHistory;
	ifstream inOrderHistory;

public:
	Users()
	{
		adress = "";
		userContact = 0;
		totalPrice = 0;
		userNamePassword = "";
		priceOfOrder = 0;
		userName = new char[30];
		password = "";
		foundUser = false;
		foundFood = false;
		price = "";
	}



	void Login()
	{
		inUserID.open("UserLogins.txt", ios::in);
		if (!inUserID)
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
			userNamePassword = userName + password;
			while (!inUserID.eof())
			{
				string temp = "";
				getline(inUserID, temp);
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
		inUserID.close();
	}

	void setUserContact()
	{
		cout << "Enter Your Contact: ";
		cin >> userContact;
		outUserContact.open("UserContacts.txt", ios::out);
		if (!outUserContact)
		{
			cout << "Can't CREAT File" << endl;
		}
		else
		{
			outUserContact << userContact << endl;
		}
		outOrderHistory.close();
	}

	void getUserContact()
	{
		inUserContact.open("UserContacts.txt", ios::in);
		if (!inUserContact)
		{
			cout << "User Wants ContactLess Delivery " << endl;
		}
		else
		{
			string temp;
			getline(inUserContact, temp);
			cout << "Contact No: " << temp;
		}
		inUserContact.close();
	}

	void setUserAdress()
	{
		cout << "Enter Your Adress and put _ in place of spaces: ";
		cin >> adress;
		outUserAdress.open("UserAdress.txt", ios::out);
		if (!outUserAdress)
		{
			cout << "Can't CREAT File " << endl;
		}
		else
		{
			outUserAdress << adress << endl;
		}
		outUserAdress.close();
	}

	void getUserAdress()
	{
		inUserAdress.open("UserAdress.txt", ios::out);
		if (!inUserAdress)
		{
			cout << "Can't OPEN File " << endl;
		}
		else
		{
			string temp;
			getline(inUserAdress, temp);
			cout << "\nUser Adress: " << temp << endl;
		}
	}
	void Register()
	{
		outUserID.open("UserLogins.txt", ios::app);
		if (!outUserID)
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

			
				outUserID << userName;
				outUserID << password << endl;


			}
		}
		outUserID.close();
	}


	bool foundUsers()
	{
		if (foundUser)
			return true;
		else
			return false;
	}



	void DisplayFood()
	{
		inMenu.open("Menu.txt", ios::in);
		if (!inMenu)
		{
			cout << "Can't open MENU" << endl;
		}
		else
		{
			cout << "\n\t\t--> Displaying Food <-- " << endl;
			while (!inMenu.eof())
			{
				string food;
				string price;
				getline(inMenu, food);
				getline(inMenu, price);
				cout << "\n\t\t--> "<<food << " = " << price << endl;
			}
			inMenu.close();
		}
		while (true)
		{
			int choice;
			cout << "\n\n\t\t\t\t\t\t>>ENTER CHOICE<<  \n\n\t1 -->  Select Food\n\t2 -->  Payment/Exit" << endl;
			cin >> choice;
			if (choice == 1)
			{
				SelectFood();
			}
			else if (choice == 2)
			{
				cout << "Your Total Price is " << totalPrice << endl;
				Payment();
				break;
			}
		}
	}


	void SelectFood()
	{
		inMenu.open("Menu.txt", ios::in);
		if (!inMenu)
		{
			cout << "Can't open Menu" << endl;
		}
		else
		{
			string food;
			cout << "Enter Food Name from Menu to Order: ";
			cin >> food;
			cout << "You Selected: " << food << endl;
			while (!inMenu.eof())
			{
				string temp;
				getline(inMenu, temp);
				if (food == temp)
				{
					getline(inMenu, price);
					priceOfOrder = stoi(price);
					foundFood = true;
					break;
				}
			}
			if (foundFood)
			{
				totalPrice += priceOfOrder;
				cout << "Your Order is Placed of " << food << " for " << priceOfOrder << endl;
				outOrderHistory.open("OrderHistory.txt", ios::app);
				outOrderHistory << "Orderd " << food <<" by " <<userName<< " for " << priceOfOrder << endl;
				outOrderHistory.close();
			}
			else
			{
				cout << "Your Order is Not Available in Menu " << endl;
			}
		}
		inMenu.close();

	}
	void Payment()
	{
		int choice = 0;
		cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  App Wallet\n\t2 -->  Cash on Delivery " << endl;
		cin >> choice;
		if (choice == 1)
		{
			if (totalPrice > moneyAvailable)
			{
				cout << "You Have less Available Balance " << endl;
				cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Add Money" << endl;
				cin >> choice;
				if (choice == 1)
				{
					addMoney();
				}
		
			}
			else if (totalPrice < moneyAvailable)
			{
				cout << "Avialable Balance: " << moneyAvailable;
				PayOrder(totalPrice);
				cout << "\nTransaction in Process.";
				Sleep(500);
				cout << ".";
				Sleep(400);
				cout << ".";
				Sleep(300);
				cout << ".";
				Sleep(200);
				cout << ".";
				cout << "\n<--Transaction Successful-->" << endl;
			}
		}
		else if (choice == 2)
		{
			cout << "Money Given: ";
			cin >> money;
			if (money > priceOfOrder)
			{
				cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Take Change\n\t2 -->  Add Change to Wallet " << endl;
				cin >> choice;
				if (choice == 1)
				{
					cout << "Here is Your Change: " << money - priceOfOrder;
				}
				else if (choice == 2)
				{
					OrderMoney(money - priceOfOrder);
				}
			}
			else if (money < priceOfOrder)
			{
				cout << "Remaining Money Will be Deducted From Your Wallet" << endl;
				addMoney();
			}
		}
	}

	void DeleteAccount()
	{
		cout << "Deleting Account";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		inUserID.open("UserLogins.txt", ios::in);
		if (!inUserID)
		{
			cout << "Can't OPEN File " << endl;
		}
		else
		{
			string temp;
			ofstream fout;
			fout.open("Temp.txt", ios::app);
			if (!fout)
			{
				cout << "Can't CREATE Temp File " << endl;
			}
			else
			{
				while (!inUserID.eof())
				{
					getline(inUserID, temp);
					if (temp == userNamePassword)
					{
						continue;
					}
					else
					{
						fout << temp << endl;
					}

				}
			}
			fout.close();
		}
		inUserID.close();
		remove("UserLogins.txt");
		rename("Temp.txt", "UserLogins.txt");
		cout << "\nAccount Successfully Deleted " << endl;
	}


	void UpdateAccount()
	{
		cout << "Enter userName: ";
		cin >> userName;
		cout << "Enter Password: ";
		cin >> password;

		cout << "Updating Account";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		Sleep(300);
		cout << ".";
		inUserID.open("UserLogins.txt", ios::in);
		if (!inUserID)
		{
			cout << "Can't OPEN File " << endl;
		}
		else
		{
			string temp;
			ofstream fout;
			fout.open("Temp.txt", ios::app);
			if (!fout)
			{
				cout << "Can't CREATE Temp File " << endl;
			}
			else
			{
				while (!inUserID.eof())
				{
					getline(inUserID, temp);
					if (temp == userNamePassword)
					{
						fout << userName << password << endl;
					}
					else
					{
						fout << temp << endl;
					}

				}
			}
			fout.close();
		}
		inUserID.close();
		remove("UserLogins.txt");
		rename("Temp.txt", "UserLogins.txt");
		cout << "\nAccount Successfully Updated " << endl;

	}

	void getOrderHistory()
	{
		string t1, t2, t3, t4, t5, t6;
		inOrderHistory.open("OrderHistory.txt", ios::app);
		cout << "Your Order History is " << endl;
		while (!inOrderHistory.eof())
		{
			inOrderHistory >> t1;
			inOrderHistory >> t2;
			inOrderHistory >> t3;
			inOrderHistory >> t4;
			inOrderHistory >> t5;
			inOrderHistory >> t6;

			if (t4 == userName)
			{
				cout << t1 << " " << t2 << " " << t3 << " " << " You " << " " << t5 << " " << t6 << endl;
			}
		}
		inOrderHistory.close();
	}

	~Users()
	{
		 outUserID.close();
		 inUserID.close();
	}

};