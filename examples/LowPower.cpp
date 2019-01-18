#include <main.h>
#include <WioCellLibforArduino.h>
#include "STM32LowPower.h"

void setup() {
  LowPower.begin();
}

void loop() {
	HAL_Delay(10000);

//	 __WFI();

//	 __WFE();

//	 HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);

//  LowPower.deepSleep(10000);

//	LowPower.shutdown(10000);
}
