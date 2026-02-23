#include <REGX52.H>

unsigned char nixietable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--){
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}
}

void nixie(unsigned char location,unsigned char num){
	
	switch(location){
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=nixietable[num];
	Delay(5);
	P0=0x00;//œ˚”∞  —” ±÷√¡„
}


void main(){
	
	while(1){
		nixie(1,1);
//		Delay(20);
		nixie(2,2);
//		Delay(20);
		nixie(3,3);
//		Delay(20);
	}
	
}