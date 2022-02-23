/* Author: Cassie Naze
 * Created: 22 February 2022
 * This is the C file to define the function for clustering.
 */

#include "nazec_k_means.hpp"

void BigCass::Cluster::setter(std::string objectName, float objectMean, std::vector<float> clusterData){
    this->objectName = objectName;
    this->objectMean = objectMean;
    this->clusterData = clusterData;
}

std::string BigCass::Cluster::getObjName(){
    return this->objectName;
}

float BigCass::Cluster::getMean(){
    return this->objectMean;
}
        
std::vector<float> BigCass::Cluster::getClusterData(){
    return this->clusterData;
}

float BigCass::Cluster::distance(float logData){
    // calculated |a-b|
    float distance = 0;
    distance = abs((this->objectMean) - logData);
    return distance;
}

int main(int argc, char** argv){

    BigCass::statistics statsFunc;
    BigCass::Cluster clusterFunc;

    // Open the file for the input log data
    // Strings for the names of the files
    std::string infile = argv[1];

    // Strings for holding the data
    std::string dataPlaceHolder;

    // Placeholder for the incoming data vector
    std::vector<float> vector;

    // In/out file streams
    std::ifstream stream("log_ratio_input.dat");

    // Time to open the data files
    stream.open(infile);

    // Variable for file size
    int size = 0;
    
    // Do all the error checking for each file to be sure they exist
    if(stream.is_open()){
        while(std::getline(stream,dataPlaceHolder)){
            vector.push_back(stof(dataPlaceHolder));
            size++;
        }    
    }
    else{
        std:: cout << "That log input data file does not exist." << std::endl;
        return 1; 
    }

}