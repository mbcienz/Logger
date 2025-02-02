#include <iostream>
#include <mutex>

enum priorityType {
    tracePriority, debugPriority, infoPriority, warningPriority, errorPriority, fatalPriority
};

class Logger{
    private: 
        static priorityType priority;
        static std::mutex mutex;


    public:

        // set the lower buond priority. For example: if "warning" is the current lower priority, all
        // the prints lower then warning priority will not get displayed.  
        static void setLowerBoundPriority(priorityType newPriority){
            priority = newPriority;
        };

        // print the trace priority message;
        template<typename... Args>
        static void trace(const char* message, Args... args){
            log("\033[1;36m[TRACE]", tracePriority, message, args...);
        };
        
        // print the debug priority message;
        template<typename... Args>
        static void debug(const char* message, Args... args){
            log("\033[0;35m[DEBUG]", debugPriority, message, args...);
        };

        // print the info priority message;
        template<typename... Args>
        static void info(const char* message, Args... args){
            log("\033[0;32m[INFO]", infoPriority, message, args...);
        };

        // print the warning priority message;
        template<typename... Args>
        static void warning(const char* message, Args... args){
            log("\033[0;33m[WARN]", warningPriority, message, args...);
        };

        // print the error priority message;
        template<typename... Args>
        static void error(const char* message, Args... args){
            log("\033[0;31m[ERROR]", errorPriority, message, args...);
        };

        // print the fatal priority message;
        template<typename... Args>
        static void fatal(const char* message, Args... args){
            log("\033[1;31m[FATAL]", fatalPriority, message, args...);
        };


    private: 
        // the function which print the message.
        template<typename... Args>
        static void log(const char* prio, priorityType messagePriority, const char* messageStr, Args... args){
            
            //useful if you want to filter some priority messages. You should set the priority first, through the setLowerBoundPriority method. 
            if(priority<=messagePriority){
                //lock the mutex, for multithreading safety. It will automatically unlock when go out of scope (out from this if).
                std::scoped_lock lock(mutex);
                std::cout << prio << "\t" << messageStr;
                ((std::cout << ' ' << args), ...);
                std::cout<<"\033[0m\n";
                
            };

        };

};

priorityType Logger::priority = tracePriority;
std::mutex Logger::mutex;