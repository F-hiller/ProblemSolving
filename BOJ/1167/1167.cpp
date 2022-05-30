typedef struct node* nodePointer;
typedef struct node {
	int node_num, value;
	nodePointer next;
};
nodePointer* edge;
void push(int fir, int sec, int value) {
	nodePointer addNode1, addNode2;
	addNode1 = (nodePointer)malloc(sizeof(struct node));
	//addNode2 = (nodePointer)malloc(sizeof(struct node));

	addNode1->next = edge[fir]->next;
	addNode1->node_num = sec;
	addNode1->value = value;

	//addNode2->next = edge[sec]->next;
	//addNode2->node_num = fir;
	//addNode2->value = value;

	edge[fir]->next = addNode1;
	//edge[sec]->next = addNode2;
}

int n, m, t, N, K, itemp1, itemp2, itemp3;
int counter[SHARING];
bool visited[SHARING];
int result = 0, result_node = 0;

void clear() {
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

void bfs(int start) {
	int i, j, k;
	nodePointer ntemp;
	queue<pii> q;
	q.push(pii(start, 0));
	while (!q.empty())
	{
		pii top = q.front();
		q.pop();
		int index = top.first;
		int value = top.second;

		if (0 < index && index <= n && !visited[index])
		{
			if (value > result)
			{
				result = value;
				result_node = index;
			}
			visited[index] = 1;

			ntemp = edge[index]->next;
			while (ntemp)
			{
				q.push(pii(ntemp->node_num, value + ntemp->value));
				ntemp = ntemp->next;
			}
		}
	}
}

void solution() {
	int i, j, k;
	bfs(1);
	clear();
	result = 0;
	bfs(result_node);
	cout << result;
}

int main() {
	//init
	FastIO;
	//init
	int i, j, k;
	init();

	solution();

	return 0;
}

void init() {
	int i, j, k;
	cin >> n;
	edge = (nodePointer*)malloc(sizeof(nodePointer)*(n + 1));
	for (i = 1; i <= n; i++)
	{
		edge[i] = (nodePointer)malloc(sizeof(struct node));
		edge[i]->next = NULL;
	}
	for (i = 1; i <= n; i++)
	{
		cin >> itemp1;
		while (true)
		{
			cin >> itemp2;
			if (itemp2 == -1)
			{
				break;
			} 
			cin >> itemp3;
			push(itemp1, itemp2, itemp3);
			counter[itemp1]++;
		}
	}
	if (!DEBUG)
	{
		return;
	}
	nodePointer ntemp;
	cout << "=====================" << endl;
	for (i = 1; i < n; i++)
	{
		ntemp = edge[i]->next;
		cout <<"node "<< i << " : \n";
		while (ntemp)
		{
			cout << ntemp->node_num << " " << ntemp->value << endl;
			ntemp = ntemp->next;
		}
		cout << "--------------------"<< endl;
	}
	cout << "=====================" << endl;
}
