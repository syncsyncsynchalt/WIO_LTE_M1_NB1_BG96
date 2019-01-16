// GPIOの割り込み
//
// Grove-Buttonの2回路版。端的に言えばプルダウンのスイッチ2つ。
//
// VCC
//  +                   D20
//  |                    o
//  |                    |
//  |            _/      |     ___
//  |----------o/  o-----o----|___|------
//  |                          10k      |
//  |                                   |
//  |            _/            ___      |
//  |----------o/  o-----o----|___|-----o
//                       |     10k      |
//                       |              |
//                       o              |
//                      D19            ===
//                                     GND
#include "main.h"
#include <WioCellLibforArduino.h>

WioCellular Wio;

void push_d19()
{
  SerialUSB.println("Push D19");
}

void push_d20()
{
  SerialUSB.println("Push D20");
}

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);

  pinMode(WIO_D19, INPUT);
  attachInterrupt(WIO_D19, push_d19, FALLING);

  pinMode(WIO_D20, INPUT);
  attachInterrupt(WIO_D20, push_d20, FALLING);
}

void loop() {
}
