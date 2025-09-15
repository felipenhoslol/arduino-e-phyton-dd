// incluindo as bibliotecas utilizadas
#include <DHT11.h>
#include <Servo.h>

// definindo as entradas de cada componente utilizado
int const sensorTemperatura = 3;
int const entradaMotor = 9;
int const botaoAbrir = 5;
int const botaoFechar = 6;
int const alertaSonoro = 12;

// definindo o grau de abertura do motor
int const abertura_0 = 0;
int const abertura_25 = 45;
int const abertura_50 = 90;
int const abertura_75 = 135;
int const abertura_100 = 180;

// definindo a classe das bibliotecas
Servo motor;
DHT11 sensor(sensorTemperatura);

void setup()
{
  pinMode(botaoAbrir, INPUT_PULLUP);
  pinMode(botaoFechar, INPUT_PULLUP);

  motor.attach(entradaMotor);

  Serial.begin(9600);

  motor.write(abertura_0); // iniciar o motor na abertura 0%
}

void loop() {
  int temperatura = sensor.readTemperature(); // leitura do sensor de temperatura

  Serial.print("Temperatura atual: ");
  Serial.print(temperatura);
  Serial.print("\n");

  if(temperatura > 28){
    motor.write(abertura_100);
    digitalWrite(alertaSonoro, HIGH);
    delay(200);
    digitalWrite(alertaSonoro, LOW);
    delay(200);
  }

  if(temperatura > 26 && temperatura <= 28){
    motor.write(abertura_100);
  }

  if(temperatura > 24 && temperatura <= 26){
    motor.write(abertura_75);
  }

  if(temperatura > 20 && temperatura <= 24) {
    motor.write(abertura_50);
  }

  if(temperatura > 18 && temperatura <= 20){
    motor.write(abertura_25);
  }

  if(temperatura > 16 && temperatura <= 18){
    motor.write(abertura_0);
  }

  if(temperatura < 16){
    motor.write(abertura_0);
    digitalWrite(alertaSonoro, HIGH);
    delay(200);
    digitalWrite(alertaSonoro, LOW);
    delay(200);
  }

  delay(200);
}