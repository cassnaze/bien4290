/* Author: Cassie Naze
 * Created: 1 February 2022
 * This file declares the functions for statistical analysis.
*/

#ifndef stat
#define stat

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

namespace BigCass{
    class Statistics{
        public: 
            Statistics();

            /* This function is to calcuate the minimum value of the array
            * @param data: Input array
            * @returns: The min value 
            */ 
            float calcMin();
            void setMin(float data[]);

            /* This function is to calcuate the max of the array
            * @param data: Input array
            * @returns: The max value
            */ 
            float calcMax();
            void setMax(float data[]);

            /* This function is to calcuate the mean of input arrays
            * @param data: Input array
            * @returns: The mean of the input array
            */ 
            float calcMean();
            void setMean(float data[]);

            /* This function is to calcuate the standard deviation of the input array
            * @param data: Input array
            * @returns: The standard deviation 
            */ 
            float calcStdDev();
            void setStdDev(float data[]);

            /* This function is to estimate the histogram from input arguments
            * @param data: Input array
            * @returns: An array corresponding to the quantity of data in each bin
            */ 
            float histogram(); 
            void setHistogram(float data[]);

        private: 
            float data[]; // allocate it with something in the constructor; could look at std vectors 
            std::vector<float> data;

    }
}

#endif