#ifndef TER_H_INCLUDED
#define TER_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>


#include "bmp.h"

class Terrain_gen {
    int width, height;
    const char * texture;
    const char * height_map;
  public:
    std::vector<unsigned int> indicies_gen (int,int);
    std::vector<float> verticies_gen (int,int,const char*);
    int area() {return width*height;}


};
using namespace std;
std::vector<unsigned int> Terrain_gen::indicies_gen (int x, int y) {
  width = x;
  height = y;

    const int total_indicies = (((width-1) * (height-1) *6)+(height-1)*3);  // this represents how many indicies and degenerates
    unsigned int i = 0;
    unsigned int indicies[total_indicies];

    int chunk = 0;
    unsigned int n = 0;
    unsigned int Degen_counter = 0;
    while (i < total_indicies)
    {

        indicies[i] = n;
      //  cout << indicies[i] << " " ;
        i++;
        indicies[i] = width + chunk ;
     //   cout << indicies[i] << " ";
        i++;
        indicies[i] = n+1;
     //   cout << indicies[i] << endl; ;
        i++;
        indicies[i] = n+1;
     //   cout << indicies[i] << " ";
        i++;
        indicies[i] = width + chunk +1 ;
      //  cout << indicies[i] << " ";
        i++;
        indicies[i] = width + chunk;
     //   cout << indicies[i] << endl;
        i++;

        chunk++;
        n++;

       // int remainder = (chunk - Degen_counter) % (width-1);
       // cout << "chunk " << (chunk - Degen_counter)<< " (width -1) " << width -1 <<" remainder "<< remainder << endl;
        if ( chunk != 0 && (chunk - Degen_counter) % (width-1) == 0) // check if you reached the last chunk
        {
            // make degenerate
          //  cout << width << " " << chunk << " " << Degen_counter<< endl;
             indicies[i] = width + chunk ;
           //  cout << indicies[i] << " ";
            i++;
             indicies[i] = n+1;
          //   cout << indicies[i] << " ";
            i++;
             indicies[i] = n+1;
          //   cout << indicies[i] << endl ;
            i++;
           // cout << "next row " << endl ;
           chunk++;
           n++;
           Degen_counter++;
        }


    }


// convert indicies to a vector
// input array put on hold


    int sizer = sizeof(indicies) / sizeof(indicies[0]);

    std::vector<unsigned int> indicies_2(indicies, indicies + sizer);

    for (int i: indicies_2) {
   //     std::cout << i << " ";
    }


    return indicies_2;



}

std::vector<float> Terrain_gen::verticies_gen (int x, int y, const char* filename_2) {

         width = x;
          height = y;

          height_map = filename_2;
        //  cout << "we have the files " << filename_2 << endl;
            // fetch the bitmap for the z height
            BitMap example_bmp(filename_2);
           // cout << "color is " <<  example_vector[0] << endl;
            float one = 1;
            float tex_position_s = one/width;
            //cout << "tex_pos_s" << tex_position_s << endl;
            float tex_position_t = one/height;
           // cout << "tex_pos_t" << tex_position_t << endl;

            int total_vertiecies = width*height*5;
            float verticies[total_vertiecies];
            int current_row = 0;
            int current_column = 0;
            unsigned int i = 0;

            float start_s = 0;
            float start_t = 0;

        while (current_row < height)
        {
            while (current_column < (width))
            {
                verticies[i] = current_column;
              //  cout << verticies[i]<< " " ;
                i++;

                verticies[i] = current_row;
               // cout << verticies[i]<< " " ;
                i++;

                std::vector<unsigned int> z_height = example_bmp.getPixel(current_column,current_row);
                float normal_height = (1.0f/255.0f)*6.0f;
                float z_height_normal = z_height[1]*normal_height;
               // cout << "z_heigh * normal_heigt" << normal_height<< endl;
                verticies[i] = z_height_normal;
              //  cout << verticies[i]<< " " ;

                i++;

                verticies[i] = start_s;
             //   cout << verticies[i]<< " " ;

                i++;

                 verticies[i] = start_t;
               //  cout << verticies[i]<< " " << endl ;

                i++;

                start_s = start_s + tex_position_s;



                current_column ++;
            }
            current_column = 0;
            start_s = 0;
            current_row ++;
            start_t = start_t + tex_position_t;

        }

        // convert verticies to a vector
// input array put on hold


    int sizer = sizeof(verticies) / sizeof(verticies[0]);

    std::vector<float> verticies_2(verticies, verticies + sizer);

    for (float i: verticies_2) {
   //     std::cout << i << " ";
    }


    return verticies_2;




}
#endif // TER_H_INCLUDED
