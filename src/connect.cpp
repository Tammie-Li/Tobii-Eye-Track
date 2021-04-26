#include "connect.h"

void url_receiver(char const* url, void* user_data)
{
    char* buffer = (char*)user_data;
    if( *buffer != '\0' ) return; // only keep first value

    if( strlen( url ) < 256)
        strcpy( buffer, url);
}

char* get_device(tobii_api_t* api)
{
    result = tobii_enumerate_local_device_urls( api, url_receiver, url);
    assert(result == TOBII_ERROR_NO_ERROR);
    if(*url == '\0')
    {
        printf("Error: No device found\n");
    }
    std::cout << "The device number is:\t";
    for(int i=0; i<256; i++)
       std::cout << url[i];
    std::cout << std::endl;

    return url;
}

tobii_api_t* api_create()
{
    tobii_error_t result = tobii_api_create(&api, NULL, NULL);
    assert(result == TOBII_ERROR_NO_ERROR);

    return api;
}

tobii_device_t* device_create(tobii_api_t*api, char* url)
{
    result = tobii_device_create(api, url, TOBII_FIELD_OF_USE_INTERACTIVE, &device);

    assert( result == TOBII_ERROR_NO_ERROR );

    return device;
}

void close_connect(tobii_device_t* device, tobii_api_t* api)
{
    // Cleanup
    result = tobii_gaze_point_unsubscribe(device);
    assert(result == TOBII_ERROR_NO_ERROR);
    result = tobii_device_destroy(device);
    assert(result == TOBII_ERROR_NO_ERROR);
    result = tobii_api_destroy(api);
    assert(result == TOBII_ERROR_NO_ERROR);
}