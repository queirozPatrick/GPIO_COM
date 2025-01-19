// Projeto: Controle de GPIOs com BitDogLab
// Objetivo: Controlar LEDs e um buzzer via comandos UART

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/bootrom.h"

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
                // Ligar LED verde e desligar os demais
                ligar_led_verde();
                break;

            case '2':
                // Ligar LED azul e desligar os demais
                ligar_led_azul();
                break;

            case '3':
                // Ligar LED vermelho e desligar os demais
                ligar_led_vermelho();
                break;

            case '4':
                // Ligar todos os LEDs
                // (Não solicitado neste momento)
                break;

            case '5':
                // Desligar todos os LEDs
                desligar_todos_leds();
                break;

            case '6':
                // Acionar buzzer por 2 segundos
                acionar_buzzer();
                break;

            case '7':
                // Habilitar o modo de gravação via reboot - DEV_01
                printf("Reiniciando para modo de gravação...\n");
                reset_usb_boot(0, 0);  // <-- Chamada para entrar em modo boot USB
                break;

            default:
                // Comando inválido ou timeout
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

// Função para ligar um LED específico (não utilizada diretamente aqui, mas serve de exemplo)
void ligar_led(int gpio) {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(gpio, 1);
}

// Função para desligar todos os LEDs
void desligar_todos_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

// Função para acionar o buzzer por 2 segundos
void acionar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}

// Funções específicas para cada LED
void ligar_led_verde() {
    gpio_put(LED_VERDE, 1);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

void ligar_led_azul() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 1);
    gpio_put(LED_VERMELHO, 0);
}

void ligar_led_vermelho() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 1);
}
