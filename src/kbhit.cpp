#include "kbhit.h"

int kbhit() 
{
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);
    return nbbytes;
}