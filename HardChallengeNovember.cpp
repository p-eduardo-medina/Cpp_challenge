// ConsoleSplication2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// HardChallengeNovember2026

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> arr) {
	vector<vector<int>> transposed(arr[0].size(), vector<int>(arr.size())); // transposed(rows = arr[0].size(), columns = arr.size())
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			transposed[j][i] = arr[i][j];
		}
	}
	return transposed;
}

bool isMiniSudoku(std::vector<std::vector<int>> square) {
	for (int index = 1; index <= 9; index++) {
		int count = 0;
		for (int i = 0; i < square.size(); i++) for (int j = 0; j < square.size(); j++) if (square[i][j] == index) count++;
		if (count != 1) return false;
	}
	return true;
}
std::string toSnakeCase(std::string str) {
	std::string output{};
	for (char c : str) {
		if (isupper(c)) {
			if (!output.empty()) {
				output += '_';
				output += tolower(c);
			}
			else output += tolower(c);
		}
		else output += c;
	}
	return output;
}

std::string toCamelCase(std::string str) {
	std::string output{};
	for (int index = 0; index < str.length(); index++) {
		if (str[index] == '_') {
			output += toupper(str[index + 1]);
			index++;
		}
		else output += str[index];
	}
	return output;
}

int sharedLetters(std::string str1, std::string str2) {
	std::string output{};
	for (char c : str1) if (str2.find(c) != std::string::npos && output.find(c) == std::string::npos) output += c;
	return output.length();
}

int bugger(int num) {
	if (num < 9) return 0;
	else {
		int numAux = 1;
		while (num > 0) {
			numAux *= (num % 10);
			num = num / 10;
		}
		return 1 + bugger(numAux);
	}
}


std::string freeThrows(std::string success, int rows) {
	std::string probabilitie = success.substr(0, success.length()-1);
	int prob = std::stoi(probabilitie);
	double result{1};
	for (int i = 1; i <= rows; i++) result *= (0.01*prob);
	return std::to_string(static_cast<int>(std::round(result * 100))) + "%";
}

std::vector<int> profit(int A, int B) {
	int count1 = 0, count2 = 0;
	for (int index = 0; index <= 100; index++) {
		if (std::abs(index - A) < std::abs(index - B)) count1++;
		else if (std::abs(index - A) > std::abs(index - B)) count2++;
	}
	return { count1, count2 };
}
#include <numeric>
bool isShapePossible(int n, std::vector<int> angles) {
	if (n < 2) return false;
	for(int angle : angles) if (angle <= 0 || angle >= 180) return false;
	int sum = std::accumulate(angles.begin(), angles.end(), 0);
	if (sum != (n - 2) * 180) return false;
	return true;
}

std::vector<int> sortArr(std::vector<int> arr) {
	if(arr.size()<=1) return arr;
	int pivot = arr[arr.size() / 2];
	std::vector<int> smaller{}, equal{}, bigger{};
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < pivot) smaller.push_back(arr[i]);
		else if (arr[i] == pivot) equal.push_back(arr[i]);
		else bigger.push_back(arr[i]);
	}
	smaller = sortArr(smaller);
	bigger = sortArr(bigger);
	std::vector<int> result;
	for (const auto* part : { &smaller, &equal, &bigger })result.insert(result.end(), part->begin(), part->end());
	return result;
}
std::vector<int> oddSort(std::vector<int> arr) {
	std::vector<int> odds{}, output{};
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 1) odds.push_back(arr[i]);
	}
	odds = sortArr(odds);
	for (int i = 0; i < arr.size();i++) {
		if (arr[i]%2==0)output.push_back(arr[i]);
		else {
			output.push_back(odds[0]);
			odds.erase(odds.begin());
		}
	}
	return output;
}

float standardDeviation(std::vector<int> arr) {
	float mean{}, sum{}, sigma{};
	for (int x : arr) {
		mean += x;
	} mean /= arr.size();
	
	for (int x : arr) {
		sum += pow((mean - x), 2);
	}sum /= arr.size();
	return std::round(std::sqrt(sum) * 100.0) / 100.0;
}
//#include <algorithm>
bool winRound(std::vector<int> you, std::vector<int> opp) {
	std::sort(you.begin(), you.end());
	std::sort(opp.begin(), opp.end());
	return (10 * you[you.size()-1] + you[you.size() - 2]) > (10 * opp[opp.size()-1] + opp[opp.size() - 2]);
}
std::string reverse(std::string str) {
	std::vector<int> indices{};
	std::vector<char> letters{};
	std::string result{};
	for (int index = 0; index < str.size(); index++) {
		if (str[index] >= '0' && str[index] <= '9') indices.push_back(index);
		else letters.push_back(str[index]);
	}
	std::reverse(letters.begin(), letters.end());;
	for (int index = 0; index < str.size();index++) {
		if (std::find(indices.begin(), indices.end(), index) != indices.end()) result += str[index];
		else {
			result += letters[0];
			letters.erase(letters.begin());
		}
	}
	return result;
}
std::vector<char> currentlyWinning(std::vector<int> scores) {
	std::vector<int> O{scores[1]}, Y{scores[0]};
	std::vector<char> Result{};
	for (int index = 2; index < scores.size();index++) {
		scores[index] = scores[index] + scores[index - 2];
		if (index % 2 != 0)	O.push_back(scores[index]);
		
		else Y.push_back(scores[index]);
	}
	for (int index = 0; index < O.size(); index++) {
		if (O[index] > Y[index]) Result.push_back('O');
		else if (O[index] < Y[index]) Result.push_back('Y');
		else Result.push_back('T');
	}
	return Result;
}


int main()
{
	//	transposeMatrix({
	//	{ 1, 1, 1 } ,
	//	{ 2, 2, 2 },
	//	{ 3, 3, 3 }
	//	});
	//	isMiniSudoku([[1, 3, 2], [9, 7, 8], [4, 5, 6]] );
	//	toSnakeCase("helloEdabit");
	//	sharedLetters("apple", "meaty");
	//	bugger(999);
	//	freeThrows("75%", 5);
	//	profit(32, 69);
	//	oddSort({7, 5, 2, 3, 1});
	//	standardDeviation({3, 5, 7});
	//	winRound({2, 5, 2, 6, 9}, { 3, 7, 3, 1, 2 });
	//	cout << reverse("ab89c") << " cb89a"<<endl;
	currentlyWinning({ 5, 15, 17, 35, 16, 40, 66, 12, 10, 9 });
	//currentlyWinning([5, 1, 2, 10]);
	//currentlyWinning([10, 10, 5, 5, 2, 2, 1, 3, 100, 5]);

 }
