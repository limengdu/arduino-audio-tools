 /**
 * @file streams-i2s-serial.ino
 * @author Phil Schatzmann
 * @modifier Seeed Studio
 * @brief Plotting the waveform of a recorded sound from the I2S.
 * @copyright GPLv3
 */

#include "AudioTools.h"

AudioInfo info(16000, 2, 32);
I2SStream i2sStream; // Access I2S as stream
CsvOutput<int32_t> csvStream(Serial);
StreamCopy copier(csvStream, i2sStream); // copy i2sStream to csvStream

// Arduino Setup
void setup(void) {
    Serial.begin(115200);
    AudioLogger::instance().begin(Serial, AudioLogger::Info);
    
    auto cfg = i2sStream.defaultConfig(RX_MODE);
    cfg.copyFrom(info);
    cfg.i2s_format = I2S_STD_FORMAT; // or try with I2S_LSB_FORMAT
    cfg.is_master = false;  // this module nees a master clock if the ESP32 is master
    cfg.use_apll = false;   // try with yes
    i2sStream.begin(cfg);

    // make sure that we have the correct channels set up
    csvStream.begin(info);

}

// Arduino loop - copy data
void loop() {
    copier.copy();
}
