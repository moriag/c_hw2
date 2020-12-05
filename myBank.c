#define baseId 901
#define bankSize 50
#include <stdio.h>
enum{status,balance,next};
int addNext=0;
double bank[bankSize][3];
void init(){
    for (int i = 0; i < bankSize; i++)
        {
        bank[i][next]=i+1;
        bank[i][balance]=0;
        bank[i][status]=0;
        }
}
int isOpen(int account){
    account-=baseId;
    if(bank[account][status]==0) return 0;
        
   
    return 1;
}
int isValid(int account){
    account-=baseId;
    if( (account>bankSize-1) || (0>account)) return 0;
    
    return 1;
}
int openAccount(){
    if(addNext==bankSize){
        return 0;
    }
    bank[addNext][status]=1;
    int account=addNext+baseId;
    addNext=bank[addNext][next];
    return account;
}
double getBalance(int account){
    return bank[account-baseId][balance];
}
void changeBalance(int account,double amount){
    amount=(int)(amount*100);
    amount/=100;
    bank[account][balance]+=amount;
    
}
int add(int account,double amount){
    
    if(amount<0)return 0;

    changeBalance(account-baseId,amount);
    return 1;
}
int withdrawal(int account, double amount){
    account-=baseId;

    if(amount<0) return 0;
    
    if(bank[account][balance]<amount){
        return 0;}
    
    changeBalance(account,-amount);
    return 1;
}
int interst(double amount){
    if (amount<0) return 0;
    for (size_t i = 0; i < bankSize; i++)
        { 
            bank[i][balance]=(int)(100*(bank[i][balance]*(1+(amount/100))));
            bank[i][balance]/=100;
        }
    return 1;
}
void close(int account){
    account-=baseId;
    bank[account][status]=0;
    bank[account][balance]=0;
    bank[account][next]=addNext;
    addNext=account;
}


void printBalance(int account){
            printf("The balance of account number %i is: %.2f\n",account, bank[account-baseId][balance]);
}
void printBank(){
    if(addNext==0)return;
    
    for (int i = 0; i < bankSize; i++)
        {
            if(bank[i][status]==0)continue;
            printBalance(i+baseId);
        }
       
}