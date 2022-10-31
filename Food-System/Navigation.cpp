#include "Header.h"

void Menu_Start()
{
	int choice;

	cout << "Welcome to the restaurant system" << endl;
	cout << "Please choose the mode to access" << endl;
	cout << "1. Guest" << endl;
	cout << "2. Staff" << endl;
	cout << "3. Exit" << endl;

	while (true)
	{
		cout << "Please enter your choice : ";
		cin >> choice;
		if (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer. Please try again" << endl;
			continue;
		}
		else { break; }
	}

	switch (choice)
	{
	case 1:
		Guest_Interface();
		break;
	case 2:
		Staff_Interface();
		break;
	case 3:
		cout << "Thank you for using our program" << endl;
		break;
	default:
		break;
	}
}

void Staff_Interface()
{
	int choice;
	cout << "Choosing the mode of sessions" << endl;
	cout << "1. Login for Staffs" << endl;
	cout << "2. Login for Manager" << endl;
	cout << "3. Change the password" << endl;
	cout << "3. Change the password" << endl;
	cout << "4. Return" << endl;

	while (true)
	{
		cout << "Please enter your choice : ";
		cin >> choice;
		if (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid integer. Please try again" << endl;
			continue;
		}
		else { break; }
	}

	switch (choice)
	{
	case 1:
		Guest_Interface();
		break;
	case 2:
		Staff_Interface();
		break;
	case 3:
		cout << "Thank you for using our program" << endl;
		break;
	default:
		break;
	}
}

void Guest_Interface()
{

}
void Staff_Login()
{

}
void Manager_login()
{

}