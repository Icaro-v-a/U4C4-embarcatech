#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#include "includes/funcoesMatriz.h"
#include "includes/convertePixels.h"

#include "animacoes/contagem.h"

#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3
#define LED_RED 13
#define BTN_A 5
#define BTN_B 6

void mudarValor(uint8_t btn_counter, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);

int main() {
    npLED_t leds[LED_COUNT];
    int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH];
    uint8_t btn_counter;

    stdio_init_all(); 

    matrizInit(LED_PIN, leds);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);
    btn_counter = 0;

    convertARGBtoMatriz(contagem_regressiva[btn_counter], rgb_matrix);
    spriteWirite(rgb_matrix, leds);
    matrizWrite(leds);

    while (true) {
        gpio_put(LED_RED, 1);
        sleep_ms(100);
        gpio_put(LED_RED, 0);
        sleep_ms(100);
        if (!gpio_get(BTN_A) && btn_counter < 9){
            btn_counter = btn_counter + 1;
            mudarValor(btn_counter, leds, rgb_matrix);
        } else if (!gpio_get(BTN_B) && btn_counter > 0){
            btn_counter = btn_counter - 1;
            mudarValor(btn_counter, leds, rgb_matrix);
        }
    }
}

void mudarValor(uint8_t btn_counter, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
            convertARGBtoMatriz(contagem_regressiva[btn_counter], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
}

