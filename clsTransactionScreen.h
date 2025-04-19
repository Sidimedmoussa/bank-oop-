#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalencesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionScreen : protected clsSCreen
{
private:
    enum enTransactionsSections
    {
        Deposit = 1,
        Withdraw = 2,
        TotalBalances = 3,
        Transfer = 4,
        TransferLog = 5,
        MainMenue = 6
    };

    static enTransactionsSections _ChooseSection()
    {
        int c;
        c = clsInputValidate::ReadIntNumberBetween(1, 6);

        return (enTransactionsSections)c;
    }

    static void _GoBackToTransactionsManue()
    {
        cout << left << setw(34) << "     ";
        _PressToLeaveScreen();
        TransactionMenueScreen();
    }

    static void _GoToTransactionsSections()
    {

        enTransactionsSections sectionNum = _ChooseSection();

        switch (sectionNum)
        {

        case enTransactionsSections::Deposit:
            _CleanScreen();
            _Deposit();
            _GoBackToTransactionsManue();
            break;

        case enTransactionsSections::Withdraw:
            _CleanScreen();
            _Withdraw();
            _GoBackToTransactionsManue();

            break;
        case enTransactionsSections::TotalBalances:
            _CleanScreen();
            _TotalBalances();
            _GoBackToTransactionsManue();

            break; 
            
        case enTransactionsSections::Transfer:
            _CleanScreen();
            _Transfer();
            _GoBackToTransactionsManue();

            break;

        case enTransactionsSections::TransferLog :
            _CleanScreen();
            _TransferLog();
            _GoBackToTransactionsManue();

            break;
        case enTransactionsSections::MainMenue:

            break;
        }
    }

    static void _Deposit()
    {

        clsDepositScreen::Deposit();
    }

    static void _Withdraw()
    {

        // _ScreenTitle("Withdraw");
        clsWithdrawScreen::Withdraw();
        
    }
    static void _TotalBalances()
    {
        // _ScreenTitle("Total Balances");
        clsTotalBalencesScreen::ListAllBalence();
    }

    static void _Transfer()
    {
        // _ScreenTitle("Transfer");
        clsTransferScreen::Transfer();
        // clsTransferScreen::ShowTransferScreen();
    }

    static void _TransferLog(){
        clsTransferLogScreen::ListLoginStorage();

    }

public:
    static void TransactionMenueScreen()
    {
        if(! GiveAcces(clsUser::enPermissions::pTransactions))
            return;
        _CleanScreen();
        _ScreenTitle("Transactions Menue");
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << " \t\t\t\t\t\t\t  Transactions Menue" << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << left << setw(34) << "     " << "[1] Deposit." << endl;
        cout << left << setw(34) << "     " << "[2] Withdraw." << endl;
        cout << left << setw(34) << "     " << "[3] Total Balances." << endl;
        cout << left << setw(34) << "     " << "[4] Transfer." << endl;
        cout << left << setw(34) << "     " << "[5] Transfer Log." << endl;
        cout << left << setw(34) << "     " << "[6] Main Menue." << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;

        cout << left << setw(34) << "     " << "Choose what Do You Want To Do. [1 to 6] :";
        _GoToTransactionsSections();
    }
};