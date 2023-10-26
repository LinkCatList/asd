#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
class QueueMinMax{
public:
  void Push(ll x){
    this->s1.push(x);
    if(this->Min1.empty()){
      this->Min1.push(x);
    }
    else{
      this->Min1.push(min(this->Min1.top(), x));
    }

    if(this->Max1.empty()){
      this->Max1.push(x);
    }
    else{
      this->Max1.push(max(this->Max1.top(), x));
    }
  }
  void Pop(){
    if(this->s2.empty()){
      while(!this->s1.empty()){
        ll x =  this->s1.top();
        this->s1.pop();
        this->Min1.pop();
        this->Max1.pop();
        this->s2.push(x);

        if(this->Min2.empty()){
          this->Min2.push(x);
        }
        else{
          this->Min2.push(min(this->Min2.top(), x));
        }

        if(this->Max2.empty()){
          this->Max2.push(x);
        }
        else{
          this->Max2.push(max(this->Max2.top(), x));
        }
      }
    }
    this->s2.pop();
    this->Max2.pop();
    this->Min2.pop();
  }
  ll GetMax(){
    if(Max1.empty())return Max2.top();
    if(Max2.empty())return Max1.top();
    return max(Max1.top(), Max2.top());
  }
  ll GetMin(){
    if(Min1.empty())return Min2.top();
    if(Min2.empty())return Min1.top();
    return min(Min1.top(), Min2.top());
  }
  void PrintMax2(){
    stack<ll>Cur = Max2;
    vector<ll>Ans;
    while(!Cur.empty()){
      Ans.push_back(Cur.top());
      Cur.pop();
    }
    reverse(Ans.begin(), Ans.end());
    for(auto i:Ans){
      cout<<i<<" ";
    }
    cout<<"\n";
  }
  void PrintMin2(){
    stack<ll>Cur = Min2;
    vector<ll>Ans;
    while(!Cur.empty()){
      Ans.push_back(Cur.top());
      Cur.pop();
    }
    reverse(Ans.begin(), Ans.end());
    for(auto i:Ans){
      cout<<i<<" ";
    }
    cout<<"\n";
  }
  void PrintMin1(){
    stack<ll>Cur = Min1;
    vector<ll>Ans;
    while(!Cur.empty()){
      Ans.push_back(Cur.top());
      Cur.pop();
    }
    reverse(Ans.begin(), Ans.end());
    for(auto i:Ans){
      cout<<i<<" ";
    }
    cout<<"\n";
  }
private:
  stack<ll>s1;
  stack<ll>s2;
  stack<ll>Min1, Max1, Min2, Max2;
};
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  QueueMinMax q;
  ll n;
  cin>>n;
  for(ll i = 0; i<n; i++){
    ll x;
    cin>>x;
    q.Push(x);
  }
  q.Pop();
  q.Push(4);
  cout<<q.GetMax()<<" "<<q.GetMin()<<"\n";
  return 0;
}
