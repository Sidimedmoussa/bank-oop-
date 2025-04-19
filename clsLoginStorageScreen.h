#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

#include "clsDate.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsString.h"

class clsLoginStorageScreen : protected clsSCreen
{
private:
    struct stLoginStorage
    {
        string DateTime;
        string UserName;
        string PassWord;
        string Permissions;
    };
    static stLoginStorage _ConvertLineTostLoginStorage(string Line)
    {
        vector<string> LineSplit = clsString::Split(Line, "|");
        stLoginStorage stRecord;

        stRecord.DateTime = LineSplit[0];
        stRecord.UserName = LineSplit[1];
        stRecord.PassWord = LineSplit[2];
        stRecord.Permissions = LineSplit[3];
        return stRecord;
    }
    static vector<stLoginStorage> _LoadLoginData()
    {
        vector<stLoginStorage> vLoginData;
        fstream file;
        file.open("login_data", ios::in);

        if (file.is_open())
        {
            string Line = "";

            while (getline(file, Line))
            {

                vLoginData.push_back(_ConvertLineTostLoginStorage(Line));
            }
            file.close();
        }
        return vLoginData;
    }
    static void _PrintLoginRecord(stLoginStorage LoginRecord)
    {
        cout << left << setw(15) << "     ";
        cout << "| " << left << setw(20) << LoginRecord.DateTime;
        cout << "| " << left << setw(12) << LoginRecord.UserName;
        cout << "| " << left << setw(12) << LoginRecord.PassWord;
        cout << "| " << left << setw(12) << LoginRecord.Permissions;
        cout << endl;
    }

public:
    static void ListLoginStorage()
    {
        _ScreenTitle("Logins List");
        
        if(!GiveAcces(clsUser::enPermissions::pShowLogins))
            return ;
        vector<stLoginStorage> vLoginStorageLines = _LoadLoginData();

        if (vLoginStorageLines.empty())
        {

            cout << "\n"
                 << left << setw(34) << "     " << "\n No Data Availeble In The System." << endl;
        }

        else
        {

            cout << "\n"
                 << left << setw(34) << "     " << "\t\t\t\t Records List ( " << vLoginStorageLines.size() << " ) Login(s)" << endl;

            cout << "\n"
                 << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n"
                 << endl;
            cout << left << setw(15) << "     ";
            cout << "| " << left << setw(20) << "Date/Time";
            cout << "| " << left << setw(12) << "User Name";
            cout << "| " << left << setw(12) << "Password";
            cout << "| " << left << setw(12) << "Permisions";
            cout << "\n"
                 << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n"
                 << endl;

            for (stLoginStorage Record : vLoginStorageLines)
            {
                _PrintLoginRecord(Record);
            }
            cout << "\n"
                 << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n"
                 << endl;
        }
    }
};
