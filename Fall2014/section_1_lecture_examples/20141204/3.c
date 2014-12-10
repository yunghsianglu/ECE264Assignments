#include <pthread.h>
#include <stdio.h>

struct WorkerArg {
	int x;
	char marker;
};
void* worker(void* arg) {
	struct WorkerArg*  p_wkr_arg = (struct WorkerArg*)arg;
	while(p_wkr_arg->x < 100) {
		int i;
		for(i=0; i<10; i++) {
			(p_wkr_arg->x)++;
			printf("%c%d%c", p_wkr_arg->marker,
					p_wkr_arg->x, p_wkr_arg->marker);
		}
	}
	return NULL;
}
int main() {
	struct WorkerArg wkr_arg1, wkr_arg2;
	wkr_arg1.x = 0;
	wkr_arg1.marker = ':';
	wkr_arg2.x = 0;
	wkr_arg2.marker = '_';
	printf("x: %d, y: %d\n", wkr_arg1.x, wkr_arg2.x);

	pthread_t t1, t2;
	pthread_create(&t1, NULL, worker, &wkr_arg1);
	pthread_create(&t2, NULL, worker, &wkr_arg2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("x: %d, y: %d\n", wkr_arg1.x, wkr_arg2.x);
	return 0;
}
/*	pthread_mutex_t* mlock;*/
