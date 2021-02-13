const float anologPin=1; 
float isik = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
isik=analogRead(anologPin);
Serial.println(isik);

}
