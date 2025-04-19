#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include<vector>
#include<iomanip>


class clsShowClientsScreen: protected clsSCreen{
    private:
    static void _PrintClientRecord(clsClient client){
        cout << left << setw(15) << "     " ;
        cout << "| " << left << setw(15) << client.AcountNumber();
        cout << "| " << left << setw(20) << client.FullName();
        cout << "| " << left << setw(12) << client.GetPhone();
        cout << "| " << left << setw(20) << client.GetEmail();
        cout << "| " << left << setw(10) << client.PinCode();
        cout << "| " << left << setw(12) << client.AcountBalence();
        cout << endl;
      }

    public: 



    static void ListClient(){

        if(! GiveAcces(clsUser::enPermissions::pShow))
            return;
        _ScreenTitle("Clients List");


        vector<clsClient> vClientsList = clsClient::GetAllClient();
          
        if(vClientsList.empty()){  
        
            cout << "\n" << left << setw(34) << "     " << "\n No Clients Availeble In The System." << endl;
        }
            
        else{
            
            cout << "\n" << left << setw(34) << "     " << "\t\t\t\t Client List ( " << vClientsList.size() << " ) Client(s)" << endl;
            
        
            cout << "\n" << left << setw(15) << "     " <<  "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout <<  left << setw(15) << "     " ;
            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(20) << "Client Name";
            cout << "| " << left << setw(12) << "Phone";
            cout << "| " << left << setw(20) << "Email";
            cout << "| " << left << setw(10) << "Pin Code";
            cout << "| " << left << setw(12) << "Balance";
            cout << "\n" << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
          
            for (clsClient client : vClientsList){
                _PrintClientRecord(client);
                 
            }
            cout << "\n" << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
          
            }

    }

};