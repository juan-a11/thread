#include <iostream>
#include <pthread.h>
#include <math.h>
#include <ctime>
using namespace std;

#define NUM_THREADS 500

void * PrintHelloWolrd(void *threadis){
    clock_t timer = clock();
    long tid;
    tid = (long) threadis;
    float aux=0;
    for(int i =0; i<8000000;i++){
        aux+= sin(i/12345);
    }
    timer = clock () - timer;
    cout << "Hello World Thread ID " << tid << " tardo " << timer/CLOCKS_PER_SEC << "seg" << endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    clock_t timer_total = clock();
    for (int i =0; i< NUM_THREADS;i++){
        cout << "main(): creating thread, " << i <<endl;

        rc = pthread_create(&threads[i],NULL,PrintHelloWolrd,(void*)i);

        if(rc){
            cout << "Error:unable to create thread, "<<rc << endl;
            exit(-1);
        }
    }
    for (int i =0; i< NUM_THREADS;i++){
        pthread_join(threads[i],NULL);
    }
    timer_total = clock () - timer_total;
    cout << "Se tardo " << timer_total / CLOCKS_PER_SEC << " segundos en completarse";
    pthread_exit(NULL);
    //cout << "Hello World\n";
    
}