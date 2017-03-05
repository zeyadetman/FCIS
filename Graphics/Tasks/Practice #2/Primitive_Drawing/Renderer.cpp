#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	Cleanup();
}

void Renderer::Initialize()
{
	///////////////////////////////////////////////////////////////////////////////////////////
	/// Start Drawing your primitive
	////////////////////////////////

	// Set the background color to white
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	// [TODO] 1) create the data array (stored in RAM)
	GLfloat verts[] = 
	{ 
		-0.8f, +1.0f, +0.0f,  //up
		-1.0f, +0.0f, +0.0f, //down r
		-0.6f, 0.0f, +0.0f, //down l

		+0.8f, +1.0f, +0.0f, //up
		+0.6f, +0.0f, +0.0f, //down r
		+1.0f, 0.0f, +0.0f,  //down l

		+0.0f, +1.0f, +0.0f, //up
		0.6f, 0.0f, +0.0f, //down r
		-0.6f, 0.0f, +0.0f  //down l
	};

	GLuint myBufferID;
	glGenBuffers(1, &myBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	
	programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
	glUseProgram(programID);
}

void Renderer::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(programID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
	glDrawArrays(GL_TRIANGLES,0,9);

	
}

void Renderer::Cleanup()
{
	glDeleteBuffers(1, &vertexBufferID);
	glDeleteProgram(programID);
}