# Star Wars Theme Player with reSpeaker Lite

This project demonstrates how to play the Star Wars theme song using the reSpeaker Lite board. The reSpeaker Lite is an audio board with an integrated XIAO ESP32S3 microcontroller, featuring a dual-channel microphone and speaker. The project utilizes the reSpeaker Lite library, which is built on top of the AudioTools framework, to output the audio through the I2S interface.

## Features

- Plays the Star Wars theme song stored in memory
- Utilizes the I2S interface for audio output
- Employs the AudioTools framework for audio processing and streaming
- Easy-to-use AudioLogger for debugging and monitoring

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller)
- USB cable for power and programming

## Software Requirements

- Arduino IDE
- ESP32 Arduino Core
- [reSpeaker Lite library](https://github.com/limengdu/reSpeaker_Lite-Arduino-Library.git)

## Getting Started

### Installation

1. Install the ESP32 Arduino Core in the Arduino IDE by following the instructions provided by Espressif.

### Wiring

1. Connect the reSpeaker Lite board to your computer using a USB cable.

### Uploading the Sketch

1. Open the `stream-memory_raw-i2s.ino` sketch in the Arduino IDE.

2. Select the appropriate board and port in the Arduino IDE.

3. Upload the sketch to your reSpeaker Lite board.

4. The Star Wars theme song will start playing automatically.

## Configuration

- `info`: Defines the audio configuration, including the sample rate (22050 Hz), number of channels (1 for mono), and the number of bits per sample (16 bits).

- `i2s`: Creates an instance of the `I2SStream` class to output audio through the I2S interface.

- `music`: Creates a `MemoryStream` object to store the Star Wars theme song data in memory.

- `copier`: Creates a `StreamCopy` object to copy the audio data from the memory stream to the I2S stream.

## Customization

- You can replace the `StarWars30_raw` and `StarWars30_raw_len` variables with your own audio data to play a different song or sound effect.

- The audio configuration can be modified by adjusting the parameters of the `AudioInfo` object, such as the sample rate, number of channels, and number of bits per sample.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for more information.

