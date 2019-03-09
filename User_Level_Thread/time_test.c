#include <sys/time.h>

struct timespec ts_start;
struct timespec ts_end;
struct timespec ts_diff;

int main() {
	
	clock_gettime(CLOCK_MONOTONIC, &ts_start);
	
	for (int i = 0; i < 20; i++){
		printf("Hello!\n");
	}

	clock_gettime(CLOCK_MONOTONIC, &ts_end);

	// CLOCK_MONOTONIC guarantees that start > end

	ts_diff.tv_sec  = ts_end.tv_sec  - ts.start_tv_sec ;
	ts_diff.tv_nsec = ts_end.tv_nsec - ts_start.tv_nsec

	printf("The time duration is : %ld.%6ld\n", ts_diff.tv_sec, ts_diff.tv_nsec);
}