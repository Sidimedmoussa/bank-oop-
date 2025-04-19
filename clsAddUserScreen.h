#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsAddUserScreen : protected clsSCreen{
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

        static void _ReadClientInfo(clsUser& usr){

        cout << "First Name: " << endl;
        usr.SetFirstName(clsInputValidate::ReadString());
    
        cout << "Last Name: " << endl;
        usr.SetLastName(clsInputValidate::ReadString());
    
        cout << "Email: " << endl;
        usr.SetEmail(clsInputValidate::ReadString());
    
        cout << "Phone Number: " << endl;
        usr.SetPhone(clsInputValidate::ReadString());
    
        cout << "Password: " << endl;
        usr.SetPassword(clsInputValidate::ReadString());
    
        cout << "Permisions:  " << endl;
        usr.SetPermesions(_ReadPermissions());
    
    
    }
    static string _Decision(string Ask){
        string Respond = "n";
        cout << "\n" << Ask << "y/n:";
        cin >> Respond;
        return Respond;
    }
    static int _ReadPermissions(){

        if(_Decision("Do You Want To Give Full Acces?") == "y")
            return -1;
        int Permissions = 0;
        
        cout << "Do You Want To Give Acces To: "<< endl;

        if(_Decision("Show Client List?") == "y")
            Permissions += clsUser::enPermissions::pShow;

        if(_Decision("Add New Client?") == "y")
            Permissions += clsUser::enPermissions::pAdd; 

        if(_Decision("Delete Client?") == "y")
            Permissions += clsUser::enPermissions::pDellete;

        if(_Decision("Update Client?") == "y")
            Permissions += clsUser::enPermissions::pUpdate; 
              
        if(_Decision("Find Client?") == "y")
            Permissions += clsUser::enPermissions::pFind; 

        if(_Decision("Manage Users?") == "y")
            Permissions += clsUser::enPermissions::pManageUsers;

        if(_Decision("Show Login Storage Screen?") == "y")
            Permissions += clsUser::enPermissions::pShowLogins;

        return Permissions;
    }

public:

    static void AddNewUser(){
        _ScreenTitle("Add New User");

    
        cout << "Enter The User Name: " << endl;
      
        string UserName = clsUtil::EncryptText(clsInputValidate::ReadString());
        
        while(clsUser::IsUserExist(UserName)){
      
          cout << "User Name Exists, Please Enter An Other User Name: " << endl;
      
          UserName = clsUtil::EncryptText(clsInputValidate::ReadString());
      
        }
      

        clsUser NewUser = clsUser::GetNewClentObj(UserName);

        _ReadClientInfo(NewUser);

        clsUser::enSave SaveResult = NewUser.save();

        switch (SaveResult)
        {
        case clsUser::enSave::SaveSuccessful:
            
            cout << "\nUser Added succfully:) " << endl;
            _Print(NewUser);

        break;
        
        case clsUser::enSave::SaveError:
        cout << "\n Error: User Was Not Added , it's already exist. \n" << endl;
        
        break;
        }
    }

};