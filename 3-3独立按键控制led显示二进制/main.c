#include<REGX52.H>

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

void main(){
	unsigned char led=0;
	P2=0xFE;
	while(1){
		
		if(P3_1==0){
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			led++;
			P2=~led;
			//整个数然后取反
			//为零就导通，亮灯
		}
	}
}