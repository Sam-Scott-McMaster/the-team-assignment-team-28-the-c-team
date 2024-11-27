#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void checkUser()
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

    printf("Enter User Name: \n");
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

    printf("Enter Password: \n");
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
    return;
}