#ifndef XOR_CRYPT_H
#define XOR_CRYPT_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class FileNotFoundException : public std::runtime_error {
public:
    FileNotFoundException(std::string filePath) :
        runtime_error("File does not exist:" + filePath) {
    }
};

static std::string XORCrypt(std::string key, std::string data) {
    for (size_t i = 0; i != data.size(); i++) {
        data[i] ^= key[i % key.size()];
    }
    return data;
}

static void XORCryptFile(
        std::string filePath,
        std::string key,
        std::string newPath = "")
    {

    // Read the file
    std::ifstream inFile(filePath, std::ios_base::binary);

    // Check that the file was found and opened successfully
    if (inFile.is_open()) {
        // Read the original file
        std::string original((std::istreambuf_iterator<char>(inFile)),
			     std::istreambuf_iterator<char>());

        // Build the crypted version
        std::string crypted(XORCrypt(key, original));

	// Was a new file path given?
        if (newPath != "") {
            filePath = newPath;
        }

	// Load the output file and clear it
        std::ofstream outFile(filePath, std::ios::out | std::ios::trunc);

	// Write the crypted version to the file
        outFile << crypted;

	// Close the file
	outFile.close();
    } else {
        throw FileNotFoundException(filePath);
    }
}

#endif
