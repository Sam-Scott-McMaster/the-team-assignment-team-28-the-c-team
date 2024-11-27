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
    }
    else
    {
        printf("Wrong Username or Password\n");
    }

    strcpy(signedInUser, userName);

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

void writeTransaction(char *signedInUser, char *Transaction)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    char charline[1024];
    int lineNum = 0;

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, signedInUser))
        {
            break;
        }
    }

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, "TRANSACTIONS:\n"))
        {
            fprintf(fileOpen, "%s", Transaction);
            break;
        }
    }
    fclose(fileOpen);
}

void writeBudget(char *signedInUser, char *Budget)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
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
            fprintf(fileOpen, "%s", Budget);
            break;
        }
    }
    fclose(fileOpen);
}

char *allTrans(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    FILE *transOpen = fopen("userTrans.txt", "w+");
    char charline[1024];
    int lineNum = 0;

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, signedInUser))
        {
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