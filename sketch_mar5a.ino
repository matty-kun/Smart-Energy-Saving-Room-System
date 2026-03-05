// Pin assignments
int sensorA = 2;     // IR Sensor 1
int sensorB = 3;     // IR Sensor 2

int light = 8;       // LED (light)
int fan = 9;         // DC motor (fan)

int count = 0;       // number of people in room

void setup() {

  pinMode(sensorA, INPUT);  // Listen for signals from Sensor A
  pinMode(sensorB, INPUT);  // Listen for signals from Sensor B
  pinMode(light, OUTPUT);   // Send power to the LED
  pinMode(fan, OUTPUT);     // Send power to the Motor
  Serial.begin(9600);       // Starts the "chat" with your computer screen

}

void loop() {

// 1. Check for ENTRY (A then B)
  if (digitalRead(sensorA) == LOW) { // Assuming LOW is detected
    while (digitalRead(sensorB) == HIGH); // Wait until B is also hit
    count++;
    while (digitalRead(sensorB) == LOW); // Wait until they are totally past B
    delay(500); // Debounce delay
  }

// 2. Check for EXIT (B then A)
  if (digitalRead(sensorB) == LOW) {
    while (digitalRead(sensorA) == HIGH); // Wait until A is also hit
    if (count > 0) count--;
    while (digitalRead(sensorA) == LOW); // Wait until they are totally past A
    delay(500);
  }

// 3. Output Logic
  if (count <= 0) {
    digitalWrite(light, LOW);
    digitalWrite(fan, LOW);
    count = 0; // Keep it at zero
  } else {
    // Note: You said the system only turns things OFF, 
    // but usually, you need a way to turn them ON too!
    digitalWrite(light, HIGH); 
    digitalWrite(fan, HIGH);
  }
}