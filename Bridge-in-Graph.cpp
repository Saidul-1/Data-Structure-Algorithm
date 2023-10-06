//Bridges in a connected graph are those edges which are mendatory to keep the graph connected
vector<vector<int>>v(n+1);  //n = Number of vertices
vector<pair<int,int>>time(n+1);
vector<bool>visited(n+1,false);
vector<vector<int>>bridges(n+1,vector<int>(n+1,INT_MAX));
int tim=1;  //track the time when visited
void dfs_bridge(int root, int parent, vector<vector<int>>&v, vector<pair<int,int>>&time, vector<bool>&visited, vector<vector<int>>&bridges){
	visited[root]=true;
	time[root].first=time[root].second=tim++;
	for(int i=0;i<v[root].size();i++){
		int child=v[root][i];
		if(child==parent){continue;}  //checkpoint for infinity loop
		if(visited[child]){  //it can't be bridge as there is a secondary path through which visited earlier
			time[root].second=min(time[root].second, time[child].first);
		}
		else{
			dfs_bridge(child, root, v, time, visited, bridges);
			if(time[root].first<time[child].second){  //bridge because the child can't be visited from any other path
				bridges[root][child]=bridges[child][root]=1;
			}
			time[root].second=min(time[root].second, time[child].second);
		}
	}
}
