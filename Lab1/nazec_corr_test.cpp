/* Author: Cassie Naze
 * Created: 7 February 2022
 * This file is where the main function is for testing the correlation coef program and values and printed to the screen.
*/

#include "nazec_corr.hpp"
#include "nazec_stats.hpp"
#include "nazec_corr.cpp"
#include <experimental/filesystem>

using namespace BigCass;
//using namespace std;

/* This is the main function where all of the statistics are calculated and printed to the screen
 * @param data1: Input path for the first data file
 * @param data2: Input path for the second data file
 */ 

int main(int argc, char** argv){
    
    std:: cout << "She's running" << std::endl;

    // Check number of arguments that the function is taking in first
    if(argc > 3 || argc < 3){
        std:: cout << "Wrong number of arguments entered.. try again!" << std::endl;
        return 1; 
    }
    
    // Tried to do something here to check if the file existed but this wasnt necessary
//    if(std::experimental::filesystem::exists(argv[1]) || std::experimental::filesystem::exists(argv[1])){
//        std:: cout << "One of these data files does not exist." << std::endl;
//        return 1; 
//    }

    BigCass::correlation corrFunctions;

    // Making the variables for the data files
    std::ifstream inVector1;
    std::ifstream inVector2;

    std::vector<float> vector1;
    std::vector<float> vector2;

    std::string placeHolder1; // Placeholder for the data when it comes in from the ifstream
    std::string placeHolder2; 

    // Opening the data files
    std::string dataString1 = argv[1];
    inVector1.open(dataString1);
    std::string dataString2 = argv[2];
    inVector2.open(dataString2);

    int size1 = 0;
    int size2 = 0;

    float corrCoeff = 0;

    // Tried hardcoding these in before inserting as args in command line
    //inVector1.open("/lab/bien4290/ERP/ERP00/ERP001.txt");
    //inVector2.open("/lab/bien4290/ERP/ERP00/ERP002.txt");

    // Error checking to make sure the data exists
    // Print error to screen if not and terminate analysis
    if(inVector1.is_open()){
        while(std::getline(inVector1,placeHolder1)){
            //dataString1 = inVector1.get();
            vector1.push_back(stof(placeHolder1));
            size1++;
        }    
    }
    else{
        std:: cout << "Data file 1 don't exist" << std::endl;
        return 1; 
    }

    if(inVector2.is_open()){
        while(std::getline(inVector2,placeHolder2)){
            vector2.push_back(stof(placeHolder2));
            size2++;
        }
    }
    else{
        std:: cout << "Data file 2 don't exist." << std::endl;
        return 1; 
    }
        
    if(size1 == size2){
        corrCoeff = corrFunctions.calcCorrCoef(&vector1, &vector2, size2);
    }
    else{
        std:: cout << "Data files are not the same size. Cannot calculate values." << std::endl;
        return 1; 
    }

    // Write quantity to the screen        
    std::cout <<"Number of points in vector1: " << size1 << std::endl;
    std::cout << "Number of points in vector2: " << size2 << std::endl;

    std::cout << "Correlation coefficient: " << corrCoeff << std::endl;
}