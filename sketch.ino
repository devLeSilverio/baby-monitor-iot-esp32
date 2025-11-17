// Baby Monitor - ESP32 com Potenciômetro

#include <WiFi.h>
#include <WiFiClientSecure.h>

int buzzerPin = 35;  // GPIO 13
int ledPin = 33;     // GPIO 12
int potPin = 32;     // GPIO 34 (somente entrada analógica)
const char* telegramToken = "";
const char* chatID = "";

int threshold = 2000; // Limiar (0-4095 no ESP32)

WiFiClientSecure client;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
  Serial.println("Baby Monitor ESP32 Iniciado!");

  Serial.begin(9600);
  Serial.print("Conectando-se ao Wi-Fi");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Conectado!");

  client.setInsecure();
}

void loop() {
  int value = analogRead(potPin);
  Serial.print("Nivel: ");
  Serial.println(value);

  if (value > threshold) {
    if (client.connect("api.telegram.org", 443)) {
    String mensagem = "Olá! Seu BB está chorando hein... 🚀";
    String url = "/bot" + String(telegramToken) + "/sendMessage?chat_id=" + chatID + "&text=" + mensagem;

    client.println("GET " + url + " HTTP/1.1");
    client.println("Host: api.telegram.org");
    client.println("Connection: close");
    client.println();

    while (client.connected()) {
      String linha = client.readStringUntil('\n');
      if (linha == "\r") break;
    }
      Serial.println("Mensagem enviada!");
    } else {
      Serial.println("Falha na conexão com Telegram");
    }

    Serial.println("⚠️ Bebê chorando!!!");
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    delay(150);

    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(150);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(200);
  }
}

