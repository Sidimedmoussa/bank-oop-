#pragma once
#include <iostream>
using namespace std;


 class  clsSCreen{
protected:
    static void _ScreenTitle(string Tile){
    cout << "\n\t\t\t\t\t______________________________________________ \n" << endl;

      cout << "\t \t \t \t\t\t " << Tile << " Screen.";
      cout << "\n \t\t\t\t\t______________________________________________ \n" << endl;



    }

};