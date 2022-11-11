#include "imageMatrix.h"

int main(void) {
    ImageMatrix img_mat; 
    img_mat.read("pgms/apple-18.pgm");
    img_mat.convertToNegative();
    img_mat.save("pgms/output.pgm");

    // img_mat.getPixel(125, 125);
    // cout << img_mat.getPixel(125, 125) << endl;
    // img_mat.setPixel(125, 125, false);
    // cout << img_mat.getPixel(125, 125) << endl;

    // cout << endl;
    // cout << img_mat.getPixel(25, 25) << endl;
    // img_mat.setPixel(25, 25, true);
    // cout << img_mat.getPixel(25, 25) << endl;
    // cout << img_mat.getPixel(25, 25) << endl;


    // // img_mat.convertToNegative();
    // cout << img_mat.getAverage() << endl;

    // img_mat.blacknwhite();
    // img_mat.averageBlacks();
    // img_mat.printzero('\x00');
    // string x = "Hello world\n";
    // cout << x;  
    // cout << img_mat.array; 
    return 0;
}