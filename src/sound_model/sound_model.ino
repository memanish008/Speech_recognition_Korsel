#include "TensorFlowLite.h"
#include "tensorflow/lite/experimental/micro/kernels/micro_ops.h"
#include "tensorflow/lite/experimental/micro/micro_error_reporter.h"
#include "tensorflow/lite/experimental/micro/micro_interpreter.h"
#include "tensorflow/lite/experimental/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/version.h"

// Our model
#include "sine_model.h"

// Custom libraries
#include "movingAvg.h"
#include "Mic.h"


// tune as per your needs
#define WINDOW 5
#define SAMPLES 64-WINDOW
#define GAIN (1.0f/50)
#define FEATURE_NORM 64
#define SOUND_THRESHOLD 250     
#define BLUE 24

Mic mic;
float features[SAMPLES];
movingAvg audioSensor(WINDOW);

// TFLite globals, used for compatibility with Arduino-style sketches
namespace {
  tflite::ErrorReporter* error_reporter = nullptr;
  const tflite::Model* model = nullptr;
  tflite::MicroInterpreter* interpreter = nullptr;
  TfLiteTensor* model_input = nullptr;
  TfLiteTensor* model_output = nullptr;

  // Create an area of memory to use for input, output, and other TensorFlow
  // arrays. You'll need to adjust this by combiling, running, and looking
  // for errors.
  constexpr int kTensorArenaSize = 5 * 1024;
  uint8_t tensor_arena[kTensorArenaSize];
} // namespace

void setup() {
    Serial.begin(115200);
    PDM.onReceive(onAudio);
    mic.begin();
    audioSensor.begin();
    pinMode(BLUE, OUTPUT);
    delay(3000);
}

void loop() {
    // await for a word to be pronounced
    if (recordAudioSample()) {
        // print features to serial monitor
        
        for (int i = 0; i < SAMPLES; i++) {            
            Serial.print(features[i], 6);
            Serial.print(i == SAMPLES - 1 ? '\n' : ',');
        }
        delay(1000);
    }

    delay(20);
}

/**
 * PDM callback to update mic object
 */
void onAudio() {
    mic.update();
}

/**
 * Read given number of samples from mic
 */
bool recordAudioSample() {
    if (mic.hasData() && mic.data() > SOUND_THRESHOLD) {
        int j = 0;
        float movingAvg;
        float sensorReading;
        audioSensor.reset();
        for (int i = 0; i < (SAMPLES+WINDOW); i++) {
            digitalWrite(BLUE, HIGH);
            while (!mic.hasData())
                delay(1);
            
            digitalWrite(BLUE, LOW);
            sensorReading = mic.pop();
            sensorReading = sensorReading*GAIN;
            sensorReading = sensorReading/FEATURE_NORM;
            movingAvg = audioSensor.reading(sensorReading);
            if (i >= WINDOW){
              features[j] = movingAvg;
              j++;
            }
        }
        return true;
    }

    return false;
}
