# BabyMonitor IoT – ESP32 Cry Alert  
Monitor de choro com ESP32, LED, buzzer e notificações via Telegram.

## 👥 Integrantes do Grupo
- Letícia Silverio
- Henrique Martins
- João Victor


## 📌 Descrição do Projeto
BabyMonitor IoT é um sistema embarcado utilizando o NodeMCU ESP32 para monitorar o nível de som simulado por um potenciômetro.  
Quando o valor ultrapassa um limiar configurado, o sistema:

- Aciona um LED (alerta visual)
- Liga o buzzer (alerta sonoro)
- Envia uma notificação ao Telegram via Wi-Fi (alerta remoto)

O projeto demonstra uma integração completa entre hardware, rede Wi-Fi, API REST e atuadores físicos.


## 🧰 Componentes Utilizados
- ESP32 NodeMCU  
- Potenciômetro  
- LED + resistor  
- Buzzer  
- Protoboard  
- Wi-Fi  
- Bot do Telegram  

## 📡 Comunicação
O projeto utiliza comunicação Wi-Fi com o ESP32, realizando requisições HTTPS utilizando `WiFiClientSecure` para envio de notificações ao Telegram.

## ▶️ Como Executar
1. Insira o token do bot e o chat ID diretamente no código.  
2. Ajuste o nome e senha da rede Wi-Fi.  
3. Carregue o código no ESP32 pela Arduino IDE.  
4. Gire o potenciômetro e observe:
   - LED acendendo  
   - Buzzer tocando  
   - Mensagem no Telegram  
5. Acompanhe os valores pelo Monitor Serial.

## 🖼 Imagens do Projeto

<img width="955" height="866" alt="image" src="https://github.com/user-attachments/assets/b91fa6b4-e08b-4c30-a533-67b560daead4" />


## 📎 Código-Fonte
O código completo está disponível na pasta `/src`.

