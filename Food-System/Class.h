#include "Header.h"

static class Staff_Data
{
	// Set the private Variables
private:
	string _username;
	char _password[16];
	string _role;
	float Dollar_per_Hour;
	float Hour;
	float Total_salary;
public:
	void set_role(string role)
	{
		_role = role;
	}
	string get_role()
	{
		return _role;
	}
	void set_username(string temp)
	{
		_username = temp;						// Set private variable
	}
	string get_username()
	{
		return _username;						// Access private variable
	}
	void set_password(char arr[])
	{
		copy(arr, arr + sizeof(arr), _password); // copy(arr1, pointer-to-just-past-arr1, arr2); // set the password into char array ( private variable)
	}
	string get_password()
	{
		return _password;
	}
	void set_dollar_hour(float dollar)
	{
		Dollar_per_Hour = dollar;
	}
	float get_dollar_hour()
	{
		return Dollar_per_Hour;
	}
	void set_hour(float hour)
	{
		Hour = hour;
	}
	float get_hour()
	{
		return Hour;
	}
	float get_total_salary()
	{
		return Dollar_per_Hour * Hour;					// Return the total money staff will receive
	}
	int Write_The_File();
	int Read_The_File();
};

#pragma once
