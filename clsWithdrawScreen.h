#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsSCreen{
private:
   static void _Print(clsClient Client){

        cout << "\nClient Card:";
        cout << "\n___________________";
        // cout << "\nFirstName   : " << Client.GetFirstName();
        // cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        // cout << "\nEmail       : " << Client.GetEmail();
        // cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AcountNumber();
        // cout << "\nPassword    : " << Client.PinCode();
        cout << "\nBalance     : " << Client.AcountBalence();
        cout << "\n___________________\n";

    }
public:

    static void Withdraw(){
        _ScreenTitle("Withdraw");
         cout << "Enetr The Account Number: " << endl;
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsClient::IsClientExist(AccountNumber)){
            cout << "\nClient Not Found, Enetr The Account Number Again: \n" << endl;
            AccountNumber = clsInputValidate::ReadString();    
        }

        clsClient Client = clsClient::Find(AccountNumber);

        _Print(Client);

        cout << "\n Enter The Ammount You Want To Withdra: " << endl;
        float WithdrawAmount = clsInputValidate::ReadDblNumber();

        cout << "Do you want to Withdraw this amount? y/n" << endl;
        string WantWithdraw = clsInputValidate::ReadString();


        if (WantWithdraw == "y" && WithdrawAmount < Client.AcountBalence()){
            Client.Withdraw(WithdrawAmount);

            cout << "\n You diposit Successfully." << endl;
            cout << "\n Before Widraw: "<< Client.AcountBalence() + WithdrawAmount  << endl;
            cout << "\n After Widraw: "<< Client.AcountBalence()  << endl;

        }
        else if(WithdrawAmount > Client.AcountBalence()){
            cout << "sorry you can't withdraw this amount :(" << endl;

            cout << "\n Widraw Amount : "<< WithdrawAmount  << endl;
            cout << "\n Your Balence: "<< Client.AcountBalence()  << endl;

        }
    }

};
