void loop() {
  WiFiClient client = server.available();     // Ouve os clientes que chegam
  
  if(client){                                // Se um novo cliente se conectar
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");            // Imprime uma mensagem na porta serial
    String currentLine = "";                  // faz uma string para conter os dados de entrada do cliente    
    
    while(client.connected() && currentTime - previousTime <= timeoutTime){   // Loop enquanto o cliente está conectado, por 2 segundos
      currentTime = millis();
      
      if(client.available()){                 // Se houver bytes para ler do cliente
        char c = client.read();               // Leia um byte, então
        Serial.write(c);                      // escreve no monitor serial
        header += c;

        if(c == '\n'){                        // se o byte é um caracter de nova linha
          // Se a linha atual estiver em branco, terá dois caracteres de nova linha em uma linha.
          // esse   é o fim da solicitação HTTP do cliente, então envie uma resposta:
          if(currentLine. length() == 0){
            // Os cabeçalhos HTTP sempre começam com um código de resposta (ex: HTTP / 1.1 200 OK)                        
            // e um tipo de conteúdo para o cliente saiba o que está por vir, em seguida, uma linha em branco:
            client.println("HTTP/1.1 200 Ok");
            client.println("Content-type:text/html");
            client.println("Connection: close");            
            client.println();  
            
            // Verifica o caracter enviado pelo HTML (GET)            
            if(header.indexOf("GET /L1") >= 0){
              Status_Led =! Status_Led;                               //Inverte o estado do led
              digitalWrite(Led, Status_Led);                          // ação de ACENDER ou APGAR                           
            }
                


            // ***************** DEFINIÇÕES - CORPO - CÓDIGO DA PÁGINA HTML *****************

            // Exibir a página da web em HTML
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" hredf=\"data:,\">");
            client.println("<title> WEB SERVER + WIFI MANGER com ESP32 </title>");       //Titulo do topo da Pagina     



            // CSS para estilizar os botões e Página
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-color: #F0FFF0;}");
            client.println(".button { background-color: #4CAF50; border-radius: 15px; color: white; padding: 10px 20px;");
            client.println("text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {  background-color: #555555;}</style></head>");


            // Título da página da web
            client.println("<body>   <h1>ESP32</h1> <h3> Web Server</h3>");


            // Atualização do HTML em função do status do LED
            if(Status_Led){                                       // se o Led estiver ligado
              client.print("<a href=\"/L1\"><button class=\"button\">LED-ON</button></a>");
            }
            else{
              client.print("<a href=\"/L1\"><button class=\"button button2\">LED-OFF</button></a>");            
            }                                        

            client.println("<P>");

            client.println("Tenha um Bom Dia!");
            client.println("<P>");


            client.println("</body></html>");                     // fecha a página HTML
            
            client.println();                                     // A resposta HTTP termina com outra linha em branco:                             
            break;                                                // interrompe o loop while:            
          }
          else{
            currentLine = "";                                     // Se receber uma nova linha, limpa o currentLine:
          }
                 
        }
        else if(c != '\r'){
          currentLine += c;          
        }  
      }   
    }      
    // limpa a variável header
    header = "";
    //fecha a conexão:
    client.stop();
    Serial.println("Client Disconnected.");
    Serial.println("------------------------------------------------------------");         
  }

}
