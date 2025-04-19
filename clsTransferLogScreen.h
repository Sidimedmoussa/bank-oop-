#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

#include "clsDate.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsString.h"

class clsTransferLogScreen : protected clsSCreen
{
private:
    struct stTransferLogStorage
    {
        string DateTime;
        string SenderAcc;
        string ReceiverAcc;
        float Ammount;
        float SenderBalance;
        float ReceiverBalance;
        string UserName;
    };
    static stTransferLogStorage _ConvertLineTostTransferLogStorage(string Line)
    {
        vector<string> LineSplit = clsString::Split(Line, "|");
        stTransferLogStorage stRecord;

        stRecord.DateTime = LineSplit[0];
        stRecord.SenderAcc = LineSplit[1];
        stRecord.ReceiverAcc = LineSplit[2];
        stRecord.Ammount = stof(LineSplit[3]);
        stRecord.SenderBalance = stof(LineSplit[4]);
        stRecord.ReceiverBalance = stof(LineSplit[5]);
        stRecord.UserName = LineSplit[6];
        return stRecord;
    }
    static vector<stTransferLogStorage> _LoadLoginData()
    {
        vector<stTransferLogStorage> vTransferLogData;
        fstream file;
        file.open("transfer_data", ios::in);

        if (file.is_open())
        {
            string Line = "";

            while (getline(file, Line))
            {

                vTransferLogData.push_back(_ConvertLineTostTransferLogStorage(Line));
            }
            file.close();
        }
        return vTransferLogData;
    }
    static void _PrintTransferLogRecord(stTransferLogStorage LoginRecord)
    {
        cout << left << setw(15) << "     ";
        cout << "| " << left << setw(20) << LoginRecord.DateTime;
        cout << "| " << left << setw(8) << LoginRecord.SenderAcc;
        cout << "| " << left << setw(8) << LoginRecord.ReceiverAcc;
        cout << "| " << left << setw(8) << LoginRecord.Ammount;
        cout << "| " << left << setw(10) << LoginRecord.SenderBalance;
        cout << "| " << left << setw(10) << LoginRecord.ReceiverBalance;
        cout << "| " << left << setw(8) << LoginRecord.UserName;
        cout << endl;
    }

public:
    static void ListLoginStorage()
    {
        _ScreenTitle("Transfer List");
        
        if(!GiveAcces(clsUser::enPermissions::pShowLogins))
            return ;
        vector<stTransferLogStorage> vTransferLogStorageLines = _LoadLoginData();

        if (vTransferLogStorageLines.empty())
        {

            cout << "\n"
                 << left << setw(34) << "     " << "\n No Data Availeble In The System." << endl;
        }

        else
        {

            cout << "\n"
                 << left << setw(34) << "     " << "\t\t\t\t Records List ( " << vTransferLogStorageLines.size() << " ) Login(s)" << endl;

            cout << "\n"
                 << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_______________________________________________________________________\n"
                 << endl;
            cout << left << setw(15) << "     ";
            cout << "| " << left << setw(20) << "Date/Time";
            cout << "| " << left << setw(8) << "Sender Acc";
            cout << "| " << left << setw(8) << "Receiver Acc";
            cout << "| " << left << setw(8) << "Ammount";
            cout << "| " << left << setw(10) << "Sender Balance";
            cout << "| " << left << setw(10) << "Receiver Balance";
            cout << "| " << left << setw(8) << "User Name";
            cout << "\n"
                 << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_______________________________________________________________________\n"
                 << endl;

            for (stTransferLogStorage Record : vTransferLogStorageLines)
            {
                _PrintTransferLogRecord(Record);
            }
            cout << "\n"
                 << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n"
                 << endl;
        }
    }
};
