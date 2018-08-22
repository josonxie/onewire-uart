/**
 * \file            ow_ll_gpio.c
 * \brief           Low-level implementation using single GPIO pin
 *                  without use of UART peripheral
 */
 
/*
 * Copyright (c) 2018 Tilen Majerle
 *  
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of OneWire-UART.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 */
#include "system/ow_ll.h"

#if !__DOXYGEN__

static uint32_t baud_curr;

/**
 * \brief           Initialize low-level communication
 * \param[in]       arg: User argument passed on \ref ow_init function
 * \return          `1` on success, `0` otherwise
 */
uint8_t
ow_ll_init(void* arg) {
    /* Configure and enable UART at 115200 bauds */

    return 1;
}

/**
 * \brief           Deinit low-level
 * \param[in]       arg: User argument passed on \ref ow_init function
 * \return          `1` on success, `0` otherwise
 */
uint8_t
ow_ll_deinit(void* arg) {
    /* Disable UART peripheral */

    return 1;
}

/**
 * \brief           Set baudrate for UART hardware
 * \param[in]       baud: Expected baudrate for UART. Values can be either `9600` or `15200` bauds
 * \param[in]       arg: User argument passed on \ref ow_init function
 * \return          `1` on success, `0` otherwise
 */
uint8_t
ow_ll_set_baudrate(uint32_t baud, void* arg) {
    /* Configure UART to selected baudrate */
    baud_curr = baud;
    
    return 1;
}

/**
 * \brief           Transmit-Receive data over UART
 * \param[in]       tx: Array of data to send
 * \param[out]      rx: Array to save receive data 
 * \param[in]       len: Number of bytes to send
 * \param[in]       arg: User argument passed on \ref ow_init function
 * \return          `1` on success, `0` otherwise
 */
uint8_t
ow_ll_transmit_receive(const uint8_t* tx, uint8_t* rx, size_t len, void* arg) {
    /* Perform data exchange */
    if (baud_curr == 9600) {                    /* On low baudrate */
        /* Send reset pulse */
    } else {                                    /* On high baudrate */
        while (len--) {                         /* Process all bytes */
            if (*tx != 0x00) {                  /* Send logical 1 pulse and read response */
                *rx = 0;                        /* Save reply from device */
            } else {                            /* Send logical 0 pulse and read response */
            
            }
            tx++;
            rx++;
        }
    }
    
    return 1;
}

#endif /* !__DOXYGEN__ */