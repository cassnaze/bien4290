/* Author: Cassie Naze
 * Created: 22 February 2022
 * This is the C file to define the function for clustering.
 */

#include "nazec_k_means.hpp"

void BigCass::Cluster::setObjName(std::string objectName){
    this->objectName = objectName;
}

std::string BigCass::Cluster::getObjName(){
    return this->objectName;
}

void BigCass::Cluster::setMean(float objectMean){
    this->objectMean = objectMean;
}

float BigCass::Cluster::getMean(){
    return this->objectMean;
}

void BigCass::Cluster::setClusterData(std::vector<float> clusterData){
    this->clusterData = clusterData;
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

    // Class instances that we need to use in this function 
    BigCass::statistics statsFunc;
    BigCass::Cluster supClust;
    BigCass::Cluster statClust;
    BigCass::Cluster expClust;

    // Open the file for the input log data
    // Strings for the names of the files
    std::string infile = argv[1];
    std::string geneFile = argv[2];

    // Strings for holding the data
    std::string dataPlaceHolder;
    std::string genePlaceholder;

    // Placeholder for the incoming data vector
    std::vector<float> vector;
    std::vector<std::string> geneVector;

    // In/out file streams
    std::ifstream stream("log_out.dat");
    std::ifstream geneStream("gene_list.txt");

    // Time to open the data files
    stream.open(infile);
    geneStream.open(geneFile);

    // Variable for file size
    int size = 0, geneListSize = 0;
    
    // Do all the error checking for each file to be sure they exist
    if(stream.is_open()){
        while(std::getline(stream,dataPlaceHolder)){
            vector.push_back(stof(dataPlaceHolder));
            size++;
        }    
    }
    else{
        std:: cout << "That log input data file does not exist or cannot be opened." << std::endl;
        return 1; 
    }

    if(geneStream.is_open()){
        while(std::getline(geneStream,genePlaceholder)){
            geneVector.push_back(genePlaceholder);
            geneListSize++;
        }    
    }
    else{
        std:: cout << "That gene list file does not exist or cannot be opened." << std::endl;
        return 1; 
    }

    // Initialize three different clusters with this initial means
        // Supressed gene: lr = -0.5
    float meanSup = -0.5;
        // Stationary gene: lr = 0
    float meanStat = 0.0;
        // Expressed gene: lr = 0.5
    float meanExp = 0.5;
    
    supClust.setObjName("SurpressedGene");
    supClust.setMean(meanSup);

    statClust.setObjName("StationaryGene");
    statClust.setMean(meanStat);

    expClust.setObjName("ExpressedGene");
    expClust.setMean(meanExp);

    // Write the looping stuff here


    // Add the stuff for the output files

}