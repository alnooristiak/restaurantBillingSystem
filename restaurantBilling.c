#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to represent a user
struct user
{
    char username[50];
    char password[50];
};

// Struct to represent an item in the restaurant
struct items
{
    char item[30];
    float price;
    int qty;
};

// Struct to represent an order in the restaurant
struct orders
{
    char customer[50];
    char date[30];
    int numOfItems;
    struct items itm[50];
};

// Function to register a new user
void registerUser()
{
    FILE *fp = fopen("restaurant_users.csv", "a+");
    if (fp == NULL)
    {
        printf("Error opening file for registration.\n");
        return;
    }

    struct user newUser;
    printf("Enter username: ");
    fgets(newUser.username, sizeof(newUser.username), stdin);
    newUser.username[strcspn(newUser.username, "\n")] = 0;

    printf("Enter password: ");
    fgets(newUser.password, sizeof(newUser.password), stdin);
    newUser.password[strcspn(newUser.password, "\n")] = 0;

    char line[100];
    int userExists = 0;
    fseek(fp, 0, SEEK_SET);
    while (fgets(line, sizeof(line), fp))
    {
        char fileUsername[50];
        sscanf(line, "%49[^,]", fileUsername);
        if (strcmp(fileUsername, newUser.username) == 0)
        {
            printf("Username already exists! Please try a different username.\n");
            userExists = 1;
            break;
        }
    }

    if (!userExists)
    {
        fprintf(fp, "%s,%s\n", newUser.username, newUser.password);
        printf("Registration successful! You can now log in.\n");
    }

    fclose(fp);
}

// Function to login an existing user
void loginUser()
{
    FILE *fp = fopen("restaurant_users.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file for login.\n");
        return;
    }

    char username[50], password[50];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    char line[100];
    int loginSuccess = 0;
    while (fgets(line, sizeof(line), fp))
    {
        char fileUsername[50], filePassword[50];
        sscanf(line, "%49[^,],%49[^\n]", fileUsername, filePassword);

        if (strcmp(fileUsername, username) == 0 && strcmp(filePassword, password) == 0)
        {
            printf("Login successful! Welcome, %s.\n", username);
            loginSuccess = 1;
            break;
        }
    }

    if (!loginSuccess)
    {
        printf("Invalid username or password. Please try again.\n");
    }

    fclose(fp);
}

// Function to generate bill headers
void generateBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t============ ADV. RESTAURANT ============\n");
    printf("Date: %s\n", date);
    printf("Invoice To: %s\n", name);
    printf("-----------------------------------------\n");
    printf("Items\t\tQty\t\tTotal\n");
    printf("-----------------------------------------\n");
}

// Function to generate bill body
void generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t%d\t\t%.2f\n", item, qty, qty * price);
}

// Function to generate bill footer
void generateBillFooter(float total)
{
    float discount = 0.1 * total;
    float netTotal = total - discount;
    float vat = 0.15 * netTotal;
    float grandTotal = netTotal + vat;

    printf("-----------------------------------------\n");
    printf("Sub Total:\t\t\t%.2f\n", total);
    printf("Discount (10%%):\t\t\t%.2f\n", discount);
    printf("Net Total:\t\t\t%.2f\n", netTotal);
    printf("VAT (15%%):\t\t\t%.2f\n", vat);
    printf("-----------------------------------------\n");
    printf("Grand Total:\t\t\t%.2f\n", grandTotal);
    printf("-----------------------------------------\n");
}

// Function to save the bill in a CSV file
void saveBillToCSV(struct orders ord)
{
    FILE *csvFile = fopen("RestaurantBills.csv", "a+");
    if (csvFile == NULL)
    {
        printf("Error opening CSV file to save the bill.\n");
        return;
    }

    static int headerWritten = 0;
    if (headerWritten == 0)
    {
        fprintf(csvFile, "Customer Name,Date,Item,Quantity,Unit Price,Total\n");
        headerWritten = 1;
    }

    for (int i = 0; i < ord.numOfItems; i++)
    {
        float itemTotal = ord.itm[i].qty * ord.itm[i].price;
        fprintf(csvFile, "%s,%s,%s,%d,%.2f,%.2f\n",
                ord.customer,
                ord.date,
                ord.itm[i].item,
                ord.itm[i].qty,
                ord.itm[i].price,
                itemTotal);
    }

    fclose(csvFile);
    printf("Bill saved to CSV successfully.\n");
}

// Function to show all invoices from CSV, separated by customer
void showAllInvoices()
{
    FILE *fp = fopen("RestaurantBills.csv", "r");
    if (fp == NULL)
    {
        printf("Error: No invoices found.\n");
        return;
    }

    char line[200];
    int lineNumber = 0;
    char currentCustomer[50] = "";

    printf("\n\n========== All Invoices ==========\n");

    while (fgets(line, sizeof(line), fp))
    {
        if (lineNumber == 0)
        {
            // Skip the header line
            lineNumber++;
            continue;
        }

        char customerName[50];
        sscanf(line, "%49[^,]", customerName);

        // Print separator when a new customer is encountered
        if (strcmp(currentCustomer, customerName) != 0)
        {
            if (lineNumber > 1)
            {
                printf("\n-----------------------------------------\n");
            }
            printf("\nInvoices for Customer: %s\n", customerName);
            printf("Item, Quantity, Unit Price, Total\n");
            strcpy(currentCustomer, customerName); // Update current customer
        }

        // Print the invoice details for the customer
        printf("%s", line);
        lineNumber++;
    }

    if (lineNumber == 1)
    {
        // Only header was read, no invoices
        printf("No invoices found in the system.\n");
    }

    fclose(fp);
}

// Function to search for invoices by customer name
void searchInvoice()
{
    char searchName[50];
    printf("\nEnter customer name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove the newline character

    FILE *fp = fopen("RestaurantBills.csv", "r");
    if (fp == NULL)
    {
        printf("Error: No invoices found.\n");
        return;
    }

    char line[200];
    int lineNumber = 0;
    int found = 0;

    printf("\n\n========== Search Results ==========\n");

    while (fgets(line, sizeof(line), fp))
    {
        if (lineNumber == 0)
        {
            // Skip the header line
            lineNumber++;
            continue;
        }

        char customerName[50];
        sscanf(line, "%49[^,]", customerName);

        // Check if the customer name matches the search query
        if (strcmp(customerName, searchName) == 0)
        {
            if (!found)
            {
                printf("\nInvoices for Customer: %s\n", searchName);
                printf("Item, Quantity, Unit Price, Total\n");
                found = 1;
            }
            printf("%s", line);
        }
    }

    if (!found)
    {
        printf("No invoices found for customer: %s\n", searchName);
    }

    fclose(fp);
}

int main()
{
    int choice, opt, n;
    char continueChoice = 'y', saveBill = 'y', contFlag = 'y';
    struct orders ord;
    FILE *fp;

    while (contFlag == 'y')
    {
        printf("\n===== Restaurant Management System =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            printf("Exiting the system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf("%c", &continueChoice);
        getchar();

        if (continueChoice == 'n')
            break;
    }

    while (contFlag == 'y')
    {
        printf("\n\n========== RESTAURANT MENU ==========\n");
        printf("1. Generate Invoice\n");
        printf("2. Show All Invoices\n");
        printf("3. Search Invoice\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        getchar();

        switch (opt)
        {
        case 1:
        {
            printf("\nEnter customer name: ");
            fgets(ord.customer, sizeof(ord.customer), stdin);
            ord.customer[strcspn(ord.customer, "\n")] = 0;

            strcpy(ord.date, __DATE__);

            printf("Enter number of items: ");
            scanf("%d", &n);
            ord.numOfItems = n;

            for (int i = 0; i < n; i++)
            {
                getchar();
                printf("\nEnter item %d: ", i + 1);
                fgets(ord.itm[i].item, sizeof(ord.itm[i].item), stdin);
                ord.itm[i].item[strcspn(ord.itm[i].item, "\n")] = 0;

                printf("Enter quantity: ");
                scanf("%d", &ord.itm[i].qty);

                printf("Enter unit price: ");
                scanf("%f", &ord.itm[i].price);
            }

            float total = 0;
            for (int i = 0; i < ord.numOfItems; i++)
            {
                total += ord.itm[i].qty * ord.itm[i].price;
            }

            generateBillHeader(ord.customer, ord.date);
            for (int i = 0; i < ord.numOfItems; i++)
            {
                generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
            }
            generateBillFooter(total);

            printf("\nSave the invoice? (y/n): ");
            scanf(" %c", &saveBill);

            if (saveBill == 'y')
            {
                fp = fopen("RestaurantBill.dat", "a+");
                fwrite(&ord, sizeof(struct orders), 1, fp);
                fclose(fp);

                saveBillToCSV(ord);

                printf("Invoice saved successfully.\n");
            }
            break;
        }
        case 2:
            showAllInvoices();
            break;
        case 3:
            searchInvoice(); // Add the new search function
            break;
        case 4:
            printf("Exiting the system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &contFlag);
        getchar();
    }

    return 0;
}
