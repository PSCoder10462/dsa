#define M 1000000007

int *getProductArrayExceptSelf(int *arr, int n)
{
    
  
  //Write your code here
  int *p1 = new int[sizeof(int) * n];
  int *p2 = new int[sizeof(int) * n];

  if (n<=1) {
      for (int i=0; i<n; ++i) p1[i]=1;
      return p1;
  }
   
    
  int t = 1;

  // for left product
  p1[0] = 1;
  for (int i = 1; i < n; ++i)
    p1[i] = (p1[i - 1]%M * arr[i - 1]%M)%M;

  // for right product
  p2[n - 1] = 1;
  for (int i = n - 1; i > 0; --i)
    p2[i - 1] = (p2[i]%M * arr[i]%M)%M;

  int *ans = new int[sizeof(int) * n];
  for (int i = 0; i < n; ++i)
    ans[i] = p1[i] * p2[i];

  return ans;
}
