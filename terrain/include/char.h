#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <array>




class char_ui_gen {

    // assume these are private
    int width, height;
    char letter_1;
    float input_var1;
    char letter_2;
    float input_var2;
  public:
    // we are outputting these
    // do not need to pass in any argument
    // for verticy return
    std::array<float,100> gen_UI_space_v (void);
    // for indicy return
    std::vector<unsigned int> gen_UI_space_i (void);

    std::array<float,100> Update_disp (char, float, char, float);

    std::array<float,100> face_vertices = {
            // positions         // texture coords
         0.0f,  0.1f, 0.0f, 0.0f, 0.25f, // top right
         0.0f,  0.0f, 0.0f, 0.0f, 0.5f, // bottom right
        0.1f,  0.0f, 0.0f, 0.1f, 0.5f, // bottom left
        0.1f,  0.1f, 0.0f, 0.1f, 0.25f,  // top left
        // positions         // texture coords
         0.1f,  0.1f, 0.0f, 0.1f, 0.0f, // top right
         0.1f, 0.0f, 0.0f, 0.1f, 0.2f, // bottom right
        0.2f, 0.0f, 0.0f, 0.2f, 0.2f, // bottom left
        0.2f,  0.1f, 0.0f, 0.2f, 0.0f,  // top left
        // positions         // texture coords
         0.2f,  0.1f, 0.0f, 0.2f, 0.0f, // top right
         0.2f, 0.0f, 0.0f, 0.2f, 0.2f, // bottom right
        0.3f, 0.0f, 0.0f, 0.3f, 0.2f, // bottom left
        0.3f,  0.1f, 0.0f, 0.3f, 0.0f,  // top left

        // positions         // texture coords
         0.3f,  0.1f, 0.0f, 0.3f, 0.0f, // top right
         0.3f, 0.0f, 0.0f, 0.3f, 0.2f, // bottom right
        0.4f, 0.0f, 0.0f, 0.4f, 0.2f, // bottom left
        0.4f,  0.1f, 0.0f, 0.4f, 0.0f,  // top left

        // positions         // texture coords
         0.4f,  0.1f, 0.0f, 0.9f, 0.5f, // top right
         0.4f, 0.0f, 0.0f, 0.9f, 0.75f, // bottom right
        0.5f, 0.0f, 0.0f, 1.0f, 0.75f, // bottom left
        0.5f,  0.1f, 0.0f, 1.0f, 0.5f,  // top left
    };
};


// this is a githum test


using namespace std;
// passes in no arguments
std::array<float,100> char_ui_gen::gen_UI_space_v (void) {





    return face_vertices;

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
       // std::cout << i << " ";
    }
    return indicies_2;

};

std::array<float, 8u> SandTpop(char x)
{

std::array<float,8> SandR_values = {
0.0f,0.0f,
0.0f,0.0f,
0.0f,0.0f,
0.0f,0.0f
};

   switch(x) {
      case 'a' :
        //cout << "got an a" << endl;
        SandR_values = {
        0.0f,0.25f,
        0.0f, 0.5f,
        0.1f, 0.5f,
        0.1f, 0.25f,
        };

        break;
      case 'b' :
        //cout << "got an b" << endl;
        SandR_values = {
         0.1f, 0.25f, // top right
        0.1f, 0.5f,
        0.2f, 0.5f,
        0.2f, 0.25f,
        };
        break;
      case 'c' :
         //cout << "got an c" << endl;
         SandR_values = {
         0.2f, 0.25f, // top right
        0.2f, 0.5f,
        0.3f, 0.5f,
        0.3f, 0.25f,
        };
         break;
      case 'd' :
         //cout << "got an d" << endl;
         SandR_values = {
         0.3f, 0.25f, // top right
        0.3f, 0.5f,
        0.4f, 0.5f,
        0.4f, 0.25f,
        };
         break;
      case 'e' :
         //cout << "got an e" << endl;
         SandR_values = {
         0.4f, 0.25f, // top right
        0.4f, 0.5f,
        0.5f, 0.5f,
        0.5f, 0.25f,
        };
         break;
        case 'f' :
         //cout << "got an f" << endl;
         SandR_values = {
         0.5f, 0.25f, // top right
        0.5f, 0.5f,
        0.6f, 0.5f,
        0.6f, 0.25f,
        };
         break;
         case 'g' :
         //cout << "got an g" << endl;
         SandR_values = {
         0.6f, 0.25f, // top right
        0.6f, 0.5f,
        0.7f, 0.5f,
        0.7f, 0.25f,
        };
         break;
         case 'h' :
         //cout << "got an h" << endl;
         SandR_values = {
         0.7f, 0.25f, // top right
        0.7f, 0.5f,
        0.8f, 0.5f,
        0.8f, 0.25f,
        };
         break;
         case 'i' :
         //cout << "got an i" << endl;
         SandR_values = {
         0.8f, 0.25f, // top right
        0.8f, 0.5f,
        0.9f, 0.5f,
        0.9f, 0.25f,
        };
         break;
         case 'j' :
         //cout << "got an j" << endl;
         SandR_values = {
         0.9f, 0.25f, // top right
        0.9f, 0.5f,
        1.0f, 0.5f,
        1.0f, 0.25f,
        };
         break;
         case 'k' :
         //cout << "got an k" << endl;
         SandR_values = {
         0.0f, 0.5f, // top right
        0.0f, 0.75f,
        0.1f, 0.75f,
        0.1f, 0.5f,
        };
         break;
         case 'l' :
         //cout << "got an l" << endl;
         SandR_values = {
        0.1f, 0.5f, // top right
        0.1f, 0.75f,
        0.2f, 0.75f,
        0.2f, 0.5f,
        };
         break;
         case 'm' :
         //cout << "got an m" << endl;
                  SandR_values = {
        0.2f, 0.5f, // top right
        0.2f, 0.75f,
        0.3f, 0.75f,
        0.3f, 0.5f,
        };
         break;
         case 'n' :
         //cout << "got an n" << endl;
                  SandR_values = {
        0.3f, 0.5f, // top right
        0.3f, 0.75f,
        0.4f, 0.75f,
        0.4f, 0.5f,
        };
         break;
         case 'o' :
         //cout << "got an o" << endl;
                  SandR_values = {
        0.4f, 0.5f, // top right
        0.4f, 0.75f,
        0.5f, 0.75f,
        0.5f, 0.5f,
        };
         break;
         case 'p' :
         //cout << "got an p" << endl;
                  SandR_values = {
        0.5f, 0.5f, // top right
        0.5f, 0.75f,
        0.6f, 0.75f,
        0.6f, 0.5f,
        };
         break;
         case 'q' :
         //cout << "got an q" << endl;
                  SandR_values = {
        0.6f, 0.5f, // top right
        0.6f, 0.75f,
        0.7f, 0.75f,
        0.7f, 0.5f,
        };
         break;
         case 'r' :
         //cout << "got an r" << endl;
                  SandR_values = {
        0.7f, 0.5f, // top right
        0.7f, 0.75f,
        0.8f, 0.75f,
        0.8f, 0.5f,
        };
         break;
         case 's' :
         //cout << "got an s" << endl;
                  SandR_values = {
        0.8f, 0.5f, // top right
        0.8f, 0.75f,
        0.9f, 0.75f,
        0.9f, 0.5f,
        };
         break;
         case 't' :
         //cout << "got an t" << endl;
                  SandR_values = {
        0.9f, 0.5f, // top right
        0.9f, 0.75f,
        1.0f, 0.75f,
        1.0f, 0.5f,
        };
         break;
         case 'u' :
         //cout << "got an u" << endl;
         SandR_values = {
        0.0f, 0.75f, // top right
        0.0f, 1.0f,
        0.1f, 1.0f,
        0.1f, 0.75f,
        };
         break;
         case 'v' :
         //cout << "got an v" << endl;
          SandR_values = {
        0.1f, 0.75f, // top right
        0.1f, 1.0f,
        0.2f, 1.0f,
        0.2f, 0.5f,
        };
         break;
         case 'w' :
         //cout << "got an w" << endl;
          SandR_values = {
        0.2f, 0.75f, // top right
        0.2f, 1.0f,
        0.3f, 1.0f,
        0.3f, 0.75f,
        };
         break;
         case 'x' :
         //cout << "got an x" << endl;
          SandR_values = {
        0.3f, 0.75f, // top right
        0.3f, 1.0f,
        0.4f, 1.0f,
        0.4f, 0.75f,
        };
         break;
         case 'y' :
         //cout << "got an y" << endl;
          SandR_values = {
        0.4f, 0.75f, // top right
        0.4f, 1.0f,
        0.5f, 1.0f,
        0.5f, 0.75f,
        };
         break;
         case 'z' :
        // cout << "got an z" << endl;
          SandR_values = {
        0.5f, 0.75f, // top right
        0.5f, 1.0f,
        0.6f, 1.0f,
        0.6f, 0.75f,
        };
         break;
         case '1' :
         //cout << "got an 1" << endl;
          SandR_values = {
        0.0f, 0.0f, // top right
        0.0f, 0.25f,
        0.1f, 0.25f,
        0.1f, 0.0f,
        };
         break;
         case '2' :
        // cout << "got an 2" << endl;
          SandR_values = {
        0.1f, 0.0f, // top right
        0.1f, 0.25f,
        0.2f, 0.25f,
        0.2f, 0.0f,
        };
         break;
         case '3' :
         //cout << "got an 3" << endl;
         SandR_values = {
        0.2f, 0.0f, // top right
        0.2f, 0.25f,
        0.3f, 0.25f,
        0.3f, 0.0f,
        };
         break;
         case '4' :
         //cout << "got an 4" << endl;
         SandR_values = {
        0.3f, 0.0f, // top right
        0.3f, 0.25f,
        0.4f, 0.25f,
        0.4f, 0.0f,
        };
         break;
         case '5' :
         //cout << "got an 5" << endl;
         SandR_values = {
        0.4f, 0.0f, // top right
        0.4f, 0.25f,
        0.5f, 0.25f,
        0.5f, 0.0f,
        };
         break;
         case '6' :
        // cout << "got an 6" << endl;
         SandR_values = {
        0.5f, 0.0f, // top right
        0.5f, 0.25f,
        0.6f, 0.25f,
        0.6f, 0.0f,
        };
         break;
         case '7' :
       //  cout << "got an 7" << endl;
         SandR_values = {
        0.6f, 0.0f, // top right
        0.6f, 0.25f,
        0.7f, 0.25f,
        0.7f, 0.0f,
        };
         break;
         case '8' :
       //  cout << "got an 8" << endl;
         SandR_values = {
        0.7f, 0.0f, // top right
        0.7f, 0.25f,
        0.8f, 0.25f,
        0.8f, 0.0f,
        };
         break;
         case '9' :
        // cout << "got an 9" << endl;
         SandR_values = {
        0.8f, 0.0f, // top right
        0.8f, 0.25f,
        0.9f, 0.25f,
        0.9f, 0.0f,
        };
         break;
         case '0' :
        // cout << "got an 0" << endl;
         SandR_values = {
        0.9f, 0.0f, // top right
        0.9f, 0.25f,
        1.0f, 0.25f,
        1.0f, 0.0f,
        };
         break;
         case '.' :
       //  cout << "got an 0" << endl;
         SandR_values = {
        0.6f, 0.75f, // top right
        0.6f, 1.0f,
        0.7f, 1.0f,
        0.7f, 0.75f,
        };
         break;
         case '?' :
        // cout << "got an 0" << endl;
         SandR_values = {
        0.7f, 0.75f, // top right
        0.7f, 1.0f,
        0.8f, 1.0f,
        0.8f, 0.75f,
        };
         break;
         case '&' :
       //  cout << "got an 0" << endl;
         SandR_values = {
        0.8f, 0.75f, // top right
        0.8f, 1.0f,
        0.9f, 1.0f,
        0.9f, 0.75f,
        };
         break;
         case '*' :
       //  cout << "got an 0" << endl;
         SandR_values = {
        0.9f, 0.75f, // top right
        0.9f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.75f,
        };
         break;
      default :
         cout << "character not found" << endl;
   }


return SandR_values;
};

// pass in 4 character sets to update verticies S and T according to Letter map
std::array<float,100> char_ui_gen::Update_disp (char feed1, float feed2, char feed3, float feed4) {

letter_1 = feed1;
input_var1 = roundf(feed2 * 100) / 100;

char array1[10];
sprintf(array1, "%f", input_var1);

letter_2 = feed3;
input_var2 = roundf(feed4 * 100) / 100;

char array2[10];
sprintf(array2, "%f", input_var2);

//std::cout << letter_1 << input_var1 << letter_2 << input_var2 << endl;
//std::cout << array1[0] << " " << array1[1] << " " << array1[2] << " " << array1[3] << " " << array1[4] << endl;


 // begin case for every character
std::array<float, 8u> first_letter = SandTpop(letter_1);

face_vertices[3] = first_letter[0];
face_vertices[4] = first_letter[1];
face_vertices[8] = first_letter[2];
face_vertices[9] = first_letter[3];
face_vertices[13] = first_letter[4];
face_vertices[14] = first_letter[5];
face_vertices[18] = first_letter[6];
face_vertices[19] = first_letter[7];

std::array<float, 8u> second_letter = SandTpop(array1[0]);
face_vertices[23] = second_letter[0];
face_vertices[24] = second_letter[1];
face_vertices[28] = second_letter[2];
face_vertices[29] = second_letter[3];
face_vertices[33] = second_letter[4];
face_vertices[34] = second_letter[5];
face_vertices[38] = second_letter[6];
face_vertices[39] = second_letter[7];

std::array<float, 8u> third_letter = SandTpop(array1[1]);
face_vertices[43] = third_letter[0];
face_vertices[44] = third_letter[1];
face_vertices[48] = third_letter[2];
face_vertices[49] = third_letter[3];
face_vertices[53] = third_letter[4];
face_vertices[54] = third_letter[5];
face_vertices[58] = third_letter[6];
face_vertices[59] = third_letter[7];

std::array<float, 8u> fourth_letter = SandTpop(array1[2]);
face_vertices[63] = fourth_letter[0];
face_vertices[64] = fourth_letter[1];
face_vertices[68] = fourth_letter[2];
face_vertices[69] = fourth_letter[3];
face_vertices[73] = fourth_letter[4];
face_vertices[74] = fourth_letter[5];
face_vertices[78] = fourth_letter[6];
face_vertices[79] = fourth_letter[7];

std::array<float, 8u> fifth_letter = SandTpop(array1[3]);
face_vertices[83] = fifth_letter[0];
face_vertices[84] = fifth_letter[1];
face_vertices[88] = fifth_letter[2];
face_vertices[89] = fifth_letter[3];
face_vertices[93] = fifth_letter[4];
face_vertices[94] = fifth_letter[5];
face_vertices[98] = fifth_letter[6];
face_vertices[99] = fifth_letter[7];

return face_vertices;
};






#endif // CHAR_H_INCLUDED
