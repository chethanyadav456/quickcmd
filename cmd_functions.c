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
#include <iphlpapi.h> // For IP address retrieval
#pragma comment(lib, "Ws2_32.lib") // Link with Winsock library
#pragma comment(lib, "Iphlpapi.lib") // Link with IP Helper library

void printfNewLine(char *str);
void ipaddr();
int hostname();
void display_help();

// Function to retrieve and display the local machine's IP addresses
void ipaddr()
{
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;
    IP_ADAPTER_INFO *pAdapterInfo;
    IP_ADAPTER_INFO *pAdapter = NULL;

    // Allocate memory for the adapter info structure
    pAdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
    if (pAdapterInfo == NULL)
    {
        printf("Error allocating memory needed to call GetAdaptersInfo\n");
        return;
    }

    // Make an initial call to GetAdaptersInfo to get the necessary size of the buffer
    dwSize = sizeof(IP_ADAPTER_INFO);
    if (GetAdaptersInfo(pAdapterInfo, &dwSize) == ERROR_BUFFER_OVERFLOW)
    {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO *)malloc(dwSize);
        if (pAdapterInfo == NULL)
        {
            printf("Error allocating memory\n");
            return;
        }
    }

    // Call GetAdaptersInfo to get the adapter information
    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &dwSize)) == NO_ERROR)
    {
        pAdapter = pAdapterInfo;
        while (pAdapter)
        {
            printf("Adapter Name: %s\n", pAdapter->AdapterName);
            printf("IP Address: %s\n", pAdapter->IpAddressList.IpAddress.String);

            // Move to the next adapter in the list
            pAdapter = pAdapter->Next;
        }
    }
    else
    {
        printf("GetAdaptersInfo failed with error: %d\n", dwRetVal);
    }

    // Free allocated memory
    if (pAdapterInfo)
        free(pAdapterInfo);
}

// Function to get and display the local machine's hostname
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

// Function to display help commands
void display_help()
{
    printfNewLine("Available commands:");
    printfNewLine("  ipaddr - Display the IP address");
    printfNewLine("  help   - Show this help message");
    printfNewLine("  hostname   - Display the hostname");
    printfNewLine("  exit   - Exit the program");
}

// Utility function to print strings with a newline
void printfNewLine(char *str)
{
    printf("%s\n", str);
}
