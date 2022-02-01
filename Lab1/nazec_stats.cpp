/* Author: Cassie Naze
 * Created: 1 February 2022
 * This file calculates statistical data including min/max, mean, standard deviation and histogram values.
*/

#include "nazec_stats.hpp"


float BigCass::Statistics::calcMin(){
    return this->data;
}
void BigCass::Statistics::setMin(float data[]){

    this->data = min;
}

float BigCass::Statistics::calcMax(){
    return this->data;
}
void BigCass::Statistics::setMax(float data[]){

    this->data = max;
}

float BigCass::Statistics::calcMean(){
    return this->data;
}
void BigCass::Statistics::setMean(float data[]){

    this->data = mean;
}

float BigCass::Statistics::calcStdDev(){
    return this->data;
}
void BigCass::Statistics::setStdDev(float data[]){

    this->data = std;
}

float BigCass::Statistics::histogram(){
    return this->data;
}
void BigCass::Statistics::setHistogram(float data[]){

    this->data = bins[]; 
}