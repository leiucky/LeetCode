//leetcode two sum
bool compareSTB(pair<int, int> x, pair<int, int> y)
{
	return x.first < y.first;
}

bool compareSTB2(int x, int y)
{
	return x < y ;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<pair<int, int>> Nindex;
		for (vector<int>::size_type i = 0; i!=numbers.size(); i++)
		{
			Nindex.push_back(make_pair(numbers[i], i));
		}
		
        sort(Nindex.begin(), Nindex.end(), compareSTB);
		Nindex;

	vector<int> temp;
	for (vector<int>::size_type i = 0; i!=Nindex.size(); i++)
	{
		int sub = target - Nindex[i].first;
		if (sub < 0)
			continue;
		int r = bsearch(Nindex, sub, i);
		if (r < 0)
			continue;
		temp.push_back(Nindex[i].second+1);
		temp.push_back(Nindex[r].second+1);
		break;
	}

	sort(temp.begin(), temp.end(), compareSTB2);
	return temp;
    }

private:
    int bsearch(vector<pair<int,int>>& arr, int v, int index);
};

int Solution::bsearch(vector<pair<int,int>>& arr, int v, int index)
{
	int left = 0;
	int right = arr.size()-1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid].first == v && mid != index)
			return mid;
		
		if (arr[mid].first < v)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}