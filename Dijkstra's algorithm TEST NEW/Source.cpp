#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void printSolution(float dist[], int maxNode, map<int, vector<int>> mapping, int sourceNode)
{
	for (auto& it : mapping)
	{
		if (it.first >= maxNode)
		{
			break;
		}

		if (it.first == sourceNode)
		{
			cout << "Starting Node | Routes to | Weight" << endl;
			cout << "\t" << it.first;

			for (int i = 0; i < it.second.size(); i++)
			{
				if (i < 1)
				{
					cout << "\t    " << it.second[i] << "\t     " << dist[it.second[i]] << endl;
				}
				else
				{
					cout << "\t\t    " << it.second[i] << "\t     " << dist[it.second[i]] << endl;
				}
			}
			cout << endl;
			printf("     Shortest Path for Node %d\n", it.first);
		}
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < maxNode; i++)
		printf("%d \t\t %.2f\n", i, dist[i]);
}

float minDistance(float dist[], bool Tset[])
{
	float min = INFINITY, index;

	for (int i = 0; i < 20; i++)
	{
		if (Tset[i] == false && dist[i] <= min)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void DijkstraShortAlgorithm(float graph[20][20], int src, int maxNode, map<int, vector<int>> mapping)
{
	float dist[20];
	bool check[20];

	for (int i = 0; i < 20; i++)
	{
		dist[i] = INFINITY, check[i] = false;
	}

	dist[src] = 0;

	// Shortest path
	for (int i = 0; i < 20; i++) 
	{
		int u = minDistance(dist, check);

		check[u] = true;

		for (int b = 0; b < 20; b++)
		{
			if (!check[b] && graph[u][b] && dist[u] != INFINITY && dist[u] + graph[u][b] < dist[b])
			{
				dist[b] = dist[u] + graph[u][b];
			}
		}
	}

	printSolution(dist, maxNode, mapping, src);
}

int main()
{
	// Open and read net.txxt file for nodes

	std::ifstream inputText("net.txt");
	string str1;
	string str2;
	string delimiter = "\n";

	// Variables
	int lineCounter = 0;
	int DestNode = 0;
	string getMaxNode;
	string getFirstNode;
	string getSecondNode;
	string getWeight;
	int MaxNode = 0;
	int FirstNode;
	int SecondNode;
	float Weight;
	float graphWeight[20][20] = { 0 };

	// Mapping
	map<int, vector<int>> mapping;

	vector<int> vect0;
	vector<int> vect1;
	vector<int> vect2;
	vector<int> vect3;
	vector<int> vect4;
	vector<int> vect5;
	vector<int> vect6;
	vector<int> vect7;
	vector<int> vect8;
	vector<int> vect9;
	vector<int> vect10;
	vector<int> vect11;
	vector<int> vect12;
	vector<int> vect13;
	vector<int> vect14;
	vector<int> vect15;
	vector<int> vect16;
	vector<int> vect17;
	vector<int> vect18;
	vector<int> vect19;

	mapping.insert(pair <int, vector<int>>(0, vect0));
	mapping.insert(pair <int, vector<int>>(1, vect1));
	mapping.insert(pair <int, vector<int>>(2, vect2));
	mapping.insert(pair <int, vector<int>>(3, vect3));
	mapping.insert(pair <int, vector<int>>(4, vect4));
	mapping.insert(pair <int, vector<int>>(5, vect5));
	mapping.insert(pair <int, vector<int>>(6, vect6));
	mapping.insert(pair <int, vector<int>>(7, vect7));
	mapping.insert(pair <int, vector<int>>(8, vect8));
	mapping.insert(pair <int, vector<int>>(9, vect9));
	mapping.insert(pair <int, vector<int>>(10, vect10));
	mapping.insert(pair <int, vector<int>>(11, vect11));
	mapping.insert(pair <int, vector<int>>(12, vect12));
	mapping.insert(pair <int, vector<int>>(13, vect13));
	mapping.insert(pair <int, vector<int>>(14, vect14));
	mapping.insert(pair <int, vector<int>>(15, vect15));
	mapping.insert(pair <int, vector<int>>(16, vect16));
	mapping.insert(pair <int, vector<int>>(17, vect17));
	mapping.insert(pair <int, vector<int>>(18, vect18));
	mapping.insert(pair <int, vector<int>>(19, vect19));



	// Read from text file and store into string
	while (getline(inputText, str1))
	{
		str2 += str1 + "\n";
		lineCounter++;
	}

	// Parse for nodes and weights
	for (int i = 0; i < lineCounter; i++)
	{
		if (i == 0)
		{
			// Get destination node (which will be the maximum number of nodes - 1)
			getMaxNode = str2.substr(str2.find("\n") - 1, 1);
			MaxNode = stoi(getMaxNode);
			DestNode = stoi(getMaxNode) - 1;
			str2.erase(0, str2.find(delimiter) + delimiter.length());
		}
		else
		{
			getFirstNode = str2.substr(0, str2.find(" "));
			FirstNode = stoi(getFirstNode);
			/*cout << "First node: " << getFirstNode << endl;
			cout << "First node (int): " << FirstNode << endl;*/

			if (FirstNode / 10 < 1)
			{
				getSecondNode = str2.substr(str2.find(getFirstNode) + 2, str2.find(" ") + 1);
				SecondNode = stoi(getSecondNode);
				/*cout << "Second node: " << getSecondNode << endl;
				cout << "Second node (int): " << SecondNode << endl;*/

				getWeight = str2.substr(str2.find(getSecondNode) + 2, str2.find("\n") - 3);
				Weight = stof(getWeight);
				/*cout << "Weight: " << getWeight << endl;
				cout << "Weight (double): " << Weight << endl;*/

				//cout << endl;
			}
			else
			{
				getSecondNode = str2.substr(str2.find(getFirstNode) + 2, str2.find(" ") + 1);
				SecondNode = stoi(getSecondNode);
				/*cout << "Second node: " << getSecondNode << endl;
				cout << "Second node (int): " << SecondNode << endl;*/

				getWeight = str2.substr(str2.find(getSecondNode) + 3, str2.find("\n") - 5);
				Weight = stof(getWeight);
				/*cout << "Weight: " << getWeight << endl;
				cout << "Weight (double): " << Weight << endl;*/

				/*cout << endl;*/
			}

			// Assign mapping
			auto it = mapping.find(FirstNode);
			(*it).second.push_back(SecondNode);

			graphWeight[FirstNode][SecondNode] = Weight;

			// Last thing to do is to erase the top line of the string
			str2.erase(0, str2.find(delimiter) + delimiter.length());
		}
	}

	cout << endl;
	for (int i = 0; i < MaxNode; i++)
	{
		DijkstraShortAlgorithm(graphWeight, i, MaxNode, mapping);

		cout << endl;
	}
}