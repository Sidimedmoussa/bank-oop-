#pragma onece 

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClient.h"

class clsDeleteClientScreen: protected clsSCreen{

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
        static void DeleteClient(){
            if(! GiveAcces(clsUser::enPermissions::pDellete))
                return;
            
            _ScreenTitle("Delete Client");


            cout << "Enter The Account Number: " << endl;
        
            string AccountNumber = clsInputValidate::ReadString();
            
            while(!clsClient::IsClientExist(AccountNumber)){
        
            cout << "Client Not exist, please Enter The Account Number Again: " << endl;
        
            AccountNumber = clsInputValidate::ReadString();
        
            }
        
            clsClient client = clsClient::Find(AccountNumber);
        
            _Print(client);
        
        
            cout << "\n\n Do you realy want to delete this client? y/n \n" << endl;
            string do_delete = clsInputValidate::ReadString();
            if( do_delete == "y"){
        
                if (client.Delete()){
        
                    cout << "\n Client is deleted successfuly."<< endl;
                    _Print(client);
                }
                else 
                cout << "sorry Client not deleted" << endl;
            }
            
        }
      
      
};