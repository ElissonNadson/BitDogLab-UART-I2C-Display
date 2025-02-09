#include "button.h"
#include "pico/stdlib.h"
#include "pico/time.h"
#include "interrupt.h"

// Inicializa um botão (sem interrupção)
void inicializar_botao(uint8_t botaoGPIO) {
    gpio_init(botaoGPIO);
    gpio_set_dir(botaoGPIO, GPIO_IN);
    gpio_pull_up(botaoGPIO);
}

// Inicializa um botão (com interrupção)
void inicializar_botao_com_interrupcao(uint botaoGPIO, uint32_t evento, bool habilitado) {
    inicializar_botao(botaoGPIO);
    gpio_set_irq_enabled_with_callback(botaoGPIO, evento, habilitado, &manipulador_irq_gpio);
}

// Verifica se o botão foi pressionado
bool botao_pressionado(uint8_t botaoGPIO) {
    return !gpio_get(botaoGPIO);
}

// Tratamento de debouncing do botão
bool debouncing(uint32_t ms){
    static uint32_t ultimo_tempo = 0;
    uint32_t tempo_atual = to_ms_since_boot(get_absolute_time());
    if (tempo_atual - ultimo_tempo < ms)
        return false;
    ultimo_tempo = tempo_atual;
    return true;
}