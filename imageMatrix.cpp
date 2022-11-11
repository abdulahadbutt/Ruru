#include "imageMatrix.h"

/*********************************************************************************************
 *  Private Functions
 ***********************************************************************************************/
char ImageMatrix::decode(char i) {
    if (i == ONE) {
        return '1';
    }
    if (i == ZERO) {
        return '0';
    }
    cout << "ENCODING ERROR: INPUT ENCODERS ARE DIFFERENT" << endl; 
    return 'E';
}

char ImageMatrix::encode(char i) {
    if (i == '1') {
        return ONE;
    }
    if (i == '0') {
        return ZERO;
    }
    cout << "DECODING ERROR: INPUT ENCODERS ARE DIFFERENT" << endl; 
    return 'E';
}


int ImageMatrix::two2oneD(int row, int col) {
    // if row > width raise error
    if (row > height) {
        cout << "Row value is out of bounds" << endl;
        return -1;
    }


    if (col > width) {
        cout << "Column value is out of bounds" << endl;
        return -1;
    }


    int i = row * width + col;
    return i; 
}

int *ImageMatrix::one2twoD(int i) {
    // cout << "INPUT: " << i << endl;
    int y = i / width;
    int x = i % width;

    // cout << i << ":" << y << " " << x << endl;
    int *coords = new int[2];
    coords[0] = y;
    coords[1] = x;
    // {y, x};
    return coords;
}


string getTime() {
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    return ctime(&end_time);
}
/*********************************************************************************************
 *  Basic Functionality
 ***********************************************************************************************/
void ImageMatrix::read(string filepath) {
    /* 
     * Data is saved in a data string and a width and height variable
     * Params:
     *  filepath: path to pgm file
     *  
     * Returns:
     *  None
     */
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

    // Decoding the string
    for (int i = 0; i < data.length(); i++) {
        data[i] = decode(data[i]);
    }

    // cout << data << endl;
}



void ImageMatrix::save(string filepath) {
    ofstream out(filepath);
    out << "P5" << '\n';
    // out << "#" << filepath << '\n';
    // out << "#" << "created PNM file" << '\n';

    out << shape << '\n';
    out << 255 << '\n';
    for (int i = 0; i < data.length(); i++) {
        out << encode(data[i]);
        // cout << encode(data[i]);
    }
    out.close();
}


int ImageMatrix::getPixel(int row, int col) {
    int i = two2oneD(row, col);
    

    if (i == -1) {
        return i;
    }

    if (data[i] == '0') {return 0;}
    else return 255;
}


void ImageMatrix::setPixel(int row, int col, bool on) {
    int i = two2oneD(row, col);
    if (i == -1) {
        return;
    }

    if (on) {
        data[i] = '1'; 
    }
    else {
        data[i] = '0'; 
    }
}


int ImageMatrix::getSize() {
    return width * height;
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


/*********************************************************************************************
 *  Q1 Solutions
 ***********************************************************************************************/
int ImageMatrix::getAverage() {
    int sum = 0; 
    for (int i = 0; i < width * height; i++) {
        if (data[i] == '1') {
            sum += 1;
        }
    }

    sum = sum * 255; 
    return sum / (width * height);
}


void ImageMatrix::blacknwhite() {
    int whites = 0, blacks = 0;

    for (int i = 0; i < width * height; i++) {
        if (data[i] == '1') {
            whites++;
        }
        else {
            blacks++;
        }
    }

    cout << "Number of white pixels: " << whites << endl;
    cout << "Number of black pixels: " << blacks << endl;
    cout << "Total Pixels: " << blacks + whites << endl;

} 

void ImageMatrix::averageBlacks() {
    int numBlacks[height] = {0};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = width * i + j;
            if (data[idx] == '0') {
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



/*********************************************************************************************
 *  Q2 Solutions
 ***********************************************************************************************/
void ImageMatrix::connCompQ(int row, int col) {
    int i = two2oneD(row, col);
    if (i == -1) return;

    cout << "[PUSHING]: " << i << endl;
    q.push(i);
    string output_s(data.length(), '1');

    // while(!q.empty()) {
    //     cout << q.front() << endl;
    //     q.pop();
    // }
    int t;
    while(!q.empty()) {
        int curr = q.front();
        cout << "CURR: (" << one2twoD(curr)[0] << " " << one2twoD(curr)[1] << ")" << endl; 
        output_s[curr] = '0';

        // cout << "[POPPING]: " << curr << endl;
        q.pop();
        cout << "DATA: " << output_s << endl; 
        
        cin >> t;
        int *n = getNeighbours(curr);
        cout << "Neighbours: ";
        for (int i = 0; i < 8; i++) {
            cout << n[i] << ' ';
        }
        cin >> t;
        for (int i = 0; i < 8; i++) {
            if (n[i] == -1) {
                continue;
            }
            if (output_s[n[i]] == '1'){
                output_s[n[i]] == '0';
                q.push(n[i]);
            }
        }

        delete[] n;
    }

}


int *ImageMatrix::getNeighbours(int i){

    // cout << "COORDS: " << endl;
    int *coords = one2twoD(i);
    int row = coords[0];
    int col = coords[1];
    

    int *neighbours = new int[8];
    for (int i = 0; i < 8; i++) {
        neighbours[i] = -1;
    }


    int idx = 0;
    for (int j = -1; j < 2; j++) {
        for (int i = -1; i < 2; i++) {
            if (i == 0 && j == 0) {
                continue;
            }


            int row_c = row + j;
            int col_c = col + i;

            // cout << "i: " << i << endl;
            // cout << "j: " << j << endl;
            // cout << "row: " << row_c << endl; 
            // cout << "col: " << col_c << endl; 
            // cout << endl;
            if (row_c > height || col_c > width || row_c < 0 || col_c < 0) {
                continue;
                idx++;
            }

            neighbours[idx] = two2oneD(row_c, col_c);
            idx++;
            // cout << row_c << " " << col_c << endl;

        }
    }
    // cout << "NEIGHBOURS" << endl;
    // for (int i = 0; i < 8; i++) {
    //     int *cs = one2twoD(neighbours[i]);
    //     cout << "index: " << neighbours[i] << endl;
    //     cout << "(" << cs[0] << ',' << cs[1] << ")" << endl << endl;
    // }
    return neighbours;
}


