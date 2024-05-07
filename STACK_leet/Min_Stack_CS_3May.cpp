#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
vector<pair<int,int>>v1;
	public:
		
		// Constructor
		minStack() 
		{ 
		 
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
		   if(v1.empty()){
			   v1.push_back({num,num});
		   }else{
			   int k=min(v1.back().second,num);
			   v1.push_back({num,k});
		   }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(v1.empty()){
				return -1;
			}else{
				int top1=v1.back().first;
				v1.pop_back();
				return top1;
			}
			
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(v1.empty()){
				return -1;
			}else{
				return v1.back().first;
			}
			
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{ 
			if(v1.empty()){
				return -1;
			}else{
				return v1.back().second;
			}
		}
};