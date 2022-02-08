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


std::vector<float> BigCass::statistics::histogram(std::vector<float>* data, int size, float mean, float std){
    // Centered at the dataset mean
    // Each bin should have a width of 0.4*stddev
        // Bins should begin and end at the sample mean +/-3 stddev
    
    //std::vector<float> bins;
    std::vector<float> bin_count;
    float width = 0.4 * std;
    float begin = mean - (3.0 * std);
    float end = mean + (3.0 * std);
    //int count = 0;
/*
    // This is what we did in comp apps and it did not work for me
    // I also think that this is not calculating the bins like we are supposed to do
    for(int i = 0; i<15; i++){
        bin_count.push_back(0);
    }
    for(int i = 1; i < 16; i++){
        bins[i] = bins[i-1] + width+begin;
    }
    for(int i = 0; i<15; i++){
        for(int j = 0; j <size; j++){
            if((*data)[j]>= bins[i] && (*data)[j]< bins[i+1]){
                count++;
            }
            bin_count[i] = count;
        }
        count = 0;
    }
*/

    for(int i = 0; i<10; i++){
        bin_count.push_back(0);
    }

	for(int j=0; j<size;j++) {

		if (((*data)[j] > begin) && ((*data)[j] <= (width+begin))) {
			bin_count[0]++; 
		}
		else if (((*data)[j] > ((width*1) + begin)) && ((*data)[j] <= ((width*2)+begin)))	{
			bin_count[1]++; 
		}
	        else if (((*data)[j] > ((width*2) + begin)) && ((*data)[j] <= ((width*3) + begin))){
			bin_count[2]++;  
		}
		else if (((*data)[j] > ((width*3) + begin)) && ((*data)[j] <= ((width*4) + begin))){
			bin_count[3]++; 
		}
        else if (((*data)[j] > ((width*4) + begin)) && ((*data)[j] <= ((width*5) + begin))){
            bin_count[4]++; 
        }
        else if (((*data)[j] > ((width*5) + begin)) && ((*data)[j] <= ((width*6) + begin))){
            bin_count[5]++; 
        }
        else if (((*data)[j] > ((width*6) + begin)) && ((*data)[j] <= ((width*7) + begin))){
            bin_count[6]++; 
        }
        else if (((*data)[j] > ((width*7) + begin)) && ((*data)[j] <= ((width*8) + begin))){
            bin_count[7]++; 
        }
        else if (((*data)[j] > ((width*8) + begin)) && ((*data)[j] <= ((width*9) + begin))){
            bin_count[8]++; 
        }
        else if (((*data)[j] > ((width*9) + begin)) && ((*data)[j] <= ((width*10) + begin))){
            bin_count[9]++; 
        }
        else if (((*data)[j] > ((width*10) + begin)) && ((*data)[j] <= end)){
            bin_count[10]++; 
        }
	}

    // Setting each * in the output to be equal to 5 values
	for(int count = 0; count <10; count++)
	{
		bin_count[count] = bin_count[count]/10.0;
	}

    
    return bin_count;
}