/*
 * GPS.h
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#ifndef CODE_GPS_H_
#define CODE_GPS_H_

#define Point_MAX   16
#define FLASH_SECTION_INDEX       (0)                                 // 存储数据用的扇区
#define FLASH_PAGE_INDEX          (11)                                // 存储数据用的页码 倒数第一个页码
#define SUB_1_PAGE_INDEX   (11)                                         //GPS存储页码
#define SUB_2_PAGE_INDEX   (10)                                         //GPS存储页码
#define SUB_3_PAGE_INDEX   (9)                                         //GPS存储页码

extern int    Index_1;
extern int N_1;//科目一索引变量
extern double LAT_data_1[Point_MAX];//科目一纬度存储数组
extern double LOG_data_1[Point_MAX];//科目一经度存储数组
extern double LAT_OUT_1 [Point_MAX]; //科目一纬度取回数组
extern double LOG_OUT_1 [Point_MAX]; //科目一经度取回数组

extern int    Index_2 ;               //科目二数组索引
extern int N_2;//科目一索引变量
extern double LAT_data_2[Point_MAX];//科目二纬度存储数组
extern double LOG_data_2[Point_MAX];//科目二经度存储数组
extern double LAT_OUT_2 [Point_MAX]; //科目一纬度取回数组
extern double LOG_OUT_2 [Point_MAX]; //科目一经度取回数组

extern int    Index_3 ;               //科目二数组索引
extern int N_3;//科目一索引变量
extern double LAT_data_3[Point_MAX];//科目二纬度存储数组
extern double LOG_data_3[Point_MAX];//科目二经度存储数组
extern double LAT_OUT_3 [Point_MAX]; //科目一纬度取回数组
extern double LOG_OUT_3 [Point_MAX]; //科目一经度取回数组



extern double Nomal_Error;
extern double Distance;
extern double Azimuth;


void GPS_init(void);
void GPS_parse(void);
void GPS_text(void);
void GPS_point_SUB1_get(void);
void GPS_point_SUB2_get(void);
void GPS_point_SUB3_get(void);
void GPS_flash_output(int sub) ;
void Follow_track(int SUB);



#endif /* CODE_GPS_H_ */
