#include<iostream>
#include<iomanip>
// #include "clsClient.cpp"
// #include "clsInputValidate.h"
// #include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;




 







// void printClientBalanceRecord(clsClient client){
//     cout << "| " << left << setw(15) << client.AcountNumber();
//     cout << "| " << left << setw(40) << client.FullName();
//     cout << "| " << left << setw(12) << client.AcountBalence();
//     cout << endl;
// }
// void ListAllBalence(){

//         vector<clsClient> vClientsList = clsClient::GetAllClient();
//         double TotalBalance = clsClient::TotalBalance();

//         cout << "\t\t\t\t Client List ( " << vClientsList.size() << " ) Client(s)" << endl;

//         cout << "\n_______________________________________________________";
//         cout << "_________________________________________\n" << endl;

//         cout << "| " << left << setw(15) << "Accout Number";
//         cout << "| " << left << setw(40) << "Client Name";
//         cout << "| " << left << setw(12) << "Balance";
//         cout << "\n_______________________________________________________";
//         cout << "_________________________________________\n" << endl;

//         for(clsClient client : vClientsList){
//           printClientBalanceRecord(client);
           
//         }
//         cout << "\n_______________________________________________________";
//         cout << "_________________________________________\n" << endl;

//         cout << "\t\t\t\t Total Balance: " << TotalBalance << endl;
//         cout << "\t\t\t\t (" << clsUtil::NumberToText(TotalBalance) << ")" << endl;

// }




int main(){

 
  clsMainScreen::MainScreen();

    return 0;
}