/**
 * @~Chinese
 * @file get_button_status.ino
 * @brief 获取各按键状态。
 * @example get_button_status.ino
 */
/**
 * @~English
 * @file get_button_status.ino
 * @brief Get button status.
 * @example get_button_status.ino
 */
#include "adc_button.h"
#include "adc_button_lib.h"

const uint8_t adc_pin = A2;
em::AdcButton adc_button(adc_pin);

void setup() {
  Serial.begin(115200);  // 9600bps
  Serial.println(String("adc button lib version: ") + em::adc_button_lib::Version());
  Serial.println("please press any button on ADC pin!");
}

void loop() {
  adc_button.Tick();
  for (uint8_t i = static_cast<uint8_t>(em::AdcButton::ButtonType::kButtonTypeA);
       i <= static_cast<uint8_t>(em::AdcButton::ButtonType::kButtonTypeE);
       i++) {
    char buttonChar = 'A' + (i - static_cast<uint8_t>(em::AdcButton::ButtonType::kButtonTypeA));
    if (adc_button.IsPressed(static_cast<em::AdcButton::ButtonType>(i)))
      Serial.println(String("button ") + buttonChar + String(" is pressed!"));
    if (adc_button.IsPressing(static_cast<em::AdcButton::ButtonType>(i)))
      Serial.println(String("button ") + buttonChar + String(" is pressing!"));
    if (adc_button.IsReleased(static_cast<em::AdcButton::ButtonType>(i)))
      Serial.println(String("button ") + buttonChar + String(" is released!"));
  }
  delay(20);
}