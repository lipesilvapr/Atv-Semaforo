#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERMELHO 13
#define LED_AMARELO 11
#define LED_VERDE 12

// Variáveis globais para controlar o estado do semáforo
int estado_semaforo = 0; // 0: Vermelho, 1: Amarelo, 2: Verde

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado do semáforo
    switch (estado_semaforo) {
        case 0:
            gpio_put(LED_VERMELHO, 0); // Desliga vermelho
            gpio_put(LED_AMARELO, 1); // Liga amarelo
            estado_semaforo = 1;
            break;
        case 1:
            gpio_put(LED_AMARELO, 0); // Desliga amarelo
            gpio_put(LED_VERDE, 1);  // Liga verde
            estado_semaforo = 2;
            break;
        case 2:
            gpio_put(LED_VERDE, 0);   // Desliga verde
            gpio_put(LED_VERMELHO, 1); // Liga vermelho
            estado_semaforo = 0;
            break;
    }
    return true; // Continua o temporizador
}

int main() {
    // Inicializa o padrão de entrada/saída
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa o semáforo no estado vermelho
    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Cria um temporizador repetitivo de 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (1) {
        // Imprime uma mensagem a cada segundo
        printf("Semáforo em execução...\n");
        sleep_ms(1000);
    }

    return 0;
}