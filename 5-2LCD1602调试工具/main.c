#include <REGX52.H>
#include"LCD1602.h"

int Result;

void main(){
	LCD_Init();
	Result=1+1;
//	LCD_ShowNum(1,1,Result,3);
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(1,3,"hello");//一行三列
	LCD_ShowNum(1,9,123,3);//一行三列三位，如果是四位就补零
	LCD_ShowSignedNum(1,13,-66,2);
	LCD_ShowHexNum(2,1,0xA8,2);
	LCD_ShowBinNum(2,4,0xAA,8);
	while(1){
		
	}

}