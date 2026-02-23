#include <REGX52.H>
#include"Delay.h"
#include"LCD1602.h"
#include"MatrixKey.h"

unsigned char KeyNum=0;
unsigned int Password,cnt=0;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1){
		KeyNum=MatrixKey();
		if(KeyNum){//按按键了再换数字，不然就一直保持原来
			if(KeyNum<=10&&cnt<4){//输入次数小于4
				Password*=10;		//密码左移
				Password+=KeyNum%10; //获取一位
				cnt++;  //计数加一
				LCD_ShowNum(2,1,Password,4);//更新显示
			}
			if(KeyNum==11){//s11 确认
				if(Password==2345){
					LCD_ShowString(1,14,"OK ");//显示ok
				}else{
					LCD_ShowString(1,14,"err");//不然显示err
				}
				Password=0;
				cnt=0;					//计数密码清零
				LCD_ShowNum(2,1,Password,4);//更新显示
			}
			if(KeyNum==12){//s12 取消
				Password=0;
				cnt=0;					//计数密码清零
				LCD_ShowNum(2,1,Password,4);//更新显示
			}
		}
	}
}