#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "camera.h"
#include "shader.h"
#include "ter.h"
#include "char.h"
#include <iostream>



// forward declarations .

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadTexture(const char *path);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;



int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST); //LEAVE DISABLED FOR NOW , NO VISUAL


    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("shader.vs", "shader.fs");

     // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader_2("shader_flat.vs", "shader_flat.fs");

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader_3("shader_flat.vs", "shader_flat.fs");



     //use terrain class to get indicies and verticies vector
    unsigned int terrain_height = 50 ;
    unsigned int terrain_length = 50 ;
      Terrain_gen level;
    std::vector<unsigned int> indicies = level.indicies_gen (terrain_length,terrain_height);
    std::vector<float> verticies = level.verticies_gen(terrain_length,terrain_height,"..\\..\\include\\test.bmp");
      unsigned int ind_num_elements_2 = indicies.size();
    cout << "indicies variable" << ind_num_elements_2  << endl;

    // end terrain clas

    // start char UI class
    // line 1
    char_ui_gen feedback_1;
    std::vector<unsigned int> indicies_ui_1 = feedback_1.gen_UI_space_i();
    std::array<float,100> verticies_ui_1 = feedback_1.gen_UI_space_v();
    //end line 1
    // line 2
    char_ui_gen feedback_2;
    std::vector<unsigned int> indicies_ui_2 = feedback_2.gen_UI_space_i();
    std::array<float,100> verticies_ui_2 = feedback_2.gen_UI_space_v();
    //end line 2
    // line 3
    char_ui_gen feedback_3;
    std::vector<unsigned int> indicies_ui_3 = feedback_3.gen_UI_space_i();
    std::array<float,100> verticies_ui_3 = feedback_3.gen_UI_space_v();
    //end line 3



    // start terrain buffers
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
  //  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(verticies[0]), &verticies[0], GL_STATIC_DRAW); // this line fails after certain number of triangles
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  //  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(indicies[0]), &indicies[0], GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // end terrain buffers


    // start flat text buffers line 1
     unsigned int VBO_1, VAO_1, EBO_1;
    glGenVertexArrays(1, &VAO_1);
    glGenBuffers(1, &VBO_1);
    glGenBuffers(1, &EBO_1);
    glBindVertexArray(VAO_1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_1);
    glBufferData(GL_ARRAY_BUFFER, verticies_ui_1.size() * sizeof(verticies_ui_1[0]), &verticies_ui_1[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_1);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies_ui_1.size() * sizeof(indicies_ui_1[0]), &indicies_ui_1[0], GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(2);
    // texture coord attribute
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(3);
    // end flat text buffers 1

    // texture subroutine .

    unsigned int texture = loadTexture("..\\..\\include\\civet.jpg");
    unsigned int texture_face = loadTexture("..\\..\\include\\text.png");



     // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)  // MAY NOW BE NEEDED
    // -------------------------------------------------------------------------------------------
    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);

    // shader for 2d
    ourShader_2.use();
    ourShader_2.setInt("texture3", 2);
    ourShader_2.setInt("texture4", 3);

    // shader for 2d
    ourShader_3.use();
    ourShader_3.setInt("texture3", 2);
    ourShader_3.setInt("texture4", 3);

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
         // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;


        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // activate shader
        ourShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        // render terrain
        glBindVertexArray(VAO);

            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
           // model = glm::translate(model, cubePositions[i]);

           // model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 0.5f));
            ourShader.setMat4("model", model);

            glDrawElements(GL_TRIANGLE_STRIP, ind_num_elements_2, GL_UNSIGNED_INT,0 );



            // line 1
            // translate letters to the side
            glm::mat4 transform = glm::mat4(1.0);
            transform = glm::translate(transform, glm::vec3(-0.5f, -0.5f, 0.0f));
            // line 2
            // translate letters to the side
            glm::mat4 transform_2 = glm::mat4(1.0);
            transform_2 = glm::translate(transform_2, glm::vec3(-0.5f, -0.2f, 0.0f));
            // line 3
            // translate letters to the side
            glm::mat4 transform_3 = glm::mat4(1.0);
            transform_3 = glm::translate(transform_3, glm::vec3(-0.5f, -0.0f, 0.0f));


           // get matrix's uniform location and set matrix
            ourShader_2.use();
            glBindTexture(GL_TEXTURE_2D, texture_face);
            unsigned int transformLoc = glGetUniformLocation(ourShader_2.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

            // fetch current XYZ os
            glm::vec3 pos = camera.GetXYZPosition();
            //pass in new vertexes
             verticies_ui_1 = feedback_1.Update_disp('x',pos.x);
            // update the vertex buffer for the UI interface
             glBufferSubData(GL_ARRAY_BUFFER, 0,verticies_ui_1.size() * sizeof(verticies_ui_1[0]),&verticies_ui_1[0]);
            glBindVertexArray(VAO_1);
            glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);


            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform_2));
            verticies_ui_1 = feedback_1.Update_disp('y',pos.y);
            glBufferSubData(GL_ARRAY_BUFFER, 0,verticies_ui_1.size() * sizeof(verticies_ui_1[0]),&verticies_ui_1[0]);
            glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);

            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform_3));
            verticies_ui_1 = feedback_1.Update_disp('z',pos.z);
            glBufferSubData(GL_ARRAY_BUFFER, 0,verticies_ui_1.size() * sizeof(verticies_ui_1[0]),&verticies_ui_1[0]);
            glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);



            // end line 1

            /*
            // start line 2
            //pass in new vertexes
            ourShader_2.use();
             verticies_ui_1 = feedback_2.Update_disp('y',pos.y);

            glBindVertexArray(VAO_2);
            glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);
            */
            // end line 2

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteVertexArrays(1, &VAO_1);
    glDeleteBuffers(1, &VBO_1);
    glDeleteBuffers(1, &EBO_1);


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// utility function for loading a 2D texture from file
// ---------------------------------------------------
unsigned int loadTexture(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
