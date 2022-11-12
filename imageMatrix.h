#include <iostream>
#include <string>
#include <fstream> 
#include <queue>
#include <chrono>
#include <ctime>  

#define ZERO '\x00'
#define ONE  '\x00FF'


using namespace std;

string getTime();

class ImageMatrix {
    public:
        int width, height;
        string shape; 
        string data; // '0' represents 0 and '1' represents 255
        queue <int> q; 

        // Basic functionality
        void read(string filepath);
        void save(string filepath);
        int getPixel(int row, int col);
        void setPixel(int row, int col, bool on);
        int getSize();
        void convertToNegative();


        // Q1
        int getAverage();
        void blacknwhite();
        void averageBlacks();


        // Q2
        void connCompQ(int row, int col);

    private:
        char decode(char);
        char encode(char);


        int two2oneD(int row, int col);
        void one2twoD(int i, int *coords);
        void getNeighbours(int i, int *n);
    // private:
    //     const int ZERO = '\x00';
    //     const int ONE =  '\x00FF';
};