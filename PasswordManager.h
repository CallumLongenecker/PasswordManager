#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class PasswordManager
{
private:
    string username;
    string password;
    string encrypt(string in);
    bool meetsCriteria(string toCheck);
public:
    void setUsername(string user) {
        username = user;
    }
    string getUsername() {
        return username;
    }
    void setEncryptedPassword(string pass) {
        password = pass;
    }
    string getEncryptedPassword() {
        return password;
    }
    bool setNewPassword(string pass) {
        if (meetsCriteria(pass)) {
            setEncryptedPassword(encrypt(pass));
            return true;
        } 
        return false;
    }
    bool authenticate(string pass) {
        return encrypt(pass) == password;    
    }
};