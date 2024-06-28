# Keyword Spotting with reSpeaker Lite and TensorFlow Lite

This project demonstrates how to perform keyword spotting using the reSpeaker Lite board and TensorFlow Lite. The reSpeaker Lite is an audio board with an integrated XIAO ESP32S3 microcontroller, featuring a dual-channel microphone and speaker. The project utilizes the reSpeaker Lite library, which is built on top of the AudioTools framework, and integrates with TensorFlow Lite for audio classification.

## Features

- Captures audio from the I2S interface using the reSpeaker Lite board
- Performs keyword spotting using a pre-trained TensorFlow Lite model
- Classifies the captured audio into predefined categories: silence, unknown, yes, and no
- Provides a callback function to respond to detected commands
- Utilizes the AudioTools framework for audio processing and streaming
- Easy-to-use AudioLogger for debugging and monitoring

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller)
- USB cable for power and programming

## Software Requirements

- Arduino IDE
- ESP32 Arduino Core
- [reSpeaker Lite library](https://github.com/limengdu/reSpeaker_Lite-Arduino-Library.git)
- [TensorFlow Lite library](https://github.com/limengdu/tflite-micro-reSpeaker-Lite-arduino-examples)

## Getting Started

### Installation

1. Install the ESP32 Arduino Core in the Arduino IDE by following the instructions provided by Espressif.

### Wiring

1. Connect the reSpeaker Lite board to your computer using a USB cable.

### Uploading the Sketch

1. Open the `streams-i2s-tflite.ino` sketch in the Arduino IDE.

2. Select the appropriate board and port in the Arduino IDE.

3. Upload the sketch to your reSpeaker Lite board.

4. Open the Serial Monitor to view the classification results and any log messages.

## Configuration

- `i2s`: Creates an instance of the `I2SStream` class to capture audio from the I2S interface.

- `tfl`: Creates an instance of the `TfLiteAudioStream` class to process the captured audio using TensorFlow Lite.

- `kCategoryLabels`: Defines the category labels for the classification results.

- `copier`: Creates a `StreamCopy` object to copy the audio data from the I2S stream to the TensorFlow Lite stream.

- `channels`: Specifies the number of audio channels (1 for mono).

- `samples_per_second`: Specifies the sample rate of the audio input.

- `respondToCommand`: A callback function that is invoked when a command is detected. It receives the detected command, score, and a flag indicating if it is a new command.

## Customization

- You can modify the `kCategoryLabels` array to define your own set of category labels for the classification results.

- The `respondToCommand` function can be customized to perform specific actions based on the detected commands.

- The TensorFlow Lite model can be replaced with your own trained model by updating the `model.h` file.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for more information.

