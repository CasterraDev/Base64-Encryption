#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "base64.h"

int main(){
	int choice;
	std::string word = "";
	std::cout << "Welcome! This program encodes and decodes words using base64 encryption." << "\n";
	do{
		std::cout << "Type 1 for encode and 2 for decode. 0 to exit" << "\n";
		std::cin >> choice;
		if (choice == 0){
			return 0;
		}else if (choice == 1){
			std::cout << "What do you want to encode?" << "\n";
			std::cin >> word;
			std::cout << base64_encode(word) << "\n";
		}else if (choice == 2){
			std::cout << "What do you want to decode?" << "\n";
			std::cin >> word;
			std::cout << base64_decode(word) << "\n";
		}
	}while(choice != 0);
		
	return 0;
}