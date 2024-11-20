#ifndef LL2_LAB_VISMESSAGE_H
#define LL2_LAB_VISMESSAGE_H

#include <Arduino.h>

#define FRAME_TYPE_COUNT         19UL     // Frame type count
#define FRAME_TYPE_OTAINIT       10UL     // Initialise OTA mode
#define FRAME_TYPE_ANALYSERDATA  11UL     // Analyser data frame 
#define FRAME_TYPE_PANELCONTROL  12UL     // Panel control frame
#define FRAME_TYPE_SETCONFIG     13UL     // Set config frame
#define FRAME_TYPE_PANELCONFIG   14UL     // Panel config frame
#define FRAME_TYPE_BOARDCONFIG   15UL     // Board config frame
#define FRAME_TYPE_SCENECONFIG   16UL     // Scene config frame
#define FRAME_TYPE_VISUALCONFIG  17UL     // Visual config frame
#define FRAME_TYPE_PULSECONFIG   18UL     // Pulse config frame 

#endif