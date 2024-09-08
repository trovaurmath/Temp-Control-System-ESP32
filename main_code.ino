#include "DHT.h"
#include "control_logic.h"
#include "wifi_connection.h"
#include "display_output.h"

// Definindo pinos
#define DHTPIN 4      // Pino onde o sensor de temperatura está conectado
#define DHTTYPE DHT22 // Definindo o tipo do sensor (DHT11 ou DHT22)
DHT dht(DHTPIN, DHTTYPE);

// Variáveis globais
float temperatura = 0.0;
float umidade = 0.0;

void setup() {
  Serial.begin(115200);
  dht.begin(); // Inicializa o sensor DHT
  
  setupControl(); // Configura os relés de controle
  setupWiFi();    // Configura a conexão Wi-Fi
  setupDisplay(); // Configura o display
}

void loop() {
  // Leitura da temperatura e umidade
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler do sensor DHT!");
    return;
  }
  
  // Controle de dispositivos baseado na temperatura
  controlDevices(temperatura);
  
  // Atualizar a interface do display
  updateDisplay(temperatura, umidade);
  
  // Enviar dados pela conexão Wi-Fi
  sendTemperatureData(temperatura, umidade);
  
  delay(2000); // Delay de 2 segundos entre as leituras
}
