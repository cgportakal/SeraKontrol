/*
Elektronik Devreler Dersi Sera Kontrol Sistemi Projesi
*/
/********************************************
 * Hazırlayanlar                            *
 * 1030522808 Gökmen Portakal               *
 * 1030520761 Mehmet Selim Gözleyici        *
 * 1030516146 Ali Adam Mahamat              *
 * 1030516412 Abdoulsalam Ousseyni Oumarou  *
 * *****************************************/
 
/**
  Pinler	Bağlı Olan Aygıt
  0
  1
  2       DHT11 Data
  3       LED 4 Toprak Nem - M
  4       LCD - D4
  5       LCD - D5
  6       LCD - D6
  7       LCD - D7
  8       LCD - EN
  9       LCD - RS
  10      Bluetooth - TX
  11      Bluetooth - RX
  12      LED 5 Yağmur - K
  13      LED 5 Yağmur - M
  A0      Yağmur Data
  A1      Toprak Nem Data
  A2      LDR - Işık Sensörü
  A3      LED 1 - DHT11 - K
  A4      LED 2 - DHT11 - M
  A5      LED 3 - Toprak Nem - K
**/
#include <LiquidCrystal.h>
#include <dht11.h>
#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX

//LCD Display
const int d4 = 4, d5 = 5, d6 = 6, d7 = 7, en = 8, rs = 9; //LCD Pinleri
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Yagmur Sensoru
int yagmurOlcum = 0; // "yagmur" adında değişkenimizi oluşturup başlangıç için 0 değeri verdik.
int yagmurPin = A0;  // Yağmur sensörümüzü Analog A0 pinimize tanımladık.

//DHT11 Nem Sensoru
dht11 dht;
int dhtPin = 2;

//Toprak Nem Sensoru
int toprakPin = A1; // Toprak Nem Sensorumuzu Analog A1 pinimize tanımladık.
int toprakOlcum;

//LDR Işık Sensörü
int LDRPin = A2;

void setup()
{
  //Bluetooth tanımlama
  BTserial.begin(9600);

  Serial.begin(9600);
  //LCD tanımlama ve boyutu
  lcd.begin(16, 2);


  //DHT11 Nem Sensörü
  //pinMode(dhtPin, INPUT);
  //Toprak Nem Sensörü
  pinMode(toprakPin, INPUT);
  //Yagmur Sensoru
  pinMode(yagmurPin, INPUT);

  pinMode(3, OUTPUT); //3 ile 6 arasındaki pinleri çıkış olarak ayarlarladık LED'ler için
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{

  //*********************************************
  //DHT11 Nem Sensörü
  dht.read(dhtPin);
  int sicaklik = dht.temperature;
  int nem = dht.humidity;
  if (sicaklik > 25)
  {
    Serial.print(sicaklik);
    Serial.println("°C Sicak");
    Serial.print("Nem %");
    Serial.println(nem);
    //DHT - BT
    BTserial.print(sicaklik);
    BTserial.print("C Sicak");
    BTserial.print(",");
    //DHT - LCD
    lcd.setCursor(0, 0);
    lcd.print(sicaklik);
    lcd.print(" Sicak ");
    //lcd.print("Nem %");
    //lcd.print(nem);
    //DHT - BT
    BTserial.print("%");
    BTserial.print(nem);
    BTserial.print(",");
    //DHT - LED
    analogWrite(A3, 255);
    analogWrite(A4, 255);

    //Serial.println("Fan Calismaya Basladi");
    delay(100);
  }
  else if (sicaklik >= 20 && sicaklik <= 25)
  {
    Serial.print(sicaklik);
    Serial.println("°C Normal");
    Serial.print("Nem %");
    Serial.println(nem);

    //DHT - BT
    BTserial.print(sicaklik);
    BTserial.print("C Normal");
    BTserial.print(",");
    //DHT - LCD
    lcd.setCursor(0, 0);
    lcd.print(sicaklik);
    lcd.print(" Nrmal ");
    //lcd.print("Nem %");
    //lcd.print(nem);
    //DHT - BT
    BTserial.print("%");
    BTserial.print(nem);
    BTserial.print(",");
    //DHT - LED
    analogWrite(A3, 255);
    analogWrite(A4, 0);
    delay(100);
  }
  else
  {
    Serial.print(sicaklik);
    Serial.println("°C Soguk");
    Serial.print("Nem %");
    Serial.println(nem);
    //DHT - BT
    BTserial.print(sicaklik);
    BTserial.print("C Soguk");
    BTserial.print(",");
    //DHT - LCD
    lcd.setCursor(0, 0);
    lcd.print(sicaklik);
    lcd.print(" Soguk ");
    //lcd.print("Nem %");
    //lcd.print(nem);
    //DHT - BT
    BTserial.print("%");
    BTserial.print(nem);
    BTserial.print(",");
    //DHT - LED
    analogWrite(A3, 0);
    analogWrite(A4, 255);
    //Serial.println("İsitici Calismaya Basladi");
    delay(100);
  }

  //*********************************************
  //Toprak Nem Sensörü
  toprakOlcum = analogRead(toprakPin); // A1 pin değerini "toprakOlcum" değişkenimize aktardık.
  Serial.print("Toprak icin Olcum Degeri: ");
  Serial.println(toprakOlcum);

  if (toprakOlcum > 900)
  {
    Serial.println("Toprak Tamamen Kuru");
    //Toprak - BT
    BTserial.print("Toprak Kuru");
    BTserial.print(",");
    //Toprak - LCD
    lcd.print("Tp Kuru");
    //Toprak - LED
    digitalWrite(A5, 255);
    digitalWrite(3, LOW);
    Serial.println("Su Motoru Calismaya Basladi");
    delay(100);
  }
  else if (toprakOlcum > 401 && toprakOlcum <= 900)
  {
    Serial.println("Toprak Orta Derecede Nemli");
    //Toprak - BT
    BTserial.print("Toprak Nemli");
    BTserial.print(",");
    //Toprak - LCD
    lcd.print("Tp Nemli");
    //Toprak - LED
    digitalWrite(A5, 0);
    digitalWrite(3, HIGH);
    delay(100);
  }
  else if (400 >= toprakOlcum && toprakOlcum >= 0)
  {
    Serial.println("Toprak Cok Nemli");
    //Toprak - BT
    BTserial.print("Cok Islak");
    BTserial.print(",");
    //Toprak - LCD
    lcd.print("Tp Islak");
    //Toprak - LED
    digitalWrite(A5, 0);
    digitalWrite(3, HIGH);
    delay(100);
  }
  else
  {
    Serial.println("Hatalı Ölçüm");
    lcd.print("Tp Hata");
  }

  //*********************************************
  //Yagmur Sensoru
  yagmurOlcum = analogRead(yagmurPin); // A0 pin değerini "yagmurOlcum" değişkenimize aktardık.
  Serial.print("Yagmur icin Olcum Degeri: ");
  Serial.println(yagmurOlcum);
  if (yagmurOlcum > 901)
  {
    Serial.println("Yagmur yok");
    //Yagmur - BT
    BTserial.print("Yagmur yok");
    BTserial.print(",");
    //Yagmur - LCD
    lcd.setCursor(0, 1);
    lcd.print("Ygmr Yok");
    //Yagmur - LED
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(100);
  }
  else if (yagmurOlcum > 401 && yagmurOlcum <= 900)
  {
    Serial.println("Yagmur yagiyor");
    //Yagmur - BT
    BTserial.print("Yagmur var");
    BTserial.print(",");
    //Yagmur - LCD
    lcd.setCursor(0, 1);
    lcd.print("Ygmr Var");
    //Yagmur - LED
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(100);
  }
  else if (300 > yagmurOlcum && yagmurOlcum >= 0)
  {
    Serial.println("Sağanak yagis");
    //Yagmur - BT
    BTserial.print("Saganak");
    BTserial.print(",");
    //Yagmur - LCD
    lcd.setCursor(0, 1);
    lcd.print("Saganak");
    //Yagmur - LED
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(100);
  }
  else
  {
    Serial.println("Hatalı Ölçüm");
  }

  //*********************************************
  //LDR Işık Sensörü
  int isik_degeri = analogRead(LDRPin);
  if (isik_degeri >= 500)
  {
    Serial.print("Aydinlik ");
    Serial.println(isik_degeri);
    //Işık - LCD
    //lcd.setCursor(0, 1);
    //lcd.print("Aydinlik ");
    //lcd.print(isik_degeri);
    //Işık - BT
    BTserial.print("Aydinlik");
    BTserial.print(",");
  }
  else if (isik_degeri < 500 && isik_degeri > 200) {
    Serial.print("Los Isik ");
    Serial.println(isik_degeri);
    //Işık - LCD
    //lcd.setCursor(0, 1);
    //lcd.print("Los Isik ");
    //lcd.print(isik_degeri);
    //Işık - BT
    BTserial.print("Los Isik");
    BTserial.print(",");
  }
  else
  {
    Serial.print("Karanlik ");
    Serial.println(isik_degeri);
    //Işık - LCD
    //lcd.setCursor(0, 1);
    //lcd.print("Karanlik ");
    //lcd.print(isik_degeri);
    //Işık - BT
    BTserial.print("Karanlik ");
    BTserial.print(",");
  }

  //*********************************************
  //Sonuc
  if (sicaklik > 25 || sicaklik < 20 || toprakOlcum > 901 || toprakOlcum < 300 && yagmurOlcum > 901 || yagmurOlcum < 300) {
    //Sonuc - Serial Monitor
    Serial.println("Anormal Koşullar Serayı Kontrol Ediniz!");
    //Sonuc - LCD
    lcd.print(" Sorunlu");
    //Sonuc - BT
    BTserial.print("Kontrol Et!");
    BTserial.print(";");//Bluetooth yazı yazmayı sonlandırma
  } else {
    //Sonuc - Serial Monitor
    Serial.println("Kosullar Uygun ve Kontrole Ihtiyac Yok");
    //Sonuc - LCD
    lcd.print(" Guzel");
    //Sonuc - BT
    BTserial.print("Kosullar Iyi");
    BTserial.print(";");//Bluetooth yazı yazmayı sonlandırma
  }

  
  Serial.println();
  delay(2000);
  lcd.clear();
}
/*
Elektronik Devreler Dersi Sera Kontrol Sistemi Projesi
*/
/********************************************
 * Hazırlayanlar                            *
 * 1030522808 Gökmen Portakal               *
 * 1030520761 Mehmet Selim Gözleyici        *
 * 1030516146 Ali Adam Mahamat              *
 * 1030516412 Abdoulsalam Ousseyni Oumarou  *
 * *****************************************/
