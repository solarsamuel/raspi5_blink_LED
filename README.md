# raspi5_blink_LED
Blink LED's using Raspberry Pi 5 GPIO
1. Download the code (C files)
2. In terminal run: sudo apt-get install libgpiod2 libgpiod-dev
3. Compile in terminal: gcc blink_25.c -o blink_25 -lgpiod
4. Run the code in terminal: ./blink_25

The LED goes through a 220 ohm resistor, which terminates to ground.

Useful links:
VIDEO: 
Pi pinout: https://vilros.com/pages/raspberry-pi-5-pinout
Adafruit libgpiod: https://adafruit-playground.com/u/MakerMelissa/pages/comparing-libgpiod-and-gpiozero-speeds-on-the-raspberry-pi-5
How it used to be done on older Raspberry Pi: https://forums.raspberrypi.com/viewtopic.php?t=99113
