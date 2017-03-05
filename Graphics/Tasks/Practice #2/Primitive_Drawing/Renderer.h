#include <gl/glew.h>
#include "shader.hpp"
#pragma once

class Renderer
{
    GLuint vertexBufferID;
    GLuint programID;
	GLuint vertexPosition_modelspaceID;
    
public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
    void Cleanup();
};
