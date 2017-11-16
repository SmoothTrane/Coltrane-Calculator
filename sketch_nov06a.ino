#include <LiquidCrystal.h>;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int switchState1;
int switchState2;
int byte1Ready = 0;
int byte1IncrementReady = 0;
int byte2IncrementReady = 0;
char  *byte1 = "1";
char  *byte2 = "1";
bool byte1Max = 0;
bool byte2Start = 0;
int byte2Ready = 0;
int contrastReady = 0;
int leftReady;
int rightReady;
int i = 2;
int summaryVal[20];
int contrastTip = 0;

void setup() {
  
  Serial.begin(9600);
  analogWrite(9, 2);
  lcd.begin(16, 2);
  lcd.print("Press both butt");
  lcd.setCursor(0, 1);
  lcd.print("ons together");

  
}

/* Switches the leftmost bit
 *  
 */

void switchBits(char *byteNum) {
  if (byteNum[strlen(byteNum) - 1] == '1') {
    byteNum[strlen(byteNum) - 1] = '0';
  }
  else {
    byteNum[strlen(byteNum) - 1] = '1';
  }
  lcd.print(byteNum);
}



void loop() {
  analogWrite(9, i);


  switchState1 = digitalRead(8);
  switchState2 = digitalRead(7);
  
  if (switchState1 == HIGH  && switchState2 == HIGH && byte1Ready == 0) {
    *byte1 = "1";
    *byte2 = "1";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press the right");
    lcd.setCursor(0, 1);
    lcd.print("button to proceed");
    delay(1000);
    byte1Ready = 1;
  }
  else if (byte1Ready == 1 && switchState1 == HIGH && switchState2 == LOW) {
    lcd.clear();
    lcd.blink();
    switchBits(byte1);
    byte1IncrementReady = 1;
  }
  else if (byte1IncrementReady == 1 && switchState1 == LOW && switchState2 == HIGH) {
    if (strlen(byte1) < 8) {
      byte1 = concat(byte1, "0");
      lcd.clear();
      lcd.blink();
      lcd.print(byte1);
      byte1IncrementReady = 0;
    }
    else {
      byte1Max = 1;
      byte2Start = 1;   

    }
  }
  else if (byte1Max == 1 && byte2Start == 1) {
    lcd.clear();
    lcd.print("Press the right button");
        lcd.setCursor(0, 1);
lcd.print("To add byte 2");
  byte1Ready = -1;
    byte1IncrementReady = 0;
    byte2Start = 0;
    byte2Ready = 1;
  }
  else if (byte2Ready == 1 && switchState1 == HIGH && switchState2 == LOW) {
    lcd.clear();
    lcd.blink();
    switchBits(byte2);
    byte2IncrementReady = 1;
  }
  else if (byte2IncrementReady == 1 && switchState2 == HIGH && switchState1 == LOW) {
    if (strlen(byte2) < 8) {
      byte2 = concat(byte2, "0");
      lcd.clear();
      lcd.blink();
      lcd.print(byte2);
      byte2IncrementReady = 0;
    }
    else {
      byte2Ready = 0;
      lcd.clear();
      long binary1, binary2;
      binary1 = strtol(byte1, 0, 10);
      binary2 = strtol(byte2, 0, 10);
      int incrementer = 0;
      int carryVal = 0;

/*
 * 
 * Binary addition logic from  http://www.sanfoundry.com/c-program-sum-binary-numbers/
 */

      while (binary1 != 0 || binary2 != 0) {
        summaryVal[incrementer++] = (binary1 % 10 + binary2 % 10 + carryVal) % 2;
        carryVal = (binary1 % 10 + binary2 % 10 + carryVal) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
      }
      if (carryVal != 0) {
        summaryVal[incrementer++] = carryVal;
        --incrementer;
      }
      while (incrementer >= 0) {
        lcd.print(summaryVal[incrementer--]);
        byte2IncrementReady = 0;
        contrastReady = 1;
        byte1Ready = -1;

      }


    }
  }
  /* 
   *  Sets up the contrast
   *  
   */
  else if (contrastReady == 1 && switchState1 == HIGH && switchState2 == HIGH) {
    lcd.clear();
    lcd.print("Press right button to increase contrast");
    lcd.setCursor(0, 1);
    lcd.print("Press left button to decrease contrast");
    contrastReady = 0;
    leftReady = 1;
    rightReady = 1;
         delay(1000);
    contrastTip = 1;



  } else if (contrastTip ==  1 && switchState1 == HIGH && switchState2 == HIGH) {
  
    contrastTip = 0;
    reset();



  }

  else if (leftReady == 1 && switchState2 == HIGH && switchState1 == LOW) {
    if(i > 1){
     i--;
    }
    contrastTip = 1;
  }

  else if (rightReady ==  1 && switchState1 == HIGH && switchState2 == LOW) {
      i++;
    contrastTip = 1;

  }

 


}



void reset() {
  summaryVal[20] = {};
  byte1Ready = 0;
  byte1Max = 0;
  byte2Start = 0;
  leftReady = 0;
  rightReady = 0;
  contrastReady = 0;
  byte1IncrementReady = 0;
  byte1Max = 0;
  byte2Start = 0;
  byte2Ready = 0;
  byte2IncrementReady = 0;
  byte1 = "1";
  byte2 = "1";
}


/*
 * 
 *concat function from David Heffernan: https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
 * 
 */
char* concat( char *string1,  char *string2)
{
  char *result = malloc(strlen(string1) + strlen(string2) + 1);
  strcpy(result, string1);
  strcat(result, string2);
  return result;
}


