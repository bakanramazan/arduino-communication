int pin[]={6,7,8,9};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<4;i++){
  pinMode(pin[i],OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<4;i++){
  digitalWrite(pin[i],HIGH);
  delay(1000);
  digitalWrite(pin[i],LOW);
}
}
