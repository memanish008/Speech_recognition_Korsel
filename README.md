 # Speech Recognition on Kørsel

This repository contains the source code and models used for the speech recognition implemented on a Korsel robot. 
 
![Korsel Robot](./images/korsel_robot.jpg)

## Description of the project

This project intends to provide a simple ML algorithms for speech recognition. The main task is to modify the Kørsel project and make a small robot with the capability of speech recognition. 
We perform different experiment to build a tflite model using different architecture until the sufficient classification accuracies of speech control is achieved.

The trained models are deployed in the robot (Kørsel) controlled by Arduino Nano 33 BLE Sense and observe the performances on the real environment.

Arduino Nano 33 BLE Sense is used as the microcontroller in the robot since it has the feature to create ML modules using Tensorflow Lite.

Edge impluse is used as the development flatform. Loading the sample data, pre-processing them, extracting the features, building the neural architecture for model training, model testing
and building the model .zip file, all are performed in edge impluse.      

## Repository Content

**. data/_custom_noise:** - it contains the custom motor noise datas.This is the noise produced by motor when it is in driving mode and is collected using mobile phone.
**. images/** - a few images related to the project.
**. models/** - all the trained models for differents experiments performed.
**. src/** - contains the scripts written in the Arduino IDE to support the project.  

## Data Collection and Processing
We used the Google Speech Commands dataset which has 65,000 one-second long utterances of sets of thirty short words. This was obtained from the link [here](http://download.tensorflow.org/data/speech_commands_v0.02.tar.gz). 
In additon to these samples, we have also collected some custom backgrond noise of the the robot using mobile phone. This can be found in the sample data folder in our repository.

The source code and the instruction of data curation can be found in the link [here](https://github.com/memanish008/ei-keyword-spotting).

## Feature extraction
It is the process of identifying those components from audio signals that are good in identifying the linguistic content discarding the unnecessary factors like noise. Audio MFCC fature extraction is suited for the human voice.

## Trained  models 
The trained model is stored in.zip file. All these files can found in the trained model folder in our repository. 

## Deployment of the model
Before uploading the build model on the robot, we add some scripts to the model sketch to control the robot. This includes catching the target voice command predicted by the model and 
then defining its function to control the robot. This final script can be found in the trained model folder.

## Experiments 
A series of experiments were performed using differnt neural architecture to obtain the best model for speech recognition. All the models are deployed on the robot to check the performance.

## Videos  
The videos of the testing the Kørsel robot performance on the track line using different trained models are available in the Google Drive link [here](https://drive.google.com/drive/folders/1pUV_IysSdNKn0U_R8hXAS0FiaRnUzW44?usp=sharing).
