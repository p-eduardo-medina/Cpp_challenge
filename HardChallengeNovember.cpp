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



int main()
{
	//	transposeMatrix({
	//	{ 1, 1, 1 } ,
	//	{ 2, 2, 2 },
	//	{ 3, 3, 3 }
	//	});
	//	isMiniSudoku([[1, 3, 2], [9, 7, 8], [4, 5, 6]] );
	toSnakeCase("helloEdabit");
	toCamelCase("is_modal_open");
}
