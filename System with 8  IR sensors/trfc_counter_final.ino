#define ledA3 2
#define ledA2 3
#define ledA1 4

#define ledB3 5
#define ledB2 6
#define ledB1 7

#define ledC3 8
#define ledC2 9
#define ledC1 10

#define ledD3 11
#define ledD2 12
#define ledD1 13

int a1, a2, b1, b2, c1, c2, d1, d2;

int num_array[10][7] = {  { 0,0,0,0,0,0,1 },    // 0
                          { 1,0,0,1,1,1,1 },    // 1
                          { 0,0,1,0,0,1,0 },    // 2
                          { 0,0,0,0,1,1,0 },    // 3
                          { 1,0,0,1,1,0,0 },    // 4
                          { 0,1,0,0,1,0,0 },    // 5
                          { 0,1,0,0,0,0,0 },    // 6
                          { 0,0,0,1,1,1,1 },    // 7
                          { 0,0,0,0,0,0,0 },    // 8
                          { 0,0,0,0,1,0,0 }};   // 9

void setup() {

  Serial.begin(9600);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);

 for (int i=22; i<50; i++){
  pinMode(i,OUTPUT);
 }

}

void loop() {

  readSensor();

  if (a1 == 1 && a2 == 1)
  {
    roadAopen();
  }
  else if (b1 == 1 && b2 == 1 && (a1 == 0 || a2 == 0))
  {
    roadBopen();
    if (a1 == 1 && a2 == 1)
    {
      roadAopen();
    }
  }
  else if (c1 == 1 && c2 == 1 && ((b2 == 0 || a2 == 0) || (b1 == 0 || a1 == 0)))
  {
    roadCopen();
    if (a1 == 1 && a2 == 1)
    {
      roadAopen();
    }
    else if (b1 == 1 && b2 == 1 && (a1 == 0 || a2 == 0))
    {
      roadBopen();
    }
  }
  else if (d1 == 1 && d2 == 1 && ((b2 == 0 || a2 == 0 || c2 == 0) || (b1 == 0 || a1 == 0 || c1 == 0)))
  {
    roadDopen();
    if (a1 == 1 && a2 == 1)
    {
      roadAopen();
    }
    else if (b1 == 1 && b2 == 1 && (a1 == 0 || a2 == 0))
    {
      roadBopen();
    }
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if ((a1 == 1 && a2 == 0) && (d1 == 1 || b1 == 1 || a1 == 1) && (d2 == 1 && b2 == 1 && a2 == 1))
  {
    roadAopena();
  }
  else if ((b1 == 1 && b2 == 0) && (d1 == 1 || c1 == 1) && (a1 == 0 && a2 == 0) && (d2 == 0 && c2 == 0))
  {
    roadBopenb();
  }
  else if ((c1 == 1 && c2 == 0) && (d1 == 1 && d2 == 0) && (b1 == 0 && b2 == 0) && (a1 == 0 && a2 == 0))
  {
    roadCopenc();
  }
  else if ((d1 == 1 && d2 == 0) && (a1 == 0 || a2 == 0) && (b1 == 0 || b2 == 0) && (c1 == 0 || c2 == 0))
  {
    roadDopend();
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if ((a1 == 1 && a2 == 0) && (d1 == 0 || d2 == 0) && (b1 == 0 || b2 == 0) && (c1 == 0 || c2 == 0))
  {
    roadAopena();
  }
  else if ((b1 == 1 && b2 == 0) && (d1 == 0 || d2 == 0) && (a1 == 0 || a2 == 0) && (c1 == 0 || c2 == 0))
  {
    roadBopenb();
  }

  else if ((c1 == 1 && c2 == 0) && (d1 == 0 || d2 == 0) && (b1 == 0 || b2 == 0) && (a1 == 0 || a2 == 0))
  {
    roadCopenc();
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (c1 == 0 && a1 == 0 && d1 == 0 && b1 == 0)
  {
    roadAopena1();
    if (c1 == 0 && a1 == 0 && d1 == 0 && b1 == 0)
    {
      roadBopenb1();
    }
    if (c1 == 0 && a1 == 0 && d1 == 0 && b1 == 0)
    {
      roadCopenc1();
    }
    if (c1 == 0 && a1 == 0 && d1 == 0 && b1 == 0)
    {
      roadDopend1();
    }
  }
}

void readSensor()
{
  a1 = analogRead(A0);
  a2 = analogRead(A1);
  b1 = analogRead(A2);
  b2 = analogRead(A3);
  c1 = analogRead(A4);
  c2 = analogRead(A5);
  d1 = analogRead(A6);
  d2 = analogRead(A7);

  if (a1 < 400) a1 = 1; else a1 = 0; if (a2 < 400) a2 = 1; else a2 = 0;
if (b1 < 400) b1 = 1; else b1 = 0; if (b2 < 400) b2 = 1; else b2 = 0;
if (c1 < 400) c1 = 1; else c1 = 0; if (c2 < 400) c2 = 1; else c2 = 0;
if (d1 < 400) d1 = 1; else d1 = 0; if (d2 < 400) d2 = 1; else d2 = 0;

Serial.print(a1);
Serial.print("\t");
Serial.print(a2);
Serial.print("\t");
Serial.print(b1);
Serial.print("\t");
Serial.print(b2);
Serial.print("\t");
Serial.print(c1);
Serial.print("\t");
Serial.print(c2);
Serial.print("\t");
Serial.print(d1);
Serial.print("\t");
Serial.print(d2);
Serial.println("\t");

}

void roadAopen()
{

  for (int counter = 8; counter >= 2; --counter) 
  {
  digitalWrite(ledA3, LOW);
  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
   Num_Write(counter,22); 
   delay(1000);
  }
  
  digitalWrite(ledA1, LOW);
  
  digitalWrite(22,HIGH); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);  
  digitalWrite(25,HIGH);  
  digitalWrite(26,HIGH);  
  digitalWrite(27,HIGH);  
  digitalWrite(28,HIGH);   // 1

  digitalWrite(ledA2, HIGH);
  delay(1000);

  digitalWrite(22,LOW); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);  
  digitalWrite(25,LOW);  
  digitalWrite(26,LOW);  
  digitalWrite(27,LOW);  
  digitalWrite(28,HIGH); // 0
  
  digitalWrite(ledA2, LOW);
  readSensor();
}

void roadBopen()
{
for (int counterB = 8; counterB >= 2; --counterB){
  

  digitalWrite(ledB3, LOW);
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(counterB,29);
     delay(1000);
}
  digitalWrite(ledB1, LOW);

  digitalWrite(29,HIGH); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);  
  digitalWrite(32,HIGH);  
  digitalWrite(33,HIGH);  
  digitalWrite(34,HIGH);  
  digitalWrite(35,HIGH); //1
  
  digitalWrite(ledB2, HIGH);
  delay(1000);

  digitalWrite(29,LOW); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);  
  digitalWrite(32,LOW);  
  digitalWrite(33,LOW);  
  digitalWrite(34,LOW);  
  digitalWrite(35,HIGH); //0
  
  digitalWrite(ledB2, LOW);
  readSensor();
}

void roadCopen()
{
  for (int counterC = 8; counterC >= 2; --counterC){
  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(counterC,36);
     delay(1000);
  }
  digitalWrite(ledC1, LOW);

  digitalWrite(36,HIGH); 
  digitalWrite(37,LOW);  
  digitalWrite(38,LOW);  
  digitalWrite(39,HIGH);  
  digitalWrite(40,HIGH);  
  digitalWrite(41,HIGH);  
  digitalWrite(42,HIGH); //1
  
  digitalWrite(ledC2, HIGH);
  delay(1000);

  digitalWrite(36,LOW); 
  digitalWrite(37,LOW);  
  digitalWrite(38,LOW);  
  digitalWrite(39,LOW);  
  digitalWrite(40,LOW);  
  digitalWrite(41,LOW);  
  digitalWrite(42,HIGH); //0
  
  digitalWrite(ledC2, LOW);
  readSensor();
}

void roadDopen()
{
  for (int counterD = 8; counterD >= 2; --counterD){
  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  Num_Write(counterD,43);
     delay(1000);
  }
  digitalWrite(ledD1, LOW);

  digitalWrite(43,HIGH); 
  digitalWrite(44,LOW);  
  digitalWrite(45,LOW);  
  digitalWrite(46,HIGH);  
  digitalWrite(47,HIGH);  
  digitalWrite(48,HIGH);  
  digitalWrite(49,HIGH); //1
  
  digitalWrite(ledD2, HIGH);
  delay(1000);

  digitalWrite(43,LOW); 
  digitalWrite(44,LOW);  
  digitalWrite(45,LOW);  
  digitalWrite(46,LOW);  
  digitalWrite(47,LOW);  
  digitalWrite(48,LOW);  
  digitalWrite(49,HIGH); //0
  
  digitalWrite(ledD2, LOW);
  readSensor();
}

void roadAopena()
{
  for (int cA = 5; cA >= 2; --cA){
  digitalWrite(ledA3, LOW);

  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(cA,22);
     delay(1000);
  }
 
  digitalWrite(ledA1, LOW);
  
  digitalWrite(22,HIGH); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);  
  digitalWrite(25,HIGH);  
  digitalWrite(26,HIGH);  
  digitalWrite(27,HIGH);  
  digitalWrite(28,HIGH);   // 1

  digitalWrite(ledA2, HIGH);
  delay(1000);

  digitalWrite(22,LOW); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);  
  digitalWrite(25,LOW);  
  digitalWrite(26,LOW);  
  digitalWrite(27,LOW);  
  digitalWrite(28,HIGH); // 0
  
  digitalWrite(ledA2, LOW);
  readSensor();
}

void roadBopenb()
{
  for (int cB = 5; cB >= 2; --cB){
  digitalWrite(ledB3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(cB,29);
     delay(1000);
  }
  digitalWrite(ledB1, LOW);

  digitalWrite(29,HIGH); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);  
  digitalWrite(32,HIGH);  
  digitalWrite(33,HIGH);  
  digitalWrite(34,HIGH);  
  digitalWrite(35,HIGH); //1
  
  digitalWrite(ledB2, HIGH);
  delay(1000);

  digitalWrite(29,LOW); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);  
  digitalWrite(32,LOW);  
  digitalWrite(33,LOW);  
  digitalWrite(34,LOW);  
  digitalWrite(35,HIGH); //0
  
  digitalWrite(ledB2, LOW);
  readSensor();
}

void roadCopenc()
{
  for (int cC = 5; cC >= 2; --cC){
  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(cC,36);
     delay(1000);
  }
  digitalWrite(ledC1, LOW);

  digitalWrite(36,HIGH); 
  digitalWrite(37,LOW);  
  digitalWrite(38,LOW);  
  digitalWrite(39,HIGH);  
  digitalWrite(40,HIGH);  
  digitalWrite(41,HIGH);  
  digitalWrite(42,HIGH); //1
  
  digitalWrite(ledC2, HIGH);
  delay(1000);

  digitalWrite(36,LOW); 
  digitalWrite(37,LOW);  
  digitalWrite(38,LOW);  
  digitalWrite(39,LOW);  
  digitalWrite(40,LOW);  
  digitalWrite(41,LOW);  
  digitalWrite(42,HIGH); //0
  
  digitalWrite(ledC2, LOW);
  readSensor();
}

void roadDopend()
{
  for (int cD = 5; cD >= 2; --cD){
  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  Num_Write(cD,43);
     delay(1000);
  }
  digitalWrite(ledD1, LOW);

  digitalWrite(43,HIGH); 
  digitalWrite(44,LOW);  
  digitalWrite(45,LOW);  
  digitalWrite(46,HIGH);  
  digitalWrite(47,HIGH);  
  digitalWrite(48,HIGH);  
  digitalWrite(49,HIGH); //1
  
  digitalWrite(ledD2, HIGH);
  delay(1000);

  digitalWrite(43,LOW); 
  digitalWrite(44,LOW);  
  digitalWrite(45,LOW);  
  digitalWrite(46,LOW);  
  digitalWrite(47,LOW);  
  digitalWrite(48,LOW);  
  digitalWrite(49,HIGH); //0
  
  digitalWrite(ledD2, LOW);
  readSensor();
}

void Num_Write(int number, int p) 
{
  int pin= p;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[number][j]);
   pin++;
  }
}

/////default mode with 5 sec

void roadAopena1()
{
  for (int cA1 = 3; cA1 >= 2; --cA1){
  digitalWrite(ledA3, LOW);

  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(cA1,22);
     delay(1000);
  }
digitalWrite(ledA1, LOW);
  
  digitalWrite(22,HIGH); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);  
  digitalWrite(25,HIGH);  
  digitalWrite(26,HIGH);  
  digitalWrite(27,HIGH);  
  digitalWrite(28,HIGH);   // 1

  digitalWrite(ledA2, HIGH);
  delay(1000);

  digitalWrite(22,LOW); 
  digitalWrite(23,LOW);  
  digitalWrite(24,LOW);  
  digitalWrite(25,LOW);  
  digitalWrite(26,LOW);  
  digitalWrite(27,LOW);  
  digitalWrite(28,HIGH); // 0
  
  digitalWrite(ledA2, LOW);
  readSensor();
}

void roadBopenb1()
{
  for (int cB1 = 3; cB1 >= 2; --cB1){
  digitalWrite(ledB3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(cB1,29);
     delay(1000);
  }
  digitalWrite(ledB1, LOW);

  digitalWrite(29,HIGH); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);  
  digitalWrite(32,HIGH);  
  digitalWrite(33,HIGH);  
  digitalWrite(34,HIGH);  
  digitalWrite(35,HIGH); //1
  
  digitalWrite(ledB2, HIGH);
  delay(1000);

  digitalWrite(29,LOW); 
  digitalWrite(30,LOW);  
  digitalWrite(31,LOW);  
  digitalWrite(32,LOW);  
  digitalWrite(33,LOW);  
  digitalWrite(34,LOW);  
  digitalWrite(35,HIGH); //0
  
  digitalWrite(ledB2, LOW);
  readSensor();
}

void roadCopenc1()
{
  for (int cC1 = 3; cC1 >= 2; --cC1){
  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  Num_Write(cC1,36);
     delay(1000);
  }
  digitalWrite(ledC1, LOW);

  digitalWrite(36,HIGH); 
  digitalWrite(37,LOW);  
  digitalWrite(38,LOW);  
  digitalWrite(39,HIGH);  
  digitalWrite(40,HIGH);  
  digitalWrite(41,HIGH);  
  digitalWrite(42,HIGH); //1
  
  digitalWrite(ledC2, HIGH);
  delay(1000);

  digitalWrite(36,LOW); 
  digitalWrite(37,LOW);  
  digitalWrite(38,LOW);  
  digitalWrite(39,LOW);  
  digitalWrite(40,LOW);  
  digitalWrite(41,LOW);  
  digitalWrite(42,HIGH); //0
  
  digitalWrite(ledC2, LOW);
  readSensor();
}

void roadDopend1()
{
  for (int cD1 = 3; cD1 >= 2; --cD1){
  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  Num_Write(cD1,43);
     delay(1000);
  }
  digitalWrite(ledD1, LOW);

  digitalWrite(43,HIGH); 
  digitalWrite(44,LOW);  
  digitalWrite(45,LOW);  
  digitalWrite(46,HIGH);  
  digitalWrite(47,HIGH);  
  digitalWrite(48,HIGH);  
  digitalWrite(49,HIGH); //1
  
  digitalWrite(ledD2, HIGH);
  delay(1000);

  digitalWrite(43,LOW); 
  digitalWrite(44,LOW);  
  digitalWrite(45,LOW);  
  digitalWrite(46,LOW);  
  digitalWrite(47,LOW);  
  digitalWrite(48,LOW);  
  digitalWrite(49,HIGH); //0
  
  digitalWrite(ledD2, LOW);
  readSensor();
}

void Num_Write1(int number, int p) 
{
  int pin= p;
  for (int j=0; j < 7; j++) {
   digitalWrite(pin, num_array[number][j]);
   pin++;
  }
}
