/*
 *   main.c
 *
 *   Created on: Sep 15, 2024
 *   Created by: M Chethan Yadav
 *   Under License of MIT
 *
 */

#include <stdio.h>
#include <string.h>
#include "cmd_functions.h"

int main()
{
    char getCmd[100];
    printf("%c]0;%s%c", '\033', "Quick CMD", '\007');
    printf("\n\tTerminal\t");
    while (1)
    {
        printf("\nEnter the Command: ");
        scanf("%99s", getCmd);

        if (strcmp(getCmd, "exit") == 0)
        {
            printf("Exiting program.\n");
            break;
        }

        if (strcmp(getCmd, "ipaddr") == 0)
        {
            ipaddr();
        }
        else if (strcmp(getCmd, "help") == 0)
        {
            display_help();
        }
        else if (strcmp(getCmd, "hostname") == 0)
        {
            hostname();
        }
        else
        {
            printf("Invalid Command! Type \"help\" for more commands.");
        }
    }

    return 0;
}
