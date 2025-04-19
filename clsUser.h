#pragma once 

#include<iostream>
#include<fstream>
#include<vector>

#include "clsPersonne.h"
#include "clsString.h"
#include "Global.h"
#include "clsDate.h"
// #include "clsClient.h"

class clsUser : public clsPerson{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
    string _UserName;
    string _Password;
    bool _MarkDeleted = false;
    int _Permesions = -1;
    enMode _Mode;

    string  _LoginRecordLine(string sep="|"){
            string line = "";
            line += clsDate::TimeDateToString(clsDate()) + sep;
            line += UserName() + sep;
            line += Password() + sep;
            line += to_string(Permesions());
            return line;
        }

    static clsUser _ConvertLineToObject(string line, string sep="|"){
        vector<string> vSplitLine = clsString::Split(line,sep);
        return clsUser(enMode::UpdateMode, vSplitLine[0], vSplitLine[1], stoi(vSplitLine[2]), vSplitLine[3], vSplitLine[4], vSplitLine[5], vSplitLine[6]);
    }
    static string  _ConvertObjectToLine(clsUser User, string sep="|"){
        string line = "";
        line += User.UserName() + sep;
        line += User.Password() + sep;
        line += to_string(User.Permesions()) + sep;
        line += User.GetFirstName() + sep;
        line += User.GetLastName() + sep;
        line += User.GetEmail() + sep;
        line += User.GetPhone();

        return line;
    }

    static clsUser _EmptyClientObject(){
        return clsUser(enMode::EmptyMode, "", "", 0, "", "", "", "");
    }

static vector<clsUser> _LoadUsers(){
        vector<clsUser> vUsers;
        fstream file;

        file.open("users_data", ios::in);

        if(file.is_open()){

            string line;
            while(getline(file, line)){
                clsUser usr = clsUser::_ConvertLineToObject(line);
                vUsers.push_back(usr);
            }
        }
        
        file.close();

        return vUsers;
    }

    static void _saveCLients(vector<clsUser> vUsers){

        fstream file;

        file.open("users_data", ios::out);
        string UserLine;

        if(file.is_open()){
            
            for(clsUser usr : vUsers){
                if(usr.MarkDeleted() == false){
                    UserLine = _ConvertObjectToLine(usr);
                    file << UserLine << endl ;
            }
            }
            file.close();
        }
        
    }


    void _update(){
        
       vector<clsUser> _vUsers;
       _vUsers = _LoadUsers();

        for (clsUser& usr : _vUsers)
        {
            if(usr.UserName() == UserName()){

                usr = *this;
                break;
            }
        }
                
        _saveCLients(_vUsers);


    }

    void _AddNew(){
        _AddlineTofile(_ConvertObjectToLine(*this));
    }

    void _AddlineTofile(string  UsrLine, string FileName = "users_data"){
        
        fstream file;

        file.open(FileName, ios::out | ios::app);
        if(file.is_open()){
            file << UsrLine << endl;
            file.close();
        }
     } 

     

public:
    clsUser(enMode Mode, string UserName, string Password,int Permesions,
            string FirstName, string LastName, string Email, string Phone)
            : clsPerson( FirstName, LastName, Email, Phone)
    {
        
        _UserName = UserName;
        _Password = Password;
        _Mode = Mode;
        _Permesions = Permesions;
    }
string UserName(){
    return _UserName;
}

void SetUserName(string UserName){
     _UserName = UserName;
}

string Password(){
    return _Password;
}

void SetPassword(string Password){
     _Password = Password;
}

int Permesions(){
    return _Permesions;
}

void SetPermesions(int Permesions){
     _Permesions = Permesions;
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

static clsUser Find(string UserName){

        // vector<clsClient> clientObject;
        fstream file;
        file.open("users_data", ios::in);

        if(file.is_open()){
            string line;
            while (getline(file, line))
            {
                // cout << "the Line : " << line;
                clsUser User = _ConvertLineToObject(line);

                if (User.UserName() == UserName){

                    file.close();
                    return User;
                }
            }
        }
    
        return _EmptyClientObject();
    
    }

 static clsUser Find(string UserName, string Password){

        // vector<clsClient> clientObject;
        fstream file;
        file.open("users_data", ios::in);

        if(file.is_open()){

            string line;
            while (getline(file, line))
            {
                clsUser User = _ConvertLineToObject(line);

                if (User.UserName() == UserName && User.Password() == Password){

                    file.close();
                    return User;
                }
            }
        }
    
        return _EmptyClientObject();
    
    }

     static bool IsUserExist(string UserName){

        clsUser User = Find(UserName);

        return (!User.IsEmpty());
    }
    enum enSave  { SaveError= 0, SaveSuccessful = 1, saveAddError = 2};

    enSave save(){       

       switch (_Mode)
       {
       case   enMode::UpdateMode :

            _update();
            return enSave::SaveSuccessful;
        
        case enMode::AddNewMode:

            if(IsUserExist(_UserName))
                return enSave::saveAddError;

            else{
                _AddNew();
                return enSave::SaveSuccessful;
            }

       default:
            return enSave::SaveError;
       }

    }
    static clsUser GetNewClentObj(string UserName){
        return clsUser(enMode::AddNewMode,UserName,"",0,"", "","",""); 
    }

    bool Delete(){
        
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsers();
     
         for (clsUser& usr : _vUsers)
         {
             if(usr.UserName() == UserName()){
                usr.SetMarkDeleted(true);
                break;
             }
         }
         
         _saveCLients(_vUsers);

         *this = _EmptyClientObject();
         return true;
     }

      static vector<clsUser> GetAllUsers(){
        return  _LoadUsers(); 
     }

    enum enPermissions {pAll=-1, pShow=1, pAdd=2,
                         pDellete=4, pUpdate=8 , pFind=16,
                         pTransactions=32, pManageUsers=64, pShowLogins = 128,
                         CurrencyExchange = 256};

    bool CheckPermissions(enPermissions Permesions){

        if(Permesions == enPermissions::pAll)
            return true;

        if((Permesions & this->Permesions()) == Permesions)
            return true;

        return false;
    }

    void StoreLoginInfo(){
        _AddlineTofile(_LoginRecordLine(), "login_data");
    }

    
  
};
