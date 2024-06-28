# I2S to CSV Converter with reSpeaker Lite

This project demonstrates how to capture audio data from the I2S interface using the reSpeaker Lite board and convert it to CSV format for further analysis or processing. The reSpeaker Lite is an audio board with an integrated XIAO ESP32S3 microcontroller, featuring a dual-channel microphone and speaker. The project utilizes the reSpeaker Lite library, which is built on top of the AudioTools framework.

## Features

- Captures audio data from the I2S interface
- Converts the captured audio data to CSV format
- Streams the CSV data over the serial interface for further processing
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

1. Open the `streams-i2s-serial.ino` sketch in the Arduino IDE.

2. Select the appropriate board and port in the Arduino IDE.

3. Upload the sketch to your reSpeaker Lite board.

4. Open the Serial Monitor to view the CSV output and any log messages.

## Configuration

- `info`: Defines the audio configuration, including the sample rate, number of channels (2 for stereo, 1 for mono), and the number of bits per sample (32 bits).

- `i2sStream`: Creates an instance of the `I2SStream` class to access the I2S interface as a stream.

- `csvStream`: Creates a `CsvOutput` object to convert the audio data to CSV format and stream it over the serial interface.

- `copier`: Creates a `StreamCopy` object to copy the audio data from the I2S stream to the CSV stream.

- `cfg`: Configures the I2S stream with the desired settings, such as the audio format, master/slave mode, and APLL usage.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for more information.
