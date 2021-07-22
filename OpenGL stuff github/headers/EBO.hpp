#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include "../include/glad/glad.h"

class EBO
{
    public:
        GLuint ID;
        EBO(GLuint* indices, GLsizeiptr suze);

        void Bind();
        void Unbind();
        void Delete();
};

#endif