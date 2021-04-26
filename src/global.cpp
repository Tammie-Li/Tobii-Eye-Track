#include "globol.h"



char url[256] = {0};
tobii_api_t* api = NULL;
tobii_device_t* device = NULL;
tobii_error_t result;

// 服务器部分参数
WSADATA wsaData;
char buffer[BUF_SIZE];  //缓冲区大小
SOCKET sock;
sockaddr_in servAddr;
SOCKADDR clintAddr;
int nSize;

int index_suc = 0;
int index_all = 0;
int success[SUCCESS_TIME] = {0};
bool flag_success = false;

