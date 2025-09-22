/*
 * Task 1: Define the bankAccount structure and create a dynamic array of accounts
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IBAN_LEN 23
#define MAX_NAME_LEN 101
#define MAX_DATE_LEN 11
#define TRANSACTION_FILE "transaction.bin"

// Structure to store a bank account
typedef struct {
    char IBAN[MAX_IBAN_LEN];
    char clientName[MAX_NAME_LEN];
    double balance;
    double minBalance;
    char accountType[20]; // "Razplashtatelna", "Depozitna", "Detski depozit", "Kartova"
    char maturityDate[MAX_DATE_LEN];
    char openDate[MAX_DATE_LEN];
} bankAccount;

// Structure to store a transaction
typedef struct {
    char date[MAX_DATE_LEN];
    char IBAN[MAX_IBAN_LEN];
    double amount;
    double fee;
    double newBalance;
} transactionRecord;

/*
 * Task 2: Withdraw operation function
 */
double withdraw(bankAccount *accounts, int size, const char *IBAN, double amount, const char *operationDate) {
    for (int i = 0; i < size; i++) {
        if (strcmp(accounts[i].IBAN, IBAN) == 0) {
            double fee = 0.0;
            int isMaturity = strcmp(accounts[i].maturityDate, operationDate) == 0;

            // Calculate fee based on account type
            if (strcmp(accounts[i].accountType, "Depozitna") == 0) {
                if (!isMaturity) fee = 2.00;
            } else if (strcmp(accounts[i].accountType, "Detski depozit") == 0) {
                fee = 0.0;
            } else if (strcmp(accounts[i].accountType, "Razplashtatelna") == 0) {
                fee = amount * 0.005;
                if (fee < 0.5) fee = 0.5;
                if (fee > 200.0) fee = 200.0;
            } else if (strcmp(accounts[i].accountType, "Kartova") == 0) {
                fee = 10.0;
            }

            double total = amount + fee;

            // Check if withdrawal is allowed
            if (strcmp(accounts[i].accountType, "Kartova") == 0) {
                if (accounts[i].balance - total < accounts[i].minBalance) {
                    printf("Withdrawal denied: below minimum balance.\n");
                    return accounts[i].balance;
                }
            } else {
                if (accounts[i].balance - total < 0) {
                    printf("Withdrawal denied: insufficient funds.\n");
                    return accounts[i].balance;
                }
            }

            accounts[i].balance -= total;

            // Log transaction
            FILE *fp = fopen(TRANSACTION_FILE, "ab");
            if (fp == NULL) {
                perror("Error opening");
                return -1; 
            }
            if (fp) {
                transactionRecord record;
                strncpy(record.date, operationDate, MAX_DATE_LEN);
                strncpy(record.IBAN, accounts[i].IBAN, MAX_IBAN_LEN);
                record.amount = amount;
                record.fee = fee;
                record.newBalance = accounts[i].balance;
                fwrite(&record, sizeof(record), 1, fp);
                fclose(fp);
            }

            return accounts[i].balance;
        }
    }
    printf("Account not found.\n");
    return -1.0;
}

/*
 * Task 3: Export transactions in a given period to Paragon.txt
 */
int exportTransactions(const char *IBAN, const char *startDate, const char *endDate) {
    FILE *fp = fopen(TRANSACTION_FILE, "rb");
    if (fp == NULL) {
        perror("Error opening transaction.bin for appending");
        return -1;  
    }
    FILE *out = fopen("Paragon.txt", "w");
    if (out == NULL) {
        perror("Error opening Paragon.txt for writing");
        fclose(fp);
        return -1;  
    }
    int count = 0;

    if (!fp || !out) return 0;

    transactionRecord record;
    while (fread(&record, sizeof(record), 1, fp)) {
        if (strcmp(record.IBAN, IBAN) == 0 && strcmp(record.date, startDate) >= 0 && strcmp(record.date, endDate) <= 0) {
            fprintf(out, "%s,%s,%.2f,%.2f\n", record.date, record.IBAN, record.amount, record.newBalance);
            count++;
        }
    }

    fclose(fp);
    fclose(out);
    return count;
}

/*
 * Task 4: Calculate total fees for all accounts of a client in a given period
 */
void calculateClientFees(bankAccount *accounts, int size, const char *startDate, const char *endDate, const char *clientName) {
    FILE *fp = fopen(TRANSACTION_FILE, "rb");
    if (fp == NULL) {
        perror("Error opening");
        return -1;  
    }
    if (!fp) return;

    printf("%-22s:%8s\n", "IBAN", "Fee");

    for (int i = 0; i < size; i++) {
        if (strcmp(accounts[i].clientName, clientName) == 0) {
            double totalFee = 0.0;
            transactionRecord record;
            rewind(fp);
            while (fread(&record, sizeof(record), 1, fp)) {
                if (strcmp(record.IBAN, accounts[i].IBAN) == 0 && strcmp(record.date, startDate) >= 0 && strcmp(record.date, endDate) <= 0) {
                    totalFee += record.fee;
                }
            }
            printf("%-22s:%8.2f\n", accounts[i].IBAN, totalFee);
        }
    }
    fclose(fp);
}

/*
 * Main function to demonstrate functionality
 */
int main() {
    int n;
    printf("Enter number of accounts: ");
    scanf("%d", &n);
    getchar(); // clear newline

    bankAccount *accounts = malloc(n * sizeof(bankAccount));

    for (int i = 0; i < n; i++) {
        printf("\nAccount #%d\n", i + 1);
        printf("IBAN: "); fgets(accounts[i].IBAN, MAX_IBAN_LEN, stdin); strtok(accounts[i].IBAN, "\n");
        printf("Client Name: "); fgets(accounts[i].clientName, MAX_NAME_LEN, stdin); strtok(accounts[i].clientName, "\n");
        printf("Balance: "); scanf("%lf", &accounts[i].balance);
        printf("Minimum Balance: "); scanf("%lf", &accounts[i].minBalance); getchar();
        printf("Account Type: "); fgets(accounts[i].accountType, 20, stdin); strtok(accounts[i].accountType, "\n");
        printf("Maturity Date (DD.MM.YYYY): "); fgets(accounts[i].maturityDate, MAX_DATE_LEN, stdin); strtok(accounts[i].maturityDate, "\n");
        printf("Open Date (DD.MM.YYYY): "); fgets(accounts[i].openDate, MAX_DATE_LEN, stdin); strtok(accounts[i].openDate, "\n");
    }

    // Example operation
    withdraw(accounts, n, accounts[0].IBAN, 100.0, "05.06.2025");
    exportTransactions(accounts[0].IBAN, "01.06.2025", "10.06.2025");
    calculateClientFees(accounts, n, "01.06.2025", "10.06.2025", accounts[0].clientName);

    free(accounts);
    return 0;
}