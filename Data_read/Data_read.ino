

int count = 0;                                          // count = 0
char input[12] = {0};                                         // character array of size 12
boolean flag = 0; // flag =0
int i = 0;

char a[] = "27002233D2E4";
char b[] = "2700222E96BD";
char c[] = "270022321225";
char d[] = "2700222FC4EE";
char e[] = "270022517D29";

void setup()
{
  Serial.begin(9600); 
  
 
    
  
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
      
     
  
  
    if(input[11] == a[11]){
    Serial.println("Ambulance Detected!");
    Serial.println("Running Priority Traffic Optimisation ISR");
  }
  if(input[11] == b[11]){
    Serial.println("Vehicle detected!");
    Serial.println("Running Traffic Optimisation ISR");
    i++;
   
   }
   if(input[11] == c[11]){
    Serial.println("Vehicle Detected!");
    Serial.println("Running Traffic Optimisation ISR");
    i++;
    
    }
   if(input[11] == d[11]){
    Serial.println("Vehicle Detected!");
    Serial.println("Running Traffic Optimisation ISR");
    i++;
    
    }
   if(input[11] == e[11]){
    Serial.println("Vehicle Detected!");
    Serial.println("Running Traffic Optimisation ISR");
    i++; 
    } 

    Serial.println("");
    Serial.println("The total number of detected vehicles");
    Serial.print(i);
  }
  
 }
      
  
