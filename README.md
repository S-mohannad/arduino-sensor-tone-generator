# 🎵 Sensor-Controlled Tone Generator

> **Arduino Project #20** — سنسور يتحكم بتردد نغمة Buzzer بعد معايرة تلقائية

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Level](https://img.shields.io/badge/Level-Intermediate-orange?style=for-the-badge)](https://github.com/S-mohannad)

---

## 📋 Description

مشروع يحول قيمة سنسور تناظري إلى نغمة صوتية متغيرة:

**مرحلة المعايرة (setup):**
- يقرأ A0 باستمرار لمدة 10 ثواني ويتتبع الـ min والـ max

**مرحلة التشغيل (loop):**
- يقرأ قيمة A0 ويقيّدها بين min و max باستخدام `constrain()`
- يحولها إلى تردد بين **200Hz و400Hz** باستخدام `map()`
- يصدر النغمة على Buzzer في pin 10

---

## 🔌 Circuit

```
Arduino UNO
┌─────────────────┐
│            A0 ●─┼──────────┬── سنسور تناظري ── 5V
│                 │          │
│                 │        [10kΩ]
│                 │          │
│           GND ●─┼──────────┘
│                 │
│            10 ●─┼──────────🔊 Buzzer (+)
│           GND ●─┼──────────🔊 Buzzer (-)
└─────────────────┘
```

- 🎛️ سنسور تناظري على Pin A0 مع مقاومة سحب 10kΩ إلى GND
- 🔊 Buzzer على Pin 10

---

## 💡 Concepts Used

- `analogRead()` — قراءة قيمة تناظرية (0–1023) من A0
- `millis()` — تحديد فترة المعايرة (10 ثواني)
- `max()` و `min()` — تتبع أعلى وأدنى قيمة أثناء المعايرة
- `constrain()` — تقييد القيمة ضمن النطاق المُعاير
- `map()` — تحويل نطاق السنسور (min–max) إلى نطاق التردد (200–400 Hz)
- `tone()` — إصدار نغمة بتردد محدد على Buzzer

---

## 📊 Behavior

| المرحلة | الحدث |
|---------|-------|
| 0–10 ثواني | معايرة تلقائية — تتبع min و max من A0 |
| loop | قراءة A0 → constrain → map → tone |
| قيمة منخفضة | نغمة منخفضة (~200Hz) |
| قيمة عالية | نغمة عالية (~400Hz) |

---

## 🔗 Code

```cpp
int max = 0, min = 1023;
int f;

void setup() {
  pinMode(10, OUTPUT);
  while (millis() < 10000) {
    max = max(max, analogRead(A0));
    min = min(min, analogRead(A0));
  }
}

void loop() {
  int x = analogRead(A0);
  x = constrain(x, min, max);
  f = map(x, min, max, 200, 400);
  tone(10, f, 100);
  delay(100);
}
```

---

## 🔧 How to Run

1. افتح **Arduino IDE**
2. وصّل الدائرة (سنسور على A0، Buzzer على pin 10)
3. انسخ الكود والصقه في المحرر
4. اختر **Board:** Arduino UNO
5. اختر **Port** الصحيح
6. اضغط ⬆️ **Upload**
7. حرّك السنسور في نطاقه الكامل خلال أول 10 ثواني (مرحلة المعايرة)
8. بعد 10 ثواني — راقب النغمة تتغير مع حركة السنسور

---

## 👨‍💻 Author

**S-mohannad** — [@S-mohannad](https://github.com/S-mohannad)
