#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int edges, from, to, start, goal;
    cout<< "Enter number of edges: ";
    cin>> edges;

    vector<vector<int>> adj(1000001);   // تمثيل الجراف (كل رقم له لستة جيران)
    vector <bool> visited(1000001, false); // نتابع الزيارات
   vector <int> depth(1000001, 0);      // العمق (المستوى)
    vector<int> order;                  // ترتيب زيارة العقد
    queue<int> q;                       // طابور BFS

    cout << "Enter the edges:\n";
    for (int i = 0; i < edges; i++) {
        cin >> from >> to;
        adj[from].push_back(to);
    }

    cout << "Enter the starting node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    visited[start] = true;   // علمنا إننا زرنا البداية
    q.push(start);           // حطينا البداية في الطابور

    while (!q.empty()) {
        int current = q.front(); q.pop(); // خد أول عنصر وامسحه من الطابور
        order.push_back(current);         // خزن ترتيب الزيارة

        if (current == goal) break;       // لو وصلنا الهدف نوقف

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
            visited[neighbor] = true;
                depth[neighbor] = depth[current] + 1; // المستوى = مستوى اللي قبله + 1
                q.push(neighbor);                    // أضفه للطابو

     }
        }
    }

    cout << "Order of nodes visited: ";
    for (int node : order) cout << node << " ";
    cout << "\nGoal level (depth): " << depth[goal] << endl;

    return 0;
}
