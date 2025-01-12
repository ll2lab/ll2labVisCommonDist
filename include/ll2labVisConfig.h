#ifndef LL2_LAB_VIS_CONFIG_H
#define LL2_LAB_VIS_CONFIG_H

#include <Arduino.h>

// COMMON CONTROL CONSTANTS

#define WDT_TIMEOUT              3UL             // Watchdog timeout 

// COMMON COMMS CONSTANTS

#define UI_HOST_HTTP_URL         "http://visualiser.labservice.ll2.network" // Configuration UI http URL

#define COMM_HOST_BAUD           115200UL        // Common device to host serial baud rate
#define COMM_INTER_BAUD          460800UL        // Common device to device serial baud rate  
#define COMM_FRAME_SOF           217UL           // Common device to device serial Start Of Frame  

#define CTRL_HOST_IP_ADDRESS     192,168, 50,239 // Controller IP address
#define CTRL_HOST_IP_NETMASK     255,255,255,  0 // Controller IP network mask
#define CTRL_HOST_IP_GATEWAY     192,168, 50,  1 // Controller IP gatway
#define CTRL_HOST_HTTP_PORT      80UL            // Controller http port
#define CTRL_HOST_HTTP_URL       "http://viscontrol.labservice.ll2.network" // Controller http URL

#define CTRL_HOST_SERIAL         Serial          // Controller to Host serial connection
#define CTRL_HOST_BAUD           COMM_HOST_BAUD  // Controller to Host serial baud rate
#define CTRL_SEND_SERIAL         Serial1         // Controller to Sender serial connection
#define CTRL_SEND_BAUD           COMM_INTER_BAUD // Controller to Sender serial baud ratw

#define SEND_HOST_SERIAL         Serial          // Sender to Host serial connection
#define SEND_HOST_BAUD           COMM_HOST_BAUD  // Sender to Host serial baud rate
#define SEND_CTRL_SERIAL         Serial2         // Sender to Controller serial connection   
#define SEND_CTRL_BAUD           COMM_INTER_BAUD // Sender to Controller serial baud rate

#define ESPNOW_SEND_MAC          0x94,0x3C,0xC6,0x32,0xE3,0x38 // Sender MAC address
#define ESPNOW_BROADCAST_MAC     0xFF,0xFF,0xFF,0xFF,0xFF,0xFF // Sender MAC broadcast
#define ESPNOW_PACKET_MAX        250UL           // Packet size limit for ESP_NOW

#ifdef ARDUINO_ESP32S3_DEV
  #define RECV_LED_PIN             1UL             // ESP32-S3-Zero LED matrix pin
#else 
  #define RECV_LED_PIN             23UL            // ESP32-Devkit-4 LED matrix pin
#endif

// COMMON FRAME CONSTANTS AND STRUCTURES

//#define FRAME_TX_BROADCAST       0UL     // Frame is broadcast
//#define FRAME_TX_UNICAST         1UL     // Frame is unicast

// LOGGING CONTROL

#define CTRL_LOG                 true    // Controller general logging on/off
#define SEND_LOG                 true    // Sender general logging on/off
#define RECV_LOG                 false   // Receiver general logging on/off


// PERFORMANCE CONTROL

#define CTRL_PERF                true    // Controller performance measurement on/off
#define CTRL_PERF_PERIOD         10000UL // Controller performance measurement period (ms)
#define SEND_PERF                true    // Sender performance measurement on/off
#define SEND_PERF_PERIOD         10000UL // Sender performance measurement period (ms)
#define RECV_PERF                true    // Receiver performance measurement on/off
#define RECV_PERF_PERIOD         10000UL // Receiver performance measurement period (ms)


// DYNAMICS CONTROL

#define CTRL_SEND_BG_PERIOD      2500UL  // Controller period between background matrix configuration sends (x data frame sends)
#define RECV_DATA_TIMEOUT        1000UL  // Reciever data connection lost time out


// MEMORY ALLOCATION 

#define ANA_MAX_BANDS            64UL    // Analsyer maximum bands
#define CONFIG_PANEL_MAX         1UL     // Max panels per set
#define CONFIG_BOARD_MAX         8UL     // Max boards per panel
#define CONFIG_SCENE_MAX         1UL     // Max scenes per set
#define CONFIG_VISUAL_MAX        2UL     // Max visuals per scene
#define CONFIG_PULSE_MAX         2UL     // Max pulses per visual

// SHARED CONSTANTS AND STRUCTURES

#define LED_MAP_SET              0UL     // Map for set (not yet used)
#define LED_MAP_PANEL            1UL     // Map for panel
#define LED_MAP_MATRIX           2UL     // Map for matrix
#define LED_MAP_VISUAL           3UL     // Map for visual

#define VIS_HSV_NUM              3UL     // HSV component count
#define VIS_HSV_HUE              0UL     // HSV hue
#define VIS_HSV_SAT              1UL     // HSV saturation
#define VIS_HSV_VAL              2UL     // HSV value

// Component driver configuration
#define VIS_DRV_CON              0UL     // VIsual HSV constant driver
#define VIS_DRV_AUT              1UL     // VIsual HSV automatic driver
#define VIS_DRV_FFT              2UL     // VIsual HSV fft driver

// Pattern configuration                 // Visual patterns
#define VIS_PAT_NORSP            0UL      
#define VIS_PAT_AMPLI            1UL
#define VIS_PAT_EVENS            2UL
#define VIS_PAT_PEAKS            3UL
#define VIS_PAT_FLEXI            8UL
#define VIS_PAT_CLOCK            9UL
#define VIS_PAT_UPDATING         10UL

// Animation configuration
#define LED_ANI_SPAN             0UL     // Animation is span
#define LED_ANI_PULSE            1UL     // Animation is pulse

// Complexity limits
#define SCN_VIS_MAX              9       // Max visuals per scene
#define VIS_PLS_MAX              9       // Max pulses per visual

// Utilities

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#endif
