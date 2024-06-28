/**
 * @file example-serial-receive_measure.ino
 * @author Phil Schatzmann
 * @modifier Seeed Studio
 * @brief Receiving audio via ESPNow with max speed to measure thruput
 * @version 1.0
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "AudioTools.h"
#include "Communication/ESPNowStream.h"
#include "AudioCodecs/CodecSBC.h"

ESPNowStream now;
MeasuringStream out(1000, &Serial);
EncodedAudioStream decoder(&out, new SBCDecoder()); // decode and write to I2S
StreamCopy copier(decoder, now);     
const char *peers[] = {"A8:48:FA:0B:93:02"};

void setup() {
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Warning);

  // start esp-now
  auto cfg = now.defaultConfig();
  cfg.mac_address = "A8:48:FA:0B:93:01";
  now.begin(cfg);
  now.addPeers(peers);

  // start output
  decoder.begin();
  out.begin();

  Serial.println("Receiver started...");
}

void loop() { 
  copier.copy();
}
