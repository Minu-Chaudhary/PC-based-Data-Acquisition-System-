void delay_ms(int d)
{
	unsigned char i;
	for(d;d>0;d--)
	{
		for(i=500;i>0;i--); //1001
		for(i=498;i>0;i--); //998
	}	
}