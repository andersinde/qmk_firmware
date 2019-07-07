Handwired Planck
================

This firmware is for a Handwired Planck using a Teensy 2.0.

## Build log

You'll find the complete build log here:

* [Part 1](http://www.masterzen.fr/2018/12/16/handwired-keyboard-build-log-part-1/)
* [Part 2](http://www.masterzen.fr/2018/12/22/handwired-keyboard-build-log-part-2/)

## Pinout

The following pins are used:

- Columns 1-12 (L -> R): D0, F7, D1, B6, D3, B5, D2, B4, F6, B7, B3, F5
- Rows 1-4 (T -> B): C6, D7, C7, D6 

## Compiling and loading the firmware

To build the firmware, run `make handwired:planck:default`.

To flash the firemware onto the microcontroller, run `make teensy`, and press the reset button.
