#pragma once

#include"Include.h"

class Wallet
{
protected:
	int money;
	int moneyAvailable;
	long long int cardNo;
public:
	Wallet()
	{
		money = 0;
		cardNo = 0;
		moneyAvailable = 3000;
	}
	void OrderMoney(int money)
	{
		moneyAvailable += money;
	}
	void addMoney()
	{
		cout << "Enter your Card No: ";
		cin >> cardNo;
		cout << "Enter the ammount of Money ";
		cin >> money;
		moneyAvailable += money;
	}

	void PayOrder(int price)
	{
		moneyAvailable -= price;
	}

	int getAwailableBalance()
	{
		return moneyAvailable;
	}
	
};
