
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
   

   void dfs(int sr,int sc,int ic,int color,vector<vector<int>>& aux)
   {

          vector<int> deltax={-1,0,1,0};  // these are for traveesing the 4 neighbours
          vector<int> deltay={0,1,0,-1};

          aux[sr][sc]=color;

          int n=aux.size();
          int m=aux[0].size();

          for(int i=0;i<4;i++)
          {
            int newrow=sr+deltax[i];
            int newcol=sc+deltay[i];

  /* checking for valid neighbours
    1.if newrow is greater than 0
    2.if newrown is smaller than n 
    3.if newcolis greater than 0
    4.if newcol is smaller than m
    5.if that neighbours color is same as initial color or not
    6.if that neighbour has been previously visited or not by checking that is the color newcolor or not fot that neighnour


  */
            if(newrow>=0 && newrow<n && newcol<m && newcol>=0 && aux[newrow][newcol]==ic && aux[newrow][newcol]!=color)
            {
               
                dfs(newrow,newcol,ic,color,aux);

            }
          }



   }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        


      vector<vector<int>> aux=image; // generating a copy of input matrix

      int ic=image[sr][sc];   // declaring initial color

      dfs(sr,sc,ic,color,aux);

      return aux;




    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
