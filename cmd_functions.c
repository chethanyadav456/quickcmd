/*
 *   cmd_functions.c
 *
 *   Created on: Sep 15, 2024
 *   Created by: M Chethan Yadav
 *   Under License of MIT
 *
 */

#include "cmd_functions.h"

void printfNewLine(char *str);
void ipaddr();
int hostname();
void display_help();

// Function to retrieve and display the local machine's IP addresses
void ipaddr()
{
#ifdef _WIN32
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

#else
    struct ifaddrs *ifaddr, *ifa;
    char ipstr[INET_ADDRSTRLEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            if (inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, ipstr, sizeof(ipstr))) {
                printf("Adapter Name: %s\n", ifa->ifa_name);
                printf("IP Address: %s\n", ipstr);
            } else {
                perror("inet_ntop");
            }
        }
    }

    freeifaddrs(ifaddr);
#endif
}

// Function to get and display the local machine's hostname
int hostname()
{
#ifdef _WIN32
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
#else
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("gethostname");
        return EXIT_FAILURE;
    }
#endif

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
