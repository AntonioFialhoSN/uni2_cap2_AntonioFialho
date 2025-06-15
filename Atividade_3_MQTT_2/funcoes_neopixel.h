/**
 * @file funcoes_neopixel.h
 * @brief Funções para geração de números aleatórios e controle de cores RGB
 */

#ifndef FUNCOES_NEOPIXEL_H
#define FUNCOES_NEOPIXEL_H

#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/regs/rosc.h"
#include "hardware/regs/addressmap.h"

// Estrutura para representar uma cor RGB
typedef struct {
    uint16_t r;  // Componente vermelho (0-65535)
    uint16_t g;  // Componente verde (0-65535)
    uint16_t b;  // Componente azul (0-65535)
} rgb_color_t;

/**
 * @brief Inicializa o gerador de números aleatórios usando o ROSC do RP2040
 * 
 * Deve ser chamada apenas uma vez no início do programa
 */
void inicializar_aleatorio();

/**
 * @brief Gera um número aleatório no intervalo [min, max]
 * 
 * @param min Valor mínimo do intervalo
 * @param max Valor máximo do intervalo
 * @return Número aleatório no intervalo especificado
 */
int numero_aleatorio(int min, int max);

#endif // FUNCOES_NEOPIXEL_H