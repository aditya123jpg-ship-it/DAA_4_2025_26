//uid-24BCS10457
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;


int countdept=0;
int countit=0;
void complexRec(int n) {
    // start=high_resolution_clock::now();


   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           countit++;
       }
       p >>= 1;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
        countit++;
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2);
   countdept++;
   complexRec(n / 2);
   complexRec(n / 2);
   //auto end=high_resolution_clock::now();
   //auto duration=duration_cast<milliseconds>(end-start);
   //cout<<duration.count()<<endl;
}

int main(){
    auto start=high_resolution_clock::now();
    int n;
    cin>>n;
    complexRec(n);
    cout<<"Number of iterations = "<<countit<<endl;
    cout<<"Depth = "<< countdept-2<<endl;
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(end-start);
    cout<<duration.count()<<endl;
    
    
}

//Reccurence relation = 3T(N/2)+nlogn+n+n/2
//Time Complexity = O(N^log2(3))
