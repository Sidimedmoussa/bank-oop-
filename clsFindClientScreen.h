#pragma once 
#include<iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen: protected clsSCreen{
    private:

    static void _Print(clsClient Client){

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AcountNumber();
        cout << "\nPassword    : " << Client.PinCode();
        cout << "\nBalance     : " << Client.AcountBalence();
        cout << "\n___________________\n";

    }

    public: 
    static void FindClient(){

        if(! GiveAcces(clsUser::enPermissions::pFind))
            return;

        _ScreenTitle("Find Client");

        cout << "\nEnter the Account Number:"<<endl;
        string ClientNum = clsInputValidate::ReadString();

        while (!clsClient::IsClientExist(ClientNum))
        {
            cout << "Client not found, Try An Other One: "<< endl;
            ClientNum = clsInputValidate::ReadString();
        }
        
        clsClient client = clsClient::Find(ClientNum);
         _Print(client);
    
    }
};