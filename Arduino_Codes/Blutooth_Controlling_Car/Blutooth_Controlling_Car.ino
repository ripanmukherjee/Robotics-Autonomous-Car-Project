const int ledpin=13;

// Motor A
int enA = 9;
 
// Motor B
int enB = 3;

int leftMotorForward = 5;     /* IN3   */
int rightMotorForward = 8;   /* IN1  */
int leftMotorBackward = 4;    /* IN4   */
int rightMotorBackward = 7;  /* IN2  */

int state=0;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT); 
  pinMode(leftMotorBackward, OUTPUT);  
  pinMode(rightMotorBackward, OUTPUT);
  Serial.begin(9600);
}

void loop() {

// put your main code here, to run repeatedly:
if (Serial.available()>0)
{
  int state= Serial.read();
  if (state=='0')
  {
    digitalWrite(ledpin,LOW);
    Serial.println("LED is OFF");
  }
  if (state=='1')
  {
    digitalWrite(ledpin,HIGH);
    Serial.println("LED is ON");
    Serial.println("You Can Now Drive Your Car");
    Serial.println("2 - Forward");
    Serial.println("3 - Backward");
    Serial.println("4 - Right");
    Serial.println("5 - Left");
    Serial.println("6 - Stop");
  }
  if (state=='2')//move forward(all motors rotate in forward direction)
  {            
    Serial.println("Moving Forward");
    digitalWrite(enB,HIGH);
    digitalWrite(enA,HIGH);
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,HIGH);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorBackward,LOW);
  }
  if (state=='3') //move reverse (all motors rotate in reverse direction)
  {     
    Serial.println("Moving Backward");
    digitalWrite(enB,HIGH);
    digitalWrite(enA,HIGH);
    digitalWrite(leftMotorBackward,HIGH);
    digitalWrite(rightMotorBackward,HIGH);
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(rightMotorForward,LOW);
  }
  if (state=='4') //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  {      
    Serial.println("Moving Right");
    digitalWrite(enB,HIGH);
    digitalWrite(enA,HIGH); 
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(rightMotorForward,HIGH);
    digitalWrite(rightMotorBackward,LOW);
    digitalWrite(leftMotorBackward,HIGH); 
  }
  if (state=='5') //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  {      
    Serial.println("Moving Left");
    digitalWrite(enB,HIGH);
    digitalWrite(enA,HIGH);
    digitalWrite(leftMotorForward,HIGH);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(rightMotorBackward,HIGH);
    digitalWrite(leftMotorBackward,LOW);
  }
  if (state=='6') //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  {      
    Serial.println("Stopping");
    digitalWrite(enB,LOW);
    digitalWrite(enA,LOW);
    digitalWrite(leftMotorForward,LOW);
    digitalWrite(leftMotorBackward,LOW);
    digitalWrite(rightMotorForward,LOW);
    digitalWrite(rightMotorBackward,LOW);
  }
}
delay(1000);
}