#include<reg52.h>
#define uint unsigned int 
#define uchar unsigned char
uchar flag,a,i,ads,qian,bai,shi,ge,num1,num2;
sbit C1=P2^5;
sbit C2=P2^6;
sbit C3=P2^3;
sbit C4=P2^4;
uchar code t[]={0x05,0x7d,0x46,0x54,0x3c,0x94,0x84,0x5d,0x04,0x14};
void delay(uint x)
{
uint i,j;
for(i=x;i>0;i--)
for(j=110;j>0;j--);
}
void qwer(qian,bai,shi,ge)
{
C1=0;
P0=t[qian];
delay(1);
P0=0xff;
C1=1;
C2=0;
P0=t[bai];
delay(1);
P0=0xff;
C2=1;
C3=0;
P0=t[shi];
delay(1);
P0=0xff;
C3=1;
C4=0;
P0=t[ge];
delay(1);
P0=0xff;
C4=1;
}


void init()
{TMOD=0x20;
        TH1=0xfd;
        TL1=0xfd;
        TR1=1;
          SCON=0x50;
         REN=1;
        
         EA=1;
         ES=1;
}
void main()
   {
   init();
        if(flag==1)
         {
         qian=num1/10;            //num1高位赋第一位
                bai=num1%10;       //num1低位赋第二位
                shi=num2/10;           //num2高位赋第三位
                ge=num2%10;        

           qwer(qian,bai,shi,ge);}
}
void UART1_Routine() interrupt 4    //串口中断
{
        if (RI)                                                                
        {
              RI = 0;                 //清除RI位        
                ads= SBUF;                    //接收缓冲寄存器
                bai=ads&0x0f;            //数组接收百位数字
                qian=(ads&0xf0)>>4;   //数组接收千位数字
                num1=qian*10+bai;
                ads=0x00;     
                while(!RI);                      //等待接收完成
                RI=0;                     //清除RI位
                ads= SBUF;                       //接收缓冲寄存器
                ge=ads&0x0f;                     //数组接收个位数字
                shi=(ads&0xf0)>>4;        //数组接收十位数字
                num2=shi*10+ge;                                
                flag=1;                
                                                        
        }
        if (TI)
        {
                TI = 0;            //清除TI位
        }
}
     return 0;
