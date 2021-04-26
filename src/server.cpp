#include "server.h"

#define BUF_SIZE 100

void init_server()
{
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    //绑定套接字
    memset(&servAddr, 0, sizeof(servAddr));  //每个字节都用0填充
    servAddr.sin_family = PF_INET;  //使用IPv4地址
    // servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取IP地址
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servAddr.sin_port = htons(1234);  //端口
    bind(sock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));
    //接收客户端请求
    nSize = sizeof(SOCKADDR);
}


void close_udp(SOCKET sock)
{
    closesocket(sock);
    WSACleanup();
}


