
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


#include "schedule.h"





//
// main - The simulator's main routine
//
int main(int argc, char **argv){
    int processes[10];
    init();
    int i;
    for(i=0;i<10;i++){
        processes[i]=100;
        printf("Scheduled Process: %d\n", i);
        addProcess(i);
    }

    int process = 0;
    int time = 0;
    while(hasProcess()){
        process = nextProcess(&time);
        if(!process){
            printf("NULL Process, something went wrong in your code.\n");
            exit(1);
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
        }
    }


    exit(0); //control never reaches here
}
