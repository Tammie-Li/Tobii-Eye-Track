#ifndef _GLOBAL_H
#define _GLOBAL_H

#include "../tobii/tobii.h"
#include "../tobii/tobii_streams.h"
#include <winsock2.h>

#define BUF_SIZE 100
#define SUCCESS_TIME 1000

#pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll


// char url[256];
// tobii_api_t* api;
// tobii_device_t* device;
// tobii_error_t result;

// WSADATA wsaData;
// char buffer[BUF_SIZE];  //缓冲区大小
// SOCKET sock;
// sockaddr_in servAddr;
// SOCKADDR clintAddr;
// int nSize;

#endif