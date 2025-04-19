#pragma once

#include<iostream>
#include<fstream>

#include "clsString.h"

using namespace std;
class clsCurrencyExchange
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1};
    
    enMode _Mode;
    string _Country;
    string _Code;
    string _CurrenctName;
    float _Rate;

    static clsCurrencyExchange _ConvertLineToObject(string line, string sep="|"){
        vector<string> vSplitLine = clsString::Split(line,sep);
        return clsCurrencyExchange(enMode::UpdateMode, vSplitLine[0], vSplitLine[1], vSplitLine[2], stof(vSplitLine[3]));
    }

     static string  _ConvertObjectToLine(clsCurrencyExchange CountryInfo, string sep="|"){
        string line = "";
        line += CountryInfo.Country() + sep;
        line += CountryInfo.Code() + sep;
        line += CountryInfo.CurrenctName() + sep;
        line += to_string(CountryInfo.Rate());

        return line;
    }
    static clsCurrencyExchange _EmptyClientObject(){
        return clsCurrencyExchange(enMode::EmptyMode, "", "", "", 0.0);
    }
    static vector<clsCurrencyExchange> _LoadCountriesInfo(){
        vector<clsCurrencyExchange> vCountriesInfo;
        fstream file;

        file.open("Currencies.txt", ios::in);

        if(file.is_open()){

            string line;
            while(getline(file, line)){
                clsCurrencyExchange CountryInfo = clsCurrencyExchange::_ConvertLineToObject(line);
                vCountriesInfo.push_back(CountryInfo);
            }
        }
        
        file.close();

        return vCountriesInfo;
    }

    static void _saveCountriesInfo(vector<clsCurrencyExchange> vCountrisInfo){

        fstream file;

        file.open("Currencies.txt", ios::out);
        string Line;

        if(file.is_open()){
            
            for(clsCurrencyExchange cn : vCountrisInfo){

                    Line = _ConvertObjectToLine(cn);
                    file << Line << endl ;

            }
            file.close();
        }
        
    }

    void _update(){
        
       vector<clsCurrencyExchange> _vCountriesinfo;
       _vCountriesinfo = _LoadCountriesInfo();

        for (clsCurrencyExchange& cn : _vCountriesinfo)
        {
            
            if(cn.Code() == Code()){
            
                cn = *this;
                break;
            }
        }        
        _saveCountriesInfo(_vCountriesinfo);


    }

public:
    clsCurrencyExchange(enMode Mode, string Country,
                         string Code, string CurrenctName, float Rate){
        _Mode = Mode;
        _Country = Country;
        _Code = Code;
        _CurrenctName = CurrenctName;
        _Rate = Rate;            
    }

    string Country(){
        return _Country;
    }
    string Code(){
        return _Code;
    }
    string CurrenctName(){
        return _CurrenctName;
    }

    float Rate(){
        return _Rate;
    }

    void SetRate(float Rate){
        _Rate = Rate;
        _update();
    }

    bool IsEmpty(){
        return (_Mode == enMode::EmptyMode);
    }

     static clsCurrencyExchange FindByCountryName(string CountryName){
        
        CountryName = clsString::UpperAllString(CountryName);

        fstream file;
        file.open("Currencies.txt", ios::in);

        if(file.is_open()){

            string line;
            while (getline(file, line))
            {
                clsCurrencyExchange County = _ConvertLineToObject(line);

                if (clsString::UpperAllString(County.Country()) == CountryName){

                    file.close();
                    return County;
                }
            }
        }
    
        return _EmptyClientObject();
    
    }

     static clsCurrencyExchange FindByCurrencyCode(string CurrencyCode){
        
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        fstream file;
        file.open("Currencies.txt", ios::in);

        if(file.is_open()){

            string line;
            while (getline(file, line))
            {
                clsCurrencyExchange County = _ConvertLineToObject(line);

                if (County.Code() == CurrencyCode){

                    file.close();
                    return County;
                }
            }
        }
    
        return _EmptyClientObject();
    
    }


    static bool IsCurrencyExist(string Code){
        
        clsCurrencyExchange CountryInfo = FindByCurrencyCode(Code);

        return (!CountryInfo.IsEmpty());
        
    }

     static vector<clsCurrencyExchange> GetAllCountriesInfo(){
        return  _LoadCountriesInfo(); 
     }

    float ExchangeCurrencyToDollar(float AmountToExchange){
        return AmountToExchange / _Rate;
    }

    float ExchangeCurrencyToCurrency(float AmountToExchange, clsCurrencyExchange CurrencyTo){
        
        return ExchangeCurrencyToDollar(AmountToExchange) * CurrencyTo.Rate();
    }

};