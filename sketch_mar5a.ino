// Pin assignments
int sensorA = 2;     // IR Sensor 1
int sensorB = 3;     // IR Sensor 2

int light = 8;       // LED (light)
int fan = 9;         // DC motor (fan)

int count = 0;       // number of people in room

void setup() {

  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);

  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);

}

void loop() {

  // ENTRY detection
  if (digitalRead(sensorA) == HIGH) {
    delay(200);

    if (digitalRead(sensorB) == HIGH) {
      count++;
    }
  }

  // EXIT detection
  if (digitalRead(sensorB) == HIGH) {
    delay(200);

    if (digitalRead(sensorA) == HIGH) {
      count--;
    }
  }

  // Prevent negative values
  if (count < 0) {
    count = 0;
  }

  // If room empty → turn OFF appliances
  if (count == 0) {
    digitalWrite(light, LOW);
    digitalWrite(fan, LOW);
  }

}