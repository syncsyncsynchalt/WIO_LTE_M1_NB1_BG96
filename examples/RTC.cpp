/*
 * ref. STM32Cube_FW_F4_V1.23.0/Projects/STM32F410xx-Nucleo/Examples/RTC/RTC_Calendar
 */
#include "main.h"
#include <WioCellLibforArduino.h>

WioCellular Wio;

uint8_t aShowTime[50] = {0};
uint8_t aShowDate[50] = {0};

void RTC_CalendarShow(uint8_t *showtime, uint8_t *showdate)
{
  RTC_DateTypeDef sdatestructureget;
  RTC_TimeTypeDef stimestructureget;

  /* Get the RTC current Time */
  HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
  /* Get the RTC current Date */
  HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);

  /* Display time Format: hh:mm:ss */
  sprintf((char*)showtime,"%02d:%02d:%02d",stimestructureget.Hours, stimestructureget.Minutes, stimestructureget.Seconds);
  /* Display date Format: mm-dd-yy */
  sprintf((char*)showdate,"%02d-%02d-%02d",sdatestructureget.Month, sdatestructureget.Date, 2000 + sdatestructureget.Year);

}

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  MX_RTC_Init();
}

void loop() {
  delay(3000);
  RTC_CalendarShow(aShowTime, aShowDate);

  SerialUSB.println((char*) aShowTime);
  SerialUSB.println((char*) aShowDate);
}
