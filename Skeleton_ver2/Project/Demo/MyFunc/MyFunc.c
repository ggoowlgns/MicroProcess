
#include "main.h"
#include "MyFunc.h"
#include "myuart.h"
#include "MyBMP.h"
#include <math.h>


int x_pos = 200;
int y_pos = 300;
int x_pos_ball;
int y_pos_ball;

int x_pos_2p = 200;
int y_pos_2p = 80;

int moveEnd = 0;
int PowerSelected = 0;
int RangeSelected = 0;

int moveEnd_2p = 0;
int PowerSelected_2p = 0;
int RangeSelected_2p = 0;


int v = 20;     //초기속력
float vx ;      //수직방향 속도
float vy ;      //수평방향 속도

int up = 1;     //위로 올라가는지 상태

float angle = 60.0;     //각도
void MyTest(){
  // To Add Your Functions
  //SysTick_with_LCD();
  
  //MyDisplayBmp2c();
 
  //main loop
  gameStart();
  
}
void gameStart(){
  STM3210B_LCD_Init();
  LCD_Clear(White);
  SPI_FLASH_Init();
  MyJoyStickInterruptInit();
  LCD_DrawArray(pic_tank_1_bmp, x_pos, y_pos, 40, 36);
  LCD_DrawArray(pic_tank_2_bmp, x_pos_2p, y_pos_2p, 40, 36);
  
  
  
  while(1){
    //Player 1
    move_1p();
    Delay(10);
    
    darwRange();    //power gauge
    Delay(10);
    darwAngleRange(); //set angle
    Delay(10);
    vx = (float)v*sin(angle * 3.1415926535897/180.0); // 수직방향으로의 속도
    vy = (float)v*cos(angle * 3.1415926535897/180.0);// 수평방향으로의 속도
    shoot_1p(); // 1p shoot
    Delay(10);
    
    //Player 2
    move_2p();
    Delay(10);
    darwRange_2p();
    Delay(10);
    darwAngleRange_2p();
    Delay(10);
    vx = (float)v*sin(angle * 3.1415926535897/180.0); // 수직방향으로의 속도
    vy = (float)v*cos(angle * 3.1415926535897/180.0);// 수평방향으로의 속도
    shoot_2p();
    Delay(30);
    
  }
}

void move_1p(){
  gExNum = (unsigned int)move_1p;
  while(1){
    MyLcdTest();
    LCD_DrawArray(pic_tank_1_bmp, x_pos, y_pos, 40, 36);
    
    
    if(moveEnd==1){
      moveEnd=0;
      break;
    }
    
    Delay(50);
  }
}


void move_2p(){
  gExNum = (unsigned int)move_2p;
  while(1){
    MyLcdTest();
    LCD_DrawArray(pic_tank_2_bmp, x_pos_2p, y_pos_2p, 40, 36);
    
    
    if(moveEnd_2p==1){
      moveEnd_2p=0;
      break;
    }
    
    Delay(50);
  }
}


void darwRange(){
  gExNum = (unsigned int)darwRange;
  while(1){
    
    draw_range1();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 5;
      break;
    }
    Delay(10);
    
    draw_range2();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 8;
      break;
    }
    Delay(10);
    
    draw_range3();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 11;
      break;
    }
    Delay(10);
    
    draw_range4();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 15;
      break;
    }
    Delay(10);
    
    draw_range5();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 20;
      break;
    }
    Delay(10);
    
    draw_range4();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 15;
      break;
    }
    Delay(10);
    
    draw_range3();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 11;
      break;
    }
    Delay(10);
    
    draw_range2();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 8;
      break;
    }
    Delay(10);
    
    draw_range1();
    if(PowerSelected==1){
      PowerSelected=0;
      v = 5;
      break;
    }
    Delay(10);
    
  }
}


void darwAngleRange(){
  
  gExNum = (unsigned int)darwAngleRange;
  while(1){
    draw_angle_range1();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 0;
       break;
    }
    Delay(10);
    draw_angle_range2();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 10;      
       break;
    }
    Delay(10);
    draw_angle_range3();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 30;
       break;
    }
    Delay(10);
    draw_angle_range4();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 45;
       break;
    }
    Delay(10);
    draw_angle_range5();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 55;
       break;
    }
    Delay(10);
    draw_angle_range6();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 65;
       break;
    }
    Delay(10);
    draw_angle_range7();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 75;
       break;
    }
    Delay(10);
    draw_angle_range6();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 65;
       break;
    }
    Delay(10);
    draw_angle_range5();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 55;
       break;
    }
    Delay(10);
    draw_angle_range4();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 45;
       break;
    }
    Delay(10);
    draw_angle_range3();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 30;
       break;
    }
    Delay(10);
    draw_angle_range2();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 10;
       break;
    }
    Delay(10);
    draw_angle_range1();
    if(RangeSelected ==1 ){
      RangeSelected =0;
      angle = 0;
       break;
    }
    Delay(10);
  }
}


///////////////2p/////////////////////


void darwRange_2p(){
  gExNum = (unsigned int)darwRange_2p;
  while(1){
    
    draw_range1_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 5;
        break;
      }
    Delay(10);
    draw_range2_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 8;
        break;
      }
    Delay(10);
    draw_range3_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 11;
        break;
      }
    Delay(10);
    draw_range4_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 15;
        break;
      }
    Delay(10);
    draw_range5_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 20;
        break;
      }
    Delay(10);
    draw_range4_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 15;
        break;
      }
    Delay(10);
    draw_range3_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 11;
        break;
      }
    Delay(10);
    draw_range2_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 8;
        break;
      }
    Delay(10);
    draw_range1_2p();
    if(PowerSelected_2p==1){
      PowerSelected_2p=0;
      v = 5;
        break;
      }
    Delay(10);
  }
}
  
  
void darwAngleRange_2p(){
  gExNum = (unsigned int)darwAngleRange_2p;
  while(1){
    draw_angle_range1_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 0;
       break;
    }
    Delay(10);
    draw_angle_range2_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 10;
       break;
    }
    Delay(10);
    draw_angle_range3_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 30;
       break;
    }
    Delay(10);
    draw_angle_range4_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 45;
       break;
    }
    Delay(10);
    draw_angle_range5_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 55;
       break;
    }
    Delay(10);
    draw_angle_range6_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 65;
       break;
    }
    Delay(10);
    draw_angle_range7_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 75;
       break;
    }
    Delay(10);
    draw_angle_range6_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 65;
       break;
    }
    Delay(10);
    draw_angle_range5_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 55;
       break;
    }
    Delay(10);
    draw_angle_range4_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 45;
       break;
    }
    Delay(10);
    draw_angle_range3_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 30;
       break;
    }
    Delay(10);
    draw_angle_range2_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 10;
       break;
    }
    Delay(10);
    draw_angle_range1_2p();
    if(RangeSelected_2p ==1 ){
      RangeSelected_2p =0;
      angle = 0;
       break;
    }
    Delay(10);
  }
  
}

void collision(){
  LCD_DrawArray(pic_boom_1_bmp,x_pos_ball,y_pos_ball,20,17);
  Delay(10);
  LCD_DrawArray(pic_boom_2_bmp,x_pos_ball,y_pos_ball,20,17);
  Delay(10);
  LCD_DrawArray(pic_boom_3_bmp,x_pos_ball,y_pos_ball,20,17);
  Delay(10);
  LCD_DrawArray(pic_boom_4_bmp,x_pos_ball,y_pos_ball,20,17);
  Delay(10);
}

void shoot_1p(){
    x_pos_ball = x_pos - 30;
    y_pos_ball = y_pos -60;
    while(1){
   if(up == 1){
   x_pos_ball -= (int)vx;
        
   vx -= 2.0;
   
      }
    else{
   x_pos_ball += (int) vx;
        
   vx += 2.0;
    }
    y_pos_ball -= vy;
   
   Delay(10);
    if(distance(x_pos_2p +23 ,y_pos_2p-40 , x_pos_ball , y_pos_ball)<=40){
      LCD_DrawArray(pic_tank_2_bmp, x_pos_2p, y_pos_2p, 40, 36);
      up=1;
      collision();
      break;
    }else{
      LCD_DrawArray(pic_black_ball6_bmp, x_pos_ball, y_pos_ball, 50, 50);
    }
    
    if(vx <= 0) up = 0;
    else if (x_pos_ball + vx >= 239 || y_pos_ball - 2*vy<= 0 || x_pos_ball - vx <= 0 ){ //맵밖으로 나갔을때 
      
      up = 1;
      break;
    }
    
    
  }
}



void shoot_2p(){
    x_pos_ball = x_pos_2p - 30;
    y_pos_ball = y_pos_2p + 10;
  while(1){
   if(up == 1){
   x_pos_ball -= (int)vx;
        
   vx -= 2.0;
   
      }
   
    else{
   x_pos_ball += (int) vx;
        
   vx += 2.0;
    }
    y_pos_ball += vy;
   
   
   Delay(10);
    
   if(distance(x_pos+23 ,y_pos , x_pos_ball , y_pos_ball)<=40){
      LCD_DrawArray(pic_tank_1_bmp, x_pos, y_pos, 40, 36);
      up = 1;
      collision();
      break;
    }else{
      LCD_DrawArray(pic_black_ball6_bmp, x_pos_ball, y_pos_ball, 50, 50);
    }
    if(vx <= 0) up = 0;
    else if (x_pos_ball + vx >= 239 || y_pos_ball + 2*vy>= 319 || x_pos_ball - vx <= 0 ){
      
      up = 1;
      break;
    }
    
    
  }
}


float distance(int x_tank, int y_tank , int x_ball , int y_ball){
   float y_chai = (float)(y_tank - y_ball);
   float x_chai = (float)(x_tank - x_ball);
   return sqrt((x_chai*x_chai)+(y_chai*y_chai));
}