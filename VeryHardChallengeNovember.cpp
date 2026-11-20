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
//Team team("Manchester United", 30, 3, 5, 88, 20);


struct Team { 
	std::string name;int wins, loss, draws, scored, conceded;
	Team(std::string n, int w, int l, int d, int s, int c) :
		name(n), wins(w), loss(l), draws(d), scored(s), conceded(c) {} };

std::string champions(const std::vector<Team>& teams) {
	int record = 0, recordPoint = 0;
	std::string result = "";
	for (const auto team : teams) {
		if (team.wins * 3 + team.draws > record) {
			record = team.wins * 3 + team.draws;
			recordPoint = team.scored - team.conceded;
			result = team.name;
		}
		else if (team.wins * 3 + team.draws == record) {
			if (team.scored - team.conceded > recordPoint) {
				recordPoint = team.scored - team.conceded;
				result = team.name;
			}
		}
	}
	return result;
}

#include <vector>
int minLength(const std::vector<int>& values, int n) { 
	int score = values.size()+1;
	for (int index = 0; index < values.size();index++) {
		int sum = values[index];
		if (sum > n) score = 1;
		else {
			for (int jndex = index + 1; jndex < values.size();jndex++) {
				sum += values[jndex];
				if (sum > n) 
				{
					score = jndex - index + 1;
					break;
				}
			}
		}
	}
	if (score == values.size() + 1) {
		return -1;
	}else return score;
}


int main()
{
	//isPrimPythTriple({ 4, 5, 3 });
	champions(std::vector<Team>{
		Team("Manchester United", 30, 3, 5, 88, 20),
			Team("Arsenal", 24, 6, 8, 98, 29),
			Team("Chelsea", 22, 8, 8, 98, 29)
	});// ➞ "Manchester United"
	minLength({1,2,2,6,5,5,11 }, 10);

}

