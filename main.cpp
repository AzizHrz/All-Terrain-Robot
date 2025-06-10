#include <Psx.h>
#include <SPI.h>

#define dataPin 4
#define cmndPin 3
#define attPin 2
#define clockPin 5

Psx Psx;

byte envio[8];
byte data1;
byte data2;

// pins for motor 1
int RPWM1= 6; // define pin 3 for RPWM pin (output)
int REN1= 8; // define pin 2 for R_EN pin 
int LPWM1= 9; // define pin 6 for LPWM pin (output)
int LEN1= 7; // define pin 7 for L_EN pin 

// motor 1 pins end here

// pins for motor 2
int RPWM2= 10; // define pin 9 for RPWM pin (output)
int REN2= A1; // define pin 10 for R_EN pin 


int LPWM2= 11; // define pin 11 for LPWM pin (output)
int LEN2= A2; // define pin 7 for L_EN pin 

// motor 2 pins end here

uint8_t v = 0;
uint8_t v1 = 0;
//uint8_t v3 = 0;
uint8_t a ;


void setup()
{
  Serial.begin(57600);
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
   pinMode(LPWM1,OUTPUT);
  pinMode(RPWM1,OUTPUT);
  pinMode(LPWM2,OUTPUT);
  pinMode(RPWM2,OUTPUT);   
  pinMode(REN1,OUTPUT);
  pinMode(REN2,OUTPUT);
  pinMode(LEN1,OUTPUT);
  pinMode(LEN2,OUTPUT);

 
 digitalWrite(REN1,HIGH);
 digitalWrite(LEN1,HIGH);
 digitalWrite(REN2,HIGH);
 digitalWrite(LEN2,HIGH);


  
  Serial.println("Beginning ... ");   
}

void loop()
{
  Psx.read();

  if(Psx.psxID != 0x00)
  {
    envio[0] = Psx.psxID; // DIGITAL (82) , ANALOGICO (CE)
    envio[1] = Psx.psxStatus;
    envio[2] = Psx.psxThumbL; // SETAS, SELECT, DIGITAL L
    envio[3] = Psx.psxThumbR; // (x,[],/\,O), START, DIGITAL R, (L1,L2,R1,R2)
    envio[4] = Psx.psxJoyRX; // EIXO ANALOGICO "X" DO "R"
    envio[5] = Psx.psxJoyRY; // EIXO ANALOGICO "Y" DO "R"
    envio[6] = Psx.psxJoyLX; // EIXO ANALOGICO "X" DO "L"
    envio[7] = Psx.psxJoyLY; // EIXO ANALOGICO "Y" DO "L"
    



    data1=envio[1];
    data2=envio[2];
    switch (data2) {
      case 0:
       v=0;
       v1=0;
         analogWrite(RPWM1,0);
         analogWrite(LPWM1,0);
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,0);
       
        break;
      case 1:
        v = 77;//min 27
        v1 = 82;
        break;
      case 2:
        v = 90;
        v1 = 97;
        break;
      case 4:
        v = 113;
        v1 = 123;
        break;
      case 8:
        v = 179;
        v1 = 192;
        break;
        
      case 17: //R1 et []
         analogWrite(RPWM1,0);
         analogWrite(LPWM1,0);
         analogWrite(LPWM2,0);
         analogWrite(RPWM2,32);
         
        break;
        
      case 33: //L1 et[]
         analogWrite(LPWM1,0);
         analogWrite(RPWM1,32);
         
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,0);
        break;
        
        case 18: //R1 et X
         analogWrite(RPWM1,0);
         analogWrite(LPWM1,0);
        
         analogWrite(LPWM2,0);
         analogWrite(RPWM2,38);
        break;
      
      case 34: //L1 et X
         analogWrite(LPWM1,0);
         analogWrite(RPWM1,35);
         
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,0);
        break;

      case 20: //R1 et °
        analogWrite(RPWM1,0);
         analogWrite(LPWM1,0);
         analogWrite(LPWM2,0);
         analogWrite(RPWM2,48);
         
        break;
      
      case 36: //L1 et °
         analogWrite(LPWM1,0);
         analogWrite(RPWM1,44);
         
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,0);
        break;

      case 24: //R1 et triangle
        analogWrite(RPWM1,0);
         analogWrite(LPWM1,0);
         
         analogWrite(LPWM2,0);
         analogWrite(RPWM2,75);
        break;

      
      case 40: //L1 et triangle
        analogWrite(LPWM1,0);
        analogWrite(RPWM1,70);
        
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,0);
        break;

     /* case 65: //R2
      
        analogWrite(Ren2, 0);
        analogWrite(Ren1, 70);

        analogWrite(Len2, 0);
        analogWrite(Len1, 70);
        break;
        

      case 129: //L2
       
        analogWrite(Ren2, 0);
        analogWrite(Ren1, 70);

        analogWrite(Len2, 0);
        analogWrite(Len1, 70);
        
        break;*/
    }
    
    switch (data1) {
     case 0:
       
        // motor1.rotate(v,CW);
        // motor2.rotate(v,CW);
        break;
      case 1://right
        /* if (a != 1) {
            motor1.stop();// stop the motor 1
            motor2.stop();// stop the motor 2
           //  delay(90);  // stop for 3 seconds
             a = 1;
          }*/
       
         analogWrite(LPWM1,0);
          analogWrite(RPWM1,v);
          
        
         analogWrite(LPWM2,0);
          analogWrite(RPWM2,v1);
        break;
      case 2: //backward();
       /* if (a != 2) {
            motor1.stop();// stop the motor 1
            motor2.stop();// stop the motor 2
            // delay(90);  // stop for 3 seconds
             a = 2;
          }*/
    

       
         analogWrite(RPWM1,0);
         analogWrite(LPWM1,v);
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,v1);
     break;
      case 4://left
        /*if (a != 4) {
            motor1.stop();// stop the motor 1
            motor2.stop();// stop the motor 2
            // delay(90);  // stop for 3 seconds
             a = 4;
          }*/

       
         analogWrite(LPWM1,0);
          analogWrite(RPWM1,v);
          
         analogWrite(RPWM2,0);
         analogWrite(LPWM2,v1);
        break;
      case 8: // forward();
        /* if (a != 8) {
            motor1.stop();// stop the motor 1
            motor2.stop();// stop the motor 2
            // delay(90);  // stop for 3 seconds
             a = 8;
          }*/
         analogWrite(LPWM1,0);
         analogWrite(RPWM1,v);
         
         
         analogWrite(LPWM2,0);
         analogWrite(RPWM2,v1);
        break;
    }
    
   
      
      Serial.print("Data 0 ==> ");
      Serial.println(envio[2]);
      Serial.print("Data 1 ==> ");
      Serial.println(envio[3]);

 
  }

  delay(50);

}
