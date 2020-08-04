#include<reg51.h>
#include "lcd.h"
#include "delay.h"

 
#define dataport P2       // LCD dataport connected to PORT2
 
sbit rs= dataport^0;      // Register select pin connected to P2.0
sbit rw= dataport^1;      // Read Write pin connected to P2.1
sbit en= dataport^2;      // Enable pin connected to P2.2
 
 
 
/* 16x2 lcd Specification */
#define LCDMaxLines 2
#define LCDMaxChars 16
#define LineOne 0x80
#define LineTwo 0xc0
#define output_voltage 5
#define input_voltage 5
 
#define BlankSpace ' '
 
//LCD initilization
void LCD_Init()
{
    delay_ms(5000);
   lcd_WriteCmd(0x02);  //initilize the LCD in 4bit Mode
   lcd_WriteCmd(0x28);
   lcd_WriteCmd(0x0C);  // display ON cursor ON
   lcd_WriteCmd(0x01);  // clear the LCD
   lcd_WriteCmd(0x80);  // move the Cursor to First line First Position
 
}
 
 
// lcd Write command function
void lcd_WriteCmd( char a)
{
 
   dataport=(a & 0xf0);        
   rs=0;                      
   rw=0;                 
 	 en=1;                 
   delay_ms(1);
   en=0;
   delay_ms(1);                  
   dataport=((a<<4) & 0xf0);   
   rs=0;                    
   rw=0;                    
   en=1;                      
   delay_ms(1);
   en=0;
   delay_ms(1);
}
 
 
 // lcd writedata function
void lcd_Writedata( char a)
{
 
 
   dataport=(a & 0xf0);        
     rs=1;                      
     rw=0;                      
     en=1;                      
    delay_ms(1);
     en=0;
 
   delay_ms(1);                
 
   dataport=((a <<4) & 0xf0);  
     rs=1;                    
     rw=0;                     
     en=1;                      
    delay_ms(1);
     en=0;
 
   delay_ms(1);
 
}

 
 //lcd gotolinetwo fuction
void lcd_GoToLineTwo()
{
   lcd_WriteCmd(LineTwo);   // move the Cursor to Second line First Position
}
 
 
 
//lcd go to X(first row), Y(second row) line
void lcd_GoToXY(char row, char col)
{
   char pos;
 
    if(row<LCDMaxLines)
      {
         pos= LineOne | (row << 6);
                                    
 
        if(col<LCDMaxChars)
           pos= pos+col;            
                                    
 
         lcd_WriteCmd(pos);        
       }
}
 

//lcd display string function
void lcd_DisplayString(char *string_ptr)
{
   while(*string_ptr)
    lcd_Writedata(*string_ptr++);
    }
 
 
//lcd display rtc time function
void lcd_DisplayRtcTime(char hour,char min,char sec)
{
    lcd_Writedata(((hour>>4) & 0x0f) + 0x30);
    lcd_Writedata((hour & 0x0f) + 0x30);
    lcd_Writedata(':');
 
    lcd_Writedata(((min>>4) & 0x0f) + 0x30);
    lcd_Writedata((min & 0x0f) + 0x30);
    lcd_Writedata(':');
 
    lcd_Writedata(((sec>>4) & 0x0f) + 0x30);
    lcd_Writedata((sec & 0x0f) + 0x30);
 
 }
 
 
 // lcd display voltage function
void lcd_Displayvoltage(float output_counts,input_counts)
 {
      output_voltage = 2.048*(output_counts/2048.0);
      input_voltage = ( input_counts / 65536.0 ) * 4.096;
 }