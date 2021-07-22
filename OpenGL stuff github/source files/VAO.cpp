#include "../headers/VAO.hpp"

VAO::VAO()
{
    glad_glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
    VBO.Bind();
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

//binds the vertex array object
void VAO::Bind()
{
    glBindVertexArray(ID);
}

//unbinds the vertex array object as to not accidentally modify it from now on
void VAO::Unbind()
{
    glBindVertexArray(0);
}

//deletes the vertex array object to free up memory
void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}