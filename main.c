#include "myBank.h"
#include <stdio.h>

int main(){
    init();
    int accountId;
    double amount;
    int interest;
    for (char c=0; c!='E' ;)
    {
        printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        int flag;

        flag=scanf(" %c",&c);//read char ignore white spaces
        if(flag==EOF)break;
        if(flag!=1){
            printf("ilegal input\n");
            continue;
        }
        if(c=='P'){ 
            printBank();
            continue;
        }
        if(c=='E'){ init(); continue;}//will end for
        
        if(c=='I'){
            printf("Please enter interest rate: ");

            if(scanf("%d",&interest)!=1){
                printf("Failed to read the interest rate\n");
            }
            else if(!interst(interest)){
                printf("Invalid interest rate\n");
            }
            continue;
            }

        if(c=='O'){
            accountId=openAccount();//0 is returned if not able to open
            if(!accountId){
                printf("sorry bank is at capacity.\n");
                continue;
            }
            printf("Please enter amount for deposit: ");
            if(scanf("%lf",&amount)!=1)
                printf("Failed to read the amount\n");

            else if(add(accountId, amount)){
                printf("New account number is: %d \n",accountId);
                continue;
            }
            else printf("Invalid Amount\n");

            close(accountId);
            continue;
        }
        if(c=='D'||c=='W'||c=='C'||c=='B'){

            printf("Please enter account number: ");
            
            if(scanf("%int",&accountId)!=1){
                printf("Failed to read the account number\n");
                continue;
            }
            
            if(!isValid(accountId)){
                printf("Invalid account number\n");
                continue;
            }
            
            if(c=='C'){
                if(isOpen(accountId)){
                    close(accountId);
                    printf("Closed account number %d\n",accountId);
                }
                else printf("This account is already closed\n"); 
            
                continue;
            }
            
            if(!isOpen(accountId)){
                printf("This account is closed\n");
                continue;
            }
                
            if(c=='B'){
                printBalance(accountId);
                continue;
            }
            if(c=='W'){
                printf("Please enter the amount to withdraw: ");
                if(scanf("%lf",&amount)!=1){
                    printf("Failed to read the amount\n");
                    continue;
                }
                if(withdrawal(accountId, amount)){
                    printf("The new balance is: %.2f\n",getBalance(accountId));
                    continue;
                }
                if(amount<0) printf("Invalid Amount\n"); 
                else printf("Cannot withdraw more than the balance\n");
                continue;
            }
            //D
            printf("Please enter the amount to deposit: ");
            if(scanf("%lf",&amount)!=1){
                printf("Failed to read the amount\n");
                continue;
            }
            if(add(accountId, amount))
                printf("The new balance is: %.2f\n",getBalance(accountId));
            else printf("Cannot deposit a negative amount\n");
            continue;
        }
        printf("Invalid transaction type\n");  
    }
}