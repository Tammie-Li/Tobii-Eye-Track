#include "src/connect.h"
#include "src/save_data.h"
#include "src/server.h"

#define LENGTH 10

using namespace std;

int main()
{
    std::cout << "Hello, tobii" << std::endl;
    // Create API
    api = api_create();
    // Get Device Number
    char* ptr = get_device(api);
    ptr = url;
    // Create Device
    device = device_create(api, url);

    start_listen(device);
    init_server();
    // 每次收到指令 读取一次眼电信号
    while(true)
    {
        if(index_suc==SUCCESS_TIME)
        {
            break;
        }
        int strLen = recvfrom(sock, buffer, BUF_SIZE, 0, &clintAddr, &nSize);
        std::cout << buffer;
        if(buffer[0] == '8')
        {
            get_save_data(device, LENGTH);
        }
    }
    close_connect(device, api);

    close_udp(sock);
    return 0;
}
