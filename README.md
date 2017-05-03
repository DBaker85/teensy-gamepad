# Teensy Gamepad 1.0
---
##### Background

This is based on [sotasystems'](http://www.sudomod.com/forum/memberlist.php?mode=viewprofile&u=2440&sid=29745351306eb34fdc192d75ff3a6ed7) excellent code for turning a Leonardo pro micro controller into a gamepad for his [PiBoy](http://sudomod.com/forum/viewtopic.php?f=9&t=1615) project.
The teensy allows me to have some cooler functions, even if a teensy is a little overkill for this use case.

Features include :
- Joystick autocalibration from Sota's code (Just rotate the joysticks 360 degrees a couple of times and they are calibrated)
- Neopixel status led

---
##### Required Hardware and Software

- [Teensy 3.x](https://www.pjrc.com/store/teensy32.html) (This code was developed exclusively on a Teensy 3.2)
- Momentary or press switches to act as buttons
- [Arduino IDE](https://www.arduino.cc/en/Main/Software) 1.8.x
- [teensyduino](https://www.pjrc.com/teensy/teensyduino.html) add on for arduino IDE

---
##### Optional Hardware and Software

- One or two Analog Joysticks (I used 2 of [these](https://www.adafruit.com/product/444))

---
##### Dependencies

- [Bounce](https://www.pjrc.com/teensy/td_libs_Bounce.html) library (Comes with teensyduino)

---
##### Led feature requirement

This feature is heavily dependent on other hardware and scripts
- Adafruit [Neopixel](https://github.com/adafruit/Adafruit_NeoPixel) library (Comes with teensyduino)
- [Adafruit neoPixel](https://learn.adafruit.com/adafruit-neopixel-uberguide) (I used a single 5mm through hole version);
- [Powerboost 1000c](https://learn.adafruit.com/adafruit-powerboost-1000c-load-share-usb-charge-boost/overview) with safe shutdown switch;
- Safe Shutdown PCB (PowerBoost Edition)
- [Safe shutdown script] based off Camble's (power monitor)[https://github.com/Camble/GBZ-Power-Monitor_PB] script;

---
##### Installation

// TODO


Links
-----
The original code can be found on this thread:
http://www.sudomod.com/forum/viewtopic.php?f=22&t=1766
