#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../include/comp_datas.h"
#include <time.h>

float get_cpu_temperature() {
    FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (!fp) return -1.0f;

    int temp_milli_celsius;
    if (fscanf(fp, "%d", &temp_milli_celsius) != 1) {
        fclose(fp);
        return -1.0f;
    }

    fclose(fp);
    return temp_milli_celsius / 1000.0f;
}

uint64_t get_exact_time() {
    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);
    // Convert seconds and nanoseconds to a single nanoseconds value
    return (uint64_t)now.tv_sec * 1000000000UL + now.tv_nsec;
}

