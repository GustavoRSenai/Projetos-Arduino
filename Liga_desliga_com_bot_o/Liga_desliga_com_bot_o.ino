// C++ code
//
// declaração de variante
int anterior = 0;
int valor;
int estado = LOW;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop()
{
  valor = digitalRead(12);
  if (valor == HIGH && anterior == LOW){ // cita o valor necessario para variante ser ativa
    estado=! estado;
       
  }
  digitalWrite(13,estado);
    anterior = valor;
    delay(50);
  valor = 0;
   
  
}
