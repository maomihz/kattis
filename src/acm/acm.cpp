#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;

int no_penalty(std::vector<string> vec){
	int total_time = 0;
	size_t sz;
	int right_count = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == "right"){
			total_time += stoi (vec[i-2],&sz);
			right_count ++;
		}
	}
	cout << right_count << " ";
	return total_time;
}

int penalty(std::vector<string> vec){
	//1. find all solved question
	size_t sz;
	int penalty_time = 0;
	vector<string> solved_questions;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == "right"){
			solved_questions.push_back(vec[i-1]);
		}
	}
	//2. find num wrong of those
	for(int i = 0; i < vec.size(); i++){
		for(auto elem:solved_questions){
			if(vec[i] == elem && vec[i+1] == "wrong"){
				penalty_time +=20;
			}
		}
	}
	return penalty_time;
}

int main2() {
	vector<string> vec;
	string input;
	 while(input != "-1"){
		cin >> input;
		vec.push_back(input);
	}
	cout << no_penalty(vec) + penalty(vec) << endl;

}


int main() {
	int time;
	char question;
	string result;

	int total = 0;
	int solved = 0;

	int wrong_answer[26];

	for (int i = 0; i < 26; i++) {
		wrong_answer[i] = -1;
	}

	while (true) {
		cin >> time;
		if (time < 0) {
			break;
		}
		cin >> question >> result;

		// cout << time << endl;
		// cout << question << endl;
		// cout << result << endl;

		int index = int(question - 'A');
		wrong_answer[index]++;


		if (result == "right") {
			// cout << index << "," << wrong_answer[index] << endl;
			total += time + 20 * wrong_answer[index];
			solved++;
		}
	}

	cout << solved << " " << total << endl;
}