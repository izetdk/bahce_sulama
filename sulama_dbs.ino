long domatesGUN[4] = {3, 3, 4, 4};
long domatesDAK[4] = {6, 7, 7, 7};

long biberGUN[4]  = {2, 2, 3, 3};
long biberDAK[4]  = {4, 5, 5, 5};

long salataGUN[4] = {1, 1, 2, 2};
long salataDAK[4] = {2, 3, 3, 3};


long domatesMS = 0;
long biberMS   = 0;
long salataMS  = 0;

int domatesKalan = 0;
int biberKalan   = 0;
int salataKalan  = 0;

long bekle=0;
int gun=0;

int pot=0;
int knob=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  pot = analogRead(A0);
  knob = map(pot, 0, 1023, 0, 3);
  
digitalWrite(13, HIGH);
digitalWrite(12, HIGH);
digitalWrite(11, HIGH);

domatesKalan  =fmod(gun, domatesGUN[knob]);
biberKalan    =fmod(gun, biberGUN[knob]);
salataKalan   =fmod(gun, salataGUN[knob]);

if(domatesKalan < 1){
  Serial.println();
  Serial.print("\t Domates : ");
  Serial.print(domatesGUN[knob]);
  Serial.print(" gun arayla ");
  Serial.print(domatesDAK[knob]);
  Serial.println(" dakika.");
  
  domatesMS = domatesDAK[knob]*60*1000;
  digitalWrite(11, LOW);
  delay(domatesMS);
  digitalWrite(11, HIGH);
} else{
  domatesMS = 0; 
}

if(biberKalan < 1){
  
  Serial.print("\t Biber : ");
  Serial.print(biberGUN[knob]);
  Serial.print(" gun arayla ");
  Serial.print(biberDAK[knob]);
  Serial.println(" dakika.");
  
  biberMS = biberDAK[knob]*60*1000;
  digitalWrite(12, LOW);
  delay(biberMS);
  digitalWrite(12, HIGH);
} else{
  biberMS = 0; 
}

if(salataKalan < 1){
  
  Serial.print("\t Salata : ");
  Serial.print(salataGUN[knob]);
  Serial.print(" gun arayla ");
  Serial.print(salataDAK[knob]);
  Serial.println(" dakika.");
  
  salataMS = salataDAK[knob]*60*1000;
  digitalWrite(13, LOW);
  delay(salataMS);
  digitalWrite(13, HIGH);
} else{
  salataMS = 0; 
}

bekle = 60000*60*24-domatesMS-biberMS-salataMS-61000;

delay(bekle);
gun++;
}
