#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* dead_loop(void* foo) {
  for (;;);
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    const int num_thread = atoi(argv[1]);
    pthread_t threads[num_thread];
    printf("I'm gonna burn your CPU with %d threads!\n", num_thread);
    for (int i = 0; i != num_thread; ++i) {
      printf("Thread (%d) is spawning...   ", i);
      pthread_create(&(threads[i]), NULL, dead_loop, NULL);
      printf("Thread (%d) spawned!\n", i);
    }
    printf("Now, check temperature of your CPU!\n");
    for (int i = 0; i != num_thread; ++i) {
      pthread_join(threads[i], NULL);
    }
  } else {
    printf("Please input an integer as num_thread!\n");
  }
}
