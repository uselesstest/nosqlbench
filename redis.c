#ifndef REDIS_SETUP_LIB
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <hiredis/hiredis.h>
#include "timer.h"

#define TEST_OK 1
#define TEST_FAIL 2
#define TEST_UNKNOWN -1

redisContext* createNewRedis () {
    redisContext *c;
    struct timeval timeout = {1, 500000};
    c = redisConnectWithTimeout ("127.0.0.1", 6379, timeout);

    if (c == NULL || c->err) {
        printf ("Connection was not established. Exiting...\n");
        exit (1);
    }
    return c;
}

int createDemonstratorTable1 (redisContext* context, int rowsCount) {
    printf ("Creating demonstration table #1: ID, Name, Surname, Birthdate, Town\n");
    return TEST_OK;
}

int createDemonstratorTable2 (redisContext* context, int rowsCount) {
   printf ("Creating demonstration table #2: ID, Browser, OS, Time, CookieCount, UserID\n");
   return TEST_OK;
}


int linkTwoTablesByIndexes (redisContext* context, int rowCount) {
   printf ("Linking two tables by ID");
   return TEST_OK;
}
//-----------------
// Testing purposes
//-----------------

void __testRedisPing (redisContext* context) {
    redisReply* reply;
    reply = redisCommand(context, "PING");
    printf("\nTEST_REDIS: If 'PONG' then everything is fine: '%s'\n", reply->str);
    freeReplyObject(reply);
}

void __testRedisIO (redisContext* context) {
    redisReply* reply;
    reply = redisCommand (context, "SET %s %s", "Foo", "Yes, GET is working!");
    printf ("\nIf 'OK' then everything is fine: '%s'\n", reply->str);
    freeReplyObject (reply);
    reply = redisCommand (context, "GET Foo");
    printf ("Is GET working?: '%s'\n", reply->str);
    freeReplyObject (reply);
}

#define REDIS_SETUP_LIB
#endif
