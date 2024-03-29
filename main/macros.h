#include <Mux.h>
#include <Timer.h>
#ifndef MACROS_H_
#define MACROS_H_


#define NEUTRAL 0

#define GEAR_UP LOW
#define GEAR_DOWN HIGH
#define MAX_GEAR_ERROR 5
#define ENCODER_MAX 870

#define NUM_THREADS 2

#define INTERMITENCIA_RAPIDA 70
#define INTERMITENCIA_MEDIA 400
#define INTERMITENCIA_LENTA 900

#define ERROR_ACEITE_1 1
#define ERROR_ACEITE_2 2
#define ERROR_AGUA_1 3
#define ERROR_AGUA_2 4
#define ERROR_DISCOS 5
#define ERROR_LORA 6
#define ERROR_GPS 7
#define ERROR_GASOLINA 8
#define ERROR_CAMBIO_1 9
#define ERROR_CAMBIO_2 10

#define ERROR_DIR 0x20

//CODIGOS ERROR
uint8_t error_list[10][1] = {
    {0x01},
    {0x02},
    {0x03},
    {0x04},
    {0x05},
    {0x06},
    {0x07},
    {0x08},
    {0x09},
    {0x0A},
};

#endif
