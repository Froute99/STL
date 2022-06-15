#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <random>
#include <ranges>

using namespace std;


vector<string>::iterator Lower(vector<string>::iterator it);


int main()
{
	ifstream in{ "Frankenstein.txt" };
	vector<string> v1{ istream_iterator<string>{in},{} };

	cout << "단어개수 - " << v1.size() << endl;


	// [문제 3] v1에 있는 단어 중에서 "단어들.txt"에 없는 단어를 찾아 vector v2에 복사하라.
	// v2에 모두 몇 단어가 있는지 화면에 출력하고 답지에도 적어라.
	// (주의) v2에 저장된 단어는 중복되지 않아야 한다.

	ifstream words{ "단어들.txt" };
	vector<string> dictionary{ istream_iterator<string>{words}, {} };
	
	if (is_sorted(dictionary.begin(), dictionary.end()))
	{
		cout << "정렬됨\n";
	}
	copy(v1.begin(), v1.end(), Lower(v1.begin()));

	vector<string> v2;
	copy_if(v1.begin(), v1.end(), back_inserter(v2),
		[&dictionary](const string& word) {
			if (!binary_search(dictionary.begin(), dictionary.end(), word))
				return true;
			return false;
		});
	sort(v2.begin(), v2.end());
	auto p = unique(v2.begin(), v2.end());
	if (p == v2.end())
	{
		cout << "중복없음\n";
	}
	else
	{
		cout << "중복있음\n";
		v2.erase(p, v2.end());
		cout << "중복삭제\n";
	}
	
	cout << "사전에 없는 단어는 " << v2.size() << "개 입니다.\n";

}


vector<string>::iterator Lower(vector<string>::iterator dest)
{
	vector<string>::iterator it = dest;
	while (!it->empty())
	{
		transform(it->begin(), it->end(), it->begin(), toupper);
		++it;
	}
	return dest;
}

