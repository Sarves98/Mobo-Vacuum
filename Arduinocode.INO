#include <SoftwareSerial.h>

#define M1A 5
#define M1B 9

#define M2A 4
#define M2B 10



SoftwareSerial BT(3,2);

void fw();
void bw();
void left();
void right();
void stop();
void led();
const int ledPin =  LED_BUILTIN;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;
void setup() {
TCCR1B = (TCCR1B & 0b11111000) | 0x04;
BT.begin(9600);
Serial.begin(9600);
pinMode(M1A,OUTPUT);
pinMode(M1B,OUTPUT);
pinMode(M2A,OUTPUT);
pinMode(M2B,OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
if(BT.available()){
char input = BT.read();
Serial.println(input);
switch (input){
case '1':
fw();
break;
case '2':
bw();
break;
case '3':
left();
break;
case '4':
right();
break;
case '5':
{
unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval)
{
previousMillis = currentMillis;
if (ledState == LOW)
{
ledState = HIGH;
}
else
{
ledState = LOW;
}
}
break;
}
case '0':
stop();
break;
}
}
}

void bw(){
digitalWrite(M1A,0);
analogWrite(M1B,255);

digitalWrite(M2A,0);
analogWrite(M2B,255);
}


void fw(){
digitalWrite(M1A,1);
analogWrite(M1B,255);

digitalWrite(M2A,1);
analogWrite(M2B,255);
}

void left(){
digitalWrite(M1A,1);
analogWrite(M1B,200);

digitalWrite(M2A,0);
analogWrite(M2B,180);
}

void right(){
digitalWrite(M1A,1);
analogWrite(M1B,180);

digitalWrite(M2A,0);
analogWrite(M2B,200);
}
void led()
{
digitalWrite(LED_BUILTIN, ledState);

}

void stop()
{
digitalWrite(M1A,0);
analogWrite(M1B,0);
digitalWrite(M2A,0);
analogWrite(M2B,0);
}
