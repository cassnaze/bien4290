/* Author: Cassie Naze
 * Created: 1 February 2022
 * This file calculates statistical data including min/max, mean, standard deviation and histogram values.
 * Using comp apps lab 1 code for reference here
*/

#include "nazec_stats.hpp"
using namespace BigCass;

float BigCass::statistics::calcMin(std::vector<float>* data, int size){
    float littlest = 5000; 
    for(int i = 0; i < size; i++){
        if(littlest > (*data)[i]){
            littlest = (*data)[i];
        }
    }
    return littlest;
}
void BigCass::statistics::setMin(float value){
    this->min = value;
}


float BigCass::statistics::calcMax(std::vector<float>* data, int size){
    float biggest = 0;
    for(int i = 0; i < size; i++){
        if((*data)[i] > biggest){
            biggest = (*data)[i];
        }
    }
    return biggest; 
}
void BigCass::statistics::setMax(float value){
    this->max = value;
}


float BigCass::statistics::calcMean(std::vector<float>* data, int size){
    float average; 
    float sum = 0;

    for(int i = 0; i < size; i++){
        sum = sum + (*data)[i];
    }
    average = sum/size;

    return average; 
}
void BigCass::statistics::setMean(float value){
    this->mean = value;
}


float BigCass::statistics::calcStdDev(std::vector<float>* data, int size, float mean){
    float variance;
    float theStandard;
    float sum = 0;

    for(int i = 0; i < size; i++){
        sum = sum + pow(((*data)[i] - mean), 2.0);
    }

    variance = sum/size;
    theStandard = sqrt(variance);

    return theStandard;
}
void BigCass::statistics::setStdDev(float value){
    this->std = value;
}


//std::vector<float> BigCass::statistics::histogram(std::vector<float>* data, int size, float mean, float std){
//    return 0;
//}