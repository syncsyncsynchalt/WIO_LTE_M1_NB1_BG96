#include "stm32f4xx_hal.h"
#include <WioCellLibforArduino.h>

#define APN               "soracom.io"
#define USERNAME          "sora"
#define PASSWORD          "sora"

WioCellular Wio;

void setup() {
	SerialUSB.begin(115200);

	Wio.Init();
	Wio.PowerSupplyCellular(true);
	Wio.SetAccessTechnology(WioCellular::ACCESS_TECHNOLOGY_LTE_M1);
	Wio.SetSelectNetwork(WioCellular::SELECT_NETWORK_MODE_MANUAL_IMSI);
	delay(500);

	if (!Wio.TurnOnOrReset()) {
		return;
	}
	delay(500);

	// delay(120000);
	if (!Wio.Activate(APN, USERNAME, PASSWORD)) {
		return;
	}

	Wio._AtSerial.WriteCommandAndReadResponse("AT+QCFG=?", "^OK$", 500, NULL);
	Wio._AtSerial.WriteCommandAndReadResponse("AT+QCFG?", "^OK$", 500, NULL);

	Wio.GetReceivedSignalStrength();

	SerialUSB.println("### Setup completed.");
}

void loop() {
}

