/*
 * Image.h
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#ifndef CODE_IMAGE_H_
#define CODE_IMAGE_H_

#define WHITE       255
#define BLACK       0
    // 配置参数
    #define SAMPLE_ROWS 35      // 采样前30行数据（视野最近区域）
    #define CORE_START 5       // 核心区域起始行
    #define CORE_END 20         // 核心区域结束行
    #define MAX_POS 188.0f      // 中线最大理论值
    #define FILTER_FACTOR 0.3f  // 低通滤波系数

extern float image_steering_duty;

void mt9v03x_otsu_binarization(uint8_t (*image)[MT9V03X_W], uint8_t (*binary_image)[MT9V03X_W]);// 大津法二值化处理函数声明
void Find_Mid_Line(uint8_t image[][MT9V03X_W]);
void Find_Mid_Line_Draw_Line(void);
void steering_image();

void image_control(void);
void MT9V03_show(void);



#endif /* CODE_IMAGE_H_ */
