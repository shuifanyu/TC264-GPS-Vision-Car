/*
 * Common_Peripherals.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */



#include "zf_common_headfile.h"

//蜂鸣器----------------------------------------------------------------------------------------------------------

void Buzzer_init(void)//蜂鸣器初始化
{
    gpio_init(BUZZER_PIN, GPO, 0, GPO_PUSH_PULL);
}

void Buzzer_check(int time2)//蜂鸣器的自检函数
{
    gpio_set_level(BUZZER_PIN,1);
    system_delay_ms(time2);
    gpio_set_level(BUZZER_PIN,0);
}

//蜂鸣器----------------------------------------------------------------------------------------------------------

//按键与LED-------------------------------------------------------------------------------------------------------

uint8 key1_state = 1;                                                               // 按键动作状态
uint8 key2_state = 1;                                                               // 按键动作状态
uint8 key3_state = 1;                                                               // 按键动作状态
uint8 key4_state = 1;                                                               // 按键动作状态

uint8 switch1_state = 0;                                                            // 拨码开关动作状态
uint8 switch2_state = 0;                                                            // 拨码开关动作状态

uint8 key1_state_last = 0;                                                          // 上一次按键动作状态
uint8 key2_state_last = 0;                                                          // 上一次按键动作状态
uint8 key3_state_last = 0;                                                          // 上一次按键动作状态
uint8 key4_state_last = 0;                                                          // 上一次按键动作状态

uint8 switch1_state_last = 0;                                                       // 上一次拨码开关动作状态
uint8 switch2_state_last = 0;                                                       // 上一次拨码开关动作状态

uint8 key1_flag;
uint8 key2_flag;
uint8 key3_flag;
uint8 key4_flag;

uint8 key_val;


uint8 switch1_flag;
uint8 switch2_flag;

uint16 key1_count=-1;
uint16 key2_count=-1;
uint16 key3_count=-1;
uint16 key4_count=-1;

uint16 switch1_count=-1;
uint16 switch2_count=-1;

int Key_close_flag=0;//外部按键扫描隔绝标志位

void Key_init(void)//按键与LED初始化
{

       gpio_init(LED1, GPO, GPIO_HIGH, GPO_PUSH_PULL);         // 初始化 LED1 输出 默认高电平 推挽输出模式
       gpio_init(LED2, GPO, GPIO_HIGH, GPO_PUSH_PULL);         // 初始化 LED2 输出 默认高电平 推挽输出模式
       gpio_init(LED3, GPO, GPIO_HIGH, GPO_PUSH_PULL);         // 初始化 LED3 输出 默认高电平 推挽输出模式
       gpio_init(LED4, GPO, GPIO_HIGH, GPO_PUSH_PULL);         // 初始化 LED4 输出 默认高电平 推挽输出模式

       gpio_init(KEY1, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY1 输入 默认高电平 上拉输入
       gpio_init(KEY2, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY2 输入 默认高电平 上拉输入
       gpio_init(KEY3, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY3 输入 默认高电平 上拉输入
       gpio_init(KEY4, GPI, GPIO_HIGH, GPI_PULL_UP);           // 初始化 KEY4 输入 默认高电平 上拉输入

       gpio_init(SWITCH1, GPI, GPIO_HIGH, GPI_FLOATING_IN);    // 初始化 SWITCH1 输入 默认高电平 浮空输入
       gpio_init(SWITCH2, GPI, GPIO_HIGH, GPI_FLOATING_IN);    // 初始化 SWITCH2 输入 默认高电平 浮空输入

}

void key_scan(void)//按键扫描
    {


        //使用此方法优点在于，不需要使用while(1) 等待，避免处理器资源浪费

        //保存按键状态
        key1_state_last = key1_state;
        key2_state_last = key2_state;
        key3_state_last = key3_state;
        key4_state_last = key4_state;

        //读取当前按键状态
        key1_state = gpio_get_level(KEY1);
        key2_state = gpio_get_level(KEY2);
        key3_state = gpio_get_level(KEY3);
        key4_state = gpio_get_level(KEY4);


        //检测到按键按下之后  并放开置位标志位
        if(key1_state && !key1_state_last)   {key1_flag = 1;}
        if(key2_state && !key2_state_last)   {key2_flag = 1;}
        if(key3_state && !key3_state_last)   {key3_flag = 1;}
        if(key4_state && !key4_state_last)   {key4_flag = 1;}

        //标志位置位之后，可以使用标志位执行自己想要做的事件

//        system_delay_ms(10);//延时，按键程序应该保证调用时间不小于10ms

    }

void key1_clear(void)
{
  key1_flag=0;
  Buzzer_check(50);

}

void key2_clear(void)
{
  key2_flag=0;
  Buzzer_check(50);

}

void key3_clear(void)
{
  key3_flag=0;
  Buzzer_check(50);

}

void key4_clear(void)
{
  key4_flag=0;
  Buzzer_check(50);

}

//按键与LED-------------------------------------------------------------------------------------------------------

//舵机------------------------------------------------------------------------------------------------------------

void Steer_init(void)//舵机初始化
{
    pwm_init(SERVO_MOTOR_PWM, SERVO_MOTOR_FREQ, (uint32)SERVO_MOTOR_DUTY(SERVO_MOTOR_MID));
}

void Steer_set(int angle)//舵机驱动
{
    if(angle>SERVO_MOTOR_LMAX){angle=SERVO_MOTOR_LMAX;}
    if(angle<SERVO_MOTOR_RMAX){angle=SERVO_MOTOR_RMAX;}
    pwm_set_duty(SERVO_MOTOR_PWM, (uint32)SERVO_MOTOR_DUTY(angle));

}

void Steer_text(void)//舵机测试
{

       static int32 angle=SERVO_MOTOR_MID;

          key_scan();
          if(key1_flag)
             {
                 key1_flag=0;
                 angle+=10;
             }
          if(key2_flag)
             {
                 key2_flag=0;
                 angle-=10;
             }
          if(key3_flag)
             {
                 key3_flag=0;
                 angle=SERVO_MOTOR_LMAX;//左打死
             }
          if(key4_flag)
             {
                 key4_flag=0;
                 angle=SERVO_MOTOR_RMAX;//右打死
             }


          ips_show_string(0,100, "Steer_text");
          ips_show_int(100,  16*3,angle, 5);
          Steer_set(angle);
}
//舵机------------------------------------------------------------------------------------------------------------

//电机------------------------------------------------------------------------------------------------------------

void BLDC_init(void)//无刷电机初始化
{

    pwm_init(PWM_CH1, 1000, 0);                 //PWM引脚初始化
    gpio_init(DIR_CH1, GPO, 1, GPO_PUSH_PULL);  //方向引脚

}

void BLDC_ctrl(int16 Motor_SPEED)//BLDC驱动
{

    if(Motor_SPEED>=0)//正转
    {
        pwm_set_duty(PWM_CH1, (Motor_SPEED));
        gpio_set_level(DIR_CH1,1);
    }
    else             //反转
    {
        pwm_set_duty(PWM_CH1, -Motor_SPEED);
        gpio_set_level(DIR_CH1,0);
    }

}


void Motor_text(void)//电机测试
{

   static int16 MOTOR=0;


          key_scan();
          if(key1_flag)
             {
                 key1_flag=0;
                 MOTOR+=100;
             }
          if(key2_flag)
             {
                 key2_flag=0;
                 MOTOR-=100;

             }
          if(key3_flag)
             {
                 key3_flag=0;
                 MOTOR+=1000;
//                 MOTOR=100;
             }
          if(key4_flag)
             {
                 key4_flag=0;
                 MOTOR-=1000;
//                 MOTOR=190;


             }

          ips_show_string(0, 100, "Motor_text");
          ips_show_int(100,  16*3,MOTOR, 5);
          BLDC_ctrl(MOTOR);     //无刷



}

//电机------------------------------------------------------------------------------------------------------------

//摄像头----------------------------------------------------------------------------------------------------------

void MT9V03_text(void)
{
    while(1)
    {
        if(mt9v03x_finish_flag)
        {
            ips_show_string(0, 130, "MT9V03_text");
            ips200_displayimage03x((const uint8 *)mt9v03x_image, MT9V03X_W, MT9V03X_H);                       // 显示原始图像
    //            ips200_show_gray_image(0, 0, (const uint8 *)mt9v03x_image, MT9V03X_W, MT9V03X_H, 240, 180, 64);     // 显示二值化图像
            mt9v03x_finish_flag = 0;
        }
    }
}

//摄像头----------------------------------------------------------------------------------------------------------

