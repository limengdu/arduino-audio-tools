/**
 * @file example-serial-send.ino
 * @author Phil Schatzmann
 * @brief Sending encoded audio over ESPNow
 * @version 0.1
 * @date 2024-06-28
 *
 * @copyright Copyright (c) 2024
 */

#include "AudioTools.h"
#include "Communication/ESPNowStream.h"
#include "AudioCodecs/CodecSBC.h"

AudioInfo info(16000, 1, 32);
SineWaveGenerator<int16_t> sineWave(32000);  // subclass of SoundGenerator with max amplitude of 32000
GeneratedSoundStream<int16_t> sound(sineWave); // Stream generated from sine wave
ESPNowStream now;
SBCEncoder sbc;
EncodedAudioStream encoder(&now, &sbc); // encode and write to ESP-now
StreamCopy copier(encoder, sound);  // copies sound into i2s
const char *peers[] = {"A8:48:FA:0B:93:01"};

void setup() {
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Warning);

  auto cfg = now.defaultConfig();
  cfg.mac_address = "A8:48:FA:0B:93:02";
  now.begin(cfg);
  now.addPeers(peers);

  // Setup sine wave
  sineWave.begin(info, N_B4);

  // start encoder
  encoder.begin(info);
  
  Serial.println("Sender started...");
}

void loop() { 
  copier.copy();
}
