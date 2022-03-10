// File Name: project1_ASV724_crl3235.cpp
//
// Authors: Anand Valavalkar, Callum Longenecker
// Date: 1/23/2022
// Assignment Number 1
// CS 105C Spring 2022
// Instructor: Dr. Palacios
//
// C++ Program that TODO:

#include <string>
#include "PasswordManager.h"
using namespace std;

string PasswordManager::encrypt(string in) {
    string result = "";
    for (int i = 0; i < in.length(); i++) {
        char encrypted =  ((in[i] - 33) + 25) % 94 + 33; 
        result += encrypted;
    }
    return result;
}

bool PasswordManager::meetsCriteria(string toCheck){
    bool uppercaseLetter = false;
    bool lowercaseLetter = false;
    bool hasDigit = false;
    int length = toCheck.length();

    bool notValid = true; 
       
    if(length < 8){
        return false;
    }

    int i = 0;
    while(i < length && notValid){
        if(!uppercaseLetter){
            if(isupper(toCheck[i])){
               uppercaseLetter = true;
            }
        }

        if(!lowercaseLetter){
            if(islower(toCheck[i])){
               lowercaseLetter = true;
            }
        }
          
        if(!hasDigit){
            if(isdigit(toCheck[i])){
               hasDigit = true;
            }
        }

        if(uppercaseLetter && lowercaseLetter && hasDigit){
            notValid = false;
        }
        i++;
    }

    return !notValid;  
    return true;
}