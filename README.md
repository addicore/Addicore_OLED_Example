# Addicore OLED Display Example Sketches - by Addicore.com

Example sketches for the following Addicore OLED Displays;

128x64 0.96in Monochrome - (https://www.addicore.com/OLED-128x64-Monochrome-p/ad304.htm)
128x62 1.3in Monochrome - (https://www.addicore.com/OLED-128x64-1-3in-Monochrome-p/ad555.htm)
128x32 0.91in Monochrome - (https://www.addicore.com/OLED-128x32-0-91in-Monochrome-p/ad556.htm)


Requires the U8G2 Library by Olikraus - (https://github.com/olikraus/u8g2)

Graphics.h contains the Addicore logo.
Instructions for creating and displaying your own photo can be found here;
(https://sandhansblog.wordpress.com/2017/04/16/interfacing-displaying-a-custom-graphic-on-an-0-96-i2c-oled/)

Wire the OLED Display to your Arduino as detailed below. Then upload this code to your Arduino 

```
Wiring:
     **OLED ---> Arduino**
     GND          GND
     VCC          5V
     SCL          A5
     SDA          A4
```

## Revision History:
 
2-1-2021 - Andre A. McKay - Version 2.0 - Added Support for 1.3in and 0.91in OLED Displays
1-1-2021 - Andre A. McKay - Version 1.0 - Initial Release
