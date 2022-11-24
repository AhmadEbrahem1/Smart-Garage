#include <Servo.h>
Servo myservo;
#define gate 6
#define outgate 5
#define ingate 4
#define ldr A0
#define led 3


 
int places=5; //   numbers of empty places in garage
 
int i=1,o=1;//inside and outside ir sensors ,default case : high when not detecting
 
#define a 7
#define b 8
#define c 9
#define d 10
#define e 11
#define f 12
#define g 13
void setup(){

 Serial.begin(9600);
pinMode(ldr,INPUT);  
pinMode(led,OUTPUT); 
pinMode ( a,OUTPUT); 
pinMode ( b,OUTPUT);
pinMode ( c,OUTPUT);
pinMode ( d,OUTPUT); 
pinMode ( e,OUTPUT); 
pinMode ( f,OUTPUT); 
pinMode ( g,OUTPUT);
pinMode(outgate,INPUT);
pinMode(ingate,INPUT);
myservo.write(90);// initial position of gate
myservo.attach(gate);

o= digitalRead(outgate);
i= digitalRead(ingate);
}
 
 
  void loop(){
 
    int po=o; int  pi=i;//previous versions of outside  and inside ir reading
    int z=analogRead(ldr);
 Serial.println(z);
  if (z<950){ 
                 digitalWrite(led,LOW);}
 
  else 
 
             {
                  digitalWrite(led,HIGH); 
                }
 first:
    o= digitalRead(outgate);
 
     i= digitalRead(ingate);
 
     if ((po==1 &&o==0)||(pi==1 &&i==0)){// to excute code only when ir changes from 1 to 0
 
       if(o==0 &&i==1){// case1: car is entring
 
         if (places>0&& places<=5){
 
                for (int i=90; i>=0;i--){
 
                myservo.write(i);
 
                  delay(50);//open the gate for the car
 
                }
 
                 places =places-1;}
                 else // places =5
                 goto first;
 
                 label1:
 
                 o= digitalRead(outgate);
 
                 i= digitalRead(ingate);
 
      if(i==0&&o==1){   //  it means that car has passed
 
                for (int i=0; i<=90;i++){
 
                 myservo.write(i);
 
                  delay(50); //close the gate
 
                }}
 
         else  // car is still passing
 
             goto label1;}
             
             
 
             
 
        else 
 
          if(o==1&& i==0){ //case car is exiting the garage
            if(places<=5)
 
               for (int i=90; i>=0;i--){
 
                myservo.write(i);
 
                  delay(50);
 
                }
 
          if(places==5)
 
          places =5;
 
             else
 
              places =places+1;
 
         label2:
 
      o= digitalRead(outgate);
 
      i= digitalRead(ingate);
 
       if(i==1&&o==0){   //  it means that car has passed
 
     for (int i=0; i<=90;i++){
 
                myservo.write(i);
 
                  delay(50);
 
                }}
 
         else  goto label2;}
 
    else
 
        if(o==1&& i==1) // no car is entering or leaving
 
             places=places;
 
   else
 
        if(o==0&&i==0) // both ir sensors dedect a car at the same time
 
             places=places; } 
 
             // showing available places on 7 segment:  
 
             if(places==0)
 
              { digitalWrite ( a,HIGH);
 
                digitalWrite ( b,HIGH);
 
                digitalWrite ( g,LOW);
 
                digitalWrite ( e,HIGH);
 
                digitalWrite ( d,HIGH);
 
                digitalWrite ( f,HIGH);
 
                digitalWrite ( c,HIGH);}
 
     if(places==1){
 
                digitalWrite ( a,LOW);
 
                digitalWrite ( b,HIGH);
 
                digitalWrite ( g,LOW);
 
                digitalWrite ( e,LOW);
 
                digitalWrite ( d,LOW);
 
                digitalWrite ( f,LOW);
 
                digitalWrite ( c,HIGH);}
 
 
  if(places==2){
 
             digitalWrite ( a,HIGH);
 
             digitalWrite ( b,HIGH);
 
             digitalWrite ( c,LOW);
 
             digitalWrite ( e,HIGH);
 
             digitalWrite ( d,HIGH);
 
             digitalWrite ( f,LOW);
 
             digitalWrite ( g,HIGH);}
 
   if(places==3){
 
             digitalWrite ( a,HIGH);
 
             digitalWrite ( b,HIGH);
 
             digitalWrite ( f,LOW);
 
             digitalWrite ( c,HIGH);
 
             digitalWrite ( d,HIGH);
 
             digitalWrite ( e,LOW);

             digitalWrite ( g,HIGH);}
  if(places==4){
             digitalWrite ( a,LOW);
             digitalWrite( b,HIGH);
             digitalWrite ( e,LOW);
             digitalWrite ( c,HIGH);
             digitalWrite ( f,HIGH);
             digitalWrite ( d,LOW);
             digitalWrite ( g,HIGH);}
  if(places==5){
            digitalWrite ( a,HIGH);
            digitalWrite ( f,HIGH);
            digitalWrite ( e,LOW);
            digitalWrite ( c,HIGH);
            digitalWrite ( d,HIGH);
            digitalWrite ( b,LOW);
            digitalWrite ( g,HIGH);}
            }
