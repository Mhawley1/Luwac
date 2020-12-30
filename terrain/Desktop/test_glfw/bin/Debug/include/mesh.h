#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <array>



using namespace std;

class Weasel_turf
{
private:
    char * m_copyname;
    const char * m_filename;

public:
    // define incoming parameters for size
    std::vector<unsigned int> def_indicies(int row,int column);

    // define incoming texture for ground
    Weasel_turf(const char * filename);
        ~Weasel_turf();
    // define incoming texture for z height



};


Weasel_turf::Weasel_turf( const char * filename)
{

    using namespace std;

    m_filename = filename;

    ifstream inf(filename);
    if(!inf) {
        cerr<<"Unable to open file: "<<filename<<"\n";
    }
}


std::vector<unsigned int> Weasel_turf::def_indicies(int x, int y)
    {


        std::vector<unsigned int> indicies = {1,2,3};
        std::vector<float> verticies = {1.0,2.5,3.4};


        //return indicies; may have to do this in another ... thing .
        return indicies;
    }



#endif


