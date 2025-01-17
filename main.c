// Projeto: Controle de GPIOs com BitDogLab
// Objetivo: Controlar LEDs e um buzzer via comandos UART

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definições de GPIOs
#define LED_VERDE 11
#define LED_AZUL  12
#define LED_VERMELHO 13
#define BUZZER 21

// Protótipos das funções
void init_gpio();
void ligar_led(int gpio);
void desligar_todos_leds();
void acionar_buzzer();

int main() {
    stdio_init_all(); // Inicialização da UART
    init_gpio();

    printf("Sistema iniciado. Aguardando comandos...\n");

    while (1) {
        // Comando recebido via UART
        char comando = getchar_timeout_us(1000);

        switch (comando) {
            case '1':
                // DEV_02: Ligar LED verde e desligar os demais
;

            case '2':
                // DEV_03: Ligar LED azul e desligar os demais


            case '3':
                // DEV_04: Ligar LED vermelho e desligar os demais

            case '4':
                // DEV_05: Ligar todos os LEDs


            case '5':
                // DEV_06: Desligar todos os LEDs

            case '6':
                acionar_buzzer();
                break;


            case '7':
                // DEV_08: Habilitar o modo de gravação via reboot - DEV_01
                printf("Reiniciando para modo de gravação...\n");
                reset_usb_boot(0, 0);
                break;

            default:
                // Comando inválido
                break;
        }
    }

    return 0;
}

// DEV_01: Inicializar os GPIOs
void init_gpio() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Função para ligar um LED específico
void ligar_led(int gpio)

// Função para desligar todos os LEDs
void desligar_todos_leds()

// Função para acionar o buzzer por 2 segundos
void acionar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}
