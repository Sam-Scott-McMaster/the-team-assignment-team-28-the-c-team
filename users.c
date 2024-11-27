#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void checkUser(char *signedInUser)
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
    int passLine;
    bool presentUser = false;
    bool signedIn = false;
    int lineNum;
    lineNum = 0;

    printf("Enter User Name: ");
    scanf("%s", userName);

    char prompt[250];

    strcpy(prompt, "Username: ");
    strcat(prompt, userName);

    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if (strstr(charline, prompt))
        {
            presentUser = true;
            passLine = lineNum + 1;
            break;
        }
    }

    printf("\n Enter Password: ");
    scanf("%s", password);

    prompt[0] = '\0';

    strcpy(prompt, "Password: ");
    strcat(prompt, password);

    lineNum = 0;
    while (fgets(charline, sizeof(charline), fileOpen))
    {
        lineNum++;
        if ((lineNum == passLine) && (strstr(charline, prompt)))
        {
            signedIn = true;
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
    close(fileOpen);
    return;
}

void addUser()
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
        lineNum = 0;
        printf("Enter User Name:");
        scanf("%s", userName);

        while (fgets(charline, sizeof(charline), fileOpen))
        {
            lineNum++;
            if (strstr(charline, userName))
            {
                printf("\n User Name already exits, please try again \n");
                presentUser = true;
                break;
            }
        }
        if (!presentUser)
        {
            break;
        }
    }

    printf("\nEnter Password:");
    scanf("%s", password);
    fseek(fileOpen, 0, SEEK_END);

    fprintf(fileOpen, "\nUsername: %s", userName);
    fprintf(fileOpen, "\nPassword: %s", password);

    fprintf(fileOpen, "\n");
    fprintf(fileOpen, "TRANSACTIONS:\n");

    fprintf(fileOpen, "\n");
    fprintf(fileOpen, "BUDGET:\n");

    printf("\nAccount Creation Successful!\n");
    close(fileOpen);
    return;
}

void writeTransaction(char *signedInUser, char Transaction)
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
            fprintf(fileOpen, "%s", Transaction);
            break;
        }
    }
    close(fileOpen);
}

void writeBudget(char *signedInUser, char Budget)
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
    close(fileOpen);
}

char *allTrans(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    FILE *transOpen = fopen("userTrans.txt", "r+");
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
        fputs(charline, transOpen);
    }
    close(fileOpen);
    close(transOpen);

    return "userTrans.txt";
}

char *allBud(char *signedInUser)
{
    FILE *fileOpen = fopen("dataBase.txt", "r+");
    FILE *budOpen = fopen("userBud.txt", "r+");
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
    close(fileOpen);
    close(budOpen);
}