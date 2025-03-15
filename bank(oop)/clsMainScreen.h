#pragma once 

#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsShowClientsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"


class clsMainScreen :protected clsSCreen
{
private:
    enum enSections{ListClient = 1, 
                    AddNewClient = 2,  
                    DeleteClient = 3,  
                    updateClientInfo = 4,  
                    FindClient = 5,  
                    Transaction = 6,  
                    ManageUsers = 7,  
                    Logout = 8
                };
   static  enSections _ChooseSection(){
        int c;
        c = clsInputValidate::ReadIntNumberBetween(1,8);

        return (enSections) c;
    }

    static void _GoToSections(){
        enSections sectionNum = _ChooseSection();

        switch (sectionNum)
        {
            
        case enSections::ListClient: 
            system("cls");
            clsShowClientsScreen::ListClient();
            _GoBackToMainManue();
            break;

              
        case enSections::AddNewClient : 
            system("cls");
            _AddNewClient();
            _GoBackToMainManue();
            
        break;  
        case enSections::DeleteClient : 
            system("cls");
            _DeleteClient();
            _GoBackToMainManue();
            
            break;  
         case enSections::updateClientInfo : 
            system("cls");
            _UpdateClient();
            _GoBackToMainManue();
            
            break;  
        case enSections::FindClient : 
            system("cls");
            _FindClient();
            _GoBackToMainManue();
                
            break;  
        case enSections::Transaction : 
            system("cls");
            _Transactions();
            _GoBackToMainManue();
                    
          break;

        case enSections::ManageUsers : 
            system("cls");
            _ManageUsers();
            _GoBackToMainManue();
                  
        break;

        case enSections::Logout : 
            system("cls");
            _LogOout();
            break;
        }

    }

    static void _GoBackToMainManue(){
            cout << left << setw(34) << "     ";
            system("pause");
            MainScreen();
    }

    
    static void _AddNewClient(){
        // cout << "client will be add here." << endl;
         clsAddClientScreen::AddNewClient();  

    }

    static void _UpdateClient(){
        // cout << "client will be updated here." << endl;
        clsUpdateClientScreen::updateClient();


    }

    static void _DeleteClient(){

        // cout << "client will be delete here." << endl;
        clsDeleteClientScreen::DeleteClient();
    }

    static void _FindClient(){
        // cout << "client will be found here." << endl;
        clsFindClientScreen::FindClient();
    }

    static void _Transactions(){
        // cout<< "Transaction" << endl;

        clsTransactionScreen::TransactionMenueScreen();
    }

    static void _ManageUsers(){
        _ScreenTitle("Mange users Menue");
        cout << "Mange users" << endl;
    }

    static void _LogOout(){
        cout << "Logout" << endl;
    }

    
public:
    clsMainScreen(/* args */);
    ~clsMainScreen();




    static void MainScreen(){
        system("cls");
        _ScreenTitle("Main Menue");
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << " \t\t\t\t\t\t\t  Main Menue" << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << left << setw(34) << "     " << "[1] Show Client List." << endl;
        cout << left << setw(34) << "     " << "[2] Add New Client." << endl;
        cout << left << setw(34) << "     " << "[3] Delete Client." << endl;
        cout << left << setw(34) << "     " << "[4] Update Client Info." << endl;
        cout << left << setw(34) << "     " << "[5] Find Client." << endl;
        cout << left << setw(34) << "     " << "[6] Transactions." << endl;
        cout << left << setw(34) << "     " << "[7] Manage Users." << endl;
        cout << left << setw(34) << "     " << "[8] Logout." << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;

        cout << left << setw(34) << "     " << "Choose what Do You Want To Do. [1 to 8] :";
        _GoToSections();
        

    }
};


