// Projeto: Controle de GPIOs com BitDogLab
// Objetivo: Controlar LEDs e um buzzer via comandos UART

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
// >>> ADICIONAR ESTA LINHA PARA USAR reset_usb_boot <<<
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
                // DEV_02: Ligar LED verde e desligar os demais
                ligar_led_verde();
                break;

            case '2':
                // DEV_03: Ligar LED azul e desligar os demais
                ligar_led_azul();
                break;

            case '3':
                // DEV_04: Ligar LED vermelho e desligar os demais
                ligar_led_vermelho();
                break;

            case '4':
                // DEV_05: Ligar todos os LEDs
                // [CÓDIGO DO DEV_05 AQUI]
                break;

            case '5':
                // DEV_06: Desligar todos os LEDs
                // [CÓDIGO DO DEV_06 AQUI]
                break;

            case '6':
                acionar_buzzer();
                break;

            case '7':
                // DEV_08: Habilitar o modo de gravação via reboot - DEV_01
                printf("Reiniciando para modo de gravação...\n");
                reset_usb_boot(0, 0);  // <-- Chamada para entrar em modo boot USB
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
{
    // [CÓDIGO DO DEV RESPONSÁVEL]
}

// Função para desligar todos os LEDs
void desligar_todos_leds()
{
    // [CÓDIGO DO DEV RESPONSÁVEL]
}

// Função para acionar o buzzer por 2 segundos
void acionar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}

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
