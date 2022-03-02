/* Author: Cassie Naze
 * Created: 22 February 2022
 * This is the C file to define the function for clustering.
 */

#include "nazec_k_means.hpp"
#include "nazec_stats.hpp"
//#include "nazec_pre_processing.hpp"

//using namespace BigCass;

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

std::vector<float>* BigCass::Cluster::getClusterData(){
    return &(this->clusterData);
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
    std::string inFile = argv[1];
    //std::string geneFile = argv[2]; // hard code this one in there

    // Strings for holding the data
    std::string dataPlaceHolder;

    // Placeholder for the incoming data vector
    std::vector<float> vector;

    // In/out file streams
    std::ifstream stream;
    std::ifstream geneFile("/home/nazec/bien4290/Lab2/microarray/gene_list.txt");

    // Time to open the data files
    stream.open(inFile);
    //geneStream.open("/home/nazec/bien4290/Lab2/microarray/gene_list.txt");

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
        std:: cout << "That log input data file does not exist or cannot be opened." << std::endl;
        return 1; 
    }
    std::cout << "size is : " << vector.size() << std::endl;

    if(geneFile.is_open()){
        /*while(std::getline(geneStream,genePlaceholder)){
            geneVector.push_back(genePlaceholder);
            geneListSize++;
        }*/
        //std::cout << "Opening gene list" << std::endl;
    }
    else{
        std::cout << "That gene list file does not exist or cannot be opened." << std::endl;
        return 1; 
    }



    // Initialize three different clusters with this initial means
        // Supressed gene: lr = -0.5
    float meanSup = -0.5;
    float distSup = 0;
        // Stationary gene: lr = 0
    float meanStat = 0.0;
    float distStat = 0;
        // Expressed gene: lr = 0.5
    float meanExp = 0.5;
    float distExp = 0;
    
    supClust.setObjName("SurpressedGene");
    supClust.setMean(meanSup);

    statClust.setObjName("StationaryGene");
    statClust.setMean(meanStat);

    expClust.setObjName("ExpressedGene");
    expClust.setMean(meanExp);

    // Write the looping stuff here
    float sumMeans = 100.0;
    int supSize, statSize, expSize;

    while(sumMeans > 0.0001){

        // Reset the size counts
        supSize = 0, statSize = 0, expSize = 0;

        supClust.getClusterData()->clear();
        statClust.getClusterData()->clear();
        expClust.getClusterData()->clear();

        for(int i = 0; i < size; i++){
            distSup = supClust.distance(vector.at(i));
            distStat = statClust.distance(vector.at(i));
            distExp = expClust.distance(vector.at(i));

            if((distSup <= distStat) && (distSup <= distExp)){
                supClust.getClusterData()->push_back(vector.at(i));
                supSize++;
            }
            else if((distStat <= distSup) && (distStat <= distExp)){
                statClust.getClusterData()->push_back(vector.at(i));
                statSize++;
            }
            else{
                expClust.getClusterData()->push_back(vector.at(i));
                expSize++;
            }
        }
        //std::cout << supSize <<std::endl;

        // Calculate the new means after finding the closest cluster
        meanSup = statsFunc.calcMean(supClust.getClusterData(),supSize);
        meanStat = statsFunc.calcMean(statClust.getClusterData(),statSize);
        meanExp = statsFunc.calcMean(expClust.getClusterData(),expSize);

        // Calculate the new sum
        sumMeans = abs(supClust.getMean() - meanSup) + abs(statClust.getMean() - meanStat) + abs(expClust.getMean() - meanExp);

        // Set the new means to cycle through again
        supClust.setMean(meanSup);
        statClust.setMean(meanStat);
        expClust.setMean(meanExp);

    }

    // Output the final cluster means
    std:: cout << "Sum of Means: "<< sumMeans << std::endl;
    std:: cout << "Supressed Genes Mean: "<< meanSup << std::endl;
    std:: cout << "Stationary Genes Mean: "<< meanStat << std::endl;
    std:: cout << "Expressed Genes Mean: "<< meanExp << std::endl;

    // Add the stuff for the output files
    std::ofstream outstreamSup("suppressed_genes.txt");
    std::ofstream outstreamStat("stationary_genes.txt");
    std::ofstream outstreamExp("expressed_genes.txt");

    // Find the max and min values for the stationary cluster because it is in the middle
        // Values from the last run of the loop are still saved in the variables
    float statMin = statsFunc.calcMin(statClust.getClusterData(),statSize);
    float statMax = statsFunc.calcMax(statClust.getClusterData(),statSize);

    // Create a vector here that will hold the lines of the gene file
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(geneFile, line)){
        lines.push_back(line);
    }
    
    std::cout << "Number of suppressed genes: " << supSize << std::endl;
    std::cout << "Number of stationary genes: " << statSize << std::endl;
    std::cout << "Number of expressed genes: " << expSize << std::endl;
    //int newSize = supSize + statSize + expSize;
    //std::cout << "size is " << newSize << std::endl;
    
    // We do checking at the beginning to make sure the input data and gene file is open
    for(int i = 0; i < size; i++){
        if(outstreamSup.is_open() && outstreamStat.is_open() && outstreamExp.is_open()){
            if(vector.at(i) <= statMin){
				outstreamSup << lines[i] << " " << vector.at(i) << std::endl;
			}
			else if(vector.at(i) >= statMax){
				outstreamExp << lines[i] << " " << vector.at(i) << std::endl;
			}
			else{
				outstreamStat << lines[i] << " " << vector.at(i) << std::endl;
			}
        }
        else{
            std::cout << "One or more of the output files is not open. Try running again" << std::endl;
            return 1;
        }
    }

}