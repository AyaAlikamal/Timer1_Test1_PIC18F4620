/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

volatile uint_32 timer1_on = ZERO_INIT;
timer1_config_t timer1_obj;
timer1_config_t counter1_obj;
void Timer1_Interrupt_Hundeller(void);

void timer1_timer_init(){
Std_ReturnType ret = E_NOT_OK;
timer1_obj.TMR1_Interrupt_Hundeler = Timer1_Interrupt_Hundeller;
timer1_obj.Timer_priority = Interrupt_Periority_LOW;
timer1_obj.timer1_mode = TIMER1_TIMER_MODE_CFG;
timer1_obj.timer1_prescaller = TIMER1_PRESACLER_VALUE_8;
timer1_obj.timer1_preload_value = 3036;
timer1_obj.timer1_register_size = TIMER1_REG_16BIT_MODE_CFG;
ret = Timer1_Init(&timer1_obj);
}


void timer1_Counter_init(){
Std_ReturnType ret = E_NOT_OK;
counter1_obj.TMR1_Interrupt_Hundeler = Timer1_Interrupt_Hundeller;
counter1_obj.Timer_priority = Interrupt_Periority_LOW;
counter1_obj.timer1_mode = TIMER1_COUNTER_MODE_CFG;
counter1_obj.timer1_prescaller = TIMER1_PRESACLER_VALUE_1;
counter1_obj.timer1_preload_value = 0;
counter1_obj.timer1_register_size = TIMER1_REG_16BIT_MODE_CFG;
counter1_obj.timer1_counter_mode = TIMER1_SYNC_Counter_CFG;
ret = Timer1_Init(&counter1_obj);
}
void timer1_timer_generate_500HZ(void){
Std_ReturnType ret = E_NOT_OK;
timer1_obj.TMR1_Interrupt_Hundeler = Timer1_Interrupt_Hundeller;
timer1_obj.Timer_priority = Interrupt_Periority_LOW;
timer1_obj.timer1_mode = TIMER1_TIMER_MODE_CFG;
timer1_obj.timer1_prescaller = TIMER1_PRESACLER_VALUE_1;
timer1_obj.timer1_preload_value = 64536;
timer1_obj.timer1_register_size = TIMER1_REG_16BIT_MODE_CFG;
ret = Timer1_Init(&timer1_obj);


}


led_t led1={
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF
};

int main() {
   
Std_ReturnType ret = E_NOT_OK;
//application_initialize();

ret = led_initialize(&led1);
timer1_timer_generate_500HZ();
while(1){
//      led_toggle(&led1);
}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   Std_ReturnType ret = E_NOT_OK;

}
void Timer1_Interrupt_Hundeller(){
    led_toggle(&led1);
    
}
