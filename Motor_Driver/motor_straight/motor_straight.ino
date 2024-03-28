int rms=10;
int rmf=8;
int rmb=13;

int lms=9;
int lmf=12;
int lmb=11;

void setup() {
 pinMode(rmf,OUTPUT);
 pinMode(rmb,OUTPUT);
 pinMode(lmf,OUTPUT);
 pinMode(lmb,OUTPUT);
 pinMode(rms,OUTPUT);
 pinMode(lms,OUTPUT);
}

void loop() {
       
       
       digitalWrite(rmf,HIGH);
       digitalWrite(rmb,LOW); 

       digitalWrite(lmf,HIGH);
       digitalWrite(lmb,LOW);
       
       analogWrite(rms,255);
       analogWrite(lms,255);

}
