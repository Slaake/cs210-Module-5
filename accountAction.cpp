#include "accountAction.h"
#include <iostream>
#include <iomanip>
using namespace std;

Investment::Investment(double t_initial, double t_monthly, double t_annual, int t_years) // Constructor
{
    m_initialInvestment = t_initial;
    m_monthlyDeposit = t_monthly;
    m_annualInterest = t_annual;
    m_years = t_years;
}

void Investment::calculateWithoutDeposits() // Calculate without monthly deposits
{
    cout << "\nBalance and Interest Without Additional Monthly Deposits:\n";
    calculate(0); // No monthly deposits
}

void Investment::calculateWithDeposits() // Calculate with monthly deposits
{
    cout << "\nBalance and Interest With Additional $" << m_monthlyDeposit << " Monthly Deposits:\n";
    calculate(m_monthlyDeposit); // With monthly deposits
}

void Investment::calculate(double t_monthlyDeposit) // Core calculation logic
{
    double balance = m_initialInvestment;

    cout << "----------------------------------------------------------\n";
    cout << "|Year|\t  |Year End Balance|\t|Year End Interest Earned|\n";
    cout << "----------------------------------------------------------\n";

    for (int year = 1; year <= m_years; ++year) // Loop through each year
    {
        double yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month)
        {
            double total = balance + t_monthlyDeposit;
            double interest = total * (m_annualInterest / 100.0 / 12.0);
            balance = total + interest;
            yearlyInterest += interest;
        }
        // Display year-end results in a formatted table
        cout << " " << setw(2) << year << setw(12) << "$" << fixed << setprecision(2) << balance << setw(15) << "$" << yearlyInterest << endl;
    }
}

void Investment::mainMenu() // Display main menu and get user input
{
    cout << "What is the starting amount of your investment: $";
    cin >> m_initialInvestment;
    while (cin.fail() || m_initialInvestment < 0) // Input validation for initial investment
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT! Please enter a non-negative number for the initial investment." << endl;
        cout << "What is the starting amount of your investment: $";
        cin >> m_initialInvestment;
    }
    cout << "What is the amount you plan to contribute to the growth of your investment each month: $";
    cin >> m_monthlyDeposit;
    while (cin.fail() || m_monthlyDeposit < 0) // Input validation for monthly deposit
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT! Please enter a non-negative number for the monthly deposit." << endl;
        cout << "What is the amount you plan to contribute to the growth of your investment each month: $";
        cin >> m_monthlyDeposit;
    }
    cout << "What is the interest rate that is added to the principal sum of your investment and its previously accumulated interest (%): ";
    cin >> m_annualInterest;
    while (cin.fail() || m_annualInterest < 0) // Input validation for annual interest
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT! Please enter a non-negative number for the annual interest rate." << endl;
        cout << "Interest rate that is added to the principal sum of your investment and its previously accumulated interest (%): ";
        cin >> m_annualInterest;
    }
    cout << "What is the number of years your investment has to grow: ";
    cin >> m_years;
    while (cin.fail() || m_years <= 0) // Input validation for number of years
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT! Please enter a positive number for the number of years." << endl;
        cout << "What is the number of years your investment has to grow: ";
        cin >> m_years;
    }
    cout << endl;
    cout << "\t==================================" << endl;
    cout << "\t|   - - -> Data Entered <- - -   |" << endl;
    cout << "\t==================================" << endl;
    cout << "Initial Investment: $" << fixed << setprecision(2) << m_initialInvestment << endl;
    cout << "Monthly Deposit: $" << fixed << setprecision(2) << m_monthlyDeposit << endl;
    cout << "Annual Interest: " << fixed << setprecision(2) << m_annualInterest << "%" << endl;
    cout << "Number of Years: " << m_years << endl;
    cout << endl;
    cout << "Press ENTER to continue to calculate your investment..." << endl;
    cin.ignore();
    cin.get();
}
