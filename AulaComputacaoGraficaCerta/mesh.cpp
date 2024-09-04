#include "Mesh.h"

Mesh::Mesh() {
	VAO = 0;
	VBO = 0;
	IBO = 0;
}

Mesh::~Mesh() {
	if (VBO != 0) glDeleteBuffers(1, &VBO);
	if (IBO != 0) glDeleteBuffers(1, &IBO);
	if (VAO != 0) glDeleteBuffers(1, &VAO);
}

void Mesh::CreateMesh(GLfloat* vertices, unsigned int numOfVertices,
	GLuint* indices, unsigned int numOfIndices) {
	Mesh::numOfIndices = numOfIndices;

	glGenVertexArrays(1, &VAO); //Cria o VAO
	glBindVertexArray(VAO); //Coloca o VAO em contexto

	glGenBuffers(1, &IBO); //Cria o IBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO); //Coloca o IBO em contexto
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numOfIndices, indices, GL_STATIC_DRAW); //Explica o valor do Array

	glGenBuffers(1, &VBO); //Cria o VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO); //Coloca o VBO em contexto
	glBufferData(GL_ARRAY_BUFFER, numOfVertices, vertices, GL_STATIC_DRAW); //Explica o valor do Array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //Explica os valores de x e y
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //remover do contexto o IBO
	glBindBuffer(GL_ARRAY_BUFFER, 0); //remover do contexto o VBO
	glBindVertexArray(0); //remover do contexto o VAO
}

void Mesh::RenderMesh() {
	glBindVertexArray(VAO);

	/*
	* Desenha o triangulo 3D
	*/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO); //Coloca o IBO em contexto
	glDrawElements(GL_TRIANGLES, Mesh::numOfIndices, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //remover do contexto o IBO
}