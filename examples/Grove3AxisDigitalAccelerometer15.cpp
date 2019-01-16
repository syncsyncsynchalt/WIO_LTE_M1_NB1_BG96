/**
 * Groveの3軸加速度センサの安い方
 * https://www.seeedstudio.com/Grove-3-Axis-Digital-Accelerometer-1-5-p-765.html
 *
 *
 *
 * マイコンの周波数を下げて使うときの注意。
 * APB1とAPB2を 8MHz 未満にすると I2C がちゃんと動かない。わからない。特にまだ困ってないのでそのままにしています。
 *
 */

#include <WioCellLibforArduino.h>

#include <Wire.h>
#include "MMA7660.h"

WioCellular Wio;

MMA7660 accelemeter;

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

	accelemeter.init();
}

void loop() {
	int8_t x;
	int8_t y;
	int8_t z;
	float ax, ay, az;
	accelemeter.getXYZ(&x, &y, &z);

	SerialUSB.print("x = ");
	SerialUSB.println(x);
	SerialUSB.print("y = ");
	SerialUSB.println(y);
	SerialUSB.print("z = ");
	SerialUSB.println(z);

	accelemeter.getAcceleration(&ax, &ay, &az);
	SerialUSB.println("accleration of X/Y/Z: ");
	SerialUSB.print(ax);
	SerialUSB.println(" g");
	SerialUSB.print(ay);
	SerialUSB.println(" g");
	SerialUSB.print(az);
	SerialUSB.println(" g");
	SerialUSB.println("*************");
	delay(500);
}

