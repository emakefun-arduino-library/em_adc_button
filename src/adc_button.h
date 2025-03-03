/**
 * @file adc_button.h
 */
#pragma once

#ifndef ADC_BUTTON_H_
#define ADC_BUTTON_H_

#include <WString.h>
#include <stdint.h>

namespace em {
/**
 * @~Chinese
 * @class AdcButton
 * @brief AdcButton是ADC按键模块的驱动类。
 */
/**
 * @~English
 * @class AdcButton
 * @brief AdcButton is a driver class for the ADC button module.
 */
class AdcButton {
 public:
  /**
   * @~Chinese
   * @brief 按键类型枚举。
   */
  /**
   * @~English
   * @brief Button type enumeration.
   */
  enum ButtonType : uint8_t {
    kButtonTypeNone = 0,
    kButtonTypeA = 1,
    kButtonTypeB = 2,
    kButtonTypeC = 3,
    kButtonTypeD = 4,
    kButtonTypeE = 5,
  };
  /**
   * @~Chinese
   * @brief 构造函数。
   * @param pin ADC输入引脚。
   */
  /**
   * @~English
   * @brief Constructor.
   * @param pin ADC input pin.
   */
  explicit AdcButton(uint8_t pin);

  /**
   * @~Chinese
   * @brief 获取按键类型。
   * @return 返回什么类型按键按下。
   */
  /**
   * @~English
   * @brief Get button type.
   * @return What type of button is pressed.
   */
  ButtonType GetButtonType(void);

 private:
  uint8_t pin_;
};
}  // namespace em
#endif