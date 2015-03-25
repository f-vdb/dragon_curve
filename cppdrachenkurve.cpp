

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

using namespace std;

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
    string dragoncurve="R";
    const unsigned int ITERATION = 30;
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
    
    cout << dragoncurve.length() << " the length of the string in terms of bytes" << endl;
    cout << dragoncurve.capacity() << " the size of the storage space currently allocated" << endl;
    cout << dragoncurve.max_size() << " the maximum length the string can reach\n" <<
                                      " but the value is not guaranteed to be able to reach" << endl;
    cout << "=================================================\n";
    cout << "f(tinkerDragoncurve) took " << stop << " ms " << endl;
    cout << "f(tinkerDragoncurve) took " << stop/1000.0 << " seconds " << endl;
}


