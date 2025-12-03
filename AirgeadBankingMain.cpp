// Created by Shirl Lakeway
// Created on November 25, 2025
// CS-210 Project 5-3 Airgead Banking

#include <iostream>
#include <iomanip>
#include "accountAction.h"
using namespace std;

int main()
{
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int years;
    char m_userChoice = 'y'; // Used for main loop control

    Investment inv(initialInvestment, monthlyDeposit, annualInterest, years); // Create Investment object

    cout << "\t==================================" << endl;
    cout << "\t|   Airgead Banking Calculator   |" << endl;
    cout << "\t==================================" << endl;
    while (m_userChoice == 'y' || m_userChoice == 'Y') { // Main loop for repeated calculations
    inv.mainMenu(); // Display menu and get user input
    inv.calculateWithoutDeposits(); // Calculate and display without deposits
    inv.calculateWithDeposits(); // Calculate and display with deposits
    cout << "\nWould you like to run another calculation? (y/n): ";
    cin >> m_userChoice;
    while (m_userChoice != 'y' && m_userChoice != 'Y' && m_userChoice != 'n' && m_userChoice != 'N') { // Input validation
        cout << "INVALID INPUT! Please enter 'y/Y' for yes or 'n/N' for no: ";
        cin >> m_userChoice;
    }
    cout << endl;
    }
    
    cout << "\t==============================================" << endl;
    cout << "\t|              Thank you                     |" << endl;
    cout << "\t|  for using the Airgead Banking Calculator! |" << endl;
    cout << "\t==============================================" << endl;

    return 0;
}
