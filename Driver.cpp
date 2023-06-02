

#include"Headers.h"



int main()
{ 
	system("color 0B");
	while (true)
	{
		int choice = 0;
		cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  User\n\t2 -->  Rider\n\t3 -->  Manager\n\t4 -->  Exit " << endl;
		cin >> choice;
		if (choice == 1)														   // for user
		{
			Users u1;
			while (true)
			{
				cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Login\n\t2 -->  Register\n\t3 -->  Exit" << endl;
				cin >> choice;
				if (choice == 1)
				{
					u1.Login();
					break;
				}
				else if (choice == 2)
				{
					u1.Register();
				}
				else if (choice == 3)
				{
					break;
				}
				else
					cout<<"Enter Right Choice: "<<endl;
			}

			if (u1.foundUsers())
			{
				cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Share Contact\n\t2 -->  ContactLess Delivery" << endl;
				cin >> choice;
				if (choice == 1)
				{
					u1.setUserContact();
				}
				else if (choice == 2)
				{
					remove("UserContacts.txt");
				}
				else
				{
					cout << "Wrong Choice, Your Contact will not be Shared "<<endl;
					remove("UserContacts.txt");
				}
				u1.setUserAdress();
				while (true)
				{
					cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<<  \n\n\t1 -->  Display Food\n\t2 -->  Delete Account\n\t3 -->  Update Account\n\t4 -->  Order History\n\t5 -->  Exit " << endl;

					cin >> choice;
					if (choice == 1)
					{
						u1.DisplayFood();
					}
					else if (choice == 2)
					{
						u1.DeleteAccount();
					}
					else if (choice == 3)
					{
						u1.UpdateAccount();
					}
					else if (choice == 4)
					{
						u1.getOrderHistory();
					}
					else if (choice == 5)
					{
						break;
					}
					else
						cout << "Enter Right Choice" << endl;
				}
			}
			else
			{
				while (true)
				{
					cout << "Wrong Login " << endl;
					cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<<  \n\n\t1 -->  Try Again\n\t2 -->  Exit" << endl;
					cin >> choice;
					if (choice == 1)
					{
						u1.Login();
						if (u1.foundUsers())
						{
							while (true)
							{
								cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<<  \n\n\t1 -->  Display Food\n\t2 -->  Delete Account\n\t3 -->  Update Account\n\t4 -->  Order History\n\t5 -->  Exit " << endl;

								cin >> choice;
								if (choice == 1)
								{
									u1.DisplayFood();
								}
								else if (choice == 2)
								{
									u1.DeleteAccount();
								}
								else if (choice == 3)
								{
									u1.UpdateAccount();
								}
								else if (choice == 4)
								{
									u1.getOrderHistory();
								}
								else if (choice == 5)
								{
									break;
								}
								else
									cout << "Enter Right Choice" << endl;
							}
						}
					}
					else if (choice == 2)
					{
						break;
					}
					else
						cout << "Enter Right Choice" << endl;
				}
			}

		}
		else if (choice == 2)														 // for rider
		{
			Rider r1;
			while (true)
			{
				cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Login\n\t2 -->  Register" << endl;
				cin >> choice;
				if (choice == 1)
				{
					r1.Login();
				}
				else if (choice == 2)
				{
					r1.Register();
				}
				if (r1.foundRiders())
				{
					cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  View Order\n\t2 -->  Confirm Order\n\t3 -->  Cancle Order" << endl;
					cin >> choice;
					if (choice == 1)
					{
						r1.viewOrder();
						r1.getUserAdress();
						r1.getUserContact();
						cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Confirm Order\n\t2 -->  Cancle Order" << endl;
						cin >> choice;
						if (choice == 1)
						{
							r1.confirmOrder();
						}
						else if (choice == 2)
						{
							cout << "Order Cancelled" << endl;
							break;
						}
						break;
					}
					else if (choice == 2)
					{
						r1.getUserContact();
						r1.getUserAdress();
						r1.confirmOrder();
					}
					else if (choice == 3)
						break;
				}
				else 
				{
					cout << "Wrong Login" << endl;
				}
			}
		}
		else if (choice == 3)														// for manager
		{
			Manager m1;
			Cart c1;
			m1.Login();
			string food;
			int price;

				if (m1.foundManager())
				{
					cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 -->  Add Food to Menu\n\t2 -->  Block User \n\t3 -->  View Order History\n\t4 -->  Delete Food\n\t5 -->  Delect Previous Orders History\n\t6 -->  Exit" << endl;
					cin >> choice;
					if (choice == 1)
					{
						int size = 0, i = 0;
						cout << "How many Foods you want to add: ";
						cin >> size;
						while (i<size)
						{
							cout << "Set Available Food: ";
							cin >> food;
							cout << "Set price of " << food << ": ";
							cin >> price;
							c1.setFoodandPrice(food, price);
							i++;
						}
					}
					else if (choice == 2)
					{
						m1.BlockAccount();
					}
					else if (choice == 3)
					{
						cout << "\n\t\t\t\t\t\t>>ENTER CHOICE<< \n\n\t1 --> View All History\n\t2 --> View Specific User History " << endl;
						cin >> choice;
						if (choice == 1)
						{
							m1.showTotalHistory();
						}
						else if (choice == 2)
						{
							m1.showSpecificHistory();
						}
						else
						{
							cout << "Wrong Choice" << endl;
						}
					}
					else if (choice ==4)
					{
						c1.deleteFood();
					}
					else if (choice == 5)
					{
						cout << "History Deleted Permanented " << endl;
						remove("OrderHistory.txt");
					}
					else if (choice == 6)
						break;
					else
						cout << "Enter Right Choice";
				}
				else
				{
					cout << "Wrong Login " << endl;
					break;
				}
			
		}
		else if (choice == 4)
		{
			break;
		}
		else
		{
			cout << "Enter Right Choice " << endl;
		}


	}


	remove("ManagerLogin.txt");
	remove("UserContacts.txt");
	remove("UserAdress.txt");
	cout << "\n\n--> See You Next Time <--\n\n";
	return 0;

}

