//additional variables
typedef struct person {
	string name;
	int day;
	int month;
	int year;
};
bool pred(person a, person b) {
	if (a.year == b.year)
	{
		if (a.month == b.month)
		{
			return a.day > b.day;
		}
		return a.month > b.month;
	}
	return a.year > b.year;

}
//main function
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//init
	int i, j, k, itemp;
	//solution
	cin >> n;
	vector<person> people(n);
	for (i = 0; i < n; i++)
	{
		cin >> people[i].name >> people[i].day >> people[i].month >> people[i].year;
	}
	sort(people.begin(), people.end(), pred);
	cout << people[0].name << endl << people[people.size() - 1].name;
	return 0;
}
