#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsCurrencyExchange.h"
#include<vector>
#include<iomanip>


class clsShowCurrenciesScreen : protected clsSCreen{
    private:
    static void _PrintCurrencyRecord(clsCurrencyExchange CurrencyInfo){
        cout << left << setw(15) << "     " ;
        cout << "| " << left << setw(30) << CurrencyInfo.Country();
        cout << "| " << left << setw(6) << CurrencyInfo.Code();
        cout << "| " << left << setw(40) << CurrencyInfo.CurrenctName();
        cout << "| " << left << setw(12) << CurrencyInfo.Rate();
        cout << endl;
      }

    public: 



    static void ListCurrencies(){

        // if(! GiveAcces(clsUser::enPermissions::CurrencyExchange))
        //     return;
        _ScreenTitle("Currencies List");


        vector<clsCurrencyExchange> vCurrenciesList = clsCurrencyExchange::GetAllCountriesInfo();
          
        if(vCurrenciesList.empty()){  
        
            cout << "\n" << left << setw(34) << "     " << "\n No Currencies Availeble In The System." << endl;
        }
            
        else{
            
            cout << "\n" << left << setw(34) << "     " << "\t\t\t\t Currencies List ( " << vCurrenciesList.size() << " ) Currencies" << endl;
            
        
            cout << "\n" << left << setw(15) << "     " <<  "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout <<  left << setw(15) << "     " ;
            cout << "| " << left << setw(30) << "Country";
            cout << "| " << left << setw(6) << "Code";
            cout << "| " << left << setw(40) << "Name";
            cout << "| " << left << setw(12) << "Rate/(1$)";
            cout << "\n" << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
          
            for (clsCurrencyExchange Currency : vCurrenciesList){
                _PrintCurrencyRecord(Currency);
                 
            }
            cout << "\n" << left << setw(15) << "     " << "_______________________________________________________";
            cout << "_________________________________________\n" << endl;
          
            }

    }

};