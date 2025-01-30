#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#include "includes/funcoesMatriz.h"
#include "includes/teclado.h"
#include "includes/convertePixels.h"

#include "animacoes/teste.h"
#include "animacoes/cobrinha.h"
#include "animacoes/contagem.h"

#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3

void a1(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void a2(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void a3(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void a4(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void a5(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void a9(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);

// Funções obrigatórias
void acendeAzulTotal(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void acendeVerdeTotal(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void acendeVermelho80(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void acendeBranco20(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);
void apagaTodosLeds(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);

int main() {
    npLED_t leds[LED_COUNT];
    int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH];

    stdio_init_all(); 
    keypad_init();

    matrizInit(LED_PIN, leds);

    while (true) {
        char key = keypad_read();
       
        if (key == '1') {
            // implementação da animação 1
            printf("TECLA PRESSIONADA: 1\n"); 
            a1(16, leds, rgb_matrix);
        } else if (key == '2') {
            // implementação da animação 2
            printf("TECLA PRESSIONADA: 2\n"); 
            a2(leds, rgb_matrix);
        } else if (key == '3') {
            // implementação da animação 3
            printf("TECLA PRESSIONADA: 3\n");
            a3(29, leds, rgb_matrix);
        } else if (key == '4') {
            // implementação da animação 4
            printf("TECLA PRESSIONADA: 4\n"); 
            a4(7, leds, rgb_matrix);
        } else if (key == '5') {
            // implementação da animação 5
            printf("TECLA PRESSIONADA: 5\n");
            a5(5, leds, rgb_matrix);
        } else if (key == '6') {
            // implementação da animação 6
            printf("TECLA PRESSIONADA: 6\n"); 
        } else if (key == '7') {
            // implementação da animação 7
            printf("TECLA PRESSIONADA: 7\n"); 
        } else if (key == '8') {
            // implementação da animação 8
            printf("TECLA PRESSIONADA: 8\n");
        } else if (key == '9') {
            // implementação da animação 9
            printf("TECLA PRESSIONADA: 9\n");
            a9(10, leds, rgb_matrix);
        } else if (key == '0') {
            // implementação da animação 10
            printf("TECLA PRESSIONADA: 0\n"); 
        } else if (key == 'A') {
            printf("TECLA PRESSIONADA: A\n");
            apagaTodosLeds(leds, rgb_matrix);
        } else if (key == 'B') {
            printf("TECLA PRESSIONADA: B\n"); 
            acendeAzulTotal(leds, rgb_matrix);
        } else if (key == 'C') {
            printf("TECLA PRESSIONADA: C\n");
            acendeVermelho80(leds, rgb_matrix);
        } else if (key == 'D') {
            printf("TECLA PRESSIONADA: D\n"); 
            acendeVerdeTotal(leds, rgb_matrix);
        } else if (key == '*') {
            printf("TECLA PRESSIONADA: *\n");
            reset_usb_boot(0, 0);
        } else if (key == '#') {
            printf("TECLA PRESSIONADA: #\n"); 
            acendeBranco20(leds, rgb_matrix);
        }

        sleep_ms(200);
    }
}

// Na estrutura da função a1, o parâmetro frames é o número de frames na animação, definida na hora da criação do array animacao1.
void a1(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    for (int j = 0; j < frames; j++) {
        convertARGBtoMatriz(animacao1[j], rgb_matrix);
        spriteWirite(rgb_matrix, leds);
        matrizWrite(leds); 
        sleep_ms(100); // Define a velocidade da animação
    }
    turnOffLEDs(leds); // Adicione trun off após o loop interno para desligar a matriz
}

void a2(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    // Ligar linha por linha
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 255; // R
            rgb_matrix[linha][col][1] = 0;   // G
            rgb_matrix[linha][col][2] = 0;   // B
        }
        spriteWirite(rgb_matrix, leds);
        matrizWrite(leds); 
        sleep_ms(500); // Pausa para visualizar a linha acendendo
    }

    // Desligar linha por linha
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 0; // R
            rgb_matrix[linha][col][1] = 0; // G
            rgb_matrix[linha][col][2] = 0; // B
        }
        spriteWirite(rgb_matrix, leds);
        matrizWrite(leds); 
        sleep_ms(500); // Pausa para visualizar a linha apagando
    }
}

void a3(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
        for (int i = 0; i < frames; i++) {
            convertARGBtoMatriz(cobrinha[i], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
            sleep_ms(300); // Define a velocidade da animação
        }
        turnOffLEDs(leds); // Adicione trun off após o loop interno para desligar a matriz
}

void a4(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    // Repete a animação 3 vezes
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < frames; j++) {
            convertARGBtoMatriz(animacao4[j], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
            sleep_ms(100); // Define a velocidade da animação
        }
    }
    turnOffLEDs(leds); // Desligando a matriz de led após a execução da animação
}

void a5(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
        for (int i = 0; i < frames; i++) {
            convertARGBtoMatriz(animacao5[i], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
            sleep_ms(1000); // Define a velocidade da animação
        }
        turnOffLEDs(leds); // Adicione trun off após o loop interno para desligar a matriz
}

void a9(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
        for (int i = 0; i < frames; i++) {
            convertARGBtoMatriz(contagem_regressiva[i], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
            sleep_ms(1000); // Define a velocidade da animação
        }
        turnOffLEDs(leds); // Adicione trun off após o loop interno para desligar a matriz
}

void acendeAzulTotal(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 0;   
            rgb_matrix[linha][col][1] = 0;   
            rgb_matrix[linha][col][2] = 255; // B (azul, 100% intensidade)
        }
    }
    // Atualiza os LEDs com a matriz configurada
    spriteWirite(rgb_matrix, leds);
    matrizWrite(leds); 
}

void acendeVerdeTotal(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 0;
            rgb_matrix[linha][col][1] = 255 * 0.5;  // D (todos leds verde, 50% intensidade) 
            rgb_matrix[linha][col][2] = 0;
        }
    }
    // Atualiza os LEDs com a matriz configurada
    spriteWirite(rgb_matrix, leds);
    matrizWrite(leds); 
}

void acendeVermelho80(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 255*0.8;   // c - acender leds vermelho a 80% da intensidade
            rgb_matrix[linha][col][1] = 0;   
            rgb_matrix[linha][col][2] = 0; 
        }
    }
    spriteWirite(rgb_matrix, leds);
    matrizWrite(leds); 
}

void acendeBranco20(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            // c - acender leds branco a 20% da intensidade
            rgb_matrix[linha][col][0] = 255*0.2; 
            rgb_matrix[linha][col][1] = 255*0.2;   
            rgb_matrix[linha][col][2] = 255*0.2; 
        }
    }
    spriteWirite(rgb_matrix, leds);
    matrizWrite(leds); 
}

void apagaTodosLeds(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    npClear(leds);
    matrizWrite(leds); 
}

