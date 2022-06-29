//
// Created by Iluha on 29.06.2022.
//

#ifndef MISHINU_MATRIX_H
#define MISHINU_MATRIX_H

#include <iostream>
#include <fstream>

class matrix {
    int** graph;
    int countTops;
    int countRibs;
public:
    matrix() {
        this->graph = nullptr;
        this->countRibs = 0;
        this->countTops = 0;
    }
    ~matrix() {
        for (int i = 0; i < this->countTops; i++)
            delete[] this->graph[i];

        delete[] this->graph;
    }

    void read(std::ifstream &fin) {
        if (!fin) {
            std::cout << "Failed!\n";
        } else {
            fin >> this->countTops >> this->countRibs;

            this->graph = new int*[this->countTops];

            for (int i = 0; i < this->countTops; i++) {
                this->graph[i] = new int[this->countRibs];

                for (int j = 0; j < this->countRibs; j++)
                    fin >> this->graph[i][j];
            }
        }
    };
    int** translate(int &n) {
        n = this->countTops;
        int** newGraph = new int*[n];

        for (int i = 0; i < n; i++)
            newGraph[i] = new int[n]{};

        for (int i = 0; i < this->countRibs; i++) {
            bool check = false;
            int first, second;

            for (int j = 0; j < this->countTops; j++)
                if (this->graph[j][i] == 1) {
                    if (check == false) {
                        first = j;
                        check = true;
                    } else
                        second = j;
                }

            newGraph[first][second] = 1;
            newGraph[second][first] = 1;
        }

        return newGraph;
    }

    void print() {
        for (int i = 0; i < this->countTops; i++) {
            for (int j = 0; j < this->countRibs; j++)
                std::cout << this->graph[i][j] << " ";

            std::cout << std::endl;
        }
    }
};


#endif //MISHINU_MATRIX_H
