#include "msp.h"
#include "blink_LED.h"

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    LED_setup(); // initializes P1.0 for LED
    set_DCO(1,0);//set DCO speed with clock dividers
    monitor_mclk();//brings MCLK signal to P4.3
        while (1){// continuous loop
            P1->OUT &= ~BIT0;//low signal turns off LED off P1.0
            delay_ms(400); //delay 40ms
            P1->OUT |= BIT0;//high signal turns LED on P1.0
            delay_ms(400); //delay 40ms
        }
}
