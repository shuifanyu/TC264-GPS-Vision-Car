/*
 * Menu.h
 *
 *  Created on: 2025年7月18日
 *      Author: P2855
 */

#ifndef CODE_MENU_H_
#define CODE_MENU_H_

//函数声明
void  Menu(void);//菜单函数



//结构体声明
typedef struct
{
    int current;
    int up;//向上翻索引号
    int down;//向下翻索引号
    int enter;//确认索引号
    void (*current_operation)();//当前页面的索引号要执行的显示函数，这是一个函数指针
}key_table;



extern  key_table table[100];

extern void fun_a1();
extern void fun_b1();
extern void fun_c1();
extern void fun_d1();
extern void fun_e1();
extern void fun_f1();

///////////////////////////////////////////////

extern void fun_a21();
extern void fun_a22();
extern void fun_a23();
extern void fun_a24();
extern void fun_a25();
extern void fun_a26();

extern void fun_b21();
extern void fun_b22();
extern void fun_b23();
extern void fun_b24();
extern void fun_b25();
extern void fun_b26();

extern void fun_c21();
extern void fun_c22();
extern void fun_c23();
extern void fun_c24();
extern void fun_c25();
extern void fun_c26();

extern void fun_d21();
extern void fun_d22();
extern void fun_d23();
extern void fun_d24();
extern void fun_d25();
extern void fun_d26();

extern void fun_e21();
extern void fun_e22();
extern void fun_e23();
extern void fun_e24();
extern void fun_e25();
extern void fun_e26();

//////////////////////////////////////////////

extern void fun_a31();
extern void fun_a32();
extern void fun_a33();
extern void fun_a34();
extern void fun_a35();

extern void fun_b31();
extern void fun_b32();
extern void fun_b33();
extern void fun_b34();
extern void fun_b35();

extern void fun_c31();
extern void fun_c32();
extern void fun_c33();
extern void fun_c34();
extern void fun_c35();

extern void fun_d31();
extern void fun_d32();
extern void fun_d33();
extern void fun_d34();
extern void fun_d35();

extern void fun_e31();
extern void fun_e32();
extern void fun_e33();
extern void fun_e34();
extern void fun_e35();



extern void fun_0();
void GPS_flash_input(int sub);



#endif /* CODE_MENU_H_ */
