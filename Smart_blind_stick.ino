#define ultraSoundSignal_1 8
 #define ultraSoundSignal_2 9
 #define ultraSoundSignal_3 10
 #define vibrator1 11
 #define buzzer 14
 #define led1 12
   
   
     
unsigned long echo = 0;
int x1=0;
int x2=0;
int x3=0;
int y=0;
 unsigned long ultrasoundValue = 0;
void setup()
{
  pinMode(led1,OUTPUT);
  Serial.begin(9600);    //start Serial communication
 
 

pinMode(ultraSoundSignal_1,OUTPUT);   //set ultrasonic pins as output
pinMode(ultraSoundSignal_2,OUTPUT);
pinMode(ultraSoundSignal_3,OUTPUT);


pinMode(vibrator1,OUTPUT);
pinMode(buzzer,OUTPUT);
   
     
  
}

void loop()
{                                                                                            
  int value=analogRead(A1);
  //Serial.println(value);
  //Serial.println("  ");
  if(value<250)
  {
    digitalWrite(led1,1);
  }
  else
  {
    digitalWrite(led1,0);
  }

   int water=analogRead(A2);
     Serial.print("water  ");
     Serial.print(water);
     Serial.print("  ");

     if(water<500)
     {
      digitalWrite(buzzer,1);
      delay(100);
      digitalWrite(buzzer,0);
      delay(100);
      
     }
     
  
  // x1=distance1();
 // Serial.print("   x1=     ");
 // Serial.print(x1);
  
  


   x2=distance2();
  Serial.print("   x2=     ");
  Serial.print(x2);
  
 
   x3=distance3();
  Serial.print("   x3=     ");
  Serial.print(x3);

  

    if(x3>30)    //depth
    {
      digitalWrite(buzzer,1);
      delay(50);
      digitalWrite(buzzer,0);
      delay(50);
      
    }
    

     if(x2<=20)
     {
        digitalWrite(vibrator1,1);
        delay(50);
        digitalWrite(vibrator1,0);
        delay(50);
     }


else if(x2>20)
{
  digitalWrite(vibrator1,0);
}

  delay(10);

}

 unsigned int distance1()
{
 pinMode(ultraSoundSignal_1, OUTPUT); // Switch  pin to output
 digitalWrite(ultraSoundSignal_1, LOW); // Send low pulse
 delayMicroseconds(2); // Wait for 2 microseconds
 digitalWrite(ultraSoundSignal_1, HIGH); // Send high pulse
 delayMicroseconds(5); // Wait for 5 microseconds
 digitalWrite(ultraSoundSignal_1, LOW); // Holdoff
 pinMode(ultraSoundSignal_1, INPUT); // Switch signalpin to input
 digitalWrite(ultraSoundSignal_1, HIGH); // Turn on pullup resistor
  echo = pulseIn(ultraSoundSignal_1, HIGH); //Listen for echo
  ultrasoundValue = echo * 0.034 / 2; //distance
 return ultrasoundValue;
}
unsigned int distance2()
{
 pinMode(ultraSoundSignal_2, OUTPUT); // Switch  pin to output
 digitalWrite(ultraSoundSignal_2, LOW); // Send low pulse
 delayMicroseconds(2); // Wait for 2 microseconds
 digitalWrite(ultraSoundSignal_2, HIGH); // Send high pulse
 delayMicroseconds(5); // Wait for 5 microseconds
 digitalWrite(ultraSoundSignal_2, LOW); // Holdoff
 pinMode(ultraSoundSignal_2, INPUT); // Switch pin to input
 digitalWrite(ultraSoundSignal_2, HIGH); // Turn on pullup resistor
 echo = pulseIn(ultraSoundSignal_2, HIGH); //Listen for echo
 ultrasoundValue = echo * 0.034 / 2; //distance
 return ultrasoundValue;
}
unsigned int distance3()
{
 pinMode(ultraSoundSignal_3, OUTPUT); // Switch pin to output
 digitalWrite(ultraSoundSignal_3, LOW); // Send low pulse
 delayMicroseconds(2); // Wait for 2 microseconds
 digitalWrite(ultraSoundSignal_3, HIGH); // Send high pulse
 delayMicroseconds(5); // Wait for 5 microseconds
 digitalWrite(ultraSoundSignal_3, LOW); // Holdoff
 pinMode(ultraSoundSignal_3, INPUT); // Switch pin to input
 digitalWrite(ultraSoundSignal_3, HIGH); // Turn on pullup resistor
 echo = pulseIn(ultraSoundSignal_3, HIGH); //Listen for echo
 ultrasoundValue = echo * 0.034 / 2; //distance
 return ultrasoundValue;
}
