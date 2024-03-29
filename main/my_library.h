#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//#include <string>
#include <SPI.h>
#include "mcp2515_can.h"
#include <Mux.h>
#include <SoftwareSerial.h>
#include <thermistor.h>
#include <Servo.h>
#include <EEPROM.h>
#include <Arduino.h>
#include <Thread.h>
#include <trigger.h>
#include <EasyNextionLibrary.h>
#include <ThreadController.h>
#include <stdlib.h>
#include <ezLED.h>
#include "macros.h"
#include "structs.h"


//MACROS



using namespace admux;

const int spiCSPin = 2;
const int interruptPin = 10;

mcp2515_can CAN(10);

ThreadController Threads_controller = ThreadController();
//threads_structs* threads_array[NUM_THREADS];


EasyNex myNex(Serial);
//Entradas
SoftwareSerial gps(16,17);
Mux mult_1(Pin(A0, INPUT, PinType::Analog), Pinset(41, 42, 43, 44));
Mux mult_2(Pin(A9, INPUT, PinType::Analog), Pinset(45, 46, 47, 48));

int pulsador_paro;
int pulsador_flash;
int pulsador_3;
int pulsador_PM;
int pulsador_kers;
int pulsador_6;
int pulsador_anterior;
int pulsador_siguiente;
int pulsador_9;
int pulsador_drs;
int pulsador_leva_subir;
int pulsador_leva_bajar;

Input_CanBus inputs_canbus[12] = {
    Input_CanBus(&pulsador_paro, 0x28),
    Input_CanBus(&pulsador_flash, 0x29),
    Input_CanBus(&pulsador_3, 0x2A),
    Input_CanBus(&pulsador_PM, 0x2B),
    Input_CanBus(&pulsador_kers, 0x2C),
    Input_CanBus(&pulsador_6, 0x2D),
    Input_CanBus(&pulsador_anterior, 0x2E),
    Input_CanBus(&pulsador_siguiente, 0x2F),
    Input_CanBus(&pulsador_9, 0x30),
    Input_CanBus(&pulsador_drs, 0x31),
    Input_CanBus(&pulsador_leva_subir, 0x32),
    Input_CanBus(&pulsador_leva_bajar, 0x33),
};

Var vars_struct[32] = {
        Var(&temp_water_1, &mult_1, 0, 0x00),
        Var(&temp_water_2, &mult_1, 1, 0x01),
        Var(&temp_oil_1, &mult_1, 2, 0x02),
        Var(&temp_oil_2, &mult_1, 3, 0x03),
        Var(&pres_oil_1, &mult_1, 4, 0x04),
        Var(&pres_oil_2, &mult_1, 5, 0x05),
        Var(&rpm_1, &mult_1, 6, 0x06),
        Var(&rpm_2, &mult_1, 7, 0x07),
        Var(&lambda_1, &mult_1, 8, 0x08),
        Var(&lambda_2, &mult_1, 9, 0x09),
        Var(&SDA_giro, &mult_1, 10, 0x0A),
        Var(&SLC_giro, &mult_1, 11, 0x0B),
        Var(&temp_wheel_1, &mult_1, 12, 0x0C),
        Var(&temp_wheel_2, &mult_1, 13, 0x0D),
        Var(&temp_wheel_3, &mult_1, 14, 0x0E),
        Var(&temp_wheel_4, &mult_1, 15, 0x0F),
        Var(&temp_disc_1, &mult_1, 16, 0x10),
        Var(&temp_disc_2, &mult_2, 0, 0x11),
        Var(&temp_disc_3, &mult_2, 1, 0x12),
        Var(&temp_disc_4, &mult_2, 2, 0x13),
        Var(&pres_wheel_1, &mult_2, 3, 0x14),
        Var(&pres_wheel_2, &mult_2, 4, 0x15),
        Var(&pres_wheel_3, &mult_2, 5, 0x16),
        Var(&pres_wheel_4, &mult_2, 6, 0x17),
        Var(&amp_1, &mult_2, 7, 0x18),
        Var(&volt_1, &mult_2, 8, 0x19),
        Var(&amp_2, &mult_2, 9, 0x1A),
        Var(&volt_2, &mult_2, 10, 0x1B),
        Var(&gas_level, &mult_2, 11, 0x1C),
        Var(&reserva_1, &mult_2, 12, 0x1D),
        Var(&reserva_2, &mult_2, 13, 0x1E),
        Var(&reserva_3, &mult_2, 14, 0x1F),
};

//PROTOTIPOS
void init_inputs_outputs();

#endif
