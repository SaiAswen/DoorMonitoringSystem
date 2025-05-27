#include "Wire.h"
#include <stdint.h>  // for uint8_t

// Door sensor input pins
const int doorSensorPins[4] = {2, 3, 4, 5};
bool doorOpenFlags[4] = {false};

const int MODE_OFF = 0;
const int MODE_AUTO = 1;
const int MODE_ALWAYS_ON = 2;

// Output pins
const int lightPin = 10;
const int ledGreenPin = 11;
const int ledRedPin = 12;

int roofSwitchMode = MODE_AUTO;

void initializeHardware()
{
  for (int i = 0; i < 4; i++)
    {
    pinMode(doorSensorPins[i], INPUT_PULLUP);
    }
  pinMode(lightPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);

  Wire.begin();
  Serial.begin(9600);
}

void updateRoofMode()
{
  int sensorValue = analogRead(A0);
  if (sensorValue < 341)
    {
    roofSwitchMode = MODE_OFF;
    }
  else if (sensorValue < 682)
    {
    roofSwitchMode = MODE_AUTO;
    }
  else
    {
    roofSwitchMode = MODE_ALWAYS_ON;
    }
}

void detectDoorStatus()
{
  for (int i = 0; i < 4; i++)
    {
    doorOpenFlags[i] = (digitalRead(doorSensorPins[i]) == LOW);  // Active low sensor
    }
}

int anyDoorOpen()
{
  for (int i = 0; i < 4; i++)
    {
    if (doorOpenFlags[i] == 1)
        {
        return 1;
        }
    }
  return 0;
}


void showStatusLEDs()
{
  if (anyDoorOpen())
    {
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    }
  else
    {
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledGreenPin, HIGH);
    }
}

void controlInteriorLight()
{
  switch (roofSwitchMode)
  {
    case MODE_OFF:
      digitalWrite(lightPin, LOW);
      break;
    case MODE_ALWAYS_ON:
      digitalWrite(lightPin, HIGH);
      break;
    case MODE_AUTO:
      digitalWrite(lightPin, anyDoorOpen() ? HIGH : LOW);
      break;
  }
}

uint8_t prepareDoorStatus()
{
  uint8_t statusByte = 0;
  for (int i = 0; i < 4; i++)
    {
    if (doorOpenFlags[i])
    {
      statusByte |= (1 << i);
    }
  }
  return statusByte;
}

void sendStatusOverI2C()
{
  uint8_t doorStatus = prepareDoorStatus();
  Wire.beginTransmission(0x08);
  Wire.write(doorStatus);
  Wire.endTransmission();
}

void setup()
{
  initializeHardware();
}

void loop()
{
  updateRoofMode();
  detectDoorStatus();
  showStatusLEDs();
  controlInteriorLight();
  sendStatusOverI2C();

  delay(500);
}
