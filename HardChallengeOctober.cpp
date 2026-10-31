// Middle cpp Projects.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// HardChallengeOctober

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string> 
#include <vector>

double cubeDiagonal(double volume) {
	double diagonal = pow(volume, 1.0 / 3.0) * sqrt(3);
	return std::round(diagonal * 100.0) / 100.0;
}

std::string tweakLetters(std::string s, std::vector<int> arr) {
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int lenchar = alphabet.length();
	std::string result = "";
	for (int index = 0; index < s.length(); index++) {
		int charindex = alphabet.find(s[index]) + arr[index];
		result = result + alphabet[(charindex % lenchar + lenchar) % lenchar]; // This line ensures that the index wraps around correctly for negative values
	}
	return result;
}

using namespace std;
bool circularShift(vector<int> arr1, vector<int> arr2, int n) {
	//	bool allShifted = std::all_of(arr1.begin(), arr1.end()-1, [&](int x) {
	//		return arr1[(x+n) % arr1.size()] == arr2[x];
	//		});
	bool allshifted = true;
	for (int index = 0; index < arr1.size(); index++) {
		if (arr1[(index + n) % arr1.size()] != arr2[index]) {
			allshifted = false;
			break;
		}
	}
	return allshifted;
}


vector<int> quicksort(std::vector<int> arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	int pivot = arr[arr.size() / 2];
	std::vector<int> smallerelements = {}, equalelements = {}, greaterelements = {};
	for (int index = 0; index < arr.size(); index++) {
		if (arr[index] < pivot) {
			smallerelements.push_back(arr[index]);
		}
		else if (arr[index] == pivot) {
			equalelements.push_back(arr[index]);
		}
		else {
			greaterelements.push_back(arr[index]);
		}
	}
	smallerelements = quicksort(smallerelements);
	greaterelements = quicksort(greaterelements);
	std::vector<int> result;
	result.insert(result.end(), smallerelements.begin(), smallerelements.end());
	result.insert(result.end(), equalelements.begin(), equalelements.end());
	result.insert(result.end(), greaterelements.begin(), greaterelements.end());
	return result;
}

bool cons(std::vector<int> arr) {
	std::vector<int> sortArr = quicksort(arr);
	for (int index = 0; index < sortArr.size() - 1; index++) {
		if (sortArr[index] + 1 != sortArr[index + 1]) {
			return false;
		}
	}
	return true;
}


bool isDisarium(int number) {
	std::string charNum = std::to_string(number);
	int sum{ 0 };
	for (int index = 0; index < charNum.length(); index++) {
		int num = charNum[index] - '0';
		sum += pow(num, index + 1);
	}
	if (sum == number) { return true; }
	return false;
}

int findOdd(vector<int> arr) {
	for (int num : arr) {
		int total_occurrences = std::count(arr.begin(), arr.end(), num);
		if (total_occurrences % 2 == 1) {
			return num;
		}
	}
}

std::vector<std::string> makeBox(int n) {
	std::vector<std::string> output = {};
	for (int i = 0; i < n; i++) {
		std::string row = "";
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n-1) { 
				row += "#"; 
			}
			else {
				row += " ";
			}

		}
		output.push_back(row);
	}
	return output;
}


bool firstBeforeSecond(std::string str, std::string first, std::string second) {
	std::vector<int> arrFirst = {}, arrSecond = {};
	for (int index = 0; index < str.size(); index++) {
		if (str[index] == first[0]) {
			arrFirst.push_back(index);
		}
		else if (str[index] == second[0]) {
			arrSecond.push_back(index);
		}
	}
	for (int index2 : arrSecond) {
		for (int index1 : arrFirst) {
			if (index1 > index2) {
				return false;
			}
		}
	}
	return true;
}

bool firstBeforeSecond2(std::string str, char first, char second) {
	return str.substr(str.find(second), str.size()).find(first) == std::string::npos;
}


std::string mysteryFunc(std::string s) {
	std::string output = "";
	for (int index = 0; index < s.size(); index += 2) {
		std::string result( s[index+1] - '0', s[index]);
		output += result;
	}
	return output;
}

#include <map>
std::map<std::string, std::string> parseCode(const std::string& code) { 
	std::map<std::string, std::string> output = {};
	std::string firstName = code.substr( 0, code.find('0')), lastName = "",
		id = code.substr(code.rfind('0') + 1, code.size() - code.find("0"));

	for (int index = code.find('0') ; index < code.rfind('0'); index++) {
		if (code[index] != '0') {
			lastName += code[index];
		}
	}
	output.insert({
		{ "firstName", firstName },
		{ "lastName",lastName },
		{ "id",id }
		});
	return output; 
}


bool canBuild(std::string str1, std::string str2) {
	for (char c : str2) {
		if (str1.find(c) == std::string::npos) {
			return false;
		}
	}
	return true;
}
#include <string>
bool overTwentyOne(std::vector<char> cards) {
	int sum = 0;
	for (char card : cards) {
		if (card >= '0' && card <= '9') { sum += card - '0'; }
		else if (card == 'A') { sum += 1; }
		else sum += 10;
	}
	return sum >= 21;
}
bool overTwentyOne2(std::vector<char> cards) {
	int v = 0;
	for (char c : cards)
		v += (isdigit(c) ? (c - '0') : 0) + (c == 'J' || c == 'K' || c == 'Q') * 10 + (c == 'A');
	return v > 21;
}

struct Grocery {
	std::string product;
	int quantity;
	double price;
};

double getTotalPrice(const std::vector<Grocery>& groceries) {
	double sum = 0.0;
	for (const auto& Grocery : groceries) {	sum += (Grocery.price) * (Grocery.quantity);}
	return sum;
}

bool isprime(int num) {
	if (num == 1) { return false; }
	for (int i = 2;i < static_cast<int>(std::sqrt(num) + 1); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
int sumPrimes(std::vector<int> arr) {
	int sum = 0;
	for (int num : arr) {
		if (isprime(num)) { sum += num; }
	}
	return sum;
}


bool booleanAnd(const std::vector<bool>& values) {
	bool flag = true;
	for (bool value : values) {flag = flag and value;}
	return flag;
}
bool booleanOr(const std::vector<bool>& values) { 
	bool flag = true;
	for (bool value : values) { flag = flag or value; }
	return flag;
}
bool booleanXor(const std::vector<bool>& values) { 
	bool flag = values[0];
	std::vector<bool> subvector(values.begin() + 1, values.end());
	for (bool value : subvector) { flag = flag == value; }
	return not flag; 
}

int countSmileys(std::vector<std::string> arr) {
	const std::vector<char> eyes = { ':',';' }, nose = { '-','~' }, mouth = { ')','D' };
	int count = 0;
	for (const auto& face : arr) {
		if ((face.size() == 2 || face.size() == 3) &&
			std::find(eyes.begin(), eyes.end(), face[0]) != eyes.end() &&
			std::find(mouth.begin(), mouth.end(), face.back()) != mouth.end() &&
			(face.size() == 2 ||
				std::find(nose.begin(), nose.end(), face[1]) != nose.end())) {
			++count;
		}
	}
	return count;
}

std::string invert2(const std::string& text) {
	std::string output = "";
	for (int index = 1;index <= text.size(); index++) {
		char co{};
		if (std::islower(text[text.size() - index])) {
			co = std::toupper(text[text.size() - index]);
		}
		else {
			co = std::tolower(text[text.size() - index]);
		}
		output +=co;
	}
	return output;
}

std::string invert(const std::string& str)
{
	std::string result(str);
	std::reverse(std::begin(result), std::end(result));
	for (char& c : result) {
		c = isupper(c) ? tolower(c) : toupper(c);
	}
	return result;
}

std::vector<std::string> constructDeconstruct(std::string str) {
	std::vector<string> output = {};
	for (int index = 1; index < 2*(str.size()); index++) {
		int i = (index < str.size()) ? index : 2 * (str.size()) - index;
		output.push_back(str.substr(0, i));
	}
	return output;
}

bool isIcecreamSandwich(std::string str) {
	int mid_index = str.length() / 2;
	if (str.size() < 3 || str[0]== str[mid_index] ) { return false; }
	for (int index = 0; index <= mid_index; index++) {
		if (str[index] != str[str.size() - index - 1] ||
			!(str[index] == str[0] || str[index] == str[mid_index])) { return false; }
	}
	return true;
}


int main()
{
	//	tweakLetters("apple", { 0, 1, -1, 0, -1 });
	//	circularShift({1, 2, 3, 4}, {3, 4, 1, 2}, 2);
	//	quicksort({5, 2, 8, 1, 9});
	//  cons({ 5, 1, 4, 3, 2 });
	//  isDisarium(135);
	//  findOdd({ 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 });
	//  makeBox(5);
	//  cout << std::string::npos << endl;
	//	firstBeforeSecond("a rabbit jumps joyfully", "a", "j");
	//	mysteryFunc("A4B5C2");
	//	parseCode("John000Doe000123");
	//	cout <<canBuild("got 2 go", "gogogo 2 today") << endl;
	//	overTwentyOne2({"2", "8", "J"});
	//	getTotalPrice({ { "Chocolate", 1, 0.1 },{ "Lollipop", 1, 0.2 } });
	//	isprime(4);
	//	booleanXor({ true,true,false,true });
	//	cout << countSmileys({ ";D", ":-(", ":-)", ";~)" }) << endl
	//	invert("dLROW YM sI HsEt"); // ➞ "TeSh iS my worlD"
	//	constructDeconstruct("Hello");
	//	isIcecreamSandwich("CDC");

	return 0;
}
