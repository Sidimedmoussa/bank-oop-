#pragma once

#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"

class clsTransferScreen: protected clsSCreen{
private:
    static void _Print(clsClient Client){

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AcountNumber();
        cout << "\nBalance     : " << Client.AcountBalence();
        cout << "\n___________________\n";

    }
   static string _ReadAcountNumber(string AskMessage){

        string AccountNumber ="";
        cout << "\n" << AskMessage << ": ";
        cin >> AccountNumber;


        while (!clsClient::IsClientExist(AccountNumber)){

            cout << "\nAccount Not Found"<< endl;

            cout << "\n" << AskMessage << ": ";
            cin >> AccountNumber;
        }

        return AccountNumber;
    }

        
public:

  static void Transfer(){
        _ScreenTitle("Transfer");
        clsClient Sender = clsClient::Find(_ReadAcountNumber("Please Enter Account Number To Transfer from"));
        _Print(Sender);

        clsClient Receiver = clsClient::Find(_ReadAcountNumber("Please Enter Account Number To Transfer To"));
        _Print(Receiver);

        float TransferAmount;
        cout << "\nEnter Transfer Amount: ";
        cin >> TransferAmount;

        while(TransferAmount > Sender.AcountBalence())
        {
            cout << "\nAoumt Exceeds The Available Balance,Enter Another Amount: ";
            cin >> TransferAmount;
        }
        
        cout << "\nAre You Sure You Want To Perform This operation? y/n: ";
        string Decision;
        cin >> Decision;

        if(Decision == "y"){
            if(Sender.SendAmount(Receiver, TransferAmount)){
                cout << "\nTransfer Done Succesfuly" << endl;
            }
            else
             cout << "\nSomthing went wrong" << endl;

        }

        _Print(Sender);
        _Print(Receiver);

  }
};

