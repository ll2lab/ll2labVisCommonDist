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

struct PanelConfg{
  uint8_t  panel_id;         // Panel id
  uint32_t panel_dim_x;      // Panel dimension x
  uint32_t panel_dim_y;      // Panel dimension y
  uint32_t panel_dim_z;      // Panel dimension y
  int32_t  panel_pos_x;      // Panel position x
  int32_t  panel_pos_y;      // Panel position y
  int32_t  panel_pos_z;      // Panel position z
  int32_t  panel_piv_x;      // Panel pivot x
  int32_t  panel_piv_y;      // Panel pivot y
  int32_t  panel_piv_z;      // Panel pivot z
  int32_t  panel_rot_x;      // Panel rotation about x axis (degrees)
  int32_t  panel_rot_y;      // Panel rotation about y axis (degrees)
  int32_t  panel_rot_z;      // Panel rotation about z axis (degrees) 
  bool     panel_rev_x;      // Panel reverse x-axis
  bool     panel_rev_y;      // Panel reverse y-axis
  bool     panel_rev_z;      // Panel reverse z-axis
  bool     panel_ref_x;      // Panel reflect across x-centre
  bool     panel_ref_y;      // Panel reflect across y-centre
  bool     panel_ref_z;      // Panel reflect across z-centre
};
struct MatrixConfig{

  uint8_t  panel_id;         // Panel id
  uint32_t panel_dim_x;      // Panel dimension x
  uint32_t panel_dim_y;      // Panel dimension y
  uint32_t panel_dim_z;      // Panel dimension y
  int32_t  panel_pos_x;      // Panel position x
  int32_t  panel_pos_y;      // Panel position y
  int32_t  panel_pos_z;      // Panel position z
  int32_t  panel_piv_x;      // Panel pivot x
  int32_t  panel_piv_y;      // Panel pivot y
  int32_t  panel_piv_z;      // Panel pivot z
  int32_t  panel_rot_x;      // Panel rotation about x axis (degrees)
  int32_t  panel_rot_y;      // Panel rotation about y axis (degrees)
  int32_t  panel_rot_z;      // Panel rotation about z axis (degrees) 
  bool     panel_rev_x;      // Panel reverse x-axis
  bool     panel_rev_y;      // Panel reverse y-axis
  bool     panel_rev_z;      // Panel reverse z-axis
  bool     panel_ref_x;      // Panel reflect across x-centre
  bool     panel_ref_y;      // Panel reflect across y-centre
  bool     panel_ref_z;      // Panel reflect across z-centre
  uint32_t panel_bri;        // Panel brightness (% of full brightness)

  uint8_t  matrix_id;        // Matrix id
  uint8_t  matrix_pin;       // Matrix SPI pin
  uint8_t  matrix_mac[6];    // Matrix MAC address
  uint32_t matrix_dim_x;     // Matrix dimension x
  uint32_t matrix_dim_y;     // Matrix dimension y
  uint32_t matrix_dim_z;     // Matrix dimension y
  int32_t  matrix_pos_x;     // Matrix position x
  int32_t  matrix_pos_y;     // Matrix position y
  int32_t  matrix_pos_z;     // Matrix position z
  int32_t  matrix_piv_x;     // Matrix pivot x
  int32_t  matrix_piv_y;     // Matrix pivot y
  int32_t  matrix_piv_z;     // Matrix pivot z
  int32_t  matrix_rot_x;     // Matrix rotation about x axis (degrees)
  int32_t  matrix_rot_y;     // Matrix rotation about y axis (degrees)
  int32_t  matrix_rot_z;     // Matrix rotation about z axis (degrees) 
  bool     matrix_rev_x;     // Matrix reverse x-axis
  bool     matrix_rev_y;     // Matrix reverse y-axis
  bool     matrix_rev_z;     // Matrix reverse z-axis
  bool     matrix_ref_x;     // Matrix reflect across x-centre
  bool     matrix_ref_y;     // Matrix reflect across y-centre
  bool     matrix_ref_z;     // Matrix reflect across z-centre
  uint32_t matrix_bri;       // Matrix brightness (% of panel brightness)

  uint8_t  visual_id;        // Visual id
  uint32_t visual_dim_x;     // Visual dimension x
  uint32_t visual_dim_y;     // Visual dimension y
  uint32_t visual_dim_z;     // Visual dimension y
  int32_t  visual_pos_x;     // Visual position x
  int32_t  visual_pos_y;     // Visual position y
  int32_t  visual_pos_z;     // Visual position z
  int32_t  visual_piv_x;     // Visual pivot x
  int32_t  visual_piv_y;     // Visual pivot y
  int32_t  visual_piv_z;     // Visual pivot z
  int32_t  visual_rot_x;     // Visual rotation about x axis (degrees)
  int32_t  visual_rot_y;     // Visual rotation about y axis (degrees)
  int32_t  visual_rot_z;     // Visual rotation about z axis (degrees) 
  bool     visual_rev_x;     // Visual reverse x-axis
  bool     visual_rev_y;     // Visual reverse y-axis
  bool     visual_rev_z;     // Visual reverse z-axis
  bool     visual_ref_x;     // Visual reflect across x-centre
  bool     visual_ref_y;     // Visual reflect across y-centre
  bool     visual_ref_z;     // Visual reflect across z-centre  
  uint32_t visual_bri;       // Visual brightness (% of matrix brightness)
};

/*struct VisualConfig{
  uint32_t visual_dim_x;     // Visual dimension x
  uint32_t visual_dim_y;     // Visual dimension y
  uint32_t visual_dim_z;     // Visual dimension y
  int32_t  visual_pos_x;     // Visual position x
  int32_t  visual_pos_y;     // Visual position y
  int32_t  visual_pos_z;     // Visual position z
  int32_t  visual_piv_x;     // Visual pivot x
  int32_t  visual_piv_y;     // Visual pivot y
  int32_t  visual_piv_z;     // Visual pivot z
  int32_t  visual_rot_x;     // Visual rotation about x axis (degrees)
  int32_t  visual_rot_y;     // Visual rotation about y axis (degrees)
  int32_t  visual_rot_z;     // Visual rotation about z axis (degrees) 
  bool     visual_rev_x;     // Visual reverse x-axis
  bool     visual_rev_y;     // Visual reverse y-axis
  bool     visual_rev_z;     // Visual reverse z-axis
  bool     visual_ref_x;     // Visual reflect across x-centre
  bool     visual_ref_y;     // Visual reflect across y-centre
  bool     visual_ref_z;     // Visual reflect across z-centre  
};
*/
struct VisHSV{                          // helper struct for component definition

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

struct VisControl{
        bool     panel_rst;
        bool     panel_run;  
        uint32_t panel_frm_mrk;        
};

struct VisData{
        uint32_t panel_frm_num;
        uint32_t analyser_var_pss;
        float    analyser_var_bnd[64];
};

struct VisConfig{
        float    analyser_rsp_tho;
        uint32_t analyser_bnd_rng;
        uint32_t visual_dim_x;
        uint32_t visual_dim_y;
        uint32_t visual_dim_z;
        int32_t  visual_pos_x;
        int32_t  visual_pos_y;
        int32_t  visual_pos_z;
        int32_t  visual_piv_x;
        int32_t  visual_piv_y;
        int32_t  visual_piv_z;
        bool     visual_rev_x;
        bool     visual_rev_y;
        bool     visual_rev_z;
        bool     visual_ref_x;
        bool     visual_ref_y;
        bool     visual_ref_z;


        uint32_t visual_frm_ini;
        uint32_t visual_frm_div;
        uint32_t visual_frm_inc;
        uint32_t visual_pat_sel;
        VisHSV   visual_hsv[3];

};

#endif