#include<iostream>
#include<vector>
using namespace std;

void upheapify(vector<int>&heap,int idx)
{
    if(idx==0)
    {
        return;
    }
    int parentidx = (idx-1)/2;
    if(heap[parentidx] < heap[idx])
    {
        //swap
        swap(heap[parentidx] , heap[idx]);
         upheapify(heap , parentidx);
    }
   
    else
    {
        return ;
    }
    
}
void downheapify( vector <int> &heap , int idx)
{
   int lidx = 2*idx + 1;
   int ridx = 2*idx + 2;
   if(lidx >= heap.size() && ridx >= heap.size())
   {
       return;
   }
    int tempidx = idx;
    if(lidx < heap.size() && heap[lidx] > heap[tempidx])
    {
        tempidx = lidx;
    }
    if(lidx < heap.size() && heap[ridx] > heap[tempidx])
    {
        tempidx=ridx;
    }
    if(tempidx==idx)
    return;
    swap(heap[tempidx],heap[idx]);
    downheapify(heap,tempidx);

}
void deletehighestpriority(vector<int>&heap)
{
    swap(heap[0] , heap[heap.size()-1]) ;
    heap.pop_back() ;
    downheapify(heap,0) ;
}
void insert(vector<int>&heap,int key)
{
    heap.push_back(key) ;
    upheapify(heap , heap.size() - 1) ;
}
void buildheap(vector<int>&heap)
{
       for(int i=heap.size()-1 ; i >= 0 ; i--)
        downheapify(heap,1);
}
void display(vector <int> heap)
{ 
    for(int i = 0 ; i < heap.size() ; i++)
    cout<< heap[i] <<" ";
    cout<< endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
            
     vector <int> heap;
     int n;
     cin>>n;

     for(int i = 0 ; i < n ; i++)
     {
         int x;
         cin>>x;
         heap.push_back(x);
     }
     buildheap(heap);
     display(heap);
     deletehighestpriority(heap);
     display(heap);
    return 0;
    
}