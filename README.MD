# Winky lights for game cabinet
Just needed somethin' to drive some WS2812s

### Parts
So, the main constraint was to only use parts in my bin-o-junk (and whatever structure that gets 3D printed).  I picked:  
+ Metro Mini Arduino-type board.  It's an ATMega 328p on a small board with a USB-to-serial chip on it.  I ordered a bunch from [Adafruit](https://www.adafruit.com/product/2590) a couple of years back and some left over.
+ some WS2812 addressible LEDs.  Got spools of 'em

### Project layout
There are 3 main directories under the base `metronome` directory:  
+ avr - this contains all of the code for the ATMega chip
  + the base directory has the main.cpp file, a common header, and a python script.  The script is used to determine register setting for timers
  + string - a class for the string of addressible LEDS
  + sys - common files to config the serial port, I/O, fuses, etc.
    + There's a directory under here for the WS2812 library.  That's the only thing I didn't write, it came from Matthias Riegler.  It's a nice simple library that works well.
  + ref - reference material like datasheets and schematic of the proto board

There's also directories `obj` and `bin` created when it's built.  `bin` is where the final hex and other outputs are placed, `obj` is where the object files 
### Tooling
I like to use Linux and Mac OSX for development; I did this one is on OSX.
##### Development
I have never used the Arduino thingy, just never saw the need for it.  I don't like the look of the libraries.  I used Brew to install avr-gcc and avrdude.  For reference, the avr-gcc I used is based on GCC 7.2.0.

Editing is done in MS VS Code; I really like it as an editor.  It is the same look and feel on Mac OSX and Linux, and has a nice selection of plugins available.

There's a `Makefile` that will work for Linux, you may just need to change the first two lines to correctly point to your installation.  Windows people are on their own.

For debugging, I'm using a combination of debug print statements and a logic analyzer (and winky lights).  The print statements are sent out the USB-to-Serial link and can just be read in a serial terminal.

*When building for release, comment out the line that adds -DDEBUG to the CFLAGS.  It'll pull out all of the serial and print stuff, which will cut a large hunk out of the compiled hex file*

### Notes to read if you've only used the Arduino IDE Chingus Thingy
If you're coming from the Arduino IDE... Well; I've never used it because I don't like that kind of simplification of things. It's a good way for people to learn, but they don't necessarily learn the 'real' way things work. If you want to know what's under the hood, there are two pieces of documentation that you absolutely must look at.

The first is the docs for avr libc. The compiler we're going to use as a gnu thing, avr-gcc, but what it really needs to work is a standard 'c' library to link to. One that is made to work on the AVR microcontrollers. The documentation for it is [here](https://www.nongnu.org/avr-libc/user-manual/pages.html). Don't read from start to end, but take a look. You'll see which headers need to be used for which functions and get a good overview of the toolchain.

The next thing is the datasheet for the AVR. Now that Microchip has purchased Atmel, I hope they keep up the good documentation that Atmel had... The nearest I can see with a quick glance is [here](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf). Work your way through the basics and focus on the peripherals. Without the Arduino environment to help you, you'll need to understand how to use the peripherals; how their registers work and such.

*Both of the linked documents above can be found in the `./avr/ref` directory*