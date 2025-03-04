/**
 * @file asr_speech_recognition.cpp
 */

#include "adc_button.h"

#include <Arduino.h>
namespace em {
AdcButton::AdcButton(uint8_t pin) : pin_(pin) {
  pinMode(pin_, INPUT);
#ifdef ESP32
  analogReadResolution(10);
#endif
}
AdcButton::ButtonType AdcButton::GetButtonType() {
  int value = analogRead(pin_);
  if (value > 1000)
    return ButtonType::kButtonTypeNone;
  else if (value > 750 && value <= 1000)
    return ButtonType::kButtonTypeA;
  else if (value > 500 && value <= 750)
    return ButtonType::kButtonTypeB;
  else if (value > 350 && value <= 500)
    return ButtonType::kButtonTypeC;
  else if (value > 100 && value <= 350)
    return ButtonType::kButtonTypeD;
  else if (value == 0)
    return ButtonType::kButtonTypeE;
}

AdcButton::ButtonType AdcButton::DebouncedValue() {
  ButtonType value = GetButtonType();
  if (current_button_type_ != value) {
    current_button_type_ = value;
    last_read_time_ = millis();
  } else if (last_button_type_ != value && millis() - last_read_time_ > 50)
    last_button_type_ = value;
  return last_button_type_;
}

void AdcButton::Tick() {
  last_key_state_ = current_key_state_;
  current_key_state_ = DebouncedValue();
}

bool AdcButton::IsPressed(ButtonType key) {
  return last_key_state_ != key && current_key_state_ == key;
}

bool AdcButton::IsPressing(ButtonType key) {
  return current_key_state_ == key && last_key_state_ == key;
}

bool AdcButton::IsReleased(ButtonType key) {
  return last_key_state_ == key && current_key_state_ != key;
}
}  // namespace em