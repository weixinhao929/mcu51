#include <REGX52.H>
#include"Delay.h"
#include"Timer0.h"
#include"LCD1602.h"

unsigned char Sec,Min,Hour;

void main(){
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
	
  while(1){
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
  }
}


void Timer_Rountine() interrupt 1{
	static unsigned int T0cnt;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0cnt++;
	if(T0cnt>=1000){
		T0cnt=0;
		Sec++;
		if(Sec>59){
			Sec=0;
			Min++;
			if(Min>59){
				Min=0;
				Hour++;
				if(Hour>23){
					Hour=0;
				}
			}
		}
	}
}