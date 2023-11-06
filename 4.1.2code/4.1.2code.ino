/*
Wenxi Wei
*/
const int potential_GPIO = 4;
const int LED_GPIO = 7;

const int ledChannel = 0;      // Choose an available channel //6 channels for ledc in esp32c3, we choose channel 0
const int ledFrequency = 30;   // Frequency in 30hz
const int ledResolution = 14;  // Resolution in bits


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  // set up GPIO input and output
  pinMode(potential_GPIO, INPUT);
  pinMode(LED_GPIO, OUTPUT);

  // Set up LEDC for PWM control
  ledcSetup(ledChannel, ledFrequency, ledResolution);
  ledcAttachPin(LED_GPIO, ledChannel);  // attach PWM to GPIO7
}

// the loop routine runs over and over again forever:
void loop() {

  //step 1: read value in pin 4 potentiometer
  //step 2: change the value 0--4095 to 0--225 by map
  long x = analogRead(potential_GPIO);
  int duty = map(x, 0, 4095, 0, 255);

  //step 3: set duty cycle
  ledcWrite(ledChannel, duty);  // Set the duty cycle

  Serial.println(duty);

  delay(20);
}
