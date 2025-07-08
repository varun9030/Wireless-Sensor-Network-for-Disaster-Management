#include <LiquidCrystal.h>
#include <DFRobot_DHT11.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Object Initialization
DFRobot_DHT11 DHT;
Adafruit_MPU6050 mpu;

// LCD Pins
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pin Definitions
#define DHT11_PIN 6
#define ECHO_PIN A0
#define TRIG_PIN A1
#define BUZZER_PIN 7

// Globals
int cnt = 0;
long int prv = 0;

void setup() {
  Serial.begin(9600);

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("MPU6050 not connected!");
    while (1);
  }

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("   WELCOME  ");
  delay(1000); // Add delay to show welcome message
  lcd.clear();
}

void loop() {
  // Read MPU6050
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  int xval = a.acceleration.x;
  int yval = a.acceleration.y;
  int zval = a.acceleration.z;

  // Ultrasonic Sensor Distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int distance = pulseIn(ECHO_PIN, HIGH) / 58.2;

  // Read DHT11
  DHT.read(DHT11_PIN);
  int tempVal = DHT.temperature;
  int humVal = DHT.humidity;

  // Gas sensor reading
  int gasVal = analogRead(A2);
  int pressureVal = 1021; // Placeholder for pressure sensor (constant here)

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("X:" + String(xval) + " L:" + String(distance) + " G:" + String(gasVal));
  lcd.setCursor(0, 1);
  lcd.print("T:" + String(tempVal) + " H:" + String(humVal) + " P:" + String(pressureVal));

  // Check Thresholds
  if (xval > 5 || distance < 6 || gasVal > 500 || tempVal > 37 || humVal > 91) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Serial Logging
  cnt++;
  if (cnt > 15) {
    cnt = 0;
    Serial.print("238294,OF5XKDVEWHTHIM2X,0,0,SRC 24G,src@internet,");
    Serial.print(xval); Serial.print(",");
    Serial.print(distance); Serial.print(",");
    Serial.print(gasVal); Serial.print(",");
    Serial.print(tempVal); Serial.print(",");
    Serial.print(humVal); Serial.print(",");
    Serial.print(pressureVal);
    Serial.println(",0");
  }

  delay(500);
}
