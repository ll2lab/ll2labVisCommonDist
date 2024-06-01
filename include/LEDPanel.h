#include <Arduino.h>
#include <VisConfig.h>

#ifndef LEDPANEL_H
#define LEDPANEL_H

class LEDPanel{

  public:

    uint32_t  pnl_led_w;    // matrix leds width
    uint32_t  pnl_led_h;    // matrix leds height
    uint32_t  pnl_led_d;    // matrix leds depth

         LEDPanel(uint32_t w, uint32_t h, uint32_t d);
        ~LEDPanel();

    void  addMatrix(const char* mac, uint32_t x, uint32_t y, uint32_t z, uint32_t w, uint32_t h, uint32_t d);

    MatConfig mtx[4];
    uint32_t        mtx_num;
};

#endif
