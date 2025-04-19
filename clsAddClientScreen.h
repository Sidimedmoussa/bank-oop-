#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"
class clsAddClientScreen : protected clsSCreen{
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
        static void _ReadClientInfo(clsClient& client){

            cout << "First Name: " << endl;
            client.SetFirstName(clsInputValidate::ReadString());
        
            cout << "Last Name: " << endl;
            client.SetLastName(clsInputValidate::ReadString());
        
            cout << "Email: " << endl;
            client.SetEmail(clsInputValidate::ReadString());
        
            cout << "Phone Number: " << endl;
            client.SetPhone(clsInputValidate::ReadString());
        
            cout << "Pin Code " << endl;
            client.SetPinCode(clsInputValidate::ReadString());
        
            cout << "Account Balence:  " << endl;
            client.SetAcountBalence(clsInputValidate::ReadFloatNumber());
        
        
        }


public:

    static void AddNewClient(){

        if(! GiveAcces(clsUser::enPermissions::pAdd))
            return;
        _ScreenTitle("Add New Client");

    
        cout << "Enter The Account Number: " << endl;

        string AccountNumber = clsInputValidate::ReadString();
    
        while( clsClient::IsClientExist(AccountNumber)){

            cout << "Client is exist, please Enter an other Account Number Again: " << endl;

            AccountNumber = clsInputValidate::ReadString();

        }

        clsClient NewClient = clsClient::GetNewClentObj(AccountNumber);

        _ReadClientInfo(NewClient);

        clsClient::enSave SaveResult = NewClient.save();

        switch (SaveResult)
        {
        case clsClient::enSave::SaveSuccessful:
            
            cout << "\nAccound Added succfully:) " << endl;
            _Print(NewClient);

        break;
        
        case clsClient::enSave::SaveError:
        cout << "\n Error: Client Was Not Added , it's already exist. \n" << endl;
        
        break;
        }
    }

};