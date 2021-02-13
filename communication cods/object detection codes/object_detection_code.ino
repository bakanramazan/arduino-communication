int trigpini = 8; // TRIG pin 
int echopini = 7;  // ECHO pin
long deger;
long cm;

void setup(){
  pinMode(trigpini, OUTPUT); 
  pinMode(echopini,INPUT); 
 Serial.begin(9600);       
  
}

void loop()
{
  digitalWrite(trigpini, LOW);
  digitalWrite(trigpini, HIGH);        
  digitalWrite(trigpini, LOW);   
  deger = pulseIn(echopini, HIGH);     
  cm= (deger/2)/29.1;                  
if(cm<=100){
Serial.println(cm);     
  delay(1000); 
}
}
