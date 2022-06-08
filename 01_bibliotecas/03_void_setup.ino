void setup() {
  // Acompanhar o processo na serial do Arduino IDE
  Serial.begin(115200);
  Serial.println("Configurar Rede WIFI");

  /////////////////////////////////////////////////////////

  // A rede que o ESP32 vai criar e a senha de acesso
  // Só cria caso ele não se conecte em nenhuma rede antes
  wifiManager.autoConnect("ESP32", "123456789");

  // Se conseguir se conectar dá um delay de 150 milissegundos e inicia a conexão WIFI
  delay(150);
  WiFi.begin();

  // Se conectar, mostra os dados do IP que será utilizado pra fazer o acesso ao site
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("-------------------------------------------------------");
    Serial.println("Conectado IP: ");
    Serial.println(WiFi.localIP());
    Serial.println("-------------------------------------------------------");

    delay(150);
    server.begin();
  }

  ////////////////////////////////////////////////////////////////////////////////////////////

  // SETUP - Definição dos Pinos
  delay(50);


  pinMode(Led, OUTPUT);

  //Inicia o LED em LOW -> Desligado
  digitalWrite(Led, LOW);


  // Só pra saber que todo processo acima foi feito
  Serial.println("************************** INICIOU **************************");
}