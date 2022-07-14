//ToggLED v 0.2
//by Scott Smith
//2022-7-14
//
//Push the button to turn the LED on/off. LED defaults to off. Includes debouncing to prevent flickering.
//Only detects first time button is pushed down. Ignores subsequent duplicate signals (from switch bounce)
//and ignores release of switch.

const int ledPin = 5;
const int buttonPin = 9;
const int debounceDelay = 50; //milliseconds. Delay before accepting duplicate inputs. Increase if LED flickers

int ledPower = LOW; //Setup led state tracker var, defaulting to off
int lastButtonState; //setup var for comparing button state
int currentButtonState; //other var for comparing button state


void setup()
{
  Serial.begin(9600); //Start console for debugging
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("Sketch begin");

  digitalWrite(ledPin, ledPower); //match led state
  currentButtonState = digitalRead(buttonPin); //set var to current state of button (should be HIGH)
}

void loop()
{
  lastButtonState = currentButtonState; //set last state var
  currentButtonState = digitalRead(buttonPin); //read current state

  if (lastButtonState == HIGH && currentButtonState == LOW)
  {
    Serial.println("Switch is pressed");
    
    ledPower = !ledPower;
    digitalWrite(ledPin, ledPower); //toggle led state

    if (ledPower == HIGH)
    {
      Serial.println("LED is ON");
    }
    else
    {
      Serial.println("LED is OFF");
    }
    
    delay(debounceDelay); //wait to prevent duplicatic signals from switch bounce.
  }
}
