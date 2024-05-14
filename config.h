#pragma once
#pragma once
#include <Arduino.h>
#include "config.h"

const char* host = "ESP32-GSP";

#define WIFI                               // Используем модуль вайфая
#define DEBUG                              // Замаркировать если не нужны тесты
#define DEBUG_OUTPUT_PORT Serial

#define SD_CARD                           // SD нужную включить, по умолчанию SPIFFS
//#define SD_CARD_MMC
//#define LITTLEFS

//define TFT_ERR                           // Отключает вывод на экран  - tftDisplay()
//#define LCD_RUS                          // Замаркировать, если скетч вывод латиницей


/*
 * static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

static const uint8_t SS    = 5;
static const uint8_t MOSI  = 23;
static const uint8_t MISO  = 19;
static const uint8_t SCK   = 18;

static const uint8_t A0 = 36;
static const uint8_t A3 = 39;
static const uint8_t A4 = 32;
static const uint8_t A5 = 33;
static const uint8_t A6 = 34;
static const uint8_t A7 = 35;
static const uint8_t A10 = 4;
static const uint8_t A11 = 0;
static const uint8_t A12 = 2;
static const uint8_t A13 = 15;
static const uint8_t A14 = 13;
static const uint8_t A15 = 12;
static const uint8_t A16 = 14;
static const uint8_t A17 = 27;
static const uint8_t A18 = 25;
static const uint8_t A19 = 26;

static const uint8_t T0 = 4;
static const uint8_t T1 = 0;
static const uint8_t T2 = 2;
static const uint8_t T3 = 15;
static const uint8_t T4 = 13;
static const uint8_t T5 = 12;
static const uint8_t T6 = 14;
static const uint8_t T7 = 27;
static const uint8_t T8 = 33;
static const uint8_t T9 = 32;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;
*/

//  G0 - TFT_CS         0 <-> TFT_CS                // Define chipselect pin for TFT Display
//  G1 - TX UART        1 <-> (Serial)
//  G2 - TFT_RST        2 <-> TFT_RST
//  G3 - RX UART        3 <-> (Serial)
//  g4 - TFT_DC         4 <-> TFT_DC
//  G5 - SD_CS          5 <-> SD_CS                  // Define chipselect pin for SD Card
//  G6 -
//  G7 -
//  G8 -
//  G9 -
//  G10 -
//  G11 -
//  G12 - AD9833_MISO  12  X  NOT CONNECTED
//  G13 - AD9833_MOSI  13 <-> AD9833_SDATA  <-> TFT_MOSI
//  G14 - AD9833_SCK   14 <-> AD9833_SCLK   <-> TFT_SCK
//  G15 - AD9833_CS    15 <-> AD9833_FSYNC
//  G16 - MCP41x1_CS   16 <-> MCP41x1_CS

//  G17 - MCP41x1_ALC  17 <-> MCP41010_ALC           // Define chipselect pin for MCP41010 for ALC
//  G18 - MCP41x1_SCK  18 <-> MCP41010_SCLK          // Define SCK pin for MCP41010
//  G19 - MCP41x1_MISO 19  X  NOT CONNECTED          // Define MISO pin for MCP4131 or MCP41010
//  G20 -
//  G21 - SDA // LCD, INA219
//  G22 - SCK // LCD, INA219
//  G23 - MCP41x1_MOSI 23 <-> MCP41010_SDATA          // Define MOSI pin for MCP4131 or MCP41010
//  G24 -
//  G25 - PIN_RELE                  25 <-> RELAY      // PIN_RELE
//  G26 - ROTARY_ENCODER_A_PIN      26 <-> ENC_CLK
//  G27 - ROTARY_ENCODER_B_PIN      27 <-> ENC_DT
//  G28 -
//  G29 -
//  G30 -
//  G31 -
//  G32 - ON_OFF_CASCADE_PIN        32 <-> LT1206_SHUTDOWN
//  G33 - PIN_ZUM                   33 <-> BUZZER
//  G34 -
//  G35 - ROTARY_ENCODER_BUTTON_PIN 35 <-> ENC_SW //  PULL_UP +3.3 R 4K7
//  G36 -
//  G39 - CORRECT_PIN A3 (ADC3) (VN)39 <-> SENS_IMPLOSION

/*
   1   3.3V
   2   EN  - EN
   3   SP  - SENSOR_VP  - G36 - ADC0  
   4   SN  - SENSOR_VN  - G39 - CORRECT_PIN A3 (ADC3) (VN)39 <-> SENS_IMPLOSION
   5   G34 - ADC6 -
   6   G35 - ROTARY_ENCODER_BUTTON_PIN 35 <-> ENC_SW //  PULL_UP +3.3 R 4K7
   7   G32 - ON_OFF_CASCADE_PIN        32 <-> LT1206_SHUTDOWN
   8   G33 - PIN_ZUM                   33 <-> BUZZER
   9   G25 - PIN_RELE                  25 <-> RELAY      // PIN_RELE
   10  G26 - ROTARY_ENCODER_A_PIN      26 <-> ENC_CLK
   11  G27 - ROTARY_ENCODER_B_PIN      27 <-> ENC_DT
   12  G14 - AD9833_SCK   14 <-> AD9833_SCLK   <-> TFT_SCK
   13  G12 - AD9833_MISO  12  X  NOT CONNECTED
   14  GND
   15  G13 - AD9833_MOSI  13 <-> AD9833_SDATA  <-> TFT_MOSI
   16  D2
   17  D3
   18  CMD
   19  +5V
   20  GND
   21  G23 - MCP41x1_MOSI 23 <-> MCP41010_SDATA          // Define MOSI pin for MCP4131 or MCP41010
   22  G22 - SCK // INA219 (SCL)
   23  TX - UART (Serial)
   24  RX - UART (Serial)
   25  G21 - SDA // INA219 (SDA)
   26  GND
   27  G19 - MCP41x1_MISO 19  X  NOT CONNECTED          // Define MISO pin for MCP4131 or MCP41010
   28  G18 - MCP41x1_SCK  18 <-> MCP41010_SCLK          // Define SCK pin for MCP41010
   29  G5  - SD_CS         5 <-> SD_CS                  // Define chipselect pin for SD Card
   30  G17 - MCP41x1_ALC  17 <-> MCP41010_ALC           // Define chipselect pin for MCP41010 for ALC
   31  G16 - MCP41x1_CS   16 <-> MCP41x1_CS
   32  G4 - TFT_DC         4 <-> TFT_DC
   33  G0 - TFT_CS         0 <-> TFT_CS                // Define chipselect pin for TFT Display
   34  G2 - TFT_RST        2 <-> TFT_RST
   35  G15 - AD9833_CS    15 <-> AD9833_FSYNC
   36  D1
   37  D0
   38  SCK
*/
