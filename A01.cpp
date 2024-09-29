// Name: Emanuel Cruz
// SSID: 8164200
// Assignment #: 1
// Submission Date: 9/29/2024
//
// Description: A program to encrypt and decrypt a message using a shift cipher
// The plaintext message must only contain lowercase alpha and digits 0-9
//
// command line arguments
// -p theplaintextmessage1 - the plaintext (p) message to be encrypted
// -c PDALH7EJPATPIAOO7CA@ - the cipher (c) text to be decrypted
// -k 9                    - the key (k) shift value
// -e                      - the option to encrypt (e)
// -d                      - the option to decrypt (d)
//

#include <iostream> //std::cout, std::cin, etc.
#include <cstdlib>  //C++ version of stdlib.h
#include <cstring>  //C++ version of string.h
#include <string>   //C++ string library
#define CBL 64
//todo: add other includes you may need
//Command line args reference:
//https://docs.microsoft.com/en-us/cpp/cpp/main-function-command-line-args

char codebook[] = {
    'z', 'Z', 'y', 'Y', 'x', 'X', 'w', 'W', 'v', 'V', 'u', 'U', 't', 'T', 's', 'S',
    'r', 'R', 'q', 'Q', 'p', 'P', 'o', 'O', 'n', 'N', 'm', 'M', 'l', 'L', 'k', 'K',
    'j', 'J', 'i', 'I', 'h', 'H', 'g', 'G', 'f', 'F', 'e', 'E', 'd', 'D', 'c', 'C',
    'b', 'B', 'a', 'A', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '@', ']'
};

//itterates through the codebook and each char until the input letter matches the array then returns the match.
int charindex(char letter){
	for(int i=0; i < CBL; i++){
		//Returns matching letter char from codebook array
		if (codebook[i] == letter){ 
	        return i;
		  }
	}
	return 0;
}

//Function to match index num to corresponding codebook array num
int indexmatch(int index){
	return codebook[index];
}


int main(int argc, char* argv[]){
	// Insufficient arguments, exit program
	if (argc < 6) {
		std::cerr << "Error: Insufficient arguments.\n";
		return -1;
	}

	// Example variable declaration
	std::string msg;      // string to store argv[msg_index]
	int key = 0; 	      // shift amount
	bool encrypt = false; // perform encryption set to true
	bool decrypt = false; // perform decryption set to true

	// Example command line argument processing using a loop
	for (int i = 1; i < argc; i++) {
		// use strcmp to compare command line switches to argv[i]
		if (std::strcmp(argv[i], "-p") == 0)
			msg = argv[++i]; //store the plaintext in string msg

		if (std::strcmp(argv[i], "-c") == 0)
			msg = argv[++i];

		if (std::strcmp(argv[i], "-k") == 0)
			key = std::atoi(argv[i + 1]); //stores the char number as an int number

		if (std::strcmp(argv[i], "-e") == 0)
			encrypt = true; //shifts bool value from initial false to true 

		if (std::strcmp(argv[i], "-d") == 0)
			decrypt = true; //shifts bool value from initial false to true
	}
	// A1 todo: -e encrypt the plaintext with key value k
	if (encrypt) {
	//So here we are parsing each letter from string message into char 
	//letter so it can pass through function charindex.
        for (char letter : msg) {
			//Stores the index of each character, from codebook array. 
            int index = charindex(letter);
			//Encryption formula
		    int shiftedindex = (index + key) % CBL;
			//passed int through indmatch function to return characters.
			char finalmessage = indexmatch(shiftedindex);
		    std::cout << finalmessage;
        }  
									std::cout <<"\n";
	}

	// A1 todo: -d decrypt the ciphertext -c with key value k
	if (decrypt) {
		for (char letter : msg) {
            int index = charindex(letter);
			int shiftedindex;
			
			if ((index-key)>=0){
			    int shiftedindex = (index-key) % CBL;
				char finalmessage = indexmatch(shiftedindex);
							std::cout << finalmessage;


			} else{
				int shiftedindex = ((index-key)%CBL) + CBL; 
				char finalmessage = indexmatch(shiftedindex);
							std::cout << finalmessage;

	        }

	    }
									std::cout <<"\n";

	}
	// print out the ciphertext or plaintext using standard-out
	return 0;
}//main