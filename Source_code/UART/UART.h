#include<reg51.h>
 void uart_init(void);
 void uart_tx(unsigned char);
 unsigned char uart_rx(void);
 void uart_str(unsigned char *);
 void uart_int(int);
 void uart_float(float);
 
 void main()
 {
	 unsigned char r;
	 uart_init();
	 while(1)
	 {
		 r=uart_rx();
		 uart_tx(r);
	 } 
	 void uart_init(void)
	 {
	 SCON = 0x40; //UART Mode 1
	 TMOD = 0x20; //Timer 1 Mode 2
	 Th1=TL1=253;
	 TR1=1;
	 }	 
 }
	 
	 
	 
	 void uart_tx(unsigned char d)
	 {
		 SBUF=d; //Tx is started
		 while(TI==0);
		 TI=0;
	 }
		 unsigned char uart_rx()
	 {
		 while(RI==0);
		 RI=0;
		 return SBUF;
	 } 
		 void uart_str(unsigned char *s)
		 {
			 while(*s)
				 uart_tx(*s++);
		 }	
	
		 void uart_int(int n)
		 {
			 uart_tx('-');
			 n=-n;
		 while(n>0)
		 {
			 arr[j++ = n%10;
			 n=n/10;
		 } 
		   for(--j;arr[j;j--)
			 uart_tx(arr[j +48);
		 }
		void uart_float(float f)
		{
			int t=f;
			uart_num(t);
			uart_tx('.');
			t=(f-t)*1000;
			uart_num(t);
		}