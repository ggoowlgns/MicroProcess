#include "main.h"
#include "MyFunc.h"
#include "MyBMP.h"
#include "myuart.h"
unsigned char gExti[16] = {0,};
unsigned int gExNum = 0;
unsigned short gColor;
unsigned int toggle = 0;
unsigned int clockCounter = 0;
unsigned int xPos_, yPos_;




static void
MyLedInit()
{
    // LEDs ==> LD1, LD2, LD3, LD4 => (PC6, PC7, PC8, PC9)
  //
  rRCC_APB2ENR = rRCC_APB2ENR | (1<<4); 
  bRCC_APB2ENR_IOPCEN = 1;  
  
  //  PC6 ==> output
  rGPIOC_CRL = rGPIOC_CRL & ~(0xf << 24);
  rGPIOC_CRL = rGPIOC_CRL | (0x3 << 24);
   
  //  PC7 ==> output
  rGPIOC_CRL = rGPIOC_CRL & ~(0xf << 28);
  rGPIOC_CRL = rGPIOC_CRL | (0x3 << 28);
  
  //  PC8 ==> output
  rGPIOC_CRH = rGPIOC_CRH & ~(0xf << 0);
  rGPIOC_CRH = rGPIOC_CRH | (0x3 << 0);
  
  //  PC9 ==> output
  rGPIOC_CRH = rGPIOC_CRH & ~(0xf << 4);
  rGPIOC_CRH = rGPIOC_CRH | (0x3 << 4);
}

void
MyJoyStickInterruptInit() {
  // 12 -> select
  // 0  -> right
  // 1  -> left
  // 8  -> up
  // 14 -> down    
  // Clock Enable for port D/E
  rRCC_APB2ENR = rRCC_APB2ENR | (1<<5) | (1<<6);
  
  //
  //	joystick (PD12, PD14, PE1, PE0, PD8)
  //
  //	unmasking
  rEXTI_IMR = rEXTI_IMR | (1<<12) | (1<<14) | (1<<1) | (1<<0) | (1<<8);
  rEXTI_FTSR = rEXTI_FTSR | (1<<12) | (1<<14) | (1<<1) | (1<<0) | (1<<8);
  
  // exti select (PD12, PD14, PE1, PE0, PD8)
  // for PD12
  rAFIO_EXTICR4 = rAFIO_EXTICR4 & ~(0xf << 0);
  rAFIO_EXTICR4 = rAFIO_EXTICR4 | (0x3 << 0);

  // for PD14
  rAFIO_EXTICR4 = rAFIO_EXTICR4 & ~(0xf << 8);
  rAFIO_EXTICR4 = rAFIO_EXTICR4 | (0x3 << 8);

  // for PE1
  rAFIO_EXTICR1 = rAFIO_EXTICR1 & ~(0xf << 4);
  rAFIO_EXTICR1 = rAFIO_EXTICR1 | (0x4 << 4);
  
  // for PE0
  rAFIO_EXTICR1 = rAFIO_EXTICR1 & ~(0xf << 0);
  rAFIO_EXTICR1 = rAFIO_EXTICR1 | (0x4 << 0); 
  
  // for PD8
  rAFIO_EXTICR3 = rAFIO_EXTICR3 & ~(0xf << 0);
  rAFIO_EXTICR3 = rAFIO_EXTICR3 | (0x3 << 0);
  
  //
  //	Set NVIC registers
  //
  // enable PE0 => EXTI0 (irq6)
  *(unsigned int *)0xE000E100 |= (0x1 << 6);
  // enable PE1 =>> EXTI1 (irq7)
  *(unsigned int *)0xE000E100 |= (0x1 << 7);

  // enable PD8 =>> EXTI9_5 (irq23)
  *(unsigned int *)0xE000E100 |= (0x1 << 23);
	
  // enable PD12/PD14 =>> EXTI15_10 (irq40)
  *(unsigned int *)0xE000E104 |= (0x1 << 8);
  
  
  /* // if you want to use port B switch interrupt
  // Clock Enable for port B
  rRCC_APB2ENR = rRCC_APB2ENR | (1<<3);
        	
  //	EXTI9, unmasking
  rEXTI_IMR = rEXTI_IMR | (1<<9);
     
  // PB9 ==> set as EXTI9
  rAFIO_EXTICR3 = rAFIO_EXTICR3 & ~(0xf << 4);
  rAFIO_EXTICR3 = rAFIO_EXTICR3 | (0x1 << 4);
  */
}


void MyUartTest() {
  STM3210B_LCD_Init();
  
  LCD_Clear(White);
  
  Uart_Printf("UART Test Success...\n");
  
  while(1) {
  };
}

void MyUartTestChat() {
 char ch;
  
 STM3210B_LCD_Init();
 
 LCD_Clear(White);
 Uart_Printf("UART Chat Test Success...\n");
 
 while(1) {
   ch = Uart_Getch();
   Uart_Printf("\nReceived Char : ");
   SendChar( (int) ch);
   Uart_Printf("\n");
 }
}
void MyGpioPollTest()
{
  MyLedInit();
  STM3210B_LCD_Init();
  LCD_Clear(White);
  SPI_FLASH_Init();

  
  //  joystick (PD12, PD14, PE1, PE0, PD8)
  
  // APB2 Peripheral Clock enable register
  // (RCC_APB2ENR).IOPDEN
  // (RCC_APB2ENR).IOPEEN
  // base : RCC(0x4002.1000) offset : 0x18h
  // Clock Enable for each port  
  rRCC_APB2ENR = rRCC_APB2ENR | (1<<5) | (1<<6);
  
  //  PD12 ==> input
  rGPIOD_CRH = rGPIOD_CRH & ~(0xf << 16);
  rGPIOD_CRH = rGPIOD_CRH | (0x8 << 16);
  
  //  PD14 ==> input
  rGPIOD_CRH = rGPIOD_CRH & ~(0xf << 24);
  rGPIOD_CRH = rGPIOD_CRH | (0x8 << 24);
  
  //  PD8 ==> input
  rGPIOD_CRH = rGPIOD_CRH & ~(0xf << 0);
  rGPIOD_CRH = rGPIOD_CRH | (0x8 << 0);
  
  //  PD0 ==> input
  rGPIOE_CRL = rGPIOE_CRL & ~(0xf << 0);
  rGPIOE_CRL = rGPIOE_CRL | (0x8 << 0);
  
  //  PE1 ==> input
  rGPIOE_CRL = rGPIOE_CRL & ~(0xf << 4);
  rGPIOE_CRL = rGPIOE_CRL | (0x8 << 4);
 
  
  while(1)
  {
    //
    //  use joystick to light the four LEDs on/off
    //
    
    if( !(rGPIOE_IDR & (0x1<<1)) )  // if LEFT KEY is pressed
    {
      WavePlayer_Stop();
      //rGPIOC_ODR |= (1<<6);
      WavePlayer_Init(SpeechReadAddr);
      WavePlayer_Start();
      
    }
    else
    {
      //rGPIOC_ODR &= ~(1<<6);
    }
    
    if( !(rGPIOE_IDR & 0x01) )  // if RIGHT KEY is pressed
    {
      WavePlayer_Stop();
      //rGPIOC_ODR |= (1<<7);
      WavePlayer_Init(SpeechReadAddr2);
      WavePlayer_Start();
    }
    else
    {
      
      //rGPIOC_ODR &= ~(1<<7);
      
    }
    if( !(rGPIOD_IDR & (0x1<<14)) ) // if DOWN KEY is pressed
  
    {
      
      WavePlayer_Stop();
      WavePlayer_Init(SpeechReadAddr3);
      WavePlayer_Start();
       //rGPIOC_ODR |= (1<<8);
    }
    else
    {
      rGPIOC_ODR &= ~(1<<8);
    }
     
    if( !(rGPIOD_IDR & (0x1<<8)) )  // if UP KEY is pressed
    {
      
      WavePlayer_Stop();
       //rGPIOC_ODR |= (1<<9);
      WavePlayer_Init(SpeechReadAddr4);
      WavePlayer_Start();
      /*LCD_DrawArray(pic_mario_jmp1_bmp, 100 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp1_bmp, 90 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp1_bmp, 80 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp1_bmp, 70 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp1_bmp, 60 , 150 ,32,74);
      Delay(10);
      LCD_DrawArray(pic_mario_jmp2_bmp, 60 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp2_bmp, 70 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp2_bmp, 80 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp2_bmp, 90 , 150 ,32,74);
      Delay(2);
      LCD_DrawArray(pic_mario_jmp2_bmp, 100 , 150 ,32,74);
      */
           
      //Delay(10);
      //LCD_DrawArray(pic_mario1_bmp, 118 , 150 ,32,56);
      //Delay(10);
      
    }
    else
    {   //LCD_DrawArray(pic_mario_jmp2_bmp, 100 , 150 ,32,74);
       //LCD_DrawArray(pic_mario_jmp2_bmp, 100 , 150 ,32,74);
      //rGPIOC_ODR &= ~(1<<9);
    }
    
     if( !(rGPIOD_IDR & (0x1<<12)) ) // if SEL KEY is pressed
    {
     
    }
    Delay(20);
  } // End While Loop    
}

void
MyLcdTest()
{
  
  int interest[] = {0, 1, 8, 12, 14};
  int i;
  int tmp;
  //gExNum = (unsigned int)MyLcdTest;
  //MyJoyStickInterruptInit();
	

  /* Initialize the LCD */
  //STM3210B_LCD_Init();
  //Uart_Printf( "STM3210B_LCD_Init() Success...\n" );
       
  //gColor = Red;

 // while (1)
  //{
    for (i = 0; i < sizeof(interest) / sizeof (int); i++) {
      tmp = interest[i];
      if (gExti[tmp]) {
      //LCD_Clear(gColor);
      gExti[tmp] = 0;
      }
    }
}


void MySysTickTest()

{

       gExNum = (unsigned int)MySysTickTest;

       MyLedInit();

       
       //SysTick Disable
       *(unsigned int *)0xE000E010 &= ~(0x1<<0);

       *(unsigned int *)0xE000E010 &= ~(1<<2);

        // 0.1초마다 SysTick Pended (interrupt 걸어줌)
       *(unsigned int *)0xE000E014 = 900000;

       
      //SysTick Interrupt Enable
       *(unsigned int *)0xE000E010 |= (1<<1);

       
        //SysTick Interrupt Enable
       *(unsigned int *)0xE000E010 |= (1<<0);


       while(1);

      //SysTick Disable
       *(unsigned int *)0xE000E010 &= ~(0x1<<0);

         

       gExNum = 0;

}
void SysTick_with_LCD() {
  unsigned int index;
  gExNum = (unsigned int)SysTick_with_LCD;
  /* Initialize the LCD */
  STM3210B_LCD_Init();
  
  LCD_Clear(White);
  
  LCD_SetTextColor( Blue );
  LCD_SetBackColor( White);
  
  
  *(unsigned int *)0xE000E010 &= ~(0x1<<0);
  *(unsigned int *)0xE000E010 &= ~(1<<2);
  *(unsigned int *)0xE000E010 &= ~(1<<4);
  *(unsigned int *)0xE000E014 = 900000;
  *(unsigned int *)0xE000E010 |= (1<<1);
  *(unsigned int *)0xE000E010 |= (1<<0);
  
  while(1){
    
    if(Uart_GetKey())
      break;
  }
  
  *(unsigned int *)0xE000E010 &= ~(0x1<<0);
  gExNum =0;
}

void LCD_Function(){
  unsigned int index;
  
  /* Initialize the LCD */
  STM3210B_LCD_Init();
  
  LCD_SetTextColor( Red );
  LCD_SetBackColor( Blue);
  
  LCD_Clear(White);
  
  LCD_DisplayStringLine( 16, "Test Display String " );
  LCD_DrawLine( 0, 0, 330, Horizontal );
  LCD_DrawLine( 0, 0, 320, Vertical );
  LCD_DrawRect(64, 64, 40, 40);
  LCD_DrawCircle( 128, 128, 30 );
  
  LCD_DrawCircle( 0, 0, 1 );
  LCD_DrawCircle( 30, 30, 1 );
  LCD_DrawCircle( 50, 50, 1 );
  LCD_DrawCircle( 70, 70, 1 );
  LCD_DrawCircle( 90, 90, 1 );
  LCD_DrawCircle( 110, 110, 1 );
  LCD_DrawCircle( 130, 130, 1 );
  LCD_DrawCircle( 150, 150, 1 );
  LCD_DrawCircle( 170, 170, 1 );
  LCD_DrawCircle( 190, 190, 1 );
  
  LCD_DrawCircle( 0, 0, 1 );
  LCD_DrawCircle( 230, 9, 1 );
  
  LCD_DrawCircle( 0, 319, 1 );
  LCD_DrawCircle( 239, 319, 1 );
  
  LCD_SetDisplayWindow( 239, 319, 239, 319 );
  
  LCD_Clear(Green);
  
  LCD_WindowModeDisable();
  while(1);
}
  


void MyDisplayBmp2c() {
  
  STM3210B_LCD_Init();
  LCD_Clear(White);

  
  //LCD_DrawArray(pic_iar_bmp, 100, 150, 71, 47);
  LCD_SetDisplayWindow(150,150,40,37);
  LCD_DrawBMP(0x100);
  while (1) {
  }
}

void MyWaveTest(){

  STM3210B_LCD_Init();

  LCD_Clear(White);

  SPI_FLASH_Init();

  //WavePlayer_Init(uint32_t my_SpeechReadAddr);

  

  IntExtOnOffConfig(DISABLE);

  

  if(Get_WaveFileStatus() == Valid_WAVE_File)

  {

    /*Start Wave audio Playing */

    //WavePlayer_Start();

    LCD_DisplayStringLine(Line5, "Loaded wave file");

  }

  else

  {

    LCD_DisplayStringLine(Line5, "No loaded wave file");

  }

  IntExtOnOffConfig(ENABLE);

  Delay(1000);

  LCD_DisplayStringLine(Line7, "Sound Play End");

  WavePlayer_Stop();

  

  while(1){

  };

  LCD_DisplayStringLine(Line9, "While Loop Escape");

}



