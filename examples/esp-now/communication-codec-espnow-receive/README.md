# reSpeaker Lite ESP-NOW Audio Streaming

This project demonstrates how to use the reSpeaker Lite board, which includes an integrated XIAO ESP32S3 microcontroller, to receive audio data over ESP-NOW and play it back using the on-board I2S interface.

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

3. Open the `communication-codec-espnow-receive.ino` sketch in the Arduino IDE.

4. Modify the following line in the sketch to match the MAC address of the sender device:

   ```cpp
   const char *peers[] = {"A8:48:FA:0B:93:02"};
   ```

5. Upload the sketch to your reSpeaker Lite board.

6. Open the Serial Monitor to view the output and ensure that the reSpeaker Lite board starts the receiver successfully.

## Functionality

The sketch performs the following tasks:

1. Sets up the ESP-NOW communication using the `ESPNowStream` class from the ESPNowStream library.
2. Configures the I2S interface using the `I2SStream` class from the reSpeaker Lite library.
3. Creates an `EncodedAudioStream` object to decode the received SBC audio data using the `SBCDecoder` class from the CodecSBC library.
4. Uses a `StreamCopy` object to copy the decoded audio data from the `ESPNowStream` to the `I2SStream`.
5. Continuously receives and plays back the audio data in the `loop()` function.

## ESP-NOW Configuration

The ESP-NOW communication is set up using the following code:

```cpp
auto cfg = now.defaultConfig();
cfg.mac_address = "A8:48:FA:0B:93:01";
now.begin(cfg);
now.addPeers(peers);
```

- The `defaultConfig()` function is used to get the default configuration for the `ESPNowStream`.
- The `mac_address` field is set to the MAC address of the receiver device.
- The `begin()` function is called to initialize the `ESPNowStream` with the specified configuration.
- The `addPeers()` function is used to add the MAC address of the sender device to the list of peers.

## Audio Decoding

The received SBC audio data is decoded using the `SBCDecoder` class from the CodecSBC library:

```cpp
EncodedAudioStream decoder(&out, new SBCDecoder(256));
```

- The `EncodedAudioStream` object is created with the `I2SStream` as the output and a new instance of the `SBCDecoder` with a buffer size of 256 bytes.
- The ESP-NOW payload size is limited to 256 bytes, so the SBC decoder is configured accordingly.

## Copying Audio Data

The decoded audio data is copied from the `ESPNowStream` to the `I2SStream` using a `StreamCopy` object:

```cpp
StreamCopy copier(decoder, now);
```

- The `StreamCopy` object is created with the `EncodedAudioStream` (decoder) as the source and the `ESPNowStream` as the destination.
- In the `loop()` function, the `copy()` function of the `StreamCopy` object is called continuously to copy the audio data.

## License

This project is open-source and available under the [GNU General Public License v3.0](LICENSE).
