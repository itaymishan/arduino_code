/* Itay Mishan */

const uint8_t input_pin = 2;
const uint8_t output_pin = 19;
const uint8_t analog_pin = output_pin - 14; // analog 5
const uint8_t monitor_pin = 13;

// data
 
// larger values == more  sensitive
// maximum is 1023 == always triggered
// minimum is 0    == never  triggered
const int16_t threshhold = 1000;
 
const uint16_t trigger_delay_us = 10;
const uint16_t trigger_time_us = 20;
const uint16_t dead_time_ms = 200;
 
void init_monitor_pin() {
    pinMode(monitor_pin, OUTPUT);
    digitalWrite(monitor_pin, LOW);
}
 
void init_input_pin() {
    pinMode(input_pin, INPUT);
    digitalWrite(input_pin, LOW);
}
 
void init_output_pin() {
      pinMode(output_pin, INPUT);
      digitalWrite(output_pin, HIGH);
}
 
boolean not_triggered() {
    return analogRead(analog_pin) > threshhold;
}
 
void setup() {
    init_input_pin();
    init_output_pin();
    init_monitor_pin();
}
 
void loop() {
    while (not_triggered()) {}
 
    delayMicroseconds(trigger_delay_us);
    // close output low
    pinMode(output_pin, OUTPUT);
    digitalWrite(monitor_pin, HIGH);
 
    delayMicroseconds(trigger_time_us);
    // open output 
    pinMode(output_pin, INPUT);
 
    delay(dead_time_ms);
    digitalWrite(monitor_pin, LOW);
} 
