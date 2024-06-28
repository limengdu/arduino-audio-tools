/**
 * @file i2s_rgb.ino
 * @author Seeed Studio
 * @brief Making a music spectrometer
 * @version 1.0
 * @date 2024-06-28
 *
 * @copyright Copyright (c) 2024
 */

#include <ESP_I2S.h>
#include <wav_header.h>
#include <Adafruit_NeoPixel.h>

I2SClass I2S;

#define PIN        D2
#define NUMPIXELS  10
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL   500                                // Time (in milliseconds) to pause between pixels

const int sampleRate = 16000;                         // sample rate in Hz
const int frequency = 440;                            // frequency of square wave in Hz
const int amplitude = 500;                            // amplitude of square wave
int32_t sample = amplitude;                           // current sample value
const int halfWavelength = sampleRate / frequency;    // half wavelength of square wave

bool i2s_rgb = true;


void setup() {
  Serial.begin(115200);
//  while(!Serial);             // Wait for the serial port to connect

  strip.begin();
  strip.show();
  strip.setBrightness(20);

  I2S.setPins(8, 7, 43, 44);  // Configure I2S pins
  if (!I2S.begin(I2S_MODE_STD, sampleRate, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO)){
    Serial.println("Failed to initialize I2S!");
    while(1);                 // Halt if failed to initialize
  }
}

void loop() {
  int32_t sample_read;
  uint32_t sum = 0;
  int count = 0;

  // Reading audio data from I2S
  for (int i = 0; i < 1024; i++) {
    sample_read = I2S.read();
    if (sample_read != 0 && sample_read != 0xFFFF){
      sum += abs(sample_read);  // Calculating Absolute Value Sums
      count++;
    }
  }

  int average = sum / count;    // Calculation of average intensity
  Serial.println(average);

  int activeLEDs = map(average, 30000, 36000, 0, NUMPIXELS);  // Mapping average to LED quantity, value to map, value current range, value target range after mapping

  // Update LED strip brightness and colour
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i < activeLEDs) {
      // Setting the colour according to the LED position
      int colorIntensity = map(i, 0, NUMPIXELS - 1, 0, 255);
      strip.setPixelColor(i, strip.Color(0, colorIntensity, 255 - colorIntensity));  // Transition from blue to green
    } else {
      strip.setPixelColor(i, strip.Color(0, 0, 0));  // Switching off inactive LEDs
    }
  }
  strip.show();

  delay(100);
}
