/*
    Copyright 2023 Patricia Antlitz
*/
#include "EDistance.hpp"

EDistance::EDistance(const std::string& s1, const std::string& s2) : str1(s1), str2(s2) {
    // Initialize the matrix with appropriate size
    optMatrix.resize((str1.length() + 1) * (str2.length() + 1), 0);
}

// Static method for penalty calculation
int EDistance::penalty(char a, char b) {
    return (a == b) ? 0 : 1;
}

// Static method for finding the minimum of three integers
int EDistance::min3(int a, int b, int c) {
    return std::min({a, b, c});
}

// Method to compute the optimal edit distance and return it
int EDistance::optDistance() {
    // Fill in the matrix
    fillMatrix();
    // Return the optimal distance from the top-left cell
    return optMatrix[0];
}

// Method to trace the matrix and return the alignment string
std::string EDistance::alignment() {
    std::string alignStr;
    size_t i = 0, j = 0;
    // Trace the matrix to build the alignment string
    while (i < str1.length() || j < str2.length()) {
        if (i < str1.length() && j < str2.length() && optMatrix[i * (str2.length() + 1) + j] ==
            optMatrix[(i + 1) * (str2.length() + 1) + (j + 1)] + penalty(str1[i], str2[j])) {
            alignStr += str1[i++];
            alignStr += " ";
            alignStr += str2[j++];
            alignStr += " ";
            alignStr += std::to_string(penalty(str1[i - 1], str2[j - 1]));
            alignStr += "\n";
        } else if (i < str1.length() && optMatrix[i * (str2.length() + 1) + j] ==
                    optMatrix[(i + 1) * (str2.length() + 1) + j] + 2) {
            alignStr += str1[i++];
            alignStr += " - 2\n";
        } else if (j < str2.length() && optMatrix[i * (str2.length() + 1) + j] ==
                    optMatrix[i * (str2.length() + 1) + (j + 1)] + 2) {
            alignStr += "- ";
            alignStr += str2[j++];
            alignStr += " 2\n";
        }
    }
    return alignStr;
}

// Private helper method to fill in the matrix
void EDistance::fillMatrix() {
    int m = str1.length();
    int n = str2.length();
    // Initialize base cases
    for (int i = 0; i <= m; ++i) {
        optMatrix[i * (n + 1) + n] = 2 * (m - i);
    }
    for (int j = 0; j <= n; ++j) {
        optMatrix[m * (n + 1) + j] = 2 * (n - j);
    }
    // Fill in the matrix
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int match = optMatrix[(i + 1) * (n + 1) + (j + 1)] + penalty(str1[i], str2[j]);
            int insertX = optMatrix[(i + 1) * (n + 1) + j] + 2;
            int insertY = optMatrix[i * (n + 1) + (j + 1)] + 2;
            // Choose the minimum cost
            optMatrix[i * (n + 1) + j] = min3(match, insertX, insertY);
        }
    }
}

