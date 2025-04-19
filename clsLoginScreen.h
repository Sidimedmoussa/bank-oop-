#pragma once 

#include<iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsSCreen{
private:
     static bool _Login(){

        bool LoginFailed = false;
        short TrialCount = 0;
        do{

            _CleanScreen();

            _ScreenTitle("Login Screen");

            if(LoginFailed){
                cout << "Wrong User Name Or Password, Try again"<<endl;
                
                TrialCount++;
                cout << 3 - TrialCount << " Trial(s) left." << endl;
                }

            if(TrialCount == 3){
                cout << "Your Locked after 3 faild trails." << endl;
                return false;
            }

            cout << "\nEnter User Name: ";
            string UserName = clsInputValidate::ReadString();

            cout << "\nEnter Password: ";
            string Pass = clsUtil::EncryptText(clsInputValidate::ReadString());

            CurrentUser = clsUser::Find(UserName, Pass);
            LoginFailed = CurrentUser.IsEmpty();

        }while( TrialCount < 3 && LoginFailed);

        CurrentUser.StoreLoginInfo();
        return true;
    }

public:

    static bool LoginScreen(){
        if(_Login()){
            clsMainScreen::MainScreen();
            return true;
        }
        return false;

    }

};
