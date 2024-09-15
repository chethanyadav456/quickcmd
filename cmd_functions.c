/*
 *   cmd_functions.c
 *
 *   Created on: Sep 15, 2024
 *   Created by: M Chethan Yadav
 *   Under License of MIT
 *
 */
#include "cmd_functions.h"
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "Ws2_32.lib") // Link with Winsock library

void ipaddr()
{
    printf("IP ADDRESS: 192.12.345.23\n");
}

int hostname()
{
    WSADATA wsaData;
    int result;

    // Initialize Winsock
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        printf("WSAStartup failed: %d\n", result);
        return EXIT_FAILURE;
    }

    char hostname[NI_MAXHOST]; // NI_MAXHOST defines the max hostname length

    // Get the hostname
    if (gethostname(hostname, sizeof(hostname)) == 0)
    {
        printf("Hostname: %s\n", hostname);
    }
    else
    {
        printf("gethostname failed: %d\n", WSAGetLastError());
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Clean up Winsock
    WSACleanup();
    return EXIT_SUCCESS;
}

void display_help()
{
    printf("Available commands:\n");
    printf("  ipaddr - Display the IP address\n");
    printf("  help   - Show this help message\n");
    printf("  hostname   - Display the hostname\n");
    printf("  exit   - Exit the program\n");
}
