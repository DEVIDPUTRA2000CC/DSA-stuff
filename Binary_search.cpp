#include<bits/stdc++.h>
using namespace std;
	// for sorted array
	
	/*int bs(vector<int> arr, int target){
   we use this int length = sizeof(array) / sizeof(array[0]);
   to define length of array if it is not define as vector stl;
	int n=arr.size();
		int low=0;
		int high=n-1;
		while(low<=high){
			int mid=(low+high)/2;
           if(arr[mid]==target){
           	return mid;
           }else if(arr[mid]<target){
           	     low=mid+1;

           }else{
           	high=mid-1;
           }
		}
		return -1;

	}
int main(){
	vector<int> arr={1, 3, 5, 6, 9, 10, 12};
	int target;
	cin>>target;
	int result=bs(arr, target);
	cout<<result;
	}
*/
// now with recursion 
/*What is Lower Bound in Binary Search?

👉 The lower bound of a value x in a sorted array is the first index (smallest position) where the element is greater than or equal to x.

If x exists in the array → lower bound gives the index of its first occurrence.

If x doesn’t exist → lower bound gives the index of the first greater element.

If all elements are smaller than x → lower bound gives the index = n (array size, meaning "not found inside array").
*/

//largest index;
//smallest index at nums[mid]>=target
int lowerbond(vector<int>& nums,int low, int high, int x, int n){
           int mid=(low+high)/2;
           if(low>high){
           	return n;
           }else if(nums[mid]>=x ){
           	 return lowerbond(nums, low, mid-1, x, n);
           }else{
           	 return lowerbond(nums, mid+1, high, x, n);
           }
            
       }
     //  smallest index at nums[mid]>target suppose {1, 3, 6, 7,9};
       // if target is 6 then 7>6;
       int upperbond(vector<int>& nums, int low, int high, int x, int n){
       	int mid=(low+high)/2;
       	if(low>high){
       		return n;
       	}else if(nums[mid]>x){
       		return upperbond(nums, low, mid-1, x, n);
       	}else{
       		return upperbond(nums, mid+1, high, x, n);
       	}
       	return n;
       }
       int searchInsert(vector<int> nums,  int low, int high, int target, int n){
       	int mid=(low+high)/2;
       	int ans=n;
       	while(low!=high){
       		if(nums[mid]>=target){
       			ans=mid; // store that may an answer index
       			high=mid-1;
       		}else{
       			low=mid+1;
       		}
       		return ans;

       }
     }
       // for smallets index;
       // largets no. in array <=target;
       //smallest no. in array>=target;
       int floor(vector<int> nums, int low, int high, int target){
 
         int ans=-1;
         while(low<=high){
         	int mid=(low+high)/2;
         	if(nums[mid]<=target){
         		ans=mid;// ans=mid
         		low=mid+1; 
         	}else{
         		high=mid-1;
         	}
         }
         return ans;
       }
       int coil(vector<int> nums, int low, int high, int target){
       	int ans=-1;
       	while(low<=high){
       		int mid=(low+high)/2;
       		if(low>high){
       			return -1;
       		}if(nums[mid]>=target){
       			ans=mid;
       			high=mid-1;
       		}else{
       			low=mid+1;
       		}
       	}
       	return ans;
       }
       int roted(vector<int> nums, int low, int high, int target ){
        while(low<=high){
          int mid=(low+high)/2;
          if(nums[mid]==target){
            return mid;
          }
          
          if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
              high=mid-1;
            }else{
              low=mid+1;
            }
          }else{
          if(nums[high]>=target && target>=nums[mid]){
              low=mid+1;
            }else{
              high=mid-1;
            }

          }
        }
          return -1;
       } 
       int findMin(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=nums[low]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
       
          return nums[low];
    }
    int timerotated(vector<int> nums, int low, int high){
      while(low<=high){
        int mid=(low+high)/2;
        //check rotated->
         if(nums[mid]>=nums[low]){
          return mid+1;
         }
    }
    return -1;
}
int duplicates(vector<int> nums){
  int ct;
        for(int i=0; i<nums.size(); i++){
             ct=nums[i];
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
        return ct;
        
    }
    int dupli(vector<int> nums){
      int low=1;
      int high=nums.size()-2;
      while(low<=high){
        int mid=(low+high)/2;
      }

      if(nums.size()==1){
        return nums[0];
      }
     if(nums[0]!=nums[1]){
      return nums[0];
     }if(nums[nums.size()-1]!=nums[nums.size()-2]){
      return nums[nums.size()-1];
     }
     while(low<=high){
      int ct=1;
        int mid=(low+high)/2;
        for(int i=0; i<=mid; i++){
          ct++;
        }

      
     if(nums[mid]!=nums[mid-1] || nums[mid]!=nums[mid+1]){
      return nums[mid];
     }if(ct%2==0){
      low=mid-1;
     }else{
      high=mid+1;
     }
    
  }
  return -1;
}


        
           int main(){
           	int n;
           	cin>>n;
           	vector<int> nums(n);
           	int target;
           	cin>>target;
           	for(int i=0; i<n; i++){
              cin>>nums[i];
           	}
            int search=dupli(nums);
            cout<<search<<endl;
}


