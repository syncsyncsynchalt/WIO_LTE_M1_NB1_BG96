#include <WioCellLibforArduino.h>

WioCellular Wio;
SerialAPI _SerialAPI = SerialAPI(NULL);
AtSerial _AtSerial = AtSerial(NULL, NULL);

void setup() {
  delay(200);

  SerialUSB.begin(115200);
  SerialUSB.println("");
  SerialUSB.println("--- START ---------------------------------------------------");

  SerialUSB.println("### I/O Initialize.");


  Wio.Init();
  SerialUSB.println("### Power supply ON.");
  Wio.PowerSupplyGrove(true);
  delay(500);

  SerialUART.begin(9600);
  _SerialAPI = SerialAPI(&SerialUART);
  _AtSerial = AtSerial(&_SerialAPI, &Wio);
  _AtSerial.WriteCommand("###SerialUART init.");

  SerialUSB.println("### Setup completed.");
}

void loop() {
	std::string response;
	if (_AtSerial.ReadResponse("^OK.*$", 3000, &response)) {
		SerialUSB.println("### Matched!");
	}
	SerialUSB.println(response.c_str());
}
