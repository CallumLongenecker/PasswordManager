#include "PasswordManager.h"




int main() {
   // allows user to change their password

   ifstream infile;
   infile.open("passwords.txt");
   string user;

   getline(infile, user);


   for(int i = 0; i < 3; i++){
      
      PasswordManager* pm = new PasswordManager();
   }
   return 0;
}