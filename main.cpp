#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

std::vector<size_t> fileSizes = {
        static_cast<size_t>(32) * 1024 * 1024,              // 32MB
        static_cast<size_t>(64) * 1024 * 1024,              // 64MB
        static_cast<size_t>(128) * 1024 * 1024,             // 128MB
        static_cast<size_t>(256) * 1024 * 1024,             // 256MB
        static_cast<size_t>(512) * 1024 * 1024,             // 512MB
        static_cast<size_t>(1024) * 1024 * 1024,            // 1024MB
        static_cast<size_t>(2048) * 1024 * 1024,            // 2048MB
        static_cast<size_t>(4096) * 1024 * 1024,            // 4096MB
        static_cast<size_t>(8192) * 1024 * 1024,            // 8192MB
//        static_cast<size_t>(16384) * 1024 * 1024,
//        static_cast<size_t>(32768) * 1024 * 1024
}; // Sizes in bytes

void createFiles(const std::string &inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return;
    }

    std::string line;
    size_t fileIndex = 0;
    size_t currentFileSize = 0;
    size_t currentTargetSize = fileSizes[fileIndex];
    std::ofstream outFile("output_" + std::to_string(currentTargetSize / (1024 * 1024)) + "MB.json");

    while (fileIndex < fileSizes.size()) {
        while (getline(inFile, line)) {
            currentFileSize += line.size() + 1; // +1 for newline character

            if (currentFileSize > currentTargetSize) {
                outFile.close();
                fileIndex++;
                if (fileIndex >= fileSizes.size()) {
                    break;
                }
                currentTargetSize = fileSizes[fileIndex];
                outFile.open("output_" + std::to_string(currentTargetSize / (1024 * 1024)) + "MB.json");
                currentFileSize = line.size() + 1;
            }
            outFile << line << "\n";
        }

        if (inFile.eof()) {
            inFile.clear();
            inFile.seekg(0, std::ios::beg); // Restart reading the file from the beginning
        }
    }

    if (outFile.is_open()) {
        outFile.close();
    }
    inFile.close();
}

int main() {
    // nspl
//    std::string inputFile = "../nspl_small_records_remove.json"; // Replace with your actual input file name
//    createFiles(inputFile);

    // TT
//    std::string inputFile = "../twitter_small_records_remove.json"; // Replace with your actual input file name
//    createFiles(inputFile);
//
//    // BB
//    std::string inputFile = "../bestbuy_small_records_remove.json"; // Replace with your actual input file name
//    createFiles(inputFile);
//
//    // WM
//    std::string inputFile = "../walmart_small_records_remove.json"; // Replace with your actual input file name
//    createFiles(inputFile);
//
//    // WP
//    std::string inputFile = "../wiki_small_records_remove.json"; // Replace with your actual input file name
//    createFiles(inputFile);
//
//    // google
    std::string inputFile = "../google_map_small_records_remove.json"; // Replace with your actual input file name
    createFiles(inputFile);

    return 0;
}
