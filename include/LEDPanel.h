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

struct HSVConfig{                          // helper struct for component definition

  uint32_t    hsv_hsv_drv;              // component driver

  uint32_t    hsv_rng_ini;              // component range initial (0-255)
  uint32_t    hsv_rng_min;              // component range minimum (0-255)
  uint32_t    hsv_rng_max;              // component range maximum (0-255)

  uint32_t    hsv_bnd_min;              // component led minimum (0-255)
  uint32_t    hsv_bnd_max;              // component led maximum (0-255)

  int32_t     hsv_bnd_del;              // component output delta per bin
  int32_t     hsv_frm_del;              // component frame delta
  float       hsv_frm_dcy;              // component frame decay multiplier

  bool        hsv_out_per;              // component persist value if > new fft value
};

struct Mappable{
  uint8_t  id;         // Mappable ID
  uint32_t dim_x;      // Mappable dimension x
  uint32_t dim_y;      // Mappable dimension y
  uint32_t dim_z;      // Mappable dimension z
  int32_t  pos_x;      // Mappable position x
  int32_t  pos_y;      // Mappable position y
  int32_t  pos_z;      // Mappable position z
  int32_t  rev_x;      // Mappable reverse over x
  int32_t  rev_y;      // Mappable reverse over y
  int32_t  rev_z;      // Mappable reverse over z  
  bool     is_rev_x;   // Mappable reverse x
  bool     is_rev_y;   // Mappable reverse y
  bool     is_rev_z;   // Mappable reverse z   
  int32_t  piv_x;      // Mappable pivot x
  int32_t  piv_y;      // Mappable pivot y
  int32_t  piv_z;      // Mappable pivot z
  int32_t  rot_x;      // Mappable rotation about pivot x (degrees)
  int32_t  rot_y;      // Mappable rotation about pivot y (degrees)
  int32_t  rot_z;      // Mappable rotation about pivot z (degrees) 
  int32_t  ref_x;      // Mappable reflect over x
  int32_t  ref_y;      // Mappable reflect over y
  int32_t  ref_z;      // Mappable reflect over z 
  bool     is_ref_x;   // Mappable reflect x
  bool     is_ref_y;   // Mappable reflect y
  bool     is_ref_z;   // Mappable reflect z    
  uint32_t led_i;      // Mappable intensity (% of parent/max intensity)  
};

struct MappableCalc{
  int32_t  pos_x0;
  int32_t  pos_x1;
  int32_t  pos_y0;
  int32_t  pos_y1;
  int32_t  pos_z0;
  int32_t  pos_z1;  
  float    rot_x_sin;  
  float    rot_y_sin;  
  float    rot_z_sin;  
  float    rot_x_cos;  
  float    rot_y_cos;  
  float    rot_z_cos; 
  uint32_t led_n;
  uint8_t  led_i;
};

struct MatrixConfig{

  uint8_t   mac[6];            // Matrix MAC address
  uint8_t   pin;               // Matrix SPI pin

  Mappable  panel;             // Panel mappable configuration
  Mappable  matrix;            // Matrix mappable configuration
  Mappable  visual;            // Visual mappable configuration

  float     visual_inp_thr;
  uint32_t  visual_frm_ini;
  uint32_t  visual_frm_div;
  uint32_t  visual_frm_inc;
  uint32_t  visual_pat_sel;
  HSVConfig visual_hsv[3];
};

struct MatrixCalc{
  MappableCalc panel;
  MappableCalc matrix;
  MappableCalc visual;
};

struct PanelControl{
        bool     panel_rst;
        bool     panel_run;  
        uint32_t panel_frm_mrk;        
};

struct AnalyserData{
        uint32_t analyser_frm_num;
        uint32_t analyser_var_pss;
        float    analyser_var_bnd[64];
};

class LEDPanel{

  public:

    uint32_t  dim_x;    // Panel width
    uint32_t  dim_y;    // Panel height
    uint32_t  dim_z;    // Panel depth
    uint8_t   led_i;      // Panel brightness %

         LEDPanel(uint32_t panel_dim_x, uint32_t panel_dim_y, uint32_t panel_dim_z);
        ~LEDPanel();

    void  addMatrix(const char* mac, uint32_t matrix_x, uint32_t matrix_y, uint32_t matrix_z, uint32_t matrix_w, uint32_t matrix_h, uint32_t matrix_d);

    MatrixConfig matrix[4];
    uint32_t  matrix_next;
};

#endif
