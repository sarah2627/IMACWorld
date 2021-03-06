#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Program.hpp"

namespace glimac{

struct CubeProgram{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    GLint uKd;
    GLint uKs;
    GLint uShininess;
    GLint uLightDir_vs;
    GLint uLightIntensityD;
    GLint uLightPos_vs;
    GLint uLightIntensityP;
    GLint uCubeColor;
    GLint uAmbiantLightIntensity;

    CubeProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/directionallight.fs.glsl")){
        //texture
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        uCubeColor = glGetUniformLocation(m_Program.getGLId(), "uCubeColor");
        //lumière 
        uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
        uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
        uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
        uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
        uLightIntensityD = glGetUniformLocation(m_Program.getGLId(), "uLightIntensityD");
        uLightPos_vs = glGetUniformLocation(m_Program.getGLId(), "uLightPos_vs");
        uLightIntensityP = glGetUniformLocation(m_Program.getGLId(), "uLightIntensityP");
        uAmbiantLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uAmbiantLightIntensity");
    }
};

struct CubeProgramTexture{
    Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    GLint uKd;
    GLint uKs;
    GLint uShininess;
    GLint uLightDir_vs;
    GLint uLightIntensityD;
    GLint uLightPos_vs;
    GLint uLightIntensityP;
    GLint uCubeColor;
    GLint uAmbiantLightIntensity;

    CubeProgramTexture(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/directionallighttexture.fs.glsl")){
        //texture
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
        uCubeColor = glGetUniformLocation(m_Program.getGLId(), "uCubeColor");
        //lumière 
        uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
        uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
        uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
        uLightDir_vs = glGetUniformLocation(m_Program.getGLId(), "uLightDir_vs");
        uLightIntensityD = glGetUniformLocation(m_Program.getGLId(), "uLightIntensityD");
        uLightPos_vs = glGetUniformLocation(m_Program.getGLId(), "uLightPos_vs");
        uLightIntensityP = glGetUniformLocation(m_Program.getGLId(), "uLightIntensityP");
        uAmbiantLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uAmbiantLightIntensity");
    }
};

}