#pragma once
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

static void XORCryptFile(std::string filePath, std::string key, bool lineEndings, std::string newPath = "") {

	// Read the file
	std::ifstream inFile(filePath, std::ios_base::binary);

	// Check that the file was found and opened successfully
	if (inFile.is_open()) {
		// Read the original file
		std::string original((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

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

int main(int argc, char** argv) {
	std::string filePath;
	std::string key;
	std::string newFilePath = filePath;

	if (argc == 3) {
		filePath = argv[1];
		key = argv[2];
	} else if (argc == 4) {
		filePath = argv[1];
		key = argv[2];
		newFilePath = argv[3];
	} else {
		printf("\nIncorrect usage!\nUse xor original_file_path key [new_file_path]\n\toriginal_file_path: The file path of the file to encrypt\decrypt\n\tkey: The key to use to encrypt the file\n\t[new_file_path] (optional): A new file to write the encrypted/decrypted contents to.\n");
		return 1;
	}

	try {
		XORCryptFile(filePath, key, true, newFilePath);
	} catch (FileNotFoundException e) {
		printf(e.what());
	}

	return 0;
}