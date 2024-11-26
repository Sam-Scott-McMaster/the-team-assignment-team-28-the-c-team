#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
        printf("Enter User Name: \n");
        scanf("%s", userName);

        while (fgets(charline, sizeof(charline), fileOpen))
        {
            lineNum++;
            if (strstr(charline, userName))
            {
                printf("User Name already exits, please try again \n");
                presentUser = true;
                break;
            }
        }
        if (!presentUser)
        {
            break;
        }
    }

    printf("Enter Password: \n");
    scanf("%s", password);
    fseek(fileOpen, 0, SEEK_END);

    fprintf(fileOpen, "\nUsername: %s", userName);
    fprintf(fileOpen, "\nPassword: %s", password);

    printf("\nAccount Creation Successful! \n");

    return;
}