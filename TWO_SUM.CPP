// TWO SUM PROBLEM

// APPROACH 1: BRUTE FORCE 
// TIME COMPLEXITY :- O(n^2)
// SPACE COMPLEXITY :- O(1)
#include<iostream>
#include<utility>
using namespace std;
pair<int,int> two_sum(int n,int arr[],int target){
       for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(arr[i]+arr[j]==target){
                   return {i,j};
                 }
             }
          }
          return {-1,-1};
      }
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int target;
cin>>target;
pair<int,int> result = two_sum(n,arr,target);
cout << result.first<< " " << result.second;
return 0;
}

// BETTER APPROACH :- HASHING
// TIME COMPLEXITY :- O(n)
// SPACE COMPLEXITY :- O(n)
#include<iostream>
#include<unordered_map>
using namespace std;
pair<int,int> twosumbetter(int n,int arr[],int target){
     unordered_map<int,int>mpp;
      for(int i=0;i<n;i++){
         int a = arr[i];
         int more = target - a;
         if(mpp.find(more)!=mpp.end()){
             return {mpp[more],i};
      }
       mpp[a] = i;
    }
return {-1,-1};
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
   cin>>arr[i];
}
int target;
cin>>target;
pair<int,int> result = twosumbetter(n,arr,target);
cout<<result.first<<" "<<result.second;
return 0;
}

// SORTING + 2 POINTER APPROACH:-
// TIME COMPEXITY:- O(n log n)
// SPACE COMPLEXITY:- O(n)

include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> twoSumSort(int n, int arr[], int target){
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end());
    int left = 0, right = n - 1;
    while(left < right){
        int sum = v[left].first + v[right].first;
        if(sum == target){
            return {v[left].second, v[right].second}; 
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }

    return {-1, -1};
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    pair<int,int> ans = twoSumSort(n, arr, target);

    cout << ans.first << " " << ans.second;

    return 0;
}
