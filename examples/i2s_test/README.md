# reSpeaker Lite I2S Test

This project is a test sketch for verifying the functionality of the I2S interface on the reSpeaker Lite board, which integrates a XIAO ESP32S3 microcontroller and a microphone array. The sketch generates a square wave audio signal, writes it to the I2S interface, and then reads back the samples from the onboard microphone array to check the integrity of the I2S transmission and reception.

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller and microphone array)
- USB cable for power and programming

## Software Requirements

- Arduino IDE

## Getting Started

### Wiring

1. Connect the reSpeaker Lite board to your computer using a USB cable.

### Software Setup

1. Install the ESP32 Arduino Core in the Arduino IDE by following the instructions provided by Espressif.

2. Open the `i2s_test.ino` sketch in the Arduino IDE.

3. Upload the sketch to your reSpeaker Lite board.

4. Open the Serial Monitor to view the test results and I2S sample values.

## Test Procedure

1. The sketch starts by initializing the serial communication and configuring the I2S pins.

2. It generates a square wave audio signal based on the specified frequency and amplitude.

3. The generated audio samples are written to the I2S interface using the `I2S.write()` function.

4. The sketch then reads back the samples from the microphone array through the I2S interface using the `I2S.read()` function and counts the number of non-zero samples received.

5. If the number of non-zero samples received exceeds a threshold (16000 in this case), the I2S reception is considered a pass. Otherwise, it is considered a fail.

6. The test results, including the I2S sample values and the pass/fail status, are printed to the Serial Monitor.

## License

This project is open-source and available under the [GNU General Public License v3.0](LICENSE).
