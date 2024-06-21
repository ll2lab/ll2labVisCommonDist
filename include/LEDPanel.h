#include <Arduino.h>

#ifndef LEDPANEL_H
#define LEDPANEL_H

#define FRAME_TYPE_COUNT        3
#define FRAME_TYPE_PANELCONTROL 0
#define FRAME_TYPE_ANALYSERDATA 1  
#define FRAME_TYPE_MATRIXCONFIG 2

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
  uint8_t  id;         // ID
  uint32_t dim_x;      // Transform dimension x
  uint32_t dim_y;      // Transform dimension y
  uint32_t dim_z;      // Transform dimension y
  int32_t  pos_x;      // Transform position x
  int32_t  pos_y;      // Transform position y
  int32_t  pos_z;      // Transform position z
  int32_t  piv_x;      // Transform pivot x
  int32_t  piv_y;      // Transform pivot y
  int32_t  piv_z;      // Transform pivot z
  int32_t  rot_x;      // Transform rotation about x axis (degrees)
  int32_t  rot_y;      // Transform rotation about y axis (degrees)
  int32_t  rot_z;      // Transform rotation about z axis (degrees) 
  bool     rev_x;      // Transform reverse x-axis
  bool     rev_y;      // Transform reverse y-axis
  bool     rev_z;      // Transform reverse z-axis
  bool     ref_x;      // Transform reflect across x-centre
  bool     ref_y;      // Transform reflect across y-centre
  bool     ref_z;      // Transform reflect across z-centre
  uint32_t led_i;        // Transform brightness (% of full brightness)  
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

  Mappable panel;
  Mappable matrix;
  Mappable visual;

  uint8_t  matrix_pin;       // Matrix SPI pin
  uint8_t  matrix_mac[6];    // Matrix MAC address

  float    visual_inp_thr;
  uint32_t visual_frm_ini;
  uint32_t visual_frm_div;
  uint32_t visual_frm_inc;
  uint32_t visual_pat_sel;
  HSVConfig   visual_hsv[3];
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
