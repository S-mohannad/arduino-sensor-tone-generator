int max=0,min=1023;
int f;
void setup() {
pinMode(10,OUTPUT);
while(millis()<10000){
max=max(max,analogRead(A0));
min=min(min,analogRead(A0));}
}
void loop() {
int x=analogRead(A0);
x=constrain(x,min,max); 
f=map(x,min,max,200,400);
tone(10,f,100);
delay(100);
}