#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include<vector>
#include<iomanip>


class clsShowUsersScreen: protected clsSCreen{
    private:
    static void _PrintUserRecord(clsUser User){
        cout << left << setw(15) << "     " ;
        cout << "| " << left << setw(15) << User.UserName();
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(12) << User.GetPhone();
        cout << "| " << left << setw(20) << User.GetEmail();
        // cout << "| " << left << setw(10) << User.PinCode();
        cout << "| " << left << setw(12) << User.Permesions();
        cout << endl;
      }

    public: 



    static void ListUsers(){
        _ScreenTitle("Users List");


        vector<clsUser> vUsersList = clsUser::GetAllUsers();
          
        if(vUsersList.empty()){  
        
            cout << "\n" << left << setw(34) << "     " << "\n No User Availeble In The System." << endl;
        }
            
        else{
            
            cout << "\n" << left << setw(34) << "     " << "\t\t\t\t Client List ( " << vUsersList.size() << " ) User(s)" << endl;
            
        
            cout << "\n" << left << setw(15) << "     " <<  "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout <<  left << setw(15) << "     " ;
            cout << "| " << left << setw(15) << "User Name";
            cout << "| " << left << setw(20) << "Client Name";
            cout << "| " << left << setw(12) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            // cout << "| " << left << setw(10) << "Pin Code";
            cout << "| " << left << setw(12) << "Permisions";
            cout << "\n" << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
          
            for (clsUser User : vUsersList){
                _PrintUserRecord(User);
                 
            }
            cout << "\n" << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
          
            }

    }

};