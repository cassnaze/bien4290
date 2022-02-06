/* Author: Cassie Naze
 * Created: 1 February 2022
 * This file calculates statistical data including min/max, mean, standard deviation and histogram values.
 * Using comp apps lab 1 code for reference here
*/

#include "nazec_stats.hpp"


float BigCass::Statistics::calcMin(std::vector<float>* data, int size){
    float littlest = 5000; 
    for(int i = 0; i < size; i++){
        if(littlest > (*data)[i]){
            littlest = (*data)[i];
        }
    }
    return littlest;
}
void BigCass::Statistics::setMin(float value){
    this->min = value;
}


float BigCass::Statistics::calcMax(std::vector<float>* data, int size){
    float biggest = 0;
    for(int i = 0; i < size; i++){
        if((*data)[i] > biggest){
            biggest = (*data)[i];
        }
    }
    return biggest; 
}
void BigCass::Statistics::setMax(float value){
    this->max = value;
}


float BigCass::Statistics::calcMean(std::vector<float>* data, int size){
    float average; 
    float sum = 0;

    for(int i = 0; i < size; i++){
        sum = sum + (*data)[i];
    }
    average = sum/size;

    return average; 
}
void BigCass::Statistics::setMean(float value){
    this->mean = value;
}


float BigCass::Statistics::calcStdDev(std::vector<float>* data, int size, float mean){
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
void BigCass::Statistics::setStdDev(float value){
    this->std = value;
}


std::vector<float> BigCass::Statistics::histogram(std::vector<float>* data, int size, float mean, float std){

}