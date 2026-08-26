class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colour(n,-1);// colour can be 0 or -1
        queue<int> qt;
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                qt.push(i);
                colour[i]=1;
                 while(!qt.empty()){
                    int temp=qt.front();
                    qt.pop();
                    for(auto &ex:graph[temp]){
                        if(colour[ex]==-1){
                        colour[ex]=(colour[temp]+1)%2;
                        qt.push(ex);
                        }
                        else{
                        if(colour[ex]==colour[temp]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};