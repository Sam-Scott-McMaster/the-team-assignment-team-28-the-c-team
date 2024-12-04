/* Huzayl Yusuf-Zai, 400533514, 13/12/2024
 *
 * This file contains all the enssessary files that write to and read from the dataBase file. It servers as a connection point between the database and
 * other functions which need information pertiaining to the user currently signed into their account. 2 functions (checkUser & addUser) deal with Signing in/up.
 * wrteTransactions and writeBudget will append/overwrite the file with new transaction info or budget info. allTrans and allBud write the transaction/budget info
 * to a new file and returns the file name.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* checkUser
 * This function validates the sign in information passed in by the user. It first looks for the username, and once that is found. It validates the password.
 * If the sign in is sucesseful, a message is displayed and the user is considered "Signed In". char *signedInUser is the user name of the current signed in user
 * that is to be references elsewhere in the code for other processess, and is assigned a value in this function. This function returns null or exit code 0 if account
 * info is wrong.
 */

void checkUser(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");

    if (fileOpen == NULL)
    {
        printf("Error occurred while opening the file!\n");
        exit(1);
    }

    char userName[200];
    char password[200];
    char charline[1024];      // Holds line content
    int passLine;             // Line which contains password
    bool presentUser = false; // Wether the user has an account
    bool signedIn = false;
    int lineNum = 0; // Track which line the iteration is on

    printf("Enter User Name: ");
    scanf("%199s", userName);
    strtok(userName, "\n");

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strncmp(charline, "Username: ", 10) == 0)
        {
            charline[strcspn(charline, "\n")] = '\0';

            if (strcmp(charline + 10, userName) == 0)
            {
                presentUser = true;
                passLine = lineNum + 1;
                break;
            }
        }
    }

    if (presentUser)
    {
        printf("\nEnter Password: ");
        scanf("%199s", password);
        strtok(password, "\n");

        fseek(fileOpen, 0, SEEK_SET);

        lineNum = 0;
        while (fgets(charline, sizeof(charline), fileOpen))
        {
            lineNum++;
            if (lineNum == passLine && strncmp(charline, "Password: ", 10) == 0)
            {
                charline[strcspn(charline, "\n")] = '\0';

                if (strcmp(charline + 10, password) == 0)
                {
                    signedIn = true;
                    break;
                }
            }
        }
    }
    if (signedIn)
    {
        printf("You are now signed in! Welcome Back %s\n", userName);
        strcpy(signedInUser, userName);
    }
    else
    {
        printf("Wrong Username or Password\n");
        exit(0);
    }

    fclose(fileOpen);
    return;
}

/* setBalance
 * This function sets the balance by looking for the username first with signedInUser, and then overwritng the line right below balance based on user input. The file is first opened
 * read, then closed and opened to right. It follows the same procedure as the following functions, this one being a bit more shallow(requires less iterating). The function also
 * takes a double pointer varible *balance and casts the users input balance to a double value to reference later.
 * The function returns Null.
 */

void setBalance(char *signedInUser, double *balance)
{
    char newBalance[200];

    FILE *fileOpen = fopen("dataBase.txt", "r");

    char charline[1024];
    char buffer[10000] = "";
    bool isUser = false;
    bool overwriteLine = false;

    printf("\nEnter Balance: ");
    scanf("%199s", newBalance);

    *balance = atof(newBalance);

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (overwriteLine)
        {
            strcat(buffer, newBalance);
            strcat(buffer, "\n");
            overwriteLine = false;
            continue;
        }

        strcat(buffer, charline);

        if (!isUser && strncmp(charline, "Username: ", 10) == 0 && strncmp(charline + 10, signedInUser, strlen(signedInUser)) == 0 && charline[10 + strlen(signedInUser)] == '\n')
        {
            isUser = true;
        }

        if (isUser && strncmp(charline, "BALANCE:\n", 8) == 0)
        {
            overwriteLine = true;
        }
    }

    fclose(fileOpen);

    fileOpen = fopen("dataBase.txt", "w");

    fputs(buffer, fileOpen);
    fclose(fileOpen);

    printf("Balance Successfully set!\n");
}

/* subBalance
 * This function is exactly the same as the last one but takes in a float subtraction parameter to subtract transactions from the balance
 * The function returns Null.
 */

void subBalance(char *signedInUser, double *balance, float subtraction)
{
    char newBalance[200];

    FILE *fileOpen = fopen("dataBase.txt", "r");

    char charline[1024];
    char buffer[10000] = "";
    bool isUser = false;
    bool overwriteLine = false;

    printf("\nEnter Balance: ");
    scanf("%199s", newBalance);

    *balance = atof(newBalance) - subtraction;

    snprintf(newBalance, sizeof(buffer), "%.2f", balance);

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (overwriteLine)
        {
            strcat(buffer, newBalance);
            strcat(buffer, "\n");
            overwriteLine = false;
            continue;
        }

        strcat(buffer, charline);

        if (!isUser && strncmp(charline, "Username: ", 10) == 0 && strncmp(charline + 10, signedInUser, strlen(signedInUser)) == 0 && charline[10 + strlen(signedInUser)] == '\n')
        {
            isUser = true;
        }

        if (isUser && strncmp(charline, "BALANCE:\n", 8) == 0)
        {
            overwriteLine = true;
        }
    }

    fclose(fileOpen);

    fileOpen = fopen("dataBase.txt", "w");

    fputs(buffer, fileOpen);
    fclose(fileOpen);

    printf("Balance Successfully set!\n");
}

/* returnBalance
 * This function assigned the value of balance of the current user to a double pointer variable *balance by first finding the user name then getting the line right below balance.
 * This functions returns Null.
 */

void returnBalance(char *signedInUser, double *balance)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    char charline[1024];

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strstr(charline, signedInUser))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strstr(charline, "BALANCE:\n"))
        {
            if (fgets(charline, sizeof(charline), fileOpen))
            {
                *balance = atof(charline);
                fclose(fileOpen);
            }
        }
    }
}
/*  addUser
 * This function adds accounts to the database on creation from the user. If the username input by the user already exists, then it will tell the user that
 * that user name is already taken. If the username is good. It will then ask for a password (both one word) and then append it to the database. he user will be
 * automatically signed in via signedInUser(parameter). Returns void.
 */

void addUser(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");

    if (fileOpen == NULL)
    {
        printf("Error Occurred While creating a "
               "file !");
        exit(1);
    }

    char userName[200];
    char password[200];
    char charline[1024];
    bool presentUser = false;
    int lineNum;
    while (1)
    {
        presentUser = false;
        lineNum = 0;
        printf("Enter User Name(One word): ");
        scanf("%199s", userName);

        rewind(fileOpen);

        while (fgets(charline, sizeof(charline), fileOpen))
        {
            lineNum++;
            if (strncmp(charline, "Username: ", 10) == 0)
            {
                charline[strcspn(charline, "\n")] = '\0';
                if (strcmp(charline + 10, userName) == 0)
                {
                    printf("\nUser Name already exists, please try again.\n");
                    presentUser = true;
                    break;
                }
            }
        }
        if (!presentUser)
        {
            break;
        }
    }

    printf("\nEnter Password(One word): ");
    scanf("%s", password);
    fseek(fileOpen, 0, SEEK_END);

    fprintf(fileOpen, "\nUsername: %s\n", userName);
    fprintf(fileOpen, "Password: %s\n", password);
    fprintf(fileOpen, "BALANCE:\n");
    fprintf(fileOpen, "-1\n");
    fprintf(fileOpen, "TRANSACTIONS:\n\n");
    fprintf(fileOpen, "BUDGET:\n\n");

    printf("\nAccount Creation Successful!\n");
    fclose(fileOpen);
    strcpy(signedInUser, userName);
    return;
}

/*  writeTransaction
 * This function appends a transaction to the transction section of the file for that perticualar user. The function takes in the username of the user (signedInUser)
 * as well as the transaction string it self, and iterates through the database to find the user name. Onces that's done, it gets to the trasnaction secion and appends
 * to the file. Returns void.
 */

void writeTransaction(char *signedInUser, char *transaction)
{
    FILE *fileOpen = fopen("dataBase.txt", "r");

    char charline[1024];
    char buffer[10000] = ""; // Holds the modifications of the file temorarily to allow changes to memory
    bool isUser = false;     // Sees if user found

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        strcat(buffer, charline);

        if (!isUser && strncmp(charline, "Username: ", 10) == 0 && strncmp(charline + 10, signedInUser, strlen(signedInUser)) == 0 && charline[10 + strlen(signedInUser)] == '\n')
        {
            isUser = true;
        }

        if (isUser && strncmp(charline, "TRANSACTIONS:\n", 14) == 0)
        {
            strcat(buffer, transaction);
            strcat(buffer, "\n");
            isUser = false;
        }
    }

    fclose(fileOpen);

    fileOpen = fopen("dataBase.txt", "w");

    fputs(buffer, fileOpen);
    fclose(fileOpen);

    printf("Transaction added successfully for user '%s'.\n", signedInUser);
}

/*  writeBudget
 * This function appends a budget if there was not one perviously, or overwrites a privious one if there was already one there. It follows the same process as writeTransaction,
 * where it looks for the username, and then the budget section for that user. The content to append/overwite is passed in through char *budget. Returns void.
 */

void writeBudget(char *signedInUser, char *Budget)
{
    FILE *fileOpen = fopen("dataBase.txt", "r");

    char charline[1024];
    char buffer[10000] = "";
    bool isUser = false;
    bool jumpLine = false; // Indicates what line to replace with new budget

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (jumpLine)
        {
            jumpLine = false;
            strcat(buffer, Budget);
            strcat(buffer, "\n");
            continue;
        }

        strcat(buffer, charline);

        if (!isUser && strncmp(charline, "Username: ", 10) == 0 &&
            strncmp(charline + 10, signedInUser, strlen(signedInUser)) == 0 &&
            charline[10 + strlen(signedInUser)] == '\n')
        {
            isUser = true;
        }

        if (isUser && strncmp(charline, "BUDGET:\n", 8) == 0)
        {
            jumpLine = true;
        }
    }

    fclose(fileOpen);

    fileOpen = fopen("dataBase.txt", "w");

    fputs(buffer, fileOpen);
    fclose(fileOpen);

    printf("Budget updated successfully for user '%s'.\n", signedInUser);
}

/* allTrans
 * This function appends all the transaction history to a new file for use in other areas of the program. It works the same as the other functions,
 * finding the users  via signedInUser and then going down to Transactions to copy the content over. Returns Char* containg file name of transations
 * for that user.
 */

char *allTrans(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    FILE *transOpen = fopen("userTrans.txt", "w+");
    char charline[1024];

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strncmp(charline, "Username: ", 10) == 0 && strcmp(charline + 10, signedInUser) == 0)
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strncmp(charline, "TRANSACTIONS:\n", 14) == 0)
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strncmp(charline, "BUDGET:\n", 8) == 0 || strncmp(charline, "Username: ", 10) == 0)
        {
            break;
        }
        fputs(charline, transOpen);
    }
    fclose(fileOpen);
    fclose(transOpen);

    return "userTrans.txt";
}

/* allBud
 * This function appends the budget information to a new file to be references in other places. Works like allTrans, but this time looks for Budget instead of Transactions.
   Returns Char* containg file name of Budget for that user.
 */

char *allBud(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    FILE *budOpen = fopen("userBud.txt", "w+");
    char charline[1024];

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strstr(charline, signedInUser))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strstr(charline, "TRANSACTIONS:\n"))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strstr(charline, "BUDGET:\n"))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        if (strstr(charline, "Username:\n"))
        {
            break;
        }
        fputs(charline, budOpen);
    }
    fclose(fileOpen);
    fclose(budOpen);

    return "userBud.txt";
}