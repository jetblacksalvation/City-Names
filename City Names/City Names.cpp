// City Names.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Header.h"
std::vector<std::string> words;
std::vector<int> numbers;

std::ifstream tfile;
std::ofstream cfile;
std::string cityName;
double cityTF;
double cityTC;

int main()
{   
    

    parse_words(words, "Text.txt");
    std::cout << "Hello World!\n";
    while (tfile >> cityName >> cityTF) {
        cityTC = (cityTF - 32.0) * (5.0 / 9.0);
        cfile << cityName << " " << cityTC <<std:: endl;
        cfile.flush();
    }
    for (auto iter : words) {
        std::cout << iter << std::endl;
    }
    for (int x = 0; x < words.size(); x++) {
        if (x % 2 == 1) {//if odd pushes the integer version of number
            std::stringstream pushthis(words[x]);
            numbers.push_back(NULL);
            pushthis >> numbers[x];
        }
    }

}
/*
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ifstream tfile;
    ofstream cfile;
    string cityName;
    double cityTF;
    double cityTC;

    tfile.open("FarenheitTemperature.txt");

    if (!tfile.is_open()) {
        cout << "Could not open file." << endl;
        return 1;
    }

    cfile.open("CelsiusTemperature.txt", 'w');

    getline(tfile, cityName);

    while (!tfile.fail()) {
        tfile >> cityTF;

        while (tfile >> cityName >> cityTF) {
            cityTC = (cityTF - 32.0) * (5.0 / 9.0);
            cfile << cityName << " " << cityTC << endl;
            cfile.flush();
        }
    }

    tfile.close();
    cfile.close();

    return 0;
}

*/