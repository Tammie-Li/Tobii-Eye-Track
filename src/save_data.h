#ifndef _SAVE_DATA_H
#define _SAVE_DATA_H

#include "globol.h"
#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <fstream>
#include "../tobii/tobii.h"
#include "../tobii/tobii_streams.h"

extern char url[256];
extern tobii_api_t* api;
extern tobii_device_t* device;
extern tobii_error_t result;

extern int index_suc;
extern int index_all;
extern int success[SUCCESS_TIME];
extern bool flag_success;

void gaze_point_callback( tobii_gaze_point_t const* gaze_point, void* /* user_data */);
void get_save_data(tobii_device_t* device, int timeLength);
void start_listen(tobii_device_t* device);

#endif