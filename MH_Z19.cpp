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

#include <MH_Z19.h>

void MH_Z19::setup() {
  this->_serial->begin(9600);
  pinMode(this->_pwm, INPUT);
}

int MH_Z19::read_pwm_value(int range) {
  int th = 0;
  double ppm = 0;

  do {
    th = pulseIn(this->_pwm, HIGH, 1004000) / 1000;
    ppm = range / 1000 * (th - 2);
  } while (th == 0);

  return (int) ppm;
}

int MH_Z19::read_uart_value() {
  byte cmd[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
  byte response[9] = {0};

  this->_serial->write(cmd, 9);
  this->_serial->readBytes(response, 9);

  if (response[0] != 0xFF || response[1] != 0x86){
    return -1;
  }

  return (256 * response[2]) + response[3];
}
