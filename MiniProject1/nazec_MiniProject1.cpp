/* Cassie Naze
 * MiniProject1
 * This is to practice creating and using librarbies 
 * The overall objective is to calculate statistics of the airspeed velocity of swallows
 */

#include "nazec_stats.hpp"

int main(int argc, char* argv[]){

    // Take filename as input argument
    BigCass::statistics statyFunctions;
    int size = 0;

    std::vector<float> data;
    std::string dataString = argv[1]; 
    std::ifstream inVector;
    inVector.open(dataString);

    if(inVector.is_open()){
        while(std::getline(inVector,dataString)){
            data.push_back(stof(dataString));
            size++;
        }
    }
    else{
        std:: cout << "The data file is not open.. try again with an existing file" << std::endl;
        return 1; 
    }

    // Calculate the min, max, mean and std dev of the airspeed velocity
    float mean = statyFunctions.calcMean(&data, size);
    float max = statyFunctions.calcMax(&data, size);
    float min = statyFunctions.calcMin(&data, size);
    float std = statyFunctions.calcStdDev(&data, size, mean);
   
    // Output results to the screen
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Maximum: " << max << std::endl;
    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Standard Deviation: " << std << std::endl;
}