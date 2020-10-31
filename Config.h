#pragma once

/* Temperature at which the fan should start running (°C): */
const float minTemp = 30;

/* Temperature at which the fan should reach maximum speed (°C): */
const float maxTemp = 45;

/* Temperature below which we assume an error occured, ignore
   the temperature and enable the fan at full speed (°C): */
const float errTemp = 10;

/* Minimum PWM value: */
const byte minPWM = 26;

/* Maximum PWM value: */
const byte maxPWM = 255;

/* Maximum fan PWM change per second for slow approach: */
const byte maxPWMChange = 1;

/* Minimum fan PWM difference for fast approach: */
const byte minPWMFastApproach = 20;

/* Interval between temperature checks (ms): */
const long interval = 1000;

/* Temperature sensor pin: */
const byte tempSensorPin = A4;

/* Fan PWM pin: */
const byte fanPWMPin = 3;
