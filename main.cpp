#include<iostream>
#include<iomanip>
#include "clsLoginScreen.h"

using namespace std;


int main(){
  clsShowCurrenciesScreen::ListCurrencies();
  while (true)
  {
    if(!clsLoginScreen::LoginScreen())
        break;
  }
    
  return 0;
}