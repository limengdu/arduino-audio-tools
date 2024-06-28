# Sine Wave Generator with reSpeaker Lite

This project demonstrates how to generate a sine wave and play it using the I2S interface on the reSpeaker Lite board. The reSpeaker Lite is an audio board with an integrated XIAO ESP32S3 microcontroller, featuring a dual-channel microphone and speaker. The project utilizes the reSpeaker Lite library, which is built on top of the AudioTools framework.

## Features

- Generates a sine wave with a specified frequency
- Plays the generated sine wave through the I2S interface
- Utilizes the AudioTools framework for audio processing and streaming
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

1. Open the `streams-generator-i2s.ino` sketch in the Arduino IDE.

2. Select the appropriate board and port in the Arduino IDE.

3. Upload the sketch to your reSpeaker Lite board.

4. Open the Serial Monitor to view the output and any log messages.

## Configuration

- `info`: Defines the audio configuration, including the sample rate, number of channels (2 for stereo, 1 for mono), and the number of bits per sample (16 bits).

- `sineWave`: Creates an instance of the `SineWaveGenerator` class with a maximum amplitude of 32000.

- `sound`: Creates a `GeneratedSoundStream` object using the `sineWave` generator.

- `out`: Creates an instance of the `I2SStream` class for audio output.

- `copier`: Creates a `StreamCopy` object to copy the generated sound to the I2S output.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for more information.
