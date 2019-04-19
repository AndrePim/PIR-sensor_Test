#include <Arduino.h>
/*
  Проверка PIR-датчика движения
*/

int ledPin = 13;    // Инициализация пина для светодиода
int inputPin = 2;   // Инициализация пина для получения сигнала от PIR-датчика
int pirState = LOW; // Начальное предположение - движение отсутствует
int val = 0;        // Переменная для чтения состояния пина

void setup()
{
  pinMode(ledPin, OUTPUT);  // Установка режима работы пина светодиода на выход
  pinMode(inputPin, INPUT); // Установка режима работы пина PIR-датчика на вход
  Serial.begin(9600);       // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
}

void loop()
{
  val = digitalRead(inputPin); // Считывание значение с датчика
  if (val == HIGH) // Проверка на соответствия, считываемого значения, HIGH
  {                             
    digitalWrite(ledPin, HIGH); // Включение светодиода
    if (pirState == LOW) 
    {
      Serial.println("Motion detected!"); // Вывод на серийный монитор изменение, а не состояние
      pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(ledPin, LOW); // Выключение светодиода
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!"); // Вывод на серийный монитор изменение, а не состояние
      pirState = LOW;
    }
  }
}