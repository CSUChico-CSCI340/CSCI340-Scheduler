// 
// 
// 
// <Put your name and ID here>
//

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>


#include "schedule.h"





//
// main - The simulator's main routine
//
int main(int argc, char **argv){
    int processes[14];
    init();
    int i;
    for(i=0;i<10;i++){
        processes[i]=100;
        int priority = i%4+1;
        printf("Scheduled Process: %d, Priority:%d\n", i, priority);
        addProcess(i,priority);
    }  
    int process = 0;
    int count = 0;
    int time = 0;
    while(hasProcess()){
        process = nextProcess(time);
        if(count==400){
            for(;i<14;i++){
                processes[i]=100;
                int priority = i%4+1;
                printf("Scheduled Process: %d, Priority:%d\n", i, priority);
                addProcess(i,priority);
            }
        }
        for(;time>0;time--){
            printf("Process %d executed\n", process);
            processes[process]--;
            if(processes[process]<0){
                if(removeProcess(process)==1){
                    printf("Process %d Finished\n", process);
                    break;
                }
                else{
                   // printf("Failed to remove Process: %d\n", process);
                }
                continue;
            }
            count++;
        }
    }
    
    
    exit(0); //control never reaches here
}
  










