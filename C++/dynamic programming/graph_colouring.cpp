#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 5

void printSolution(int color[]);

bool isSafe(int v, bool graph[V][V],
			int color[], int c)
{
	for(int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
			
	return true;
}

bool graphColoringUtil(bool graph[V][V], int m,
					int color[], int v)
{
	
	// condition if all vertices are assigned a color 
	if (v == V)
		return true;

	// different colors 
	for(int c = 1; c <= m; c++)
	{
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			if (graphColoringUtil(
				graph, m, color, v + 1) == true)
				return true;

			color[v] = 0;
		}
	}

	return false;
}

bool graphColoring(bool graph[V][V], int m)
{
	int color[V];
	for(int i = 0; i < V; i++)
		color[i] = 0;

	if (graphColoringUtil(graph, m, color, 0) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	printSolution(color);
	return true;
}

void printSolution(int color[])
{
	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for(int i = 0; i < V; i++)
		cout << " " << color[i] << " ";
		
	cout << "\n";
}

int main()
{
	
	//A-B-C-D-E
    
	bool graph[V][V] = { { 0, 1, 1, 0, 1 },
						{ 1, 0, 0, 1, 1 },
						{ 1, 0, 0, 1, 0 },
						{ 0, 1, 1, 0, 1 },
                        { 1, 1, 0, 1, 0 }, };
						
	// No of colors
	int m = 3;
	graphColoring(graph, m);
	return 0;
}
