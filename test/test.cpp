#include "../include/logger.hpp"
#include <thread>

void testMultiThread(int i){
    Logger::info("I'm the thread", i);
}

void testLowerBoundPriority(priorityType priorityLevel){
    Logger::setLowerBoundPriority(priorityLevel);
}

void allMessagges(){
    Logger::trace("Trace severity message");
    Logger::debug("Trace severity message");
    Logger::info("Trace severity message");
    Logger::warning("Trace severity message");
    Logger::error("Trace severity message");
    Logger::fatal("Trace severity message");
};
int main(){


    //test all messagges. You should see: 
    //TRACE: light blue message.
    //DEBUG: purple message.
    //INFO: light green message.
    //WARNING: yellow message.
    //ERROR: red message.
    //FATAL: bold red message.    
    allMessagges();

    //test the priority filtering.
    testLowerBoundPriority(warningPriority);
    allMessagges();


    //set the priority back to trace priority.
    testLowerBoundPriority(tracePriority);

    //test the multithread safety.
    std::thread thread[10];

    for(int i=0; i<10; i++){
        thread[i] = std::thread(testMultiThread, i);
    }

    for(int i=0; i<10; i++){
        thread[i].join();
    }

    return 0;
}