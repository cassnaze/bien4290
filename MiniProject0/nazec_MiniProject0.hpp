/* Author: Cassie Naze
 * Created: 15 February 2022
 * Header file for the time hacking program. File includes class definition with the public and private members
 */

#ifndef TIME
#define TIME

#include <iostream>
#include <unistd.h>

namespace TimeIsntReal{
    class TimeHacking{
        public:
            TimeHacking(std::string objectToHack); // Constructor
            
            void setTimeToHack(int seconds);
            int getTimeToHack();
            std::string getObjectToHack();
            void hackTime();

        private:
            int time_to_hack;
            std::string objectToHack;
    };
}

#endif