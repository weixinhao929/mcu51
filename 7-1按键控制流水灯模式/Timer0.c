#include <REGX52.H>
/**
  * @brief  定时器0初始化，1ms@12.000MHz
  * @param  无
  * @retval  无
  */
void Timer0_Init(){
//	TMOD=0x01;  //0000 0001
	TMOD=TMOD&0xF0; //把TMOD低四位清零，高四位保持不变
	TMOD|=0x01;//把TMOD最低位置1，高四位不变
//	TH0=64535/256;
//	TL0=64535%256;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

/*定时器中断函数模板
void Timer_Rountine() interrupt 1{
	static unsigned int T0cnt;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0cnt++;
	if(T0cnt>=1000){
		T0cnt=0;
	}
}
*/