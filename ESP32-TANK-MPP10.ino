#include <ESP32_Servo.h>

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#define PWM1 25
#define AIN1 14  
#define AIN2 12 //LED2
#include <analogWrite.h>

#define PWM2 26
#define BIN1  7
#define BIN2 13 //LED1
#define EN1 14
#define EN2 27

Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("JT");       //set bluetooth name of your device
  pinMode(BIN1,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN2,OUTPUT);
  
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
   
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);

  servo1.attach(15);
  servo2.attach(33);
  servo3.attach(32);

}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    digitalWrite(EN1,LOW);
    digitalWrite(EN2,LOW);
  
 
    analogWrite(PWM1,120); //Speed control of Motor A
    analogWrite(PWM2,120); //Speed control of Motor B

    delay(2500);
    analogWrite(PWM1,0); //Speed control of Motor A
    analogWrite(PWM2,0); //Speed control of Motor B
    
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,HIGH);
  
    
    analogWrite(PWM1,0); //Speed control of Motor A
    analogWrite(PWM2,0); //Speed control of Motor B
   
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,LOW);
  
 //   digitalWrite(BIN1,HIGH);
    
  
   // digitalWrite(AIN1,HIGH);

    analogWrite(PWM1,100); //Speed control of Motor A
    analogWrite(PWM2,100); //Speed control of Motor B
        delay(500); 
  
    
    analogWrite(PWM1,100); //Speed control of Motor A
    analogWrite(PWM2,50); //Speed control of Motor B
   
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,HIGH);
  
//    digitalWrite(BIN1,HIGH);

  
  //  digitalWrite(AIN1,LOW);

    analogWrite(PWM1,50); //Speed control of Motor A
    analogWrite(PWM2,100); //Speed control of Motor B
    delay(1500); 
  
    
    analogWrite(PWM1,0); //Speed control of Motor A
    analogWrite(PWM2,0); //Speed control of Motor B
   
  }

  if (GamePad.isSquarePressed())
  {
        digitalWrite(EN1,LOW);
    digitalWrite(EN2,LOW);
  
    
    analogWrite(PWM1,0); //Speed control of Motor A
    analogWrite(PWM2,0); //Speed control of Motor B
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
      digitalWrite(BIN2,HIGH);
      digitalWrite(AIN2,HIGH);
      servo3.write(120);
      }
  else {
     digitalWrite(BIN2,LOW);
      digitalWrite(AIN2,LOW);
      servo3.write(0);
  }
  

  if (GamePad.isCrossPressed())
  {
    {
     servo2.write(70);

    servo2.write(0);
    delay(100);
    servo2.write(100);
    servo2.write(0);
    delay(700);
    servo2.write(10);
    
   servo2.write(130);
    delay(1000);
    servo1.write(0);
   }
   }

  if (GamePad.isTrianglePressed())
  {
    servo2.write(90);
  delay(1000);
  servo2.write(0);
    Serial.print("ARRIBA");
    }
  else {
     servo2.write(90);
 Serial.print("Abajo");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  
  delay(10);
  
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
   servo2.write(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
   
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}
