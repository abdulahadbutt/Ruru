#include <iostream>
#include <string>
#include <fstream> 

#define ZERO '\x00'
#define ONE  '\x00FF'


using namespace std;


class ImageMatrix {
    public:
        int width, height;
        string shape; 
        string array;

        void read(string filepath);
        void save(string filepath);
        int getPixel(int row, int col);
        void setPixel(int row, int col, bool on);
        int getSize();
        void convertToNegative();



        int getAverage();
        void blacknwhite();
        void averageBlacks();
    // private:
    //     const int ZERO = '\x00';
    //     const int ONE =  '\x00FF';
};