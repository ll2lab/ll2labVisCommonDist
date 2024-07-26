#include <Arduino.h>

#ifndef LEDPANEL_H
#define LEDPANEL_H

#define FRAME_TYPE_COUNT        3
#define FRAME_TYPE_PANELCONTROL 0
#define FRAME_TYPE_ANALYSERDATA 1  
#define FRAME_TYPE_MATRIXCONFIG 2

#define LED_MAP_COUNT           3
#define LED_MAP_VISUAL          0
#define LED_MAP_PANEL           1
#define LED_MAP_MATRIX          2

#define FRAME_TX_BROADCAST      0
#define FRAME_TX_UNICAST        1

struct FrameConfig{
  uint32_t frameType;        // Frame type
  uint32_t frameHeaderSize;  // Frame header size (bytes)
  uint32_t frameDataSize;    // Frame data size (bytes)
  uint32_t frameTotalSize;   // Frame total size (bytes)
  uint32_t frameTime;        // Frame type last seen
  uint32_t packetHeaderSize; // Packet data size (bytes)
  uint32_t packetDataSize;   // Packet data size (bytes)
  uint32_t packetTotalSize;  // Packet size (bytes)
  uint32_t packetPerFrame;   // Packets per frame
};

struct FrameHeader{
  uint8_t  txType;          // Frame broadcast or unicast
  uint8_t  rxMac[6];        // Matrix MAC address for unicast
};

struct PacketHeader{
  uint32_t frameType;        // Frame type
  uint32_t packetHeaderSize; // Packet header size (bytes)
  uint32_t packetDataSize;   // Packet data size (bytes)
  uint32_t packetPerFrame;   // Packets per frame
  uint32_t packetInFrame;    // Packets number in frame
};

#define VIS_HSV_NUM   3UL
#define VIS_HSV_HUE   0UL
#define VIS_HSV_SAT   1UL
#define VIS_HSV_VAL   2UL

struct HSVCfg{                          // helper struct for component definition

  uint32_t drv;        // component driver
  uint32_t ini;        // component range initial (0-255)
  uint32_t rng_min;    // component range minimum (0-255)
  uint32_t rng_max;    // component range maximum (0-255)
  uint32_t fil_min;    // component led minimum (0-255)
  uint32_t fil_max;    // component led maximum (0-255)
  int32_t  bnd_del;    // component output delta per bin
  int32_t  frm_del;    // component frame delta
  float    dcy;        // component frame decay multiplier
  bool     per;        // component persist value if > new fft value
};

struct MapCfg{
  uint8_t  id;         // MapCfg ID
  uint32_t dim_x;      // MapCfg dimension x
  uint32_t dim_y;      // MapCfg dimension y
  uint32_t dim_z;      // MapCfg dimension z
  int32_t  pos_x;      // MapCfg position x
  int32_t  pos_y;      // MapCfg position y
  int32_t  pos_z;      // MapCfg position z
  int32_t  rev_x;      // MapCfg reverse over x
  int32_t  rev_y;      // MapCfg reverse over y
  int32_t  rev_z;      // MapCfg reverse over z  
  int32_t  piv_x;      // MapCfg pivot x
  int32_t  piv_y;      // MapCfg pivot y
  int32_t  piv_z;      // MapCfg pivot z
  int32_t  rot_x;      // MapCfg rotation about pivot x (degrees)
  int32_t  rot_y;      // MapCfg rotation about pivot y (degrees)
  int32_t  rot_z;      // MapCfg rotation about pivot z (degrees) 
  int32_t  ref_x;      // MapCfg reflect over x
  int32_t  ref_y;      // MapCfg reflect over y
  int32_t  ref_z;      // MapCfg reflect over z 
  bool     is_rev_x;   // MapCfg reverse x
  bool     is_rev_y;   // MapCfg reverse y
  bool     is_rev_z;   // MapCfg reverse z   
  bool     is_rot_x;   // MapCfg rotate x
  bool     is_rot_y;   // MapCfg rotate y
  bool     is_rot_z;   // MapCfg rotate z     
  bool     is_ref_x;   // MapCfg reflect x
  bool     is_ref_y;   // MapCfg reflect y
  bool     is_ref_z;   // MapCfg reflect z    
  uint32_t led_i;      // MapCfg relative intensity (% of parent/max intensity)  
};

struct MapPre{
  int32_t  pos_x0;     // MapPre position x0
  int32_t  pos_x1;     // MapPre position x1
  int32_t  pos_y0;     // MapPre position y0
  int32_t  pos_y1;     // MapPre position y1
  int32_t  pos_z0;     // MapPre position z0
  int32_t  pos_z1;     // MapPre position z1
  float    rot_x_sin;  // MapPre sin(x-axis rotation)  
  float    rot_y_sin;  // MapPre sin(y-axis rotation)  
  float    rot_z_sin;  // MapPre sin(z-axis rotation)  
  float    rot_x_cos;  // MapPre cos(x-axis rotation)  
  float    rot_y_cos;  // MapPre cos(y-axis rotation)  
  float    rot_z_cos;  // MapPre cos(z-axis rotation) 
  uint32_t led_n;      // MapPre number of leds
  uint8_t  led_i;      // MapPre absolute intensity
};

struct SetCfg{
};

struct PnlCfg{
};

struct BrdCfg{
};

struct VisCfg{
  uint32_t  pat;       // Visual pattern
  uint32_t  bnd;       // Visual bands
  uint32_t  stt;       // Visual frame start
  uint32_t  stp;       // Visual frame stop
  uint32_t  inc;       // Visual frame increment per loop
  uint32_t  div;       // Visual frame divisor
  float     min;       // Visual active minimum
  float     max;       // Visual active maximum
  float     dcy;       // Visual value decay
  bool      per;       // Visual value persist
  HSVCfg    hsv[3];    // Visual HSV component configs
};

struct MtxCfg{

  uint8_t   mac[6];    // Matrix MAC address
  uint8_t   pin;       // Matrix SPI pin
  struct{
    SetCfg   cfg;      // Set configuration
  } set;                
  struct{
    MapCfg   map;      // Panel map
    PnlCfg   cfg;      // Panel configuration
  } pnl;
  struct{
    MapCfg   map;      // Board map
    BrdCfg   cfg;      // Board configuration
  } brd;
  struct{
    MapCfg   map;      // Visual map
    VisCfg   cfg;      // Visual configuration
  } vis;
};

struct PanelControl{
  bool     panel_rst;
  bool     panel_run;  
  uint32_t panel_frm_mrk;        
};

struct AnalyserData{
        uint32_t analyser_frm_num;
        float    analyser_var_bnd[64];
};

class LEDPanel{

  public:
    LEDPanel();
   ~LEDPanel();

    void  addMatrix(const char* mac);

    MtxCfg matrix[4];
    uint32_t  matrix_next;
};

#endif
