#include "imageMatrix.h"

int main(void) {
    ImageMatrix img_mat; 
    img_mat.read("pgms/apple-18.pgm");
    // img_mat.save("pgms/output.pgm");

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