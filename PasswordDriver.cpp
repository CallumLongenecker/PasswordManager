// File Name: PasswordDriver.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar
// Date: 3/10/2022
// Assignment Number 2
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file is the program that drives the
// project program.

#include "PasswordManager.h"
const int SIZE = 3; // size of the array of PasswordManagers

//***********************************************************
// inputNew: Accepts input for a new password for a user and checks
// if it is a valid user and password combination and new password
//
// pmArray a pointer to an array of PasswordManagers
// returns: true if the input values are valid and the password was set.
// false otherwise.
//***********************************************************
bool inputNew(PasswordManager **pmArray)
{
   cout << "Please enter your username: ";
   string user; // The string to read in the username
   cin >> user;
   cout << "Please enter your old password: ";
   string oldPass; // The string to read in the old password
   cin >> oldPass;
   cout << "Please enter your new password: ";
   string newPass; // The string to read in the new password
   cin >> newPass;
   int i = -1;         // The int to keep track of whick entry to update
   bool found = false; // boolean to keep track of if the username is found
   while (i < SIZE && !found)
   {
      i++;
      found = (*pmArray + i)->getUsername() == user;
   }
   if (!found)
   {
      cout << "Username is invalid, password not changed." << endl;
      return false;
   }
   if (!(*pmArray + i)->authenticate(oldPass))
   {
      cout << "Old password is incorrect." << endl;
      return false;
   }
   if ((*pmArray + i)->setNewPassword(newPass))
   {
      cout << "Password has been changed for username: " << user << endl;
      return true;
   }
   else
   {
      cout << "New password does not meet criteria." << endl;
      return false;
   }
}

//***********************************************************
// main: the main function of the driver
//
// returns: int code to tell the system if a failure occurred
//***********************************************************
int main()
{
   // allows user to change their password

   ifstream infile; // the input stream from the file
   infile.open("passwords.txt");

   // an array of PasswordManagers
   PasswordManager *pmArray = new PasswordManager[SIZE];

   if (infile.good())
   {
      for (int i = 0; i < SIZE; i++)
      {
         // the username to be read in
         string user;
         // the password to be read in
         string password;
         infile >> user;
         infile >> password;
         (pmArray + i)->setUsername(user);
         (pmArray + i)->setEncryptedPassword(password);
      }
   }
   else
   {
      cout << "Input file does not exist." << endl;
      return 0;
   }
   infile.close();
   cout << "Password criteria:" << endl
        << "- it is at least 8 characters long"
        << endl
        << "- it contains at least one uppercase letter" << endl
        << "- it has one lowercase letter" << endl
        << "- it has one digit" << endl;
   while (inputNew(&pmArray));
   // the output file stream to write the password data to
   ofstream outfile;
   outfile.open("passwords.txt");
   for (int i = 0; i < SIZE; i++)
   {
      outfile << (pmArray + i)->getUsername() << " "
              << (pmArray + i)->getEncryptedPassword() << endl;
   }
   return 0;
}
