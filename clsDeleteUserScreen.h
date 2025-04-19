#pragma onece 

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsDeleteUserScreen: protected clsSCreen{

     static void _Print(clsUser User){

        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.UserName();
        cout << "\nPassword    : " ;
        cout << "\nPermisions  : " << User.Permesions();
        cout << "\n___________________\n";
    }

    public:
        static void DeleteUser(){
            _ScreenTitle("Delete User");


            cout << "Enter The User Name: " << endl;
        
            string UsrName = clsInputValidate::ReadString();
            
            while(!clsUser::IsUserExist(UsrName)){
        
            cout << "User Not exist, please Enter The User Name Again: " << endl;
        
            UsrName = clsInputValidate::ReadString();
        
            }
        
            clsUser User = clsUser::Find(UsrName);
        
            _Print(User);
        
        
            cout << "\n\n Do you realy want to delete this User? y/n \n" << endl;
            string do_delete = clsInputValidate::ReadString();
            if( do_delete == "y"){
        
                if (User.Delete()){
        
                    cout << "\n User is deleted successfuly."<< endl;
                    _Print(User);
                }
                else 
                cout << "sorry User not deleted" << endl;
            }
            
        }
      
      
};