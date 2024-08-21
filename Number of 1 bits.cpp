/*#include<iostream>
using namespace std;
int main(){
	unsigned int n;
	cout<<"Enter a number ";
	cin>>n;
	int count =0;
	while(n!=0){
		if(n&1){
			
			count++;
		}
		n = n>>1;
	}
	int ans=count;
	cout<<ans;
}
*/


// For leet code 

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            if(n&1){
                count++;
            }
           n= n>>1;
        }
        int ans= count;
        return ans;
    }
};
