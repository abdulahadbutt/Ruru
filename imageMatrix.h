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
        string data; // '0' represents 0 and '1' represents 255

        void read(string filepath);
        void save(string filepath);
        int getPixel(int row, int col);
        void setPixel(int row, int col, bool on);
        int getSize();
        void convertToNegative();



        int getAverage();
        void blacknwhite();
        void averageBlacks();

    private:
        char decode(char);
        char encode(char);


        int two2oneD(int row, int col);
        // int *one2twoD(int i);
    // private:
    //     const int ZERO = '\x00';
    //     const int ONE =  '\x00FF';
};