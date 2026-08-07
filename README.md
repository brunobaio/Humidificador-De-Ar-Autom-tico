# 📱 Aplicativo desenvolvido no MIT App Inventor

Além do sistema desenvolvido com Arduino, o projeto possui um **aplicativo mobile desenvolvido através do MIT App Inventor**.

O aplicativo é responsável por realizar a comunicação com o Arduino através do módulo Bluetooth, permitindo que o usuário acompanhe as informações coletadas pelo sensor DHT22 diretamente pelo celular.

## 🔵 Comunicação Arduino → Bluetooth → Aplicativo

O funcionamento da comunicação ocorre da seguinte maneira:

```text
Sensor DHT22
     ↓
Arduino UNO
     ↓
Módulo Bluetooth
     ↓
Comunicação Bluetooth
     ↓
Aplicativo MIT App Inventor
     ↓
Usuário visualiza os dados
```

O Arduino realiza a leitura da temperatura e da umidade:

```cpp
float temperatura = dht.readTemperature();
float umidade = dht.readHumidity();
```

Depois, essas informações são enviadas através do módulo Bluetooth:

```cpp
bluetooth.print("Temperatura: ");
bluetooth.print(temperatura);
bluetooth.print("°C, Umidade: ");
bluetooth.print(umidade);
bluetooth.print("% - ");
```

O aplicativo desenvolvido no **MIT App Inventor** recebe essas informações e permite que o usuário acompanhe as condições do ambiente pelo smartphone.

Entre as informações transmitidas estão:

* 🌡️ Temperatura atual;
* 💧 Umidade atual;
* 🌡️ Classificação da temperatura;
* 💧 Classificação da umidade;
* 📡 Dados recebidos em tempo real através da conexão Bluetooth.

Um exemplo de informação enviada pelo Arduino para o aplicativo é:

```text
Temperatura: 24.80°C, Umidade: 55.20% - Temperatura confortável. Umidade confortável.
```

## 🧩 Desenvolvimento do aplicativo

O aplicativo foi desenvolvido utilizando o **MIT App Inventor**, uma plataforma de desenvolvimento visual baseada em blocos.

Através dele foi criada a interface responsável por estabelecer a conexão Bluetooth e apresentar ao usuário os dados enviados pelo Arduino.

Dessa forma, o projeto integra **hardware e software** em uma única solução:

```text
Arduino + DHT22 + Automação
             +
         Bluetooth
             +
     Aplicativo Mobile
             =
Sistema de Monitoramento
de Temperatura e Umidade
```

## 🛠️ Tecnologias utilizadas no projeto

### Hardware

* Arduino UNO
* Sensor DHT22
* Módulo Bluetooth
* Módulo Relé
* LED vermelho
* LED verde
* Resistores
* Protoboard
* Jumpers
* Umidificador

### Software

* Arduino IDE
* C/C++
* MIT App Inventor
* Comunicação Bluetooth
* Biblioteca DHT
* Biblioteca Adafruit Sensor
* Biblioteca SoftwareSerial
