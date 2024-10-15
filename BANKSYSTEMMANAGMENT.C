#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct Account{
    int accountno;
    char name[75];
    char gender;
    float balance;
};

void createaccount(struct Account *account){
    printf("Enter account number : ");
    scanf("%d",&account->accountno);
    
    printf("Enter name : ");
    scanf("%s",&account->name);
    
    printf("Enter gender(M/F) : ");
    scanf(" %c",&account->gender);
    
    account->balance = 0.0;
    printf("Account creation successfull");
}

void deposit(struct Account *account, float amount){
    if(amount>0){
        account->balance += amount;
        printf("%f has been succesfully deposited.",account->balance);}
    else
        printf("Enter valid amount");
}

void withdraw(struct Account *account, float amount){
    if(account->balance<=0)
        printf("Insufficent funds in the account");
    else if (amount < account->balance){
        account->balance -= amount;
        printf("%f has successfully withdrawn",amount);
        printf("\nUpdated balance : %f",account->balance);
    }
    else
        printf("Invalid withdrawl amount");
}

void display(struct Account *account){
    printf("---ACCOUNT DETAILS---\n");
    printf("Acccount number : %d\n",account->accountno); 
    printf("Acccount holder name : %s\n",account->name); 
    printf("Acccount holder gender : %c\n",account->gender); 
    printf("Acccount balance : %f\n",account->balance); 
}

void delete(struct Account *account) {
    account->accountno = 0;
    account->balance = 0.0;     
    printf("Account deleted successfully!\n");
}

int main(){
    struct Account account;
    int choice;
    float amount;
    account.balance = 0.0;
    while(1){
        printf("\n--- Bank Account Managment ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Delete account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createaccount(&account);
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(&account, amount);
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(&account, amount);
                break;
            case 4:
                display(&account);
                break;
            case 5:
                delete(&account);
                break;
            case 6:
                printf("EXIT\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;   
}
