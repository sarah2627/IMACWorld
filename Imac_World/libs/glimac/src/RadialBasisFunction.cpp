#include "glimac/RadialBasisFunction.hpp"
#include <Eigen/Dense>
#include <random>

namespace glimac{


    double RadialBasisFunction::distance(glm::vec3 A, glm::vec3 B)
    {
        return sqrt( std::pow(A[0]-B[0], 2) + std::pow(A[1]-B[1], 2) + std::pow(A[2]-B[2], 2));
    }

    double RadialBasisFunction::radialFunctionGauss( glm::vec3 A, glm::vec3 B)
    {
        return glm::exp(- std::pow(distance(A,B), 2));
        //return glm::exp(-std::pow(glm::distance(A,B),2));
    }

    double RadialBasisFunction::radialFunctionInverseQuadra( glm::vec3 A, glm::vec3 B)
    {
        return 1.0/(1.0+(pow(distance(A,B), 2)));
    }

    double RadialBasisFunction::radialFunctionMultiQuadra( glm::vec3 A, glm::vec3 B)
    {
        return sqrt(1.0+(pow(distance(A,B), 2)));
    }

    double RadialBasisFunction::radialFunctionInverseMultiQuadra( glm::vec3 A, glm::vec3 B)
    {
        return 1.0/radialFunctionMultiQuadra(A,B);
    }

    Eigen::VectorXd RadialBasisFunction::findOmega()
    {
        Eigen::MatrixXd M = Eigen::MatrixXd::Zero(m_ValuePoint.size(),m_ValuePoint.size()); 
        for(int i=0; i<m_ValuePoint.size(); i++)
        {
            for(int j =0; j<m_ValuePoint.size(); j++)
            {
                M(i,j) = radialFunctionGauss(m_Points[i], m_Points[j]);
            }    
        }
        return M.inverse()*m_ValuePoint;
        //return M.colPivHouseholderQr().solve(m_ValuePoint);
    } 



    RadialBasisFunction::RadialBasisFunction()
        : m_ValuePoint(3), m_Omega(3)
    {
        // we choose the position
        m_Points.push_back(glm::vec3(0.f, 0.f, 0.f));
        m_Points.push_back(glm::vec3(10.f, 0.f, 0.f));
        m_Points.push_back(glm::vec3(0.f,5.f, 5.f));
        
        // we create the value
        m_ValuePoint[0] = 30.f; 
        m_ValuePoint[1] = -18.0;
        m_ValuePoint[2] = -4.0;

        m_Omega = findOmega();
    }

    
    double RadialBasisFunction::calculBasisFunction(glm::vec3 V)
    {
        double sum = 0.0;
        for(int i = 0; i < m_Omega.size(); i++)
        {
            sum += m_Omega[i] * radialFunctionGauss(m_Points[i], V);
        }
        return sum;
    }

}






