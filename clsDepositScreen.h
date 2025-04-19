#pragma once 

#include<iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"

class clsDepositScreen: protected clsSCreen{

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
    static void Deposit(){
        _ScreenTitle("Diposit");

        cout << "Enetr The Account Number: " << endl;
        string AccountNumber = clsInputValidate::ReadString();
        
        while (!clsClient::IsClientExist(AccountNumber)){
            cout << "\nClient Not Found, Enetr The Account Number Again: \n" << endl;
            AccountNumber = clsInputValidate::ReadString();    
        }

        clsClient Client = clsClient::Find(AccountNumber);

        _Print(Client);

        cout << "Do you want to Deposit an amount? y/n" << endl;
        string WantDeposit = clsInputValidate::ReadString();

        if (WantDeposit == "y"){
            cout << "\nEnter The Ammount You Want To Deposit: " << endl;
            float DepositAmount = clsInputValidate::ReadDblNumber();
            
            Client.Deposit(DepositAmount);

            cout << "\nYou diposit Successfully." << endl;

            cout << "\nClient Info After Deposit:" << endl;
            _Print(Client);

        }

        


    }

};