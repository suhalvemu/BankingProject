//
//  Account.h
//  BankingProject
//
//  Created by Suhal Vemu on 13/04/20.
//  Copyright © 2020 Suhal Vemu. All rights reserved.
//

#ifndef Account_h
#define Account_h

#include "Error.h"
#define MIN_BALANCE 500;
#include <fstream>
#include <string.h>
#include<iostream>
using namespace std;

class Account{
private:
    long accountNumber;
    string firstName;
    string lastName;
    double balance;
    static long nextAccountNumber;
public:
    Account(){};
    Account(string firstName,string lastName,double balance){
        nextAccountNumber++;
        setFirstName(firstName);
        setLastName(lastName);
        setBalance(balance);
        accountNumber=nextAccountNumber;
    }
    
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setBalance(double balance);
    
    long getAccountNumber(){ return  accountNumber;}
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    double getBalance(){return balance;}
    
    void deposit(double amount);
    void withDraw(double amount);
    
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    
    friend ofstream & operator<<(ofstream &ofs, Account &acc);
    friend ifstream & operator>>(ifstream &ifs, Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
    
};


long Account::nextAccountNumber=1;

void Account::setFirstName(string firstName){
    if(firstName!="")
        this->firstName=firstName;
    else throw NameError();
}

void Account::setLastName(string lastName){
    this->lastName=lastName;
}

void Account::setBalance(double balance){
    if(balance<500){
        cout<<"Minimum Balance To Open an Account is 500 Rupees"<<endl;
    }
    this->balance=balance;
}

void Account::deposit(double amount){
    balance +=amount;
}

void Account::withDraw(double amount){
    if(balance - amount<500)
        throw insufficentFunds();
    balance -=amount;
}

void Account::setLastAccountNumber(long accountNumber){
    nextAccountNumber=accountNumber;
}

long Account::getLastAccountNumber(){
    return nextAccountNumber;
}

ofstream & operator<<(ofstream &ofs, Account &acc){
    ofs<<acc.accountNumber<<endl;
    ofs<<acc.firstName<<endl;
    ofs<<acc.lastName<<endl;
    ofs<<acc.balance<<endl;
    return ofs;
}


ifstream & operator>>(ifstream &ifs,Account &acc){
    ifs>>acc.accountNumber;
    ifs>>acc.firstName;
    ifs>>acc.lastName;
    ifs>>acc.balance;
    return ifs;
}

ostream & operator<<(ostream &os,Account &acc){
    os<<"First Name:"<<acc.getFirstName()<<endl;
    os<<"Last Name:"<<acc.getLastName()<<endl;
    os<<"Account Number:"<<acc.getAccountNumber()<<endl;
    os<<"Balance:"<<acc.getBalance()<<endl;
    return os;
}

#endif /* Account_h */
