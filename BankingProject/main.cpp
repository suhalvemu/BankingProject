//
//  main.cpp
//  BankingProject
//
//  Created by Suhal Vemu on 13/04/20.
//  Copyright © 2020 Suhal Vemu. All rights reserved.
//



#include <iostream>
#include "Account.h"
#include "Bank.h"
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    Bank b;
    Account acc;
    int choice;
    string fname,lname;
    long accountNumber;
    float balance;
    float amount;
    cout<<"********Banking System*******"<<endl;
    do{
        cout<<"\n\tSelect one option below ";
        cout<<"\n\t1 Open an Account";
        cout<<"\n\t2 Balance Enquiry";
        cout<<"\n\t3 Deposit";
        cout<<"\n\t4 Withdrawal";
        cout<<"\n\t5 Close an Account";
        cout<<"\n\t6 Show All Accounts";
        cout<<"\n\t7 Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                    cout<<"Enter First Name:";
                    cin>>fname;
                    cout<<"Enter Last Name:";
                    cin>>lname;
                    cout<<"Enter Initial Balance:";
                    cin>>balance;
                    acc=b.OpenAccount(fname, lname, balance);
                    cout<<acc;
                    break;
            case 2:
                    cout<<"Enter the Account Number:";
                    cin>>accountNumber;
                    acc=b.BalanceEnquiry(accountNumber);
                    cout<<endl<<"Your Account Details"<<endl;
                    cout<<acc;
                    break;
            case 3:
                    cout<<"Enter Account Number:";
                    cin>>accountNumber;
                    cout<<"Enter Balance:";
                    cin>>amount;
                    acc=b.Deposit(accountNumber, amount);
                    cout<<endl<<"Amount is Deposited"<<endl;
                    cout<<acc;
                    break;
            case 4:
                    cout<<"Enter Account Number:";
                    cin>>accountNumber;
                    cout<<"Enter Balance:";
                    cin>>amount;
                    acc=b.WithDraw(accountNumber, amount);
                    cout<<endl<<"Amount Withdrawn"<<endl;
                    cout<<acc;
                    break;
            case 5:
                    cout<<"Enter Account Number:";
                    cin>>accountNumber;
                    b.CloseAccount(accountNumber);
                    cout<<endl<<"Account is Closed"<<endl;
                    cout<<acc;
                    break;
            case 6:
                    b.showAllAccounts();
                    break;
            case 7:
                    break;;
            default:
                    cout<<"\n Enter correct choice";
                    exit(0);
                    break;
        }
    }while (choice!=7);
    
    return 0;
}
