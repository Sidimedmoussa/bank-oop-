#pragma once 
#include<iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen: protected clsSCreen{
    private:

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
    static void FindUser(){
        _ScreenTitle("Find User");

        cout << "\nEnter the User Name:"<<endl;
        string UsrName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UsrName))
        {
            cout << "User not found, Try An Other One: "<< endl;
            UsrName = clsInputValidate::ReadString();
        }
        
        clsUser User = clsUser::Find(UsrName);
         _Print(User);
    
    }
};