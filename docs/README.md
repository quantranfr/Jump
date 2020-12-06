# Measuring jump duration

Here's how the electronic part works:

[![](http://img.youtube.com/vi/hSRXQWLW5NU/0.jpg)](https://youtu.be/hSRXQWLW5NU)

**Material**

* LED matrix module - P10 red 16x32
* Arduino Uno
* Limit switch

**Libraries**

Cf. the `uno` part of [this repository](https://github.com/quantranfr/LEDMatrix).

**Wiring**

Concerning the LED module, cf. the `uno` part of [this repository](https://github.com/quantranfr/LEDMatrix).

Connect the limit switch to the Arduino as below:

```
Arduino
GND  5V
|    |
|    5kohms
|    |
|    -----> D4
|    |
COM  NO
Limit switch     
```

