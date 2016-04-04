#include "ksbit.h"

enum class DigitalPin {
    P0 = MICROBIT_ID_IO_P0,
    P1 = MICROBIT_ID_IO_P1,
    P2 = MICROBIT_ID_IO_P2,
    P3 = MICROBIT_ID_IO_P3,
    P4 = MICROBIT_ID_IO_P4,
    P5 = MICROBIT_ID_IO_P5,
    P6 = MICROBIT_ID_IO_P6,
    P7 = MICROBIT_ID_IO_P7,
    P8 = MICROBIT_ID_IO_P8,
    P9 = MICROBIT_ID_IO_P9,
    P10 = MICROBIT_ID_IO_P10,
    P11 = MICROBIT_ID_IO_P11,
    P12 = MICROBIT_ID_IO_P12,
    P13 = MICROBIT_ID_IO_P13,
    P14 = MICROBIT_ID_IO_P14,
    P15 = MICROBIT_ID_IO_P15,
    P16 = MICROBIT_ID_IO_P16,
    P19 = MICROBIT_ID_IO_P19,
    P20 = MICROBIT_ID_IO_P20,
};

enum class AnalogPin {
    P0 = MICROBIT_ID_IO_P0,
    P1 = MICROBIT_ID_IO_P1,
    P2 = MICROBIT_ID_IO_P2,
    P3 = MICROBIT_ID_IO_P3,
    P4 = MICROBIT_ID_IO_P4,
    P10 = MICROBIT_ID_IO_P10,
};

MicroBitPin *getPin(int id) {
    switch (id) {
        case MICROBIT_ID_IO_P0: return &uBit.io.P0;
        case MICROBIT_ID_IO_P1: return &uBit.io.P1;
        case MICROBIT_ID_IO_P2: return &uBit.io.P2;
        case MICROBIT_ID_IO_P3: return &uBit.io.P3;
        case MICROBIT_ID_IO_P4: return &uBit.io.P4;
        case MICROBIT_ID_IO_P5: return &uBit.io.P5;
        case MICROBIT_ID_IO_P6: return &uBit.io.P6;
        case MICROBIT_ID_IO_P7: return &uBit.io.P7;
        case MICROBIT_ID_IO_P8: return &uBit.io.P8;
        case MICROBIT_ID_IO_P9: return &uBit.io.P9;
        case MICROBIT_ID_IO_P10: return &uBit.io.P10;
        case MICROBIT_ID_IO_P11: return &uBit.io.P11;
        case MICROBIT_ID_IO_P12: return &uBit.io.P12;
        case MICROBIT_ID_IO_P13: return &uBit.io.P13;
        case MICROBIT_ID_IO_P14: return &uBit.io.P14;
        case MICROBIT_ID_IO_P15: return &uBit.io.P15;
        case MICROBIT_ID_IO_P16: return &uBit.io.P16;
        case MICROBIT_ID_IO_P19: return &uBit.io.P19;
        case MICROBIT_ID_IO_P20: return &uBit.io.P20;
        default: return NULL;
    }
}


//% color=351 weight=30
namespace pins {
    #define PINOP(op) \
      MicroBitPin *pin = getPin((int)name); \
      if (!pin) return; \
      pin->op

    #define PINREAD(op) \
      MicroBitPin *pin = getPin((int)name); \
      if (!pin) return 0; \
      return pin->op


    //%
    MicroBitPin *getPinAddress(int id) {
        return getPin(id);
    }


    /**
     * Read the specified pin or connector as either 0 or 1
     * @param name pin to read from
     */
    //% help=pins/digital-read-pin weight=30
    //% blockId=device_get_digital_pin block="digital read|pin %name" blockGap=8
    int digitalReadPin(DigitalPin name) {
        PINREAD(getDigitalValue());
    }

    /**
      * Set a pin or connector value to either 0 or 1.
      * @param name pin to write to
      * @param value value to set on the pin, 1 eg,0
      */
    //% help=pins/digital-write-pin weight=29
    //% blockId=device_set_digital_pin block="digital write|pin %name|to %value"
    void digitalWritePin(DigitalPin name, int value) { 
        PINOP(setDigitalValue(value));
    }

    /**
     * Read the connector value as analog, that is, as a value comprised between 0 and 1023.
     * @param name pin to write to
     */
    //% help=pins/analog-read-pin weight=25
    //% blockId=device_get_analog_pin block="analog read|pin %name" blockGap="8" 
    int analogReadPin(AnalogPin name) {
        PINREAD(getAnalogValue());
    }

    /**
     * Set the connector value as analog. Value must be comprised between 0 and 1023.
     * @param name pin name to write to
     * @param value value to write to the pin between ``0`` and ``1023``. eg:1023,0
     */
    //% help=pins/analog-write-pin weight=24
    //% blockId=device_set_analog_pin block="analog write|pin %name|to %value" blockGap=8
    void analogWritePin(AnalogPin name, int value) { 
        PINOP(setAnalogValue(value));
    }

    /**
     * Configures the Pulse-width modulation (PWM) of the analog output to the given value in **microseconds** or `1/1000` milliseconds.
     * If this pin is not configured as an analog output (using `analog write pin`), the operation has no effect.
     * @param name analog pin to set period to
     * @param micros period in micro seconds. eg:20000
     */
    //% help=pins/analog-set-period weight=23
    //% blockId=device_set_analog_period block="analog set period|pin %pin|to (µs)%micros" 
    void analogSetPeriod(AnalogPin name, int micros) { 
        PINOP(setAnalogPeriodUs(micros));
    }

    /**
     * Writes a value to the servo, controlling the shaft accordingly. On a standard servo, this will set the angle of the shaft (in degrees), moving the shaft to that orientation. On a continuous rotation servo, this will set the speed of the servo (with ``0`` being full-speed in one direction, ``180`` being full speed in the other, and a value near ``90`` being no movement).
     * @param name pin to write to
     * @param value angle or rotation speed, eg:180,90,0
     */
    //% help=pins/servo-write-pin weight=20
    //% blockId=device_set_servo_pin block="servo write|pin %name|to %value" blockGap=8
    void servoWritePin(AnalogPin name, int value) { 
        PINOP(setServoValue(value));
    }

    /**
     * Configures this IO pin as an analog/pwm output, configures the period to be 20 ms, and sets the pulse width, based on the value it is given **microseconds** or `1/1000` milliseconds.
     * @param name pin name
     * @param micros pulse duration in micro seconds, eg:1500
     */
    //% help=pins/serial-set-pulse weight=19
    //% blockId=device_set_servo_pulse block="servo set pulse|pin %value|to (µs) %micros"
    void servoSetPulse(AnalogPin name, int micros) { 
        PINOP(setServoPulseUs(micros));
    }


    MicroBitPin* pitchPin = NULL;

    /**
     * Sets the pin used when using `pins->analog pitch`.
     * @param name TODO
     */
    //% help=pins/analog-set-pitch weight=12
    void analogSetPitchPin(AnalogPin name) { 
      pitchPin = getPin((int)name);
    }

    /**
     * Emits a Pulse-width modulation (PWM) signal to the current pitch pin. Use `analog set pitch pin` to define the pitch pin.
     * @param frequency TODO
     * @param ms TODO
     */
    //% help=pins/analog-pitch weight=14 async
    void analogPitch(int frequency, int ms) { 
      if (pitchPin == NULL) return;
      if (frequency <= 0) {
        pitchPin->setAnalogValue(0);
      } else {
        pitchPin->setAnalogValue(512);
        pitchPin->setAnalogPeriodUs(1000000/frequency);
      }
      
      if (ms > 0) {
          uBit.sleep(ms);
          pitchPin->setAnalogValue(0);
          wait_ms(5);
      }
    }

    /**
     * Create a new zero-initialized buffer.
     * @param size number of bytes in the buffer
     */
    //%
    Buffer createBuffer(int size)
    {
        return ManagedBuffer(size).leakData();
    }
    
    // TODO:
    void i2cReadBuffer(int address, RefBuffer *buf)
    {
      uBit.i2c.read(address << 1, buf->cptr(), buf->size());
    }

    void i2cWriteBuffer(int address, RefBuffer *buf)
    {
      uBit.i2c.write(address << 1, buf->cptr(), buf->size());
    }

    int i2cReadRaw(int address, char *data, int length, int repeated)
    {
      return uBit.i2c.read(address, data, length, repeated);
    }

    int i2cWriteRaw(int address, const char *data, int length, int repeated)
    {
      return uBit.i2c.write(address, data, length, repeated);
    }
}
