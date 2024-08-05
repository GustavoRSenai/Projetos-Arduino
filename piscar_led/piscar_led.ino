//programação para piscar led
//manda sinal forte para saida 7
//aguarda 1 segundo
//envia sinal baixo para a saida 7

void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT)  //porta 7 para definir led como saida

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(7,HIGH);//sinal alto
delay(1000);//espere 1 segundo
digitalWrite(7,LOW);//sinal baixo
delay(1000);//espere 1 segundo
}
