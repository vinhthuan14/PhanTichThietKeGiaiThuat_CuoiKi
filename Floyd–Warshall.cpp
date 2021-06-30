#include <bits/stdc++.h>
using namespace std;
 
// số đỉnh v = 4
#define V 4
#define INF 99999
// hàm trả về kết quả cuối cùng và in ra ma trận
void printSolution(int dist[][V])
{
    cout << "Khoang cach ngan nhat giua cac cap dinh: \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}
void floydWarshall(int graph[][V])
{
    //dist lưu lại khoảng cách ngắn nhất giữa các cặp đỉnh
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j]; // khởi tạo đồ thị
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // nếu đỉnh k nằm trên đường đi ngắn nhất từ i tới j
                // lưu dist [i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
int main()
{
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    floydWarshall(graph);
    return 0;
}
