// Name: Boyuan Pang
// Course: CIS 006 Intro to programming 
// CRN: 30036 
// Date: 6/21/2024
// Assignment: Asterisks

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int asterisks; // number of asterisks to be printed
    char ans; // user answer to whether they wish to go again
    
    // loops program until user wishes to stop
    do
    {
         // getting the amount of asterisks
        cout << "how many asterisks should I print out?\n";
        cin >> asterisks;
        
        // printing out the asterisks
        for (int ast = 0; ast < asterisks; ast++)
            cout << "*";
        
        // detirmines whether program should repeat
        cout << endl << "Do you want to go again? y/n:\n";
        cin >> ans;
        
    } while (ans == 'y');
    
    return 0;
}