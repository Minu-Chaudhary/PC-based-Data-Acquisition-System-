#include<reg51.h>

sbit cs = P1^3;
sbit mosi = P1^4;
sbit miso = P1^5;
sbit clk = P1^6;

float spi_adc_read()
{
	unsigned int adc_val=0;
	char j;
	cs=0; 											//initiate communication
	clk=0; mosi=1; clk=1; 			//Start Bit
	clk=0; mosi=1; clk=1;			 //Single ended mode
	clk=0; clk=1; 							//don't care _bit
	clk=0;mosi=d1;clk=1; 				//D1
	clk=0;mosi=d1;clk=1;			 //D0
	clk=0; clk=1;							 //sampling condition
	clk=0; clk=1; 						//null _bit
	
	// to read 12 _bit digital _code
	for(j=11; j>=0;j--)
	{
		clk=0;
		if(miso)
			adc_val |=(1<<j);
		clk=1;
	}
		
		cs=1;										 //stop communication
			return((adc_val*5.0)/4096); //formula
}