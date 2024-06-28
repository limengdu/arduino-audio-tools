# reSpeaker Lite MQTT Audio Streaming

This project demonstrates how to use the reSpeaker Lite board, which includes an integrated XIAO ESP32S3 microcontroller, to generate and send audio data to an MQTT broker.

## Hardware Requirements

- reSpeaker Lite board (with integrated XIAO ESP32S3 microcontroller)
- USB cable for power and programming

## Software Requirements

- Arduino IDE
- [ArduinoMqttClient library](https://www.arduino.cc/reference/en/libraries/arduinomqttclient/)
- [reSpeaker Lite library](https://github.com/limengdu/reSpeaker_Lite-Arduino-Library.git)

## Setup Instructions

1. Connect the reSpeaker Lite board to your computer using a USB cable.

2. Open the Arduino IDE and install the necessary libraries:
   - WiFi library (should be included with the ESP32 board package)
   - ArduinoMqttClient library (can be installed via the Library Manager)
   - reSpeaker Lite library (modified version of AudioTools library, provided with the project)

3. Open the `reSpeaker_MQTT_Audio.ino` sketch in the Arduino IDE.

4. Modify the following lines in the sketch to match your WiFi and MQTT broker settings:

   ```cpp
   const char* ssid = "SSID";    // your network SSID (name)
   const char* password = "PASSWORD";    // your network password (use for WPA, or use as key for WEP)
   const char* broker = "test.mosquitto.org"; 
   const char* topic = "audio.wav";
   int port = 1883;
   ```

5. Upload the sketch to your reSpeaker Lite board.

6. Open the Serial Monitor to view the output and ensure that the reSpeaker Lite board connects to the WiFi network and MQTT broker successfully.

## Functionality

The sketch performs the following tasks:

1. Connects to the specified WiFi network.
2. Connects to the specified MQTT broker.
3. Generates white noise audio using the `WhiteNoiseGenerator` class from the reSpeaker Lite library.
4. Encodes the audio data as a WAV file using the `WAVEncoder` class from the reSpeaker Lite library.
5. Sends the encoded audio data to the specified MQTT topic using the `MqttClient` class from the ArduinoMqttClient library.
6. Maintains the MQTT connection by regularly calling the `poll()` function.

## Customization

You can customize the audio generation and encoding by modifying the following lines in the sketch:

```cpp
WhiteNoiseGenerator<int16_t> noise(32000);
GeneratedSoundStream<int16_t> in_stream(noise);
EncodedAudioStream out_stream(&mqttClient, new WAVEncoder());
```

- `WhiteNoiseGenerator` generates white noise audio with a specified maximum amplitude.
- `GeneratedSoundStream` creates an input stream from the generated audio.
- `EncodedAudioStream` encodes the audio data using the specified encoder (WAV in this case).

You can also adjust the size of the audio data being sent by modifying the `SIZE` and `N` constants:

```cpp
#define SIZE 1024
#define N 100
```

- `SIZE` represents the size of each audio data chunk.
- `N` represents the number of audio data chunks to send.

## License

This project is open-source and available under the [GNU General Public License v3.0](LICENSE).
