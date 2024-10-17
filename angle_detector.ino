#include <Servo.h>  // add servo library
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows 
Servo myservo;  // create servo object to control a servo
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  lcd.begin(); // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
}
 
void loop() {
lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Angle");        // print message at (0, 0)=   b sssd
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo (value between 0 and 180)
 Serial.println(val);
  myservo.write(val);                  // sets the servo position according to the scaled value
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print(val); // print message at (2, 1)
  delay(50);;// waits for the servo to get there
}
