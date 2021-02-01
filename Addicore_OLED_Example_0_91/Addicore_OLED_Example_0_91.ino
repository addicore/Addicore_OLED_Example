//**********************************************************************************************************************
//
//                              Addicore OLED Display - 128x32 0.91" Monochrome Example Sketch
//                                                 by Addicore.com
//
//**********************************************************************************************************************
//  Example sketch for the Addicore OLED Display - 128x32 0.91" Monochrome found
//  at https://www.addicore.com/OLED-128x32-0-91in-Monochrome-p/ad556.htm
//  
//  Requires the U8G2 Library by Olikraus - https://github.com/olikraus/u8g2
//
//  Graphics.h contains the Addicore logo.
//  Instructions for creating and displaying your own photo can be found here;
//  https://sandhansblog.wordpress.com/2017/04/16/interfacing-displaying-a-custom-graphic-on-an-0-96-i2c-oled/ 
//
//  Wire the OLED Display to your Arduino as detailed below. Then
//  Upload this code to your Arduino 
//  
//  Wiring:
//                 OLED ---> Arduino
//                 GND          GND
//                 VCC          5V
//                 SCL          A5
//                 SDA          A4
//
//**********************************************************************************************************************
// Revision History:
//
//       2-1-2021   Andre A. McKay    Version 1.0   Initial Release
//       
//
// Copyright (C) 2020  Boffintronics, LLC
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//**********************************************************************************************************************

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "graphics.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

void setup(void) {
  
  u8g2.begin();
}

void loop(void) {
  MainScreen();
  DisplayText();
  delay(5000);
  SolidScreen();
  delay(5000);

}


void MainScreen() {
  u8g2.clearBuffer();
  u8g2.setBitmapMode(0);
  u8g2.drawXBM( 0, 0, Logo_width, Logo_height, Logo_bits);
  u8g2.sendBuffer();
}

void SolidScreen() {
  u8g2.clearBuffer();
  u8g2.setDrawColor(1);
  u8g2.drawBox(0,0,128,32);
  u8g2.sendBuffer();
}

void DisplayText() {
  u8g2.setFont(u8g2_font_helvR08_tf);
  char *LN_1 = "OLED Display";
  char *LN_2 = "128 x 32 Pixels, 0.96 inch";
  char *LN_3 = "www.addicore.com";
  int LN_1_S = ((u8g2.getDisplayWidth() - u8g2.getStrWidth(LN_1))/2);
  int LN_2_S = ((u8g2.getDisplayWidth() - u8g2.getStrWidth(LN_2))/2);
  int LN_3_S = ((u8g2.getDisplayWidth() - u8g2.getStrWidth(LN_3))/2);
  u8g2.drawStr(LN_1_S, 29, LN_1);
  u8g2.sendBuffer();
  delay(1000);
  ClearLines();
  u8g2.drawStr(LN_2_S, 29, LN_2);
  u8g2.sendBuffer();
   delay(1000);
  ClearLines();
  u8g2.drawStr(LN_3_S, 29, LN_3);
  u8g2.sendBuffer();
}

void ClearLines() {
  u8g2.setDrawColor(0);
  u8g2.drawBox(0,19,128,32);
  u8g2.setDrawColor(1);
}
