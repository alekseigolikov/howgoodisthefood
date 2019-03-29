//new
const int buttonPin_r = 4;
const int buttonPin_g = 12;
const int buttonBoth = buttonPin_r + buttonPin_g;
const int ledPin_r =  2; 
const int ledPin_g =  15; 

const int blink_fast = 50;
const int blink_slow = 200;
const int fade_speed = 10;

void configure_pins() {
  //start serial connection
  //Serial.begin(115200);
  pinMode(buttonPin_r, INPUT_PULLUP);
  pinMode(buttonPin_g, INPUT_PULLUP);
  pinMode(ledPin_r, OUTPUT);
  pinMode(ledPin_g, OUTPUT);

}

void led_on(int blink_led) {
  digitalWrite(blink_led, HIGH);
}

void led_off(int blink_led) {
  digitalWrite(blink_led, LOW);
}

void led_blink(int blink_led, int blink_times, int blink_speed) {
  for( int i = 0; i < blink_times; i++) {
    digitalWrite(blink_led, HIGH);
    delay(blink_speed);
    digitalWrite(blink_led, LOW);
    delay(blink_speed);
  }
}


void led_fade(int blink_led, int blink_times, int blink_speed) {
  for( int i = 0; i < blink_times; i++) {
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      analogWrite(blink_led, fadeValue);
      delay(blink_speed);
    }
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      analogWrite(blink_led, fadeValue);
      delay(blink_speed);
    }
  }
}


void led_semaphore(int blink_first, int blink_then, int blink_times, int blink_speed){
  for( int i = 0; i < blink_times; i++) {
    led_on(blink_first);
    led_off(blink_then);
    delay(blink_speed);
    led_off(blink_first);
    led_on(blink_then);
    delay(blink_speed);
    led_off(blink_then);
  }
}

int detect_button(int button_first, int button_second)
{
  int result_out = 0;
  int read_button;
  read_button = digitalRead(button_first);
  if ( read_button == LOW ){
    result_out+=button_first;
  }
  read_button = digitalRead(button_second);
  if ( read_button == LOW ){
    result_out+=button_second;
  }
  return result_out;
}
