/* Author: Cassie Naze
 * Created: 22 February 2022
 * The purpose of this header file is to declare a function for clustering.
 */

#ifndef CLUSTY
#define CLUSTY

#include "nazec_pre_processing.hpp"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <stdlib.h>


namespace BigCass{
    class Cluster{
        public:
            /* This is the setter function for all of the privata variables.
             * @param objectName: The name of the cluster.
             * @param objectMean: The mean of the cluster.
             * @param clusterDataPoints: The vector of data points in the cluster.
             */
            void setter(std::string objectName, float objectMean, std::vector<float> clusterDataPoints);
            
            /* This is the getter function for the object name variable.
             * @returns: The string with the cluster name.
             */
            std::string getObjName();
            
            /* This is the setter function for the object mean variable.
             * @returns: The variable with the cluster mean.
             */
            float getMean();
        
            /* This is the setter function for the cluster data vector.
             * @returns: The vector with the cluster data points.
             */
            std::vector<float> getClusterData();

            /* This function calculates the distance from the data point to the cluster object.
             * @param datapoint: The input data point
             * @returns: The distance from the point to the cluster object 
             */
            float distance(float logData);

        private:
            // The variables that need to be gotted.
            std::string objectName;
            float objectMean;
            std::vector<float> clusterData;
    };
}

#endif