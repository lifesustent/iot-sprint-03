# SPRINT 03 - ESR1

Apresentação do projeto disponível no [Youtube](https://www.youtube.com/watch?v=mRC0HpYm2lU&t=3s).

## Alunos

- Deivison Pertel – **RM 550803**
- Eduardo Akira Murata – **RM 98713**
- Guilherme Jacob Soares da Costa – **RM 84581**
- Fabrizio El Ajouri Romano – **RM 550410**
- Wesley Souza de Oliveira – **RM 97874**

# Resumo

O código Arduino monitora a temperatura e umidade ambiente usando o sensor DHT22 e exibe essas leituras em um display LCD. Além disso, ele aciona alertas visuais caso a temperatura fique fora dos limites definidos. O programa utiliza a biblioteca ArduinoJson para processar dados, a biblioteca DHT para interagir com o sensor e a biblioteca LiquidCrystal para controlar o display LCD.

## Componentes Necessários
- Arduino Uno ou placa compatível
- Sensor DHT22 (ou DHT11)
- Display LCD 16x2
- Resistores para o display LCD (consulte a ligação correta)
- Jumpers
- Cabo USB para conexão com o computador

## Bibliotecas Utilizadas
**ArduinoJson :** Essa biblioteca é usada para processar dados JSON. É comumente utilizada para trabalhar com dados estruturados.

**Link:** ArduinoJson
DHT: Esta biblioteca permite a comunicação com o sensor DHT para medir a temperatura e umidade.

**Link:** DHT Library
LiquidCrystal: A biblioteca LiquidCrystal é usada para controlar o display LCD e exibir informações nele.

**Link:** LiquidCrystal Library

## Configuração de Pinos
**O código faz uso dos seguintes pinos do Arduino:**

- Pino 5: Conectado ao sensor DHT22 para leitura de temperatura e umidade.
- Pino 8 a 12: Conectados ao display LCD para controle.
- Pino 13: Usado para um alerta de temperatura alta.
- Pino 8: Usado para um alerta de temperatura baixa.

## Configuração Inicial
A função ***setup()*** é executada uma vez no início do programa e é usada para configurar os pinos, inicializar o sensor DHT, configurar o display LCD e iniciar a comunicação serial a uma taxa de 9600 bps para a depuração.


## Loop Principal
A função ***loop()*** é executada continuamente após a inicialização. Aqui estão as principais tarefas executadas no loop:

- Leitura de Temperatura e Umidade: O código lê a temperatura em graus Celsius e a umidade em porcentagem do sensor DHT22.

- Exibição no Display LCD: As leituras de temperatura e umidade são exibidas no display LCD.

- Saída para o Monitor Serial: As leituras também são - enviadas para o Monitor Serial para fins de depuração.

- Alertas de Temperatura: Se a temperatura medida estiver acima do limite definido em TempAlta, um LED conectado ao pino AlertaTempAlta acende. Se estiver abaixo do limite definido em TempBaixa, um LED conectado ao pino AlertaTempBaixa acende. Caso contrário, ambos os LEDs estão desligados.

- Delay: O programa aguarda 1 segundo antes de continuar, para evitar leituras rápidas e frequentes.

## Como Executar o Código
**Para executar este código, siga estas etapas:**

1 - Conecte o sensor DHT22 ao pino 5 do Arduino e o display LCD aos pinos 8 a 12, conforme definido no código.

2 - Carregue o código no Arduino IDE e faça o upload para a placa Arduino.

3 - Abra o Monitor Serial para ver as leituras de temperatura e umidade em tempo real.

4 - Conecte LEDs aos pinos ***AlertaTempBaixa*** e ***AlertaTempAlta*** para observar os alertas visuais de temperatura.

5 - Monitore as leituras no display LCD e no Monitor Serial e observe os alertas conforme a temperatura varia.

## Personalização
**Você pode personalizar este código alterando os seguintes parâmetros:**

- ***DHTPIN*** e ***DHTTYPE*** para adaptar ao seu sensor DHT específico.
- ***empBaixa*** e ***TempAlta*** para definir os limites de temperatura para os alertas.
- Os textos exibidos no display LCD na função ***setup()***.

## SimulIDE

<img src="/assets/img/SimullDE.jpeg">

## *Observação*
*Para mais informações acesse nosso [github](https://github.com/lifesustent/iot-sprint-03.git)
