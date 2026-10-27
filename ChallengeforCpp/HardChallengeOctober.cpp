// Middle cpp Projects.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

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
	for(int index = 0; index < arr1.size(); index++) {
		if(arr1[(index+n) % arr1.size()] != arr2[index]) {
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
	for(int index = 0; index < arr.size(); index++) {
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

int main()
{
//	tweakLetters("apple", { 0, 1, -1, 0, -1 });
//	circularShift({1, 2, 3, 4}, {3, 4, 1, 2}, 2);
//	quicksort({5, 2, 8, 1, 9});
	cons({5, 1, 4, 3, 2});
	return 0;
}
