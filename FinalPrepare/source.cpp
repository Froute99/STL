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

	cout << "�ܾ�� - " << v1.size() << endl;


	// [���� 3] v1�� �ִ� �ܾ� �߿��� "�ܾ��.txt"�� ���� �ܾ ã�� vector v2�� �����϶�.
	// v2�� ��� �� �ܾ �ִ��� ȭ�鿡 ����ϰ� �������� �����.
	// (����) v2�� ����� �ܾ�� �ߺ����� �ʾƾ� �Ѵ�.

	ifstream words{ "�ܾ��.txt" };
	vector<string> dictionary{ istream_iterator<string>{words}, {} };
	
	if (is_sorted(dictionary.begin(), dictionary.end()))
	{
		cout << "���ĵ�\n";
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
		cout << "�ߺ�����\n";
	}
	else
	{
		cout << "�ߺ�����\n";
		v2.erase(p, v2.end());
		cout << "�ߺ�����\n";
	}
	
	cout << "������ ���� �ܾ�� " << v2.size() << "�� �Դϴ�.\n";

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

