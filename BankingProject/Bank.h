//
//  Bank.h
//  BankingProject
//
//  Created by Suhal Vemu on 13/04/20.
//  Copyright © 2020 Suhal Vemu. All rights reserved.
//

#ifndef Bank_h
#define Bank_h
#include <vector>
#include <map>
#include "Account.h"
#include <fstream>
#include <cstdlib>

#define FILELOC "../Bank.data"

class Bank{
private:
    map<long,Account>  accounts;
public:
    Bank();
    Account OpenAccount(string fname,string lname,double balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber,double amount);
    Account WithDraw(long accountNumber,double amount);
    void CloseAccount(long accountNumber);
    void showAllAccounts();
    ~Bank();
};


Bank::Bank(){
    try{
        Account account;
        ifstream infile;
        
        infile.open(FILELOC);
        
        if(!infile){
            cout<<"Error in Opening! File Not Found!"<<endl;
            return ;
        }
        while(!infile.eof()){
            infile>>account;
            accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
        }
        Account::setLastAccountNumber(account.getAccountNumber());
            infile.close();
        
    }
    catch(...){
        cout<<"Exception Occured!!"<<endl;
    }
}


Account Bank::OpenAccount(string fname,string lname, double balance){
    ofstream outfile;
    Account account(fname,lname,balance);
    accounts.insert(pair<long,Account>(account.getAccountNumber(),account));
    outfile.open(FILELOC,ios::trunc);
    
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::BalanceEnquiry(long accountNumber){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    return itr->second;
}

Account Bank::Deposit(long accountNumber,double amount){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    itr->second.deposit(amount);
    return itr->second;
}

Account Bank::WithDraw(long accountNumber,double amount){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    itr->second.withDraw(amount);
    return itr->second;
}

void Bank::CloseAccount(long accountNumber){
    map<long,Account>::iterator itr=accounts.find(accountNumber);
    cout<<"Account Deleted"<<itr->second;
    accounts.erase(accountNumber);
}

void Bank::showAllAccounts(){
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
        
    }
}

Bank::~Bank(){
    ofstream outfile;
    outfile.open(FILELOC,ios::trunc);
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        outfile<<itr->second;
    }
    outfile.close();
}

#endif /* Bank_h */
