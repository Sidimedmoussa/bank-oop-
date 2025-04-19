#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculator.h"
class clsCurrencyExchangeScreen : protected clsSCreen
{
private:
    enum enCurrencyExchangeSections
    {
        ListCurrencies = 1,
        FindCurrency = 2,
        UpdateRate = 3,
        CurrencyCalculator = 4,
        MainMenue = 6
    };

    static enCurrencyExchangeSections _ChooseSection()
    {
        int c;
        c = clsInputValidate::ReadIntNumberBetween(1, 5);

        return (enCurrencyExchangeSections)c;
    }

    static void _GoBackToCurrencyExchangeManue()
    {
        cout << left << setw(34) << "     ";
        _PressToLeaveScreen();
        CurrencyExchangeMenueScreen();
    }

    static void _CurrencyExchangeSections()
    {

        enCurrencyExchangeSections sectionNum = _ChooseSection();

        switch (sectionNum)
        {

        case enCurrencyExchangeSections::ListCurrencies:
            _CleanScreen();
            _ListCurrencies();
            _GoBackToCurrencyExchangeManue();
            break;

        case enCurrencyExchangeSections::FindCurrency:
            _CleanScreen();
            _FindCurrency();
            _GoBackToCurrencyExchangeManue();

            break;
        case enCurrencyExchangeSections::UpdateRate:
            _CleanScreen();
            _UpdateRate();
            _GoBackToCurrencyExchangeManue();

            break;
        case enCurrencyExchangeSections::CurrencyCalculator:
            _CleanScreen();
            _CurrencyCalculator();
            _GoBackToCurrencyExchangeManue();

            break; 
        case enCurrencyExchangeSections::MainMenue:

            break;
        }
    }

    static void _ListCurrencies(){
        clsShowCurrenciesScreen::ListCurrencies();
    }
    
    static void _FindCurrency(){
        clsFindCurrencyScreen::FindCurrency();
    }
    static void _UpdateRate(){
        clsUpdateRateScreen::UpdateRate();
    }

    static void _CurrencyCalculator(){
        clsCurrencyCalculator::CurrencyCalculator();
    }

public:
    static void CurrencyExchangeMenueScreen()
    {
        if(! GiveAcces(clsUser::enPermissions::pTransactions))
            return;
        _CleanScreen();
        _ScreenTitle("Currency Exchange");
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << " \t\t\t\t\t\t\t  Currency Exchange Menue" << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;
        cout << left << setw(34) << "     " << "[1] Lis Currencies." << endl;
        cout << left << setw(34) << "     " << "[2] Find Currency." << endl;
        cout << left << setw(34) << "     " << "[3] Update Rate." << endl;
        cout << left << setw(34) << "     " << "[4] Currency Calculator." << endl;
        cout << left << setw(34) << "     " << "[5] Main Menue." << endl;
        cout << "\n \t\t\t\t===================================================================" << endl;

        cout << left << setw(34) << "     " << "Choose what Do You Want To Do. [1 to 5] :";
        _CurrencyExchangeSections();
    }
};