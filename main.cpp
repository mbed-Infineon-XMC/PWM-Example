/* mbed Example Program
 * Copyright (c) 2006-2014 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************* Includes */
#include "mbed.h"
#include "rtos.h"

/******************************************************************** Globals */
PwmOut out1(LED1); //Change light intensity of LED1
PwmOut out2(LED2); //Blink LED1 with 1Hz.
Ticker flipper;

/****************************************************************** Functions */

/**
 * Change duty cycle periodically
 */
void change_duty_cycle() {

    static float duty = 0.0;
    static float dir = 1.0;

    if(duty > 0.7){
        dir = -1.0;
    }else if(duty < 0.0){
        dir = 1.0;
    }

    duty += (0.01 * dir);
    out1.write(duty);
}


/**
 * Main Function
 */
int main() {

    /* Create Ticker to periodically change duty cycle of LED1 */
    flipper.attach(&change_duty_cycle, 0.01);
    out1.period_ms(5);

    /* Configure LED2 Period=1s; Duty-Cycle = 50% */
    out2.period(1);
    out2.write(0.5);

    while (1) {
        wait(1);
    }
}

/*EOF*/
