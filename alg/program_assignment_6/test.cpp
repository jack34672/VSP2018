#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <string>
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
	int input, i;
	char c;
	int strlength, num=0, tens=1;
	string name;
	getline(cin, name);
	strlength = name.length();
	for(i=strlength-1; i>=0; i--){
		if(name[i]==' '){
			vec.push_back(num);
			num = 0;
			tens = 1;
		}else if(name[i]=='-'){
			num = 0-num;
		}else{
			num = num + (name[i]-48)*tens;
			tens = tens * 10;
		}
		if(i==0){
			vec.push_back(num);
		}
	}
	
  cout << maximumZeroSubsequenceLength(vec); // 4

  return 0;
}
