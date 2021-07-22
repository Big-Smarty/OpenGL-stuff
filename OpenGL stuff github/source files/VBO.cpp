#include "../headers/VBO.hpp"

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

//binds the vertex buffer object
void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

//unbinds the vertex buffer object as to not accidentally modify it further on
void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//deletes the vertex buffer object to free up memory
void VBO::Delete()
{
    glDeleteBuffers(1, &ID);
}