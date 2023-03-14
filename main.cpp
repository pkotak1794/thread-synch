//  main.cpp: Thread Synchronization
//  Copyright (C) by Priyanka Kotak on 10/7/22.

#include <iostream>
#include <fstream>
#include <pthread.h>

std::ofstream myFile("synch.txt"); // create file to write to
pthread_mutex_t mtx; // mutex lock for critical section

// define function to write numerics to file
void* threadNum(void *arg) {

  pthread_mutex_lock(&mtx);

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j <= 26; j++) {
      myFile << j << " "; 
    }
    myFile << std::endl;
  }
  pthread_mutex_unlock(&mtx);
  pthread_exit(0);

}

// define function to write alphabets to file 
void* threadAlpha(void *arg) {

  pthread_mutex_lock(&mtx);

  for (int i = 0; i < 20; i++) {
    for (char j = 'A'; j <= 'Z'; j++) {
      myFile << j << " "; 
    }
    myFile << std::endl;
  }
  pthread_mutex_unlock(&mtx);
  pthread_exit(0);

}

int main(int argc, const char * argv[]) {

    pthread_t t1, t2; // declare two threads 

    // create both threads 
    pthread_create(&t1, NULL, threadNum, &myFile); 
    pthread_create(&t2, NULL, threadAlpha, &myFile);

    // threads waiting 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    myFile.close();

    return 0;
}
