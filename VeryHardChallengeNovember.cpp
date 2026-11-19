// VeryHardChallengeNovember.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string> 
#include <numeric>
#include <vector>
#include <map>

struct Student {
	std::string name;
	std::vector<int>notes;
};
std::map<int, int> getNotesDistribution(const std::vector<Student>& students) {
	std::vector<int> validNotes;
	for (const auto& student : students) {
		std::copy_if(student.notes.begin(), student.notes.end(),
			std::back_inserter(validNotes),
			[](int note) { return note >= 1 && note <= 5; }); //Función Lambda  [](int note)
	}

	return std::accumulate(
		validNotes.begin(), validNotes.end(),
		std::map<int, int>{}, //Valor antes de iniciar
		[](std::map<int, int> distribution, int note) {
			++distribution[note];
			return distribution;
		});
}

//#include <map>
std::map<int,int> GetFnP(long long n) {
	std::map<int, int> result;
	for (long long p = 2; p <= n / p; ++p) {
		if (n % p == 0) {
			int exponent = 0;
			do {
				n /= p;
				++exponent;
			} while (n % p == 0);
			result[p] = exponent;
		}
	}
	if (n > 1) {
		result[n]=1;
	}
	return result;
}

bool isPrime(int n, int m) {
	if (n == 1 || m == 1) return true;
	int index = 2;
	while (index <= n && index <= m) {
		if (n % index == 0 && m % index == 0) return true;
		index++;
	}
	return false;
}

bool isPrimPythTriple(std::vector<int> arr) {
	int c = *std::max_element(arr.begin(), arr.end()), sum=0,counter=0;//El * des-referencia el apuntador del iterados max_element
	for (int& n : arr) if (n != c) sum += n * n;
	if (sum == c * c) {
		for (int i = 0; i < arr.size() - 1;i++) {
			if (isPrime(arr[i], arr[i + 1])) { counter++; }
		}
	}
	else return false;
	if (counter > 0) return false;
	return true;
}


int main()
{
	isPrimPythTriple({ 4, 5, 3 });
}

