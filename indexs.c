#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
//CREATE STRUCTURE FOR STORE BANK ALL INFORMATION
typedef struct bank{
float balance;
char name[100];
char account_number[20];
char password[100];
char phone_number[20];
char full_address[200];
char pen_number[20];
char aadhar[20];
char dateofbirth[20];
}bank;

//CREATE STRUCTURE FOR DEBT AND CREDIT FOR BANK TRANSACTION
struct trs{
  float balance;  
  char account_number[20];
float debit_data;  
    float credit_data;
};

//FUNCTION DECLEAREATION
void open_account();
void blance_enquiry();
void deposite_money();
void withdraw_money();
void transaction();
void ntonull(char*);

int main()
{
  char stop;
  while(1){
 system("clear");
 printf("\n\n--------------Welcome To My Banking Project----------------\n\n\n\n");
 printf("_______________________________________________");
 printf("\n            1. Deposite Money");
 printf("\n_______________________________________________");
 printf("\n            2. Withdraw Money\n");
 printf("_______________________________________________");
 printf("\n            3. Aaccount Details\n");
 printf("_______________________________________________");
 printf("\n            4. Open Saving Account\n");
 printf("_______________________________________________");
 printf("\n            5. Close Bank Task");
 printf("\n_______________________________________________");
 printf("\n            6. Transaction\n");
 printf("\n_______________________________________________\n\n\n\n\n\n\n\n\n\n");
 printf("Enter Your Choice:- ");
 int choice;
 scanf("%d",&choice);
 system("clear");
 switch(choice){

  case 1:deposite_money(); 
  
   break;
  case 2: withdraw_money(); break;
  case 3: blance_enquiry(); __fpurge(stdin); scanf("%c",&stop); break;

  case 4: open_account(); printf("Account Created Sucessfully"); scanf("%c",&stop); break;
  case 5: exit(0);
  case 6:  transaction();   __fpurge(stdin); scanf("%c",&stop);                      break;
  default: printf("\n\nYour Choice Is Incorrect....\n Please Enter Correct Choice");
 }

  }
}


void open_account(){
bank data;
struct trs trss;
FILE *ftptr=fopen("transaction.dat","ab+");
if(ftptr==NULL){return;}
trss.credit_data=0,trss.debit_data=0, trss.balance=0;
//FOR OPEN FILE

FILE *fptr=fopen("bankdata.dat","ab+");
if(fptr==NULL){printf("\nBank Linke Is Failed ON This Time Tray After Some Time...");}
__fpurge(stdin);
printf("\nEnter Your name");
fgets(data.name,sizeof(data.name),stdin);
       ntonull(data.name);
       printf("\nEnter Pen: ");
fgets(data.pen_number,sizeof(data.pen_number),stdin);
       ntonull(data.pen_number);

printf("\nEnter Phone: ");
fgets(data.phone_number,sizeof(data.phone_number),stdin);
       ntonull(data.phone_number);

       printf("\nEnter Aadhar: ");
fgets(data.aadhar,sizeof(data.aadhar),stdin);
       ntonull(data.aadhar);

    printf("Enter Date Of Birth: ");
fgets(data.dateofbirth,sizeof(data.dateofbirth),stdin);
       ntonull(data.dateofbirth);

printf("\nEnter Residence Address");
fgets(data.full_address,sizeof(data.full_address),stdin);
       ntonull(data.full_address);

data.balance=0;

printf("\n Create Account Number: ");
fgets(data.account_number,sizeof(data.account_number),stdin);
       ntonull(data.account_number);
       strcpy(trss.account_number,data.account_number);
       fwrite(&trss,sizeof(trss),1,ftptr);
       fwrite(&data,sizeof(data),1,fptr);
       fclose(fptr);
       fclose(ftptr);
}

void blance_enquiry(){
bank data;
FILE *fptr=fopen("bankdata.dat","rb+");
if(fptr==NULL){printf("File Is Not Created On This Time Tray Later...."); return;}
char account_number[20];
printf("Enter Your Account NO: ");
__fpurge(stdin);
fgets(account_number,sizeof(account_number),stdin);
       ntonull(account_number);

while(fread(&data,sizeof(data),1,fptr)){
  if(0==strcmp(data.account_number,account_number)){
    printf("\n__________________________________________\n");
      printf("        A/C BALANCE: %.2f       \n",data.balance);
      printf("\n__________________________________________");
      printf("\nAccount Number Is: %s",data.account_number);
      printf("\n Name Is: %s",data.name);
      printf("\nPen NO: %s",data.pen_number);
      printf("\nAadhar NUmber: %s",data.aadhar);
      printf("\nPhone: %s",data.phone_number);
      printf("\nDate Of Birth: %s",data.dateofbirth);
      printf("\n__________________________________________\n");
      fclose(fptr);
       return;
  }
  
}
fclose(fptr);
printf("Data Not Fount: ");
}


void deposite_money(){
  bank data;
 struct trs trss;
FILE *fptr=fopen("bankdata.dat","rb+");
if(fptr==NULL){printf("\nSurver Unreachable Tray Later...."); return;}
printf("\nEnter Account Number: ");
char account_number[20];
__fpurge(stdin);
fgets(account_number,sizeof(account_number),stdin);
ntonull(account_number);

while(fread(&data,sizeof(data),1,fptr)){

  if(0==strcmp(account_number,data.account_number))
  {
    FILE *ftptr=fopen("transaction.dat","ab+");
    if(ftptr==NULL){ return;}
    strcpy(trss.account_number,data.account_number);
    fseek(fptr,-sizeof(data),SEEK_CUR);
    printf("\nEnter Amount: ");
    float balance;
    scanf("%f",&balance);
    trss.credit_data=balance; //STORE DATA FOR TRANSACTION HISTORY from transaction structure veriable
    //__fpurge(stdin);
    data.balance+=balance;
    trss.balance=data.balance;
    trss.debit_data=0;
  
    fwrite(&trss,sizeof(trss),1,ftptr);
    fclose(ftptr);
    strcpy(data.name,"your name");

    fwrite(&data,sizeof(data),1,fptr);
    char stop;
    printf("\nMony Deposite Sucessfully....");__fpurge(stdin); scanf("%c",&stop);
    fclose(fptr);
    return;
  }
}
printf("Data Not Found");
fclose(fptr);
}

void transaction(){
  char account_number[20];
struct trs trss;  //transction 
FILE *fptr=fopen("transaction.dat","rb");
if(fptr==NULL){printf("Not Reacheable...."); }
printf("\nEnter Account Number: ");
__fpurge(stdin);
fgets(account_number,sizeof(account_number) ,stdin);
ntonull(account_number);
printf("\n___________________________________________________________________________\n");
printf("      DATE       DEBIT       CREDIT        BALANCE        TRANSACTION ID\n");

while(fread(&trss,sizeof(trss),1,fptr)){
//printf("\n\n %s==%s\n\n",trss.account_number,account_number);
  if(0==strcmp(trss.account_number,account_number)){
printf("\n 00/00/0000     %.2f        %.2f          %.2f             0000000000    \n ",trss.debit_data,trss.credit_data,trss.balance);
  }
}
fclose(fptr);
return;
}

void withdraw_money(){
char stop;
char account_number[100];
bank data;
FILE *fptr=fopen("bankdata.dat","rb+");
if(fptr==NULL){ printf("\nTray Again Later...."); return; }
//PROBLAM IS HERE STARTING
printf("\nEnter Your Account Number: ");
  __fpurge(stdin);
  fgets(account_number,sizeof(account_number),stdin);
  ntonull(account_number);
while(fread(&data,sizeof(data),1,fptr)){
  if(0==strcmp(data.account_number,account_number)){
              
    printf("\n\nEnter Withdraw Amount: ");
  float amount;
  scanf("%f",&amount);
                if(amount>data.balance){ system("clear"); printf("\nBalance Insufsient"); __fpurge(stdin); scanf("%c",&stop); return; }
  __fpurge(stdin);
data.balance-=amount;
FILE *FPTR=fopen("transaction.dat","ab+");
if(FPTR==NULL){return;}
struct trs trss;
trss.balance=data.balance;
trss.debit_data=amount;
strcpy(trss.account_number,data.account_number);

//HERE , I HAVE TO ASSIGN TIME IN TRSS;
fwrite(&trss,sizeof(trss),1,FPTR);
fclose(FPTR);
  fseek(fptr,-sizeof(data),SEEK_CUR);
  fwrite(&data,sizeof(data),1,fptr);
  printf("\nMony withdraw Sucessfully %.2f Rupee A/c Balance: %.2f ",amount,data.balance);
  scanf("%c",&stop);
  fclose(fptr);
  return;
  }      
}//end of while loop

      fclose(fptr);
      printf("\nData Not found....");
      return;

}

void ntonull(char *name){
  int indexs=strcspn(name,"\n");
name[indexs]='\0';
}

void hellows(){printf("HELLOW WORLD");}
