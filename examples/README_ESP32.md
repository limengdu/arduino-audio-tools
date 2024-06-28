# ESP32 Configuration

If you are using ESP32 by Espressif Systems version 3.0.0 and later, audio tools will use the new adc_continuous API.
This board option is under development and changing.

For the adc_continuous API, audio tools provides the following options:

- **sample_rate** (per channel), the effective ADC sampling rate is the number of channels x sample rate and can be:
    - ESP32: 20kHz to 2MHz
    - other ESP32 eg. ESP32S3 611Hz to 83kHz

for example:

    -       306
    -     4,000
    -     5,000
    -     8,000
    -    10,000
    -    11,025
    -    16,000
    -    20,000
    -    22,050
    -    40,000
    -    44,100
    -    48,000
    -    88,200
    -    96,000
    -   176,400
    -   192,200
    -   352,800
    -   384,000
    -   500,000
    - 1,000,000

- **adc_bit_with**
    - 9, 10, 11, 12 depending on ESP32 model
    - audio stream is int16_t
- **adc_calibration_active**: values measured are in mV
- **is_auto_center_read**: subtraction of current estimated average from samples
- **adc_attenuation**:

    | attenuation     | range   | accurate range |
    | ------------    | --------| -------------- |
    | ADC_ATTEN_DB_0  | 0..1.1V | 100-950mV      |
    | ADC_ATTEN_DB_2_5| 0..1.5V | 100-1250mV     |
    | ADC_ATTEN_DB_6  | 0..2.2V | 150-1750mV     |
    | ADC_ATTEN_DB_12 | 0..3.9V | 150-2450mV     |
   
- **channels**:
    - mono = 1  
    - stereo = 2
- **adc_channels**: defining the channels (only channels on ADC unit 1 are supported) e.g.:
    - A3 on Sparkfun ESP32 Thing Plus is ADC_CHANNEL_3
    - A4 on Sparkfun ESP32 Thing Plus is ADC_CHANNEL_0
    - D5 on Adafruit ESP32-S3 is ADC_CHANNEL_4
    - D6 on Adafruit ESP32-S3 is ADC_CHANNEL_5

## Example Configuration
```
auto adcConfig = adc.defaultConfig(RX_MODE);
adcConfig.sample_rate = 44100;
adcConfig.adc_bit_width = 12;
adcConfig.adc_calibration_active = true;
adcConfig.is_auto_center_read = false;
adcConfig.adc_attenuation = ADC_ATTEN_DB_12; 
adcConfig.channels = 2;
adcConfig.adc_channels[0] = ADC_CHANNEL_4; 
adcConfig.adc_channels[1] = ADC_CHANNEL_5;
```

