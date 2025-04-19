#pragma once 
#include<iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsUpdateClientScreen: protected clsSCreen{
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
    static void updateClient(){
        
        if(! GiveAcces(clsUser::enPermissions::pUpdate))
            return;

        _ScreenTitle("Update Client");

        cout << "Enter The Account Number: " << endl;
      
         string AccountNumber = clsInputValidate::ReadString();
        
        while(!clsClient::IsClientExist(AccountNumber)){
      
          cout << "Client Not exist, please Enter The Account Number Again: " << endl;
      
          AccountNumber = clsInputValidate::ReadString();
      
        }
      
        clsClient client = clsClient::Find(AccountNumber);
      
         _Print(client);
      
        cout << "\n Are You Sure you want to Update this infos? y/n" << endl;

        string do_update = clsInputValidate::ReadString();
        if( do_update == "y"){
                cout << "\n\nUpdate Client info: \n" << endl;
                cout << "\n______________________ \n" << endl;
            
                _ReadClientInfo(client);
                cout << "\n______________________ \n" << endl;
                
                clsClient::enSave SaveResult;
                SaveResult = client.save();
                
                switch (SaveResult)
                {
                case clsClient::enSave::SaveSuccessful:
                
                    cout << "\nAccound updated succfully:) " << endl;
                    _Print(client);
            
                break;
                
                case clsClient::enSave::SaveError:
                cout << "\n Error: Client Was Not Updated , it's Empty \n" << endl;
                
                break;
                }
            }
      }
      
};