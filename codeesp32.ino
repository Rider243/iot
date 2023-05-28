#define BLYNK_TEMPLATE_ID "TMPLO67VjyAT"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "vAw3z5qHlJjcBIJbpb3bL91LQNnFDoKO"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "vAw3z5qHlJjcBIJbpb3bL91LQNnFDoKO";


char ssid[] = "Phi Ho";
char pass[] = "thanhthao123456";

WidgetLED led_connect(V0);

void setup() {
//  pinMode(2,INPUT_PULLUP);
//  pinMode(2, OUTPUT);
//  digitalWrite(2,LOW);
  Serial.begin(9600);
  pinMode(33,OUTPUT);
  digitalWrite(33,HIGH);

  Blynk.begin(auth, ssid, pass);
}
/////////////////////////////////////////////////////////////code động cơ xe
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("1");//Forward
  else
  Serial.write("5");//Stop
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("2");//Reverse
  else
  Serial.write("5");//Stop
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("3");//Turnleft
  else
  Serial.write("5");//Stop
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("4");//Turnright
  else
  {
   delay(200);
  Serial.write("5");
}
}

BLYNK_WRITE(V5)
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("6");//Rollpumpleft
//   else
//  {
//   delay(200);
//  Serial.write("5");
//}
}

BLYNK_WRITE(V6)
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("7");//Rollpumpright
//  else
//  {
//   delay(200);
//  Serial.write("5");
//}
}

BLYNK_WRITE(V7  )
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("8");//Rollpumpup
//   else
//  {
//   delay(200);
//  Serial.write("5");
//}
}
BLYNK_WRITE(V8  )
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("9");//Rollpumpdown
//   else
//  {
//   delay(200);
//  Serial.write("0");
//}
}

BLYNK_WRITE(V9  )
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("+");//IncreaseSpeed
//   else
//  {
//   delay(200);
//  Serial.write("0");
//}
}

BLYNK_WRITE(V10  )
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("-");//DecreaseSpeed
//   else
//  {
//   delay(200);
//  Serial.write("0");
//}
}

BLYNK_WRITE(V11 )
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("a");//Pump
//   else
//  {
//   delay(200);
//  Serial.write("0");
//}
}

BLYNK_WRITE(V12  )
{
  int pinValue = param.asInt();
  if(pinValue == 1) 
  Serial.write("b");//StopPump
//   else
//  {
//   delay(200);
//  Serial.write("0");
//}
}













void loop() {


  int PIN = random(0, 80);
  Blynk.virtualWrite(V3, PIN);
  Blynk.run();
  
//  if(Serial.available()){
//    char data_rcvd = Serial.read();
//    
//    if(data_rcvd == '1') digitalWrite(33,HIGH);
//    if(data_rcvd == '0') digitalWrite(33,LOW);    
//  }
//  
//  if(digitalRead(2) == HIGH){ 
//    Serial.write('0'); 
//  }
//  else {Serial.write('1'); 
//  }
  
}
