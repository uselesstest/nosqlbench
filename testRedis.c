#include "redis.c"

int main () {
   redisContext* context;
   context = createNewRedis ();
   __testRedisPing (context);
   __testRedisIO (context);
   createDemonstratorTable1 (context, 0);
   createDemonstratorTable2 (context, 0);
   linkTwoTablesByIndexes (context, 0);
}
