// #include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int n, m;
int x_1, y_1, x_2, y_2;
int dis[205][205];
bool vis[205][205]; 
string mapp[205];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};
void bfs(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dis[i][j] = -1, vis[i][j] = false;
    queue<pair<int, int>> q; 
    q.push({x_1, y_1}); 
    dis[x_1][y_1] = 0;
    vis[x_1][y_1] = true;
    while(!q.empty()){
        pair<int, int> t = q.front(); q.pop();
        for(int i=0; i<8; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            while(1){
                if(x == x_2 && y == y_2){
                 
                    cout << dis[t.first][t.second] << endl;
                    return;
                }
                if(x < 0 || x >= n || y < 0 || y >= m || mapp[x][y] == 'X') break; 
              
                x += dx[i];
                y += dy[i];
            }
        }
     
        for(int i=0; i<4; i++){
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && mapp[x][y] != 'X' && !vis[x][y]){
               
                q.push({x, y});
                dis[x][y] = dis[t.first][t.second] + 1;
                vis[x][y] = true;
            }
        }
    }
    cout << "Impossible!" << endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; i++) 
        cin >> mapp[i];
    while(cin >> x_2 >> y_2 >> x_1 >> y_1){
        if( x_1 == 0 && y_1 == 0 && x_2 == 0 && y_2 == 0 ) break;
        x_1--; y_1--; x_2--; y_2--;
        bfs();
    }
    return 0;
}


// https://www.cnblogs.com/ssNiper/p/11450483.html
