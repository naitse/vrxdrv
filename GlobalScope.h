#ifndef GlobalScope_H
#define GlobalScope_H
#include <Arduino.h>

extern String buttonName;
extern String prevBtn;
extern int vrx;
extern String page;
extern int prevFreq[];
extern int tunnedFreq[];
extern int tunnedChannel[];
extern String tunnedBand[];
extern int enter;
extern int RX5808_DATA_PIN;             //DATA output line to RX5808 module
extern int RX5808_SEL_PIN;              //CLK output line to RX5808 module
extern int RX5808_CLK_PIN;
extern int RSSI_PRI_PIN;
extern int VRX_DATA_PIN[];
extern void selectVRX(int vrxIdx);
extern int tunnedRSSI[];
extern int rssiReadInx;

const unsigned char rsz_argentos2[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x1F,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x1F,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0x80,0x1F,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xE0,0x1F,0xC0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x3E,0x00,0x1F,0xFF,0xFF,0xF8,0x02,0xF8,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x81,0x80,0x3F,0xFF,0xFF,0xFC,0x03,0x02,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x20,0x0C,0x00,0x7F,0xFF,0xFF,0xFE,0x06,0x20,0x08,0x00,0x00,0x00,
  0x00,0x00,0x00,0x60,0x07,0x00,0xFF,0xFF,0xFF,0xFE,0x03,0xC0,0x0C,0x00,0x00,0x00,
  0x00,0x00,0x00,0x60,0x03,0x81,0xFF,0xFF,0xFF,0xFF,0x03,0x80,0x0C,0x00,0x00,0x00,
  0x00,0x00,0x00,0xE0,0x01,0xC1,0xFF,0xFF,0xFF,0xFF,0x07,0x00,0x0E,0x00,0x00,0x00,
  0x00,0x00,0x00,0xE0,0x00,0xC3,0xFF,0xFF,0xFF,0xFF,0x87,0x00,0x0F,0x00,0x00,0x00,
  0x00,0x00,0x01,0xE0,0x00,0xE3,0xFF,0xFF,0xFF,0xFF,0x8E,0x00,0x0F,0x00,0x00,0x00,
  0x00,0x00,0x0B,0xE0,0x00,0xE3,0xFF,0xFF,0xFF,0xFF,0xDE,0x00,0x0F,0x80,0x00,0x00,
  0x00,0x00,0x33,0x20,0x00,0xE3,0xFF,0xFF,0xE1,0xFF,0xFE,0x00,0x09,0x88,0x00,0x00,
  0x00,0x00,0x67,0x20,0x00,0xE3,0xF8,0x00,0x00,0x0F,0xCE,0x00,0x08,0xC4,0x00,0x00,
  0x00,0x00,0xC6,0x60,0x00,0xE3,0xC0,0x00,0x00,0x00,0xC6,0x00,0x0C,0xC2,0x00,0x00,
  0x00,0x01,0x8E,0xC0,0x00,0x42,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0xE1,0x00,0x00,
  0x00,0x03,0x0C,0x80,0x00,0x40,0x00,0x00,0x00,0x00,0x06,0x00,0x03,0x70,0x80,0x00,
  0x00,0x06,0x1F,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x06,0x00,0x01,0xF0,0xC0,0x00,
  0x00,0x0C,0x1E,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0xF0,0x60,0x00,
  0x00,0x18,0x1C,0x3C,0x00,0x80,0x00,0x00,0x00,0x00,0x02,0x00,0x38,0x70,0x30,0x00,
  0x00,0x30,0x1C,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x30,0x18,0x00,
  0x00,0x60,0x1F,0xFF,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x03,0xFF,0xF0,0x0C,0x00,
  0x00,0x40,0x7F,0xFF,0xE0,0x00,0x00,0x03,0xC0,0x00,0x00,0x0F,0xFF,0xFC,0x04,0x00,
  0x00,0x83,0xFD,0xFF,0xF8,0x00,0x00,0x03,0xE0,0x00,0x00,0x3F,0xFF,0x7F,0x82,0x00,
  0x01,0x84,0xC4,0x3F,0xFE,0x00,0x00,0x04,0x60,0x00,0x00,0x7F,0xF8,0x46,0x43,0x00,
  0x01,0x09,0xC4,0x0F,0xFF,0x00,0x00,0x04,0x30,0x06,0x01,0xFF,0xE0,0x47,0x21,0x00,
  0x02,0x13,0x84,0x0F,0xFF,0xC0,0xFC,0x0D,0xBF,0xFF,0x07,0xFF,0xE0,0x43,0x90,0x80,
  0x02,0x27,0x87,0x1F,0xFF,0xE0,0xFF,0xF9,0x9F,0xFF,0x0F,0xFF,0xF0,0xC1,0xC8,0x00,
  0x04,0x6F,0x07,0xFF,0xFF,0xF0,0xFE,0x7F,0xBF,0x9F,0x1F,0xFF,0xFF,0xC1,0xEC,0x40,
  0x00,0xFE,0x00,0x0F,0xFF,0xF8,0xFC,0x7F,0xFE,0x0E,0x1F,0xFF,0xE0,0x00,0xFE,0x00,
  0x01,0xFE,0x00,0x00,0x3F,0xF0,0xF8,0x7F,0xFE,0x1E,0x1F,0xF8,0x00,0x00,0x7F,0x00,
  0x03,0xF8,0x00,0x00,0x00,0x00,0x6C,0x7F,0xFE,0x08,0x00,0x00,0x00,0x00,0x3F,0x80,
  0x07,0xE0,0x7F,0xE0,0x00,0x00,0x00,0x7F,0xEE,0x00,0x00,0x00,0x1F,0xF8,0x0F,0xC0,
  0x0F,0xC3,0xFF,0xF8,0x00,0x00,0x00,0x3F,0x7E,0x00,0x00,0x00,0x7F,0xFF,0x07,0xE0,
  0x1F,0x0F,0xFF,0xFE,0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0xFF,0xFF,0xC1,0xF0,
  0x3C,0x1F,0xFF,0xFF,0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x03,0xFF,0xFF,0xF0,0x78,
  0x78,0x7F,0xFF,0xFF,0xC0,0x00,0x00,0x3F,0xFC,0x00,0x00,0x07,0xFF,0xFF,0xF8,0x3C,
  0xE0,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x3F,0xFC,0x00,0x00,0x1F,0xFF,0xFF,0xFC,0x0E,
  0x81,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x3F,0xFC,0x00,0x00,0x7F,0xFF,0xFF,0xFE,0x02,
  0x01,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x3F,0xFC,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0x00,
  0x07,0xFF,0xF0,0x18,0x7F,0x80,0x00,0x1F,0xDC,0x00,0x07,0xFC,0x30,0x1F,0xFF,0xC0,
  0x07,0xFE,0x02,0x30,0x07,0xF0,0x00,0x1A,0xDC,0x00,0x1F,0xC0,0x18,0x81,0xFF,0xC0,
  0x07,0xF8,0x18,0xE0,0x00,0xFC,0x00,0x02,0xD8,0x00,0xFE,0x00,0x0E,0x30,0x3F,0xC0,
  0x0F,0xE1,0xF1,0xC0,0x00,0x3F,0xC0,0x00,0x00,0x07,0xF8,0x00,0x07,0x1F,0x1F,0xC0,
  0x0F,0xFF,0xC7,0x00,0x00,0x0F,0xFC,0x00,0x00,0xFF,0xE0,0x00,0x01,0xC7,0xFF,0xE0,
  0x1E,0xFE,0x1E,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0xF0,0xFF,0xE0,
  0x18,0x00,0x78,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x3C,0x00,0x70,
  0x10,0x07,0xE0,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x0F,0xC0,0x30,
  0x00,0x7E,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0xFC,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


#endif