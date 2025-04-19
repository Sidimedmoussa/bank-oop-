#pragma once
#include <iostream>
// #include "clsUser.h"
#include "Global.h"

using namespace std;

class clsSCreen
{
protected:
    
    static void _ScreenTitle(string Tile)
   {
    cout << "\n\t\t\t\t\t______________________________________________ \n"
         << endl;

    cout << "\t \t \t \t\t\t " << Tile << " Screen.";
    cout << "\n \t\t\t\t\t______________________________________________ \n"
         << endl;

    cout << "\n \t\t\t\t\t User: " << CurrentUser.UserName()  <<endl;
    cout << "\n \t\t\t\t\t Date  : " << clsDate::DateToString(clsDate()) << endl;
    
  }

  static void _CleanScreen(){
      #ifdef _WIN32
          system("cls");
      #elif __linux__
          system("clear");
      #elif __APPLE__
          std::cout << "Running on macOS\n";
      #else
          std::cout << "Unknown operating system\n";
      #endif
  }
  static void _PressToLeaveScreen(){
      #ifdef _WIN32
          system("pause");
      #elif __linux__
          system("read -p 'Press Enter to continue...' var");
      #elif __APPLE__
          std::cout << "Running on macOS\n";
      #else
          std::cout << "Unknown operating system\n";
      #endif
  }

    static bool GiveAcces(clsUser::enPermissions Permissions){

        if(!CurrentUser.CheckPermissions(Permissions)){
            cout << "\t\t\t\t\t---------------------------------------------"<< endl;
            cout << "\n\n\t\t\t\t\t Acces Denied, Please Contact You admin." <<endl;
            cout << "\n\t\t\t\t\t--------------------------------------------"<< endl;
            return false;
        }
            return true;
      
    }

};