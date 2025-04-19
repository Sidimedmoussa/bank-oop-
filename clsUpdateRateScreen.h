#pragma once 
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyExchange.h"

class clsUpdateRateScreen : protected clsSCreen
{
private:
   static void _Print(clsCurrencyExchange Currency){

        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry  : " << Currency.Country();
        cout << "\nCode     : " << Currency.Code();
        cout << "\nName     : " << Currency.CurrenctName();
        cout << "\nRate(1$) : " << Currency.Rate();
        cout << "\n___________________\n";
    }
public:
    static void UpdateRate(){
        _ScreenTitle("Update Currency Rate");

        cout << "\nEnter the Currency Code: "<<endl;
        string Code = clsInputValidate::ReadString();

        
        while(!clsCurrencyExchange::IsCurrencyExist(Code)){
      
          cout << "Currency Not Exist, Please Enter Currency Code Again: " << endl;
      
          Code = clsInputValidate::ReadString();
      
        }
      
        clsCurrencyExchange Currency = clsCurrencyExchange::FindByCurrencyCode(Code);

        _Print(Currency);
      
        cout << "\n Are You Sure you want to Update the Rate? y/n" << endl;

        string do_update = clsInputValidate::ReadString();
        if( do_update == "y"){
            cout << "\n\nUpdate Rate: \n" << endl;
            cout << "\n______________________ \n" << endl;

            cout << "\nEnter the New Rate: " ;
            float NewRate = clsInputValidate::ReadFloatNumber();
            Currency.SetRate(NewRate);

            cout << "\nCurrency Rate updated succfully:) " << endl;
            _Print(Currency);
        }


        
    }
};