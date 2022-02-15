/* Author: Cassie Naze
 * Created: 7 February 2022
 * This file has the function definition for the correlation coefficient program.
*/

#include "nazec_stats.hpp"
#include "nazec_corr.hpp"
//#include "nazec_stats.cpp"

using namespace BigCass;

float BigCass::correlation::calcCorrCoef(std::vector<float>* data1, std::vector<float>* data2, int size){
   
    // Need placeholder variables for calculation here
    BigCass::statistics helperFunctions;
    float xMean = helperFunctions.calcMean(data1,size);
    float yMean = helperFunctions.calcMean(data2,size);
    float xSum = 0;
    float ySum = 0;
    float sum = 0;
    float xSq = 0;
    float ySq = 0;
    float numerator = 0;
    float denominator = 0;
    float corrCoeff = 0;

    // Increment through the data vectors to find the sums and stuff
    for(int i = 0; i < size; i++){
        float X = (*data1)[i];
        float Y = (*data2)[i];
        xSum = xSum + X;
        ySum = ySum + X;
        sum = sum + (X * Y);
        //sum = xSum + ySum;

        //xSq = xSq + (*data1)[i] * (*data1)[i];
        //ySq = ySq + (*data2)[i] * (*data2)[i];
        xSq = xSq + pow(X,2.0);
        ySq = ySq + pow(Y,2.0);
    }

    // Calculations for numerator and denominator
    numerator = (sum) - (size * xMean * yMean);
    denominator = sqrt((xSq - (size * xMean * xMean)) * (ySq - (size * yMean * yMean)));

    corrCoeff = numerator / denominator; 

    return corrCoeff;
}