int right1 = 11;
int right2 = 10;
int left1 = 6;
int left2 = 9;
int trigPin = 3;
int echoPin = 5;
int mic = A0;
int micvalue = 0;
int type = 0;
void setup()
{
    Serial.begin(9600); 
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(mic,INPUT);
}
void loop(){
    micvalue=analogRead(mic);
    if(analogRead(mic) >= 30 && type == 0){
      type+=1;
      delay(1000);
      } 
          if(analogRead(mic) >= 30 && type == 1){
      type-=1;
      delay(1000);
      } 
    if(type >= 1){
  analogWrite(right1,200);
  analogWrite(left1,200);
 long duration, distance;
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(1000);
 digitalWrite(trigPin, LOW);
 duration=pulseIn(echoPin, HIGH);
 distance =(duration/2)/29.1;


  delay(10);
 if(distance<=30){
       analogWrite(right1,200);
       analogWrite(left1,0);
  delay(3000);
  }
    }
    if(type <= 0){
       analogWrite(right1,0);
       analogWrite(left1,0);
      }
      Serial.println(analogRead(mic));
  Serial.println(type);
}
