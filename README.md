# Wild-Bird-RGB-LEDs-for-Wemos-D1-ESP8266
Wild-Bird RGB LED idea is to be attached to a drone or bike for entertainment purposes.
Uses 2 Tilt sensors to reset the module or the cycle and extend delay before going to deep-sleep mode.
First Tilt sensor is connected between D6 (GPIO12) and GND with a Pull-up resistor of 10KOhm.
Second Tilt sensor is bridged between RST and D0 (GPIO16) which keep it in sleep-mode until the device is in motion. 
(Tilt sensor do not wake-up the module if battery is low)


![Image](https://user-images.githubusercontent.com/131245523/236570260-f4b95e72-514d-4d54-829c-df9f27f373b4.jpg)
![Image](https://user-images.githubusercontent.com/131245523/236570261-92d7048e-ccc7-46fa-afbf-8b254e5b2894.jpg)
![Image](https://user-images.githubusercontent.com/131245523/236570262-4dde6169-2eb6-49f9-8afa-c187861e00f0.jpg)
![Image](https://user-images.githubusercontent.com/131245523/236570263-80a3f6ac-aa7c-4fe9-bc75-d8ba493e45ef.jpg)
![Image](https://user-images.githubusercontent.com/131245523/236570264-84236025-799f-417b-a7f3-d9d2d1856b63.jpg)


Battery monitoring part are originally written by: Usman Ali Butt (https://www.engineersgarage.com/nodemcu-battery-voltage-monitor/)
Interrupt Code part (https://lastminuteengineers.com/handling-esp8266-gpio-interrupts-tutorial/)
PWM Code part are originally written by: Rui Santos (https://randomnerdtutorials.com/esp8266-pwm-arduino-ide/)
