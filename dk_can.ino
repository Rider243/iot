#include <SoftwareSerial.h> // giúp mình tạo 1 cổng uart mềm
const byte RX = 19;
const byte TX = 18;
SoftwareSerial mySerial = SoftwareSerial(RX, TX);


#define BRAKE 24
#define CW    25
#define CCW   26
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").
#define MOTOR_1 20
#define MOTOR_2 21
#define LEFT 22
#define RIGHT 23



#define encoder  2



//MOTOR 1
#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8

//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9

#define PWM_MOTOR_1 5
#define PWM_MOTOR_2 6

#define PWM_PUMP 10
#define EN_PIN_1 A0


short usSpeed = 150;  //default motor speed
unsigned short usMotor_Status = BRAKE;


#define in1rl 11
#define in2rr 12
#define in3ru 13
#define in4rd 14
#define pump1 15
#define pump2 16




//uint8_t CW ;
//uint8_t CCW ;
//uint8_t MOTOR_1 ;
//uint8_t MOTOR_2 ;
//uint8_t LEFT ;
//uint8_t RIGHT ;
//uint8_t BRAKE ;
//uint8_t PUMPSP ;
//uint8_t BRAKEPUMP ;
//short usSpeed = 150;  //default motor speed
//unsigned short usMotor_Status = BRAKE;



void setup() 
{
   mySerial.begin(9600);
   Serial.begin(9600);
   
   pinMode(in1rl, OUTPUT);
   pinMode(in1rl, OUTPUT);
   
   pinMode(in3ru, OUTPUT);
   pinMode(in4rd, OUTPUT);

   pinMode(pump1, OUTPUT);
   pinMode(pump2, OUTPUT);
 
   pinMode(MOTOR_A1_PIN, OUTPUT);
   pinMode(MOTOR_B1_PIN, OUTPUT);
 
   pinMode(MOTOR_A2_PIN, OUTPUT);
   pinMode(MOTOR_B2_PIN, OUTPUT);

   pinMode(PWM_MOTOR_1, OUTPUT);
   pinMode(PWM_MOTOR_2, OUTPUT);

   pinMode(PWM_PUMP, OUTPUT);
   pinMode(EN_PIN_1, OUTPUT);

   digitalWrite(PWM_PUMP, HIGH);
   digitalWrite(EN_PIN_1, HIGH);
   
   



   

   
} 

 void loop() 
{
  char user_input;   
  while(Serial.available())
  {
    user_input = Serial.read();  

       if (user_input =='1')
    {
       Forward();;
    }
    else if(user_input =='2')
    {
      Reverse();
    }
        else if(user_input =='3')
    {
      Turnleft();
    }
        else if(user_input =='4')
    {
      Turnright();
    } 
    if (user_input =='5')
    {
       Stop();
    }
    else if(user_input =='6')
    {
      Rollleft();
    }
        else if(user_input =='7')
    {
      Rollright();
    }
        else if(user_input =='8')
    {
      Rollup();
    }   
    else if(user_input =='9')
    {
      Rolldown();
    } 

    else if(user_input =='a')
    {
      Pump();
    } 

    else if(user_input =='b')
    {
      StopPump();
    } 
    
     else if(user_input =='+')
    {
      IncreaseSpeed();
    }
    else if(user_input =='-')
    {
      DecreaseSpeed();
    }  
  }
}  

 void Pump()
 {
   digitalWrite(pump1, HIGH);
   digitalWrite(pump2, LOW);
   Serial.println("DANG PHUN ");
 }

  void StopPump()
 {
   digitalWrite(pump1, LOW);
   digitalWrite(pump2, LOW);
   Serial.println("DUNG PHUN ");
 }


void Rollleft() 
{

   digitalWrite(in1rl, HIGH);
   digitalWrite(in2rr, LOW);
   Serial.println("QUAY TRAI ");
 
   delay(100); 
   digitalWrite(in1rl, LOW);  
} 

void Rollright() 
{

   digitalWrite(in1rl, LOW);
   digitalWrite(in2rr, HIGH);
   Serial.println("QUAY PHAI ");
 
   delay(100); 
   digitalWrite(in1rl, LOW);
    digitalWrite(in2rr, LOW);
  
} 

void Rollup() 
{

   //digitalWrite(in3ru, HIGH);
   analogWrite(in3ru, 125);
   digitalWrite(in4rd, LOW);
   Serial.println("QUAY LEN ");
   delay(75); 
   digitalWrite(in3ru, LOW); 
   digitalWrite(in4rd, LOW);
} 

void Rolldown() 
{

   //digitalWrite(in4rd, HIGH);
   analogWrite(in4rd, 150);
   digitalWrite(in3ru, LOW);
   Serial.println("QUAY XUONG ");
   delay(75); 
   digitalWrite(in4rd, LOW);  
    digitalWrite(in3ru, LOW) ;
} 

void Stop()
{
  
  usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);
  Serial.println("DUNG LAi ");
}

void Forward()
{
;
  usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  Serial.println("DI TOI ");
}

void Reverse()
{
  
  usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  Serial.println("DI LUI ");
}

void Turnleft()
{
  
  usMotor_Status = LEFT;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  Serial.println("QUA TRAI ");
}
void Turnright()
{
  
  usMotor_Status = RIGHT;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  Serial.println("QUA PHAI ");
}

void IncreaseSpeed()
{
  usSpeed = usSpeed + 10;
  if(usSpeed > 255)
  {
    usSpeed = 255;  
  }
  

  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);  
  Serial.println("TANG TOC ");
}

void DecreaseSpeed()
{
  usSpeed = usSpeed - 10;
  if(usSpeed < 0)
  {
    usSpeed = 0;  
  }
  
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);  
  Serial.println("GIAM TOC ");
}


void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }


     else if(direct == LEFT)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW); 
    }
    else if(direct == RIGHT)
    {
       
         digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);    
    }

        else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_1, pwm); 
  }
  else if(motor == MOTOR_2)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);  
          
    }
    else if(direct == LEFT)
    {
      
       digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW); 
          
    }
    else if(direct == RIGHT)
    {
         
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);   
    }
    else
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    }

    
      analogWrite(PWM_MOTOR_1, pwm);
    analogWrite(PWM_MOTOR_2, pwm);
  }
}









  
