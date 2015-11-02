
int leftButton = 4;
int rightButton = 5;
int upButton = 11;
int downButton = 12;

void setup() {
  Serial.begin(9600);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
}

void loop() {

  //Serial.println(Serial.read());
  
  if(Serial.read() == 65){
  int leftV = digitalRead(leftButton);
  int rightV = digitalRead(rightButton);
  int upV = digitalRead(upButton);
  int downV = digitalRead(downButton);
  
  
  if(leftV == 1){
     Serial.write("l");
  }
  else if(rightV == 1){
     Serial.write("r");
  }
  else if(upV == 1){
     Serial.write("u");
  }
  else if(downV == 1){
     Serial.write("d");
  }
  
  }
  
  Serial.write(0);
  
  delay(50);
  
}



