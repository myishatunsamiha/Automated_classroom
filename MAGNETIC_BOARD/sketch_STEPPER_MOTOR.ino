#define D 700

int dis = 0; // Record the number of steps we've taken void setup() {
bool flag3 = false, flag4 = false, flag5 = false, flag = true, f = false;
int count = 0;



void setup(){
  Serial.begin(9600);
    
  pinMode(8, OUTPUT);
  
  pinMode(9, OUTPUT);
  
  digitalWrite(8, LOW);
  
  digitalWrite(9, LOW);

/////switch
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  pinMode(12, OUTPUT);
  
  digitalWrite(12, HIGH);

}

void loop() {
  if(flag3 == true){
    
    digitalWrite(8, HIGH);
    delayMicroseconds(D);
    digitalWrite(8, LOW);
    delayMicroseconds(D);

    if(flag == true) digitalWrite(9, HIGH);
    
    if(flag)dis--;
    else dis++;

    if (dis == -801) { // We are! Reverse direction (invert DIR signal)
      delay(300);
      flag = false;
      digitalWrite(9, LOW);
    }
    if(dis == -1){
     count++;
     flag = true;
     digitalWrite(9, HIGH);
     delay(300);
     
     if(count == 3){
      count = 0;
      dis++;
      flag3 = false;
     }
    }
  }

  if(flag5 == true){
    
    digitalWrite(8, HIGH);
    delayMicroseconds(D);
    digitalWrite(8, LOW);
    delayMicroseconds(D);

    
    if(flag)dis++;
    else dis--;

    if (dis == 801) { // We are! Reverse direction (invert DIR signal)
      delay(300);
      flag = false;
      digitalWrite(9, HIGH);
    }
    if(dis == 1){
     count++;
     flag = true;
     digitalWrite(9, LOW);
     delay(300);
     
     if(count == 3){
      count = 0;
      dis--;
      flag5 = false;
      f = false;
     }
    }
  }

  if(flag4 == true){
    f = true;
    flag4 = false;
    flag3 = true;
    flag5 = false;
  }

  if(f == true){
    if(flag3 == false) flag5 = true;
  }
  
  if(dis == 0){
    if(digitalRead(3) == HIGH){
      flag3 = true;
      flag4 = false;
      flag5 = false;
    }
    else if(digitalRead(4) == HIGH){
      flag3 = false;
      flag4 = true;
      flag5 = false;
    }
    else if(digitalRead(5) == HIGH){
      flag3 = false;
      flag4 = false;
      flag5 = true;
    }
  }


  /*if(flag){
    Distance++;
  }
  else Distance--;


  if (Distance == 800) { // We are! Reverse direction (invert DIR signal)
     delay(500);
     flag = false;
     digitalWrite(9, HIGH);
  }
  if(Distance == 0){
     flag = true;
     digitalWrite(9, LOW);
     delay(500);
        
  }*/
  
}
