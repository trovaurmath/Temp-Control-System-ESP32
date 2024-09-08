#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include "DHT.h"

// Definições do sensor DHT
#define DHTPIN 4      // Pino onde o sensor de temperatura está conectado
#define DHTTYPE DHT22 // Tipo de sensor (DHT11 ou DHT22)
DHT dht(DHTPIN, DHTTYPE);

// Função para configurar o sensor DHT
void setupSensor() {
    dht.begin(); // Inicializa o sensor de temperatura e umidade
}

// Função para ler a temperatura do sensor
float readTemperature() {
    float temp = dht.readTemperature();
    if (isnan(temp)) {
        Serial.println("Falha ao ler a temperatura!");
        return 0.0; // Retorna um valor padrão em caso de falha
    }
    return temp;
}

// Função para ler a umidade do sensor
float readHumidity() {
    float hum = dht.readHumidity();
    if (isnan(hum)) {
        Serial.println("Falha ao ler a umidade!");
        return 0.0; // Retorna um valor padrão em caso de falha
    }
    return hum;
}

#endif
