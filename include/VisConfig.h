#ifndef VISCONFIG_H
#define VISCONFIG_H

#define FRAME_TYPE_COUNT  4
#define FRAME_TYPE_VISCTL 0
#define FRAME_TYPE_VISCFG 1
#define FRAME_TYPE_VISDAT 2
#define FRAME_TYPE_MATCFG 3

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
 
struct PacketHeader{
  uint32_t frameType;        // Frame type
  uint32_t packetHeaderSize; // Paket header size (bytes)
  uint32_t packetDataSize;   // Packet data size (bytes)
  uint32_t packetPerFrame;   // Packets per frame
  uint32_t packetInFrame;    // Packets number in frame
};

struct MatrixConfig{
  uint8_t  panel_id;         // Panel id
  uint32_t panel_w;          // Panel width
  uint32_t panel_h;          // Panel height
  uint32_t panel_d;          // Panel depth
  bool     panel_rev_x;      // Panel reverse x-axis
  bool     panel_rev_y;      // Panel reverse y-axis
  bool     panel_rev_z;      // Panel reverse z-axis
  bool     panel_ref_x;      // Panel reflect across x-centre
  bool     panel_ref_y;      // Panel reflect across y-centre
  bool     panel_ref_z;      // Panel reflect across z-centre
  float    panel_rotx;       // Panel rotation about x axis (radians)
  float    panel_roty;       // Panel rotation about y axis (radians)
  float    panel_rotz;       // Panel rotation about z axis (radians)
  uint8_t  matrix_id;        // Matrix id
  uint8_t  matrix_pin;       // Matrix SPI pin
  uint8_t  matrix_mac[6];    // Matrix MAC address
  int32_t  matrix_x;         // Matrix x position (w.r.t. panel)
  int32_t  matrix_y;         // Matrix y position (w.r.t. panel)
  int32_t  matrix_z;         // Matrix z position (w.r.t. panel)         
  uint32_t matrix_w;         // Matrix width
  uint32_t matrix_h;         // Matrix height
  uint32_t matrix_d;         // Matrix depth
  uint8_t  matrix_i;         // Matrix intensity (0-255)   
  bool     matrix_rev_x;     // Matrix reverse x-axis
  bool     matrix_rev_y;     // Matrix reverse y-axis
  bool     matrix_rev_z;     // Matrix reverse z-axis
  bool     matrix_ref_x;     // Matrix reflect x-axis
  bool     matrix_ref_y;     // Matrix reflect y-axis
  bool     matrix_ref_z;     // Matrix reflect z-axis 
  float    matrix_rotx;      // Matrix rotation about x axis (radians)
  float    matrix_roty;      // Matrix rotation about y axis (radians)
  float    matrix_rotz;      // Matrix rotation about z axis (radians) 
};


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

struct VisConfig{
        float    ana_rsp_tho;
        uint32_t ana_bnd_rng;
        uint32_t mtx_win_w;
        uint32_t mtx_win_h;
        uint32_t mtx_win_x;
        uint32_t mtx_win_y;
        uint32_t vis_rev_x;
        uint32_t vis_ref_x;
        uint32_t vis_rev_y;
        uint32_t vis_ref_y;
        uint32_t vis_frm_ini;
        uint32_t vis_frm_div;
        uint32_t vis_frm_inc;
        uint32_t vis_pat_sel;
        VisHSV   vis_hsv[3];

};

#endif