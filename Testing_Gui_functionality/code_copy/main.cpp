#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//code for adjusting window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
//processes input from user
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//vertices for the triangle
float vertices[] =
{
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};

int main()
{

//initialization of glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//Creating a window using glfw
    GLFWwindow* window = glfwCreateWindow(800,600 ,"learningOpenGL", NULL, NULL);
    if(window ==NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
//make the context of our window the main context on the current thread.
    glfwMakeContextCurrent(window);

//init glad (manages function pointers for OpenGL)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

//tell gl size of the rendering window
    glViewport(0,0,800,600);


//call function for every window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//Creating a VBO(vertex buffer object)
    unsigned int VBO;
    glGenBuffers(1, &VBO);

//bind buffer using function BindBuffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

//function copies the defined vertex data into buffer memory
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


//render loop
    while(!glfwWindowShouldClose(window))
    {
    // input
        processInput(window);

    // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    //clear colorbuffer with new collor buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

// clear delete GLFW resources allocated
    glfwTerminate();
    return 0;
}