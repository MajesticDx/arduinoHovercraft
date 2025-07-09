
#include <Servo.h>
#include <SoftwareSerial.h>

#define BTRX D2
#define BTTX D3

#define servopin D5

#define bdc1pin D9
#define bdc2pin D11
#define UserButton_state  PC13

SoftwareSerial SerialBT(BTRX, BTTX);

Servo ESCg;
Servo ESCh;
Servo servo;

String message;
int kommando;

int valueESCh = 0;
int valueESCg = 0;
int valueservo = 125;

void setup() {
  SerialBT.begin(9600);

  pinMode(bdc1pin, OUTPUT);
  pinMode(bdc2pin, OUTPUT);
  pinMode(servopin, OUTPUT);

  ESCg.attach(bdc1pin, 1000, 2000);
  ESCh.attach(bdc2pin, 1000, 2000);
  servo.attach(servopin);

  attachInterrupt(digitalPinToInterrupt(UserButton_state), isr_EXT_Wurf, FALLING);
  Serial.begin(115200);

  //analogWriteResolution(16);
  //analogWriteFrequency(50);
  
  Serial.println("Ende Setup");
}

void isr_EXT_Wurf(void) {
  
  if (valueESCg == 0) {
    valueESCh = 90;
    valueESCg = 90;
  } else if (valueESCg == 90) {
    valueESCh = 180;
    valueESCg = 180;
  } else {
    valueESCh = 0;
    valueESCg = 0;
  }

}

void loop() {
  Serial.println("value :");
  Serial.println(valueESCg);
  Serial.println(valueESCh);
  Serial.println(valueservo);

  BLE_RX();

  ESCg.write(valueESCg);
  ESCh.write(valueESCh);
  servo.write(valueservo);
  delay(100);
}
