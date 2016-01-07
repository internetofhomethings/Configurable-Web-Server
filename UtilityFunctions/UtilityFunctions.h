/***************************************************
  This is a library of utility functions

  Designed specifically to work with ESP8266 in the
  Arduino IDE platform.

  Written by Dave St. Aubin.
  Creative Commons license.
 ****************************************************/

#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

float powr(float x, int y);
void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);

#endif //  UTILITYFUNCTIONS_H
