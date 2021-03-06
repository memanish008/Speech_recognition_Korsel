# Speech Recognition on Kørsel

This repository contains the source code and models used for the speech recognition implemented on a Kørsel robot. 

![Kørsel Robot](./assets/Kørsel_driving.gif)
<br/><br/>

## Description of the project

This project intends to provide a simple ML algorithms for speech recognition. The main task is to modify the Kørsel robot and add the speech recognition feature to control the Kørsel robot. 
We perform different experiments to build a tflite model using different architecture until the sufficient classification accuracies of speech control is achieved.
The trained models are deployed in the robot (Kørsel) controlled by Arduino Nano 33 BLE Sense and observe the performances on the real environment.

Kørsel is a simple line tracking robot developed at the University of Applied Sciences Ravensburg Weingarten in the Faculty of Electrical Engineering and Computer Science. It is controlled by a Arduino nano and
has a CNY70 sensor which detects either the black line or the bright/white background. It drives in a zigzag way around tracking line detecting the background color. 

Arduino Nano 33 BLE Sense is used as the microcontroller in the robot since it has the feature to create ML modules using Tensorflow Lite.
Edge impluse is used as the development platform.       

## Contents

* **data/_custom_noise:** - it contains the custom motor noise datasets. This is the noise produced by motor when the robot is in driving on the trackline and is collected using mobile phone.
* **assets/** - a few images related to the project.
* **models/** - all the trained models for differents experiments performed.
* **src/** - contains the scripts written in the Arduino IDE to support the project.  


## Data Collection and Processing
We used the Google Speech Commands dataset which has 65,000 one-second long utterances of sets of thirty short words. This can be obtained from the link [here](http://download.tensorflow.org/data/speech_commands_v0.02.tar.gz). 
In additon to these samples, we have also collected some custom background noise of the the robot using mobile phone. This can be found in the data/_custom_noise folder in our repository.

The source code and the instruction of data curation can be found in the link [here](https://github.com/memanish008/ei-keyword-spotting). 


## Feature extraction
It is the process of extraction of features from the audio signals. Audio MFCC feature is extracted since its suited for the human voice.

![MFCC Feature](./assets/mfcc_feature_extraction.jpg)

<br/><br/>

## Model Training
After the data are processed, we train a classifier model with different architecture in edge impluse. When the training is done, we will see the Model panel at the right side of the page. While starting the training 20% of the data is used for the validation.
Also, we use an early stopping strategy to migitate the overfitting on the training dataset. Data augmentation is also performed while training the models in oder to create robust models by generating a comprehensive set of data. 

![Model Training](./assets/training_output.jpg)

<br/><br/>

## Model Testing
The trained models are evaluated on the test dataset. A confusion matrix is used to compare the testing accuracy of the different classes.

![Model Testing](./assets/model_testing.jpg)

<br/><br/>

## Deployment of the model
We can deploy the model back to our device. This makes the model run without internet connection, minimizes latency, and runs with minimum power consumption. Edge impluse can package up the complete model source codes in a single arduino library. 
The process to deploy the model in nano 33 is
* Download the built .zip Arduino library
* In Arduino IDE from sketch toolbar select the Include library and add this .zip file
* From the File option select examples and then open the model with the filename “nano_ble33_sense_microphone_continuous”
* make the required modification in the sketch to control the robot and then upload the sketch to the nano 33

All these trained models with the modification can be found in the models folder [here](https://github.com/memanish008/Speech_recognition_Korsel/tree/main/models) in our repository. 

![Model Deployment](./assets/model_deployment.jpg)

<br/><br/>

## Experiments

A series of experiments were performed using different neural network architectures to obtain the best model for speech recognition. This includes the whole process of data processing, impulse creating, training and building the model, and deploying it on the robot and observing the model performances on real environment.
In general, we trained and built a classifer model for the target voice command. Then while deploying the model some changes were made in the scripts. This includes catching the target voice commands predicted by the model and defining its function to control the robot. For our case, controlling the robot were
enabling and disabling the motor on the robot, changing the PWM value to control the driving speed of the robot, and blinking different color LEDs for different target voice commands. Through these experiments, we evaluated the performances of the model, found out the issues and estimated the possible ways to get rid of it.       

The videos of testing the Kørsel robot performance on the track line using different trained models are available in the Google Drive link [here](https://drive.google.com/drive/folders/1pUV_IysSdNKn0U_R8hXAS0FiaRnUzW44?usp=sharing).
