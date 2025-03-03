/**
 * @~Chinese
 * @file get_button_type.ino
 * @brief 获取按键类型。
 * @example get_button_type.ino
 * 获取按键类型。
 */
/**
 * @~English
 * @file get_button_type.ino
 * @brief Get button type.
 * @example get_button_type.ino
 * Get button type.
 */
#include "adc_button.h"
#include "adc_button_lib.h"

uint8_t ADC_PIN = A2;
em::AdcButton adc_button(ADC_PIN);

void setup() {
  Serial.begin(115200);  // 9600bps
  Serial.println(String("adc button lib version: ") + em::adc_button_lib::Version());
}

void loop() {
  if (adc_button.GetButtonType() == em::AdcButton::ButtonType::kButtonTypeNone)
    Serial.println("no button is pressed!");
  else if (adc_button.GetButtonType() == em::AdcButton::ButtonType::kButtonTypeA)
    Serial.println("button A is pressed!");
  else if (adc_button.GetButtonType() == em::AdcButton::ButtonType::kButtonTypeB)
    Serial.println("button B is pressed!");
  else if (adc_button.GetButtonType() == em::AdcButton::ButtonType::kButtonTypeC)
    Serial.println("button C is pressed!");
  else if (adc_button.GetButtonType() == em::AdcButton::ButtonType::kButtonTypeD)
    Serial.println("button D is pressed!");
  else if (adc_button.GetButtonType() == em::AdcButton::ButtonType::kButtonTypeE)
    Serial.println("button E is pressed!");
  delay(200);
}