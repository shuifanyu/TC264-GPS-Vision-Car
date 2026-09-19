/*
 * Common_Peripherals.h
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#ifndef CODE_COMMON_PERIPHERALS_H_
#define CODE_COMMON_PERIPHERALS_H_


#define BUZZER_PIN  (P33_10)

#define SERVO_MOTOR_PWM             (ATOM1_CH1_P33_9)                          // 定义主板上舵机对应引脚
#define SERVO_MOTOR_FREQ            (50)                                       // 定义主板上舵机频率
#define SERVO_MOTOR_MID             (95)                                       //中值95
#define SERVO_MOTOR_LMAX            (123)                                      //左打死
#define SERVO_MOTOR_RMAX            (67)                                       //右打死
#define SERVO_MOTOR_DUTY(x)         ((float)PWM_DUTY_MAX/(1000.0/(float)SERVO_MOTOR_FREQ)*(0.5+(float)(x)/90.0))// ------------------ 舵机占空比计算方式 ------------------


#define LED1                    (P20_9)
#define LED2                    (P20_8)
#define LED3                    (P21_5)
#define LED4                    (P21_4)

#define KEY1                    (P21_7)
#define KEY2                    (P11_3)
#define KEY3                    (P11_2)
#define KEY4                    (P20_6)

#define SWITCH2                 (P22_1)
#define SWITCH1                 (P22_2)


#define X6F_CH1                     (P10_3)      //方向舵通道
#define X6F_CH2                     (P10_1)      //油门通道

#define X6F_CH3                     (P10_1)      //指示按钮通道
#define X6F_CH4                     (P02_6)      //拨动挡位通道
#define X6F_CH5                     (P21_5)      //旋钮通道1
#define X6F_CH6                     (P21_3)      //旋钮通道2


//IPS200宏定义
#define ips_show_string                  ips200_show_string
#define ips_show_int                     ips200_show_int
#define ips_show_uint                    ips200_show_uint
#define ips_show_float                   ips200_show_float
#define ips_show_chinese                 ips200_show_chinese
#define ips_clear                        ips200_clear
#define ips_init                         ips200_init
#define ips_show_rgb565_image            ips200_show_rgb565_image


#define PWM_CH1             ATOM1_CH5_P02_5      //PWM输出端口
#define DIR_CH1             P02_4               //电机方向输出端口


extern uint8 key1_flag;
extern uint8 key2_flag;
extern uint8 key3_flag;
extern uint8 key4_flag;

extern int Key_close_flag;

void Buzzer_init(void);
void Buzzer_check(int time2);

void Key_init(void);
void key_scan(void);
void key1_clear(void);
void key2_clear(void);
void key3_clear(void);
void key4_clear(void);

void Steer_init(void);
void Steer_set(int angle);
void Steer_text(void);

void BLDC_init(void);
void BLDC_ctrl(int16 Motor_SPEED);
void Motor_text(void);

void MT9V03_text(void);







#endif /* CODE_COMMON_PERIPHERALS_H_ */
