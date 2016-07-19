/* THEREMUN de LUZ
3 sensores LDR sensan la cantidad de luz ambiente.
alejando o acercando las manos se logra controlar un LED RGB, cada LDR un color.
Así se emula al instrumento musical logrando la mezcla de colores primarios para la luz
Flavio Ragazzi 2016
*/
int Min =1023;
int MAX= 0;
int minimoR=Min;
int maximoR=MAX;

int minimoV=Min;
int maximoV=MAX;

int minimoA=Min;
int maximoA=MAX;

int sensorA0;
int sensorA1;
int sensorA2;





void setup(){
pinMode(9,OUTPUT);     //led verde
pinMode(10,OUTPUT);    //led azul
pinMode(11,OUTPUT);  //led ROJO
Serial.begin(9600);

digitalWrite(11,HIGH); //señal para calibrado 
while (millis()<10000){
sensorA0= analogRead(A0);
if(sensorA0>maximoR){
  maximoR=sensorA0;
}
if(sensorA0<minimoR){
minimoR=sensorA0;
}
sensorA1= analogRead(A1);
if(sensorA1>maximoA){
  maximoA=sensorA1;
}
if(sensorA1<minimoA){
minimoA=sensorA1;
}
sensorA2= analogRead(A2);
if(sensorA2>maximoV){
  maximoV=sensorA2;
}
if(sensorA2<minimoV){
minimoV=sensorA2;
}

}
digitalWrite(11,LOW); //fin calibrado 


Serial.print("MAX rojo=  ");
Serial.print(maximoR);
Serial.print("....");
Serial.print("Min rojo=  ");
Serial.println(minimoR);
Serial.print("MAX verde=  ");
Serial.print(maximoV);
Serial.print("....");
Serial.print("Min verde=  ");
Serial.println(minimoV);
Serial.print("MAX azul=  ");
Serial.print(maximoA);
Serial.print("....");
Serial.print("Min azul=  ");
Serial.println(minimoA);

}

void loop(){
//salida rojo
  int lecturaR=analogRead(A0);
int salidaR = constrain(lecturaR,maximoR,minimoR);
//Serial.println(salidaR);

salidaR=map(salidaR,minimoR,maximoR,0,255);
analogWrite (11,salidaR);
//salida azul
int lecturaA=analogRead(A1);
int salidaA = constrain(lecturaA,maximoA,minimoA);
Serial.println(salidaA);

salidaA=map(salidaA,minimoA,maximoA,0,255);
analogWrite (10,salidaA);
//salida verde
int lecturaV=analogRead(A2);
int salidaV = constrain(lecturaV,maximoV,minimoV);
//Serial.println(salidaV);

salidaV=map(salidaV,minimoV,maximoV,0,255);
analogWrite (9,salidaV);



}
