class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //maxHeap to store the max_freq_count;
        vector<int>count(26,0);

        for(int i=0;i<tasks.size();i++){
            count[tasks[i]-'A']++;
        }
        //max_heap
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                pq.push(count[i]);
            }
        }

        //cooldown queue
        queue<pair<int,int>>q;
        int time = 0;

        while(!pq.empty() || !q.empty()){
            time++;

            if(!pq.empty()){
                int current_time = pq.top();
                pq.pop();

                if(current_time > 1){
                    q.push({current_time-1, time+n});
                }
            }

            //cooldown reached
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
            // else if(pq.empty() && !q.empty()){
            //     time = q.front().second;
            // }
        }
        return time;
    }
};
