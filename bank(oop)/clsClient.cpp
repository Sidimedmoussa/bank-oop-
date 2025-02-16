#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "clsString.h"
#include "clsPersonne.cpp"

class clsClient : public clsPerson{

private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };

    // enMode _Mode;
    int _Mode;
    string _AcountNumber;
    string _PinCode;
    float _AcountBalence;

    static clsClient _ConvertLineToObject(string line, string sep="|"){
        vector<string> vSplitLine = clsString::Split(line,sep);
        return clsClient(enMode::UpdateMode, vSplitLine[0], vSplitLine[1], stoi(vSplitLine[2]), vSplitLine[3], vSplitLine[4], vSplitLine[5], vSplitLine[6]);
    }
    static clsClient _EmptyClientObject(){
        return clsClient(enMode::EmptyMode, "", "", 0, "", "", "", "");
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

    bool IsEmpty(){
        return (_Mode == enMode::EmptyMode);
    }
   
    void Print(){

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << AcountNumber();
        cout << "\nPassword    : " << PinCode();
        cout << "\nBalance     : " << AcountBalence();
        cout << "\n___________________\n";

    }
   
    static clsClient Find(string AcountNumber){

        // vector<clsClient> clientObject;
        fstream file;
        file.open("client_data", ios::in);

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
   
    static void update(string AcountNumber){

        // load all the client in vector
        //   create load data func 
        
        // choose the client targeted and update his info

        // get back the all info into the file data 

    }



};