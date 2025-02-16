#include<iostream>
#include "clsClient.cpp"



using namespace std;

int main(){

  clsClient client = clsClient::Find("A777","1777");

  client.Print();

  cout << client.IsClientExist("A777");

    return 0;
}