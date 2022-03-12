// File Name: PasswordManager.cpp
//
// Authors: Callum Longenecker, Anand Valavalkar
// Date: 3/10/2022
// Assignment Number 2
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This cpp file contains the methods for encrypting
// a password and to check if a password meets criteria.
// These are private methods for a PasswordManager object.

#include <string>
#include "PasswordManager.h"
using namespace std;

//***********************************************************
// encrypt: encrypts a string and returns it
//
// in the string to be encrypted
// returns: the encrypted password
//***********************************************************
string PasswordManager::encrypt(string in)
{
    // the string that stores the resulting string
    string result = "";
    for (int i = 0; i < in.length(); i++)
    {
        // the encrypted char
        char encrypted = ((in[i] - 33) + 25) % 94 + 33;
        result += encrypted;
    }
    return result;
}

//***********************************************************
// meetsCriteria: Function to check if a string meets the requirements
// of a password
//
// toCheck the string to check
// returns: true if the password meets the requirements, false otherwise
//***********************************************************
bool PasswordManager::meetsCriteria(string toCheck)
{
    // stores if the upper case condition is met
    bool uppercaseLetter = false;
    // stores if the lower case condition is met
    bool lowercaseLetter = false;
    // stores if the digit condition is met
    bool hasDigit = false;
    // stores the length of the string to check
    int length = toCheck.length();

    // stores whether the string is valid
    bool notValid = true;

    if (length < 8)
    {
        return false;
    }

    // index to index into the string
    int i = 0;

    // stops iterating through string when valid
    while (i < length && notValid)
    {
        if (!uppercaseLetter)
        {
            if (isupper(toCheck[i]))
            {
                uppercaseLetter = true;
            }
        }

        if (!lowercaseLetter)
        {
            if (islower(toCheck[i]))
            {
                lowercaseLetter = true;
            }
        }

        if (!hasDigit)
        {
            if (isdigit(toCheck[i]))
            {
                hasDigit = true;
            }
        }

        if (uppercaseLetter && lowercaseLetter && hasDigit)
        {
            notValid = false;
        }
        i++;
    }

    return !notValid;
    return true;
}