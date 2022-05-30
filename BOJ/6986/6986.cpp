int t, n, m, input1, input2;
int N, K;
double dtemp, sum;
vector<double> v;
double halfup(double value) {
	int itemp = (double)100 * value;
	if (((double)100 * value - (double)itemp) * (double)10 >= 5)
	{
		return (double)(itemp + 1) / (double)100;
	}
	return value;
}
int main() {
	//init
	FastIO;
	int i, j, k;
	cin >> N >> K;
	for (i = 0; i < N; i++)
	{
		cin >> dtemp;
		v.push_back(dtemp);
	}

	sort(v.begin(), v.end());
	sum = 0;

	for (i = K; i < N - K; i++)
	{
		sum += v[i];
	}

	//Àý»ç Æò±Õ
	double result1 = sum / (N - 2 * K);

	double fir = v[K];
	double sec = v[N - K - 1];
	sum += (fir + sec)*K;

	//º¸Á¤ Æò±Õ
	double result2 = sum /= N;

	result1 = halfup(result1);
	result2 = halfup(result2);

	printf("%.2lf\n%.2lf", result1, result2);

	return 0;
}
