/*
 * 28BYJ48电机的步进角是5.625度，内部存在减速装置减速比是1:64，也就是说给28BYJ48发送一个脉冲信号电机旋转(5.625/64)度，电机旋转一圈360度需要360/(5.635/64)=4096个脉冲信号。
 * 接线方式：
 *   IN1 -- PIN8    |    OUT1 -- 橙色线
 *   IN2 -- PIN9    |    OUT2 -- 黄色线
 *   IN3 -- PIN10   |    OUT3 -- 粉色线
 *   IN4 -- PIN11   |    OUT4 -- 蓝色线
 *                  |    5V   -- 红色线
*/

#include <EEPROM.h>
#include "Stepper28BYJ48.h"

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
int readValueL = 0; 
int readValueH = 0;
int value = 0;
int dir = 0;
int resteStep = 0;

MyStepper myStepper(4096, 8, 9, 10, 11);
void setup() {
  /* put your setup code here, to run once */
  Serial.begin(9600);

  dir = EEPROM.read(address++);
  readValueL = EEPROM.read(address++);
  readValueH = EEPROM.read(address);

  value = (readValueH << 8) + readValueL;
  Serial.println(value);
  Serial.println(dir);

  //resteStep = 2048 - value;
  if (value > 1) {
    if (dir == 1) {
      myStepper.step(value);
    }
    else {
      myStepper.step(-value);
    }
  }
  myStepper.setSpeed(10);
}
void loop() {
  /* put your main code here, to run repeatedly */
  int a = 0;
  char steper = 64;
  myStepper.step(2048);
  delay(1000);
  myStepper.step(-2048);
  delay(1000);
}
