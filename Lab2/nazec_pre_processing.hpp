/* Author: Cassie Naze
 * Created: 19 February 2022
 * The purpose of this header file is to declare a function for preprocessing.
 */


#ifndef HELLO
#define HELLO

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>

namespace BigCass{
    class PreProcessing{
        public:
            /* This is the function for calculating the loag ratio from the given equation
             * @param data1: The first data vector
             * @param size1: Size of the first data vector
             * @param data2: The second data vector
             * @param size2: Size of the second data vector
             * @param ratio: The vector that is filled with the log ratio data
             * @return: Void
             */
            void logRatio(std::vector<float>* data1, int size1, std::vector<float>* data2, int size2, std::vector<float> lr);

            /* This is the setter function for the private variable
             * @param ratio: The private variable
             */
            void setter(float ratio);

        private:
            float ratio;
    };
}

#endif