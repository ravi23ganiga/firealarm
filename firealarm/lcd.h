

#ifndef __LCD_FEATURE__
#define __LCD_FEATURE__

//LCD Macro Definition

#define LCD_PORT_DIR DDRE
#define LCD_PORT (PORTE)
#define LCD_RS (1 << 0)
#define LCD_RW (1 << 1)
#define LCD_EN (1 << 2)


//LCD Function Prototypes

void LcdInit();
void LcdCmd(UC ucvCmd);
void LcdData(UC ucvData);
void LcdString(UC *ucpvData, UC ucvLineNo);
void LcdToggleEn();
void LcdClear();

//LCD Structure


typedef struct
{
	UC ucmLcdIndex;
}LcdStruct;



#endif /* __LCD_FEATURE__ */
