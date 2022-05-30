int t, n, m, input1, input2;
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> n;

	cout << "? " << n << endl;
	cout << std::flush;
	cin >> input1;

	cout << "? " << 1 << endl;
	cout << std::flush;
	cin >> input2;

	cout << "! " << ((input1 == input2) ? 0 : (input1 > input2) ? 1 : -1) << endl;
	cout << std::flush;

	return 0;
}
