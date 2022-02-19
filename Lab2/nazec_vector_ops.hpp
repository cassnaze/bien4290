/* Author: Cassie Naze
 * Created: 19 February 2022
 * The purpose of this header file is to declare several functions that will be used for working with vectors.
 * Used some documentation here from labs done in BIEN 3200 with Dr. Cooper
 */

#ifndef OHNO
#define OHNO

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>

namespace BigCass{
    class VecOps{
        public:
        
        /* This function is to summ all elements of an array together
         * @param data: Input data vector
         * @param size: Size of the input vector
         * returns: The sum of all elements the input data vector
         */
        float sum(std::vector<float>* data, int size);

        /* This function is to subtract one array from another element-wise
         * @param data1: The first data vector
         * @param size1: Size of the first data vector
         * @param data2: The second data vector
         * @param size2: Size of the second data vector
         * returns: A vector of the subtracted elements
         */
        std::vector<float> sub(std::vector<float>* data1, int size1, std::vector<float>* data2, int size2);
        
        /* This function is to divide all elements of an array by a single constant
         * @param data: Input data vector
         * @param size: Size of the input data vector
         * @param const: The constant value to divide all elements by
         * returns: A vector of values divided by the constant value
         */
        std::vector<float> divConst(std::vector<float>* data, int size, int constant);
        
        /* This function is to set the private variables.
        */
        void setterBoi(float summ, std::vector <float> subbedVec, std::vector <float> divvedVec);

        private:
        float summ;
        std::vector <float> subbedVec;
        std::vector <float> divvedVec;


    };
}

#endif