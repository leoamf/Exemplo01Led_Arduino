int cont =100;
int pinoOut = 10;
int pinoIn = 0;
String texto;
int luz = 0, luzAnterior = 0;

void setup() {
  // put your setup code here, to run once:   
  pinMode(pinoOut,OUTPUT);
  pinMode(pinoIn,INPUT);
  Serial.begin(9600);
  texto = "";
}

void loop() {
  
  if(Serial.available())
  {
    char c = Serial.read();
    delay(10);
    texto = texto + c;
  }
  
  else if(texto != "")
  {
    //Serial.println("Recebi:" + texto);
    cont = texto.toInt();
    texto = "";
  }
  analogWrite(pinoOut, cont);
  luz = analogRead(pinoIn); 
  if(luzAnterior != luz){
    luzAnterior = luz;
   // Serial.println("Luz:" + luz);
    Serial.println( luz);
    delay(1000);
  }
  
  
    
  /*digitalWrite(pinoOut,HIGH);   
  delay(cont); //Tempo em alta
  if(cont >50)
    cont =0;
  digitalWrite(pinoOut,LOW);//Tempo Em baixa
  delay(5);*/ 
}
