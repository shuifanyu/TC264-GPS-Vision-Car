/*
 * BD_ctrl.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#include "zf_common_headfile.h"

int Ctrl_flag=0;

void I_navigation(void)//惯性导航
{
    Steer_set(SERVO_MOTOR_MID-PidLocCtrl(&I_PID,0-angle_light));
    BLDC_ctrl(3000);

}


void G_navigation(void)//GPS导航
{
    Steer_set(SERVO_MOTOR_MID-PidLocCtrl(&G_PID,Nomal_Error));

}

