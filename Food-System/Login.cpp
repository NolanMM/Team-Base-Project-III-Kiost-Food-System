

#include "Header.h"

/* This module will take responsibility for the Login session of the Staff
1. It allows staff to register a new account
2. It allows staff to change the password

***Note: All the Data will be store in the file and be encrypted*/


// Create and write to the file
int Create_New_File() {
	// Create and open a text file
	ofstream MyFile("filename.txt");

	// Write to the file
	MyFile << "Files can be tricky, but it is fun enough!";

	// Close the file
	MyFile.close();
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