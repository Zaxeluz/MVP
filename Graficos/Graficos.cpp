// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

#include <iostream>
#include <time.h>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "nave.h"

using namespace std;


GLfloat red, green, blue;

GLuint posicionID;
GLuint colorID;
GLuint ModeloID;
GLuint vistaID;
GLuint proyeccionID;

mat4 vista;
mat4 proyeccion;

Nave *nave;
Modelo *cuadrado;

Shader *shader;
//Declaraci�n de ventana
GLFWwindow *window;

//Propiedades de la ventana
GLfloat ancho = 1024;
GLfloat alto = 768;

vec3 posicionCamara;
GLfloat x = 3.0f, y = 5.0f, z = 9.0f;

void actualizar() {
	int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoderecha == GLFW_PRESS) {
		x = x + 0.01f;
		}
	

	int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoizq == GLFW_PRESS) {
		x = x - 0.01f;
	}

	int estadoarriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoarriba == GLFW_PRESS) {
		y = y + 0.01f;
	}


	int estadoabajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoabajo == GLFW_PRESS) {
		y = y - 0.01f;
	}

	int estadosi = glfwGetKey(window, GLFW_KEY_E);
	if (estadosi == GLFW_PRESS) {
		z = z + 0.01f;
	}


	int estadono = glfwGetKey(window, GLFW_KEY_Q);
	if (estadono == GLFW_PRESS) {
		z = z - 0.01f;
	}

	posicionCamara = vec3(x, y, z);

	vista = lookAt(posicionCamara,           //Posicion de la c�mara 
		vec3(0.0f, 0.0f, 0.0f),              //Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));             //Vector hacia arriba (rotaci�n c�mara)

	cuadrado->vista = vista;
		
};


void dibujar() {

	cuadrado->dibujar(GL_POLYGON);
	//figura2->dibujar(GL_POLYGON);
}



void inicializarFigura() {
	
}


void inicializarCuadrado() {
	cuadrado = new Modelo();
	srand(time(NULL));
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4(float(rand() % 101) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,(float(float(rand() % 101))) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, 1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vertices.push_back({ vec4(1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, 1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });
	cuadrado->vertices.push_back({ vec4(-1.0f, -1.0f, -1.0f, 1.0f),vec4((float(rand() % 101)) / 100,(float(rand() % 101)) / 100,(float(rand() % 101)) / 100,1.0f) });

	cuadrado->vista = vista;
	cuadrado->proyeccion = proyeccion;

}

void inicializarVista() {
	vista = lookAt(posicionCamara,           //Posicion de la c�mara 
		vec3(0.0f, 0.0f, 0.0f),              //Posicion del objetivo
		vec3(0.0f, 1.0f, 0.0f));             //Vector hacia arriba (rotaci�n c�mara)
}

void inicializarProyeccion() {
	proyeccion =
		perspective(45.0f,   //Campo de visi�n (FoV)
			ancho / alto,    //Relaci�n de aspecto (Aspect Ratio)
			0.1f,            //Near clipping (desde donde renderea)
			100.0f);         //Far clipping (asta donde renderea)
}

int main()
{
	//Inicializaci�n de GLFW
	if (!glfwInit()) {
		//Si no se inici� bien, terminar la ejecuci�n
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se cre� bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecuci�n
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializ� bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.5f;

	posicionCamara = vec3(x, y, z);

	inicializarVista();
	inicializarProyeccion();

	inicializarFigura();
	inicializarCuadrado();

	//crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new  Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos 
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	ModeloID = glGetUniformLocation (shader->getID(), "modelo");
	vistaID = glGetUniformLocation(shader->getID(), "vista");
	proyeccionID = glGetUniformLocation(shader->getID(), "proyeccion");

	//Desenlazar el shader
	shader->desenlazarShader();

	

	cuadrado->shader = shader;
	cuadrado->inicializarVertexArray(posicionID, colorID,ModeloID,vistaID,proyeccionID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar se�ales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

