/* Author: Cassie Naze
 * Created: 1 February 2022
 * This file is where the main function is and values and printed to the screen.
*/

#include "nazec_stats.hpp"
//#include "nazec_stats.cpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
using namespace BigCass;

/* This is the main function where all of the statistics are calculated and printed to the screen
 * @param data: Input path for the data file
 * @return:
 */

int main(int argc, char** argv){
    
    // Check number of arguments that the function is taking in first
    if(argc > 2 || argc < 2){
        std:: cout << "Wrong number of arguments entered.. try again!" << std::endl;
        return 1; 
    }

    // Variable for the data using namespace and class name
    BigCass::statistics statyFunctions;
    int size = 0; // The number of points in the data file

    std::vector<float> data;
    std::string dataString = argv[1]; // argv[0] is the .exe file name

    // Ensure all data points are read correctly
    // If the data isn't found, then print an eror to the screen and terminate analysis
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

    // Calculate and write the quantities to the screen
    float mean = statyFunctions.calcMean(&data, size);
    float max = statyFunctions.calcMax(&data, size);
    float min = statyFunctions.calcMin(&data, size);
    float std = statyFunctions.calcStdDev(&data, size, mean);
    std::vector <float> histo = statyFunctions.histogram(&data, size, mean, std);

    std::cout << "Number of data points: " << size << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Maximum: " << max << std::endl;
    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Standard Deviation: " << std << std::endl;

    // Histogram output
    for(int i = 0; i<15;i++){
        std::cout <<"I ";
        for(int j = 0; j<histo[i];j++){
            //std::cout << std::endl;
            std::cout << "*";
        }
        //std::cout << " " << ceil(histo[i])<< std::endl; // to print the number of values in each bin
        std::cout << std::endl;
    }
    std::cout << "Each * represents 50 data points" << std::endl;

/*  // Tried to use this code from online to print it vertically rather than horizontal but the logic doesnt make sense
    for (int value : histo) std::cout << ' ' << value;
    std::cout << std::endl;
    max = 0;
    for (int value : histo) if (max < value) max = value;
    for (; max > 0; --max) {
        for (int value : histo) std::cout << (value >= max ? " *" : "  ");
        std::cout << std::endl;
  }
*/

}