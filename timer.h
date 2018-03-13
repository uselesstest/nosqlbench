#ifndef SINCE_EPOCH_LIBRARY
#include <time.h>
#define epochTime unsigned long long

epochTime getTimeSinceEpoch () {
    struct timeval tv = {0, 0};
    gettimeofday(&tv, NULL);

    return(epochTime)(tv.tv_sec) * 1000 + (epochTime)(tv.tv_usec) / 1000;
}

epochTime getTimeSinceEpochInS () {
   time_t seconds_past_epoch;
   seconds_past_epoch = time(0);
   return seconds_past_epoch - 0;
}

epochTime calculateTimeSince (epochTime Time) {
   time_t seconds_past_epoch; 
   seconds_past_epoch = time(0);
   return seconds_past_epoch - Time;
}



#define SINCE_EPOCH_LIBRARY
#endif
