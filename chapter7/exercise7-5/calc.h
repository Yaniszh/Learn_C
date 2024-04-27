/*
 * Package Name: exercise7-5
 *
 * File Name: cal.h
 *
 * Abstract:
 * Calculate header file
 *
 * Created: yanice  2024/4/20
 *
 * History: null    null
 *
 */
    

#ifndef cal_h
#define cal_h

#define NUMBER  '0'
#define MAXOP   100     /* max size of operand or operator */

void push(double);
double pop(void);
int getop(char []);

#endif /* cal_h */
