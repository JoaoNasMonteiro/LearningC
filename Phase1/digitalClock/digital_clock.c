#import <stdio.h>
#import <stdbool.h>
#import <time.h>
#import <unistd.h>

int main(){
    time_t rawtime = 0;
    struct tm *pTime = NULL;
    bool isRunning = true;

    printf("Digital Clock \n");

    while(isRunning){
        time(&rawtime);
        fflush(stdout);
        pTime = localtime(&rawtime);

        int hours = pTime->tm_hour;
        int minutes = pTime->tm_min;
        int seconds = pTime->tm_sec;

        printf("\r%02d:%02d:%02d", hours, minutes, seconds);

        sleep(1);


    }

    return 0;
}