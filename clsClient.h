#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "clsString.h"
#include "clsPersonne.h"
#include "clsUser.h"
#include "Global.h"

class clsClient : public clsPerson{

private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};

    // enMode _Mode;
    int _Mode;
    string _AcountNumber;
    string _PinCode;
    float _AcountBalence;
    bool _MarkDeleted = false;

    static clsClient _ConvertLineToObject(string line, string sep="|"){
        vector<string> vSplitLine = clsString::Split(line,sep);
        return clsClient(enMode::UpdateMode, vSplitLine[0], vSplitLine[1], stoi(vSplitLine[2]), vSplitLine[3], vSplitLine[4], vSplitLine[5], vSplitLine[6]);
    }

    static string  _ConvertObjectToLine(clsClient client, string sep="|"){
        string line = "";
        line += client.AcountNumber() + sep;
        line += client.PinCode() + sep;
        line += to_string(client.AcountBalence()) + sep;
        line += client.GetFirstName() + sep;
        line += client.GetLastName() + sep;
        line += client.GetEmail() + sep;
        line += client.GetPhone();

        return line;
    }
    static clsClient _EmptyClientObject(){
        return clsClient(enMode::EmptyMode, "", "", 0, "", "", "", "");
    }

    static vector<clsClient> _LoadClient(){
        vector<clsClient> vClients;
        fstream file;

        file.open("client_data.txt", ios::in);

        if(file.is_open()){

            string line;
            while(getline(file, line)){
                clsClient client = clsClient::_ConvertLineToObject(line);
                vClients.push_back(client);
            }
        }
        
        file.close();

        return vClients;
    }

   static void _saveCLients(vector<clsClient> vClients){

        fstream file;

        file.open("client_data.txt", ios::out);
        string clientLine;

        if(file.is_open()){
            
            for(clsClient cl : vClients){
                if(cl.MarkDeleted() == false){
                    clientLine = _ConvertObjectToLine(cl);
                    file << clientLine << endl ;
                }
            }
            file.close();
        }
        
    }

    void _update(){
        
       vector<clsClient> _vClients;
       _vClients = _LoadClient();

        for (clsClient& cl : _vClients)
        {
            
            if(cl.AcountNumber() == AcountNumber()){
            
                cl = *this;
                break;
            }
        }        
        _saveCLients(_vClients);


    }

     void _AddNew(){
        _AddlineTofile(_ConvertObjectToLine(*this));
    }

     void _AddlineTofile(string  ClientLine, string FileName = "client_data"){
        
        fstream file;

        file.open(FileName, ios::out | ios::app);
        if(file.is_open()){
            file << ClientLine << endl;
            file.close();
        }
        
    }
     string  _TransferRecordLine(float Ammount, clsClient Receiver,clsUser currentUser, string sep="|"){
            string line = "";
            line += clsDate::TimeDateToString(clsDate()) + sep;
            line += AcountNumber() + sep;
            line += Receiver.AcountNumber() + sep;
            line += to_string(Ammount) + sep;
            line += to_string(AcountBalence()) + sep;
            line += to_string(Receiver.AcountBalence()) + sep;
            line += currentUser.UserName();
            return line;
        }
    void StoreTransferInfo(float Ammount, clsClient Receiver, clsUser currentUser){
        _AddlineTofile(_TransferRecordLine(Ammount, Receiver, currentUser), "transfer_data");
    }

    public:
    clsClient (int Mode, string AcountNumber, string PinCode, float AcountBalence, string FirstName, string LastName, string Email, string Phone)
    : clsPerson ( FirstName,  LastName,  Email,  Phone)
    {

        _Mode = Mode;
        _AcountNumber = AcountNumber;
        _PinCode = PinCode;
        _AcountBalence = AcountBalence;
    }

    string AcountNumber(){
        return _AcountNumber;
    }
    string PinCode(){
        return _PinCode;
    }

    void SetPinCode(string PinCode){
        _PinCode = PinCode;
    }
    float AcountBalence(){
        return _AcountBalence;
    }

    void SetAcountBalence(float AcountBalence){
        _AcountBalence = AcountBalence;
    }

    bool MarkDeleted(){
        return _MarkDeleted;
    }
    void SetMarkDeleted(bool MarkDeleted){
        _MarkDeleted = MarkDeleted;
    }
   
    bool IsEmpty(){
        return (_Mode == enMode::EmptyMode);
    }
   
    // void Print(){

    //     cout << "\nClient Card:";
    //     cout << "\n___________________";
    //     cout << "\nFirstName   : " << GetFirstName();
    //     cout << "\nLastName    : " << GetLastName();
    //     cout << "\nFull Name   : " << FullName();
    //     cout << "\nEmail       : " << GetEmail();
    //     cout << "\nPhone       : " << GetPhone();
    //     cout << "\nAcc. Number : " << AcountNumber();
    //     cout << "\nPassword    : " << PinCode();
    //     cout << "\nBalance     : " << AcountBalence();
    //     cout << "\n___________________\n";

    // }
   
    static clsClient Find(string AcountNumber){

        // vector<clsClient> clientObject;
        fstream file;
        file.open("client_data.txt", ios::in);

        if(file.is_open()){

            string line;
            while (getline(file, line))
            {
                clsClient client = _ConvertLineToObject(line);

                if (client.AcountNumber() == AcountNumber){

                    file.close();
                    return client;
                }
            }
        }
    
        return _EmptyClientObject();
    
    }

    static clsClient Find(string AcountNumber, string PinCode){

        // vector<clsClient> clientObject;
        fstream file;
        file.open("client_data", ios::in);

        if(file.is_open()){

            string line;
            while (getline(file, line))
            {
                clsClient client = _ConvertLineToObject(line);

                if (client.AcountNumber() == AcountNumber && client.PinCode() == PinCode){

                    file.close();
                    return client;
                }
            }
        }
    
        return _EmptyClientObject();
    
    }

    static bool IsClientExist(string AcountNumber){

        clsClient client = Find(AcountNumber);

        return (!client.IsEmpty());
    }
    
    enum enSave  { SaveError= 0, SaveSuccessful = 1, saveAddError = 2};

    enSave save(){       

       switch (_Mode)
       {
       case   enMode::UpdateMode :
            _update();
            return enSave::SaveSuccessful;
        
        case enMode::AddNewMode:

            if(IsClientExist(_AcountNumber))
                return enSave::saveAddError;

            else{
                _AddNew();
                return enSave::SaveSuccessful;
            }

       default:
            return enSave::SaveError;
       }

    }

    
    static clsClient GetNewClentObj(string AccountNumber){
        return clsClient(enMode::AddNewMode,AccountNumber,"",0,"", "","",""); 
    }

    bool Delete(){
        
        vector<clsClient> _vClients;
        _vClients = _LoadClient();
     
         for (clsClient& cl : _vClients)
         {
             if(cl.AcountNumber() == AcountNumber()){
                cl.SetMarkDeleted(true);
                break;
             }
         }
         
         _saveCLients(_vClients);

         *this = _EmptyClientObject();
         return true;
     }

     static vector<clsClient> GetAllClient(){
        return  _LoadClient(); 
     }

     static double TotalBalance(){
        vector<clsClient> vClients =  _LoadClient();

        double TotalBalence = 0;

        for(clsClient client : vClients)
          TotalBalence += client.AcountBalence();

        return TotalBalence;
     }

    void Deposit(float DepositAmmount){
        cout << "\nMode: " << _Mode << endl;
        _AcountBalence += DepositAmmount;

        save();
     }

    void Withdraw(float WithdrawAmmount){

        _AcountBalence -= WithdrawAmmount;
        save();
     }

     bool SendAmount(clsClient &ClientReceiver, float Amount){
        if(AcountBalence() < Amount)
            return false;
        
        Withdraw(Amount);
        ClientReceiver.Deposit(Amount);
        // _TransferRecordLine(Amount,ClientReceiver,CurrentUser);

        StoreTransferInfo(Amount, ClientReceiver, CurrentUser);
        return true;
    }  


};