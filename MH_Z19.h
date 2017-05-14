/*
 * Copyright (c) 2017 Jimms Hsieh
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __ARDUINO_MH_Z19
#define __ARDUINO_MH_Z19

#include <Arduino.h>
#include <SoftwareSerial.h>

class MH_Z19 {
  public:
    MH_Z19(uint8_t pwm, uint8_t tx, uint8_t rx): _pwm(pwm), _tx(tx), _rx(rx) {
       _serial = new SoftwareSerial(tx, rx);
    }
    ~MH_Z19() {
      delete this->_serial;
      this->_serial = NULL;
    }
    int read_pwm_value(int range=5000);
    int read_uart_value();
    void setup();

  private:
    uint8_t _pwm;
    uint8_t _tx;
    uint8_t _rx;
    SoftwareSerial *_serial;
};

#endif
