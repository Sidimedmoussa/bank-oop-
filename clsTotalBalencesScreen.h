#pragma once

#include <iostream>
#include <iomanip>
#include "clsClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
using namespace std;
class clsTotalBalencesScreen : protected clsSCreen{
private:
    static void _PrintClientBalanceRecord(clsClient client){
        cout << "| " << left << setw(15) << client.AcountNumber();
        cout << "| " << left << setw(40) << client.FullName();
        cout << "| " << left << setw(12) << client.AcountBalence();
        cout << endl;
    }
public:
    
static void ListAllBalence(){
        _ScreenTitle("Total Balences");
        vector<clsClient> vClientsList = clsClient::GetAllClient();
        double TotalBalance = clsClient::TotalBalance();

        cout << "\t\t\t\t Client List ( " << vClientsList.size() << " ) Client(s)" << endl;

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        for(clsClient client : vClientsList){
          _PrintClientBalanceRecord(client);
           
        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t\t\t Total Balance: " << TotalBalance << endl;
        cout << "\t\t\t\t (" << clsUtil::NumberToText(TotalBalance) << ")" << endl;

}
};

