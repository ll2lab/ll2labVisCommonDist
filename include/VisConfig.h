#include <Arduino.h>

struct VisHSV{                          // helper struct for component definition

  uint32_t    cmp_cmp_drv;              // component driver

  uint32_t    cmp_rng_ini;              // component range initial (0-255)
  uint32_t    cmp_rng_min;              // component range minimum (0-255)
  uint32_t    cmp_rng_max;              // component range maximum (0-255)

  uint32_t    cmp_bnd_min;              // component led minimum (0-255)
  uint32_t    cmp_bnd_max;              // component led maximum (0-255)

  int32_t     cmp_bnd_del;              // component output delta per bin
  int32_t     cmp_frm_del;              // component frame delta
  float       cmp_frm_dcy;              // component frame decay multiplier

  bool        cmp_out_per;              // component persist value if > new fft value
};

/*
struct VisConfig{

        //VisConfig2
        float    ana_rsp_tho;
        uint32_t ana_bnd_rng;
        uint32_t mtx_win_w;
        uint32_t mtx_win_h;
        uint32_t mtx_win_x;
        uint32_t mtx_win_y;
        uint32_t _mtx_led_lay;
        uint32_t vis_frm_ini;
        uint32_t vis_frm_div;
        uint32_t vis_frm_inc;
        uint32_t vis_pat_sel;
        uint32_t ana_var_pss;
        VisHSV   vis_hsv[3];

        //VisControl
        bool     vis_cfg_rst;
        bool     app_vis_run;  
        uint32_t app_frm_num;
        uint32_t app_frm_mrk;
        float    ana_var_bnd[64];
};
*/

struct VisControl{
        bool     vis_cfg_rst;
        bool     app_vis_run;  
        uint32_t app_frm_mrk;        
};

struct VisData{
        uint32_t app_frm_num;
        uint32_t ana_var_pss;
        float    ana_var_bnd[64];
};

struct VisConfig2{
        float    ana_rsp_tho;
        uint32_t ana_bnd_rng;
        uint32_t mtx_win_w;
        uint32_t mtx_win_h;
        uint32_t mtx_win_x;
        uint32_t mtx_win_y;
        uint32_t _mtx_led_lay;
        uint32_t vis_frm_ini;
        uint32_t vis_frm_div;
        uint32_t vis_frm_inc;
        uint32_t vis_pat_sel;
        VisHSV   vis_hsv[3];
};


struct MatConfig{
  uint8_t  mtx_num;
  uint32_t pnl_led_w;
  uint32_t pnl_led_h;
  uint32_t pnl_led_d;
  uint32_t mtx_led_x;
  uint32_t mtx_led_y;
  uint32_t mtx_led_z;
  uint32_t mtx_led_w;
  uint32_t mtx_led_h;
  uint32_t mtx_led_d;  
};

struct PacketHeader{
  uint32_t   frameType;      // Frame type
  uint32_t   packetNum;      // Packets number in frame
  uint32_t   packetLast;     // Packets per frame
  uint32_t   dataSize;       // Packet data size (bytes)
};

struct FrameConfig{
  uint32_t   frameType;      // Frame type
  uint32_t   frameSize;      // Frame type size (bytes)
  uint32_t   frameTime;      // Frame type last seen
  uint32_t   packetLast;     // Packets per frame
  uint32_t   packetSize;     // Packet size (bytes)
  uint32_t   dataSize;       // Packet data size (bytes)
};
