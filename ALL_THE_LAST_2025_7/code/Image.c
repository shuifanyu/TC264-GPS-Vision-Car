/*
 * Image.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#include "zf_common_headfile.h"

    uint8 base_image[MT9V03X_H][MT9V03X_W];
    // 计算并绘制中线
    uint8_t left_line_list[MT9V03X_H];
    uint8_t right_line_list[MT9V03X_H];
    uint8_t mid_line_list[MT9V03X_H];
    float image_steering_duty;

// 大津法二值化处理
void mt9v03x_otsu_binarization(uint8_t (*image)[MT9V03X_W], uint8_t (*binary_image)[MT9V03X_W])
{
    uint16_t threshold = 0;               // 最佳阈值
    uint32_t histogram[256] = {0};       // 灰度直方图
    uint32_t total_pixels = MT9V03X_H * MT9V03X_W;
    uint32_t sum = 0;
    uint32_t sumB = 0;                   // 背景类累积灰度值
    uint32_t q1 = 0;                     // 背景类像素数
    float max_var = 0;                 // 最大类间方差

    // 计算直方图
    for (uint16_t i = 0; i < MT9V03X_H; i++)
    {
        for (uint16_t j = 0; j < MT9V03X_W; j++)
        {
            histogram[image[i][j]]++;
        }
    }

    // 计算总灰度值
    for (uint16_t i = 0; i < 256; i++)
    {
        sum += i * histogram[i];
    }

    // 大津法求最佳阈值
    for (uint16_t t = 0; t < 256; t++)
    {
        q1 += histogram[t];
        if (q1 == 0) continue;

        uint32_t q2 = total_pixels - q1;
        if (q2 == 0) break;

        sumB += t * histogram[t];
        float u1 = (float)sumB / q1;          // 背景均值
        float u2 = (float)(sum - sumB) / q2;  // 前景均值
        float var = q1 * q2 * (u1 - u2) * (u1 - u2); // 类间方差

        if (var > max_var)
        {
            max_var = var;
            threshold = t;
        }
    }

    // 应用阈值进行二值化
    for (uint16_t i = 0; i < MT9V03X_H; i++)
    {
        for (uint16_t j = 0; j < MT9V03X_W; j++)
        {
            binary_image[i][j] = (image[i][j] >= threshold) ? 255 : 0;
        }
    }
}



void Find_Mid_Line(uint8_t image[][MT9V03X_W])
{
    uint8_t left_point = 1;
    uint8_t right_point = MT9V03X_W - 1;

    // 初始化首行数据
    left_line_list[0] = 1;
    right_line_list[0] = MT9V03X_W - 1;
    mid_line_list[0] = (left_point + right_point) / 2;

    for(uint8_t i = MT9V03X_H - 1; i > 0; i--)
    {
        uint8_t found_left = 0;
        uint8_t found_right = 0;

        // 中间搜索策略
        if(image[i][MT9V03X_W/2] == WHITE)
        {
            // 搜索左边界
            for(uint8_t j = MT9V03X_W/2; j > 1; j--){
                if((image[i][j] == BLACK) && (image[i][j+1] == WHITE)){
                    left_point = j;
                    found_left = 1;
                    break;
                }
            }
            // 搜索右边界
            for(uint8_t j = MT9V03X_W/2; j < MT9V03X_W-1; j++){
                if((image[i][j] == BLACK) && (image[i][j-1] == WHITE)){
                    right_point = j;
                    found_right = 1;
                    break;
                }
            }
        }
        else if(image[i][MT9V03X_W/4] == WHITE)
            {
                // 搜索左边界
                for(uint8_t j = MT9V03X_W/4; j > 1; j--){
                    if((image[i][j] == BLACK) && (image[i][j+1] == WHITE)){
                        left_point = j;
                        found_left = 1;
                        break;
                    }
                }
                // 搜索右边界
                for(uint8_t j = MT9V03X_W/4; j < MT9V03X_W/2-1; j++){
                    if((image[i][j] == BLACK) && (image[i][j-1] == WHITE)){
                        right_point = j;
                        found_right = 1;
                        break;
                    }
                }
            }
        else if(image[i][MT9V03X_W*3/4] == WHITE)
            {
                // 搜索左边界
                for(uint8_t j = MT9V03X_W*3/4; j > 1; j--){
                    if((image[i][j] == BLACK) && (image[i][j+1] == WHITE)){
                        left_point = j;
                        found_left = 1;
                        break;
                    }
                }
                // 搜索右边界
                for(uint8_t j = MT9V03X_W*3/4; j < MT9V03X_W-1; j++){
                    if((image[i][j] == BLACK) && (image[i][j-1] == WHITE)){
                        right_point = j;
                        found_right = 1;
                        break;
                    }
                }
            }
        else if((image[i][MT9V03X_W/4] == BLACK)&&(image[i][MT9V03X_W/2] == BLACK)&&(image[i][MT9V03X_W*3/4] == BLACK))
        {
            found_left = 0;
            found_right = 0;
        }


        // 未找到时从两边搜
        if(!found_left){
            // 搜索左边界
            for(uint8_t j = 1; j <187; j++)
            {
                    if((image[i][j] == BLACK) && (image[i][j+1] == WHITE))
                        {
                           left_point = j;
                           break;
                        }
            }
               }
               if(!found_right)
               {
                   // 搜索右边界
                   for(uint8_t j = 187; j >1; j--)
                   {
                       if((image[i][j] == BLACK) && (image[i][j-1] == WHITE))
                       {
                           right_point = j;
                           break;
                       }
                   }
               }

        // 边界保护
        left_point = (left_point < 1) ? 1 : left_point;
        right_point = (right_point >= MT9V03X_W) ? MT9V03X_W-1 : right_point;

        // 保存结果
        left_line_list[i] = left_point;
        right_line_list[i] = right_point;
        mid_line_list[i] = (left_point + right_point) / 2;
    }
}

void Find_Mid_Line_Draw_Line(void)
{
    for(uint8_t i = 0; i < MT9V03X_H-2; i++){
        ips200_draw_point(left_line_list[i], i, RGB565_BLUE);
        ips200_draw_point(left_line_list[i], i+1, RGB565_BLUE);
        ips200_draw_point(left_line_list[i], i+2, RGB565_BLUE);
        ips200_draw_point(right_line_list[i], i, RGB565_GREEN);
        ips200_draw_point(right_line_list[i], i+1, RGB565_GREEN);
        ips200_draw_point(right_line_list[i], i+2, RGB565_GREEN);

        ips200_draw_point(mid_line_list[i], i, RGB565_RED);
    }
}


// 舵机控制函数优化版本
void steering_image()
{
    // 有效性检查：确保处理的是有效帧数据
    if(mt9v03x_finish_flag == 0) return;

    // 数据采集与加权计算
    float weighted_sum = 0;
    float weight_total = 0;

    for(int i = 0; i < SAMPLE_ROWS; i++)
    {
        // 动态权重分配（核心区域3倍权重）
        float weight = (i >= CORE_START && i <= CORE_END) ? 3.0f : 1.0f;

        // 数据有效性验证
        if(mid_line_list[i] < 1 || mid_line_list[i] > MAX_POS-1){
            weight = 0; // 无效数据零权重
            continue;
        }

        weighted_sum += mid_line_list[i] * weight;
        weight_total += weight;
    }

    // 异常情况处理（无有效数据时保持上一状态）
    if(weight_total < 0.1f) return;

    // 计算加权平均值
    float mid_avg = weighted_sum / weight_total;

    // 动态范围映射（0~187 -> 96~56）
    // 理论公式：duty = 96 - (mid_avg / 187) * 40
    float target_duty = 96.0f - (mid_avg / MAX_POS) * 40.0f;

    // 低通滤波（平滑处理）
    static float filtered_duty = 76.0f; // 初始居中值
    filtered_duty = filtered_duty * (1-FILTER_FACTOR) + target_duty * FILTER_FACTOR;

    image_steering_duty=filtered_duty;
}


void image_control(void)
{

    if(mt9v03x_finish_flag)
           {
               // 执行图像处理流程
               mt9v03x_otsu_binarization(mt9v03x_image, base_image);
               Find_Mid_Line(base_image);//搜边
               // 显示处理结果
               ips200_show_gray_image(0, 0, (const uint8 *)base_image, MT9V03X_W, MT9V03X_H, 188, 120,0);       // 显示灰度图像
//               ips200_show_gray_image(0, 0, (const uint8 *)base_image, MT9V03X_W, MT9V03X_H, 188, 120,0);       // 显示灰度图像

               Find_Mid_Line_Draw_Line();//画线

               // image驱动舵机
               steering_image();

               mt9v03x_finish_flag = 0;
           }

}


void MT9V03_show(void)
{

    if(mt9v03x_finish_flag)
    {
        if(gpio_get_level(P20_6)==0)
        {
            mt9v03x_otsu_binarization(mt9v03x_image, base_image);
            ips200_displayimage03x((const uint8 *)base_image, MT9V03X_W, MT9V03X_H);                       // 显示二值化图像

        }
        else
        {
            ips200_displayimage03x((const uint8 *)mt9v03x_image, MT9V03X_W, MT9V03X_H);                       // 显示原始图像
        }
        mt9v03x_finish_flag = 0;
    }

}
