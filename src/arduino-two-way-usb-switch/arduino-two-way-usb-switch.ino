// https://github.com/constrkh/arduino-two-way-usb-switch
//


const uint8_t relayVcc = 7;
const uint8_t relayDataCh1 = 5;
const uint8_t relayDataCh2 = 6;
const uint8_t ch1Led = 4;
const uint8_t ch2Led = 3;
const uint8_t btnPin = 2;

const uint16_t dataSwitchDelay = 1000;

uint8_t currentChannel = 2;

void setup()
{
  pinMode(relayVcc, OUTPUT);
  pinMode(relayDataCh1, OUTPUT);
  pinMode(relayDataCh2, OUTPUT);
  digitalWrite(relayDataCh1, LOW);
  digitalWrite(relayDataCh2, LOW);
  digitalWrite(relayVcc, LOW);
  pinMode(ch1Led, OUTPUT);
  pinMode(ch2Led, OUTPUT);
  pinMode(btnPin, INPUT);
  
  delay(100);
  
  switchChannels();
  
  delay(200);
  
}

void switchChannels()
{
  
  digitalWrite(ch1Led, LOW);
  digitalWrite(ch2Led, LOW);
  
  // power is the first to come and the last to leave
  digitalWrite(relayDataCh1, LOW);
  digitalWrite(relayDataCh2, LOW);
  delay(100);
  
  if (currentChannel == 1) {
    currentChannel = 2;
    digitalWrite(relayVcc, HIGH);
    delay(dataSwitchDelay);
    digitalWrite(relayDataCh2, HIGH);
    digitalWrite(ch2Led, HIGH);
  } else {
    currentChannel = 1;
    digitalWrite(relayVcc, LOW);
    delay(dataSwitchDelay);
    digitalWrite(relayDataCh1, HIGH);
    digitalWrite(ch1Led, HIGH);
  }
  
  
}

void loop()
{
  if (digitalRead(btnPin) == HIGH) {
    switchChannels();
    delay(1000);
  }
  delay(100);
}
