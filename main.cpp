#include <iostream>
#include <pthread.h>
#include <math.h>
using namespace std;

#define NUM_THREADS 500

void * PrintHelloWolrd(void *threadis){
    long tid;
    tid = (long) threadis;
    float aux=0;
    for(int i =0; i<8000000;i++){
        aux+= sin(i/12345);
    }
    cout << "Hello World Thread ID " << tid <<endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;

    for (int i =0; i< NUM_THREADS;i++){
        cout << "main(): creating thread, " << i <<endl;
        rc = pthread_create(&threads[i],NULL,PrintHelloWolrd,(void*)i);

        if(rc){
            cout << "Error:unable to create thread, "<<rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    //cout << "Hello World\n";
    
}