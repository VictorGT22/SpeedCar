
#include "my_library.h"

char dato=' ';
int ledEvent;
unsigned long time;

void setup()
{
    //led_posterior.blink(INTERMITENCIA_RAPIDA, INTERMITENCIA_RAPIDA);
    init_inputs_outputs();
    //time = millis();
}

void gps_information()
{
    /*if (gps.available)
    {
        dato = gps.read();
        //enviar por lo_ra
        Serial.println(dato);
    }*/
}


void get_inputs()
{
    neutral_1->get_value();
    neutral_2->get_value();

    for (int i = 0; i < 32; i++)
        vars_struct[i].get_value();
    /*if (CAN.checkReceive() == CAN_MSGAVAIL)
    {
        Serial.println("entra???");
        unsigned char len = 0;
        unsigned char buf[MAX_CHAR_IN_MESSAGE];
        uint8_t canId;
        if (CAN.readMsgBuf(&len, buf) == CAN_OK)
        {
            canId = CAN.getCanId();
            for (int i = 0; i < 12; i++)
            {
                if (inputs_canbus[i].check_ID(canId))
                    inputs_canbus[i].save_value(buf[0]);
            }
        }
    }*/
}

void send_errors()
{
    //if (temp_oil_1)
        error_code = 1;
    //if (temp_oil_2)
        error_code = 2;
    //if (temp_water_1)
        error_code = 3;
    //if (temp_water_2)
        error_code = 4;
    //if (temp_disc_1 || temp_disc_2 || temp_disc_3 || temp_disc_4)
        error_code = 5;
    //if (gas_level)
        error_code = 6;
    //if (gear_1_error)
        error_code = 7;
    //if (gear_2_error)
        error_code = 8;
    //send_canbus(ERROR_DIR, ERROR_CAMBIO_1);
}

void send_data()
{
    neutral_1->send_canbus();
    neutral_2->send_canbus();

    for (int i = 0; i < 32; i++)
        vars_struct[i].send_value();
    send_errors();
}

void send_canbus(uint8_t id, uint8_t data[])
{
    uint8_t dataLength = sizeof(data);
    if (CAN.sendMsgBuf(id, 0, dataLength, data) == CAN_OK)
        Serial.println("Mensaje enviado CanBus");
    else
        Serial.println("Error al ennviar mensjae CanBus");
}

void manage_light()
{
    if ((!engine_1_on || !engine_2_on) && led_speed != 0)
    {
        led_posterior.blink(INTERMITENCIA_LENTA, INTERMITENCIA_LENTA);
        led_speed = 0;

    }
    else if ((volt_1 <= 50 || volt_2 <= 50) && led_speed != 1)
    {
        led_posterior.blink(INTERMITENCIA_MEDIA, INTERMITENCIA_MEDIA);
        led_speed = 1;
    }
    else if (error_code >= 1 && error_code <= 4 && led_speed != 2)
    {
        led_posterior.blink(INTERMITENCIA_RAPIDA, INTERMITENCIA_RAPIDA);
        led_speed = 2;
    }

}


void loop()
{
    led_posterior.loop();
    manage_light();
    get_inputs();
    //Serial.println("entra!!!");
    send_data();
    
    //gps_information();
}
