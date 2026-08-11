#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    while (1)
    {
        time_t now;
        struct tm *currentTime;

        time(&now);
        currentTime = localtime(&now);

        printf("\rDigital Clock: %02d:%02d:%02d",
               currentTime->tm_hour,
               currentTime->tm_min,
               currentTime->tm_sec);

        fflush(stdout);

        sleep(1);
    }

    return 0;
}