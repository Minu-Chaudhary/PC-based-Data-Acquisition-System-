// the #ifndef prevents the file from being included more than once
#ifndef __DS1307_H__   
#define __DS1307_H__
 
void ds1307_Init();
void ds1307_Write(unsigned char dat);
void ds1307_SetTime(unsigned char hh, unsigned char mm, unsigned char ss);
void ds1307_GetTime(unsigned char *h_ptr,unsigned char *m_ptr,unsigned char *s_ptr);
#endif