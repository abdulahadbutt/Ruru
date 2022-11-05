#include "imageMatrix.h"


void ImageMatrix::averageBlacks() {
    int numBlacks[height] = {0};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = width * i + j;
            if (array[idx] == ZERO) {
                numBlacks[i]++;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < height; i++) {
        // sum += numBlacks[i]
        cout << i << ":" << numBlacks[i] / (float) width << endl; 
    }
}

void ImageMatrix::blacknwhite() {
    int whites = 0, blacks = 0;

    for (int i = 0; i < width * height; i++) {
        if (array[i] == ONE) {
            whites++;
        }
        else {
            blacks++;
        }
    }

    cout << "Number of white pixels: " << whites << endl;
    cout << "Number of black pixels: " << blacks << endl;
    // cout << "Total Pixels: " << blacks + whites << endl;

} 

void ImageMatrix::convertToNegative() {
    for (int i = 0; i < width * height; i++) {
        switch (array[i])
        {
        case '\x00':      array[i] = '\x00FF';  break;
        case '\x00FF':    array[i] = '\x00';    break;
        }
    }
}


int ImageMatrix::getSize() {
    return width * height;
}

void ImageMatrix::setPixel(int row, int col, bool on) {
    // if row > width raise error

    int i = row + width * col;
    // if i > index length raise error 
    if (on) {
        array[i] = ONE; 
    }
    else {
        array[i] = ZERO; 
    }
}

int ImageMatrix::getPixel(int row, int col) {
    // if row > width raise error

    int i = row + width * col;
    // if i > index length raise error 

    if (array[i] == ONE) {
        return 1;
    }
    else {
        return 0;
    }
}

void ImageMatrix::save(string filepath) {
    ofstream out(filepath);
    out << "P5" << '\n';
    out << "#" << filepath << '\n';
    out << "#" << "created PNM file" << '\n';

    out << shape << '\n';
    out << 255 << '\n';
    out << array;
    out.close();
}

void ImageMatrix::read(string filepath) {
    ifstream file(filepath);
    if (file.is_open()) {
        string tp; 
        for (int i = 0; getline(file, tp); i++) {
            // cout << tp << endl;
            // cout << "NEXTLINE" << endl; 
            switch (i)
            {
                case 3: shape = tp;  break;
                case 5: array = tp;  break;         
                default: break;
            }
        // cout << "Total Lines: " << i << endl; 
        }

    }

    string w = shape.substr(0, shape.find(" "));
    string h = shape.substr(shape.find(" ") + 1, shape.find('\0'));

    width =  stoi(w);
    height = stoi(h);

    // Encoding the string
    for (int i = 0; i < array.length(); i++) {
        if (array[i] == ZERO) {
            array[i] = '0';
        }
        else {
            array[i] = '1';
        }
    }

    cout << array << endl;
}

int ImageMatrix::getAverage() {
    int sum = 0; 
    for (int i = 0; i < width * height; i++) {
        if (array[i] == ONE) {
            sum += 1;
        }
    }

    sum = sum * 255; 
    return sum / (width * height);
}
