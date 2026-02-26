#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Servo myservo;

// PINS
int trigPin = 9;
int echoPin = 10;
int servoPin = 6;
int buzzer = 4;

// SERVO ANGLES (CHANGE IF NEEDED)
int openAngle = 0;  
int closeAngle = 90;   

long duration;
int distance;
bool lidOpen = false;

// 🎵 Mario tune notes
int melody[] = {
  660, 660, 0, 660,
  0, 510, 660, 0,
  770, 0, 380
};

int noteDurations[] = {
  100, 100, 100, 100,
  100, 100, 100, 100,
  100, 100, 100
};

void playMario() {
  unsigned long startTime = millis();

  while (millis() - startTime < 2000) {
    for (int i = 0; i < 11; i++) {

      if (millis() - startTime >= 2000) break;

      if (melody[i] != 0)
        tone(buzzer, melody[i]);

      delay(noteDurations[i]);
      noTone(buzzer);
      delay(30);
    }
  }
}


// distance function
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  myservo.attach(servoPin);
  myservo.write(closeAngle);

  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(0,20);
  display.print("READY");
  display.display();
}


void loop() {

  distance = getDistance();
  Serial.println(distance);

  // OPEN LID (hand detected)
  if(distance < 20 && !lidOpen) {

    delay(200); // confirm detection
    distance = getDistance();

    if(distance < 20) {

      myservo.write(openAngle);
      playMario();
      lidOpen = true;

      display.clearDisplay();
      display.setCursor(0,20);
      display.print("OPEN");
      display.display();

      delay(200); // keep lid open
    }
  }

  // CLOSE LID (hand removed)
  if(distance > 25 && lidOpen) {

    myservo.write(closeAngle);
    lidOpen = false;

    display.clearDisplay();
    display.setCursor(0,20);
    display.print("CLOSED");
    display.display();
  }

  delay(300);
}
