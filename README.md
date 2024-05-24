                                                        THIS IS A MENU DRIVEN PROGRAM IN C LANGUAGE SUPPORTED IN UBUNTU,MACE,LINUX



# BANKING-PROJECT-IN-C-LANGUAGE
PROJECT HAS A CREATED STRUCTURE TYPE OF BANK WHICH IS CONTAINT CHAR MOBILE,NAME,DATE OF BIRTH,AND OTHER
                                            CODE HERE:

 typedef struct {
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


                                            
This Project Has A bankdata.dat File Which Is Store All Customer Details
#2. There Is Define 4 Function 
    (I) Open Saving Account
     for open saving account customer have to type all document details Like PAN,AADHAR, MOBILE,NAME
     void open_account(){
bank data;
//FOR OPEN FILE

FILE *fptr=fopen("bankdata.dat","ab+");
if(fptr==NULL){printf("\nBank Linke Is Failed ON This Time Tray After Some Time...");}
__fpurge(stdin);
printf("\nEnter Your name");
fgets(data.name,sizeof(data),stdin);
       ntonull(data.name);
       printf("\nEnter Pen: ");
fgets(data.pen_number,sizeof(data),stdin);
       ntonull(data.pen_number);

printf("\nEnter Phone: ");
fgets(data.phone_number,sizeof(data),stdin);
       ntonull(data.phone_number);

       printf("\nEnter Aadhar: ");
fgets(data.aadhar,sizeof(data),stdin);
       ntonull(data.aadhar);

    printf("Enter Date Of Birth: ");
fgets(data.dateofbirth,sizeof(data),stdin);
       ntonull(data.dateofbirth);

printf("\nEnter Residence Address");
fgets(data.full_address,sizeof(data),stdin);
       ntonull(data.full_address);

data.balance=0;

printf("\n Create Account Number: ");
fgets(data.account_number,sizeof(data),stdin);
       ntonull(data.account_number);
       
fwrite(&data,sizeof(data),1,fptr);
fclose(fptr);
}

    (II) For BALANCE Enquiry And All Details View
     CODE HERE   void balance_enquiry();

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




_____________________________________________________FULL CODE HERE...._____________________________________________________________________________________
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>

//CREATE STRUCTURE FOR STORE BANK ALL INFORMATION
typedef struct {
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

//FUNCTION DECLEAREATION
void open_account();
void blance_enquiry();
void deposite_money();
void withdraw_money();
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
  default: printf("\n\nYour Choice Is Incorrect....\n Please Enter Correct Choice");
 }

  }
}


void open_account(){
bank data;
//FOR OPEN FILE

FILE *fptr=fopen("bankdata.dat","ab+");
if(fptr==NULL){printf("\nBank Linke Is Failed ON This Time Tray After Some Time...");}
__fpurge(stdin);
printf("\nEnter Your name");
fgets(data.name,sizeof(data),stdin);
       ntonull(data.name);
       printf("\nEnter Pen: ");
fgets(data.pen_number,sizeof(data),stdin);
       ntonull(data.pen_number);

printf("\nEnter Phone: ");
fgets(data.phone_number,sizeof(data),stdin);
       ntonull(data.phone_number);

       printf("\nEnter Aadhar: ");
fgets(data.aadhar,sizeof(data),stdin);
       ntonull(data.aadhar);

    printf("Enter Date Of Birth: ");
fgets(data.dateofbirth,sizeof(data),stdin);
       ntonull(data.dateofbirth);

printf("\nEnter Residence Address");
fgets(data.full_address,sizeof(data),stdin);
       ntonull(data.full_address);

data.balance=0;

printf("\n Create Account Number: ");
fgets(data.account_number,sizeof(data),stdin);
       ntonull(data.account_number);
       
fwrite(&data,sizeof(data),1,fptr);
fclose(fptr);
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
    fseek(fptr,-sizeof(data),SEEK_CUR);
    printf("\nEnter Amount: ");
    float balance;
    scanf("%f",&balance);
    //__fpurge(stdin);
    data.balance+=balance; printf("\n\n2.YES\n");
  
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



void withdraw_money(){
char stop;
char account_number[100];
bank data;
FILE *fptr=fopen("bankdata.dat","rb+");
if(fptr==NULL){ printf("\nTray Again Later...."); return; }

//PROBLAM IS HERE STARTING
printf("\nEnter Your Account Number: ");
  __fpurge(stdin);
  //FOLT HERE
  //fgets(accountnumber,sizeof(accountnumber),stdin);
  fgets(account_number,sizeof(account_number),stdin);
  ntonull(account_number);
 // gets(account_number);

while(fread(&data,sizeof(data),1,fptr)){
  printf("\n3.Yes I Am Here");
  if(0==strcmp(data.account_number,account_number)){
              
    printf("\n\nEnter Withdraw Amount: ");
  float amount;
  scanf("%f",&amount);
                if(amount>data.balance){ system("clear"); printf("\nBalance Insufsient"); __fpurge(stdin); scanf("%c",&stop); return; }
  __fpurge(stdin);
data.balance-=amount;
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
