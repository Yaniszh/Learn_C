/*
 * Package Name: exercise6-2
 *
 * File Name: ch.h
 *
 * Abstract:
 * Declare getch() and un_getch() functions.
 *
 * Created: yanice  2024/4/12
 *
 * History: null    null
 *
 */
    

#ifndef ch_h
#define ch_h

#include <stdio.h>
#define BUFSIZE 20

int getch(void);
void un_getch(int c);

#endif /* ch_h */
