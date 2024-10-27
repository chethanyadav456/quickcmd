/*
 *   cmd_functions.h
 *
 *   Created on: Sep 15, 2024
 *   Created by: M Chethan Yadav
 *   Under License of MIT
 *
 */

#ifndef CMD_FUNCTIONS_H
#define CMD_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

// For Windows
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iphlpapi.h>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")

// For Linux
#else
#include <unistd.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

void ipaddr();
int hostname();
void display_help();
void printfNewLine(char *str);

#endif // CMD_FUNCTIONS_H
