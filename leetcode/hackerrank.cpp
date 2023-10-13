#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minOperations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER threshold
 *  3. INTEGER d
 */

int minOperations(vector<int> arr, int threshold, int d) {
    sort(arr.begin(),arr.end());
    // unordered_map<int,int>m;
    // for(int i=0;i<arr.size();i++){
    //     m[arr[i]]++;
    // }
    int minOpr = INT32_MAX;
    for(int i=arr.size()-threshold;i>-1;i--){
        int nElem = 1,j = i+1,opr = 0;
        while(nElem<threshold && j<arr.size()){
            int times=0,elem=arr[j];
            while(elem>threshold){
                elem = elem/d;
                times++;
            }
            if(elem==arr[i]){
                opr+=times;
                nElem++;
            }
            j++;
        }
        if(nElem==threshold){
            if(minOpr>opr){
                minOpr = opr;
            }
        }
    }
    return minOpr;
}

int main()
{
    vector<int>arr = {64,30,25,33};
    cout << minOperations(arr,2,2);
    return 0;
}
