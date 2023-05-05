/* Wild-Bird RGB LEDs project
Made to be attached to a drone or bike for entertainment purposes.
Battery monitoring part are originally written by: Usman Ali Butt (https://www.engineersgarage.com/nodemcu-battery-voltage-monitor/)
Interrupt Code part (https://lastminuteengineers.com/handling-esp8266-gpio-interrupts-tutorial/)
PWM Code part are originally written by: Rui Santos (https://randomnerdtutorials.com/esp8266-pwm-arduino-ide/)
*/
// Choose the pin for the On-board LED (IO2 Low level)
#define LED 2

//Define LED Output
const int LEDRV = 4;
const int LEDBL = 5;
const int LEDBR = 14;
const int LEDVR = 13;

//Structure for Tilt function
struct TILT {
  const uint8_t PIN;
  uint32_t numberTiltAction;
  bool motion;
};

//variables to keep track of the timing of recent interrupts
unsigned long Tilt_time = 0;
unsigned long last_Tilt_time = 0;

TILT Tilt = { D6, 0, false };

void ICACHE_RAM_ATTR ISR() {
  Tilt_time = millis();
  if (Tilt_time - last_Tilt_time > 5000) {
    Tilt.numberTiltAction++;
    Tilt.motion = true;
    last_Tilt_time = Tilt_time;
  }
}

int BAT = A0;
float RatioFactor = 39.1 ;


void setup() {

  delay(100);
  Serial.begin(9600);

  // prepare INPUT/OUTPUT
  
  pinMode(LED, OUTPUT);
  pinMode(Tilt.PIN, INPUT_PULLUP);    //prepare Tilt Sensor
  attachInterrupt(Tilt.PIN, ISR, CHANGE);
  pinMode(LEDVR, OUTPUT);
  digitalWrite(LEDVR, HIGH);
  pinMode(LEDBR, OUTPUT);
  digitalWrite(LEDBR, HIGH);
  pinMode(LEDBL, OUTPUT);
  digitalWrite(LEDBL, HIGH);
  pinMode(LEDRV, OUTPUT);
  digitalWrite(LEDRV, HIGH);

  //Battery Monitoring : Go to Sleep if low

  float Tvoltage = 0.0;
  float Vvalue = 0.0, Rvalue = 0.0;
  Vvalue = Vvalue + analogRead(BAT);         //Read analog Voltage
  delay(50);                                 //ADC stable
  Vvalue = (float)Vvalue / 10.0;             //Find average of 10 values
  Rvalue = (float)(Vvalue / 1024.0) * 1;  //Convert Voltage in 5v factor
  Tvoltage = Rvalue * RatioFactor;

  Serial.println("Battery Voltage =");
  Serial.print(Tvoltage);
  if (Tvoltage <= 3.4) {
    ESP.deepSleep(0);
  }

  for (int i = 0; i <= 10; i++) {
    digitalWrite(LED, HIGH);
    delay(20);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
  }


  analogWrite(LEDRV, 192);
  delay(200);
  analogWrite(LEDRV, 255);
  analogWrite(LEDBR, 192);
  delay(200);
  analogWrite(LEDBR, 255);
  analogWrite(LEDBL, 192);
  delay(200);
  analogWrite(LEDBL, 255);
  analogWrite(LEDVR, 192);
  delay(200);
  analogWrite(LEDVR, 255);
  analogWrite(LEDRV, 192);
  delay(200);
  analogWrite(LEDRV, 255);
  analogWrite(LEDRV, 192);
  analogWrite(LEDVR, 192);
  delay(200);
  analogWrite(LEDRV, 255);
  analogWrite(LEDVR, 255);
  analogWrite(LEDBR, 192);
  delay(200);
  analogWrite(LEDBR, 255);
  analogWrite(LEDBL, 192);
  delay(200);
  analogWrite(LEDBL, 255);
  analogWrite(LEDVR, 192);
  delay(200);
  analogWrite(LEDVR, 255);
  analogWrite(LEDRV, 192);
  delay(200);
  analogWrite(LEDRV, 255);
  analogWrite(LEDRV, 192);
  analogWrite(LEDVR, 192);
  delay(200);
  analogWrite(LEDRV, 255);
  analogWrite(LEDVR, 255);

  delay(2000);
}

void loop() {

   for (int i = 0; i <= 3; i++) {

    if (Tilt.motion) {
      (i = 0);
      Serial.printf("Tilt has been detected %u times\n", Tilt.numberTiltAction);
      Tilt.motion = false;

      for (int i = 0; i < 20; i++) {
        delay(10);
        analogWrite(LEDBL, 0);
        delay(10);
        analogWrite(LEDBL, 255);
        analogWrite(LEDVR, 0);
        delay(10);
        analogWrite(LEDVR, 255);
        analogWrite(LEDBR, 0);
        analogWrite(LEDBL, 0);
        delay(10);
        analogWrite(LEDBR, 255);
        analogWrite(LEDBL, 255);
        analogWrite(LEDRV, 0);
        delay(10);
        analogWrite(LEDRV, 255);
        analogWrite(LEDBR, 0);
        delay(10);
        analogWrite(LEDBR, 255);
      }
    }

    if (i < 3) {
        // changing the LED brightness with PWM
      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDRV, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDRV, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDRV, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDRV, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDBR, dutyCycle);
        delay(5);
        analogWrite(LEDBR, 255);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite((LEDBL), dutyCycle);
        delay(5);
        analogWrite(LEDBL, 255);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDBR, dutyCycle);
        delay(5);
        analogWrite(LEDBR, 255);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDBL, dutyCycle);
        delay(5);
        analogWrite(LEDBL, 255);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }

      for (int i = 0; i < 7; i++) {
        for (int i = 0; i < 20; i++) {
          delay(10);
        analogWrite(LEDBL, 0);
        delay(10);
        analogWrite(LEDBL, 255);
        analogWrite(LEDVR, 0);
        delay(10);
        analogWrite(LEDVR, 255);
        analogWrite(LEDBR, 0);
        analogWrite(LEDBL, 0);
        delay(10);
        analogWrite(LEDBR, 255);
        analogWrite(LEDBL, 255);
        analogWrite(LEDRV, 0);
        delay(10);
        analogWrite(LEDRV, 255);
        analogWrite(LEDBR, 0);
        delay(10);
        analogWrite(LEDBR, 255);
        }
        for (int i = 0; i < 8; i++) {
          delay(10);
          analogWrite(LEDVR, 0);
          delay(80);
          analogWrite(LEDVR, 255);
          analogWrite(LEDRV, 0);
          delay(80);
          analogWrite(LEDRV, 255);
          analogWrite(LEDBR, 0);
          analogWrite(LEDBL, 0);
          delay(80);
          analogWrite(LEDBR, 255);
          analogWrite(LEDBL, 255);
        }
      }
      for (int i = 0; i < 3; i++) {
        delay(10);
        analogWrite(LEDVR, 0);
        delay(180);
        analogWrite(LEDVR, 255);
        delay(100);
        analogWrite(LEDVR, 0);
        delay(180);
        analogWrite(LEDVR, 255);
        delay(100);
        analogWrite(LEDRV, 0);
        delay(180);
        analogWrite(LEDRV, 255);
        delay(100);
        analogWrite(LEDRV, 0);
        delay(180);
        analogWrite(LEDRV, 255);
        delay(100);
        analogWrite(LEDRV, 0);
        analogWrite(LEDVR, 0);
        delay(180);
        analogWrite(LEDRV, 255);
        analogWrite(LEDVR, 255);
        delay(100);
        analogWrite(LEDRV, 0);
        analogWrite(LEDVR, 0);
        delay(180);
        analogWrite(LEDRV, 255);
        analogWrite(LEDVR, 255);
        analogWrite(LEDBR, 0);
        delay(180);
        analogWrite(LEDBL, 255);
        delay(100);
        analogWrite(LEDBL, 0);
        delay(180);
        analogWrite(LEDBR, 255);
        analogWrite(LEDBR, 0);
        delay(180);
        analogWrite(LEDBL, 255);
        delay(100);
        analogWrite(LEDBL, 0);
        delay(180);
        analogWrite(LEDBR, 255);
        analogWrite(LEDBL, 255);
      }

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }
      delay(30);

       for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        delay(1);
      }
      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        delay(1);
      }
      delay(30);

       for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }

      delay(30);

      for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }
      delay(30);

      for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        // changing the LED brightness with PWM
        analogWrite(LEDVR, dutyCycle);
        analogWrite(LEDRV, dutyCycle);
        analogWrite(LEDBL, dutyCycle);
        analogWrite(LEDBR, dutyCycle);
        delay(1);
      }


      for (int i = 0; i < 2; i++) {
        analogWrite(LEDVR, 0);
        delay(240);
        analogWrite(LEDVR, 255);
        delay(100);
        analogWrite(LEDRV, 0);
        analogWrite(LEDVR, 0);
        delay(240);
        analogWrite(LEDRV, 255);
        analogWrite(LEDVR, 255);
        analogWrite(LEDRV, 0);
        delay(240);
        analogWrite(LEDRV, 255);
        delay(100);
        analogWrite(LEDBR, 0);
        analogWrite(LEDBL, 0);
        delay(240);
        analogWrite(LEDBR, 255);
        analogWrite(LEDBL, 255);
        delay(100);
        analogWrite(LEDBR, 0);
        analogWrite(LEDBL, 0);
        delay(660);
        analogWrite(LEDBR, 255);
        analogWrite(LEDBL, 255);
      }
    } else ESP.deepSleep(10);
  }
}
