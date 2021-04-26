#include "save_data.h"


void gaze_point_callback( tobii_gaze_point_t const* gaze_point, void* /* user_data */)
{
    // Check that the data is valid before using it
    // std::cout << gaze_point->timestamp_us << std::endl;
    if(gaze_point->validity == TOBII_VALIDITY_VALID)
    {
        // printf( "Gaze point: %f, %f\n", gaze_point->position_xy[0], gaze_point->position_xy[1]);
        std::cout << "gaze point: " << gaze_point->position_xy[0] << "\t" << gaze_point->position_xy[1] << \
                    "\t" << gaze_point->timestamp_us << std::endl;
        // 追加形式保存数据
        std::ofstream saveFile("D:\\tobii-eye-tracker\\data\\data.txt", std::ios::app);
        saveFile << gaze_point->position_xy[0] << "\t\t" << gaze_point->position_xy[1] << "\n";
        saveFile.close();
        flag_success = true;
    }
    else{
        std::cout << "your eye is out of the screnn" << "\t" << gaze_point->timestamp_us << std::endl;
    }
}


void get_save_data(tobii_device_t* device, int timeLength)
{ 
    for( int i=0; i<timeLength; i++)
    {
        // Optionally block this thread until data is available. Especially useful if running in a separate thread.
        result = tobii_wait_for_callbacks(1, &device);
        assert( result == TOBII_ERROR_NO_ERROR || result == TOBII_ERROR_TIMED_OUT );

        // Process callbacks on this thread if data is available
        result = tobii_device_process_callbacks(device);
        assert( result == TOBII_ERROR_NO_ERROR );
    }
    // 保存成功的索引值
    if(flag_success)
    {
        success[index_suc] = index_all;
        std::ofstream saveFile("D:\\tobii-eye-tracker\\data\\index.txt", std::ios::app);
        saveFile << index_all << "\n";
        saveFile.close();
        index_suc = index_suc + 1;
        
    }
    index_all = index_all + 1;
    flag_success = false;
    std::cout << index_suc << std::endl;
    std::cout << index_all << std::endl;
}

void start_listen(tobii_device_t* device)
{
    result = tobii_gaze_point_subscribe(device, gaze_point_callback, 0);
    assert(result == TOBII_ERROR_NO_ERROR );
}
