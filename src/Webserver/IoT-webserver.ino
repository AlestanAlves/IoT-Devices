#include <WiFi.h>

const char* ssid = "xxxx";
const char* password = "xxxx";
WiFiServer server(80);
String recebe_dados;
String estado_do_pino_2 = "off";
const int porta_2 = 2;

void setup() {
  Serial.begin(115200);
  pinMode(porta_2, OUTPUT);
  digitalWrite(porta_2, LOW);
  Serial.print("Conectando em: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("tentativa...");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("No IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
void loop() {
  WiFiClient client = server.available(); 
    if (client) {
      Serial.println("Novo cliente conectou no ESP.");
      String linha_atual = "";
      while (client.connected()) {
        if (client.available()) {
          char c = client.read();
          Serial.write(c);
          recebe_dados += c;
          if (c == '\n') {
            if (linha_atual.length() == 0) {
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println("Connection: close");
              client.println();
              if (recebe_dados.indexOf("GET /LED/on") >= 0) {
                Serial.println("GPIO 2 on");
                estado_do_pino_2 = "on";
                digitalWrite(porta_2, HIGH);
              }
              else if (recebe_dados.indexOf("GET /LED/off") >= 0) {
                Serial.println("GPIO 2 off");
                estado_do_pino_2 = "off";
                digitalWrite(porta_2, LOW);
              }
              client.println("<!DOCTYPE html><html>");
              client.println("<head><title>Curso ESP32 IoT</title><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><meta charset=\"utf-8\" />");
              client.println("<link rel=\"icon\" href=\"data:,\">");
              client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
              client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;box-shadow:5px 5px 7px;");
              client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
              client.println(".button2 {background-color: #555555;box-shadow:7px 7px 8px #ffd800;}</style></head>");
              client.println("<body><h1>Curso de ESP32 com IoT</h1><br><h2>  Centro Paula Souza</h2><br>");
              client.println("<p>LED na Porta D2 - Status: " + estado_do_pino_2 + "</p>");
              if (estado_do_pino_2 == "off") {
                client.println("<p><a href=\"/LED/on\"><button class=\"button\">ON</button></a></p>");
              }
              else {
                client.println("<p><a href=\"/LED/off\"><button class=\"button button2\">OFF</button></a></p>");
              }
              client.println("<span style=\"font-size:12px;color:#121ab2;margin-top:30%;\">By Prof. Jean</span></body></html>");
              client.println();
              break;
            }
            else {
              linha_atual = "";
            }
          }
          else if (c != '\r') {
            linha_atual += c;
          }
        }
      }
      recebe_dados = "";
      client.stop();
      Serial.println("Cliente desconectou.");
      Serial.println("");
    }
}
