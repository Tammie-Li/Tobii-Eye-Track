#ifndef _SERVER_H
#define _SERVER_H

#include "globol.h"

extern WSADATA wsaData;
extern char buffer[BUF_SIZE];  //缓冲区大小
extern SOCKET sock;
extern sockaddr_in servAddr;
extern SOCKADDR clintAddr;
extern int nSize;

void init_server();
void close_udp(SOCKET sock);

#endif