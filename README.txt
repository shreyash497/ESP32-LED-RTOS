 ESP32 FreeRTOS Dual LED Blinking Project

This project demonstrates how to use **FreeRTOS tasks** on the ESP32 using **ESP-IDF**.  
Two LEDs blink at different rates using independent tasks running under FreeRTOS.

 Features
- Two independent FreeRTOS tasks  
- Different blinking intervals  
- Task priorities demonstration  
- UART serial log output

 Requirements
- ESP-IDF v5.3.1 or later  
- ESP32 Dev Board  
- Two LEDs + 220Ω resistors  

 Circuit Connection

| LED | ESP32 GPIO | Connection |
|------|-------------|-------------|
| LED1 | GPIO 2 | Other pin → GND |
| LED2 | GPIO 4 | Other pin → GND |


 Build and Flash

```bash
idf.py build
idf.py -p COM9 flash
idf.py -p COM9 monitor
