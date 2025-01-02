#pragma once

// Iostream - STD I/O Library
#include <iostream>

// Vector - STD Vector/Array Library
#include <vector>

// String - STD String Library
#include <string>

// fStream - STD File I/O Library
#include <fstream>

// Math.h - STD math Library
#include <math.h>

#include "OBJLoader.h"

class Model
{
private:
  GLuint list;

public:
  void Load(std::string filename)
  {
    OBJ::Loader loader;
    loader.LoadFile(filename);
    list = glGenLists(1);

    glDisable(GL_COLOR_MATERIAL);
    glNewList(list, GL_COMPILE);
    glPushAttrib(GL_LIGHTING_BIT);
    for (int i = 0; i < loader.LoadedMeshes.size(); i++)
    {
      glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *)&loader.LoadedMeshes[i].MeshMaterial.Ka);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *)&loader.LoadedMeshes[i].MeshMaterial.Kd);
      glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *)&loader.LoadedMeshes[i].MeshMaterial.Ks);
      glMaterialfv(GL_FRONT, GL_EMISSION, (GLfloat *)&loader.LoadedMeshes[i].MeshMaterial.Ke);
      glMaterialf(GL_FRONT, GL_SHININESS, loader.LoadedMeshes[i].MeshMaterial.Ns);
      glBegin(GL_TRIANGLES);
      for (int j = 0; j < loader.LoadedMeshes[i].Indices.size(); j++)
      {
        int index = loader.LoadedMeshes[i].Indices[j];
        glNormal3fv((GLfloat *)&loader.LoadedMeshes[i].Vertices[index].Normal);
        glTexCoord2fv((GLfloat *)&loader.LoadedMeshes[i].Vertices[index].TextureCoordinate);
        glVertex3fv((GLfloat *)&loader.LoadedMeshes[i].Vertices[index].Position);
      }
      glEnd();
    }
    glPopAttrib();
    glEndList();

    std::cout << "TEST: " << loader.LoadedIndices.size() << " " << loader.LoadedVertices.size() << '\n';
  }

  void Draw()
  {
    glCallList(list);
  }
};