#include <Mux.h>
#include <Timer.h>
#ifndef STRUCTS_H_
#define STRUCTS_H_

class D_Input {
    private:
        bool relased;
        int pin_input;
        int input_state;
        int pin_output;
        unsigned long time_interval;
        unsigned long time_pressed;

    public:
        D_Input (const int pin_in, const int pin_out, unsigned long time_pressed)
        {
            this->pin_input = pin_in;
            this->pin_output = pin_out;
            this->time_pressed = 0;
            this->relased = true;
            pinMode(this->pin_input, INPUT_PULLUP);
            if (this->pin_output != -1)
                pinMode(this->pin_output, OUTPUT);
        }

        void get_value()
        {
            this->input_state = digitalRead(this->pin_input);
        }

        void send_canbus()
        {
            int hexValue;
            //String hexString = String(input_state ? 1 : 0, HEX);
            //sscanf(hexString.c_str(), "%x", &hexValue);
        }
} ;

class A_Input_Multiplexor {
    private:
        int pin_input;
        int input_value;

    public:
        void init_input(const int pin_in)
        {
            this->pin_input = pin_in;
        }
        void get_value()
        {
            this->input_value = analogRead(this->pin_input);
        }

        void send_canbus()
        {
            //int hexValue;
            //String hexString = String(input_state ? 1 : 0, HEX);
            //sscanf(hexString.c_str(), "%x", &hexValue);
        }

} ;

class Var {
    private:
        int pos_mult;
        int *var;
        int value;
        admux::Mux *mult;
        unsigned int direction;

    public:
        Var(int *puntero_var, admux::Mux *mult, int pos, int dir)
        {
            this->var = puntero_var;
            this->mult = mult;
            this->pos_mult = pos;
            this->direction = dir;
        }

        void get_value()
        {
            int16_t readValue = mult->read(this->pos_mult);
            *var = readValue;
            value = readValue;
        }

        void send_value()
        {
            /*Serial.print("Value: ");
            Serial.println(value);
            Serial.print("Direccion: ");
            Serial.println(direction, HEX);*/
        }
};

class Stepper {
    private:
        int pin_pulse;
        int pin_dir;
        int pin_enable;

    public:
        Stepper(int pulse, int dir, int enable) {
            this->pin_pulse = pulse;
            this->pin_dir = dir;
            this->pin_enable = enable;

            pinMode(this->pin_pulse, OUTPUT);
            pinMode(this->pin_dir, OUTPUT);
            pinMode(this->pin_enable, OUTPUT);
        }
};

class Input_CanBus {
    private:
        int *var;
        uint8_t dir;
    public:
        Input_CanBus(int *variable, uint8_t direction)
        {
            this->var = variable;
            this->dir = direction;
        }
        void save_value(uint8_t value)
        {
            *this->var = value;
        }
        bool check_ID(uint8_t ID)
        {
            if (ID == dir)
                return true;
            return false;
        }
};

int degrees_goal;
//Multiplexor 
int temp_oil_1;
int temp_water_1;
int pres_oil_1;
int temp_oil_2;
int temp_water_2;
int pres_oil_2;
int rpm_1;
int rpm_2;
int lambda_1;
int lambda_2;
int temp_wheel_1;
int temp_wheel_2;
int temp_wheel_3;
int temp_wheel_4;
int temp_disc_1;
int temp_disc_2;
int temp_disc_3;
int temp_disc_4;
int pres_wheel_1;
int pres_wheel_2;
int pres_wheel_3;
int pres_wheel_4;
int amp_1;
int volt_1 = 100;
int amp_2;
int volt_2 = 100;
int gas_level;
int SDA_giro;
int SLC_giro;
int reserva_1;
int reserva_2;
int reserva_3;

int gear_1_error;
int gear_2_error;

int error_code = 0;


bool engine_1_on = false;
bool engine_2_on = false;
int led_speed = -1;

//INPUT CANBUS
D_Input *neutral_1;
D_Input *neutral_2;



//Pines
ezLED led_posterior(LED_BUILTIN);
//const int led_posterior = 13;
Timer timer_led;


//A_Input *pedal_brake;
//thermistor *temp_agua;

Stepper *stepper_gear_1;
Stepper *stepper_gear_2;
Stepper *stepper_bias;

#endif
