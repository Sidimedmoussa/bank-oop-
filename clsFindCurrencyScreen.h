#pragma once 
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyExchange.h"

class clsFindCurrencyScreen: protected clsSCreen{
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
    enum enSearshBy {sCode=1, sCountry=2};
    static enSearshBy _ChooseSearchMethod()
    {
        int c;
        c = clsInputValidate::ReadIntNumberBetween(1, 2);

        return (enSearshBy) c;
    }
    
    public: 
    static void FindCurrency(){
        _ScreenTitle("Find Currency");

        cout << "\nFind By: [1] Code or [2] Country: ";
        enSearshBy SearchMethod = _ChooseSearchMethod();

        clsCurrencyExchange currency = clsCurrencyExchange::FindByCountryName("");

        if(SearchMethod == enSearshBy::sCountry){

            cout << "\nEnter the Country Name:"<<endl;
            currency = clsCurrencyExchange::FindByCountryName(clsInputValidate::ReadString());
        }

        if(SearchMethod == enSearshBy::sCode){

            cout << "\nEnter the Currency Code: "<<endl;
            currency = clsCurrencyExchange::FindByCurrencyCode(clsInputValidate::ReadString());
        }

        if(currency.IsEmpty()){
            cout << "\nCurrency Not Found" << endl;

        }
        else {
            _Print(currency);
        }
     
    
    }
};