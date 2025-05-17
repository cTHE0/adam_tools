#ifndef COMP_DATAS_H
#define COMP_DATAS_H

#include <stdint.h> 

// Lit la température CPU en degrés Celsius
// Retourne -1.0 en cas d'erreur
float get_cpu_temperature();
uint64_t get_exact_time();
#endif
