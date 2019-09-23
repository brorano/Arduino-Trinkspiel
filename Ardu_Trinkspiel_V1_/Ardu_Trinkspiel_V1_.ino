const int ledCount = 8;
int switchPin1 = 2;
int switchPin2 = 11;
int taster = 12;
int pinArray[] = {
  3, 4, 5, 6, 7, 8, 9, 10
  };
int dly=35;
int tasterStat;
int swPosition;


void setup(){
  //loop the pin array and set all to output:
  for (int thisLed = 0; thisLed <= ledCount; thisLed++) {
    pinMode(pinArray[thisLed], OUTPUT);
  }
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(taster, INPUT_PULLUP);
}
void loop(){

getSwitch();
switch (swPosition) {
  case 1:
    uModus();
    break;
  case 2:
    //gameMode
    break;
  default:
  
    break;
}







}


void allLedsOff(){
  digitalWrite( 3 ,LOW);
  digitalWrite( 4 ,LOW);
  digitalWrite( 5 ,LOW);
  digitalWrite( 6 ,LOW);
  digitalWrite( 7 ,LOW);
  digitalWrite( 8 ,LOW);
  digitalWrite( 9 ,LOW);
  digitalWrite(10 ,LOW);
}

int getSwitch(){
  int i = digitalRead(switchPin1);
  int f = digitalRead(switchPin2);
  if(!i){ 
    swPosition = 1;
  }
  else{swPosition = 2;}
  return swPosition;
}



void hochAn(){
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(pinArray[thisLed], HIGH);
    tasterStat = digitalRead(taster);
    if(!tasterStat){
      allLedsOff();
      
    }
    delay(dly);
  }
}





void hochAus(){
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(pinArray[thisLed], LOW);
    tasterStat = digitalRead(taster);
    if(!tasterStat){
      allLedsOff();
      
    }
    delay(dly);
  }
}





void runterAn(){
  for (int thisLed = 7; thisLed >= 0; thisLed--) {
    digitalWrite(pinArray[thisLed], HIGH);
    tasterStat = digitalRead(taster);
    if(!tasterStat){
      allLedsOff();
      
    }
    delay(dly);
  }
}






void runterAus(){
  for (int thisLed = 7; thisLed >= 0; thisLed--) {
    digitalWrite(pinArray[thisLed], LOW);
    tasterStat = digitalRead(taster);
    if(!tasterStat){
      allLedsOff();
      
    }
    delay(dly);
  }
}



void uModus(){
  
hochAn();
hochAus();
runterAn();
runterAus();

}
