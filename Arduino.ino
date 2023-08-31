#include "Ultrasonic.h"
//importanto a biblioteca do sensor 

//definindo as entradas e saidas dos prinos 
const int echoPin = 5;
const int trigPin = 4;
const int relayPinD = A2;
const int relayPinE = A1;

Ultrasonic ultrasonic(trigPin,echoPin); // inicializa os pinos do sensor 
 
int distancia; //criamos uma variavel global para guardar os cm do snesor usanod um valor inteiro
void setup(){ //função setup e inicializa apenas uma vez quando o arduino e ligado ou reiniciaco
  pinMode(echoPin, INPUT); //inicializa o plugin definindo ele como entrada 
  pinMode(trigPin, OUTPUT);// inicializa outro plugin definindo como saida
  pinMode(relayPinE, OUTPUT);
  pinMode(relayPinD, OUTPUT);
  Serial.begin(9600); //inicializa a porta serial
  }
void loop(){//funcão void loop é executada em loop todo o momento que o arduino está rodando

 hcsr04(); //chama a função do
Serial.print("Distancia "); //impimi distancia no terminal
  Serial.print(distancia); //imprimi no terminal a distancia do objeto do carrinho
  Serial.println("cm"); //impimir no monitor do serial

//aqui criamos uma condição que verifica a distancia do carrinhoa te o objeto, caso senha menor ou igual a 45 ele desliga os motore e liga apenas um motor para fazer o contorno.
if(distancia <= 45){
      digitalWrite(relayPinE, LOW);//low seria desligadp (o 0 no binario)
      digitalWrite(relayPinD, LOW);
      digitalWrite(relayPinD, HIGH);// e o High seria logado (o 1 no binario)
      digitalWrite(relayPinE, LOW);


  }else{//aqui é um (caso não) caso a distancia seja maior que 45 ele apenas continua andando 
  digitalWrite(relayPinD, HIGH);
  digitalWrite(relayPinE, HIGH);
  }
  
}
//funcão que calcula a dinstancia do sensor ate o obj
void hcsr04(){
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); //espera 2 microsegundos antes de enviar o pulso 
    digitalWrite(trigPin, HIGH); //envia o pulso para o pino trigPin com u de 5V iniciando o pulso sonoro
    delayMicroseconds(10); //espera 10 micro segubndo, esse e o tempo que o pulso e enviado.
    digitalWrite(trigPin, LOW); //envioa um sinal low para terminar o pulso
    distancia = (ultrasonic.Ranging(CM)); //varivael global que recebe o resultado com a distancia do sensor ate o objeto que o pulso bateu e voltou.
 }
