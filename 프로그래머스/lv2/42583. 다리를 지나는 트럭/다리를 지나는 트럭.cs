using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int bridge_length, int weight, int[] truck_weights)
    {
        int totalWeight = 0;
        int time = 0;
        int truck = 0;
        int move = 0;
        Queue<int> queue = new Queue<int>();

        while (truck < truck_weights.Length)
        {
            if (queue.Count == bridge_length)
                totalWeight -= queue.Dequeue();

            if (totalWeight + truck_weights[truck] <= weight)
            {
                totalWeight += truck_weights[truck];
                queue.Enqueue(truck_weights[truck]);
                truck++;
            }

            else
                queue.Enqueue(move);

            time++;
        }
        
        return time + bridge_length;
    }
}
