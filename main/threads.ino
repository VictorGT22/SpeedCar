#include "my_library.h"
String frase_final = "";

void setup_threads(void)
{ 
    //int i = 0;
    //while (i < num_threads) {
    /*threads_array[i] = new threads_structs;
    threads_array[i]->thread_ptr = new Thread();
    i++;
    }

    threads_array[0]->thread_ptr->onRun(thread_gears);
    threads_array[1]->thread_ptr->onRun(threads_throttle);
    threads_array[2]->thread_ptr->onRun(threads_buttons);
    threads_array[3]->thread_ptr->onRun(threads_target_gears);
    threads_array[4]->thread_ptr->onRun(threads_read_inputs);
    threads_array[5]->thread_ptr->onRun(threads_clutch);
    threads_array[6]->thread_ptr->onRun(threads_stop_motor);
    threads_array[7]->thread_ptr->onRun(threads_print_screen);
    threads_array[8]->thread_ptr->onRun(threads_dashboard);
    threads_array[9]->thread_ptr->onRun(threads_outputs);

    i = 0;
    while (i < num_threads) {
    Threads_controller.add(threads_array[i]->thread_ptr);
    i++;
    }*/
}
/*
void func_threads_control()
{
    int i = 1;
    while (i < num_threads) {
        if (threads_array[i]->thread_ptr->shouldRun()) {
            threads_array[i]->thread_ptr->run();
        }
        i++;
    }
}


void thread_gears(void)
{
    change_gears();
    //EEPROM.update(gear_ptr, 0);
    EEPROM.update(gear_ptr, var->current_gear);
}

void threads_throttle(void)
{
    if (var->mode_limit != 0)
        var->throttle_servo.write(map(var->rpm_launch, 0, 1023, 190, 80));
    else
        func_throttle();
}

void threads_buttons(void)
{
    get_buttons();
    change_modes();
    if (var->but_alarm->output_state)
    {
        var->alarm = 0;
        myNex.writeStr("page 0");
        var->but_alarm->output_state = LOW;
    }
}
void threads_target_gears(void)
{
    if (var->alarm != 1) {
        target_gears();
    }
}

void threads_read_inputs(void)
{
    read_inputs();
}

void threads_clutch(void)
{
    if (var->current_gear == 1 && var->clutch_pressed > 0) {
        relase_clutch_proportional();
    }
}

void threads_stop_motor(void)
{
    if (var->but_stop_motor->input_state) {
        digitalWrite(var->but_stop_motor->pin_output, LOW);
        digitalWrite(rele_motor, LOW);
        delay(1000);
        digitalWrite(rele_motor, HIGH);
    }
    if (cut_spark && millis() > time_final_cut) {
        cut_spark = 0;
        digitalWrite(rele_motor, HIGH);
    }
    if (cut_spark && millis() < time_final_cut)
        digitalWrite(rele_motor, LOW);
}

void threads_print_screen(void)
{
    //print_gears();
    //print_bat();
    //print_others();
    get_screen_info();
    Serial.println(var->rpm_launch);
    //analogWrite(var->but_limit->pin_output , map(num, 0, 100, 0, 255));

}

void threads_outputs(void)
{
    digitalWrite(var->but_neutral->pin_output, var->current_gear == NEUTRAL ? HIGH : LOW);
    digitalWrite(var->but_limit->pin_output, var->mode_limit ? HIGH : LOW);

    digitalWrite(var->but_stop_motor->pin_output, var->mode_kart == GAS_MODE || var->mode_kart == KERS_MODE ? HIGH : LOW);
    digitalWrite(var->but_mode->pin_output, var->mode_kart == ELEC_MODE ? HIGH : LOW);
    digitalWrite(var->but_kers->pin_output, var->mode_kart == KERS_MODE ? HIGH : LOW);
}
*/
void threads_dashboard(void)
{
    /*write_values_dash("$Max_TempAgua", 1);
    write_values_dash("$Max_TempAceite", 1);
    write_values_dash("$Max_SensAcc", 1);
    print_serial();
    write_values_dash("$Max_SensFreno", 1);
    write_values_dash("$Min_TempAgua", 1);
    write_values_dash("$Min_TempAceite", 1);
    print_serial();
    write_values_dash("$Min_SensAcc", 1);
    write_values_dash("$Min_SensFreno", 1);
    write_values_dash("$TempAgua", 1);
    print_serial();
    write_values_dash("$TempAceite", 1);
    write_values_dash("$SensAcelerador", var->pedal_throttle->input_value);
    write_values_dash("$SensFreno", var->pedal_brake->input_value);
    print_serial();
    write_values_dash("$EncoderGear", var->current_degrees);
    write_values_dash("$Revoluciones", var->current_degrees);
    write_values_dash("$TargetGear", var->target_gear);
    print_serial();
    write_values_dash("$Marcha", var->current_gear);
    print_serial();
    delay(50);*/
}
/*
void write_values_dash(String type, int value)
{
  frase_final.concat(type);
  frase_final.concat(",");
  frase_final.concat(value);
  frase_final.concat(",");
  frase_final.concat(";");
}

void print_serial()
{
  const char *final_string = "";
  frase_final.concat("\n\0");
  final_string = frase_final.c_str();
  Serial.write(final_string);
  Serial.flush();
  frase_final = "";
}
*/