#include <Arduino.h>
#include <VisConfig.h>

#ifndef LEDPANEL_H
#define LEDPANEL_H

class LEDPanel{

  public:

    uint32_t  panel_w;    // matrix leds width
    uint32_t  panel_h;    // matrix leds height
    uint32_t  panel_d;    // matrix leds depth

         LEDPanel(uint32_t panel_w, uint32_t panel_h, uint32_t panel_d);
        ~LEDPanel();

    void  addMatrix(const char* mac, uint32_t matrix_x, uint32_t matrix_y, uint32_t matrix_z, uint32_t matrix_w, uint32_t matrix_h, uint32_t matrix_d);

    MatConfig matrix[4];
    uint32_t  matrix_next;
};

#endif
