String firstname;
const int x=10;
#define ledpin 13
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(ledpin,OUTPUT);
 Serial.begin(9600);
  firstname ="yashraj";
 delay(1000);
Serial.println(firstname);
delay(1000);
Serial.println(x);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=analogRead(A0);

Serial.println(val);
if(val<50)
{
  digitalWrite(ledpin,HIGH);

}
else
{
  digitalWrite(ledpin,LOW);
}


 delay(1000);
}
