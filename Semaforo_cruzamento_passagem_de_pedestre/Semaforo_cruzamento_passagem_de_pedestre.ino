//definição das leds verdes:
#define ver_ped1 11
#define ver_ped2 4
#define ver_car1 10
#define ver_car2 5

//definiçãop das leds vermelhas:
#define verm_ped1 12 
#define verm_ped2 2
#define verm_car1 8
#define verm_car2 3

 //definição das leds amarelas:
#define ama_car1 9
#define ama_car2 6

//definição dos botões:
#define botao1 7
#define botao2 13

//definição das variaveis:

//definição do valor do botão:
int botao = 0;

//foram definidos os tempos entre as funções do semaforo:
int t1 = 10000; //10s
int t2 = 500; // 0.5s

//foram definidas variaveis para a função while:
int v1 = 0; 
int v2 = 0; 
//foram definidas variaveis para identificar o estado dos botoes
int estadoBotao1 = 0; 
int estadoBotao2 = 0;
//definidas variaveis long(que sao variaveis de tamanho extendido)
long tempo = 0; // conta em ms quanto tempo o programa esta rodando
long ultimoTempo = 0; // registra tempo que algo começou para calcular o Delta (tempo - ultimoTempo)


void setup()
{
  //foram definidas as portas dos leds como saida:
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  //foi definida as portas dos botoes como entrada:
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  Serial.begin(9600);
}

void fechamento_seguranca2(){
  
   digitalWrite(ver_ped2, LOW);
     while (v2<2){
      digitalWrite(verm_ped2, LOW);
      delay(t2);
      digitalWrite(verm_ped2, HIGH);
      delay(t2);
      digitalWrite(verm_ped2, LOW); //semaforo de pedestres 1 piscante para o aviso de fechamento
      delay(t2);
      digitalWrite(verm_ped2, HIGH);
      delay(t2);
      digitalWrite(verm_ped2, LOW);
      delay(t2);
      digitalWrite(verm_ped2, HIGH);
       delay(t2);
      v2 = v2 + 1;
    }
  v2 = v2 - 2;
}

void fechamento_seguranca1(){
   digitalWrite(ver_ped1, LOW);//verde1 off
     while (v1<2){
      digitalWrite(verm_ped1, LOW);
      delay(t2);
      digitalWrite(verm_ped1, HIGH);
      delay(t2);
      digitalWrite(verm_ped1, LOW); //semaforo de pedestres 1 piscante para o aviso de fechamento
      delay(t2);
      digitalWrite(verm_ped1, HIGH);
      delay(t2);
      digitalWrite(verm_ped1, LOW);
      delay(t2);
      digitalWrite(verm_ped1, HIGH);
       delay(t2);
      v1 = v1 + 1;
    }
  v1 = v1 - 2;
}
  
void loop(){
  
  // 1º semaforo 1 verde
  digitalWrite(ver_car1, HIGH);//verde1 on
  digitalWrite(verm_car1, LOW);//vermelho1 off
  digitalWrite(ama_car1, LOW);//amarelo1 off
  
  digitalWrite(verm_ped1, HIGH);//vemelho_ped1 on
  digitalWrite(ver_ped1, LOW);//verde_ped1 off
  
  // 1º semaforo 2 vermelho
   digitalWrite(verm_car2, HIGH);//vermelho2 on
   digitalWrite(ver_car2, LOW);//verde2 off
  digitalWrite(ama_car2, LOW);//amarelo2 off
  
  digitalWrite(verm_ped2, LOW);//vemelho_ped2 off
  digitalWrite(ver_ped2, HIGH);//verde_ped2 on
  
  ultimoTempo = millis(); // sistem botao1 semaforo 1
  estadoBotao1 = digitalRead(botao1);
  while ((tempo - ultimoTempo < 10000) && estadoBotao1 == 0)// conte ate 10s porem se o botao for precionado pare de contar
  {
    tempo = millis();
    estadoBotao1 = digitalRead(botao1);
     Serial.println(estadoBotao1);
  }
  
  // 2º semaforo 1 amarelo
  digitalWrite(ver_car1, LOW);//verde1 off
  digitalWrite(verm_car1, LOW);//vermelho1 off
  digitalWrite(ama_car1, HIGH);//amarelo1 on
  
  digitalWrite(verm_ped1, HIGH);//vemelho_ped1 on
  digitalWrite(ver_ped1, LOW);//verde_ped1 off
  
  fechamento_seguranca2();//fechamento
  
  // 3º semaforo 1 Vermelho
  digitalWrite(ver_car1, LOW);//verde1 off
  digitalWrite(verm_car1, HIGH);//vermelho1 on
  digitalWrite(ama_car1, LOW);//amarelo1 off
  
  digitalWrite(verm_ped1, LOW);//vemelho_ped1 off
  digitalWrite(ver_ped1, HIGH);//verde_ped1 on

  
  // 2º semaforo 2 verde
   digitalWrite(verm_car2, LOW);//vermelho2 off
   digitalWrite(ver_car2, HIGH);//verde2 on
  digitalWrite(ama_car2, LOW);//amarelo2 off
  
  digitalWrite(verm_ped2, HIGH);//vemelho_ped2 on
  digitalWrite(ver_ped2, LOW);//verde_ped2 off
  
  ultimoTempo = millis(); // sistem botao2 semaforo 2
  estadoBotao2 = digitalRead(botao1);
  while ((tempo - ultimoTempo < 10000) && estadoBotao2 == 0)// conte ate 10s porem se o botao for precionado pare de contar
  {
    tempo = millis();
    estadoBotao2 = digitalRead(botao2);
     Serial.println(estadoBotao2);
  }
  
  
  // 3º semaforo 2 amarelo
   digitalWrite(verm_car2, LOW);//vermelho2 off
   digitalWrite(ver_car2, LOW);//verde2 off
  digitalWrite(ama_car2, HIGH);//amarelo2 on
  
  digitalWrite(verm_ped2, HIGH);//vemelho_ped2 on
  digitalWrite(ver_ped2, LOW);//verde_ped2 off
  
  fechamento_seguranca1();
  }
 
