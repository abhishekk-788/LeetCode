class Solution {
    public long subArrayRanges(int[] nums) 
    {
        long sum=0;
        int n=nums.length;

        Stack<Integer> stack= new Stack<>();
        int[] minPrev= new int[n];
        int[] minNext= new int[n];
        int[] maxPrev= new int[n];
        int[] maxNext= new int[n];

        Arrays.fill(minPrev,-1);
        Arrays.fill(minNext,n);
        Arrays.fill(maxPrev,-1);
        Arrays.fill(maxNext,n);

        for(int i=0;i<n;i++){
            while(!stack.isEmpty() && nums[stack.peek()] > nums[i])
                stack.pop();

            if(!stack.isEmpty())
                minPrev[i]=stack.peek();

            stack.push(i);
        }

        stack.clear();
        for(int i=n-1;i>=0;i--){
            while(!stack.isEmpty() && nums[stack.peek()] >= nums[i])
                stack.pop();

            if(!stack.isEmpty())
                minNext[i]=stack.peek();

            stack.push(i);
        }

        stack.clear();
        for(int i=0;i<n;i++){
            while(!stack.isEmpty() && nums[stack.peek()] < nums[i])
                stack.pop();

            if(!stack.isEmpty())
                maxPrev[i]=stack.peek();

            stack.push(i);
        }

        stack.clear();
        for(int i=n-1;i>=0;i--)
        {
            while(!stack.isEmpty() && nums[stack.peek()] <= nums[i])
                stack.pop();

            if(!stack.isEmpty())
                maxNext[i]=stack.peek();

            stack.push(i);
        }

        for(int i=0;i<n;i++)
        {
            System.out.println(minPrev[i] + " " + minNext[i] + " " + maxPrev[i] + " " + maxNext[i]);
            
            long leftMin= i-minPrev[i];
            long rightMin= minNext[i]-i;
            long leftMax= i-maxPrev[i];
            long rightMax= maxNext[i]-i;

            sum+=(leftMax*rightMax - leftMin*rightMin)*nums[i];
        }

        return sum;
    }
}