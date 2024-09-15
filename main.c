/*
    *   main.c
    *
    *   Created on: Sep 15, 2024
    *   Created by: M Chethan Yadav
    *   Under Linence of MIT
    *
*/

#include <stdio.h>
#include <string.h> 
#include <ws2tcpip.h>

// Global variables
void ipaddr(); 
void display_help(); 
void hostname();

// Main function
int main() {
    char getCmd[100];
    printf("%c]0;%s%c", '\033', "Quick CMD", '\007');
    printf("\n\tTerminal\t");
    while (1) { 
        printf("\nEnter the Command: ");
        scanf("%99s", getCmd); 

        if (strcmp(getCmd, "exit") == 0) {
            printf("Exiting program.\n");
            break; 
        }

        if (strcmp(getCmd, "ipaddr") == 0) {
            ipaddr();
        } else if (strcmp(getCmd, "help") == 0) {
            display_help();
        } else if (strcmp(getCmd, "hostname") == 0) {
            hostname();
        } else {
            printf("Invalid Command! Type \"help\" for more commands.");
        }
    }

    return 0;
}

// Function definitions
void ipaddr() {
    printf("IP ADDRESS: 192.12.345.23\n");
}

void hostname() {
    printf("Loyola");
}

void display_help() {
    printf("Available commands:\n");
    printf("  ipaddr - Display the IP address\n");
    printf("  help   - Show this help message\n");
    printf("  hostname   - Display the hostname\n");
    printf("  exit   - Exit the program\n");
}
