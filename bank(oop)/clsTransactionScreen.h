#pragma once

#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
class clsTransactionScreen : protected clsSCreen{
    private:
    enum enTransactionsSections{Deposit = 1, 
                                Withdraw = 2,  
                                TotalBalances = 3,  
                                MainMenue = 4
                            };

    static  enTransactionsSections _ChooseSection(){
            int c;
            c = clsInputValidate::ReadIntNumberBetween(1,4);

            return (enTransactionsSections) c;
    }

    static void _GoBackToTransactionsManue(){
            cout << left << setw(34) << "     ";
            system("pause");
            TransactionMenueScreen();
        }

    static void _GoToTransactionsSections(){

        enTransactionsSections sectionNum = _ChooseSection();

        switch (sectionNum)
        {
            
        case enTransactionsSections::Deposit: 
            system("cls");
            _Deposit();
            _GoBackToTransactionsManue();
            break;

              
        case enTransactionsSections::Withdraw: 
            system("cls");
            _Withdraw();
            _GoBackToTransactionsManue();
            
        break;  
        case enTransactionsSections::TotalBalances : 
            system("cls");
            _TotalBalances();
            _GoBackToTransactionsManue();
            
            break;
         case enTransactionsSections::MainMenue : 
           
            break;  
     
        }

    }

    static void _Deposit(){

        clsDepositScreen::Deposit();        
    }

    static void _Withdraw(){

        _ScreenTitle("Withdraw");
        
    }
    static void _TotalBalances(){

        _ScreenTitle("Total Balances");
        
    }

    public:

    static void TransactionMenueScreen(){
        system("cls");
        _ScreenTitle("Transactions Menue");
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << " \t\t\t\t\t\t\t  Transactions Menue" << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << left << setw(34) << "     " << "[1] Deposit." << endl;
        cout << left << setw(34) << "     " << "[2] Withdraw." << endl;
        cout << left << setw(34) << "     " << "[3] Total Balances." << endl;
        cout << left << setw(34) << "     " << "[4] Main Menue." << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;

        cout << left << setw(34) << "     " << "Choose what Do You Want To Do. [1 to 4] :";
        _GoToTransactionsSections();
        

    }


};