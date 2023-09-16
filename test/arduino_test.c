// #include <Arduino.h>
// #include <SoftwareSerial.h>

// SoftwareSerial espSerial(10, 11); // RX, TX

// void setup() {
//   // Initialize the serial port (UART) for communication with the computer
//   Serial.begin(9600);
//   while (!Serial) {
//     ; // Wait for the initialization of the port to complete
//   }

//   // Initialize the serial port for communication with the ESP32
//   espSerial.begin(115200);
// }

// void send_data_prepare_cmd(){
//     // Send the data_prepare command to ESP32
//     byte data_prepare[] = {0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//     for (int i = 0; i < sizeof(data_prepare); i++) {
//       espSerial.write(data_prepare[i]);
//     }
//     Serial.println("Message data_prepare is sended!");

//     delay(3000); // Wait 3 seconds for a response

//     // Show the response from ESP32 in the Serial monitor
//     while (espSerial.available() > 0) {
//       Serial.write(espSerial.read());
//     }
// }

// void send_weight_array_cmd(){
//   byte weight_array[] = { // Send weight. Message Weight
//     0x05, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x64, 0x36, 0x5f, 0x1d, 0x3f, 0x80, 0x00, 0x00,
//     0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00,
//     0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00,
//     0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00
//   };
//   for (int i = 0; i < sizeof(weight_array); i++) {
//       espSerial.write(weight_array[i]);
//   }
//   Serial.println("Message Weight_array sended!");
//   // Wait for a moment and then show the response from ESP32
//   delay(500);
//   while (espSerial.available() > 0) {
//     Serial.write(espSerial.read());
//   }
// }

// void loop() {
//   char userInput;

//   // Check if there's data available from the Serial
//   if (Serial.available() > 0) {
//     userInput = Serial.read();

//     if (userInput == 'A') {
//       send_data_prepare_cmd();
//     } 
//     else if (userInput == 'Q') {
//       send_weight_array_cmd();
//     } 
//     else if (userInput != '\n' && userInput != '\r') {
//       Serial.println("Error message!");
//     }
//   }
// }
