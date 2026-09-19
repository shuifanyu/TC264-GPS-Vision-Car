/*
 * Menu.c
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */


#include "zf_common_headfile.h"

int  func_index = 0; //初始显示欢迎界面
int  last_index = 127; //last初始为无效值


void (*current_operation_index)(void);       //显示函数索引指针(当前操作索引)

key_table table_dispaly[100]=                 //结构体数组
{
//{索引，向上，向下，确认，显示函数}
    //第0层
    {0,0,0,1,(*fun_0)},                     //AIIT_meun

    //第1层
    {1,6,2, 7,(*fun_a1)},
    {2,1,3,13,(*fun_b1)},
    {3,2,4,19,(*fun_c1)},
    {4,3,5,25,(*fun_d1)},
    {5,4,6,31,(*fun_e1)},
    {6,5,1, 0,(*fun_f1)},

    //第2层
    {7,12, 8, 37, (*fun_a21)},
    {8, 7, 9, 38, (*fun_a22)},
    {9, 8, 10,39, (*fun_a23)},
    {10,9, 11,40, (*fun_a24)},
    {11,10,12,41, (*fun_a25)},
    {12,11,7,  1, (*fun_a26)},            //ESC

    {13,18,14,42, (*fun_b21)},
    {14,13,15,43, (*fun_b22)},
    {15,14,16,44, (*fun_b23)},
    {16,15,17,45, (*fun_b24)},
    {17,16,18,46, (*fun_b25)},
    {18,17,13, 2, (*fun_b26)},           //ESC

    {19,24,20,47, (*fun_c21)},
    {20,19,21,48, (*fun_c22)},
    {21,20,22,49, (*fun_c23)},
    {22,21,23,50, (*fun_c24)},
    {23,22,24,51, (*fun_c25)},
    {24,23,19,3,  (*fun_c26)},           //ESC

    {25,30,26,52, (*fun_d21)},
    {26,25,27,53, (*fun_d22)},
    {27,26,28,54, (*fun_d23)},
    {28,27,29,55, (*fun_d24)},
    {29,28,30,56, (*fun_d25)},
    {30,29,25,4,  (*fun_d26)},           //ESC

    {31,36,32,57, (*fun_e21)},
    {32,31,33,58, (*fun_e22)},
    {33,32,34,59, (*fun_e23)},
    {34,33,35,60, (*fun_e24)},
    {35,34,36,61, (*fun_e25)},
    {36,35,31,5,  (*fun_e26)},           //ESC

    //第3层
    {37,37,37,7, (*fun_a31)},
    {38,38,38,8, (*fun_a32)},
    {39,39,39,9, (*fun_a33)},
    {40,40,40,10,(*fun_a34)},
    {41,41,41,11,(*fun_a35)},

    {42,42,42,13,(*fun_b31)},
    {43,43,43,14,(*fun_b32)},
    {44,44,44,15,(*fun_b33)},
    {45,45,45,16,(*fun_b34)},
    {46,46,46,17,(*fun_b35)},

    {47,47,47,19,(*fun_c31)},
    {48,48,48,20,(*fun_c32)},
    {49,49,49,21,(*fun_c33)},
    {50,50,50,22,(*fun_c34)},
    {51,51,51,23,(*fun_c35)},

    {52,52,52,25,(*fun_d31)},
    {53,53,53,26,(*fun_d32)},
    {54,54,54,27,(*fun_d33)},
    {55,55,55,28,(*fun_d34)},
    {56,56,56,29,(*fun_d35)},

    {57,57,57,31,(*fun_e31)},
    {58,58,58,32,(*fun_e32)},
    {59,59,59,33,(*fun_e33)},
    {60,60,60,34,(*fun_e34)},
    {61,61,61,35,(*fun_e35)},
};


void Menu(void)//菜单函数
{



                if(key1_flag)
                {

                    func_index = table_dispaly[func_index].up;    //向上翻
                    key1_clear();
                }
                if(key2_flag)
                {

                    func_index = table_dispaly[func_index].down;    //向下翻
                     key2_clear();

                }
                if(key3_flag)
                {

                    func_index = table_dispaly[func_index].enter;    //确认
                    key3_clear();

                }


            if (func_index != last_index)
            {
                current_operation_index = table_dispaly[func_index].current_operation;

                ips200_clear();
                (*current_operation_index)();//执行当前操作函数
                last_index = func_index;

            }
            else
            {
                (*current_operation_index)();//执行当前操作函数
            }
  }


///*********第0层***********/
void fun_0()
{
    ips200_show_string(0,0,"2025.7.21.Team:PYX,WHB,XXL");


}

////////////////////////////////////////////////////////////////////////////////////////////////////////第一层///////////////////////////////////////////////////////////////////////////////////////////////////////////
void fun_a1()
{

    ips200_show_string(0,  16*1, "->");
    ips200_show_string(20, 16*1, "GPS");                 ips200_show_string(8*23, 16*19, "Page_1");
    ips200_show_string(20, 16*2, "B");
    ips200_show_string(20, 16*3, "TEXT");
    ips200_show_string(20, 16*4, "D");
    ips200_show_string(20, 16*5, "Go");
    ips200_show_string(20, 16*6, "ESC");

}

void fun_b1()
{
    ips200_show_string(0,  16*2, "->");
    ips200_show_string(20, 16*1, "GPS");                 ips200_show_string(8*23, 16*19, "Page_1");
    ips200_show_string(20, 16*2, "B");
    ips200_show_string(20, 16*3, "TEXT");
    ips200_show_string(20, 16*4, "D");
    ips200_show_string(20, 16*5, "Go");
    ips200_show_string(20, 16*6, "ESC");



}

void fun_c1()
{
    ips200_show_string(0,  16*3, "->");
    ips200_show_string(20, 16*1, "GPS");                 ips200_show_string(8*23, 16*19, "Page_1");
    ips200_show_string(20, 16*2, "B");
    ips200_show_string(20, 16*3, "TEXT");
    ips200_show_string(20, 16*4, "D");
    ips200_show_string(20, 16*5, "Go");
    ips200_show_string(20, 16*6, "ESC");



}

void fun_d1()
{
    ips200_show_string(0,  16*4, "->");
    ips200_show_string(20, 16*1, "GPS");                ips200_show_string(8*23, 16*19, "Page_1");
    ips200_show_string(20, 16*2, "B");
    ips200_show_string(20, 16*3, "TEXT");
    ips200_show_string(20, 16*4, "D");
    ips200_show_string(20, 16*5, "Go");
    ips200_show_string(20, 16*6, "ESC");

}

void fun_e1()
{
    ips200_show_string(0,  16*5, "->");
    ips200_show_string(20, 16*1, "GPS");                 ips200_show_string(8*23, 16*19, "Page_1");
    ips200_show_string(20, 16*2, "B");
    ips200_show_string(20, 16*3, "TEXT");
    ips200_show_string(20, 16*4, "D");
    ips200_show_string(20, 16*5, "Go");
    ips200_show_string(20, 16*6, "ESC");

}

void fun_f1()
{
    ips200_show_string(0,  16*6, "->");
    ips200_show_string(20, 16*1, "GPS");                 ips200_show_string(8*23, 16*19, "Page_1");
    ips200_show_string(20, 16*2, "B");
    ips200_show_string(20, 16*3, "TEXT");
    ips200_show_string(20, 16*4, "D");
    ips200_show_string(20, 16*5, "Go");
    ips200_show_string(20, 16*6, "ESC");

}

////////////////////////////////////////////////////////////////////////////////////////////////////////第二层///////////////////////////////////////////////////////////////////////////////////////////////////////////
void fun_a21()//
{
    ips200_show_string(0,  16*1, "->");
    ips200_show_string(20, 16*1, "sub_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "sub_2");
    ips200_show_string(20, 16*3, "sub_3");
    ips200_show_string(20, 16*4, "sub_4");
    ips200_show_string(20, 16*5, "Force_erase");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_a22()
{
    ips200_show_string(0,  16*2, "->");
    ips200_show_string(20, 16*1, "sub_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "sub_2");
    ips200_show_string(20, 16*3, "sub_3");
    ips200_show_string(20, 16*4, "sub_4");
    ips200_show_string(20, 16*5, "Force_erase");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_a23()
{
    ips200_show_string(0,  16*3, "->");
    ips200_show_string(20, 16*1, "sub_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "sub_2");
    ips200_show_string(20, 16*3, "sub_3");
    ips200_show_string(20, 16*4, "sub_4");
    ips200_show_string(20, 16*5, "Force_erase");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_a24()
{
    ips200_show_string(0,  16*4, "->");
    ips200_show_string(20, 16*1, "sub_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "sub_2");
    ips200_show_string(20, 16*3, "sub_3");
    ips200_show_string(20, 16*4, "sub_4");
    ips200_show_string(20, 16*5, "Force_erase");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_a25()
{
    ips200_show_string(0,  16*5, "->");
    ips200_show_string(20, 16*1, "sub_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "sub_2");
    ips200_show_string(20, 16*3, "sub_3");
    ips200_show_string(20, 16*4, "sub_4");
    ips200_show_string(20, 16*5, "Force_erase");
    ips200_show_string(20, 16*6, "ESC");
}
void fun_a26()
{
    ips200_show_string(0,  16*6, "->");
    ips200_show_string(20, 16*1, "sub_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "sub_2");
    ips200_show_string(20, 16*3, "sub_3");
    ips200_show_string(20, 16*4, "sub_4");
    ips200_show_string(20, 16*5, "Force_erase");
    ips200_show_string(20, 16*6, "ESC");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fun_b21()
{
    ips200_show_string(0,  16*1, "->");
    ips200_show_string(20, 16*1, "B_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "B_2");
    ips200_show_string(20, 16*3, "B_3");
    ips200_show_string(20, 16*4, "B_4");
    ips200_show_string(20, 16*5, "B_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_b22()
{
    ips200_show_string(0,  16*2, "->");
    ips200_show_string(20, 16*1, "B_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "B_2");
    ips200_show_string(20, 16*3, "B_3");
    ips200_show_string(20, 16*4, "B_4");
    ips200_show_string(20, 16*5, "B_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_b23()
{
    ips200_show_string(0,  16*3, "->");
    ips200_show_string(20, 16*1, "B_1");               ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "B_2");
    ips200_show_string(20, 16*3, "B_3");
    ips200_show_string(20, 16*4, "B_4");
    ips200_show_string(20, 16*5, "B_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_b24()
{
    ips200_show_string(0,  16*4, "->");
    ips200_show_string(20, 16*1, "B_1");               ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "B_2");
    ips200_show_string(20, 16*3, "B_3");
    ips200_show_string(20, 16*4, "B_4");
    ips200_show_string(20, 16*5, "B_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_b25()
{
    ips200_show_string(0,  16*5, "->");
    ips200_show_string(20, 16*1, "B_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "B_2");
    ips200_show_string(20, 16*3, "B_3");
    ips200_show_string(20, 16*4, "B_4");
    ips200_show_string(20, 16*5, "B_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_b26()
{
    ips200_show_string(0,  16*6, "->");
    ips200_show_string(20, 16*1, "B_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "B_2");
    ips200_show_string(20, 16*3, "B_3");
    ips200_show_string(20, 16*4, "B_4");
    ips200_show_string(20, 16*5, "B_5");
    ips200_show_string(20, 16*6, "ESC");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fun_c21()
{
    ips200_show_string(0,  16*1, "->");
    ips200_show_string(20, 16*1, "Motor_text");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Steer_text");
    ips200_show_string(20, 16*3, "Imu_text");
    ips200_show_string(20, 16*4, "Mt9v03_text");
    ips200_show_string(20, 16*5, "C_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_c22()
{
    ips200_show_string(0,  16*2, "->");
    ips200_show_string(20, 16*1, "Motor_text");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Steer_text");
    ips200_show_string(20, 16*3, "Imu_text");
    ips200_show_string(20, 16*4, "Mt9v03_text");
    ips200_show_string(20, 16*5, "C_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_c23()
{
    ips200_show_string(0,  16*3, "->");
    ips200_show_string(20, 16*1, "Motor_text");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Steer_text");
    ips200_show_string(20, 16*3, "Imu_text");
    ips200_show_string(20, 16*4, "Mt9v03_text");
    ips200_show_string(20, 16*5, "C_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_c24()
{
    ips200_show_string(0,  16*4, "->");
    ips200_show_string(20, 16*1, "Motor_text");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Steer_text");
    ips200_show_string(20, 16*3, "Imu_text");
    ips200_show_string(20, 16*4, "Mt9v03_text");
    ips200_show_string(20, 16*5, "C_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_c25()
{
    ips200_show_string(0,  16*5, "->");
    ips200_show_string(20, 16*1, "Motor_text");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Steer_text");
    ips200_show_string(20, 16*3, "Imu_text");
    ips200_show_string(20, 16*4, "Mt9v03_text");
    ips200_show_string(20, 16*5, "C_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_c26()
{
    ips200_show_string(0,  16*6, "->");
    ips200_show_string(20, 16*1, "Motor_text");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Steer_text");
    ips200_show_string(20, 16*3, "Imu_text");
    ips200_show_string(20, 16*4, "Mt9v03_text");
    ips200_show_string(20, 16*5, "C_5");
    ips200_show_string(20, 16*6, "ESC");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fun_d21()
{
    ips200_show_string(0,  16*1, "->");
    ips200_show_string(20, 16*1, "D_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "D_2");
    ips200_show_string(20, 16*3, "D_3");
    ips200_show_string(20, 16*4, "D_4");
    ips200_show_string(20, 16*5, "D_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_d22()
{
    ips200_show_string(0,  16*2, "->");
    ips200_show_string(20, 16*1, "D_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "D_2");
    ips200_show_string(20, 16*3, "D_3");
    ips200_show_string(20, 16*4, "D_4");
    ips200_show_string(20, 16*5, "D_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_d23()
{
    ips200_show_string(0,  16*3, "->");
    ips200_show_string(20, 16*1, "D_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "D_2");
    ips200_show_string(20, 16*3, "D_3");
    ips200_show_string(20, 16*4, "D_4");
    ips200_show_string(20, 16*5, "D_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_d24()
{
    ips200_show_string(0,  16*4, "->");
    ips200_show_string(20, 16*1, "D_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "D_2");
    ips200_show_string(20, 16*3, "D_3");
    ips200_show_string(20, 16*4, "D_4");
    ips200_show_string(20, 16*5, "D_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_d25()
{
    ips200_show_string(0,  16*5, "->");
    ips200_show_string(20, 16*1, "D_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "D_2");
    ips200_show_string(20, 16*3, "D_3");
    ips200_show_string(20, 16*4, "D_4");
    ips200_show_string(20, 16*5, "D_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_d26()
{
    ips200_show_string(0,  16*6, "->");
    ips200_show_string(20, 16*1, "D_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "D_2");
    ips200_show_string(20, 16*3, "D_3");
    ips200_show_string(20, 16*4, "D_4");
    ips200_show_string(20, 16*5, "D_5");
    ips200_show_string(20, 16*6, "ESC");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fun_e21()
{
    ips200_show_string(0,  16*1, "->");
    ips200_show_string(20, 16*1, "Start_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Start_2");
    ips200_show_string(20, 16*3, "Start_3");
    ips200_show_string(20, 16*4, "Start_4");
    ips200_show_string(20, 16*5, "E_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_e22()
{
    ips200_show_string(0,  16*2, "->");
    ips200_show_string(20, 16*1, "Start_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Start_2");
    ips200_show_string(20, 16*3, "Start_3");
    ips200_show_string(20, 16*4, "Start_4");
    ips200_show_string(20, 16*5, "E_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_e23()
{
    ips200_show_string(0,  16*3, "->");
    ips200_show_string(20, 16*1, "Start_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Start_2");
    ips200_show_string(20, 16*3, "Start_3");
    ips200_show_string(20, 16*4, "Start_4");
    ips200_show_string(20, 16*5, "E_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_e24()
{
    ips200_show_string(0,  16*4, "->");
    ips200_show_string(20, 16*1, "Start_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Start_2");
    ips200_show_string(20, 16*3, "Start_3");
    ips200_show_string(20, 16*4, "Start_4");
    ips200_show_string(20, 16*5, "E_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_e25()
{
    ips200_show_string(0,  16*5, "->");
    ips200_show_string(20, 16*1, "Start_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Start_2");
    ips200_show_string(20, 16*3, "Start_3");
    ips200_show_string(20, 16*4, "Start_4");
    ips200_show_string(20, 16*5, "E_5");
    ips200_show_string(20, 16*6, "ESC");
}

void fun_e26()
{
    ips200_show_string(0,  16*6, "->");
    ips200_show_string(20, 16*1, "Start_1");                ips200_show_string(8*23, 16*19, "Page_2");
    ips200_show_string(20, 16*2, "Start_2");
    ips200_show_string(20, 16*3, "Start_3");
    ips200_show_string(20, 16*4, "Start_4");
    ips200_show_string(20, 16*5, "E_5");
    ips200_show_string(20, 16*6, "ESC");
}



////////////////////////////////////////////////////////////////////////////////////////////////////////第三层///////////////////////////////////////////////////////////////////////////////////////////////////////////

void fun_a31()//科目一相关
{
    ips200_show_string(8*0,16*0,"LAT:");   ips200_show_float(8*5, 16*0, gnss.latitude, 4, 6);//在页面上展示实时经纬度
    ips200_show_string(8*0,16*1,"LOG:");   ips200_show_float(8*5, 16*1, gnss.longitude, 4, 6);

    if(key1_flag==1)//采点
    {
        key1_flag=0;
        GPS_point_SUB1_get();

    }

    if(key2_flag==1)//看点
    {
        key2_flag=0;
        ips200_clear();
        for(int i=0;i<Index_1;i++)
        {
                ips200_show_float(8*3,16*(i+3),LAT_data_1[i],4,6);        ips200_show_float(8*15,16*(i+3),LOG_data_1[i],4,6);   ips200_show_uint(8*0, 16*(i+3),i+1,2);
        }
    }

    if(key4_flag==1)//存点
    {
        key4_flag=0;
        GPS_flash_input(1);//科目一
    }
}

void fun_a32()//科目二相关
{
    ips200_show_string(8*0,16*0,"LAT:");   ips200_show_float(8*5, 16*0, gnss.latitude, 4, 6);//在页面上展示实时经纬度
    ips200_show_string(8*0,16*1,"LOG:");   ips200_show_float(8*5, 16*1, gnss.longitude, 4, 6);

    if(key1_flag==1)//采点
    {
        key1_flag=0;
        GPS_point_SUB2_get();
    }

    if(key2_flag==1)//看点
    {
        key2_flag=0;
        ips200_clear();
        for(int i=0;i<Index_2;i++)
        {
                ips200_show_float(8*3,16*(i+3),LAT_data_2[i],4,6);        ips200_show_float(8*15,16*(i+3),LOG_data_2[i],4,6);   ips200_show_uint(8*0, 16*(i+3),i+1,2);
        }
    }

    if(key4_flag==1)//存点
    {
        key4_flag=0;
        GPS_flash_input(2);//科目二
    }
}



void fun_a33()//科目三
{
    ips200_show_string(8*0,16*0,"LAT:");   ips200_show_float(8*5, 16*0, gnss.latitude, 4, 6);//在页面上展示实时经纬度
    ips200_show_string(8*0,16*1,"LOG:");   ips200_show_float(8*5, 16*1, gnss.longitude, 4, 6);

    if(key1_flag==1)//采点
    {
        key1_flag=0;
        GPS_point_SUB3_get();
    }

    if(key2_flag==1)//看点
    {
        key2_flag=0;
        ips200_clear();
        for(int i=0;i<Index_3;i++)
        {
                ips200_show_float(8*3,16*(i+3),LAT_data_3[i],4,6);        ips200_show_float(8*15,16*(i+3),LOG_data_3[i],4,6);   ips200_show_uint(8*0, 16*(i+3),i+1,2);
        }
    }

    if(key4_flag==1)//存点
    {
        key4_flag=0;
        GPS_flash_input(3);//科目三
    }
}

void fun_a34()//科目四
{

}


void fun_a35()//强制清除数据
{
    if(key1_flag==1)//清除科目1数据
    {
        key1_flag=0;
        flash_erase_page(FLASH_SECTION_INDEX, SUB_1_PAGE_INDEX);                //擦除Flash数据
        ips200_show_string(8*0,16*19,"Clear Flash SUB 111 !!!");
    }

    if(key2_flag==1)//清除科目2数据
    {
        key2_flag=0;
        flash_erase_page(FLASH_SECTION_INDEX, SUB_2_PAGE_INDEX);                //擦除Flash数据
        ips200_show_string(8*0,16*19,"Clear Flash SUB 222 !!!");
    }

    if(key4_flag==1)//清除科目3数据
    {
        key4_flag=0;
        flash_erase_page(FLASH_SECTION_INDEX, SUB_3_PAGE_INDEX);                //擦除Flash数据
        ips200_show_string(8*0,16*19,"Clear Flash SUB 333 !!!");
    }
}

void fun_b31()
{



}

void fun_b32()
{



}

void fun_b33()
{



}

void fun_b34()
{



}

void fun_b35()
{



}

void fun_c31()
{
    Key_close_flag=1;
    Motor_text();

}

void fun_c32()
{
    Key_close_flag=1;
    Steer_text();

}

void fun_c33()
{
    IMU_1_Open_flag=1;////开启中断中的imu();
    ips200_show_float(0, 0, angle_light, 4, 6);//显示YAW角数据

    if(key1_flag==1)//如果按键1按下则会触发惯性导航测试
    {
        key1_flag=0;
        I_navigation_flag=1;
    }

}

void fun_c34()
{
    MT9V03_show();

}


void fun_c35()
{


}

void fun_d31()
{


}

void fun_d32()
{


}

void fun_d33()
{


}

void fun_d34()
{


}


void fun_d35()
{


}

void fun_e31()//科目一
{

    static bool once = false;
    if (!once) {
        GPS_flash_output(1);//将存储好的科目1数据重新取回
        system_delay_ms(1000);
        ips200_show_string(0,0, "Subject 1 go! go! go!");
        for(int i=0;i<16;i++)
        {
                ips200_show_float(8*3,16*(i+3),LAT_OUT_1[i],4,6);        ips200_show_float(8*15,16*(i+3),LOG_OUT_1[i],4,6);   ips200_show_uint(8*0, 16*(i+3),i+1,2);
        }
        Buzzer_check(1000);
        once = true;
    }
         ips200_show_string(8*0,16*1, "A:"); ips200_show_float(8*3,16*1, Azimuth, 3, 2);    ips200_show_string(8*10,16*1, "Y:"); ips200_show_float(8*13,16*1, angle_light, 3, 2);   ips200_show_string(8*20,16*1, "E:"); ips200_show_float(8*23,16*1, Nomal_Error, 3, 2);
         ips200_show_string(8*0,16*2, "->:"); ips200_show_uint(8*3, 16*2,N_1+1,2);
         ips200_show_string(8*10,16*2, "D:"); ips200_show_float(8*13,16*2, Distance, 3, 2);

        G_navigation_flag=1;//开启中断中的G_navigation();
        IMU_1_Open_flag=1;//开启中断中的imu();

        Follow_track(1);
        gpio_toggle_level(LED1);
}

void fun_e32()//科目二
{
    static bool once = false;
    if (!once) {
        GPS_flash_output(2);//将存储好的科目3数据重新取回
        system_delay_ms(1000);
        ips200_show_string(0,0, "Subject 2 go! go! go!");
        for(int i=0;i<16;i++)
        {
                ips200_show_float(8*3,16*(i+3),LAT_OUT_2[i],4,6);        ips200_show_float(8*15,16*(i+3),LOG_OUT_2[i],4,6);   ips200_show_uint(8*0, 16*(i+3),i+1,2);
        }
        Buzzer_check(1000);
        once = true;
    }
        ips200_show_string(8*0,16*1, "A:"); ips200_show_float(8*3,16*1, Azimuth, 3, 2);    ips200_show_string(8*10,16*1, "Y:"); ips200_show_float(8*13,16*1, angle_light, 3, 2);   ips200_show_string(8*20,16*1, "E:"); ips200_show_float(8*23,16*1, Nomal_Error, 3, 2);
        ips200_show_string(8*0,16*2, "->:"); ips200_show_uint(8*3, 16*2,N_2+1,2);
        ips200_show_string(8*10,16*2, "D:"); ips200_show_float(8*13,16*2, Distance, 3, 2);
        G_navigation_flag=1;//开启中断中的G_navigation();
        IMU_1_Open_flag=1;//开启中断中的imu();

        Follow_track(2);
        gpio_toggle_level(LED2);
}

void fun_e33()//科目三
{
    static bool once = false;
    if (!once) {
        GPS_flash_output(3);//将存储好的科目3数据重新取回
        system_delay_ms(1000);
        ips200_show_string(0,0, "Subject 3 go! go! go!");
        for(int i=0;i<16;i++)
        {
                ips200_show_float(8*3,16*(i+3),LAT_OUT_3[i],4,6);        ips200_show_float(8*15,16*(i+3),LOG_OUT_3[i],4,6);   ips200_show_uint(8*0, 16*(i+3),i+1,2);
        }

        Buzzer_check(1000);
        once = true;
    }
        ips200_show_string(8*0,16*1, "A:"); ips200_show_float(8*3,16*1, Azimuth, 3, 2);    ips200_show_string(8*10,16*1, "Y:"); ips200_show_float(8*13,16*1, angle_light, 3, 2);   ips200_show_string(8*20,16*1, "E:"); ips200_show_float(8*23,16*1, Nomal_Error, 3, 2);
        ips200_show_string(8*0,16*2, "->:"); ips200_show_uint(8*3, 16*2,N_3+1,2);
        ips200_show_string(8*10,16*2, "D:"); ips200_show_float(8*13,16*2, Distance, 3, 2);
        G_navigation_flag=1;//开启中断中的G_navigation();
        IMU_1_Open_flag=1;//开启中断中的imu();

        Follow_track(3);
        gpio_toggle_level(LED3);
}

void fun_e34()
{


}


void fun_e35()
{


}



