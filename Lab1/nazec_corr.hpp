/* Author: Cassie Naze
 * Created: 7 February 2022
 * This file declares the function for the correlation program.
*/

#ifndef ABC
#define ABC

//extern "C"
#include <cstdio>
//#include <stdlib.h>
#include <iostream>
//#include <ostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <filesystem>


namespace BigCass{
    class correlation{

        //correlation::correlation();

        public: 

        /* This function takes in two data sets and calculates the correlation coefficient between them
         * @param data1: The first input data vector
         * @param data2: The second input data vector
         * @param size: Size of the input data vector
         * @returns: The correlation coefficient
         */
        float calcCorrCoef(std::vector<float>* data1, std::vector<float>* data2, int size);

        private: 

    };
}

#endif