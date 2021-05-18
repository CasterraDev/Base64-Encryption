#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

//Char Set for Base64
std::string char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
std::string paddingCode = "00";

std::vector<std::string> split(std::string str, int delimiter){
	std::vector<std::string> res;
	int numOfSubStrings = str.length()/delimiter;

	for(auto i = 0;i<numOfSubStrings;i++){
		res.push_back(str.substr(i*delimiter,delimiter));
	}

	//If there are leftover characters at the end, put them in a shorter element at the end
	if (str.length() % delimiter != 0){
		res.push_back(str.substr(delimiter*numOfSubStrings));
	}

	return res;
}

int binToDec(int n){
	int decVal = 0;
	int base = 1;
	int temp = n;
	while(temp){
		int last_digit = temp % 10;
		temp /= 10;

		decVal += last_digit * base;
		base *= 2;
	}
	return decVal;
}

static std::string base64_encode(const std::string &in){
	std::string out;
	
	int padding = 0;
	int len = in.length();

	std::string bs = "";

	//Go through every char and turn into 8 bit binary
	//And lump it together into one string
	for(int i = 0;i<len;i++){
		bs += bitset<8>(in[i]).to_string();
	}
	//Add padding to the end
	padding = bs.length() % 3;
	for(int i = 0;i<padding;i++){
		bs += paddingCode;
	}

	//Make a vector filled with the binaryString spilt every 6th character
	std::vector<std::string> vec = split(bs,6);
	std::string ts = "";

	for(std::vector<std::string>::iterator i = vec.begin();i < vec.end();i++){
		std::string t = *i;
		int c = binToDec(stoi(t));
		ts += char_set[c];
	}
	return(ts);
}

static std::string base64_decode(const std::string &out){
	std::string str = "";
	std::string ans = "";
	for (int i = 0;i<out.size();i++){
		int t = char_set.find(out[i]);
		str += bitset<6>(t).to_string();
	}

	std::vector<std::string> vec = split(str,8);
	for(std::vector<std::string>::iterator j = vec.begin();j < vec.end();j++){
		std::string t = *j;
		int asciiVal = binToDec(stoi(t));
		char c = asciiVal;
		ans += c;
	}
	return ans;
}
