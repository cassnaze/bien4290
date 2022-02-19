/* Author: Cassie Naze
 * Created: 19 February 2022
 * This is the C++ file where the preprocessing function with be defined.
 */

#include "nazec_pre_processing.hpp"
#include "nazec_stats.hpp"
#include "nazec_vector_ops.hpp"

void BigCass::PreProcessing::setter(float ratio){
    this->ratio = ratio;
}

void BigCass::PreProcessing::logRatio(std::vector<float>* data1, int size1, std::vector<float>* data2, int size2, std::vector<float> lr){
    if(size1 != size2){
        std::cout << "These vectors are not the same size" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size1; i++){
        lr.push_back(0);
    }

    for(int i = 0; i < size1; i++){
        lr[i] = log10((*data1)[i] / (*data2)[i]);
    }

}

int main(int arcg, char** argv){

}