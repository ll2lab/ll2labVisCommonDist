#ifndef LL2_LAB_VIS_MESSAGE_H
#define LL2_LAB_VIS_MESSAGE_H

#include <Arduino.h>
#include <ll2labVisConfig.h>

enum LL2LabMessageType : uint8_t {
  FRAME_TYPE_BASE          = 10U,     // NOT USED
  FRAME_TYPE_ANALYSERDATA ,           // Analyser data frame 
  FRAME_TYPE_PANELCONTROL,            // Panel control frame
  FRAME_TYPE_SETCONFIG,               // Set config frame
  FRAME_TYPE_PANELCONFIG,             // Panel config frame
  FRAME_TYPE_BOARDCONFIG,             // Board config frame
  FRAME_TYPE_SCENECONFIG,             // Scene config frame
  FRAME_TYPE_VISUALCONFIG,            // Visual config frame
  FRAME_TYPE_PULSECONFIG              // Pulse config frame 
};

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

struct AnalyserData{                     // Analyser data
  uint32_t frm;                          // Analyser frame number
  float    bnd_val[ANA_MAX_BANDS];       // Analyser band values
};

struct PanelControl{                     // Panel control
  bool     rst;                          // Reset
  bool     run;                          // Run
  uint32_t mrk;                          // Run frame mark
  bool     dmp;                          // Dump configuration to serial
};

struct SetConfig{                        // Set configuration
  uint8_t   id;                          // Set id
  bool      sta;                          // Statistics logging on/off
};

struct PanelConfig{                      // Panel configuration
  uint8_t   id;                          // Panel id in set
};

struct BoardConfig{                      // Board configuration
  uint8_t   id;                          // Board id in panel
  uint8_t   mac[6];                      // Board MAC address
  uint8_t   pin;                         // Board SPI pin  
};

struct SceneConfig{                      // Scene configuration
  uint8_t   id;                          // Scene id in set
};

struct VisualConfig{                     // Visual configuration
  uint8_t   id;                          // Visual id in scene
  uint32_t  pat;                         // Visual pattern
  uint32_t  smp;                         // Visual samples
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

struct PulseConfig{
  uint8_t   id;                          // Pulse id in visual
  bool      is_smp_x;                    // Pulse x is sample driver
  bool      is_smp_y;                    // Pulse y is sample driver
  bool      is_smp_z;                    // Pulse z is sample driver
  int32_t   pls_x;                       // Pulse initial x co-ordinate
  int32_t   pls_y;                       // Pulse initial y co-ordinate
  int32_t   pls_z;                       // Pulse initial z co-ordinate
  int32_t   pls_l;                       // Pulse initial length
  uint32_t  pls_f;                       // Pulse frame duration
  float     pls_dx;                      // Pulse frame x delta
  float     pls_dy;                      // Pulse frame y delta
  float     pls_dz;                      // Pulse frame z delta
  float     pls_dh;                      // Pulse frame hue delta
  float     pls_ds;                      // Pulse frame saturation delta
  float     pls_dv;                      // Pulse frame value delta
  float     pls_dl;                      // Pulse length value delta
};

#endif


