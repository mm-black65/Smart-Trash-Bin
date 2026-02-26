# 🗑️ Smart Trash Bin with Mario Sound 🎵

An automatic smart trash bin built using Arduino.  
The lid opens when a hand is detected and plays a short Mario tune for 2 seconds.

---

## 🚀 Features

- Automatic lid opening using ultrasonic sensor
- Servo motor controlled lid
- OLED display for status (OPEN / CLOSED)
- Mario sound played using buzzer (2 seconds)
- Stable open/close logic (no jitter)

---

## 🛠️ Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- OLED Display (SSD1306 I2C)
- Buzzer
- Breadboard
- Jumper Wires
- USB Cable / Power Supply

---

## 🔌 Pin Connections

| Component | Arduino Pin |
|------------|------------|
| Ultrasonic TRIG | 9 |
| Ultrasonic ECHO | 10 |
| Servo | 6 |
| Buzzer | 4 |
| OLED SDA | A4 |
| OLED SCL | A5 |

Power:
- 5V → Breadboard +
- GND → Breadboard -

---

## ⚙️ How It Works

1. Ultrasonic sensor detects hand within 20cm.
2. Servo motor opens the lid.
3. Mario tune plays for 2 seconds.
4. OLED displays "OPEN".
5. After delay, lid closes.
6. OLED displays "CLOSED".

---

## 🎵 Mario Sound

A short Super Mario theme is generated using the Arduino `tone()` function.

---

## 📦 Libraries Required

Install these from Arduino IDE:

- Servo (built-in)
- Adafruit GFX
- Adafruit SSD1306
- Wire (built-in)

---

## 📷 Future Improvements

- Garbage level detection
- "Bin Full" alert
- Battery powered portable version
- IoT monitoring system

---

## 📄 License

This project is licensed under the MIT License.
