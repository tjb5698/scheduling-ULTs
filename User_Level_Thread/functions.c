/**** DO NOT MODIFY THIS FILE ****/

// Functions used by the threads

#include "threads.h"
#include "my_functions.c"

void simple_thread()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("simple_thread tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j == 10) {
            printf("DELETING MYSELF (tid: %d)\n", GetMyId());
            DeleteThread(GetMyId());
        }
        i++;
    }
}
void clean_up_thread()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("simple_thread tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j == 10) {
            printf("CLEANUP()\n");
            CleanUp();
        }
        i++;
    }
}
void sleep_test()
{
    int i = 0;
    int j = 0;
    int sleep = 0;
    while (1) {
        if (sleep == 1) {
            printf("WAKING UP\n");
            sleep = 0;
        }
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("sleep_thread tid: %d; j = %d)\n", id, j);
            j++;
        }
        if (j == 5) {
            j++;
            printf("SLEEP FOR 20 SECONDS (tid: %d)\n", GetMyId());
            sleep = 1;
            SleepThread(20);
        }
        i++;
    }
}

void suspend_test()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("suspend_test tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j == 10) {
            j++;
            printf("SUSPEND THREAD 0\n");
            SuspendThread(0);
        }
        if (j == 20) {
            j++;
            printf("RESUME THREAD 0\n");
            ResumeThread(0);
        }
        i++;
    }
}

void yield_test()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("yield_test tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j % 5 == 0) {
            j++;
            printf("YIELDING CPU (tid: %d)\n", GetMyId());
            YieldCPU();
        }
        i++;
    }
}

void delete_test()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("delete_test tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j % 25 == 0) {
            j++;
            printf("DELETING MYSELF (tid: %d)\n", GetMyId());
            DeleteThread(GetMyId());
        }
        i++;
    }
}

void delete_other_test()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("delete_other_test tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j == 20) {
            j++;
            printf("DELETING THREAD 1\n");
            DeleteThread(1);
        }
        i++;
    }
}

void create_test()
{
    int i = 0;
    int j = 0;
    while (1) {
        if (i % 100000000 == 0) {
            int id = GetMyId();
            printf("create_test tid: %d; j = %d\n", id, j);
            j++;
        }
        if (j == 10) {
            j++;
            printf("CREATING A NEW THREAD\n");
            CreateThread(simple_thread, 1);
        }
        if (j == 30) {
            printf("DELETING MYSELF (tid: %d)\n", GetMyId());
            DeleteThread(GetMyId());
        }
        i++;
    }
}