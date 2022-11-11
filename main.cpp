// Q1 part c: what does it mean williams?

#include "imageMatrix.h"
#include <chrono>
#include <ctime>  


int main(void) {
    ImageMatrix img_mat; 
    img_mat.read("pgms/apple-18.pgm");
    img_mat.save("pgms/output.pgm");
    img_mat.connCompQ(128, 128);
    cout << "What now" << endl;
    // cout << img_mat.getAverage() << endl;
    // // img_mat.convertToNegative();
    // img_mat.blacknwhite();
    // img_mat.averageBlacks();


    // img_mat.getPixel(125, 125);
    // cout << img_mat.getPixel(125, 125) << endl;

    // img_mat.setPixel(125, 125, false);
    // cout << img_mat.getPixel(125, 125) << endl;

    // img_mat.setPixel(10000, 1000, true);
    // cout << img_mat.getPixel(1000, 1000);



    // img_mat.setPixel(125, 125, false);
    // cout << img_mat.getPixel(125, 125) << endl;

    // cout << endl;
    // cout << img_mat.getPixel(25, 25) << endl;
    // img_mat.setPixel(25, 25, true);
    // cout << img_mat.getPixel(25, 25) << endl;
    // cout << img_mat.getPixel(25, 25) << endl;


    // // img_mat.convertToNegative();

    // img_mat.blacknwhite();
    // img_mat.printzero('\x00');
    // string x = "Hello world\n";
    // cout << x;  
    // cout << img_mat.array; 
    return 0;
}