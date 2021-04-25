# IoT Center Repository

Repositorio de códigos relacionados a Internet of Things 

## Devices

- ESP32
- Arduino
- Raspberry

### ESP32 installing

Step 1.1:  Allow non root user to use tty0 (USB to Serial converter) serial communication with ESP32

`sudo usermod -a -G dialout $USER`
`sudo chmod 666 /dev/ttyS4`

Step 1.2: Install git. By default its installed with ubuntu linux installation

`sudo apt-get install git`

Step 1.3: Get repository for get–pip.py, is a bootstrapping script that enables users to install pip, setup tools, and wheel in Python environments that don’t already have them.

`wget https://bootstrap.pypa.io/get-pip.py`

Step 1.4: Run python get-pip.py

`sudo python get-pip.py`

Step 1.5: Install pySerial is a Python API module to access the serial port. pySerial provides a uniform API across multiple operating systems, including Windows, Linux, and BSD.

`sudo pip install pyserial`

Step 1.6: On terminal go to you Arduino installation directory using cd command

![image](https://circuits4you.com/wp-content/uploads/2018/02/Step1-arduino-ESP32-Installation.png)

Step 1.7: Create directory espressif in arduino-1.8.3/hardware/ folder

`mkdir -p ~/Arduino/hardware/espressif`

Step 1.8: Change directory to espressif

`cd ~/Arduino/hardware/espressif`

Step 1.9: Clone esp32 core from git to esperssif directory

`git clone https://github.com/espressif/arduino-esp32.git esp32`

Step 1.10: After cloning you will find esp32 directory

`cd esp32`

Step 1.11: Update submodules of ESP32

`git submodule update –init –recursive`

Step 1.12: Run following final commands

`cd tools && python get.py`

## Circuit ESP32

![image-circuit](http://xprojetos.net/wp-content/uploads/2019/04/ESP32-DevkitV1_Pinout.jpg)
