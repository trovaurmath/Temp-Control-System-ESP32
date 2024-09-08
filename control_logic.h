#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

// Definindo os pinos de controle
#define FAN_PIN 5       // Pino do ventilador
#define HEATER_PIN 6    // Pino do aquecedor

// Limites de temperatura
#define TEMP_THRESHOLD_LOW 18.0   // Temperatura mínima para ligar o aquecedor
#define TEMP_THRESHOLD_HIGH 26.0  // Temperatura máxima para ligar o ventilador

// Função de configuração dos dispositivos de controle
void setupControl() {
    pinMode(FAN_PIN, OUTPUT);
    pinMode(HEATER_PIN, OUTPUT);
    digitalWrite(FAN_PIN, LOW);    // Desliga o ventilador inicialmente
    digitalWrite(HEATER_PIN, LOW); // Desliga o aquecedor inicialmente
}

// Função para controlar os dispositivos com base na temperatura
void controlDevices(float temperatura) {
    if (temperatura <= TEMP_THRESHOLD_LOW) {
        // Ligar aquecedor se a temperatura estiver abaixo do limite mínimo
        digitalWrite(HEATER_PIN, HIGH);
        digitalWrite(FAN_PIN, LOW);
        Serial.println("Aquecedor Ligado");
    } else if (temperatura >= TEMP_THRESHOLD_HIGH) {
        // Ligar ventilador se a temperatura estiver acima do limite máximo
        digitalWrite(FAN_PIN, HIGH);
        digitalWrite(HEATER_PIN, LOW);
        Serial.println("Ventilador Ligado");
    } else {
        // Se estiver dentro do intervalo ideal, desligar ambos
        digitalWrite(FAN_PIN, LOW);
        digitalWrite(HEATER_PIN, LOW);
        Serial.println("Todos os dispositivos desligados");
    }
}

#endif
