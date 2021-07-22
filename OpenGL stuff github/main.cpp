#include <iostream>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <tgmath.h>

#include "headers/shaderClass.hpp"
#include "headers/VAO.hpp"
#include "headers/VBO.hpp"
#include "headers/EBO.hpp"


using namespace std;

    // Vertices coordinates
GLfloat vertices[] =
{ //               COORDINATES                  /     COLORS           //
	-0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
};

    GLuint indices[] =
    {
        0, 3, 5, //lower left triangle
        3, 2, 4, //lower right triangle
        5, 4, 1 //upper triangle
    };

int main(){
    //defining window width and height
    int windowWidth = 800;
    int windowHeight = 800;

    //asking for window width and height before launching the window for ultimate chadness
    /*cout << "What should the window height be?\n";
    cin >> windowHeight;
    cout << "What should the window width be?\n";
    cin >> windowWidth;*/

    //initialise GLFW
    glfwInit();

    //stop the program with an error code if glfw failed to open
    if(!glfwInit()){
        return -1;
    }

    //defining glfw context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //telling glfw to open a window with a given res with a given name, having it be windowed
    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL tutorial", NULL, NULL);

    //make the program terminate itself with an error message if the window failed to start
    if (window == NULL){
        cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    //tells glfw which window to output context on
    glfwMakeContextCurrent(window);

    //loading up glad
    gladLoadGL();

    //defining the opengl viewport
    glViewport(0, 0, windowWidth, windowHeight);

    //generate shader object using the shader files defined down below
    Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

    //generates vertex array object and binds it
    class VAO VAO1;
    VAO1.Bind();

    //generate vertex buffer object and link it to vertices
    class VBO VBO1(vertices, sizeof(vertices));
    //generate element buffer object and link it to indices
    class EBO EBO1(indices, sizeof(indices));

    //link vbo to vao
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    //unbind all objects as to not accidentally modify them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    //gets ID of uniform called "scale"
    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    //defining the render loop
    while(!glfwWindowShouldClose(window)){
        // Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
        //assigns a value to the uniform
        glUniform1f(uniID, 0.5f);
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
    }

    // Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}