#include <Homie.hpp>
#include <Wire.h>
#include <HomieBME280Node.h>

#include <RGBWNode.h>
#include <LoggerNode.h>
#include <InputPinArrayNode.h>


#define FW_NAME "FLN_DK_ESP-1xRGBW"
#define FW_MAJOR "1"
#define FW_MINOR "0"
#define BUILD_NUMBER "1"

#define FW_VERSION FW_MAJOR "." FW_MINOR "." BUILD_NUMBER

LoggerNode LN;

//LED_RGB = 12V, G, R, B
//               15 14 16
//LED_W1  = 12V, W
//               0
RGBWNode rgbw1("LEDRGBW", 14, 15, 16, 0);

// Second White is not used for now
//LED_W2   = 12V, W
//                2
//RGBWNode w2("LED_W2", RGBWNode::NOPIN, RGBWNode::NOPIN, RGBWNode::NOPIN, 2);

// Input 1: Pin 12 (PULLUP)
//       2: Pin 12 (PULLUP)
//       3: GND
//       4: Analog -> ADC (not used)
std::vector<InputPinArrayNode::pin_data> vecInputs = {{13,false,false},{12, false, false}};
InputPinArrayNode::InputPinChangeEventHandler handler = [](uint8_t idx, bool state)->bool {
	LN.logf(__PRETTY_FUNCTION__, LoggerNode::INFO, "Input %x changed to %s", idx, state?"true":"false");
	rgbw1.switchLed((idx==0)?"w":"r", state?50:0);
	return true;
};

InputPinArrayNode inputs(vecInputs, handler);

// Sensors on I2C:
//   BME280
HomieBME280Node sensorNode;

void setup() {
	Homie_setFirmware(FW_NAME, FW_VERSION);
    Serial.begin(74880);
    Serial.println("Setup");    
    Serial.flush();
	Wire.begin(SDA, SCL);
	Homie.disableLedFeedback();	      // no Status LED
	Homie.disableResetTrigger();      // no Factory-Reset via Input-PIN
	Homie.setLoggingPrinter(&Serial); // Log homie-information to Serial
	Homie.setup();
}

void loop() {
	Homie.loop();

}
