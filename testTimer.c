#include <stdio.h>
#include <unistd.h>
#include "timer.h"

int main () {
    epochTime was = getTimeSinceEpoch ();
    unsigned int desiredTimeToTestInSeconds = 9;
    printf ("Now attempting to sleep for %d s", desiredTimeToTestInSeconds);
    usleep (desiredTimeToTestInSeconds * 1000000);
    printf ("...done!\n");
    epochTime now = getTimeSinceEpoch ();
    printf ("So the difference in time is %d seconds ", now - was);
    printf ("or %d (should be the same)", getTimeSince (was));
    return 0;
}
