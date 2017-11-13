#define LCD_Backlight;
#include <LiquidCrystal.h>;
#include <string.h>;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int switchState1;
int switchState2;
int byte1Ready = 0;
int byte1IncrementReady = 0;
int byte2IncrementReady = 0;
char* byte1 = "1";
char* byte2 = "1";
bool byte1Max = 0;
bool byte2Start = 0;
int byte2Ready = 0;

void setup() {
  Serial.begin(9600); 
  analogWrite(9,2);
  lcd.begin(16, 2);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Coltrane's Calc");
}



void switchBits(char *byteNum){
  if(byteNum[strlen(byteNum) -1] == '1'){
    byteNum[strlen(byteNum)-1] = '0';    
    }
    else{
      byteNum[strlen(byteNum)-1] = '1';
    }
    lcd.print(byteNum);
  }

  

void loop() {
  switchState1 = digitalRead(8);
  switchState2 = digitalRead(7);
  if(switchState1 == HIGH  && switchState2 == HIGH && byte1Ready == 0){
    lcd.clear();
    *byte1 = "1";
    *byte2 = "1";
    lcd.setCursor(0,0);
    lcd.print("Press the right ");
    lcd.setCursor(0,1);
    lcd.print("button to continue");
    delay(1000);
    byte1Ready = 1;
  }              
  else if(byte1Ready == 1 && switchState1 == HIGH && switchState2 == LOW){
      lcd.clear();
      lcd.blink();
      switchBits(byte1);
      byte1IncrementReady = 1;
   }
   else if(byte1IncrementReady == 1 && switchState1 == LOW && switchState2 == HIGH){
      if(strlen(byte1)< 8){
        byte1 = concat(byte1,"0");
        lcd.clear();
        lcd.blink();
        lcd.print(byte1);
        byte1IncrementReady = 0;
      }
       else{
          byte1Max = 1;
          byte2Start = 1;
       }
   }
    else if(byte1Max == 1 && byte2Start == 1){
      lcd.clear();
      lcd.print("Press the right button to continue to add to byte 2");
      byte1IncrementReady = 0;
      byte1Ready = 0;
      byte2Start = 0;
      byte2Ready = 1;
     }
    else if(byte2Ready == 1 && switchState1 == HIGH && switchState2 == LOW){
      lcd.clear();
      lcd.blink();
      switchBits(byte2);
      byte2IncrementReady = 1;      
    }
     else if(byte2IncrementReady == 1 && switchState2 == HIGH && switchState1 == LOW){
      if(strlen(byte2) < 8){
        byte2 = concat(byte2, "0");
        lcd.clear();
        lcd.blink();
        lcd.print(byte2);
        byte2IncrementReady = 0;
       }
        else{
            byte2Ready = 0;
            lcd.clear();
            long binary1, binary2;
            binary1 = strtol(byte1,0,10);
            binary2 = strtol(byte2,0,10);             
            int incrementer = 0;
            int carryVal = 0;
            int summaryVal[20];
            while (binary1 != 0 || binary2 != 0) {
              summaryVal[incrementer++] =(binary1 % 10 + binary2 % 10 + carryVal) % 2;
              carryVal =(binary1 % 10 + binary2 % 10 + carryVal) / 2;
              binary1 = binary1 / 10;
              binary2 = binary2 / 10;
          }
        if (carryVal != 0){
         summaryVal[incrementer++] = carryVal;
         --incrementer;
      }
      while (incrementer >= 0){       
          lcd.print(summaryVal[incrementer--]);
         
      }      
       
          
    }        
    
  }
    

}





char* concat( char *string1,  char *string2)
{
    char *result = malloc(strlen(string1)+strlen(string2)+1);
    strcpy(result, string1);
    strcat(result, string2);
    return result;
}


