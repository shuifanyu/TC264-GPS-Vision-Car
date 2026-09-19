/*
 * Agorithm.h
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#ifndef CODE_AGORITHM_H_
#define CODE_AGORITHM_H_


typedef struct
{
    float                kp;         //P
    float                ki;         //I
    float                kd;         //D
    float                imax;       //积分限幅

    float                out_p;  //KP输出
    float                out_i;  //KI输出
    float                out_d;  //KD输出
    float                out;    //pid输出

    float                integrator; //< 积分值
    float                last_error; //< 上次误差
    float                last_derivative;//< 上次误差与上上次误差之差
    unsigned long        last_t;     //< 上次时间
}pid_param_t;

extern int32 TIM_0_flag;
extern int32 TIM_1_flag;

extern pid_param_t I_PID;
extern pid_param_t G_PID;

float constrain_float(float amt, float low, float high);
float Sqrt_Fast(float x);

float PidLocCtrl(pid_param_t * pid, float error);
float PidIncCtrl_L(pid_param_t * pid, float error);
float PidIncCtrl_R(pid_param_t * pid, float error);





#endif /* CODE_AGORITHM_H_ */
