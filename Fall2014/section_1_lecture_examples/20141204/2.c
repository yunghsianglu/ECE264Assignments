#include <pthread.h>
#include <stdio.h>
void* worker(void* arg) {
	int *p_x = (int*)arg;
	while(*p_x < 100) {
		(*p_x)++;
	}
	printf("increment finished\n");
	return NULL;
}
int main() {
	int x = 0, y = 0;
	printf("x: %d, y: %d\n", x, y);

	pthread_t t1, t2;
	pthread_create(&t1, NULL, worker, &x); // check if returns 0
	// like calling worker(&x)

	pthread_create(&t2, NULL, worker, &y); // check if returns 0
	// like calling worker(&y)

	// Three threads are active now.

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("x: %d, y: %d\n", x, y);
	return 0;
}
