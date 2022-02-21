#include <Arduino.h>

#include <PositionalStepper.h>
#include <ISR_Timer.h>
#include <LedController.h>
#include <Logger.h>
#include <ValueSweep.h>
#include <SoftwareSerial.h>
#include <ConverterBuffer.h>

ISR_Timer main_timers;

ValueSweep<0, 180> azimuth_sweeper{90, 5};
ValueSweep<0, 180> elevation_sweeper{90, 5};

PositionalStepper azimuth_motor{2038, 7, 6, 5, 4};
PositionalStepper elevation_motor{2038, 11, 10, 9, 8};

LedController status_led{LED_BUILTIN};

SoftwareSerial transmitter(3, 2);

ConverterBuffer converter{2};

void test_next() {

    auto azimuth = azimuth_sweeper.Next();
    auto elevation = elevation_sweeper.Next();

    converter.SetValue(azimuth);
    transmitter.write(converter.GetData(), converter.Size());

    converter.SetValue(elevation);
    transmitter.write(converter.GetData(), converter.Size());

    converter.SetValue(analogRead(0));
    transmitter.write(converter.GetData(), converter.Size());
    transmitter.flush();

    status_led.blink();
}

void setup() {
    Logger::Start(9600);
    transmitter.begin(9600);

    main_timers.init();
    status_led.init();

//    elevation_motor.SetSpeed(5);
//    azimuth_motor.SetSpeed(5);

    // timers
    main_timers.setInterval(1000, test_next);
}

void loop() {
    main_timers.run();
}
