#include<Wire.h>
/*#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>

const char* ssid = "Sury";
const char* password = "ehfqa05h#";

ESP8266WebServer server(80);

String page = " ";
double data;*/
int count = 0;                                          // count = 0
char input[12] = {0};                                         // character array of size 12
boolean flag = 0;                                       // flag =0

void setup()
{
  Serial.begin(9600); 
  Wire.begin();
  // begin serial port with baud rate 9600bps


 // delay(1000);
  /*Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    
  }

  Serial.println(" ");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
    page = "<h1>RFID WEB DATA </h1><h3>Data:</h3> <h4>"+String(data)+"</h4>";   //String(input)
    server.send(200, "text/html", page);
  });
  server.begin();
  Serial.println("Web server started!");
  */
 }

void loop()
{
  if (Serial.available())
  {
    count = 0;
    while (Serial.available() && count < 12)         // Read 12 characters and store them in input array
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    Serial.print(input);                             // Print RFID tag number

    if ((input[0] ^ input[2] ^ input[4] ^ input[6] ^ input[8] == input[10]) &&
        (input[1] ^ input[3] ^ input[5] ^ input[7] ^ input[9] == input[11]))
      Serial.println("No Error");
    else
      Serial.println("Error");
     
  }
  /*
  data = analogRead(A0);
  delay(1000);
  server.handleClient();*/
  if(input != 0){
  Wire.beginTransmission(9);
  Wire.write(input);
  Wire.endTransmission();
  
  }
}
