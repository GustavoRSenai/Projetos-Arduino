
// programa para piscar 2 leds ao mesmo tempo

void setup() {
  // put your setup code here, to run once:
// Definir portas 7 e 6 como saida
pinMode(7,OUTPUT)
pinMode(6,OUTPUT)
}

void loop() {
  // put your main code here, to run repeatedly:
// manda sinal alto para porta 7e6 acendendo a led
digitalWrite(7,HIGH);
digitalWrite(6,HIGH);
delay(1000); // espera 1 segundo
// manda sinal baixo para as portas 7 e 6
digitalWrite(7,LOW);
digitalWrite(6,LOW);
delay(1000);
}
