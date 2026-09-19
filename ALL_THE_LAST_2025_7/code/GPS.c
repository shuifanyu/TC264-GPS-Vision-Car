/*
 * GPS.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */
#include "zf_common_headfile.h"


void GPS_init(void)
{
    gnss_init(GN42A);               // GN42A 为GPS模块 GN43RFA 为RTK模块
}

void GPS_parse(void)//GPS数据解析
{
    if(gnss_flag)
    {
        gnss_flag = 0;
        gnss_data_parse();           //开始解析数据
    }
}

void GPS_text(void)
{
    while(1)
    {
    ips200_show_uint(   0, 16*0, gnss.time.year, 4);
    ips200_show_uint(  80, 16*0, gnss.time.month, 2);
    ips200_show_uint( 160, 16*0, gnss.time.day, 2);
    ips200_show_uint(   0, 16*1, gnss.time.hour, 2);
    ips200_show_uint(  80, 16*1, gnss.time.minute, 2);
    ips200_show_uint( 160, 16*1, gnss.time.second, 2);

    ips200_show_uint(   0, 16*2, gnss.state, 5);
    ips200_show_float(120, 16*2, gnss.latitude, 4, 6);
    ips200_show_float(  0, 16*3, gnss.longitude, 4, 6);
    ips200_show_float(120, 16*3, gnss.speed, 4, 6);
    ips200_show_float(  0, 16*4, gnss.direction, 4, 6);
    ips200_show_uint( 120, 16*4, gnss.satellite_used, 5);
    ips200_show_float(  0, 16*5, gnss.height, 4, 6);
    }
}


int    Point_num=0;             //当前点位

int    Index_1 =0;               //科目一数组索引
double LAT_data_1[Point_MAX]={0};//科目一纬度存储数组
double LOG_data_1[Point_MAX]={0};//科目一经度存储数组
double LAT_OUT_1 [Point_MAX]={0}; //科目一纬度取回数组
double LOG_OUT_1 [Point_MAX]={0}; //科目一经度取回数组

int    Index_2 =0;               //科目二数组索引
double LAT_data_2[Point_MAX]={0};//科目二纬度存储数组
double LOG_data_2[Point_MAX]={0};//科目二经度存储数组
double LAT_OUT_2 [Point_MAX]={0}; //科目一纬度取回数组
double LOG_OUT_2 [Point_MAX]={0}; //科目一经度取回数组

int    Index_3 =0;               //科目三数组索引
double LAT_data_3[Point_MAX]={0};//科目三纬度存储数组
double LOG_data_3[Point_MAX]={0};//科目三经度存储数组
double LAT_OUT_3 [Point_MAX]={0}; //科目一纬度取回数组
double LOG_OUT_3 [Point_MAX]={0}; //科目一经度取回数组

//GPS数组存点------------------------------------------------------------------------------------------------------------------------------------

//科目1采点
void GPS_point_SUB1_get(void)
{
    if(Index_1<=Point_MAX)
                 {
                     LAT_data_1[Index_1]=gnss.latitude;//把实时维度赋值给存储纬度
                     LOG_data_1[Index_1]=gnss.longitude;//把实时经度赋值给存储经度

                     ips200_show_string(8*0,16*3,"R_LAT_1:");   ips200_show_float(8*8, 16*3, LAT_data_1[Index_1], 4, 6);
                     ips200_show_string(8*0,16*4,"R_LOG_1:");   ips200_show_float(8*8, 16*4, LOG_data_1[Index_1], 4, 6);

                     ips200_show_string(8*0,16*6,"Num:");     ips200_show_uint(8*5, 16*6, Index_1+1, 5);//数组是从0开始的,第一个点实际上是数组0,为了方便辨认+1
                     ips200_show_string(8*0,16*7,"MAX:17   SUB_1");
                     Index_1++;
                     Point_num=Index_1;
                 }

}


//科目2采点
void GPS_point_SUB2_get(void)
{
    if(Index_2<=Point_MAX)
                 {
                     LAT_data_2[Index_2]=gnss.latitude;//把实时维度赋值给存储纬度
                     LOG_data_2[Index_2]=gnss.longitude;//把实时经度赋值给存储经度

                     ips200_show_string(8*0,16*3,"R_LAT_2:");   ips200_show_float(8*8, 16*3, LAT_data_2[Index_2], 4, 6);
                     ips200_show_string(8*0,16*4,"R_LOG_2:");   ips200_show_float(8*8, 16*4, LOG_data_2[Index_2], 4, 6);

                     ips200_show_string(8*0,16*6,"Num:");     ips200_show_uint(8*5, 16*6, Index_2+1, 5);//数组是从0开始的,第一个点实际上是数组0,为了方便辨认+1
                     ips200_show_string(8*0,16*7,"MAX:17   SUB_2");
                     Index_2++;
                     Point_num=Index_2;
                 }

}

//科目3采点
void GPS_point_SUB3_get(void)
{
    if(Index_3<=Point_MAX)
                 {
                     LAT_data_3[Index_3]=gnss.latitude;//把实时维度赋值给存储纬度
                     LOG_data_3[Index_3]=gnss.longitude;//把实时经度赋值给存储经度

                     ips200_show_string(8*0,16*3,"R_LAT_3:");   ips200_show_float(8*8, 16*3, LAT_data_3[Index_3], 4, 6);
                     ips200_show_string(8*0,16*4,"R_LOG_3:");   ips200_show_float(8*8, 16*4, LOG_data_3[Index_3], 4, 6);

                     ips200_show_string(8*0,16*6,"Num:");     ips200_show_uint(8*5, 16*6, Index_3+1, 5);//数组是从0开始的,第一个点实际上是数组0,为了方便辨认+1
                     ips200_show_string(8*0,16*7,"MAX:17   SUB_3");
                     Index_3++;
                     Point_num=Index_3;
                 }

}

int32 double_to_int32(double y)
{
    int32 x = 0;
    x = (int32)(y*10000000);
    return x;
}

double int32_to_double(int32 y)
{
    double x = 0;
    x = (double)y * 1.0f / 10000000;
    return x;
}

void GPS_flash_input(int sub)
{
    if(sub==1)
    {
        printf("科目一\r\n");
        if(flash_check(FLASH_SECTION_INDEX, SUB_1_PAGE_INDEX))                      //判断Flash是否有数据
        {
            flash_erase_page(FLASH_SECTION_INDEX, SUB_1_PAGE_INDEX);                //擦除Flash数据
        }
        for(int i = 0; i < Index_1; i++)
        {
            flash_union_buffer[2*i].int32_type=double_to_int32(LAT_data_1[i]);
            flash_union_buffer[2*i+1].int32_type=double_to_int32(LOG_data_1[i]);

            printf("LAT_data_1=%7f,LOG_data_1=%7f\r\n", LAT_data_1[i],LOG_data_1[i]);
            printf("buffer_LAT=%d,buffer_LOG=%d\r\n", flash_union_buffer[2*i].int32_type,flash_union_buffer[2*i+1].int32_type);
            printf("\r\n");
        }
        flash_write_page_from_buffer(FLASH_SECTION_INDEX, SUB_1_PAGE_INDEX);        //将缓冲区的数据写入到指定Flash 扇区的页码
        Buzzer_check(300);
        ips200_show_string(8*0,16*19,"Storage_succeeded");

    }

    if(sub==2)
    {
        printf("科目二\r\n");
        if(flash_check(FLASH_SECTION_INDEX, SUB_2_PAGE_INDEX))                      //判断Flash是否有数据
        {
            flash_erase_page(FLASH_SECTION_INDEX, SUB_2_PAGE_INDEX);                //擦除Flash数据
        }
        for(int i = 0; i < Index_2; i++)
        {
            flash_union_buffer[2*i].int32_type=double_to_int32(LAT_data_2[i]);
            flash_union_buffer[2*i+1].int32_type=double_to_int32(LOG_data_2[i]);

            printf("LAT_data_2=%7f,LOG_data_2=%7f\r\n", LAT_data_2[i],LOG_data_2[i]);
            printf("buffer_LAT=%d,buffer_LOG=%d\r\n", flash_union_buffer[2*i].int32_type,flash_union_buffer[2*i+1].int32_type);
            printf("\r\n");
        }
        flash_write_page_from_buffer(FLASH_SECTION_INDEX, SUB_2_PAGE_INDEX);        //将缓冲区的数据写入到指定Flash 扇区的页码
        Buzzer_check(300);
        ips200_show_string(8*0,16*19,"Storage_succeeded");

    }

    if(sub==3)
    {
        printf("科目三\r\n");
        if(flash_check(FLASH_SECTION_INDEX, SUB_3_PAGE_INDEX))                      //判断Flash是否有数据
        {
            flash_erase_page(FLASH_SECTION_INDEX, SUB_3_PAGE_INDEX);                //擦除Flash数据
        }
        for(int i = 0; i < Index_3; i++)
        {
            flash_union_buffer[2*i].int32_type=double_to_int32(LAT_data_3[i]);
            flash_union_buffer[2*i+1].int32_type=double_to_int32(LOG_data_3[i]);

            printf("LAT_data_3=%7f,LOG_data_3=%7f\r\n", LAT_data_3[i],LOG_data_3[i]);
            printf("buffer_LAT=%d,buffer_LOG=%d\r\n", flash_union_buffer[2*i].int32_type,flash_union_buffer[2*i+1].int32_type);
            printf("\r\n");
        }
        flash_write_page_from_buffer(FLASH_SECTION_INDEX, SUB_3_PAGE_INDEX);        //将缓冲区的数据写入到指定Flash 扇区的页码
        Buzzer_check(300);
        ips200_show_string(8*0,16*19,"Storage_succeeded");

    }

}

void GPS_flash_output(int sub) {
    flash_buffer_clear();  // 清空缓冲区
    if (sub == 1) {
        // 1. 从 Flash 读取数据到缓冲区
        flash_read_page_to_buffer(FLASH_SECTION_INDEX, SUB_1_PAGE_INDEX);

        // 2. 转换数据并存储到 LAT_OUT_1 和 LOG_OUT_1
        for (int i = 0; i < 20; i++) {
            LAT_OUT_1[i] = int32_to_double(flash_union_buffer[2*i].int32_type);      // 偶数索引：纬度
            LOG_OUT_1[i] = int32_to_double(flash_union_buffer[2*i+1].int32_type);  // 奇数索引：经度


            printf("LAT_OUT_1=%7f, LOG_OUT_1=%7f\r\n", LAT_OUT_1[i], LOG_OUT_1[i]);
            printf("Raw LAT=%d, Raw LOG=%d\r\n",flash_union_buffer[2*i].int32_type,flash_union_buffer[2*i+1].int32_type);
            printf("\r\n");
        }


    }

    if (sub == 2) {
        // 1. 从 Flash 读取数据到缓冲区
        flash_read_page_to_buffer(FLASH_SECTION_INDEX, SUB_2_PAGE_INDEX);

        // 2. 转换数据并存储到 LAT_OUT_1 和 LOG_OUT_1
        for (int i = 0; i < 20; i++) {
            LAT_OUT_2[i] = int32_to_double(flash_union_buffer[2*i].int32_type);      // 偶数索引：纬度
            LOG_OUT_2[i] = int32_to_double(flash_union_buffer[2*i+1].int32_type);  // 奇数索引：经度


            printf("LAT_OUT_1=%7f, LOG_OUT_1=%7f\r\n", LAT_OUT_2[i], LOG_OUT_2[i]);
            printf("Raw LAT=%d, Raw LOG=%d\r\n",flash_union_buffer[2*i].int32_type,flash_union_buffer[2*i+1].int32_type);
            printf("\r\n");
        }


    }

    if (sub == 3) {
        // 1. 从 Flash 读取数据到缓冲区
        flash_read_page_to_buffer(FLASH_SECTION_INDEX, SUB_3_PAGE_INDEX);

        // 2. 转换数据并存储到 LAT_OUT_1 和 LOG_OUT_1
        for (int i = 0; i < 20; i++) {
            LAT_OUT_3[i] = int32_to_double(flash_union_buffer[2*i].int32_type);      // 偶数索引：纬度
            LOG_OUT_3[i] = int32_to_double(flash_union_buffer[2*i+1].int32_type);  // 奇数索引：经度


            printf("LAT_OUT_3=%7f, LOG_OUT_31=%7f\r\n", LAT_OUT_3[i], LOG_OUT_3[i]);
            printf("Raw LAT=%d, Raw LOG=%d\r\n",flash_union_buffer[2*i].int32_type,flash_union_buffer[2*i+1].int32_type);
            printf("\r\n");
        }


    }
}
//GPS数组存点------------------------------------------------------------------------------------------------------------------------------------

//核心循迹---------------------------------------------------------------------------------------------------------------------------------------

double Azimuth = 0;//方位角
double Distance = 0;//距离
double Nomal_Error = 0;//最终输出的角度偏差

int N_1 = 0;//科目一索引变量
int N_2 = 0;//科目二索引变量
int N_3 = 0;//科目三索引变量
void Follow_track(int SUB)
{
    if(SUB==1)//科目一
    {
            Azimuth=get_two_points_azimuth(gnss.latitude,gnss.longitude,LAT_OUT_1[N_1],LOG_OUT_1[N_1]);  //计算Azimuth
            Distance=get_two_points_distance(gnss.latitude,gnss.longitude,LAT_OUT_1[N_1],LOG_OUT_1[N_1]);//计算Distance

//            Azimuth+=90;//正东发车
//            Azimuth+=180;//正南发车
//            Azimuth+=270;//正西发车

            if(Azimuth>=180)//对正北发车
            {
                Azimuth-=360;//为了使GPS分成+-半轴
            }

           if(Azimuth-angle_light>180)
           {
               Nomal_Error=Azimuth-angle_light-360;
           }
           else if(Azimuth-angle_light<-180)
           {
               Nomal_Error=Azimuth-angle_light+360;
           }
           else
           {
               Nomal_Error=Azimuth-angle_light;
           }

           if(Distance<2)
           {
               N_1++;
           }

//定点速度--------------------------------------------------------------------------------------------------------------

//          if(N_1==0||N_1==1||N_1==2||N_1==3||N_1==4)
//          {
//                     BLDC_ctrl(1400);//无刷
//
//          }
//          if(N_1==5)//到达掉头点
//          {
//                     BLDC_ctrl(1000);//无刷
//
//          }
//          if(N_1==7||N_1==6||N_1==10||N_1==8||N_1==9)
//          {
//                     BLDC_ctrl(1400);//无刷
//
//          }
//          if(N_1==11)//停止点
//          {
//                     BLDC_ctrl(0);//无刷
//
//          }
          if(N_1==0)
          {
                     BLDC_ctrl(2000);//无刷

          }
          if(N_1==1||N_1==2||N_1==3||N_1==4||N_1==5)
          {
                     BLDC_ctrl(4500);//无刷

          }
          if(N_1==6)//到达掉头点
          {
                     BLDC_ctrl(2000);//无刷

          }
          if(N_1==7||N_1==8||N_1==9||N_1==10||N_1==11||N_1==12)
          {
                     BLDC_ctrl(4500);//无刷

          }
          if(N_1==13)//到达掉头点
          {
                     BLDC_ctrl(0);//无刷

          }

//定点速度--------------------------------------------------------------------------------------------------------------

    }

    if(SUB==2)
    {

            Azimuth=get_two_points_azimuth(gnss.latitude,gnss.longitude,LAT_OUT_2[N_2],LOG_OUT_2[N_2]);  //计算Azimuth
            Distance=get_two_points_distance(gnss.latitude,gnss.longitude,LAT_OUT_2[N_2],LOG_OUT_2[N_2]);//计算Distance

//            Azimuth+=90;//正东发车
//            Azimuth+=180;//正南发车
//            Azimuth+=270;//正西发车

            if(Azimuth>=180)//对正北发车
            {
                Azimuth-=360;//为了使GPS分成+-半轴
            }

           if(Azimuth-angle_light>180)
           {
               Nomal_Error=Azimuth-angle_light-360;
           }
           else if(Azimuth-angle_light<-180)
           {
               Nomal_Error=Azimuth-angle_light+360;
           }
           else
           {
               Nomal_Error=Azimuth-angle_light;
           }

           if(Distance<1)
           {
               N_2++;
           }

//定点速度--------------------------------------------------------------------------------------------------------------


           if(N_2==0)
           {
                      BLDC_ctrl(2000);//无刷
           }
           if(N_2==1||N_2==2||N_2==3||N_2==4)
           {
                      BLDC_ctrl(1500);//无刷

           }
           if(N_2==5)//到达掉头点
           {
                      BLDC_ctrl(1200);//无刷

           }
           if(N_2==6||N_2==7||N_2==8||N_2==9)
           {
                      BLDC_ctrl(1500);//无刷

           }
           if(N_2==10)
           {
                      BLDC_ctrl(2000);//无刷

           }
           if(N_2==11)//停止点
           {
                      BLDC_ctrl(0);//无刷

           }



//定点速度--------------------------------------------------------------------------------------------------------------

    }

    if(SUB==3)
    {

            Azimuth=get_two_points_azimuth(gnss.latitude,gnss.longitude,LAT_OUT_3[N_3],LOG_OUT_3[N_3]);  //计算Azimuth
            Distance=get_two_points_distance(gnss.latitude,gnss.longitude,LAT_OUT_3[N_3],LOG_OUT_3[N_3]);//计算Distance

//            Azimuth+=90;//正东发车
//            Azimuth+=180;//正南发车
//            Azimuth+=270;//正西发车

            if(Azimuth>=180)//对正北发车
            {
                Azimuth-=360;//为了使GPS分成+-半轴
            }

           if(Azimuth-angle_light>180)
           {
               Nomal_Error=Azimuth-angle_light-360;
           }
           else if(Azimuth-angle_light<-180)
           {
               Nomal_Error=Azimuth-angle_light+360;
           }
           else
           {
               Nomal_Error=Azimuth-angle_light;
           }

           if(Distance<1)
           {
               N_3++;
           }


           //定点速度--------------------------------------------------------------------------------------------------------------
           if(N_3==0||N_3==1||N_3==2||N_3==3||N_3==4)
           {
                      BLDC_ctrl(1500);//无刷

           }
           if(N_3==5)//到达掉头点
           {
                      BLDC_ctrl(1500);//无刷

           }
           if(N_3==7||N_3==6||N_3==10||N_3==8||N_3==9)
           {
                      BLDC_ctrl(1500);//无刷

           }
           if(N_3==11)//停止点
           {
                      BLDC_ctrl(0);//无刷

           }

//定点速度--------------------------------------------------------------------------------------------------------------

    }

}
//核心循迹---------------------------------------------------------------------------------------------------------------------------------------
