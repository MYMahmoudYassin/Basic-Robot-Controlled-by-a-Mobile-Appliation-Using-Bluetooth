//-------------------------------ANDROID CONTROLLED ROBOT------------------------------
//---------------------------------written by Mahmoud Yassin--------------------------------

// Successfully Tested on Android App --> 'Arduino Bluetooth 
// Terminal'; it is available free on the Google Play Store
//int enA = 3;
int in1 = 12;
int in2 = 11;
// motor two
//int enB = 6;
int in3 = 10;
int in4 = 9;



int state;
int flag=0;
void stp();
void fwd();
void left();
void right();
void back(); 
void setup()
{
// pinMode(enA, OUTPUT);
 //pinMode(enB, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT); 
 
Serial.begin(9600);                                         // Baud rate set to 9600bps
}
void loop() {
    if(Serial.available() > 0)      // Ckeck for command Recieved
    {    
      state = Serial.read();
      Serial.println(state);  
      flag=0;
    }  
    if (state == 1)     // Checking Command from User
    {
        stp();
        if(flag == 0){
          Serial.println("Stop");
          flag=1;
       }
    }
    else if (state == 2)
    {
        fwd();
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
    }
    else if (state == 3)
    {
        back();
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
    }
    else if (state == 4)
    {
        left();
        if(flag == 0)
        {
          Serial.println("Left");
          flag=1;
         }
    }
   else if (state == 5)
  {
        right();
        if(flag == 0)
        {
          Serial.println("Right");
          flag=1;
         }
  }
  
 
    
}                                           //loop() ends here
void fwd()          // Forward
{
 //Go forward function
 // turn on motor A
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 // set speed to 150 out of possible range 0~255
// analogWrite(enA, 90);
 // turn on motor B
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 // set speed to150 out of possible range 0~255
 //analogWrite(enB, 90);
}

void back()          // Backward
{
  //Go backward function
 // turn on motor A
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 // set speed to 150 out of possible range 0~255
 //analogWrite(enA,120);
 // turn on motor B
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 // set speed to150 out of possible range 0~255
 //analogWrite(enB,120);
  }

void left()          //LEFT
{
 //Go left function
 // turn on motor A
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH); 
 // set speed to 150 out of possible range 0~255
 //analogWrite(enA,150);
 // turn off motor B
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 //analogWrite(enB, 150);
}
void right()          // Right
{ //Go right function
 // turn on motor A
 digitalWrite(in1, HIGH);
 digitalWrite(in2,LOW);
 // set speed to 150 out of possible range 0~255
 //analogWrite(enA, 150);
 // turn off motor B
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
// analogWrite(enB,150);
 }
 
void stp()            // Robot STops
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
