#include<iostream>
#include<iomanip>
// #include "clsClient.cpp"
// #include "clsInputValidate.h"
// #include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;

void ReadClientInfo(clsClient& client){

  cout << "First Name: " << endl;
  client.SetFirstName(clsInputValidate::ReadString());

  cout << "Last Name: " << endl;
  client.SetLastName(clsInputValidate::ReadString());

  cout << "Email: " << endl;
  client.SetEmail(clsInputValidate::ReadString());

  cout << "Phone Number: " << endl;
  client.SetPhone(clsInputValidate::ReadString());

  cout << "Pin Code " << endl;
  client.SetPinCode(clsInputValidate::ReadString());

  cout << "Account Balence:  " << endl;
  client.SetAcountBalence(clsInputValidate::ReadFloatNumber());


}

static void updateClient(){


  cout << "Enter The Account Number: " << endl;

   string AccountNumber = clsInputValidate::ReadString();
  
  while(!clsClient::IsClientExist(AccountNumber)){

    cout << "Client Not exist, please Enter The Account Number Again: " << endl;

    AccountNumber = clsInputValidate::ReadString();

  }

  clsClient client = clsClient::Find(AccountNumber);

   client.Print();


   cout << "\n\nUpdate Client info: \n" << endl;
   cout << "\n______________________ \n" << endl;

   ReadClientInfo(client);
   cout << "\n______________________ \n" << endl;
  
   clsClient::enSave SaveResult;
   SaveResult = client.save();
  
   switch (SaveResult)
   {
   case clsClient::enSave::SaveSuccessful:
    
      cout << "\nAccound updated succfully:) " << endl;
      client.Print();

    break;
   
   case clsClient::enSave::SaveError:
    cout << "\n Error: Client Was Not Updated , it's Empty \n" << endl;
    
    break;
   }
}

 void AddNewClient(){
   
      cout << "Enter The Account Number: " << endl;

      string AccountNumber = clsInputValidate::ReadString();
   
    while( clsClient::IsClientExist(AccountNumber)){

      cout << "Client is exist, please Enter an other Account Number Again: " << endl;

      AccountNumber = clsInputValidate::ReadString();

    }
 
    clsClient NewClient = clsClient::GetNewClentObj(AccountNumber);

    ReadClientInfo(NewClient);

    clsClient::enSave SaveResult = NewClient.save();

    switch (SaveResult)
    {
    case clsClient::enSave::SaveSuccessful:
      
       cout << "\nAccound Added succfully:) " << endl;
       NewClient.Print();
 
     break;
    
    case clsClient::enSave::SaveError:
     cout << "\n Error: Client Was Not Added , it's already exist. \n" << endl;
     
     break;
    }
 }



 static void DeleteClient(){


  cout << "Enter The Account Number: " << endl;

   string AccountNumber = clsInputValidate::ReadString();
  
  while(!clsClient::IsClientExist(AccountNumber)){

    cout << "Client Not exist, please Enter The Account Number Again: " << endl;

    AccountNumber = clsInputValidate::ReadString();

  }

  clsClient client = clsClient::Find(AccountNumber);

   client.Print();


   cout << "\n\n Do you realy want to delete this client? y/n \n" << endl;
   string do_delete = clsInputValidate::ReadString();
    if( do_delete == "y"){

      if (client.Delete()){

          cout << "\n Client is deleted successfuly."<< endl;
          client.Print();
        }
      else 
        cout << "sorry Client not deleted" << endl;
    }
   
}





void printClientBalanceRecord(clsClient client){
    cout << "| " << left << setw(15) << client.AcountNumber();
    cout << "| " << left << setw(40) << client.FullName();
    cout << "| " << left << setw(12) << client.AcountBalence();
    cout << endl;
}
void ListAllBalence(){

        vector<clsClient> vClientsList = clsClient::GetAllClient();
        double TotalBalance = clsClient::TotalBalance();

        cout << "\t\t\t\t Client List ( " << vClientsList.size() << " ) Client(s)" << endl;

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        for(clsClient client : vClientsList){
          printClientBalanceRecord(client);
           
        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t\t\t Total Balance: " << TotalBalance << endl;
        cout << "\t\t\t\t (" << clsUtil::NumberToText(TotalBalance) << ")" << endl;

}




int main(){

 
  clsMainScreen::MainScreen();

    return 0;
}