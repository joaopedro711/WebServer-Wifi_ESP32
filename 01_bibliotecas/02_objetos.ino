// Instanciando OBJETOS

//Configurações e Endereço de Internet WIFI
WiFiServer server   (8090);

//variável para armazenar a solicitação HTPP
String header;

// Pega a hora atual que o ESP32 foi lido e ligado
unsigned long currentTime = millis();

// vez anterior que o cliente se conectou a rede
unsigned long previousTime = 0;

// Tempo máximo em milissegundos que o cliente fica conectado a rede
const long timeoutTime = 2000;


//Reset Wifi Manager
// limpa todos os dados gravados na memória do ESP32
// Caso mude de local, não irá mostrar os dados gravados de outro local
WiFiManager wifiManager;


// Status para controle do LED
int Status_Led = LOW;