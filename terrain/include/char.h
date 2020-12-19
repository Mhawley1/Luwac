#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>




class char_ui_gen {

    // assume these are private
    int width, height;
    const char * letter_1;
    const char * input_var1;
    const char * letter_2;
    const char * input_var2;
  public:
    // we are outputting these
    // do not need to pass in any argument
    // for verticy return
    std::vector<float> gen_UI_space_v (void);
    // for indicy return
    std::vector<unsigned int> gen_UI_space_i (void);

    std::vector<float> Update_disp (const char*, const char*, const char*, const char*);

};
using namespace std;
// passes in no arguments
std::vector<float> char_ui_gen::gen_UI_space_v (void) {

float face_vertices[] = {
        // positions         // texture coords
         0.0f,  0.1f, 0.0f, 1.0f, 1.0f, // top right
         0.0f,  0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        0.1f,  0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        0.1f,  0.1f, 0.0f, 0.0f, 1.0f,  // top left
        // positions         // texture coords
         0.1f,  0.1f, 0.0f, 1.0f, 1.0f, // top right
         0.1f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        0.2f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        0.2f,  0.1f, 0.0f, 0.0f, 1.0f,  // top left
        // positions         // texture coords
         0.2f,  0.1f, 0.0f, 1.0f, 1.0f, // top right
         0.2f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        0.3f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        0.3f,  0.1f, 0.0f, 0.0f, 1.0f,  // top left

        // positions         // texture coords
         0.3f,  0.1f, 0.0f, 1.0f, 1.0f, // top right
         0.3f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        0.4f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        0.4f,  0.1f, 0.0f, 0.0f, 1.0f,  // top left

        // positions         // texture coords
         0.4f,  0.1f, 0.0f, 1.0f, 1.0f, // top right
         0.4f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        0.5f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom left
        0.5f,  0.1f, 0.0f, 0.0f, 1.0f,  // top left


    };


    // convert verticies to a vector
    int sizer = sizeof(face_vertices) / sizeof(face_vertices[0]);

    std::vector<float> verticies_2(face_vertices, face_vertices + sizer);

    for (float i: verticies_2) {
        std::cout << i << " ";
    }
    return verticies_2;

};

std::vector<unsigned int> char_ui_gen::gen_UI_space_i (void) {

unsigned int face_indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3,  // second triangle

        4, 5, 7, // first triangle
        5, 6, 7,  // second triangle

        8, 9, 11, // first triangle
        9, 10, 11,  // second triangle

        12, 13, 15, // first triangle
        13, 14, 15,  // second triangle

        16, 17, 19, // first triangle
        17, 18, 19,  // second triangle

    };

    // convert indicies to a vector
    int sizer = sizeof(face_indices) / sizeof(face_indices[0]);

    std::vector<unsigned int> indicies_2(face_indices, face_indices + sizer);

    for (float i: indicies_2) {
        std::cout << i << " ";
    }
    return indicies_2;

};



// pass in 4 character sets to update verticies S and T according to Letter map
std::vector<float> char_ui_gen::Update_disp (const char* feed1, const char* feed2, const char* feed3, const char* feed4) {

letter_1 = feed1;
input_var1 = feed2;
letter_2 = feed3;
input_var2 = feed4;
std::cout << letter_1 << input_var1 << letter_2 << input_var2 << endl;
};




#endif // CHAR_H_INCLUDED
