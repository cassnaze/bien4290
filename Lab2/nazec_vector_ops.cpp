/* Author: Cassie Naze
 * Created: 19 February 2022
 * This is the C++ file where the functions are defined.
 */

#include "nazec_vector_ops.hpp"

void BigCass::VecOps::setterBoi(float summ, std::vector <float> subbedVec, std::vector <float> divvedVec){
    this->summ = summ;
    this->subbedVec = subbedVec;
    this->divvedVec = divvedVec;
}

float BigCass::VecOps::sum(std::vector<float>* data, int size){
    float summ = 0;

    for(int i = 0; i < size; i++){
        summ = summ + (*data)[i];
    }

    return summ;
}

std::vector<float> BigCass::VecOps::sub(std::vector<float>* data1, int size1, std::vector<float>* data2, int size2){
    if(size1 != size2){
        std::cout << "These vectors are not the same size" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<float> subbedVec;

    for(int i = 0; i < size1; i++){
        subbedVec.push_back(0);
    }

    for(int i = 0; i < size1; i++){
        subbedVec[i] = (*data1)[i] - (*data2)[i];
    }

    return subbedVec;
}
        
std::vector<float> BigCass::VecOps::divConst(std::vector<float>* data, int size, int constant){
    std::vector<float> divvedVec;

    for(int i = 0; i < size; i++){
        divvedVec.push_back(0);
    }

    for(int i = 0; i < size; i++){
        divvedVec[i] = (*data)[i] / constant;
    }

    return divvedVec;
}