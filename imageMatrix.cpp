#include "imageMatrix.h"


void ImageMatrix::averageBlacks() {
    int numBlacks[height] = {0};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = width * i + j;
            if (data[idx] == ZERO) {
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
        if (data[i] == ONE) {
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
        switch (data[i])
        {
            case '0': data[i] = '1'; break;
            case '1': data[i] = '0'; break;
        }
    }
}


int ImageMatrix::getSize() {
    return width * height;
}

void ImageMatrix::setPixel(int row, int col, bool on) {
    if (row > height) {
        cout << "Row value is out of bounds" << endl;
        return; 
    }


    if (col > width) {
        cout << "Column value is out of bounds" << endl;
        return;
    }

    int i = row + width * col;
    // if i > index length raise error 
    if (on) {
        data[i] = '1'; 
    }
    else {
        data[i] = '0'; 
    }
}

int ImageMatrix::getPixel(int row, int col) {
    // if row > width raise error
    if (row > height) {
        cout << "Row value is out of bounds" << endl;
        return -1;
    }


    if (col > width) {
        cout << "Column value is out of bounds" << endl;
        return -1;
    }


    int i = row + width * col;
    // if i > index length raise error 

    // cout << "DATA INSIDE" << endl;
    // cout << data[i] << endl; 
    
    // cout << data << endl;
    
    if (data[i] == '0') {return 0;}
    else return 1;

}

void ImageMatrix::save(string filepath) {
    ofstream out(filepath);
    out << "P5" << '\n';
    out << "#" << filepath << '\n';
    out << "#" << "created PNM file" << '\n';

    out << shape << '\n';
    out << 255 << '\n';
    out << data;
    out.close();
}



void ImageMatrix::read(string filepath) {
    ifstream file(filepath);
    if (file.is_open()) {
        string tp; 
        for (int i = 0; getline(file, tp); ) {
            if (tp[0] == '#') continue;
            // cout << i << " " << tp << endl;
            switch (i)
            {
                case 1: shape = tp;  break;
                case 3: data = tp;  break;         
                default: break;
            }
            i++;
        }
    }

    string w = shape.substr(0, shape.find(" "));
    string h = shape.substr(shape.find(" ") + 1, shape.find('\0'));

    width =  stoi(w);
    height = stoi(h);

    // Encoding the string
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == ZERO) {
            data[i] = '0';
        }
        else {
            data[i] = '1';
        }
    }

    // cout << data << endl;
    // printImage();
}


void ImageMatrix::printImage() {
    for (int i = 0; i < data.length(); i++) {
        if ((i + 1) % width == 0) {
            cout << i;
            cout << endl;
        }  
        
        // cout << data[i];
    }
}

int ImageMatrix::getAverage() {
    int sum = 0; 
    for (int i = 0; i < width * height; i++) {
        if (data[i] == ONE) {
            sum += 1;
        }
    }

    sum = sum * 255; 
    return sum / (width * height);
}
