#include<GL/glew.h>
#include<iostream>
#include<GLFW/glfw3.h>
#include<math.h>

#define PI 3.14159265

int main()
{
	GLFWwindow * pencere;//glfw penceresi
	//GLFW baþladýmý
	if (!glfwInit())
	{
		std::cout << "GLFW baþlatýlmasýnda hata oldu";
		exit(-1);
	}
	pencere = glfwCreateWindow(800, 800, "Pencere", 0, 0);//Pencereyi oluþtur

	if (!pencere)
	{
		std::cout << "Pencere oluþturalamadý";
		glfwTerminate(); //glfw çýkýlmadan önce mutlaka kapatýlmalýdýr.
		return -1;
	}

	glfwMakeContextCurrent(pencere);// pencere için bir opengl context oluþtur.

	GLenum err = glewInit();// Context oluþturulduktan sonra glew oluþturulmalýdýr.

	if (GLEW_OK != err)
	{
		std::cout << "Glew baþlatýlmadý";
		glfwTerminate();
		return -1;
	}

	int aci = 10;
	int aci_temp = aci;
	float temp_x = 0.0f;
	float temp_y = 0.0f;
	int tur = (int) 360/aci;


	while (!glfwWindowShouldClose(pencere)) //pencere durumuna çýkýþ gelmeyene kadar devam et
	{
		glClearColor(0.2f, 0.f, 0.8f, 0.f);// pencere rengini belirle
		glClear(GL_COLOR_BUFFER_BIT); //Color bufferi yeni renk için temizle

		
		glBegin(GL_TRIANGLES);// bir geometri çizilirken begin ile baþlar end ile biter
		for (int i = 0; i < tur; i++) {

		glVertex3f(0.0f, 0.0f, 0.0f);//birinci vertex


		glVertex3f(temp_x, temp_y, 0.f);//ikinci vertex


		glVertex3f((float) cos(aci * PI / 180.0), (float)sin(aci * PI / 180.0), 0.f);//3 vertex

		temp_x = (float)cos(aci * PI / 180.0);
		temp_y = (float)sin(aci * PI / 180.0);
		aci = aci + aci_temp;
		}
		glEnd(); //üçgen geometrisi için çizimi bitir
		
		
		glfwSwapBuffers(pencere);// çizimi yapmak için swapbuffer atamasý yap
		glfwPollEvents();

	}



}
