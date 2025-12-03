#ifndef ACCOUNTACTION_H
#define ACCOUNTACTION_H

class Investment
{
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_years;
    char m_userChoice = 'y';

public:
    Investment(double t_initial, double t_monthly, double t_annual, int t_years);

    void mainMenu(); // Display main menu and get user input
    void calculateWithoutDeposits(); // Calculate without monthly deposits
    void calculateWithDeposits(); // Calculate with monthly deposits

private:
    void calculate(double t_monthlyDeposit); // Core calculation logic
};

#endif
