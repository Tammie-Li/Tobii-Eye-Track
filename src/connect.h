#ifndef _CONNECT_H
#define _CONNECT_H

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "../tobii/tobii.h"
#include "../tobii/tobii_streams.h"

extern char url[256];
extern tobii_api_t* api;
extern tobii_device_t* device;
extern tobii_error_t result;

void url_receiver(char const* url, void* user_data);
char* get_device(tobii_api_t* api);
tobii_api_t* api_create();
tobii_device_t* device_create(tobii_api_t*api, char* url);
void close_connect(tobii_device_t* device, tobii_api_t* api);

#endif