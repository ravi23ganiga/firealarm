#include "global.h"


void LcdInit()
{
	LCD_PORT_DIR = OUTPUT_PORT;
	LcdCmd(0x02);
	LcdCmd(0x28);
	LcdCmd(0x06);
	LcdCmd(0x0F);
	LcdCmd(0x01);
	LcdCmd(0x80);
}

void LcdCmd(UC ucvCmd)
{
	LCD_PORT = (ucvCmd & 0xF0);
	LcdToggleEn();
	LCD_PORT = ((ucvCmd << 4) & 0xF0);
	LcdToggleEn();
}
void LcdData(UC ucvData)
{
	LCD_PORT = (ucvData & 0xF0) | LCD_RS;
	LcdToggleEn();
	LCD_PORT = ((ucvData << 4) & 0xF0) | LCD_RS;
	LcdToggleEn();
}
void LcdString(UC *ucpvData, UC ucvLineNo)
{
	if(ucvLineNo EQ 1)
		LcdCmd(0x80);
    else if(ucvLineNo EQ 2)
		LcdCmd(0xC0);

 	while(*ucpvData)
		LcdData(*ucpvData++);
}
void LcdToggleEn()
{
	LCD_PORT = LCD_PORT | LCD_EN;
	_delay_ms(20);
	LCD_PORT = LCD_PORT & (~LCD_EN);
}
void LcdClear()
{
	LcdCmd(0x01);
}
