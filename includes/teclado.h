#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"

#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

#define HIGH_LEVEL 1
#define LOW_LEVEL 0
#define NO_KEY_PRESSED 0

#define BUZZER_PIN 21

const uint8_t row_pins[KEYPAD_ROWS] = {15,14,13,12};
const uint8_t col_pins[KEYPAD_COLS] = {11,10,9,8};

const char key_map[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void keypad_init() {
  for (uint8_t i = 0; i < KEYPAD_ROWS; i++) {
    gpio_init(row_pins[i]);
    gpio_set_dir(row_pins[i], GPIO_OUT);
    gpio_put(row_pins[i], LOW_LEVEL);
  }

  for (uint8_t j = 0; j < KEYPAD_COLS; j++) {
    gpio_init(col_pins[j]);
    gpio_set_dir(col_pins[j], GPIO_IN);
    gpio_pull_down(col_pins[j]);
  }
}

char keypad_read() {
  for (uint8_t i = 0; i < KEYPAD_ROWS; i++) {
    gpio_put(row_pins[i], HIGH_LEVEL);

    for (uint8_t j = 0; j < KEYPAD_COLS; j++) {
      if (gpio_get(col_pins[j]) == HIGH_LEVEL) {
        sleep_ms(50);
        gpio_put(row_pins[i], LOW_LEVEL);

        return key_map[i][j];
      }
    }

    gpio_put(row_pins[i], LOW_LEVEL);
  }

  return NO_KEY_PRESSED;
}