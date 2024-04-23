#include <msp430.h>
#include "peripherals.h"
#include "grlib/grlib.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


/**
 * main.c
 */

long unsigned int timer_cnt = 0;
long unsigned int startingTimer = 0;

void configDisplay_clk(void);
void runtimerA2(void);
void stoptimerA2(int reset);
void displayTime(long unsigned int inTime);
void addLeadingZero(char* str, unsigned int num);
void displayTemp(float inAvgTempC);
void floatToString(float value, char *str, char unit);
void displayTimeTemp(long unsigned int inTime, float inAvgTempC);

__interrupt void TimerA2_ISR (void);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	configDisplay();
	_BIS_SR(GIE);
	runtimerA2();

	while (1){
	    displayTimeTemp(timer_cnt, 24);
	}

	return 0;
}

#pragma vector=TIMER2_A0_VECTOR
__interrupt void TimerA2_ISR (void) {
    timer_cnt++;
    if (timer_cnt == 60000)
        timer_cnt = 0;
    else if (timer_cnt % 100 == 0) {
        P1OUT = P1OUT ^ BIT0;
        P4OUT ^= BIT7;
    }
}

void displayTimeTemp(long unsigned int inTime, float inAvgTempC){
    Graphics_clearDisplay(&g_sContext);
    displayTime(inTime);
    displayTemp(inAvgTempC);
}

void addLeadingZero(char* str, unsigned int num) {
    if (num < 10) {
        sprintf(str, "0%d", num);
    } else {
        sprintf(str, "%d", num);
    }
}

void displayTime(long unsigned int inTime) {
    long unsigned int actualSeconds = inTime / 200; // this is just a random variable i tested it with and it works now we need to incorporate it with timer count
    unsigned int totalDays = actualSeconds / 86400;
    unsigned int hours = (actualSeconds - totalDays * 86400) / 3600;
    unsigned int mins = (actualSeconds - totalDays * 86400 - hours * 3600) / 60;
    unsigned int seconds = actualSeconds - totalDays * 86400 - hours * 3600 - mins * 60;

    char* months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    unsigned int month = totalDays / 30;
    unsigned int day = totalDays % 30;

    char dayStr[3];
    char hourStr[3];
    char minStr[3];
    char secStr[3];

    addLeadingZero(dayStr, day + 1);
    addLeadingZero(hourStr, hours);
    addLeadingZero(minStr, mins);
    addLeadingZero(secStr, seconds);

    char dateStr[20];
    sprintf(dateStr, "%s %s", months[month % 12], dayStr);

    char timeStr[20];
    sprintf(timeStr, "%s:%s:%s", hourStr, minStr, secStr);

    Graphics_drawStringCentered(&g_sContext, (uint8_t*) dateStr, AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
    Graphics_drawStringCentered(&g_sContext, (uint8_t*) timeStr, AUTO_STRING_LENGTH, 48, 30, TRANSPARENT_TEXT);
    Graphics_Rectangle box = {.xMin = 5, .xMax = 91, .yMin = 5, .yMax = 91};
    Graphics_drawRectangle(&g_sContext, &box);
//    Graphics_flushBuffer(&g_sContext);
}

void floatToString(float value, char *str, char unit) {
    int intPart = (int)value;
    float fracPart = value - intPart;

    sprintf(str, "%d.", intPart);

    char fracStr[3];
    sprintf(fracStr, "%d", (int)(fracPart * 10));
    strcat(str, fracStr);
    strncat(str, &unit, 1);
}


void displayTemp(float inAvgTempC) {
    float tempF = inAvgTempC * 9 / 5 + 32;

    char tempCStr[10];
    char tempFStr[10];

    floatToString(inAvgTempC, tempCStr, 'C');
    floatToString(tempF, tempFStr, 'F');

    Graphics_drawStringCentered(&g_sContext, (uint8_t*) tempCStr, AUTO_STRING_LENGTH, 48, 45, TRANSPARENT_TEXT);
    Graphics_drawStringCentered(&g_sContext, (uint8_t*) tempFStr, AUTO_STRING_LENGTH, 48, 60, TRANSPARENT_TEXT);
    Graphics_flushBuffer(&g_sContext);
}


void stoptimerA2(int reset) {
    TA2CTL = MC_0;
    TA2CCTL0 &= ~CCIE;
    if(reset)
    timer_cnt=0;
}

void runtimerA2(void) {
    TA2CTL = TASSEL_1 + MC_1 + ID_0;
    TA2CCR0 = 164; // 0.005 seconds
    TA2CCTL0 = CCIE;
}

void configDisplay_clk(void) {
    P5SEL |= (BIT5|BIT4|BIT3|BIT2);
}
