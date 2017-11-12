#define LCD_Backlight;
#include <LiquidCrystal.h>;
#include <string.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState1;
int switchState2;
int prevSwitchState = 0;
int state1 = 0;
int reply;
int digitalTest = 0;
int switchTest = 0;
int byte2SwitchTest = 0;
int currentBit = 0;
byte testLove = 111;
byte testLove2 = 001;
char* byte1 = "10101";
char* byte2 = "1";
bool byte1Max = 0;
bool byte2Test = 0;
int  test = 2; 
char testData[8];
int byte2DigitalTest = 0;



void setup() {
     Serial.begin(9600); 
      analogWrite(9,2);
     lcd.begin(16, 2);
     lcd.print("Welcome to");
     lcd.setCursor(0, 1);
     lcd.print("Coltrane's Calc");
//     testNum(&testData);
//     Serial.print(testData);
int test  = '5202' - '0';
Serial.print(test + 2 );






}


//void testNum(char byteNum[]){
//  byteNum[0] = '0';
//  byteNum->concat('0');

 // *byteNum[byteNum->length()-1] = '0';


//}

//void switchBits(String *byteNum){
//  if( == '1'){
//    byteNum[0] = '0';
//      
//    }
//    else{
//      byteNum[0]= '1';
//    }
//    lcd.print(*byteNum);
  
//  }


void switchByte1(){


   if(byte1[strlen(byte1)-1] == '1'){
    byte1[strlen(byte1)-1] = '0';
      
    }
    else{
      byte1[strlen(byte1)-1]='1';
    }
    lcd.print(byte1);

 }

  void switchByte2(){


   if(byte2[strlen(byte2)-1] == '1'){
    byte2[strlen(byte2)-1] = '0';
      
    }
    else{
      byte2[strlen(byte2)-1]='1';
    }
    lcd.print(byte2);

 }



  /*

void loop() {
  switchState1 = digitalRead(8);
  switchState2 = digitalRead(7);


  if(switchState1 == HIGH  && switchState2 == HIGH && digitalTest == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Press the right ");
    lcd.setCursor(0,1);
    lcd.print("button to continue");
    delay(1000);
    digitalTest = 1;
  }
                 
  else if(digitalTest == 1 && switchState1 == HIGH && switchState2 == LOW){
 
      lcd.clear();
      
          lcd.blink();
         switchByte1();
      //  switchBits(&byte1);
         switchTest = 1;
          // User presses right button, opens up bit 1, if user presses it again, it changes to 0
          

      

   }


   else if(switchTest == 1 && switchState1 == LOW && switchState2 == HIGH){
      if(strlen(byte1)< 8){
   

              byte1 = concat(byte1,"0");
                     lcd.clear();
    lcd.blink();
    lcd.print(byte1);
          switchTest = 0;


        }
        else{
          byte1Max = 1;
          byte2Test = 1;
          }

      
    
    }
    else if(byte1Max == 1 && byte2Test == 1)
    {
      lcd.clear();
      lcd.print("Press the right button to continue to add to byte 2");
      switchTest = 0;
      digitalTest = 0;
      byte2Test = 0;
      byte2DigitalTest = 1;

      
      }

      else if(byte2DigitalTest == 1 && switchState1 == HIGH && switchState2 == LOW){
         lcd.clear();
          lcd.blink();
         switchByte2();
      //  switchBits(&byte2);
          byte2SwitchTest = 1;
        
        }
        else if(byte2SwitchTest == 1 && switchState2 == HIGH && switchState1 == LOW){
          

      if(strlen(byte2) < 8){
          byte2 = concat(byte2, "0");
        lcd.clear();
        lcd.blink();
        lcd.print(byte2);
        byte2SwitchTest = 0;


        }else{
          byte2DigitalTest = 0;
          lcd.clear();
          //toInt not properly converting to integer equivalent 
         
          int binary1 = atoi(byte1);
          Serial.print("Binary1:");
          Serial.print(binary1);
          int binary2 = atoi(byte2);
          Serial.print("Binary2:");
          Serial.print(binary2);
          
        
          
    int i = 0, remainder = 0, sum[20];

    while (binary1 != 0 || binary2 != 0)
    {
        sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
    if (remainder != 0){
        sum[i++] = remainder;
          --i;
    }
    while (i >= 0){
        lcd.print(sum[i--]);
    }
       
          
          
          }
          
          
          
          }
    

}

*/

void loop(){}



char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


