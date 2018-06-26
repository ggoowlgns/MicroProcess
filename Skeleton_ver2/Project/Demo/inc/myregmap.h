#ifndef _MY_GPIO_MAP_
#define _MY_GPIO_MAP_

//#define GPIO_POLLING
#ifndef	GPIO_POLLING
	#define GPIO_INTERRUPT
#endif



#define WRITE_64(ah, al)			(((long long)ah<<32) + (long long)al)


//
//	refer to UM0306 page 97
//

#define rAFIO_EVCR		(*(volatile unsigned int *)0x40010000)
#define rAFIO_MAPR		(*(volatile unsigned int *)0x40010004)
#define rAFIO_EXTICR1	(*(volatile unsigned int *)0x40010008)
#define rAFIO_EXTICR2	(*(volatile unsigned int *)0x4001000C)
#define rAFIO_EXTICR3	(*(volatile unsigned int *)0x40010010)
#define rAFIO_EXTICR4	(*(volatile unsigned int *)0x40010014)

#define rGPIOB_CRL	(*(volatile unsigned int *)0x40010C00)
#define rGPIOB_CRH	(*(volatile unsigned int *)0x40010C04)
#define rGPIOB_IDR	(*(volatile unsigned int *)0x40010C08)
#define rGPIOB_ODR	(*(volatile unsigned int *)0x40010C0C)
                  	
#define rGPIOC_CRL	(*(volatile unsigned int *)0x40011000)
#define rGPIOC_CRH	(*(volatile unsigned int *)0x40011004)
#define rGPIOC_IDR	(*(volatile unsigned int *)0x40011008)
#define rGPIOC_ODR	(*(volatile unsigned int *)0x4001100C)
                  	
#define rGPIOD_CRL	(*(volatile unsigned int *)0x40011400)
#define rGPIOD_CRH	(*(volatile unsigned int *)0x40011404)
#define rGPIOD_IDR	(*(volatile unsigned int *)0x40011408)
#define rGPIOD_ODR	(*(volatile unsigned int *)0x4001140C)
                  	
#define rGPIOE_CRL	(*(volatile unsigned int *)0x40011800)
#define rGPIOE_CRH	(*(volatile unsigned int *)0x40011804)
#define rGPIOE_IDR	(*(volatile unsigned int *)0x40011808)
#define rGPIOE_ODR	(*(volatile unsigned int *)0x4001180C)

#define rEXTI_IMR 	(*(volatile unsigned int *)0x40010400)
#define rEXTI_EMR 	(*(volatile unsigned int *)0x40010404)
#define rEXTI_RTSR 	(*(volatile unsigned int *)0x40010408)
#define rEXTI_FTSR 	(*(volatile unsigned int *)0x4001040C)
#define rEXTI_SWIER 	(*(volatile unsigned int *)0x40010410)
#define rEXTI_PR 	(*(volatile unsigned int *)0x40010414)

#define rDMA_ISR 	(*(volatile unsigned int *)0x40020000)
#define rDMA_IFCR 	(*(volatile unsigned int *)0x40020004)
#define rDMA_CCR1 	(*(volatile unsigned int *)0x40020008)
#define rDMA_CNDTR1 	(*(volatile unsigned int *)0x4002000C)
#define rDMA_CPAR1 	(*(volatile unsigned int *)0x40020010)
#define rDMA_CMAR1 	(*(volatile unsigned int *)0x40020014)
#define rDMA_CCR2 	(*(volatile unsigned int *)0x4002001C)
#define rDMA_CNDTR2 	(*(volatile unsigned int *)0x40020020)
#define rDMA_CPAR2 	(*(volatile unsigned int *)0x40020024)
#define rDMA_CMAR2 	(*(volatile unsigned int *)0x40020028)
#define rDMA_CCR3 	(*(volatile unsigned int *)0x40020030)
#define rDMA_CNDTR3 	(*(volatile unsigned int *)0x40020034)
#define rDMA_CPAR3 	(*(volatile unsigned int *)0x40020038)
#define rDMA_CMAR3 	(*(volatile unsigned int *)0x4002003C)
#define rDMA_CCR4 	(*(volatile unsigned int *)0x40020044)
#define rDMA_CNDTR4 	(*(volatile unsigned int *)0x40020048)
#define rDMA_CPAR4 	(*(volatile unsigned int *)0x4002004C)
#define rDMA_CMAR4 	(*(volatile unsigned int *)0x40020050)
#define rDMA_CCR5 	(*(volatile unsigned int *)0x40020058)
#define rDMA_CNDTR5 	(*(volatile unsigned int *)0x4002005C)
#define rDMA_CPAR5 	(*(volatile unsigned int *)0x40020060)
#define rDMA_CMAR5 	(*(volatile unsigned int *)0x40020064)
#define rDMA_CCR6 	(*(volatile unsigned int *)0x4002006C)
#define rDMA_CNDTR6 	(*(volatile unsigned int *)0x40020070)
#define rDMA_CPAR6 	(*(volatile unsigned int *)0x40020074)
#define rDMA_CMAR6 	(*(volatile unsigned int *)0x40020078)
#define rDMA_CCR7 	(*(volatile unsigned int *)0x40020080)
#define rDMA_CNDTR7 	(*(volatile unsigned int *)0x40020084)
#define rDMA_CPAR7 	(*(volatile unsigned int *)0x40020088)
#define rDMA_CMAR7 	(*(volatile unsigned int *)0x4002008C)

#define rBKP_DR1 	(*(volatile unsigned int *)0x40006C04)
#define rBKP_DR2 	(*(volatile unsigned int *)0x40006C08)
#define rBKP_DR3 	(*(volatile unsigned int *)0x40006C0C)
#define rBKP_DR4 	(*(volatile unsigned int *)0x40006C10)
#define rBKP_DR5 	(*(volatile unsigned int *)0x40006C14)
#define rBKP_DR6 	(*(volatile unsigned int *)0x40006C18)
#define rBKP_DR7 	(*(volatile unsigned int *)0x40006C1C)
#define rBKP_DR8 	(*(volatile unsigned int *)0x40006C20)
#define rBKP_DR9 	(*(volatile unsigned int *)0x40006C24)
#define rBKP_DR10 	(*(volatile unsigned int *)0x40006C28)

#define rPWR_CR		(*(volatile unsigned int *)0x40007000)
#define rPWR_CSR	(*(volatile unsigned int *)0x40007004)

#define rRCC_CR			(*(volatile unsigned int *)0x40021000)
#define rRCC_CFGR		(*(volatile unsigned int *)0x40021004)
#define rRCC_CIR			(*(volatile unsigned int *)0x40021008)
#define rRCC_APB2RSTR 	(*(volatile unsigned int *)0x4002100C)
#define rRCC_APB1RSTR 	(*(volatile unsigned int *)0x40021010)
#define rRCC_AHBENR 	(*(volatile unsigned int *)0x40021014)
#define rRCC_APB2ENR 	(*(volatile unsigned int *)0x40021018)
#define rRCC_APB1ENR 	(*(volatile unsigned int *)0x4002101C)
#define rRCC_BDCR	 	(*(volatile unsigned int *)0x40021020)
#define rRCC_CSR 		(*(volatile unsigned int *)0x40021024)


#define rADC1_SR		(*(volatile unsigned int *)0x40012400)
#define rADC1_CR1		(*(volatile unsigned int *)0x40012404)
#define rADC1_CR2		(*(volatile unsigned int *)0x40012408)
#define rADC1_SMPR1		(*(volatile unsigned int *)0x4001240C)
#define rADC1_SMPR2		(*(volatile unsigned int *)0x40012410)
#define rADC1_JOFR1		(*(volatile unsigned int *)0x40012414)
#define rADC1_JOFR2		(*(volatile unsigned int *)0x40012418)
#define rADC1_JOFR3		(*(volatile unsigned int *)0x4001241C)
#define rADC1_JOFR4		(*(volatile unsigned int *)0x40012420)
#define rADC1_HTR		(*(volatile unsigned int *)0x40012424)
#define rADC1_LTR		(*(volatile unsigned int *)0x40012428)
#define rADC1_SQR1		(*(volatile unsigned int *)0x4001242C)
#define rADC1_SQR2		(*(volatile unsigned int *)0x40012430)
#define rADC1_SQR3		(*(volatile unsigned int *)0x40012434)
#define rADC1_JSQR		(*(volatile unsigned int *)0x40012438)
#define rADC1_JDR1		(*(volatile unsigned int *)0x4001243C)
#define rADC1_JDR2		(*(volatile unsigned int *)0x40012440)
#define rADC1_JDR3		(*(volatile unsigned int *)0x40012444)
#define rADC1_JDR4		(*(volatile unsigned int *)0x40012448)
#define rADC1_DR		(*(volatile unsigned int *)0x4001244C)

#define rUSART_SR		(*(volatile unsigned int *)0x40013800)
#define rUSART_DR		(*(volatile unsigned int *)0x40013804)
#define rUSART_BRR		(*(volatile unsigned int *)0x40013808)
#define rUSART_CR1		(*(volatile unsigned int *)0x4001380C)
#define rUSART_CR2		(*(volatile unsigned int *)0x40013810)
#define rUSART_CR3		(*(volatile unsigned int *)0x40013814)
#define rUSART_GTPR		(*(volatile unsigned int *)0x40013818)

/***********************************************************************************
*
*	Bit Field Map
*
***********************************************************************************/



#define bRCC_APB1ENR_PWREN	(*(volatile unsigned int *)(0x42000000 + 0x2101C * 32 + 28*4))
#define bRCC_APB1ENR_BKPEN		(*(volatile unsigned int *)(0x42000000 + 0x2101C * 32 + 27*4))


#define bRCC_APB2ENR_IOPEEN	(*(volatile unsigned int *)(0x42000000 + 0x21018 * 32 + 6*4))
#define bRCC_APB2ENR_IOPDEN	(*(volatile unsigned int *)(0x42000000 + 0x21018 * 32 + 5*4))
#define bRCC_APB2ENR_IOPCEN	(*(volatile unsigned int *)(0x42000000 + 0x21018 * 32 + 4*4))
#define bRCC_APB2ENR_IOPBEN	(*(volatile unsigned int *)(0x42000000 + 0x21018 * 32 + 3*4))
#define bRCC_APB2ENR_IOPAEN	(*(volatile unsigned int *)(0x42000000 + 0x21018 * 32 + 2*4))
#define bRCC_APB2ENR_AFIOEN	(*(volatile unsigned int *)(0x42000000 + 0x21018 * 32 + 0*4))

#define bPWR_CR_DBP			(*(volatile unsigned int *)(0x42000000 + 0x7000 * 32 + 8*4))
#define bPWR_CR_PVDE			(*(volatile unsigned int *)(0x42000000 + 0x7000 * 32 + 4*4))
#define bPWR_CR_CSBF			(*(volatile unsigned int *)(0x42000000 + 0x7000 * 32 + 3*4))
#define bPWR_CR_CWUF			(*(volatile unsigned int *)(0x42000000 + 0x7000 * 32 + 2*4))
#define bPWR_CR_PDDS			(*(volatile unsigned int *)(0x42000000 + 0x7000 * 32 + 1*4))
#define bPWR_CR_LPDS			(*(volatile unsigned int *)(0x42000000 + 0x7000 * 32 + 0*4))
#define bPWR_CSR_EWUP			(*(volatile unsigned int *)(0x42000000 + 0x7004 * 32 + 8*4))
#define bPWR_CSR_PVDO			(*(volatile unsigned int *)(0x42000000 + 0x7004 * 32 + 2*4))
#define bPWR_CSR_SBF			(*(volatile unsigned int *)(0x42000000 + 0x7004 * 32 + 1*4))
#define bPWR_CSR_WUF			(*(volatile unsigned int *)(0x42000000 + 0x7004 * 32 + 0*4))

#define bRCC_BDCR_BDRST		(*(volatile unsigned int *)(0x42000000 + 0x21020 * 32 + 16*4))

#define bGPIOC_CRH_CNF15		(*(volatile long long *)(0x42000000 + 0x11004 * 32 + 30*4))
#define bGPIOC_CRH_MODE15		(*(volatile long long *)(0x42000000 + 0x11004 * 32 + 28*4))

#define bGPIOC_CRH_CNF9		(*(volatile long long *)(0x42000000 + 0x11004 * 32 + 6*4))
#define bGPIOC_CRH_MODE9		(*(volatile long long *)(0x42000000 + 0x11004 * 32 + 4*4))
#define bGPIOC_CRH_CNF8		(*(volatile long long *)(0x42000000 + 0x11004 * 32 + 2*4))
#define bGPIOC_CRH_MODE8		(*(volatile long long *)(0x42000000 + 0x11004 * 32 + 0*4))

#define bGPIOC_CRL_CNF7		(*(volatile long long *)(0x42000000 + 0x11000 * 32 + 30*4))
#define bGPIOC_CRL_MODE7		(*(volatile long long *)(0x42000000 + 0x11000 * 32 + 28*4))
#define bGPIOC_CRL_CNF6		(*(volatile long long *)(0x42000000 + 0x11000 * 32 + 26*4))
#define bGPIOC_CRL_MODE6		(*(volatile long long *)(0x42000000 + 0x11000 * 32 + 24*4))




#endif
