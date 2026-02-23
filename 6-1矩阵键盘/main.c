#include <REGX52.H>
#include"Delay.h"
#include"LCD1602.h"
#include"MatrixKey.h"

unsigned char KeyNum;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey:");
	while(1){
		KeyNum=MatrixKey();
		if(KeyNum){//按按键了再换数字，不然就一直保持原来
			LCD_ShowNum(2,1,KeyNum,2);
		}
	}
	
}