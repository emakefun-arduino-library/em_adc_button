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

  /**
   * @~Chinese
   * @brief 对读取的按钮值进行去抖动处理
   * @return 返回去抖动后的按钮值
   */
  /**
   * @~English
   * @brief Debounce the button value read
   * @return The debounced button value
   */
  ButtonType DebouncedValue(void);

  /**
   * @~Chinese
   * @brief 刷新按键状态。
   */
  /**
   * @~English
   * @brief Refresh button status.
   */
  void Tick(void);

  /**
   * @~Chinese
   * @brief 判断按键是否按下。
   * @param key 按键类型。
   * @return 返回按键是否按下。
   */
  /**
   * @~English
   * @brief Determine whether the button is pressed.
   * @param key Button type.
   * @return Whether the button is pressed.
   */
  bool IsPressed(ButtonType key);
  
  /**
   * @~Chinese
   * @brief 判断按键是否正在按下。
   * @param key 按键类型。
   * @return 返回按键是否正在按下。
   */
  /**
   * @~English
   * @brief Determine whether the button is being pressed.
   * @param key Button type.
   * @return Whether the button is being pressed.
   */
  bool IsPressing(ButtonType key);

  /**
   * @~Chinese
   * @brief 判断按键是否松开。
   * @param key 按键类型。
   * @return 返回按键是否松开。
   */
  /**
   * @~English
   * @brief Determine whether the button is released.
   * @param key Button type.
   * @return Whether the button is released.
   */
  bool IsReleased(ButtonType key);

 private:
  uint8_t pin_;
  ButtonType current_button_type_;
  ButtonType last_button_type_ = kButtonTypeNone;
  ButtonType last_key_state_ = kButtonTypeNone;
  ButtonType current_key_state_ = kButtonTypeNone;
  mutable uint64_t last_read_time_ = 0;
};
}  // namespace em
#endif