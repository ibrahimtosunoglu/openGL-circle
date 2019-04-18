#include<GL/glew.h>
#include<iostream>
#include<GLFW/glfw3.h>
#include<math.h>

#define PI 3.14159265

int main()
{
	GLFWwindow * pencere;//glfw penceresi
	//GLFW ba�lad�m�
	if (!glfwInit())
	{
		std::cout << "GLFW ba�lat�lmas�nda hata oldu";
		exit(-1);
	}
	pencere = glfwCreateWindow(800, 800, "Pencere", 0, 0);//Pencereyi olu�tur

	if (!pencere)
	{
		std::cout << "Pencere olu�turalamad�";
		glfwTerminate(); //glfw ��k�lmadan �nce mutlaka kapat�lmal�d�r.
		return -1;
	}

	glfwMakeContextCurrent(pencere);// pencere i�in bir opengl context olu�tur.

	GLenum err = glewInit();// Context olu�turulduktan sonra glew olu�turulmal�d�r.

	if (GLEW_OK != err)
	{
		std::cout << "Glew ba�lat�lmad�";
		glfwTerminate();
		return -1;
	}

	int aci = 10;
	int aci_temp = aci;
	float temp_x = 0.0f;
	float temp_y = 0.0f;
	int tur = (int) 360/aci;


	while (!glfwWindowShouldClose(pencere)) //pencere durumuna ��k�� gelmeyene kadar devam et
	{
		glClearColor(0.2f, 0.f, 0.8f, 0.f);// pencere rengini belirle
		glClear(GL_COLOR_BUFFER_BIT); //Color bufferi yeni renk i�in temizle

		
		glBegin(GL_TRIANGLES);// bir geometri �izilirken begin ile ba�lar end ile biter
		for (int i = 0; i < tur; i++) {

		glVertex3f(0.0f, 0.0f, 0.0f);//birinci vertex


		glVertex3f(temp_x, temp_y, 0.f);//ikinci vertex


		glVertex3f((float) cos(aci * PI / 180.0), (float)sin(aci * PI / 180.0), 0.f);//3 vertex

		temp_x = (float)cos(aci * PI / 180.0);
		temp_y = (float)sin(aci * PI / 180.0);
		aci = aci + aci_temp;
		}
		glEnd(); //��gen geometrisi i�in �izimi bitir
		
		
		glfwSwapBuffers(pencere);// �izimi yapmak i�in swapbuffer atamas� yap
		glfwPollEvents();

	}



}
