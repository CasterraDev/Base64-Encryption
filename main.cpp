#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "base64.h"

int main(){
	std::string t = base64_encode("Hello");
	std::cout << t << "\n";
	std::cout << base64_decode(t) << "\n";
	return 0;
}