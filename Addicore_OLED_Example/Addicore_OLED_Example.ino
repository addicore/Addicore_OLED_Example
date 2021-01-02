//**********************************************************************************************************************
//
//                              Addicore OLED Display - 128x64 Monochrome Example Sketch
//                                                 by Addicore.com
//
//**********************************************************************************************************************
//  Example sketch for the Addicore OLED Display - 128x64 0.96in Monochrome found
//  at https://www.addicore.com/OLED-128x64-Monochrome-p/ad304.htm
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
//       1-1-2021   Andre A. McKay    Version 1.0   Initial Release
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

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 0, /* data=*/ 2);   // ESP-01, HW I2C with pin remapping

void setup(void) {
  
  u8g2.begin();
}

void loop(void) {
  MainScreen();
  SolidScreen();

}

void MainScreen() {
  u8g2.firstPage();
  do {
    u8g2.setDrawColor(1);
    u8g2.setBitmapMode(0);
    u8g2.drawXBM( 0, 0, Logo_width, Logo_height, Logo_bits);
    
    u8g2.setFont(u8g2_font_helvB10_tf);
    u8g2.drawStr( 17, 37, "OLED Display");
  
    u8g2.setFont(u8g2_font_helvR08_tf);
    u8g2.drawStr( 4, 51, "128 x 64 Pixels, 0.96 inch");
  
    u8g2.setFont(u8g2_font_helvR08_tf);
    u8g2.drawStr( 20, 64, "www.addicore.com");
  } while ( u8g2.nextPage() );
  delay(5000);
}

void SolidScreen() {
  
//  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.firstPage();
  do {
      u8g2.drawBox(0,0,128,64);
      //u8g2.drawBox(0,0,0,0);
  } while ( u8g2.nextPage() );
  delay(5000);
}
