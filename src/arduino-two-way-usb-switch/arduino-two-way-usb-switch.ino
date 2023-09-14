// https://github.com/constrkh/arduino-two-way-usb-switch
//



const uint8_t relayVcc = PA2;
const uint8_t relayDataCh1 = PC5;
const uint8_t relayDataCh2 = PC4;
const uint8_t btnPin = PC3;

const uint16_t dataSwitchDelay = 200;

uint8_t currentChannel = 2;

void setup()
{
  pinMode(relayVcc, OUTPUT);
  pinMode(relayDataCh1, OUTPUT);
  pinMode(relayDataCh2, OUTPUT);
  digitalWrite(relayDataCh1, LOW);
  digitalWrite(relayDataCh2, LOW);
  digitalWrite(relayVcc, LOW);
  pinMode(btnPin, INPUT_PULLUP);
  
  delay(100);
  
  switchChannels();
  
  delay(200);
  
}

void switchChannels()
{
  // power is the first to come and the last to leave
  digitalWrite(relayDataCh1, LOW);
  digitalWrite(relayDataCh2, LOW);
  delay(dataSwitchDelay);
  
  if (currentChannel == 1) {
    currentChannel = 2;
    digitalWrite(relayVcc, HIGH);
    delay(dataSwitchDelay);
    digitalWrite(relayDataCh2, HIGH);
  } else {
    currentChannel = 1;
    digitalWrite(relayVcc, LOW);
    delay(dataSwitchDelay);
    digitalWrite(relayDataCh1, HIGH);
  }
  
  
}

void loop()
{
  if (digitalRead(btnPin) == LOW) {
    switchChannels();
    delay(100);
  }
  delay(100);
}
