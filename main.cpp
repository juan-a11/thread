#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

#define NUM_THREADS 500
clock_t timer;
void  PrintHelloWolrd(){
    float aux=0;
    for(int i =0; i<8000000;i++){
        aux+= sin(i/12345);
    }
    cout << "El programa lleva: " << (float)(clock() - timer)/CLOCKS_PER_SEC << "seg" << endl;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    timer = clock();
    clock_t timer_total = clock();
    for (int i =0; i< NUM_THREADS;i++){
        PrintHelloWolrd();
    }
    timer_total = clock () - timer_total;
    cout << "Se tardo " << timer_total / CLOCKS_PER_SEC << " segundos en completarse";
    
}