#include <Arduino.h>
#include <VisConfig.h>

#ifndef LEDPANEL_H
#define LEDPANEL_H

class LEDPanel{

  public:

    uint32_t  panel_dim_x;    // Panel width
    uint32_t  panel_dim_y;    // Panel height
    uint32_t  panel_dim_z;    // Panel depth
    uint8_t   panel_bri;      // Panel brightness %

         LEDPanel(uint32_t panel_dim_x, uint32_t panel_dim_y, uint32_t panel_dim_z);
        ~LEDPanel();

    void  addMatrix(const char* mac, uint32_t matrix_x, uint32_t matrix_y, uint32_t matrix_z, uint32_t matrix_w, uint32_t matrix_h, uint32_t matrix_d);

    MatrixConfig matrix[4];
    uint32_t  matrix_next;
};

#endif
