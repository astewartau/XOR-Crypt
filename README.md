# XOR-Crypt
Command-line tool and C++ Headers to encrypt and decrypt files using XOR encryption.

## Instructions
- Compile main.cpp to build the command-line tool
- Include xor.hpp for use of the XORCryptFile function

## Command-line usage
`xor original_file_path key [new_file_path]`

- **original_file_path**: The file to encrypt/decrypt
- **key**: The key to use to encrypt/decrypt the file
- **new_file_path** (optional): The path to which the encrypted/decrypted contents should be written to (defaults to the original_file_path)
