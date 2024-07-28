#include <Arduino.h>

#ifndef LEDCOMMON_H
#define LEDCOMMON_H

// COMMON COMMS CONSTANTS

#define COMM_HOST_BAUD           115200UL        // Common device to host serial baud rate
#define COMM_INTER_BAUD          460800UL        // Common device to device serial baud rate  
#define COMM_FRAME_SOF           217UL           // Common device to device serial Start Of Frame  

#define CTRL_HOST_IP_ADDRESS     192,168, 50,239 // Controller IP address
#define CTRL_HOST_IP_NETMASK     255,255,255,  0 // Controller IP network mask
#define CTRL_HOST_IP_GATEWAY     192,168, 50,  1 // Controller IP gatway
#define CTRL_HOST_HTTP_PORT      80UL            // Controller http port
#define CTRL_HOST_SERIAL         Serial          // Controller to Host serial connection
#define CTRL_HOST_BAUD           COMM_HOST_BAUD  // Controller to Host serial baud rate
#define CTRL_SEND_SERIAL         Serial1         // Controller to Sender serial connection
#define CTRL_SEND_BAUD           COMM_INTER_BAUD // Controller to Sender serial baud ratw

#define SEND_HOST_SERIAL         Serial          // Sender to Host serial connection
#define SEND_HOST_BAUD           COMM_HOST_BAUD  // Sender to Host serial baud rate
#define SEND_CTRL_SERIAL         Serial2         // Sender to Controller serial connection   
#define SEND_CTRL_BAUD           COMM_INTER_BAUD // Sender to Controller serial baud rate
#define SEND_LOCAL_MAC           0x94,0x3C,0xC6,0x32,0xE3,0x38 // Sender MAC address
#define SEND_BROADCAST_MAC       0xFF,0xFF,0xFF,0xFF,0xFF,0xFF // Sender MAC broadcast

#define ESPNOW_PACKET_MAX        250UL           // Packet size limit for ESP_NOW

#define RECV_LED_PIN             23UL            // ESP32 LED matrix pin


// COMMON FRAME CONSTANTS AND STRUCTURES

#define FRAME_TX_BROADCAST       0UL                     // Frame is broadcast
#define FRAME_TX_UNICAST         1UL                     // Frame is unicast

struct FrameConfig{                      // Frame config (calculated)
  uint32_t frameType;                    // Frame type
  uint32_t frameHeaderSize;              // Frame header size (bytes)
  uint32_t frameDataSize;                // Frame data size (bytes)
  uint32_t frameTotalSize;               // Frame total size (bytes)
  uint32_t frameTime;                    // Frame type last seen
  uint32_t packetHeaderSize;             // Packet data size (bytes)
  uint32_t packetDataSize;               // Packet data size (bytes)
  uint32_t packetTotalSize;              // Packet size (bytes)
  uint32_t packetPerFrame;               // Packets per frame
};

struct FrameHeader{                      // ESP_Now frame header
  uint8_t  txType;                       // Frame broadcast or unicast
  uint8_t  rxMac[6];                     // Matrix MAC address for unicast
};

struct PacketHeader{                     // ESP_Now packet header
  uint32_t frameType;                    // Frame type
  uint32_t packetHeaderSize;             // Packet header size (bytes)
  uint32_t packetDataSize;               // Packet data size (bytes)
  uint32_t packetPerFrame;               // Packets per frame
  uint32_t packetInFrame;                // Packets number in frame
};


// LOGGING CONTROL

#define CTRL_LOG                 true    // Controller general logging on/off
#define SEND_LOG                 true    // Sender general logging on/off
#define RECV_LOG                 true    // Receiver general logging on/off


// PERFORMANCE CONTROL

#define CTRL_PERF                true    // Controller performance measurement on/off
#define CTRL_PERF_PERIOD         256UL   // Controller performance measurement period (x data frame sends)
#define SEND_PERF                true    // Sender performance measurement on/off
#define SEND_PERF_PERIOD         10000UL // Sender performance measurement period (ms)
#define RECV_PERF                true    // Receiver performance measurement on/off
#define RECV_PERF_PERIOD         10000UL // Receiver performance measurement period (ms)


// DYNAMICS CONTROL

#define CTRL_SEND_BG_PERIOD      360UL   // Controller period between background matrix configuration sends (x data frame sends)
#define RECV_DATA_TIMEOUT        1000UL  // Reciever data connection lost time out

// MEMORY ALLOCATION 

#define ANA_MAX_BANDS           64UL     // Analsyer maximum bands

// SHARED FRAME TYPES, CONSTANTS AND STRUCTURES

#define FRAME_TYPE_COUNT         3UL     // Frame type count
#define FRAME_TYPE_PANELCONTROL  0UL     // Panel control frame
#define FRAME_TYPE_MATRIXCONFIG  1UL     // Matrix config frame
#define FRAME_TYPE_ANALYSERDATA  2UL     // Analyser data frame 

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
#define VIS_PAT_STAND            1UL
#define VIS_PAT_EVENS            3UL
#define VIS_PAT_SPLIT            4UL
#define VIS_PAT_LIMIT            5UL
#define VIS_PAT_SHOTS            6UL
#define VIS_PAT_BUMPS            7UL
#define VIS_PAT_PINGS            8UL
#define VIS_PAT_SHOT2            9UL
#define VIS_PAT_DIAGS            10UL
#define VIS_PAT_TEST             11UL

#define LED_ANI_SPAN             0UL     // Animation is span
#define LED_ANI_PULSE            1UL     // Animation is pulse

struct MapConfig{
  uint32_t dim_x;                        // Map dimension x
  uint32_t dim_y;                        // Map dimension y
  uint32_t dim_z;                        // Map dimension z
  int32_t  pos_x;                        // Map position x
  int32_t  pos_y;                        // Map position y
  int32_t  pos_z;                        // Map position z
  int32_t  rev_x;                        // Map reverse over x
  int32_t  rev_y;                        // Map reverse over y
  int32_t  rev_z;                        // Map reverse over z  
  int32_t  piv_x;                        // Map pivot x
  int32_t  piv_y;                        // Map pivot y
  int32_t  piv_z;                        // Map pivot z
  int32_t  rot_x;                        // Map rotation about pivot x (degrees)
  int32_t  rot_y;                        // Map rotation about pivot y (degrees)
  int32_t  rot_z;                        // Map rotation about pivot z (degrees) 
  int32_t  ref_x;                        // Map reflect over x
  int32_t  ref_y;                        // Map reflect over y
  int32_t  ref_z;                        // Map reflect over z 
  bool     is_rev_x;                     // Map reverse x
  bool     is_rev_y;                     // Map reverse y
  bool     is_rev_z;                     // Map reverse z   
  bool     is_rot_x;                     // Map rotate x
  bool     is_rot_y;                     // Map rotate y
  bool     is_rot_z;                     // Map rotate z     
  bool     is_ref_x;                     // Map reflect x
  bool     is_ref_y;                     // Map reflect y
  bool     is_ref_z;                     // Map reflect z    
  uint32_t led_i;                        // Map relative intensity (% of parent/max intensity)  
};

struct PanelControl{                      // Panel control
  bool     rst;                           // Reset
  bool     run;                           // Run
  uint32_t mrk;                           // Run frame mark
};

struct HSVConfig{                        // HSV component configuration
  uint32_t drv;                          // HSV component driver
  uint32_t ini;                          // HSV component range initial (0-255)
  uint32_t rng_min;                      // HSV component range minimum (0-255)
  uint32_t rng_max;                      // HSV component range maximum (0-255)
  uint32_t fil_min;                      // HSV component led minimum (0-255)
  uint32_t fil_max;                      // HSV component led maximum (0-255)
  int32_t  bnd_del;                      // HSV component output delta per bin
  int32_t  frm_del;                      // HSV component frame delta
  float    dcy;                          // HSV component frame decay multiplier
  bool     per;                          // HSV component persist value if > new fft value
};

struct SetConfig{                        // Set configuration
};

struct PanelConfig{                      // Panel configuration
};

struct BoardConfig{                      // Board configuration
};

struct VisualConfig{                     // Visual configuration
  uint32_t  pat;                         // Visual pattern
  uint32_t  low;                         // Visual band low
  uint32_t  hgh;                         // Visual band high
  uint32_t  stt;                         // Visual frame start
  uint32_t  stp;                         // Visual frame stop
  uint32_t  inc;                         // Visual frame increment per loop
  uint32_t  div;                         // Visual frame divisor
  float     min;                         // Visual active minimum
  float     max;                         // Visual active maximum
  float     dcy;                         // Visual value decay
  bool      per;                         // Visual value persist
  HSVConfig hsv[VIS_HSV_NUM];            // Visual HSV component configs
};

struct MatrixConfig{                     // Matrix configuration

  uint8_t       mac[6];                  // Matrix MAC address
  uint8_t       pin;                     // Matrix SPI pin
  struct{                                // Set 
    SetConfig   cfg;                     // Set configuration
  } set;                
  struct{                                // Panel 
    MapConfig    map;                    // Panel map
    PanelConfig  cfg;                    // Panel configuration
  } pnl;
  struct{                                // Board
    MapConfig    map;                    // Board map
    BoardConfig  cfg;                    // Board configuration
  } brd;
  struct{                                // Visual
    MapConfig    map;                    // Visual map
    VisualConfig cfg;                    // Visual configuration
  } vis;
};

struct AnalyserData{                     // Analyser data
  uint32_t frm;                          // Analyser frame number
  float    bnd_val[ANA_MAX_BANDS];       // Analyser band values
};


// Utilities

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#endif
