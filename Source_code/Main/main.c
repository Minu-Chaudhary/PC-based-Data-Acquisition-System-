#include<reg51.h> 
#include<lcd.h>  	 
#include<ds1307.h> 
#include<i2c.h>
#include<delay.h>
#include<mcp3204.h>
 
/* main program */
void main() 
{
   unsigned char sec,min,hour,voltage;
 
  /* Initilize the lcd */
    lcd_Init();
 
  /* Initilize the RTC(ds1307)*/
    ds1307_Init();
 
 
  /*set the time only once */
  ds1307_SetTime(0x23,0x59,0x30);  
  
 
  /* Display "time" on first line*/
  lcd_DisplayString("Time: ");
 
   /* Display "voltage" on Second line*/
  lcd_GoToLineTwo();
  lcd_DisplayString("Voltage: ");
 
   /* Display the time and voltage continously */ 
   while(1)
    {
	   /* Read the Time from RTC(ds1307) */ 
        ds1307_GetTime(&hour,&min,&sec);        
 
		/* Display the time on firstline 7th position*/
 
         lcd_GoToXY(0,6); 		 
         lcd_DisplayRtcTime(hour,min,sec);
 
		
		 /*initializing adc(mpc3204)*/
		 lcd_Init();
		 lcd_DisplayString("voltage:");
		 while(1)
		 {
			 lcd_WriteCmd(0xc0); //2nd line
			 lcd_Displayvoltage(spi_adc_read(0,0));
		 }
}
}