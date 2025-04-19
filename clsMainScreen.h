#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsShowClientsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginStorageScreen.h"
#include "clsCurrencyExchangeScreen.h"
class clsMainScreen : protected clsSCreen
{
private:
    enum enSections
    {
        ListClient = 1,
        AddNewClient = 2,
        DeleteClient = 3,
        updateClientInfo = 4,
        FindClient = 5,
        Transaction = 6,
        ManageUsers = 7,
        LoginStorage = 8,
        CurrencyExchange = 9,
        Logout = 10
    };
    static enSections _ChooseSection()
    {
        int c;
        c = clsInputValidate::ReadIntNumberBetween(1, 10);

        return (enSections)c;
    }

    static void _GoToSections()
    {
        enSections sectionNum = _ChooseSection();

        switch (sectionNum)
        {

        case enSections::ListClient:
            _CleanScreen();
            clsShowClientsScreen::ListClient();
            _GoBackToMainManue();
            break;

        case enSections::AddNewClient:
            _CleanScreen();
            _AddNewClient();
            _GoBackToMainManue();

            break;
        case enSections::DeleteClient:
            _CleanScreen();
            _DeleteClient();
            _GoBackToMainManue();

            break;
        case enSections::updateClientInfo:
            _CleanScreen();
            _UpdateClient();
            _GoBackToMainManue();

            break;
        case enSections::FindClient:
            _CleanScreen();
            _FindClient();
            _GoBackToMainManue();

            break;
        case enSections::Transaction:
            _CleanScreen();
            _Transactions();
            _GoBackToMainManue();

            break;

        case enSections::ManageUsers:
            _CleanScreen();
            _ManageUsers();
            _GoBackToMainManue();

            break;

        case enSections::LoginStorage:
            _CleanScreen();
            _ListLoginStorage();
            _GoBackToMainManue();
            break;
        case enSections::CurrencyExchange:
            _CleanScreen();
            _CurrencyExchange();
            _GoBackToMainManue();
            break;

        case enSections::Logout:
            _CleanScreen();
            _Logout();
            break;
        }
    }

    static void _GoBackToMainManue()
    {
        cout << left << setw(34) << "     ";
        _PressToLeaveScreen();
        MainScreen();
    }

    static void _AddNewClient()
    {
        // cout << "client will be add here." << endl;
        clsAddClientScreen::AddNewClient();
    }

    static void _UpdateClient()
    {
        // cout << "client will be updated here." << endl;
        clsUpdateClientScreen::updateClient();
    }

    static void _DeleteClient()
    {

        // cout << "client will be delete here." << endl;
        clsDeleteClientScreen::DeleteClient();
    }

    static void _FindClient()
    {
        // cout << "client will be found here." << endl;
        clsFindClientScreen::FindClient();
    }

    static void _Transactions()
    {
        // cout<< "Transaction" << endl;

        clsTransactionScreen::TransactionMenueScreen();
    }

    static void _ManageUsers()
    {
        // _ScreenTitle("Mange users Menue");
        // cout << "Mange users" << endl;
        clsManageUsersScreen::ManageUsersScreen();
    }
    static void _ListLoginStorage(){
        clsLoginStorageScreen::ListLoginStorage();
    }

    static void _Logout()
    {
        // cout << "Logout" << endl;
        CurrentUser = clsUser::Find("","");
    }
    static void _CurrencyExchange(){
       clsCurrencyExchangeScreen::CurrencyExchangeMenueScreen();
    }
public:
    static void MainScreen()
    {
        _CleanScreen();
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
        cout << left << setw(34) << "     " << "[8] Login Storage." << endl;
        cout << left << setw(34) << "     " << "[9] Currency Exchange." << endl;
        cout << left << setw(34) << "     " << "[10] Logout." << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;

        cout << left << setw(34) << "     " << "Choose what Do You Want To Do. [1 to 10] :";
        _GoToSections();
    }
};
