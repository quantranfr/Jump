#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>

SoftDMD dmd(1,1);  // DMD controls the entire display

int Cpin = 4;
int val = HIGH;
int lastVal = HIGH;
unsigned long lastDown = 0;
unsigned long lastUp = 0;
bool saidHi = false;

void setup() {
  dmd.setBrightness(125);
  dmd.selectFont(SystemFont5x7);
  dmd.begin();
  
  Serial.begin(9600);
  pinMode(Cpin, INPUT);
}

void loop() {
  val = digitalRead(Cpin);

  if (lastVal == LOW && val == HIGH) {
    lastUp = millis();
  }
  if (lastVal == HIGH && val == LOW) {
      lastDown = millis();
  }
  if (lastUp > 20) {
      
    if (lastDown > lastUp + 20) {
      Serial.print(lastDown-lastUp);
      Serial.println("ms");
      dmd.clearScreen();
      dmd.drawString(5,0, String(lastDown-lastUp));
      dmd.drawString(10, 8, "ms");
      lastUp = 0;
      delay(50);
    } else if (millis() - lastUp > 2000) {
      Serial.println("Bye bye");
      dmd.clearScreen();
      dmd.drawString(5,5, "Bye!");
      lastUp = 0;
      lastDown = 0;
      saidHi = false;
      delay(1500);
      Serial.println("");
      dmd.clearScreen();
    }
    
  } else if ((!saidHi) && (lastDown > 20)) {
    Serial.println("Jump!");
    dmd.clearScreen();
    dmd.drawString(2,5, "Jump!");
    saidHi = true;
  }
  lastVal = val;
  delay(3);
}
