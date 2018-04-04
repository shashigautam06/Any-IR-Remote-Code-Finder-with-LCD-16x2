
#define Hex code1 fe708f
#include <IRremote.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x3F, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified module
int RECV_PIN = A0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH); // NOTE: You can turn the backlight off by setting it to LOW instead of HIGH
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IR Remote Reader started");
  lcd.setCursor(0, 1);
  lcd.print("Read any remote");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Remote button HEX code :");
    Serial.println(results.value, HEX);
    unsigned int value = results.value;
    Serial.print("Remote button DECIMAL code :");
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("IR INT:");
    lcd.print(value);
    lcd.setCursor(0, 1);
    lcd.print("IR HEX:");
    lcd.print(results.value, HEX);
    // delay(1000);


  }

  delay(100);
}


