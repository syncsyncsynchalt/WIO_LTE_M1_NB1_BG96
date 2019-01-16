/*
 * grove-button.inoからArduinoの皮を剥がした場合
 */
#include "main.h"
#include <WioCellLibforArduino.h>

GPIO_InitTypeDef GPIO_InitStruct = {0};

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  GPIO_InitStruct.Pin = GRO_POWR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GRO_POWR_GPIO_Port, &GPIO_InitStruct);

  HAL_GPIO_WritePin(GRO_POWR_GPIO_Port, GPIO_MODE_OUTPUT_PP, GPIO_PIN_SET);

  GPIO_InitStruct.Pin = D38_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(D38_GPIO_Port, &GPIO_InitStruct);
}

void loop() {
  int buttonState = HAL_GPIO_ReadPin(D38_GPIO_Port, D38_Pin) == GPIO_PIN_SET ? HIGH : LOW;;
  SerialUSB.print(buttonState ? '*' : '.');
  delay(100);
}
