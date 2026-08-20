#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

char menuC(const char* msg, const char *opt, int err, const char *errMsg);

int menuN(const char* msg, int amountOptions, int err, const char *errMsg);

#endif // MENU_H_INCLUDED
