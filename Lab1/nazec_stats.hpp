/* Author: Cassie Naze
 * Created: 1 February 2022
 * This file declares the functions for statistical analysis.
*/

#ifndef STATY
#define STATY

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

namespace BigCass{
    class Statistics{
        public: 
            //Statistics(); // Constructor.. do we need this?f

            /* This function is to calcuate the minimum value of the array
            * @param data: Input vector of the data
            * @param size: Size of the input data vector
            * @returns: The min value 
            */ 
            float calcMin(std::vector<float>* data, int size);
            void setMin(float value);

            /* This function is to calcuate the max of the array
            * @param data: Input vector of the data
            * @param size: Size of the input data vector
            * @returns: The max value
            */ 
            float calcMax(std::vector<float>* data, int size);
            void setMax(float value);

            /* This function is to calcuate the mean of input arrays
            * @param data: Input vector of the data
            * @param size: Size of the input data vector
            * @returns: The mean of the input array
            */ 
            float calcMean(std::vector<float>* data, int size);
            void setMean(float value);

            /* This function is to calcuate the standard deviation of the input array
            * @param data: Input vector of the data
            * @param size: Size of the input data vector
            * @param mean: The mean calcuated from calcMean function
            * @returns: The standard deviation 
            */ 
            float calcStdDev(std::vector<float>* data, int size, float mean);
            void setStdDev(float value);

            /* This function is to estimate the histogram from input arguments
            * @param data: Input vector of the data
            * @param size: Size of the input data vector
            * @param mean: The mean calcuated from calcMean function
            * @param std: The standard deviation from calcStdDev function
            * @returns: A vector corresponding to the quantity of data in each bin
            * return hashbin, assign classvariables (vector or array that is the same length of elemetns in the bins) to get values in bins, calcualte bins externally to the 
            * histogram and histogram function takes in the bin values
            */ 
            std::vector<float> histogram(std::vector<float>* data, int size, float mean, float std); 

        private: 
            //float data[]; // allocate it with something in the constructor; could look at std vectors 
            //std::vector<float>* data; // this is actually going to be what we use as an arg for the functions
            
            float min;
            float max;
            float mean;
            float std;
            //float bins[];
    };
}

#endif