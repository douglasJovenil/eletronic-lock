/*******************************************************************************
 *                                                                             *
 * Autor: Douglas Jovenil Castilhos dos Santos                                 *
 *                                                                             *
 * ****************** Criando novo projeto MPLAB X IDE v3.35 *******************
 *                                                                             *
 * File -> New Project -> Microchip Embedded -> Standalone Project -> Next     *
 * Famyly = Advanced 8-bit MCUs (PIC18) -> Device = PIC18F4550 -> Next         *
 * Simulator -> Next                                                           *
 * XC8 -> Next                                                                 *
 * Finish                                                                      *
 *                                                                             *
 * ************************ Configurando PIC18F4550 **************************** 
 *                                                                             *
 * Windows -> Target Memory view -> Configuration Bits                         *
 * Setar todos os valores em que Field possui a opcao ON/OFF para OFF          *
 * Exceto os valores MCLLRE e CCP2MX que deverao ficar como ON                 *
 * Clicar em Generate Source Code to Output                                    *
 * Copiar o codigo gerado e colar no programa                                  *
 * Eh o codigo que esta neste arquivo ate a linha #define _XTAL_FREQ 20000000   *
 *                                                                             *
 * ******************** PIC18F4550 Configuration Bit Settings ******************
 *                                                                             * 
 * 'C' source line config statements                                           *
 *                                                                             *
 *******************************************************************************/

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 1         // Brown-out Reset Voltage bits (Setting 2 4.33V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON     // CCP2 MUX bit (CCP2 input/output is not multiplexed with RB3)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

/*******************************************************************
 *                                                                 *
 * #pragma config statements should precede project file includes. *
 * Use project enums instead of #define for ON and OFF.            *
 *                                                                 *
 *******************************************************************/
#define _XTAL_FREQ 20000000         // *** Inserido manualmente ***

#include "XLCD\busyxlcd.c"
#include "XLCD\openxlcd.c"
#include "XLCD\putrxlcd.c"
#include "XLCD\putsxlcd.c"
#include "XLCD\readaddr.c"
#include "XLCD\readdata.c"
#include "XLCD\setcgram.c"
#include "XLCD\setddram.c"
#include "XLCD\wcmdxlcd.c"
#include "XLCD\writdata.c"
#include "XLCD\xlcd.h"

#define FALSE   0
#define TRUE    1
#define OFF     0
#define ON      1
#define OUT     0
#define IN      1
#define DOWN   'd'
#define UP     'u'

#define ONE     17
#define TWO     18
#define THREE   20
#define FOUR    33
#define FIVE    34
#define SIX     36
#define SEVEN   65
#define EIGHT   66
#define NINE    68
#define ERASE   129
#define _ZERO   130
#define ENTER   132

#define SIZE_PASS               10
#define DELAY_TIME              1000
#define NUM_BUTTONS             11
#define NUM_COLUMNS             0b100
#define ZERO_ASCII              48
#define END_LCD                 0x40
#define START_LCD               0x00
#define CMD_CLEAR               0x01
#define DELAY_CLEAR             80
#define MAX_WRONG_PASS          3
#define LED                     RB7
#define TIME_BLINK_WRONG_PASS   30
#define TIME_BLINK              500

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef char int8_t;

void keyboardScan(uint8_t[], uint8_t[], uint8_t*, uint8_t*);
void changePass(uint8_t[], uint8_t*, uint8_t*);
void writeCharLCD(uint8_t, uint8_t, uint8_t);
void writeArrayLCD(const int8_t[], int8_t );
__bit checkPassword(uint8_t[], uint8_t[]);
uint8_t sizeArray(const uint8_t[]);
void clearArray(uint8_t[]);
void myDelay(uint32_t);
void blinkLed(uint8_t);
void DelayFor18TCY();
void DelayPORXLCD();
void definitions(); 
void correctPass();
void wrongPass();
void DelayXLCD();
void clearLCD();

void definitions(){
    TRISD = 0b11110000;
    TRISB = OUT;
    LATD = OFF;

    OpenXLCD(FOUR_BIT&LINES_5X7); // configura para 4-bit, 5x7, multiplas linhas
    while(BusyXLCD());            
    WriteCmdXLCD(0x06);           // move o cursor para direita depois de escrever 
    while(BusyXLCD()); 
    WriteCmdXLCD(0x0C);           // display ligado sem aparecer o cursor
    while(BusyXLCD()); 
}

void myDelay(uint32_t time){
    for (uint32_t i=0; i<time; i++) __delay_ms(1);
}

void DelayFor18TCY(void){
    __delay_us((8*18.0*4000000.0)/_XTAL_FREQ); 
}

void DelayPORXLCD(void){
    __delay_ms(60);
}

void DelayXLCD(void){
    __delay_ms(20);
}
