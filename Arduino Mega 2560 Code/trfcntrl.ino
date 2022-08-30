/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/



// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

}

// the loop function runs over and over again forever
void loop() { 
  while ( Serial.available()){
  String p[10];                // msg starts with # and ends with '\n', with parms sre delemited by #
  String y = Serial.readStringUntil('\n') + "\n";
  int i = 1;
  int j = 0;
  String r = "#Invalid Msg Format\n";
  
  if ( y.charAt(0) == '#' ) {
    do {
      int k = y.indexOf('#',i);
      p[j++] = y.substring(i,k);
      i = k + 1;  
    } while ( y.charAt(i) != '\n');
    if ( p[0].charAt(0) == '0' ) {
      r = "#ok " + onoff(p,++j) + "\n";

//      r="#ok\n";
    } else {
        if ( p[0].charAt(0) == '1' ) {
           r = "#" + readsensor(p[1]) + "\n";
        } else 
            r = "#Invalid Function Code Received\n"; 
    }
   } 
  
    char* buf = (char*) malloc(sizeof(char) * r.length() + 1);
    r.toCharArray(buf, r.length() + 1);  
    Serial.write(buf);
    free(buf);
  }   
  
}

    
String onoff ( String p[], int x ) {
  int l = 1;
  String o = "";
  do {
    int i = 0;
    int j = 0;
    String q[] = {"","","","",""};
    int maxe=3;
    do {                            //   pin no, on(O) or off (F), deley (milli seconds ),
      int k = p[l].indexOf(',',i);
      q[j++] = p[l].substring(i,k);
      if ( ( j == 2 ) &&  ( q[1].charAt(0) == 'B' ) )
        maxe = 5;
      i = k + 1;  
    } while ( j < maxe );

    int dly = q[2].toInt();
    if ( dly > 0 )
      delay(dly);    
    int pinno = q[0].toInt();
    char fc = q[1].charAt(0);
    if ( fc == 'O' or fc == 'F') {
      o = o +  q[0] + "  " + q[1] + "  " + q[2];
      pinMode(pinno, OUTPUT);  
      if ( fc =='O')
        digitalWrite(pinno, HIGH);  
      else
        digitalWrite(pinno, LOW);
    } else {
        o = o +  q[0] + "  " + q[1] + "  " + q[2] + "  " + q[3] + "  " + q[4];
        unsigned long time = millis()+ q[4].toInt();
        int bf = q[3].toInt(); 
        pinMode(pinno, OUTPUT); 
        do {
          digitalWrite(pinno, HIGH);
          delay(bf);
          digitalWrite(pinno, LOW);
          delay(bf);
        } while ( millis() < time );
 
    }
    l++;
       
  } while ( l < x );

  return o;   
}

String readsensor( String p ) {
  int i = 0;
  int j = 0;
  /*
     pin no,wait until next read, read until time elaps
     returns sensor values delemited by ","
  */
  String q[] = { " ", " ", " ", " " } ;                
  do {
      int k = p.indexOf(',',i);
      q[j++] = p.substring(i,k);
      i = k + 1;
      if ( i +1 > p.length() ) {
        break;
      }    } while ( j  < 4  );

     
//  int spinno= q[0].toInt();     
  int s[] = {54,55,56,57,58,59,60,61,62};
  int si = q[0].substring(1,2).toInt();
  int spinno=s[si];
  int rdelay = q[1].toInt();      
  
  pinMode(spinno, INPUT);  
  String sv = "";  
  unsigned long time = millis()+ q[2].toInt();
  
  String rok = "0";
  do {
    int srv = analogRead(spinno);
    sv = sv + srv + ",";
    if  ( ( q[3].charAt(0) != ' ' ) && ( srv >= q[3].toInt() )  ){
      rok = "1";
      break;
    }  
    delay(rdelay);
  } while ( millis() < time );
 
  if ( q[3].charAt(0) != ' ' )  
    return rok + "#" + sv;  
  else
    return sv;  
}
