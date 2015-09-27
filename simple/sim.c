//
//
//
// <Put your name and ID here>
//

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
    while(hasProcess()){
        process = nextProcess();
        for(;;){
            printf("Process %d executed\n", process);
            processes[process]--;
            if(processes[process]<0){
                printf("Process %d Finished\n", process);
                break;
            }
        }
    }


    exit(0); //control never reaches here
}
