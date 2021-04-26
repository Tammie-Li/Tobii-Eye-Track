## 基于Tobii Eye Tracker 5的眼动采集程序

 使用Tobii公司的Eye Tracker 5采集实验者的眼动信号。本程序提供设备的初始化，基本采集功能以及简单的通信功能
### 准备

 - 安装设备驱动（这里直接在Windows设备管理器中更新就好）
 - 在菜单栏中打开Tobii Experience软件进行设备校准:exclamation:
 
 - 下载dll文件[Stream Engine 4.1.0 for Windows x64](https://developer.tobii.com/download-packages/stream-engine-4-1-0-for-windows-x64/?wpdmdl=12054&refresh=6086bad5cf1211619442389 "Download Stream Engine 4.1.0 for Windows x64")
 
### 文件结构

    . ├── .vscode
	  ├── bin 	 
		  ├── tobii_stream_engine.dll
	  ├── data
		  ├── data.txt
		  └── index.txt  
	  ├── lib
		  ├── tobii_stream_engine.dll
		  └── tobii_stream_engine.lib 
	  ├── src 
		  ├── connect.cpp 
		  └── connect.h 
		  └── global.cpp 
		  └── global.h
		  └── save_data.cpp
		  └── save_data.h
		  └── server.cpp
		  └── server.h
	  ├── tobii
		  ├── tobii.h 
		  └── tobii_streams.h 
	  ├── main.cpp
	  ├── Makefile
	  ├── README.md
	

 ### 使用方法
 进入文件目录, 执行以下指令，生成eyeTrack可执行文件（在bin目录下）
 

    make


 ### 免责声明
仅限用于学习和研究目的；不得将上述内容用于商业或者非法用途，否则，一切后果请用户自负