#include "MyFunc.h"
#include "MyBMP.h"
#include "stm3210b_lcd.h"
#include "main.h"
extern int x_pos;
extern int y_pos;

extern int x_pos_2p;
extern int y_pos_2p;

/**********************************************
****************1 Player***********************
***********************************************/

void draw_range1() {
    LCD_DrawArray(pic_range_bar_1_bmp, x_pos, y_pos+20, 28, 47);
    MyLcdTest();  
    //Uart_SendString(string);
}


void draw_range2() {
    LCD_DrawArray(pic_range_bar_2_bmp, x_pos, y_pos+20, 28, 47);
    MyLcdTest();  
    //Uart_SendString(string);
}


void draw_range3() {
    LCD_DrawArray(pic_range_bar_3_bmp, x_pos, y_pos+20, 28, 47);
    MyLcdTest();  
    
    
    //Uart_SendString(string);
}


void draw_range4() {
    LCD_DrawArray(pic_range_bar_4_bmp, x_pos, y_pos+20, 28, 47);
    MyLcdTest();  
    
    
    //Uart_SendString(string);
}


void draw_range5() {
    LCD_DrawArray(pic_range_bar_5_bmp, x_pos, y_pos+20, 28, 47);
    MyLcdTest();  
    //Uart_SendString(string);
}

///////////////////////ANGLE/////////////////////////////////////////////

void draw_angle_range1() {
    LCD_DrawArray(pic_tank_1_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}
void draw_angle_range2() {
    LCD_DrawArray(pic_tank_2_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}
void draw_angle_range3() {
    
    LCD_DrawArray(pic_tank_3_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}
void draw_angle_range4() {
    LCD_DrawArray(pic_tank_4_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}
void draw_angle_range5() {
    LCD_DrawArray(pic_tank_5_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}
void draw_angle_range6() {
    LCD_DrawArray(pic_tank_6_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}
void draw_angle_range7() {
    LCD_DrawArray(pic_tank_7_angle_bmp, x_pos-6, y_pos-42, 20, 20);
    MyLcdTest();  
    //Uart_SendString(string);
}



/**********************************************
****************2 Player***********************
***********************************************/

void draw_range1_2p() {
    LCD_DrawArray(pic_range_bar_1_bmp, x_pos_2p, y_pos_2p-70, 28, 47);
    MyLcdTest();  
}


void draw_range2_2p() {
    LCD_DrawArray(pic_range_bar_2_bmp, x_pos_2p, y_pos_2p-70 , 28, 47);
    MyLcdTest();  
}


void draw_range3_2p() {
    LCD_DrawArray(pic_range_bar_3_bmp, x_pos_2p, y_pos_2p-70, 28, 47);
    MyLcdTest();  
    
    
}


void draw_range4_2p() {
    LCD_DrawArray(pic_range_bar_4_bmp,x_pos_2p, y_pos_2p-70, 28, 47);
    MyLcdTest();  
    
}


void draw_range5_2p() {
    LCD_DrawArray(pic_range_bar_5_bmp, x_pos_2p, y_pos_2p -70, 28, 47);
    MyLcdTest();  
}

///////////////////////ANGLE/////////////////////////////////////////////

void draw_angle_range1_2p() {
    LCD_DrawArray(pic_tank_1_angle_2p_bmp,  x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();
}
void draw_angle_range2_2p() {
    LCD_DrawArray(pic_tank_2_angle_2p_bmp, x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();  
}
void draw_angle_range3_2p() {
    LCD_DrawArray(pic_tank_3_angle_2p_bmp, x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();  
}
void draw_angle_range4_2p() {
    LCD_DrawArray(pic_tank_4_angle_2p_bmp, x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();  
}
void draw_angle_range5_2p() {
    LCD_DrawArray(pic_tank_5_angle_2p_bmp,x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();  
}
void draw_angle_range6_2p() {
    LCD_DrawArray(pic_tank_6_angle_2p_bmp, x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();  
}
void draw_angle_range7_2p() {
    LCD_DrawArray(pic_tank_7_angle_2p_bmp, x_pos_2p-6, y_pos_2p-17, 20, 20);
    MyLcdTest();  
}

