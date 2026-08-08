class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count =0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                queue<int>qt;
                qt.push(i);
                visited[i]=true;
                while(!qt.empty()){
                    int ele=qt.front();
                    qt.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[ele][j]&&visited[j]==false){
                            qt.push(j);
                            visited[j]=true;
                        }
                    }
                }
                cout<<i<<" "<<count<<endl;
            }
        }
        return count;
    }
};