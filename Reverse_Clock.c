//Reverse Clock
//clock will tick back for one second relative to when started
//currently set to only run for 10 seconds and will then exit

#include <stdio.h>
#include <windows.h>
#include <time.h>
//include if on linux
//#include <unistd.h>

int main(void){

    int oneSecond = 1000;
    //establish local time
    time_t currentTime = time(NULL);
    struct tm *tm_struct = localtime(&currentTime);
    int currentHour = tm_struct->tm_hour;
    int currentMinute = tm_struct->tm_min;
    int currentSecond = tm_struct->tm_sec;
    int z = 0;
 
    for (int i = currentSecond; i < 60; i--) {
        if (z != 10){
            z++;
            Sleep(oneSecond);
            printf("\n");
            printf("%d",currentHour);
            printf(":%d",currentMinute);
            printf(":%d",i);

            if (i == 0){
                i = i + 60;
                currentMinute = currentMinute -1;
            };

            if (currentMinute == 0){
                currentMinute = currentMinute + 59;
                currentHour = currentHour - 1;
            };

            if (currentHour == 0){
                currentHour = currentHour + 24;
            };
            };     
    }

    return 0;
}
