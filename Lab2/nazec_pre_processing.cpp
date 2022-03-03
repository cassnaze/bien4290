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

void BigCass::PreProcessing::logRatio(std::vector<float>* data1, int size1, std::vector<float>* data2, int size2, std::vector<float>* lr){
    if(size1 != size2){
        std::cout << "These vectors are not the same size" << std::endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size1; i++){
        lr->push_back(0);
    }

    for(int i = 0; i < size1; i++){
        lr->at(i) = log10((*data1)[i] / (*data2)[i]);
    }
}

int main(int argc, char** argv){
    // Check number of arguments that the function is taking in first
    if(argc > 7 || argc < 7){
        std:: cout << "WRONG number of arguments entered.. try again!" << std::endl;
        return 1; 
    }

    // Instances of the classes
    BigCass::PreProcessing logFunc;
    BigCass::statistics statsFunc;
    BigCass::VecOps vecFunc;

    // Strings for the names of the files
    std::string infile1 = argv[1];
    std::string infile2 = argv[2];
    std::string infile3 = argv[3];
    std::string infile4 = argv[4];
    std::string outfile(argv[5]);

    // Strings for holding the data
    std::string dataPlaceHolder1;
    std::string dataPlaceHolder2;
    std::string dataPlaceHolder3;
    std::string dataPlaceHolder4;

    // Placeholder for the incoming data vector
    std::vector<float> vector1;
    std::vector<float> vector2;
    std::vector<float> vector3;
    std::vector<float> vector4;

    // In/out file streams
    std::ifstream stream1;
	std::ifstream stream2;
	std::ifstream stream3;
    std::ifstream stream4;
	std::ofstream outstream;

    // Time to open the data files
    stream1.open(infile1);
    stream2.open(infile2);
    stream3.open(infile3);
    stream4.open(infile4);
    outstream.open(outfile);

    // Size vectors to keep track of the number of data points
    int size1 = 0, size2 = 0, size3 = 0, size4 = 0;

    // Do all the error checking for each file to be sure they exist
    if(stream1.is_open()){
        while(std::getline(stream1,dataPlaceHolder1)){
            vector1.push_back(stof(dataPlaceHolder1));
            size1++;
        }    
    }
    else{
        std:: cout << "Sporulating data file doesn't exist." << std::endl;
        return 1; 
    }

    if(stream2.is_open()){
        while(std::getline(stream2,dataPlaceHolder2)){
            vector2.push_back(stof(dataPlaceHolder2));
            size2++;
        }    
    }
    else{
        std:: cout << "Background red data file doesn't exist." << std::endl;
        return 1; 
    }

    if(stream3.is_open()){
        while(std::getline(stream3,dataPlaceHolder3)){
            vector3.push_back(stof(dataPlaceHolder3));
            size3++;
        }    
    }
    else{
        std:: cout << "Non-sporulating data file doesn't exist." << std::endl;
        return 1; 
    }

    if(stream4.is_open()){
        while(std::getline(stream4,dataPlaceHolder4)){
            vector4.push_back(stof(dataPlaceHolder4));
            size4++;
        }    
    }
    else{
        std:: cout << "Background green data file doesn't exist." << std::endl;
        return 1; 
    }


    // Compare the sizes of the data files
    int redSize = 0;
    int greenSize = 0;
    if(size1 == size2){
        //std::cout << "Data 1 size: " << size1 <<std::endl;
        //std::cout << "Data 2 size: " << size2 <<std::endl;
        redSize = size1;
    }  
    else{
        std::cout << "Data 1 size: " << size1 <<std::endl;
        std::cout << "Data 2 size: " << size2 <<std::endl;
        std::cout << "The sporulating data is larger than the background data. Cannot run." << std::endl;
        return 1;
    }

    if(size3 == size4){
        //std::cout << "Data 3 size: " << size3 <<std::endl;
        //std::cout << "Data 4 size: " << size4 <<std::endl;
        greenSize = size3;
    }  
    else{
        std::cout << "Data 3 size: " << size3 <<std::endl;
        std::cout << "Data 4 size: " << size4 <<std::endl;
        std::cout << "The non-sporulating data is larger than the background data. Cannot run." << std::endl;
        return 1;
    }
    

    // Look at the input argument for the number of genes and compare the num genes there should be
    int numGenes = std::stoi(argv[6]);
    int maxDataPoints = 6118; // This comes from the lab manual; each file should have this many points

    if(numGenes > maxDataPoints){
        std::cout << "The number of genes is more than the number of data points given. Try again" << std::endl;
        return 1;
    }

    // Call our functions now
    std::vector<float> subRed = vecFunc.sub(&vector1, redSize, &vector2, redSize);
    std::vector<float> subGreen = vecFunc.sub(&vector3, greenSize, &vector4, greenSize);

    float meanRed = statsFunc.calcMean(&subRed, redSize);
    float meanGreen = statsFunc.calcMean(&subGreen, greenSize);;

    std::vector<float> divRed = vecFunc.divConst(&subRed, redSize, meanRed);
    std::vector<float> divGreen = vecFunc.divConst(&subGreen, greenSize, meanGreen);;

    std::vector<float> lr;
    if(redSize == maxDataPoints){
        logFunc.logRatio(&divRed, redSize, &divGreen, greenSize, &lr);
    }

    // Do the output file stuff yuh
    if(outstream.is_open()){
        for(int i = 0; i < redSize; i++){
            outstream << lr[i];
            outstream << "\n";
            //std::cout << "Log Ratio at point " << i << ": " << lr[i] <<std::endl;
        }
    }
    else{
        std:: cout << "Either the file is not open or the log ratio can't be calculated." << std::endl;
        return 1; 
    }

    outstream.close();
}