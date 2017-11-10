#define LCD_Backlight;
#include <LiquidCrystal.h>;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState1;
int switchState2;
int prevSwitchState = 0;
int state1 = 0;
int reply;
int digitalTest = 0;

void setup() {
     Serial.begin(9600); 
      analogWrite(9,2);
     lcd.begin(16, 2);
     lcd.print("Welcome to");
     lcd.setCursor(0, 1);
     lcd.print("Coltrane's Calc");


}


void enterByte(){
  
  
  
}

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
//                   
  else if(digitalTest == 1 && switchState1 == HIGH && switchState2 == LOW){
 
      lcd.clear();
          lcd.blink();

      

   }
//   else if(digitalTest == 1 && switchState1 == LOW && switchState2 == HIGH){
//    lcd.clear();
//    
//    }

    
//  if(switchState1 != prevSwitchState && switchState2 != prevSwitchState){
//    Serial.print(switchState1);
//    Serial.print(switchState2);
//    if(switchState1 == LOW && switchState2 == LOW){
//      reply = random(8);
//    
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print("The ball says: ");
//    lcd.setCursor(0,1);

//    switch(reply){
//      case 0:
//      lcd.print("Yes");
//      break;
//      case 1:
//      lcd.print("Most likely");
//      break;
//      case 2:
//      lcd.print("Certainly");
//      break;
//      case 3:
//      lcd.print("Outlook good");
//      break;
//      case 4:
//      lcd.print("Unsure");
//      break;
//      case 5:
//      lcd.print("Ask again");
//      break;
//      case 6:
//      lcd.print("Doubtful");
//      break;
//      case 7:
//      lcd.print("No");
//      break;
//      
//      }
//    }
//  }
//  
      prevSwitchState = switchState1;
//  if(switchState1 == HIGH && switchState1 == HIGH){
//    lcd.print("Enter");
//    lcd.blink(q);
//   
//   }
//   else{
//    
//    }
//  lcd.display();
//     lcd.print("Hello Friends");
//    
//    lcd.setCursor(0, 1);
//     lcd.print("KesPra");
}
