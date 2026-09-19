/*
 * IMU_1.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#include "zf_common_headfile.h"

int IMU_1_Open_flag = 0;
int I_navigation_flag = 0;
int G_navigation_flag = 0;

float average,
      YAW,
      Angle_z,
      angle_light,
      test;
void imu(void)
{
    imu963ra_get_gyro();
//    imu660ra_get_gyro();
    float gyro = 0;
    float gyro_less = 0;
    float gyro_last = 0;
    float gyro_dt = 0.04;

    gyro_last = gyro_less ;
    gyro_less = gyro;

    gyro = ((float)imu963ra_gyro_z - average);
//    gyro = ((float)imu660ra_gyro_z - average);
    gyro = 0.5f * gyro + 0.3f * gyro_less + 0.2 *gyro_last;

    test = gyro;
    test = (int)test/10*10;
    YAW = -(float)((test)/14.3f)*gyro_dt;
//        YAW = -(float)((test)/16.4f)*gyro_dt;
    Angle_z += YAW;
    if(  Angle_z > 360)
       {
         Angle_z -=360;
       }
       else if(Angle_z <0)
       {
           Angle_z +=360;
       }
    angle_light += YAW;

    if(  angle_light > 180)
       {
         angle_light -=360;//修改180换360
       }
       else if(angle_light <-180)
       {
           angle_light +=360;//修改180换360
       }
}

//void imu_up()
//{
//    float data[3]={0.0};
//    int i,j;
//    for(i = 0; i<20 ; i++)
//    {
//        imu963ra_get_gyro();
//        data[2] +=imu963ra_gyro_z;
//    }
//    for(j =0 ; j < 3; j++)
//    {
//        average /= 20;
//    }
//}


