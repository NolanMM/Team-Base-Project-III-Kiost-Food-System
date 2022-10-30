

#include "Header.h"
#include "Class.h" 
/* This module will take responsibility for the Login session of the Staff
1. It allows staff to register a new account
2. It allows staff to change the password

***Note: All the Data will be store in the file and be encrypted*/

// Create and write to the file
int Contestant<Staff_Data>::input()
{

}

void Read_file()
{
// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile("filename.txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline(MyReadFile, myText)) {
	// Output the text from the file
	cout << myText;
}

// Close the file
MyReadFile.close();
}
