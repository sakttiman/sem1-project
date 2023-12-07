#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
char name[20];
int dip_amt, amt = 0, acc_no, ac, count = 0; // Global variables
int trans_amt;
int with_amt;
/*-----------------------------------------------------------------------------*/
void divider()
{
int i;
for( i= 0; i <50; i++)
{
printf("-");
}
}
/*-----------------------------------------------------------------------------*/
void deposit_money()
{
time_t tm;
time(&tm);
FILE *ptr = fopen("Account.txt", "a");
printf("*****DEPOSITING MONEY*****\n");
int i;
for(i = 0; i < 50; i++)
{
printf("-");
}
printf("\nEnter the amount you want to deposit\n");
scanf("%d", &dip_amt);
amt += dip_amt;
printf("****Money Deposited****\n");
printf("Now balance : %d\n", amt);
fprintf(ptr, "\nRs%d had been deposited to your account \n", dip_amt);
fprintf(ptr, "Date/Time of transaction : %s\n", ctime(&tm));
count++;
fclose(ptr);
printf("Press any key....\n");
}
/*-------------------------------------------------------------------------*/
void withdraw_money()
{
time_t tm;
time(&tm);
FILE *ptr = fopen("Account.txt", "a");
printf("*****WITHDRAWING MONEY*****\n");
int i;
for (i = 0; i < 50; i++)
{
printf("-");
}
printf("\nEnter the amount you want to withdraw\n");
scanf("%d", &with_amt);
if (amt < with_amt)
{
printf("****Insufficient balance****\n");
}
else
{
amt = amt - with_amt;
printf("*****Money withdrawn*****\n");
printf("Current balance : %d\n", amt);
fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
fprintf(ptr, "Date/Time of transaction : %s\n", ctime(&tm));
count++;
}
fclose(ptr);
printf("Press any key....\n");
}

/*-------------------------------------------------------------------------*/
void checkDetail()
{
printf("ACCOUNT DETAILS\n");
int i;
for ( i = 0; i < 50; i++)
{
printf("-");
}
printf("\nName : %s\n", name);
printf("Account No. : %d\n", acc_no);
printf("Total balance = %d\n ", amt);
printf("\n%d transactions have been made from your account \n", count);
printf("Press any key.....");

}

/*-------------------------------------------------------------------------*/
void LastDetail()
{
printf("ACCOUNT DETAILS\n");
int i;
for (i = 0; i < 50; i++)
{
printf("-");
}
printf("\nName : %s\n", name);
printf("Account No. : %d\n", acc_no);
printf("Total balance = %d\n ", amt);
printf("\n\nPress any key to exit.....");
}

/*----------------------------------------------------------------------------*/
void menu()
{
system("cls");
divider();
printf("\n\tMENU\n");
divider();
printf("\n1.Deposit Money\n");
printf("2.Withdraw Money\n");
printf("3.Account details\n");
printf("4.Exit\n");
divider();
}
/*------------------------------------------------------------------------------*/
void fun(){
    FILE *ptr = fopen("Account.txt", "w");
int choice;
printf("Enter your name : \n");
gets(name);
gets(name);
fprintf(ptr, "\nName : %s\n", name);
printf("Enter your account no. : ");
scanf("%d", &acc_no);
fprintf(ptr, "Account no. : %d\n", acc_no);
fclose(ptr);
while (1)
{
menu();
printf("\nEnter your choice :\n");
scanf("%d", &choice);
switch (choice)
{
case 1:
system("cls");
deposit_money();
break;
case 2:
system("cls");
withdraw_money();
break;
case 3:
system("cls");
checkDetail();
case 4:
system("cls");
LastDetail();
exit(0);
default:
printf("*****Invalid choice*****");
}
}
}
/*--------------------------------------------------------------------------*/
int newacc(){
printf("welcome to the customers current account\n");
fun();
return 0;
}
/*-------------------------------------------------------------------*/
int loginacc(){
printf("welcome to the customers current account\n");
fun();
return 0;
}
/*-------------------------------------------------------------------*/
int  Admi_sav(){
system("cls");
printf("choose the type: \n");
printf("1. create new account\n");
printf("2. login existing account\n");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
system("cls");
newacc();
break;
case 2:
system("cls");
loginacc();
break;
default:
printf("invalid choice");
}
return 0;
}
/*------------------------------------------------------------*/
int Admi_curr(){
system("cls");
printf("choose the type: \n");
printf("1. create new account\n");
printf("2. login existing account\n");
int choice;
scanf("%d",&choice);
switch(choice){
case 1:
system("cls");
newacc();
break;
case 2:
system("cls");
loginacc();
break;
default:
printf("invalid choice");
}
return 0;
}
/*---------------------------------------------------------------------*/
int Cus_sav(){
system("cls");
printf("welcome to the customers saving account\n");
fun();
return 0;
}
/*---------------------------------------------------------------------*/
int Cus_curr(){
system("cls");
printf("welcome to the customers current account\n");
fun();
return 0;
}
/*--------------------------------------------------------------------*/
void curr_acc(){
    system("cls");
    int acc_right;
    again:
    printf("welcome to the current account\n");
    printf("choose the option:\n");
    printf("1. Administrative Rights \t\t 2. Customer Rights\n");
    scanf("%d",&acc_right);
    if(acc_right==1){
        Admi_curr();
    }
    else if(acc_right==2){
        Cus_curr();
    }
    else{
        printf("you choose the wrong option please try again");
        goto again;
    }
}
/*------------------------------------------------------------------------*/
void sav_acc(){
    system("cls");
    int acc_right;
    again:
    printf("welcome to the saving account\n");
    printf("choose the option:\n");
    printf("1. Administrative Rights \t\t 2. Customer Rights\n");
    scanf("%d",&acc_right);
     if(acc_right==1){
        Admi_sav();
    }
    else if(acc_right==2){
        Cus_sav();
    }
    else{
        printf("you choose the wrong option please try again");
        goto again;
    }
}
/*-----------------------------------------------------------------------*/
int main(){
    system("cls");
int acc_ty;
again:
printf("Choose the type of account:\n");
printf("1. saving account\n");
printf("2. current account\n");
scanf("%d",&acc_ty);
if(acc_ty==1){
    sav_acc();
}
else if(acc_ty==2){
    curr_acc();
}
else{
    printf("you choose the wrong option please try again");
    goto again;
}
return 0;
}
/*----------------------------------------------------------------------*/

