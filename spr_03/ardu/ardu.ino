#include <ArduinoJson.h>
#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 5 // Pino ao qual o sensor DHT22 está conectado
#define DHTTYPE DHT22 // Tipo do sensor DHT (DHT22 ou DHT11)

DHT dht(DHTPIN, DHTTYPE);

int AlertaTempBaixa = 8;
int AlertaTempAlta = 13;
int TempBaixa = 0;
int TempAlta = 35;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  pinMode(AlertaTempBaixa, OUTPUT);
  pinMode(AlertaTempAlta, OUTPUT);

  dht.begin();

  lcd.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");
  lcd.setCursor(0, 1);
  lcd.print("Umidade:");
  
  // Inicializar a comunicação serial com uma taxa de 9600 bps
  Serial.begin(9600);
}

void loop() {
  float temperaturaC = dht.readTemperature();
  float umidadePercent = dht.readHumidity();

  // Exibir leituras no LCD
  lcd.setCursor(13, 0); // Define a posição do cursor no LCD
  lcd.print("    "); // Limpa o espaço antigo
  lcd.setCursor(13, 0);
  lcd.print(temperaturaC);
  
  lcd.setCursor(8, 1); // Define a posição do cursor no LCD
  lcd.print("    "); // Limpa o espaço antigo
  lcd.setCursor(8, 1);
  lcd.print(umidadePercent);

  // Enviar as leituras para o Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.print("°C, Umidade: ");
  Serial.print(umidadePercent);
  Serial.println("%");

  if (temperaturaC >= TempAlta) {
    digitalWrite(AlertaTempBaixa, LOW);
    digitalWrite(AlertaTempAlta, HIGH);
  } else if (temperaturaC <= TempBaixa) {
    digitalWrite(AlertaTempBaixa, HIGH);
    digitalWrite(AlertaTempAlta, LOW);
  } else {
    digitalWrite(AlertaTempBaixa, LOW);
    digitalWrite(AlertaTempAlta, LOW);
  }

  delay(1000);
}
