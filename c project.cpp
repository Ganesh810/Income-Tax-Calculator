#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int income;
    float tax;
} TaxPayer;

void addRecord();
void listRecords();
void searchRecord();
void editRecord();
void deleteRecord();

void addRecord() {
    FILE *fp;
    TaxPayer tp;
    printf("Enter name: ");
    scanf("%s", tp.name);
    printf("Enter age: ");
    scanf("%d", &tp.age);
    printf("Enter income: ");
    scanf("%d", &tp.income);
    if (tp.income <= 250000) {
        tp.tax = 0;
    } else if (tp.income > 250000 && tp.income <= 500000) {
        tp.tax = 0.05 * (tp.income - 250000);
    } else if (tp.income > 500000 && tp.income <= 1000000) {
        tp.tax = 12500 + 0.2 * (tp.income - 500000);
    } else {
        tp.tax = 112500 + 0.3 * (tp.income - 1000000);
    }
    fp = fopen("tax_records.txt", "ab");
    fwrite(&tp, sizeof(TaxPayer), 1, fp);
    fclose(fp);
    printf("Record added successfully.\n");
}

void listRecords() {
    FILE *fp;
    TaxPayer tp;
    fp = fopen("tax_records.txt", "rb");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Age", "Income", "Tax");
    while (fread(&tp, sizeof(TaxPayer), 1, fp) == 1) {
        printf("%-20s %-10d %-10d %-10.2f\n", tp.name, tp.age, tp.income, tp.tax);
    }
    fclose(fp);
}

void searchRecord() {
    FILE *fp;
    TaxPayer tp;
    char name[50];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%s", &name);
    fp = fopen("tax_records.txt", "rb");
    while (fread(&tp, sizeof(TaxPayer), 1, fp) == 1) {
        if (strcmp(name, tp.name) == 0) {
            printf("%-20s %-10d %-10d %-10.2f\n", tp.name, tp.age, tp.income, tp.tax);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Record not found.\n");
    }
    fclose(fp);
}

void editRecord() {
    FILE *fp;
    TaxPayer tp;
    char name[50];
    int found = 0;
    printf("Enter name to edit: ");
    scanf("%s", &name);
    fp = fopen("tax_records.txt", "r+b");
    while (fread(&tp, sizeof(TaxPayer), 1, fp) == 1) {
        if (strcmp(name, tp.name) == 0) {
            printf("Enter new name: ");
            scanf("%s", &tp.name);
            printf("Enter new age: ");
            scanf("%d", &tp.age);
            printf("Enter new income: ");
            scanf("%d", &tp.income);
            if (tp.income <= 250000){
tp.tax = 0;
} else if (tp.income > 250000 && tp.income <= 500000) {
tp.tax = 0.05 * (tp.income - 250000);
} else if (tp.income > 500000 && tp.income <= 1000000) {
tp.tax = 12500 + 0.2 * (tp.income - 500000);
} else {
tp.tax = 112500 + 0.3 * (tp.income - 1000000);
}
fseek(fp, -sizeof(TaxPayer), SEEK_CUR);
fwrite(&tp, sizeof(TaxPayer), 1, fp);
found = 1;
break;
}
}
if (found == 0) {
printf("Record not found.\n");
} else {
printf("Record updated successfully.\n");
}
fclose(fp);
}

void deleteRecord() {
FILE *fp, *tempfp;
TaxPayer tp;
char name[50];
int found = 0;
printf("Enter name to delete: ");
scanf("%s", &name);
fp = fopen("tax_records.txt", "rb");
tempfp = fopen("temp.txt", "wb");
while (fread(&tp, sizeof(TaxPayer), 1, fp) == 1) {
if (strcmp(name, tp.name) != 0) {
fwrite(&tp, sizeof(TaxPayer), 1, tempfp);
} else {
found = 1;
}
}
fclose(fp);
fclose(tempfp);
remove("tax_records.txt");
rename("temp.txt", "tax_records.txt");
if (found == 0) {
printf("Record not found.\n");
} else {
printf("Record deleted successfully.\n");
}
}

int main() {
int choice;
do {
printf("Tax Calculator\n");
printf("1. Add new record\n");
printf("2. List all records\n");
printf("3. Search record\n");
printf("4. Edit record\n");
printf("5. Delete record\n");
printf("0. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
addRecord();
break;
case 2:
listRecords();
break;
case 3:
searchRecord();
break;
case 4:
editRecord();
break;
case 5:
deleteRecord();
break;
case 0:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
break;
}
} while (choice != 0);
return 0;
}

