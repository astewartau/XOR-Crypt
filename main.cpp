#include "xor.hpp"

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

        printf("\nIncorrect usage!\nUse xor original_file_path key
[new_file_path]\n\toriginal_file_path: The file path of the file to
encrypt\\decrypt\n\tkey: The key to use to encrypt the
file\n\t[new_file_path] (optional): A new file to write the
encrypted/decrypted contents to.\n");
	
        return 1;
    }


    try {
        XORCryptFile(filePath, key, newFilePath);
    } catch (FileNotFoundException e) {
        printf(e.what());
    }
    
    return 0;
}
