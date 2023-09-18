/**
 * @mainpage ESP32_STM_UART
 * @brief Проект ESP32_STM_UART предназначен для реализации протокола общения между микроконтроллерами ESP32 и STM32
 * с использованием интерфейса UART. Проект содержит файлы ESP32_STM_UART.h и Settings_ESP.h.
 * @section structure Структура проекта
 * * main.cpp
 * * ESP32_STM_UART.h
 * * ESP32_STM_UART.cpp
 * * Settings_ESP.h
 * @section protocol Протокол общения
 * Протокол общения между устройствами STM и ESP32 описан в документации проекта.

 * @details Протокол общения между устройствами представляет собой набор команд, передаваемых по UART. Команды от STM32
 * содержат определенные значения, указывающие на тип команды и ее параметры. Команды от ESP32 являются ответами на
 * соответствующие команды от STM32 и содержат информацию о выполнении команды и ее результатах.
 * В библиотеке ESP32_STM_UART реализованы методы для обработки входящих команд, отправки их на STM32, а также для
 * обработки ответов от STM32. Кроме того, библиотека содержит дополнительные методы для работы с UART, такие как
 * настройка скорости передачи данных и установка пинов для подключения интерфейса UART.
 * Для работы с библиотекой необходимо создать объект класса ESP32_STM_UART и вызвать методы для обработки команд и
 * отправки ответов. Подробная документация по каждому методу доступна в соответствующих файлах с исходным кодом.
*/
/**

 * @file main.cpp
 * @brief Главный файл проекта ESP32_STM_UART. Точка входа в программу
 * @details В функции setup() происходит инициализация устройств и настройка параметров UART. В функции loop()
 * происходит обработка входящих команд и отправка ответов на STM32.
 * 
*/
#include <Arduino.h>
#include <WiFi.h>
#include "ESP32_STM_UART.h"
#include "Settings_ESP.h"
#include <HTTPClient.h>
#include <Update.h>


const char* ssid = "Simba";
const char* password = "Mainura1994";
bool debug_flag = true;
//String serialNumber = String(ESP.getChipRevision());

uint64_t mac = ESP.getEfuseMac(); 
String serialNumber = macToString(mac);


//HardwareSerial Serial2(2);
uint32_t uartBaudRate = 115200; 
/**
 * @brief Создает экземпляр ESP32_STM_UART для обработки сообщений.
 * @param Serial2 Аппаратный последовательный порт, используемый для общения.
 * @param uartBaudRate Скорость передачи данных в бод (baud rate) для последовательного порта.
 */

ESP32_STM_UART stmUart(Serial2, uartBaudRate);

/**
 * @brief Настраивает начальные параметры, такие как последовательный порт и подключение Wi-Fi.
 */

void setup() {
    // Serial2.begin(uartBaudRate, SERIAL_8N1, 21, 22); // Serial2.begin(baud-rate, protocol, RX pin, TX pin);
    Serial2.begin(uartBaudRate, SERIAL_8N1, 22, 21); // Марат, я не уверен. Если буфер будет пустым то измени rx pin, tx pin
    Serial.begin(uartBaudRate);
    print_debug(debug_flag, String("Ready"));
    WiFi.begin(ssid, password);
    /**
     * @brief Подключение к wi-fi retries раз
    */
    print_debug(debug_flag, String("Testing the STM-ESP32 communication protocol. Project Velvet."));
    print_debug(debug_flag, String("Author of the code for the ESP32 microcontroller: Maxat Suieubayev."));
    print_debug(debug_flag, String("Author of the code for STM: Marat Kamalov."));
    print_debug(debug_flag, String("Supervisor: Sanat Baiguanish."));
    print_debug(debug_flag, String(""));
    print_debug(debug_flag, String("We are currently in ESP32.\nAt the moment, the debug_flag is set to true in main.cpp."));
    print_debug(debug_flag, String("The debug_flag is necessary for displaying the process happening inside the ESP32 microcontroller. "));
    print_debug(debug_flag, String("To disable message output, set debug_flag to False."));
    print_debug(debug_flag, String(""));
    print_debug(debug_flag, String("ESP32 code version: 0.0.2"));
    print_debug(debug_flag, String("ESP32 Serial number: ")+String(serialNumber));
    print_debug(debug_flag, String(""));
    print_debug(debug_flag, String("Please just enjoy!"));
    
    print_debug(debug_flag, String("Wi-Fi Connection Starting"));

    if(stmUart.check_wifi()){
        print_debug(debug_flag, String("Let's start"));
    }
    else {print_debug(debug_flag, String("Check ssid & pass!"));}
        /**
         * @brief Не удалось подключиться к Wi-Fi, здесь можно добавить обработку ошибок
        */ 
}
/**
 * @brief Основной цикл программы, обрабатывает входящие сообщения через stmUart.
 */
void loop() {
    stmUart.processIncomingMessage();
}