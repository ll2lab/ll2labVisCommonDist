#include <Arduino.h>

#ifndef LEDCOMMON_H
#define LEDCOMMON_H

// COMMON FRAME CONSTANTS AND STRUCTURES

#define FRAME_TX_BROADCAST       0UL   // Frame is broadcast
#define FRAME_TX_UNICAST         1UL   // Frame is unicast

#define FRAME_TYPE_COUNT         3UL   // Frame type count
#define FRAME_TYPE_PANELCONTROL  0UL   // Panel control frame
#define FRAME_TYPE_MATRIXCONFIG  1UL   // Matrix config frame
#define FRAME_TYPE_ANALYSERDATA  2UL   // Analyser data frame 

struct FrameConfig{                    // Frame config (calculated)
  uint32_t frameType;                  // Frame type
  uint32_t frameHeaderSize;            // Frame header size (bytes)
  uint32_t frameDataSize;              // Frame data size (bytes)
  uint32_t frameTotalSize;             // Frame total size (bytes)
  uint32_t frameTime;                  // Frame type last seen
  uint32_t packetHeaderSize;           // Packet data size (bytes)
  uint32_t packetDataSize;             // Packet data size (bytes)
  uint32_t packetTotalSize;            // Packet size (bytes)
  uint32_t packetPerFrame;             // Packets per frame
};

struct FrameHeader{                    // ESP_Now frame header
  uint8_t  txType;                     // Frame broadcast or unicast
  uint8_t  rxMac[6];                   // Matrix MAC address for unicast
};

struct PacketHeader{                   // ESP_Now packet header
  uint32_t frameType;                  // Frame type
  uint32_t packetHeaderSize;           // Packet header size (bytes)
  uint32_t packetDataSize;             // Packet data size (bytes)
  uint32_t packetPerFrame;             // Packets per frame
  uint32_t packetInFrame;              // Packets number in frame
};


// SHARED FRAME CONSTANTS AND STRUCTURES

#define LED_MAP_SET              0UL   // Map for set (not yet used)
#define LED_MAP_PANEL            1UL   // Map for panel
#define LED_MAP_MATRIX           2UL   // Map for matrix
#define LED_MAP_VISUAL           3UL   // Map for visual

#define VIS_HSV_NUM              3UL   // HSV component count
#define VIS_HSV_HUE              0UL   // HSV hue
#define VIS_HSV_SAT              1UL   // HSV saturation
#define VIS_HSV_VAL              2UL   // HSV value
struct MapConfig{
  uint8_t  id;                         // Map ID
  uint32_t dim_x;                      // Map dimension x
  uint32_t dim_y;                      // Map dimension y
  uint32_t dim_z;                      // Map dimension z
  int32_t  pos_x;                      // Map position x
  int32_t  pos_y;                      // Map position y
  int32_t  pos_z;                      // Map position z
  int32_t  rev_x;                      // Map reverse over x
  int32_t  rev_y;                      // Map reverse over y
  int32_t  rev_z;                      // Map reverse over z  
  int32_t  piv_x;                      // Map pivot x
  int32_t  piv_y;                      // Map pivot y
  int32_t  piv_z;                      // Map pivot z
  int32_t  rot_x;                      // Map rotation about pivot x (degrees)
  int32_t  rot_y;                      // Map rotation about pivot y (degrees)
  int32_t  rot_z;                      // Map rotation about pivot z (degrees) 
  int32_t  ref_x;                      // Map reflect over x
  int32_t  ref_y;                      // Map reflect over y
  int32_t  ref_z;                      // Map reflect over z 
  bool     is_rev_x;                   // Map reverse x
  bool     is_rev_y;                   // Map reverse y
  bool     is_rev_z;                   // Map reverse z   
  bool     is_rot_x;                   // Map rotate x
  bool     is_rot_y;                   // Map rotate y
  bool     is_rot_z;                   // Map rotate z     
  bool     is_ref_x;                   // Map reflect x
  bool     is_ref_y;                   // Map reflect y
  bool     is_ref_z;                   // Map reflect z    
  uint32_t led_i;                      // Map relative intensity (% of parent/max intensity)  
};

struct PanelControl{                    // Panel control
  bool     rst;                         // Reset
  bool     run;                         // Run
  uint32_t mrk;                         // Run frame mark
};

struct HSVConfig{                      // HSV component configuration
  uint32_t drv;                        // HSV component driver
  uint32_t ini;                        // HSV component range initial (0-255)
  uint32_t rng_min;                    // HSV component range minimum (0-255)
  uint32_t rng_max;                    // HSV component range maximum (0-255)
  uint32_t fil_min;                    // HSV component led minimum (0-255)
  uint32_t fil_max;                    // HSV component led maximum (0-255)
  int32_t  bnd_del;                    // HSV component output delta per bin
  int32_t  frm_del;                    // HSV component frame delta
  float    dcy;                        // HSV component frame decay multiplier
  bool     per;                        // HSV component persist value if > new fft value
};

struct SetConfig{                      // Set configuration
};

struct PanelConfig{                    // Panel configuration
};

struct BoardConfig{                    // Board configuration
};

struct VisualConfig{                   // Visual configuration
  uint32_t  pat;                       // Visual pattern
  uint32_t  bnd;                       // Visual bands
  uint32_t  stt;                       // Visual frame start
  uint32_t  stp;                       // Visual frame stop
  uint32_t  inc;                       // Visual frame increment per loop
  uint32_t  div;                       // Visual frame divisor
  float     min;                       // Visual active minimum
  float     max;                       // Visual active maximum
  float     dcy;                       // Visual value decay
  bool      per;                       // Visual value persist
  HSVConfig hsv[3];                    // Visual HSV component configs
};

struct MatrixConfig{                   // Matrix configuration

  uint8_t       mac[6];                // Matrix MAC address
  uint8_t       pin;                   // Matrix SPI pin
  struct{                              // Set 
    SetConfig   cfg;                   // Set configuration
  } set;                
  struct{                              // Panel 
    MapConfig    map;                  // Panel map
    PanelConfig  cfg;                  // Panel configuration
  } pnl;
  struct{                              // Board
    MapConfig    map;                  // Board map
    BoardConfig  cfg;                  // Board configuration
  } brd;
  struct{                              // Visual
    MapConfig    map;                  // Visual map
    VisualConfig cfg;                  // Visual configuration
  } vis;
};

struct AnalyserData{                   // Analyser data
  uint32_t frm;                        // Analyser frame number
  float    analyser_var_bnd[64];       // Analyser band values
};

#endif
