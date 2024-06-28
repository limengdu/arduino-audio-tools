# Audio Reactive NeoPixel Strip with reSpeaker

This project demonstrates how to use the reSpeaker board to control a NeoPixel LED strip based on the intensity of audio input received through the I2S interface. The LED strip reacts to the audio by adjusting its brightness and color according to the average intensity of the audio samples.

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller)
- [Grove - RGB LED Stick](https://www.seeedstudio.com/Grove-RGB-LED-Stick-10-WS2813-Mini.html)
- Jumper wires

## Software Requirements

- Arduino IDE

## Wiring

1. Connect the NeoPixel LED strip to the reSpeaker board:
   - Data pin of the LED strip to pin D2 of the reSpeaker
   - Power and ground pins of the LED strip to the appropriate power supply

2. The I2S microphone is already integrated on the reSpeaker board, so no additional wiring is needed for audio input.

## Setup Instructions

1. Install the reSpeaker Arduino Library in the Arduino IDE by following the instructions provided in the reSpeaker documentation.

2. Open the `i2s_rgb.ino` sketch in the Arduino IDE.

3. Modify the following constants in the sketch if needed:
   - `PIN`: The pin number connected to the data pin of the NeoPixel strip (default: D2)
   - `NUMPIXELS`: The number of pixels in the NeoPixel strip (default: 10)
   - `sampleRate`: The sample rate of the I2S audio input (default: 16000 Hz)

4. Upload the sketch to your reSpeaker board.

5. Open the Serial Monitor to view the average audio intensity values.

## Functionality

The sketch performs the following tasks:

1. Initializes the NeoPixel LED strip and sets its brightness.

2. Configures the I2S interface.

3. Continuously reads audio samples from the I2S interface in blocks of 1024 samples.

4. Calculates the absolute value sum of the non-zero audio samples and determines the average intensity.

5. Maps the average intensity to the number of active LEDs on the NeoPixel strip.

6. Updates the color and brightness of each LED based on its position and the mapped intensity value.
   - The color transitions from blue to green along the length of the strip.
   - Inactive LEDs are turned off.

7. Displays the updated LED colors on the NeoPixel strip.

8. Prints the average audio intensity value to the Serial Monitor for debugging purposes.

9. Repeats the process with a delay of 100 milliseconds between each iteration.

## Customization

You can customize the behavior of the audio reactive NeoPixel strip by modifying the following parameters:

- `DELAYVAL`: The delay time (in milliseconds) between each pixel update (default: 500)
- Mapping range for `activeLEDs`: Adjust the range of average intensity values to map to the number of active LEDs (default: 30000 to 36000)
- Color scheme: Modify the `strip.setPixelColor()` function to change the color transition or use different colors for the LEDs

## License

This project is open-source and available under the [GNU General Public License v3.0](LICENSE).
