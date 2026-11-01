#define RXD2 16
#define TXD2 17

void setup() {

  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("UART Lookback Test Started");
}

void loop() {
  Serial2.println("Hello UART");
  delay(200); 

  while (Serial2.available()){
    String msg = Serial2.readStringUntil('\n');
  Serial.print("Received :");
  Serial.println(msg);
  }

  delay(1000);
}
