//inclusão das bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"
#include "includes/funcoesMatriz.h"
#include "includes/convertePixels.h"
#include "animacoes/contagem.h"

//definição dos valores
#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3
#define LED_RED 13
#define BTN_A 5
#define BTN_B 6

//função para incrementar/decrementar matriz de leds
void mudarValor(uint8_t btn_counter, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);

int main() {
    //inicialização da matriz de leds
    npLED_t leds[LED_COUNT];
    int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH];
    stdio_init_all(); 
    matrizInit(LED_PIN, leds);

    //inicialização do led RGB vermelho
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);
    
    //inicialização do botão A
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);

    //inicialização do botão B
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);

    //Contador do valor da matriz
    uint8_t btn_counter;
    btn_counter = 0;

    //Começa exibindo 0 na matriz
    mudarValor(btn_counter, leds, rgb_matrix);

    while (true) {
        //Led RGB vermelho pisca continuamente 5x por segundo
        gpio_put(LED_RED, 1);
        sleep_ms(100);
        gpio_put(LED_RED, 0);
        sleep_ms(100);
        //Se o botão A for pressionado, incrementa o valor da matriz
        //Se o botão B for pressionado, decrementa o valor da matriz
        if (!gpio_get(BTN_A) && btn_counter < 9){
            btn_counter = btn_counter + 1;
            mudarValor(btn_counter, leds, rgb_matrix);
        } else if (!gpio_get(BTN_B) && btn_counter > 0){
            btn_counter = btn_counter - 1;
            mudarValor(btn_counter, leds, rgb_matrix);
        }
    }
}

//função para incrementar/decrementar matriz de leds
void mudarValor(uint8_t btn_counter, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
            convertARGBtoMatriz(contagem_regressiva[btn_counter], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
}

