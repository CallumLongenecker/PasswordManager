// File Name: PasswordManager.h
//
// Authors: Callum Longenecker, Anand Valavalkar
// Date: 3/10/2022
// Assignment Number 2
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// This header file contains all the information about
// an instance of a PasswordManager object and what
// is public and private for it to contain.

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class PasswordManager
{
private:
    // stores the username for a PasswordManager object
    string username;
    // stores the password for a PasswordManager object
    string password;

    //***********************************************************
    // encrypt: encrypts a string and returns it
    //
    // in the string to be encrypted
    // returns: the encrypted password
    //***********************************************************
    string encrypt(string in);
    //***********************************************************
    // meetsCriteria: Function to check if a string meets the requirements
    // of a password
    //
    // toCheck the string to check
    // returns: true if the password meets the requirements, false otherwise
    //***********************************************************
    bool meetsCriteria(string toCheck);

public:
    //***********************************************************
    // setUsername: sets the username for a PasswordManager object
    //
    // user string to set the username to
    // returns: void
    //***********************************************************
    void setUsername(string user)
    {
        username = user;
    }
    //***********************************************************
    // getUsername: returns the username stored in a PasswordManager
    //              object
    //
    // returns: string equal to the username
    //***********************************************************
    string getUsername()
    {
        return username;
    }
    //***********************************************************
    // setEncryptedPassword: sets the password value for a
    //                       PasswordManager object.
    //
    // pass the string of an encrypted password
    // returns: void
    //***********************************************************
    void setEncryptedPassword(string pass)
    {
        password = pass;
    }
    //***********************************************************
    // getEncryptedPassword: returns the encrypted password stored in a
    //                      PasswordManager object
    //
    // returns: the encrypted password stored in a PasswordManager object
    //***********************************************************
    string getEncryptedPassword()
    {
        return password;
    }
    //***********************************************************
    // setNewPassword: sets a new password if it meets the criteria
    //
    // pass the unencrypted password to check if it is possible to set
    // returns: true if set was successful, false otherwise
    //***********************************************************
    bool setNewPassword(string pass)
    {
        if (meetsCriteria(pass))
        {
            setEncryptedPassword(encrypt(pass));
            return true;
        }
        return false;
    }
    //***********************************************************
    // authenticate: checks if an unencrypted password matches the
    //              currently stored password
    //
    // pass string to compare to the encrypted value
    // returns: true if the passwords are the same, false otherwise
    //***********************************************************
    bool authenticate(string pass)
    {
        return encrypt(pass) == password;
    }
};