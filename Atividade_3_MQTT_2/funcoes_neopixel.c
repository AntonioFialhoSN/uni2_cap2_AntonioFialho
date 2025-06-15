/**
 * @file funcoes_neopixel.c
 * @brief Implementação das funções para geração de números aleatórios
 */

#include "funcoes_neopixel.h"

// Flag para verificar se o gerador já foi inicializado
static bool aleatorio_inicializado = false;

void inicializar_aleatorio() {
    if (aleatorio_inicializado) return;
    
    // Usa o oscilador de anel (ROSC) do RP2040 como fonte de entropia
    uint32_t random = 0;
    for (int i = 0; i < 32; i++) {
        random <<= 1;
        random |= (1 & *((uint32_t*)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET)));
    }
    srand(random);
    
    aleatorio_inicializado = true;
}

int numero_aleatorio(int min, int max) {
    if (!aleatorio_inicializado) {
        inicializar_aleatorio();
    }
    
    if (min >= max) {
        return min;
    }
    
    return min + (rand() % (max - min + 1));
}