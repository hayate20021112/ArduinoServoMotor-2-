#include <Servo.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);

const int RunBT = 2;
const int CBT   = 3;

int count = 0;

Servo servo;

    void setup() {
    servo.attach(11);
    servo.write(0);
    pinMode(RunBT,INPUT);
    pinMode(CBT,INPUT);
    lcd.backlight();
    lcd.init();
}

void loop() {
    if(digitalRead(CBT) == 1){
        count = count +15;
        delay(300);
    }

    if(count > 180){
        lcd.init();
        count = 0;
    }

    if(digitalRead(RunBT) == 1){
        servo.write(count);
        delay(300);
        lcd.setCursor(0,1);
        lcd.print("RUN!");
    }

    servo.write(0);

    lcd.setCursor(0,0);
    lcd.print("C=");
    lcd.setCursor(3,0);
    lcd.print(count);
    lcd.init();
}
