#include <OneWire.h>
#include <DallasTemperature.h>
#include "Config.h"

OneWire ow(tempSensorPin);
DallasTemperature tempSensors(&ow);
byte fanPWM = 255;

void setup() {
  Serial.begin(9600);
  tempSensors.begin();
}

void loop() {
  /* Get temperature: */
  tempSensors.requestTemperatures();
  float temp = tempSensors.getTempCByIndex(0);

  /* Calculate target fan PWM value: */
  byte targetPWM = 0;
  if (temp < errTemp) {
    /* Error. */
    targetPWM = maxPWM;
  } else if (temp < minTemp) {
    /* Below the minimum temperature. */
    targetPWM = 0;
  } else if (temp > maxTemp) {
    /* Above the maximum temperature. */
    targetPWM = maxPWM;
  } else {
    /* Somewhere in between. */
    targetPWM = round((temp - minTemp) * (maxPWM - minPWM) / (maxTemp - minTemp) + minPWM);
  }

  /* Approach target PWM: */
  if (targetPWM < fanPWM) {
    /* Current PWM value is higher than our target. */
    if ((fanPWM - targetPWM) > minPWMFastApproach) {
      /* The difference is high, directly go to target. */
      fanPWM = targetPWM;
    } else {
      /* The difference is low, slowly approach it. */
      fanPWM -= maxPWMChange;
    }
  } else if (targetPWM > fanPWM) {
    /* Current PWM value is lower than our target. */
    if ((targetPWM - fanPWM) > minPWMFastApproach) {
      /* The difference is high, directly go to target. */
      fanPWM = targetPWM;
    } else {
      /* The difference is low, slowly approach it. */
      fanPWM += maxPWMChange;
    }
  }

  /* Set fan PWM: */
  analogWrite(fanPWMPin, fanPWM);

  /* Send debug message: */
  Serial.print(temp);
  Serial.print(F(", "));
  Serial.println(fanPWM);

  /* Wait a moment: */
  delay(interval);
}
