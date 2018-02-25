static const uint8_t pins[]={2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3,A4,A5};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int n=0; n<18; n++){
    pinMode(pins[n], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<18; i++){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
    for(int j=0; j<18; j++){
      if(i!=j){
        pinMode(pins[j], INPUT);
      }
      if(digitalRead(pins[j])==HIGH && i!=j){
        Serial.print(pins[i]);
        Serial.print(',');
        Serial.println(pins[j]);
      }
    }
    digitalWrite(pins[i], LOW);
  }
}
