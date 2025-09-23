#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IBAN_LEN 23
#define MAX_NAME_LEN 101
#define MAX_TYPE_LEN 20
#define DATE_LEN 11
#define TRANSACTION_FILE "transaction.bin"
#define PARAGON_FILE "Paragon.txt"

typedef struct {
    char iban[MAX_IBAN_LEN];
    char client_name[MAX_NAME_LEN];
    double balance;
    double min_balance;
    char account_type[MAX_TYPE_LEN]; // e.g. "Current", "Deposit", etc.
    char maturity_date[DATE_LEN];
    char open_date[DATE_LEN];
} bank_account;

typedef struct {
    char date[DATE_LEN];
    char iban[MAX_IBAN_LEN];
    double amount;
    double fee;
    double new_balance;
} transaction;

// Helper to compare dates (returns -1, 0, 1)
int compare_dates(const char *d1, const char *d2) {
    int day1, mon1, year1, day2, mon2, year2;
    sscanf(d1, "%2d.%2d.%4d", &day1, &mon1, &year1);
    sscanf(d2, "%2d.%2d.%4d", &day2, &mon2, &year2);

    if (year1 != year2) return year1 < year2 ? -1 : 1;
    if (mon1 != mon2) return mon1 < mon2 ? -1 : 1;
    if (day1 != day2) return day1 < day2 ? -1 : 1;
    return 0;
}

// Validates date format (DD.MM.YYYY)
int is_valid_date(const char *date) {
    int d, m, y;
    return sscanf(date, "%2d.%2d.%4d", &d, &m, &y) == 3 && d >= 1 && d <= 31 && m >= 1 && m <= 12 && y >= 1900;
}

void input_accounts(bank_account **accounts, int *count) {
    printf("Enter number of accounts: ");
    scanf("%d", count);
    *accounts = (bank_account *)malloc(*count * sizeof(bank_account));

    for (int i = 0; i < *count; i++) {
        printf("\n--- Enter data for account %d ---\n", i + 1);
        printf("IBAN (22 characters): ");
        scanf("%22s", (*accounts)[i].iban);
        while (strlen((*accounts)[i].iban) != 22) {
            printf("Invalid IBAN. Enter again: ");
            scanf("%22s", (*accounts)[i].iban);
        }

        printf("Client Name: ");
        scanf(" %[^\n]", (*accounts)[i].client_name);

        printf("Balance: ");
        scanf("%lf", &(*accounts)[i].balance);

        printf("Minimum balance: ");
        scanf("%lf", &(*accounts)[i].min_balance);

        printf("Account type (Current/Deposit/Child/Card): ");
        scanf("%s", (*accounts)[i].account_type);

        do {
            printf("Maturity Date (DD.MM.YYYY): ");
            scanf("%s", (*accounts)[i].maturity_date);
        } while (!is_valid_date((*accounts)[i].maturity_date));

        do {
            printf("Open Date (DD.MM.YYYY): ");
            scanf("%s", (*accounts)[i].open_date);
        } while (!is_valid_date((*accounts)[i].open_date));
    }
}

double withdraw(bank_account *accounts, int count, const char *iban, double amount, const char *op_date) {
    FILE *f = fopen(TRANSACTION_FILE, "ab");
    if (!f) {
        printf("Error opening transaction file.\n");
        return -1;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].iban, iban) == 0) {
            double fee = 0.0;

            if (strcmp(accounts[i].account_type, "Deposit") == 0) {
                if (compare_dates(op_date, accounts[i].maturity_date) != 0)
                    fee = 2.00;
            } else if (strcmp(accounts[i].account_type, "Child") == 0) {
                fee = 0.0;
            } else if (strcmp(accounts[i].account_type, "Current") == 0) {
                fee = amount * 0.005;
                if (fee < 0.5) fee = 0.5;
                if (fee > 200.0) fee = 200.0;
            } else if (strcmp(accounts[i].account_type, "Card") == 0) {
                fee = 10.0;
            }

            double total = amount + fee;

            if (accounts[i].balance - total < 0 ||
                (strcmp(accounts[i].account_type, "Card") == 0 && accounts[i].balance - total < accounts[i].min_balance)) {
                printf("Insufficient funds for withdrawal.\n");
                fclose(f);
                return accounts[i].balance;
            }

            accounts[i].balance -= total;

            transaction t;
            strcpy(t.date, op_date);
            strcpy(t.iban, iban);
            t.amount = amount;
            t.fee = fee;
            t.new_balance = accounts[i].balance;
            fwrite(&t, sizeof(transaction), 1, f);
            fclose(f);
            return t.new_balance;
        }
    }

    printf("Account not found.\n");
    fclose(f);
    return -1;
}

int export_paragon(const char *iban, const char *start_date, const char *end_date) {
    FILE *in = fopen(TRANSACTION_FILE, "rb");
    FILE *out = fopen(PARAGON_FILE, "w");
    if (!in || !out) return 0;

    transaction t;
    int count = 0;
    while (fread(&t, sizeof(transaction), 1, in)) {
        if (strcmp(t.iban, iban) == 0 &&
            compare_dates(t.date, start_date) >= 0 &&
            compare_dates(t.date, end_date) <= 0) {
            fprintf(out, "%s,%s,%.2f,%.2f\n", t.date, t.iban, t.amount, t.new_balance);
            count++;
        }
    }

    fclose(in);
    fclose(out);
    return count;
}

void print_fees(bank_account *accounts, int count, const char *client_name, const char *start, const char *end) {
    FILE *f = fopen(TRANSACTION_FILE, "rb");
    if (!f) {
        printf("Error reading transaction file.\n");
        return;
    }

    transaction t;
    double fees[100] = {0};
    char ibans[100][MAX_IBAN_LEN];
    int acc_count = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].client_name, client_name) == 0) {
            strcpy(ibans[acc_count], accounts[i].iban);
            acc_count++;
        }
    }

    while (fread(&t, sizeof(transaction), 1, f)) {
        for (int i = 0; i < acc_count; i++) {
            if (strcmp(t.iban, ibans[i]) == 0 &&
                compare_dates(t.date, start) >= 0 &&
                compare_dates(t.date, end) <= 0) {
                fees[i] += t.fee;
            }
        }
    }

    fclose(f);
    for (int i = 0; i < acc_count; i++) {
        printf("%-22s: %8.2f\n", ibans[i], fees[i]);
    }
}

int main() {
    bank_account *accounts = NULL;
    int count;

    input_accounts(&accounts, &count);

    // Example withdrawal
    char iban[23], op_date[11];
    double amount;
    printf("\n--- Withdrawal ---\nEnter IBAN: ");
    scanf("%s", iban);
    printf("Enter amount: ");
    scanf("%lf", &amount);
    printf("Enter date (DD.MM.YYYY): ");
    scanf("%s", op_date);

    double new_balance = withdraw(accounts, count, iban, amount, op_date);
    if (new_balance >= 0)
        printf("New balance: %.2f\n", new_balance);

    // Example export
    printf("\n--- Export Paragon ---\n");
    char start[11], end[11];
    printf("Enter IBAN: ");
    scanf("%s", iban);
    printf("Enter start date: ");
    scanf("%s", start);
    printf("Enter end date: ");
    scanf("%s", end);
    int total = export_paragon(iban, start, end);
    printf("%d operations exported.\n", total);

    // Example fee summary
    printf("\n--- Fees for Client ---\nEnter client name: ");
    scanf(" %[^\n]", iban); // reuse variable to store name
    printf("Enter start date: ");
    scanf("%s", start);
    printf("Enter end date: ");
    scanf("%s", end);
    print_fees(accounts, count, iban, start, end);

    free(accounts);
    return 0;
}