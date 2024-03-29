#include "my_library.h"

void init_inputs_outputs()
{
    //gps.begin(9600);
    Serial.begin(9600);
    //myNex.begin(115200);
    /*
     * while (CAN_OK != CAN.begin(CAN_500KBPS))
    {
        Serial.println("CAN ERROR: al inicializar..");
    }
    Serial.println("CAN OK");
    */
    neutral_1 = new D_Input(3, -1, 0);
    neutral_2 = new D_Input(4, -1, 0);
   
    //STEPPER
    stepper_gear_1 = new Stepper(32, 33, 34);
    stepper_gear_2 = new Stepper(35, 36, 37);
    stepper_bias = new Stepper(38, 39, 40);
    
}
