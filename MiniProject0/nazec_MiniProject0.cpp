/* Author: Cassie Naze
 * Created: 15 February 2022
 * C++ file for the time hacking program. All function defined here.
 */

#include "nazec_MiniProject0.hpp"
using namespace TimeIsntReal;

TimeHacking::TimeHacking(std::string objectToHack){
    // put stuff here if you want, but dont need to
    // constructor
}
void TimeIsntReal::TimeHacking::setTimeToHack(int seconds){
    this->time_to_hack = seconds; 
}
int TimeIsntReal::TimeHacking::getTimeToHack(){
    return time_to_hack;
}
std::string TimeIsntReal::TimeHacking::getObjectToHack(){
    return objectToHack;
}
void TimeIsntReal::TimeHacking::hackTime(){
    // sleep for number of seconds the user indicated before indicating that time was hacked
    sleep(time_to_hack);
}

int main(int argc, char** argv){
    // Ask user what object they want to hack and how many seconds they want to hack it for
    std::cout << "What object do you want to hack?" << std::endl;
    char temp[50];
    std::string object;
    //object.push_back(argv[1]);
    scanf("%s",temp);
    object = temp;
    std::cout << "The object is: " << object << std::endl;

    std::cout << "How many seconds do you want to hack for?" << std::endl;
    int seconds;// = argv[2];
    scanf("%i",&seconds);
    std::cout << "The hack time is " << seconds << " seconds." << std::endl;

    // Instance of the class
    TimeIsntReal::TimeHacking hackBoy(object);
    
    // Setter to set hack time
    hackBoy.setTimeToHack(seconds);
    hackBoy.getTimeToHack();
    hackBoy.getObjectToHack();
    std::cout << "Hacking of the " << object << " is in progress." << std::endl;
    hackBoy.hackTime();
    std::cout << object << " has been hacked. Hacking complete." << std::endl;
    return 0;
}