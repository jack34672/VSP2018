#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
using namespace std;

int maximumZeroSubsequenceLength(const vector<int>& vec) {
  unordered_map<int, int> x1, x2;
  x1.emplace(0, 0); // 0 valuessum to 0 at the beginning
  x2 = x1;
  for (auto& element : vec) {
    for (auto& subsum : x1) {
      int opt1 = 0;
      auto it = x1.find(subsum.first + element);
      if (it != x1.end())
        opt1 = it->second;
      x2[subsum.first + element] = max(opt1, x1[subsum.first] + 1);
    }
    x1 = x2;
  }
  return x1[0];
}

int main(int argc, char * argv[]) {

	vector<int> vec;
	int input;
	char c;
	while(cin >> input)
	vec.push_back(input);

  cout << maximumZeroSubsequenceLength(vec); // 4

  return 0;
}
