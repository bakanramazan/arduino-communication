const int sagIleriPini = 2;
const int sagGeriPini = 4;
const int solIleriPini = 5;
const int solGeriPini = 7;

const int sagIsikGiris = A0;
const int solIsikGiris = A1;
const int onIsikGiris = A2;
long sagOkunanIsik = 0;
long solOkunanIsik = 0;
long onOkunanIsik = 0;

const int trigPini = 12; // TRIG pin
const int echoPini = 11;  // ECHO pin
//int echoOkunanDeger = 0;
//unsigned long mesafe = 0;
int sinirIsik = 350;

void setup() {
  pinMode(sagIleriPini, OUTPUT);
  pinMode(sagGeriPini, OUTPUT);
  pinMode(solIleriPini, OUTPUT);
  pinMode(solGeriPini, OUTPUT);
  pinMode(sagIsikGiris, INPUT);
  pinMode(solIsikGiris, INPUT);
  pinMode(onIsikGiris, INPUT);
  pinMode(echoPini, INPUT );
  pinMode(trigPini, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sagOkunanIsik = analogRead(sagIsikGiris);
  solOkunanIsik = analogRead(solIsikGiris);
  onOkunanIsik = analogRead(onIsikGiris);
//  //Serial.print("SAG > ");
//  Serial.println(sagOkunanIsik);
//  Serial.print("SOL > ");
//  Serial.println(solOkunanIsik);
//  Serial.print("ON > ");
//  Serial.println(onOkunanIsik);
  if (sagOkunanIsik < sinirIsik  || solOkunanIsik < sinirIsik || onOkunanIsik < sinirIsik) {

    if (sagOkunanIsik < solOkunanIsik && sagOkunanIsik < onOkunanIsik) {
      sagIleri();
      delayMicroseconds(900);
      
    }
    else if ( solOkunanIsik < sagOkunanIsik &&  solOkunanIsik < onOkunanIsik) {
      solIleri();
      delayMicroseconds(900);
      
    }
    else if (onOkunanIsik < sagOkunanIsik &&  onOkunanIsik < solOkunanIsik) {
      ileri();
    }
  } else {
    Serial.println("DUR");
    dur();
  }
}


//long cisimAlgilama() {
//  digitalWrite(trigPini, LOW);
//  delayMicroseconds(1000);
//  digitalWrite(trigPini, HIGH);
//  delayMicroseconds(1000);
//  digitalWrite(trigPini, LOW);
//
//  long echoOkunanDeger = pulseIn(echoPini, HIGH);
//  long mesafe = (echoOkunanDeger / 2) / 29.1;
//  return mesafe;
//}
void ileri() {
  digitalWrite(sagIleriPini, LOW);
  digitalWrite(sagGeriPini, HIGH);
  digitalWrite(solIleriPini, HIGH);
  digitalWrite(solGeriPini, LOW);
}
void geri() {
  digitalWrite(sagIleriPini, HIGH);
  digitalWrite(sagGeriPini, LOW);
  digitalWrite(solIleriPini, LOW);
  digitalWrite(solGeriPini, HIGH);
}
void sagIleri() {
  digitalWrite(sagIleriPini, LOW);
  digitalWrite(sagGeriPini, LOW);
  digitalWrite(solIleriPini, HIGH);
  digitalWrite(solGeriPini, LOW);
}
void solIleri() {
  digitalWrite(sagIleriPini, LOW);
  digitalWrite(sagGeriPini, HIGH);
  digitalWrite(solIleriPini, LOW);
  digitalWrite(solGeriPini, LOW);
}
void sagGeri() {
  digitalWrite(sagIleriPini, LOW);
  digitalWrite(sagGeriPini, LOW);
  digitalWrite(solIleriPini, LOW);
  digitalWrite(solGeriPini, HIGH);
}
void solGeri() {
  digitalWrite(sagIleriPini, HIGH);
  digitalWrite(sagGeriPini, LOW);
  digitalWrite(solIleriPini, LOW);
  digitalWrite(solGeriPini, LOW);
}
void dur() {
  digitalWrite(sagIleriPini, HIGH);
  digitalWrite(sagGeriPini, HIGH);
  digitalWrite(solIleriPini, HIGH);
  digitalWrite(solGeriPini, HIGH);
}


