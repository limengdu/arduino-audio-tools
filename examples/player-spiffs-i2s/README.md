# MP3 Player with reSpeaker Lite

This project demonstrates how to use the reSpeaker Lite board to play MP3 files stored in the SPIFFS file system. The reSpeaker Lite is an audio board with an integrated XIAO ESP32S3 microcontroller, featuring a dual-channel microphone and speaker. The project utilizes the reSpeaker Lite library, which is built on top of the AudioTools framework.

## Features

- Plays MP3 files from the SPIFFS file system
- Utilizes the I2S interface for audio output
- Supports metadata extraction and callback
- Easy-to-use AudioPlayer class for seamless audio playback

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller)
- USB cable for power and programming

## Software Requirements

- Arduino IDE
- ESP32 Arduino Core
- [reSpeaker Lite library](https://github.com/limengdu/reSpeaker_Lite-Arduino-Library.git)
- [reSpeaker Lite arduino libhelix](https://github.com/limengdu/reSpeaker_Lite-arduino-libhelix)

## Getting Started

### Installation

1. Install the ESP32 Arduino Core in the Arduino IDE by following the instructions provided by Espressif.

### Wiring

1. Connect the reSpeaker Lite board to your computer using a USB cable.

### Uploading Files to SPIFFS

You can refer to the [Wiki here](https://wiki.seeedstudio.com/xiao_esp32s3_sense_filesystem/#serial-peripheral-interface-flash-file-system-spiffs).

1. Make sure you have the necessary tools to upload files to SPIFFS. You can use the "ESP32 Sketch Data Upload" tool in the Arduino IDE or an external tool like "ESP32 File Uploader".

2. Create a folder named "data" in your sketch directory and place the MP3 files you want to play inside it.

3. Upload the files to SPIFFS using the chosen tool.

### Uploading the Sketch

1. Open the `player-spiffs-i2s.ino` sketch in the Arduino IDE.

2. Select the appropriate board and port in the Arduino IDE.

3. Upload the sketch to your reSpeaker Lite board.

4. Open the Serial Monitor to view the metadata and playback information.

## Configuration

- `startFilePath`: The directory path where the MP3 files are located in SPIFFS (default: "/").
- `ext`: The file extension of the audio files (default: "mp3").

You can modify these constants in the sketch to match your specific file structure and requirements.

## Customization

- `printMetaData`: This function is called when metadata is extracted from the audio file. You can customize the function to handle the metadata according to your needs.

- `AudioSourceSPIFFS`: You can change the file filter by uncommenting the line `//source.setFileFilter("*Bob Dylan*");` and replacing the filter with your desired criteria.

## License

This project is licensed under the GNU General Public License v3.0. See the [LICENSE](LICENSE) file for more information.
