#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// USING PATH VISITED ARRAY
class Solution {
  public:
  bool checkdfs(int node,vector<int>adj[],int vis[],int pathVis[]){
      vis[node]=1;
      pathVis[node]=1;
      for(auto i:adj[node]){
          if(!vis[i]){
              if(checkdfs(i,adj,vis,pathVis)==true)return true;
          }
          else if(pathVis[i])return true;
      }
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathVis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkdfs(i,adj,vis,pathVis)==true)return true;
            }
        }
        return false;
    }
};

// USING TOPOSORT:

bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0)q.push(it);
	        }
	    }
	    if(cnt==V)return false;
	    return true;
    }

int main(){

return 0;
}