#ifndef _MY_FUNC_
#define _MY_FUNC_


extern unsigned char gExti[];
extern unsigned int gExNum;
extern unsigned short gColor;
extern unsigned int toggle;
extern unsigned int clockCounter;
extern unsigned int xPos_, yPos_;

void obstacle(unsigned int px);
extern void ball_clear();
extern void gameStatus();
extern float distance();
extern void collision();
extern void shoot_2p();
extern void shoot_1p();
extern void move_2p();
extern void move_1p();
extern void darwAngleRange_2p();
extern void darwRange_2p();
extern void gameStart();
extern void darwAngleRange();
extern void darwRange();
extern void MyLcdTest();
extern void MySysTickTest();
extern void SysTick_with_LCD();
extern void MyJoyStickInterruptInit();
extern void MyLcdTest();
extern void MyDisplayBmp2c();
extern void Drop_block();
extern void drop_block();
extern void tet_start();
extern void test();
extern void super_mario();
extern void supermario();
extern void gamemain();
extern void MyUartTest();
extern void MyUartTestChat();
extern void draw_floor(unsigned int idx);
extern void draw_mario_run(unsigned int idx);
extern void draw_mario_asend(unsigned int idx);
extern void draw_mario_desend(unsigned int idx);

extern void draw_mario(unsigned int run_idx, unsigned int jmp_idx);
//extern void generate_obstacle(unsigned int idx);
extern void draw_turtle(unsigned int idx, unsigned int random);
extern void check_collison(unsigned int idx, unsigned int jmp_idx, unsigned int random);
extern void program_end();
extern int check_kill_turtle(unsigned int idx, unsigned int jmp_idx);
//extern void draw_dead_turtle(unsigned int idx);

extern void MyTest();
#endif
