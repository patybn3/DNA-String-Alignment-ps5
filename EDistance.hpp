/*
    Copyright 2023 Patricia Antlitz
*/
#include <iostream>
#include <vector>
#include <algorithm>

class EDistance {
 public:
    // Constructor
    EDistance(const std::string& str1, const std::string& str2);
    // Static method for penalty calculation
    static int penalty(char a, char b);
    // Static method for finding the minimum of three integers
    static int min3(int a, int b, int c);
    // Method to compute the optimal edit distance and return it
    int optDistance();
    // Method to trace the matrix and return the alignment string
    std::string alignment();

 private:
    // Private member variables
    std::string str1;
    std::string str2;
    std::vector<int> optMatrix;
    // Private helper method to fill in the matrix
    void fillMatrix();
};

