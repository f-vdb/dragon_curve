
/*
 * 0. Ordnung: e
 * 1. Ordnung: r
 *             R
 * 2. Ordnung: rRL
 *             RRL
 * 3. Ordnung: rrlRrLl
 *             RRLRRLL
 * 4. Ordnung: rrlrrllRrrlLrll
 *             RRLRRLLRRRLLRLL
 * 5. Ordnung: rrlrrllrrrllrllRrrlrrllLrrllrll
 *             RRLRRLLRRRLLRLLRRRLRRLLLRRLLRLL
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>

#include "pngwriter.h"
using namespace std;

// MAXIMUM
const uint PNG_SIZE_X{17000};
const uint PNG_SIZE_Y{25000};
const uint length = 3;
const unsigned int ITERATION = 24;

// nice start....
//const uint PNG_SIZE_X{1000};
//const uint PNG_SIZE_Y{1000};
//const uint length = 100;
//const unsigned int ITERATION = 4;

uint startX = (PNG_SIZE_X/3) * 2;
uint startY = (PNG_SIZE_Y/6) * 2;
uint endX = 0;
uint endY = 0;
std::string oldWay = "N";   




void zeichne(const char trend); 
 
void changeMiddle(string& s) {
    s.replace(s.length()/2, 1, "L");
}

int tinkerDragoncurve(unsigned int iterations, string& dragoncurve){
    if (iterations == 0)
        return 0;
    string dalt;
    for(unsigned int i = 1; i < iterations; ++i){
        dalt = dragoncurve;
        changeMiddle(dalt);
        dragoncurve += "R";
        dragoncurve += dalt;
    }
    return 23;   
}

int main() {
    std::string filename = std::to_string(ITERATION);
    std::string x = std::to_string(PNG_SIZE_X);
    std::string y = std::to_string(PNG_SIZE_Y);
    filename += "_Iterations" + x + "x" + y + "y" + ".png";
    std::cout << filename << std::endl;
    char *cstr = new char[filename.length()+1];
    strncpy(cstr, filename.c_str(), filename.length()+1);
    pngwriter png(PNG_SIZE_X, PNG_SIZE_Y,0, cstr);
    delete[] cstr;
    string dragoncurve="R";
    //const unsigned int ITERATION = 32;
    //dragoncurve.capacity(4611686018427387897);
    int error;
    auto start = chrono::high_resolution_clock::now();
    //error = tinkerDragoncurve(10, dragoncurve);
    
    error = tinkerDragoncurve(ITERATION, dragoncurve);
    
    
    //error = tinkerDragoncurve(30, dragoncurve);
    //error = tinkerDragoncurve(30, dragoncurve);
    //error = tinkerDragoncurve(30, dragoncurve);
    //error = tinkerDragoncurve(30, dragoncurve);
    auto stop = chrono::duration_cast<chrono::milliseconds>(\
        chrono::high_resolution_clock::now()-start).count();  
            
    //cout << dragoncurve << endl;
    fstream fStream;
    fStream.open(to_string(ITERATION)+".TXT", fstream::out);
    if(!fStream)
        cout << "something went wrong....\n";
    fStream << dragoncurve;
    fStream.close();
    fStream.clear();
    

    // erste Linie - senkrechte zeichnen
    png.line_blend(startX, startY, startX, startY + length, 1, 0.0, 0.0, 1.0);
    startX = startX;  
    startY = startY + length;
    for(const auto& trend : dragoncurve){
        zeichne(trend);               

        std::cout << startX << " " << startY << " " << endX << " " << endY << std::endl;
        png.line_blend(startX, startY, endX, endY, 1, 0.0, 1.0, 0.0);
        startX = endX;
        startY = endY;
    }
    png.close();

    cout << dragoncurve.length() << " the length of the string in terms of bytes" << endl;
    cout << dragoncurve.capacity() << " the size of the storage space currently allocated" << endl;
    cout << dragoncurve.max_size() << " the maximum length the string can reach\n" <<
                                      " but the value is not guaranteed to be able to reach" << endl;
    cout << "=================================================\n";
    cout << "f(tinkerDragoncurve) took " << stop << " ms " << endl;
    cout << "f(tinkerDragoncurve) took " << stop/1000.0 << " seconds " << endl;
}

 void zeichne(const char trend) {
    if(oldWay == "N" && trend == 'R'){
        endX = startX + length;
        endY = startY;
        oldWay = "O";
    }
    else if(oldWay == "N" && trend == 'L'){
        endX = startX - length;
        endY = startY;
        oldWay = "W";
    }
    else if(oldWay == "O" && trend == 'R'){
       endX = startX;
       endY = startY - length;
       oldWay = "S";
    }
    else if(oldWay == "O" && trend == 'L'){
       endX = startX;
       endY = startY + length;
       oldWay = "N";
    } 
    else if(oldWay == "S" && trend == 'R'){
       endX = startX - length;
       endY = startY;
       oldWay = "W";
    }
    else if(oldWay == "S" && trend == 'L'){
       endX = startX + length;
       endY = startY;
       oldWay = "O";
    }
    else if(oldWay == "W" && trend == 'R'){
       endX = startX;
       endY = startY + length;
       oldWay = "N";
    }
    else if (oldWay == "W" && trend == 'L'){
       endX = startX;
       endY = startY - length;
       oldWay = "S";
    } 
    else
        std::cout << "fehler....\n";


}
 
