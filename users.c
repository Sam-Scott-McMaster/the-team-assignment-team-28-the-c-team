#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    char charline[1024];
    int passLine;
    bool presentUser = false;
    bool signedIn = false;
    int lineNum = 0;

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
    fprintf(fileOpen, "TRANSACTIONS:\n\n");
    fprintf(fileOpen, "BUDGET:\n\n");

    printf("\nAccount Creation Successful!\n");
    fclose(fileOpen);
    strcpy(signedInUser, userName);
    return;
}

void writeTransaction(char *signedInUser, char *transaction)
{
    FILE *fileOpen = fopen("dataBase.txt", "r");
    if (fileOpen == NULL)
    {
        printf("Error: Could not open the file.\n");
        return;
    }

    char charline[1024];
    char buffer[10000] = "";
    int foundUser = 0, foundTransactions = 0;

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        strcat(buffer, charline);

        if (!foundUser && strncmp(charline, "Username: ", 10) == 0 && strncmp(charline + 10, signedInUser, strlen(signedInUser)) == 0 && charline[10 + strlen(signedInUser)] == '\n')
        {
            foundUser = 1;
        }

        if (foundUser && strncmp(charline, "TRANSACTIONS:\n", 14) == 0)
        {
            foundTransactions = 1;
            strcat(buffer, transaction);
            strcat(buffer, "\n");
            foundUser = 0;
        }
    }

    fclose(fileOpen);

    if (!foundUser && !foundTransactions)
    {
        printf("Error: TRANSACTIONS section not found for user '%s'.\n", signedInUser);
        return;
    }

    fileOpen = fopen("dataBase.txt", "w");
    if (fileOpen == NULL)
    {
        printf("Error: Could not reopen the file for writing.\n");
        return;
    }

    fputs(buffer, fileOpen);
    fclose(fileOpen);

    printf("Transaction added successfully for user '%s'.\n", signedInUser);
}

void writeBudget(char *signedInUser, char *Budget)
{
    FILE *fileOpen = fopen("dataBase.txt", "r");
    if (fileOpen == NULL)
    {
        printf("Error: Could not open the file.\n");
        return;
    }

    char charline[1024];
    char buffer[10000] = "";
    int foundUser = 0, foundBudget = 0, skipNextLine = 0;

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        // Check if we need to skip the next line (line under BUDGET:)
        if (skipNextLine)
        {
            skipNextLine = 0;       // Skip the current line and reset flag
            strcat(buffer, Budget); // Replace it with the new budget
            strcat(buffer, "\n");
            foundBudget = 1; // Mark that budget was updated
            continue;
        }

        // Append the current line to the buffer
        strcat(buffer, charline);

        // Check if this line contains the username
        if (!foundUser && strncmp(charline, "Username: ", 10) == 0 &&
            strncmp(charline + 10, signedInUser, strlen(signedInUser)) == 0 &&
            charline[10 + strlen(signedInUser)] == '\n')
        {
            foundUser = 1; // User found
        }

        // Check if this line is the BUDGET header for the found user
        if (foundUser && strncmp(charline, "BUDGET:\n", 8) == 0)
        {
            skipNextLine = 1; // Mark to skip the next line
        }
    }

    fclose(fileOpen);

    if (!foundUser || !foundBudget)
    {
        printf("Error: BUDGET section not found or could not be updated for user '%s'.\n", signedInUser);
        return;
    }

    // Open the file for writing and update it
    fileOpen = fopen("dataBase.txt", "w");
    if (fileOpen == NULL)
    {
        printf("Error: Could not reopen the file for writing.\n");
        return;
    }

    fputs(buffer, fileOpen);
    fclose(fileOpen);

    printf("Budget updated successfully for user '%s'.\n", signedInUser);
}

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

char *allBud(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    FILE *budOpen = fopen("userBud.txt", "w+");
    char charline[1024];
    int lineNum = 0;
    int trans = 0;

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, signedInUser))
        {
            trans = lineNum;
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, "TRANSACTIONS:\n"))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, "BUDGET:\n"))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
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