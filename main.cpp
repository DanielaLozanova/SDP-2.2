#include<iostream>
#include<list>
#include<string>
#include<fstream>

using namespace std;

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

void CocktailSort(list<int>& listSorted)
{
	bool swapped = true;
	std::list<int>::iterator start = listSorted.begin();
	std::list<int>::iterator end = prev(listSorted.end(), 1);

	std::list<int>::iterator it = listSorted.begin();
	std::list<int>::iterator bit;

	while (swapped)
	{
		swapped = false;

		while (it != end)
		{
			bit = next(it, 1);
			if (*it > *bit)
			{
				std::swap(*it, *bit);
				swapped = true;
			}
			++it;
		}

		if (!swapped)
			break;

		swapped = false;
		--end;
		it = end;

		while (it != start) {
			bit = prev(it, 1);
			if (*it < *bit)
			{
				std::swap(*it, *bit);
				swapped = true;
			}
			--it;
		}

		++start;
		it = start;
	}
}


void r(const string & path, list<int>& l)
{
	ifstream file(path);
	if (!file)
	{
		cout << "Error file cannot be opened " << endl;
		return;
	}
	unsigned int n = 0, cnt = 0;
	file >> n;
	file.get();
	int value = 0;
	while (!file.eof()) {
		file >> value;
		l.push_back(value);
	}

	file.seekg(0, ios::beg);
	file.close();
}


int main()
{
	list<int> l;
	r("file.txt", l);
	CocktailSort(l);
	while (!l.empty())
	{
		cout << l.front() << " ";
		l.pop_front();
	}

	return 0;
}