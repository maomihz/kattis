#include <bits/stdc++.h>
#include <iostream>
using namespace std;
unordered_map<int, vector<int>> sum_and_set;
bool match_found = false;

vector<int> read_input(int n) {
  std::vector<int> input;
  while (n--) {
    int i;
    cin >> i;
    input.push_back(i);
  }
  return input;
}

void print_vec(std::vector<int> v) {
  cout << "[";
  for (auto i : v) {
    cout << i << ",";
  }
  cout << "], ";
}

void print_sol(std::vector<int> v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int sum_vec(std::vector<int> v) {
  int sum = 0;
  for (auto i : v) {
    sum += i;
  }
  return sum;
}

void calc_set(vector<int> &set, vector<int> &powerSet, int set_size) {
  // count all elements
  if (match_found == true) {
    return;
  }
  if (set_size == 0) {
    int sum = sum_vec(powerSet);
    if (sum_and_set.find(sum) == sum_and_set.end()) {
      sum_and_set[sum] = powerSet;
    } else {
      print_sol(sum_and_set.at(sum));
      print_sol(powerSet);
      match_found = true;
      return;
    }
    return;
  }

  powerSet.push_back(set[set_size - 1]);
  calc_set(set, powerSet, set_size - 1);

  powerSet.pop_back();
  calc_set(set, powerSet, set_size - 1);
}

void calc_test() {
  int n;
  cin >> n;
  vector<int> input = read_input(n);
  vector<int> newVec;
  match_found = false;

  // pair<set<int>,set<int>> output;
  calc_set(input, newVec, input.size());

  if (match_found == false)
    cout << "Impossible" << endl;
}
int main() {
  int m;
  cin >> m;
  int l = m;
  while (m--) {
    cout << "Case #" << l - m << ":" << endl;
    calc_test();
    sum_and_set.clear();
  }
}