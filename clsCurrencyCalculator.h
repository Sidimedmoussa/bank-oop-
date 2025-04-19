#pragma once 

#include<iostream>

#include "clsCurrencyExchange.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsCurrencyCalculator : protected clsSCreen
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

    static clsCurrencyExchange _ReadCurrency(string AskMsg){

        cout << endl << AskMsg << endl;
        string Code = clsInputValidate::ReadString();

        
        while(!clsCurrencyExchange::IsCurrencyExist(Code)){
      
          cout << "Currency Not Exist, Please " << AskMsg << " Again: " << endl;
      
          Code = clsInputValidate::ReadString();
      
        }

        return clsCurrencyExchange::FindByCurrencyCode(Code);
    }
public:
    static void CurrencyCalculator(){

        string AnotherExchange = "n";

        do{
            if(AnotherExchange == "y" || AnotherExchange == "Y")
                _CleanScreen();

            _ScreenTitle("Currency Calculator");

            clsCurrencyExchange Currency1 = _ReadCurrency("Enter Currency1 code:");
            clsCurrencyExchange Currency2 = _ReadCurrency("Enter Currency2 code:");

            cout << "\nEnter Amount To Exchange: ";
            float Amount = clsInputValidate::ReadFloatNumber();
            float ExchangedAmount = 0.0;

            if(Currency2.Code() == "USD"){
                ExchangedAmount = Currency1.ExchangeCurrencyToDollar(Amount);

                cout << "\nConvert From: "<< endl;
                _Print(Currency1);

                cout << endl<< Amount << " " << Currency1.Code() << " = " << ExchangedAmount << " USD" << endl;
            }
            else{
                ExchangedAmount = Currency1.ExchangeCurrencyToCurrency(Amount, Currency2);

                cout << "\nConvert From: "<< endl;
                _Print(Currency1);

                cout << "\nTo: "<< endl;
                _Print(Currency2);

                cout << endl<< Amount << " " << Currency1.Code() << " = " << ExchangedAmount << " " << Currency2.Code()  << endl;
            }

            cout << "\nDo You Want To Perform Another Calculation? y/n :" ;
            AnotherExchange = clsInputValidate::ReadString();
        }while (AnotherExchange == "y" || AnotherExchange == "Y");


    }
};


