#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <string>

//unix headers
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

using namespace std;

int main(int argv, char **argc)
{
    cout << "Hello World!" << endl;

    //Open the port to the arduino
    int handle = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
    if(handle == -1) return -1;

    struct termios options;
    tcgetattr(handle, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    options.c_lflag |= ICANON;

    tcsetattr(handle, TCSANOW, &options);
    fcntl(handle, F_SETFL, 0);

    int c = 0;
    cout << "starting to read stuffs: " << endl;
    while(true)
    {
        char buf[256];
        int r = read(handle, buf, sizeof(buf));
        buf[r] = '\0';
        std::cout << "read: " << buf;

        string s = "thanks! " + to_string(c++);
        write(handle, s.c_str(), s.length());
    }

    return 0;
}