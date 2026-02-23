#include <REGX52.H>
void Delay(unsigned int xms);
void main(){
	unsigned char cnt=0;
	P2=~0x01;
	while(1){
		if(P3_1==0){
			Delay(20);
			while(P3_1==0);
			Delay(20);
			if(cnt>7){
				cnt=0;
			}
			cnt++;
			P2=~(0x01<<cnt);
		}
		if(P3_0==0){
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(cnt==0){
				cnt=7;
			}else{
				cnt--;
			}
			P2=~(0x01<<cnt);
		}
	}
}

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