# reSpeaker Lite ESP-NOW Audio Streaming

This project demonstrates how to use the reSpeaker Lite board, which includes an integrated XIAO ESP32S3 microcontroller, to generate a sine wave audio signal, encode it using the SBC codec, and send the encoded audio data over ESP-NOW to a receiver device.

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller)
- USB cable for power and programming

## Software Requirements

- Arduino IDE
- [reSpeaker Lite library](https://github.com/limengdu/reSpeaker_Lite-Arduino-Library.git)
- [CodecSBC library](https://github.com/limengdu/reSpeaker_Lite-libsbc.git)

## Setup Instructions

1. Connect the reSpeaker Lite board to your computer using a USB cable.

2. Open the Arduino IDE and install the necessary libraries:
   - reSpeaker Lite library (modified version of AudioTools library, provided with the project)
   - CodecSBC library (modified version of arduino-libsbc library, provided with the project)

3. Open the `communication-codec-espnow-send.ino` sketch in the Arduino IDE.

4. Modify the following line in the sketch to match the MAC address of the receiver device:

   ```cpp
   const char *peers[] = {"A8:48:FA:0B:93:01"};
   ```

5. Upload the sketch to your reSpeaker Lite board.

6. Open the Serial Monitor to view the output and ensure that the reSpeaker Lite board starts the sender successfully.

## Functionality

The sketch performs the following tasks:

1. Sets up a `SineWaveGenerator` to generate a sine wave audio signal with a frequency of B4 (494 Hz) and a maximum amplitude of 32000.
2. Creates a `GeneratedSoundStream` object to convert the generated sine wave into a stream of audio samples.
3. Sets up the ESP-NOW communication using the `ESPNowStream` class from the ESPNowStream library.
4. Creates an `EncodedAudioStream` object to encode the audio samples using the SBC codec and write the encoded data to the `ESPNowStream`.
5. Uses a `StreamCopy` object to copy the audio samples from the `GeneratedSoundStream` to the `EncodedAudioStream`.
6. Continuously generates, encodes, and sends the audio data in the `loop()` function.

## Sine Wave Generation

The sine wave audio signal is generated using the `SineWaveGenerator` class:

```cpp
SineWaveGenerator<int16_t> sineWave(32000);
```

- The `SineWaveGenerator` is a subclass of `SoundGenerator` and generates a sine wave with a specified maximum amplitude (32000 in this case).
- The generated sine wave is then converted into a stream of audio samples using the `GeneratedSoundStream` class.

## ESP-NOW Configuration

The ESP-NOW communication is set up using the following code:

```cpp
auto cfg = now.defaultConfig();
cfg.mac_address = "A8:48:FA:0B:93:02";
now.begin(cfg);
now.addPeers(peers);
```

- The `defaultConfig()` function is used to get the default configuration for the `ESPNowStream`.
- The `mac_address` field is set to the MAC address of the sender device.
- The `begin()` function is called to initialize the `ESPNowStream` with the specified configuration.
- The `addPeers()` function is used to add the MAC address of the receiver device to the list of peers.

## Audio Encoding

The audio samples are encoded using the SBC codec with the `SBCEncoder` class from the CodecSBC library:

```cpp
SBCEncoder sbc;
EncodedAudioStream encoder(&now, &sbc);
```

- An instance of the `SBCEncoder` is created.
- The `EncodedAudioStream` object is created with the `ESPNowStream` as the output and the `SBCEncoder` as the encoder.

## Copying Audio Data

The audio samples are copied from the `GeneratedSoundStream` to the `EncodedAudioStream` using a `StreamCopy` object:

```cpp
StreamCopy copier(encoder, sound);
```

- The `StreamCopy` object is created with the `EncodedAudioStream` (encoder) as the destination and the `GeneratedSoundStream` (sound) as the source.
- In the `loop()` function, the `copy()` function of the `StreamCopy` object is called continuously to copy the audio data.

## License

This project is open-source and available under the [GNU General Public License v3.0](LICENSE).
