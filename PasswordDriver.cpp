#include "PasswordManager.h"

bool inputNew(PasswordManager **pmArray)
{
   cout << "Please enter your username: ";
   string user;
   cin >> user;
   cout << "Please enter your old password: ";
   string oldPass;
   cin >> oldPass;
   cout << "Please enter your new password: ";
   string newPass;
   cin >> newPass;
   int i = -1;
   bool found = false;
   while (i < 3 && !found)
   {
      i++;
      found = (*pmArray + i)->getUsername() == user;
      
   }
   if (!found)
   {
      cout << "Username is invalid, password not changed." << endl;
      return false;
   }
   string encrypted = (*pmArray + i)->getEncryptedPassword();
   string oldEncrypted = "";
   for (int i = 0; i < oldPass.length(); i++)
   {
      char encrypt = ((oldPass[i] - 33) + 25) % 94 + 33;
      oldEncrypted += encrypt;
   }
   bool oldPassMatch = true;
   if (oldEncrypted.length() != encrypted.length())
   {
      oldPassMatch = false;
   }
   else
   {
      int j = 0;
      while (j < encrypted.length() && oldPassMatch)
      {
         oldPassMatch = encrypted[j] == oldEncrypted[j];
         j++;
      }
   }
   if (!oldPassMatch)
   {
      cout << "Old password is incorrect." << endl;
      return false;
   }
   if ((*pmArray + i)->setNewPassword(newPass)) {
      cout << "Password has been changed for username: " << user << endl;
      return true;
   } else {
      cout << "New password does not meet criteria." << endl;
      return false;
   }

}

int main()
{
   // allows user to change their password

   ifstream infile;
   infile.open("passwords.txt");
   PasswordManager *pmArray = new PasswordManager[3];
   string user;
   string password;

   if (infile.good())
   {
      for (int i = 0; i < 3; i++)
      {
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
   ofstream outfile;
   outfile.open("passwords.txt");
   for (int i = 0; i < 3; i++) {
      outfile << (pmArray + i)->getUsername() << " " <<  (pmArray + i)->getEncryptedPassword() << endl;
   }
   return 0;
}
