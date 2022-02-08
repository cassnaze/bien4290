/* Author: Cassie Naze
 * Created: 7 February 2022
 * This file is where the main function is for testing the correlation coef program and values and printed to the screen.
*/

#include "nazec_corr.hpp"
#include "nazec_stats.hpp"
using namespace BigCass;

/* This is the main function where all of the statistics are calculated and printed to the screen
 * @param data1: Input path for the first data file
 * @param data2: Input path for the second data file
 */

int main(int argc, char** argv){
    
    std:: cout << "She's running" << std::endl;

    BigCass::correlation corrFunctions;

    // Open the data file
    std::ifstream indata1;
    std::ifstream indata2;

    std::string data1;
    std::string data2;

    std::vector<float> vector1;
    std::vector<float> vector2;

    //float data1;
    //float data2;
    int size1;
    int size2;
    float corrCoeff;

    indata1.open("/lab/bien4290/ERP/ERP00/ERP001.txt");
    indata2.open("/lab/bien4290/ERP/ERP00/ERP002.txt");

    // Error checking first to make sure the data exists
    if(indata1.is_open() && indata2.is_open()){
        while(std::getline(indata1,data1)){
            //data1 = indata1.get();
            size1++;
            vector1.push_back(stof(data1));
        }    
        while(std::getline(indata2,data2)){
            size2++;
            vector2.push_back(stof(data2));
        }

        std::cout <<"Size of 1 is " << size1 << std::endl;
        std::cout << "Size of 2 is " << size2 << std::endl;
        
        if(size1 == size2){
            corrCoeff = corrFunctions.calcCorrCoef(&vector1, &vector2, size1);
        }
        else{
            std:: cout << "Data files are not the same size" << std::endl;
            return 0; 
        }
    }


    // Print error to screen if not and terminate analysis

    // Write quantity to the screen 

}