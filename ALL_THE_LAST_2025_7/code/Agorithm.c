/*
 * Agorithm.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#include "zf_common_headfile.h"
int32 TIM_0_flag=0;
int32 TIM_1_flag=0;

//===================================================PID_1===================================================



pid_param_t I_PID;
pid_param_t G_PID;

//限幅
float constrain_float(float amt, float low, float high)
{
    return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

//快速开方函数
float Sqrt_Fast(float x)
{
    float halfx = 0.5f * x;
    float y = x;
    long i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *) &i;
    y = y * (1.5f - (halfx * y * y));
    return y;
}

float PidLocCtrl(pid_param_t * pid, float error)
{

    G_PID.kp=1.1;
    G_PID.kd=5;

    I_PID.kp=2;
    I_PID.kd=1;

    /* 累积误差 */
    pid->integrator += error;

    /* 误差限幅 */
    constrain_float(pid->integrator, -pid->imax, pid->imax);


    pid->out_p = pid->kp * error;
    pid->out_i = pid->ki * pid->integrator;
    pid->out_d = pid->kd * (error - pid->last_error);

    pid->last_error = error;

    pid->out = pid->out_p + pid->out_i + pid->out_d;

//    if(pid->out>SERVO_MOTOR_LMAX)
//    {pid->out=SERVO_MOTOR_LMAX;}
//    if(pid->out<SERVO_MOTOR_RMIN)
//    {pid->out=SERVO_MOTOR_RMIN;}
    return pid->out;
//    printf("OUT:%d\n",pid->out);
}

float PidIncCtrl_L(pid_param_t * pid, float error)
{




    pid->out_p = pid->kp * (error - pid->last_error);
    pid->out_i = pid->ki * error;
    pid->out_d = pid->kd * ((error - pid->last_error) - pid->last_derivative);

    pid->last_derivative = error - pid->last_error;
    pid->last_error = error;

    pid->out += pid->out_p + pid->out_i + pid->out_d;
    return pid->out;
}

float PidIncCtrl_R(pid_param_t * pid, float error)
{



    pid->out_p = pid->kp * (error - pid->last_error);
    pid->out_i = pid->ki * error;
    pid->out_d = pid->kd * ((error - pid->last_error) - pid->last_derivative);

    pid->last_derivative = error - pid->last_error;
    pid->last_error = error;

    pid->out += pid->out_p + pid->out_i + pid->out_d;
    return pid->out;
}
//===================================================PID_1===================================================




