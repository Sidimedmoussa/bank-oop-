#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsShowUsersScreen.h"



class clsManageUsersScreen : protected clsSCreen
{
private:
    enum enManageUsersSections
    {
        ListUsers = 1,
        AddNewUser = 2,
        DeleteUser = 3,
        updateUsersInfo = 4,
        FindUser = 5,
        MainMenue = 6
    };
    static enManageUsersSections _ChooseSection()
    {
        int c;
        c = clsInputValidate::ReadIntNumberBetween(1, 6);

        return (enManageUsersSections)c;
    }

    static void _GoToManageUsersSections()
    {
        enManageUsersSections sectionNum = _ChooseSection();

        switch (sectionNum)
        {

        case enManageUsersSections::ListUsers:
            _CleanScreen();
            _ListUsers();
            _GoToManageUsrMenue();
            break;

        case enManageUsersSections::AddNewUser :
            _CleanScreen();
            _AddNewUser();
            _GoToManageUsrMenue();

            break;
        case enManageUsersSections::DeleteUser:
            _CleanScreen();
            _DeleteUser();
            _GoToManageUsrMenue();

            break;
        case enManageUsersSections::updateUsersInfo:
            _CleanScreen();
            _UpdateUser();
            _GoToManageUsrMenue();

            break;
        case enManageUsersSections::FindUser :
            _CleanScreen();
            _FindUser();
            _GoToManageUsrMenue();

            break;

        case enManageUsersSections::MainMenue:

            break;
        }
    }

    static void _GoToManageUsrMenue()
    {
        // cout << left << setw(34) << "     ";
        _PressToLeaveScreen();
        ManageUsersScreen();
    }

    static void _ListUsers(){
        // cout << "User will be here" << endl;
        clsShowUsersScreen::ListUsers();
    }
    static void _AddNewUser()
    {
        // cout << "User will be add here." << endl;
        clsAddUserScreen::AddNewUser();
    }

    static void _UpdateUser()
    {
        // cout << "User will be updated here." << endl;
        clsUpdateUserScreen::UpdateUser();
    }

    static void _DeleteUser()
    {

        // cout << "User will be delete here." << endl;
        clsDeleteUserScreen::DeleteUser();
    }

    static void _FindUser()
    {
        // cout << "User will be found here." << endl;
        clsFindUserScreen::FindUser();
    }

public:


    static void ManageUsersScreen(){

        if(! GiveAcces(clsUser::enPermissions::pManageUsers))
            return;

        _CleanScreen();
        _ScreenTitle("Manage Users");
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << " \t\t\t\t\t\t\t  Manage Users Menue" << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << left << setw(34) << "     " << "[1] Show User List." << endl;
        cout << left << setw(34) << "     " << "[2] Add New User." << endl;
        cout << left << setw(34) << "     " << "[3] Delete User." << endl;
        cout << left << setw(34) << "     " << "[4] Update User Info." << endl;
        cout << left << setw(34) << "     " << "[5] Find User." << endl;
        cout << left << setw(34) << "     " << "[6] Main Menue." << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;

        cout << left << setw(34) << "     " << "Choose what Do You Want To Do. [1 to 5] :";
        _GoToManageUsersSections();
    }
};
